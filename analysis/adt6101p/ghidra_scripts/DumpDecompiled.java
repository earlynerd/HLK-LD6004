// Decompile every function in the program and write pseudo-C to a file.
// Args: <output-file>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.PrintWriter;
import java.io.FileWriter;

public class DumpDecompiled extends GhidraScript {

	@Override
	public void run() throws Exception {
		String[] args = getScriptArgs();
		String out;
		if (args.length > 0) {
			out = args[0];
		} else {
			// Default: alongside the imported file, app1.elf -> app1_decompiled.c
			String exec = currentProgram.getExecutablePath();
			int dot = exec.lastIndexOf('.');
			out = (dot > 0 ? exec.substring(0, dot) : exec) + "_decompiled.c";
		}
		DecompInterface decomp = new DecompInterface();
		decomp.openProgram(currentProgram);
		int ok = 0, fail = 0;
		try (PrintWriter pw = new PrintWriter(new FileWriter(out))) {
			FunctionManager fm = currentProgram.getFunctionManager();
			for (Function f : fm.getFunctions(true)) {
				pw.printf("%n/* ===== %s @ %s ===== */%n", f.getName(), f.getEntryPoint());
				DecompileResults r = decomp.decompileFunction(f, 60, monitor);
				if (r.decompileCompleted()) {
					pw.print(r.getDecompiledFunction().getC());
					ok++;
				} else {
					pw.println("/* FAILED: " + r.getErrorMessage() + " */");
					fail++;
				}
			}
		} finally {
			decomp.dispose();
		}
		println("Decompiled " + ok + " functions, " + fail + " failures -> " + out);
	}
}
