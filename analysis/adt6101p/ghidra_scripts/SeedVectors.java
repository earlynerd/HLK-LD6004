// Seed functions from the Cortex-M3 vector table of a raw binary image.
// Args: none. Assumes image base is the program's minimum address and the
// vector table starts there (SP word, then handler words with thumb bit set).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;

public class SeedVectors extends GhidraScript {

	@Override
	public void run() throws Exception {
		Address base = currentProgram.getMinAddress();
		long max = currentProgram.getMaxAddress().getOffset() + 1;
		monitor.setMessage("Seeding vector-table handlers at " + base);

		// Entry 0 is the initial SP; entries 1..N are handler pointers.
		// Skip empty slots (unused IRQs) instead of stopping at the first one.
		for (int i = 1; i <= 0xFF; i++) {
			long v = currentProgram.getMemory().getLong(base.add(i * 4), false);
			if (v == 0 || (v & 1) == 0) {
				continue;
			}
			long target = (v & ~1L);
			if (target < base.getOffset() || target >= max) {
				continue;
			}
			Address addr = currentProgram.getAddressFactory().getAddress(Long.toHexString(target));
			try {
				disassemble(addr);
				createFunction(addr, "vector_" + i);
			} catch (Exception e) {
				println("vector_" + i + " @ " + addr + ": " + e.getMessage());
			}
		}
	}
}
