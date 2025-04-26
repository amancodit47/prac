#include <xc.h>         // Include XC8 compiler header for PIC18F4550
#include <stdio.h>      // (Optional) Standard I/O header
#include <stdlib.h>     // (Optional) Standard library functions
#include <pic18f4550.h> // Device-specific header file

void main(void) {
    int sum = 0;                 // Variable to store the total sum
    int arr[5] = {1, 2, 3, 4, 5}; // Integer array with 5 elements

    // Loop through the array and calculate the sum
    for(int i = 0; i < 5; i++) {
        sum = sum + arr[i];     // Add each element to sum
    }

    TRISD = 0;      // Set PORTD as output
    PORTD = sum;    // Send the result (15) to PORTD

    return;         // End of main function
}

/*
  🧪 How to Check the Result in MPLAB X Simulator (PIC18F4550):

  1. Open this project in MPLAB X IDE.
  2. Build the code using the XC8 compiler.
  3. Go to: Window > Target Memory Views > SFRs.
  4. In the SFR window, locate and expand PORTD.
  5. Start the simulator by clicking: Debug > Debug Project or press F5.
  6. After execution, observe that PORTD shows the value 0x0F (which is 15 in decimal),
     confirming that the sum of array {1,2,3,4,5} is correctly output.
*/
