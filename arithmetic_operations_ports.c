#include <xc.h>     // Include processor files - each processor file is guarded. Provides register definitions.
#include <stdio.h>  // Standard I/O library (not used here but included)
#include <stdlib.h> // Standard library (not used here but included)

// Main function
void main(void) {
    int sum;
    int num1 = 0x02;     // First number in hexadecimal (decimal 2)
    int num2 = 0x03;     // Second number in hexadecimal (decimal 3)
    
    sum = num1 + num2;   // Perform addition: 2 + 3 = 5

    TRISA = 0;           // Set all pins of PORTA as output
    PORTA = sum;         // Send the result (5) to PORTA
    
    int sub;
    int num3 = 0x04;     // First number (decimal 4)
    int num4 = 0x02;     // Second number (decimal 2)
    
    sub = num3 - num4;   // Perform subtraction: 4 - 2 = 2

    TRISB = 0;           // Set all pins of PORTB as output
    PORTB = sub;         // Send the result (2) to PORTB
    
    int mul;
    int num5 = 0x02;     // First number (decimal 2)
    int num6 = 0x02;     // Second number (decimal 2)
    
    mul = num5 * num6;   // Perform multiplication: 2 * 2 = 4

    TRISC = 0;           // Set all pins of PORTC as output
    PORTC = mul;         // Send the result (4) to PORTC
    
    int div;
    int num7 = 0x04;     // First number (decimal 4)
    int num8 = 0x02;     // Second number (decimal 2)
    
    div = num7 / num8;   // Perform integer division: 4 / 2 = 2

    TRISD = 0;           // Set all pins of PORTD as output
    PORTD = div;         // Send the result (2) to PORTD
}

/*
  🧪 How to Check the Result in MPLAB X Simulator (PIC18F4550):

  1. Open this project in MPLAB X IDE.
  2. Build the code using the XC8 compiler.
  3. Go to: Window > Target Memory Views > SFRs.
  4. In the SFR window, locate and expand PORTA, PORTB, PORTC, and PORTD.
  5. Start the simulator by clicking: Debug > Debug Project or press F5.
  6. After execution, verify the following values on the ports:
       - PORTA = 0x05  (Addition: 2 + 3)
       - PORTB = 0x02  (Subtraction: 4 - 2)
       - PORTC = 0x04  (Multiplication: 2 * 2)
       - PORTD = 0x02  (Division: 4 / 2)
*/

