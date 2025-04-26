#include <xc.h>           // Include processor definitions for PIC18F4550
#include <stdlib.h>       // Standard library functions
#include <pic18f4550.h>   // Device-specific header

// Simple delay loop (not accurate, just crude timing)
void delay() {
    for(int i = 0; i < 1000; i++) {
        // Do nothing, just delay
    }
}

void main(void) {
    TRISB = 0x00;     // Set all PORTB pins as output
    PORTB = 0xFF;     // Initialize PORTB to all HIGH (all LEDs ON if connected)

    while(1) {
        LATB = ~LATB; // Toggle all bits of LATB (bitwise NOT)
        delay();      // Call delay to slow down toggling
    }

    return; // This will never be reached due to infinite loop
}

/*
  🧪 How to Check the Result in MPLAB X Simulator (PIC18F4550):

  1. Open MPLAB X, build the project with XC8.
  2. Go to: Window > Target Memory Views > SFRs.
  3. Find and monitor `LATB` under PORTB group.
  4. Click Debug > Debug Project (F5) to start simulation.
  5. Use "Pause" to freeze execution at any time.
  6. You’ll observe LATB toggling between 0x00 and 0xFF repeatedly.
     → This simulates LED blinking ON and OFF for all 8 bits on PORTB.

  🔧 Tip: You can also simulate time-based blinking better by setting breakpoints or stepping over in MPLAB X.
*/

