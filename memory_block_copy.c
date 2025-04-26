#include <xc.h>           // Include processor definitions for PIC18F4550
#include <stdio.h>        // Standard I/O (optional)
#include <stdlib.h>       // Standard library functions (optional)
#include <pic18f4550.h>   // Device-specific header

void main(void) {
    // Pointer to source memory location (address 0x60)
    int *source = (int*)0x60;

    // Pointer to destination memory location (address 0x70)
    int *destination = (int*)0x70;

    // Copy 5 integer values from source to destination
    for(int i = 0; i < 5; i++) {
        destination[i] = source[i];
    }

    return; // End of program
}

/*
  🧪 How to Check the Result in MPLAB X Simulator (PIC18F4550):

  1. Before running the simulation, manually write test values at memory addresses:
     - Open Window > Target Memory Views > File Registers.
     - Set values at 0x60 to 0x64 (e.g., 0x01, 0x02, 0x03, 0x04, 0x05).
  
  2. Build and run (F5) the program in the simulator.
  
  3. After execution, verify that:
     - Memory from 0x70 to 0x74 contains the same values as 0x60 to 0x64.
       → If 0x60 = 0x01, then 0x70 should also be 0x01, and so on.

  4. This confirms that the memory block copy was successful using pointers.
*/

