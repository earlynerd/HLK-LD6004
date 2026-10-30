// Split over-merged functions at known vector targets and decompile those ISRs.
// Output: <elf-path>_isrs.c
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.io.FileWriter;

public class DumpIsrs extends GhidraScript {

	private static final long[] ADDRS = {
		0x14CE4L, // IRQ0
		0x1497CL, // IRQ3
		0x1498CL, // IRQ4
		0x0E654L, // IRQ5
		0x11D7CL, // IRQ7
		0x129FCL, // IRQ10
		0x0E800L, // IRQ13
	};

	@Override
	public void run() throws Exception {
		String exec = currentProgram.getExecutablePath();
		int dot = exec.lastIndexOf('.');
		String out = (dot > 0 ? exec.substring(0, dot) : exec) + "_isrs.c";

		for (long a : ADDRS) {
			Address addr = currentProgram.getAddressFactory().getAddress(Long.toHexString(a));
			Function fn = getFunctionContaining(addr);
			try {
				if (fn == null) {
					disassemble(addr);
					createFunction(addr, "isr_" + Long.toHexString(a));
				} else if (!fn.getEntryPoint().equals(addr)) {
					// manual split: remove the merged function, recreate both halves
					Address entry = fn.getEntryPoint();
					Address max = fn.getBody().getMaxAddress();
					String origName = fn.getName();
					AddressSet set1 = new AddressSet(entry, addr.prev());
					AddressSet set2 = new AddressSet(addr, max);
					currentProgram.getFunctionManager().removeFunction(entry, monitor);
					currentProgram.getFunctionManager().createFunction(
						origName + "_head", entry, set1, SourceType.USER);
					currentProgram.getFunctionManager().createFunction(
						"isr_" + Long.toHexString(a), addr, set2, SourceType.USER);
				}
			} catch (Exception e) {
				println("split/create at " + addr + ": " + e.getMessage());
			}
		}

		DecompInterface decomp = new DecompInterface();
		decomp.openProgram(currentProgram);
		try (PrintWriter pw = new PrintWriter(new FileWriter(out))) {
			for (long a : ADDRS) {
				Address addr = currentProgram.getAddressFactory().getAddress(Long.toHexString(a));
				Function fn = getFunctionAt(addr);
				pw.printf("%n/* ===== isr_%x @ %s ===== */%n", a, addr);
				if (fn == null) {
					pw.println("/* no function at address */");
					continue;
				}
				DecompileResults r = decomp.decompileFunction(fn, 60, monitor);
				pw.println(r.decompileCompleted() ? r.getDecompiledFunction().getC()
						: "/* FAILED: " + r.getErrorMessage() + " */");
			}
		} finally {
			decomp.dispose();
		}
		println("ISR decompile -> " + out);
	}
}
