#include <xc.h>     // Include processor definitions for PIC18F4550
#include <stdio.h>  // Standard I/O (not required but included)
#include <stdlib.h> // Standard library (not required but included)

void main(void) {
    int arr[] = {3, 4, 5, 6, 1}; // Initialize an unsorted array of 5 elements

    // Bubble Sort - Sorting the array in ascending order
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Define pointers to specific RAM addresses
    int *arr1 = (int*)0x30; // Starting address to store sorted (ascending) array
    int *arr2 = (int*)0x40; // Starting address to store reverse (descending) array

    // Store sorted array in ascending and descending order into memory
    for(int i = 0; i < 5; i++) {
        arr1[i] = arr[i];           // Store ascending order at 0x30
        arr2[i] = arr[4 - i];       // Store descending order at 0x40
    }

    return; // End of program
}

/*
  🧪 How to Check the Result in MPLAB X Simulator (PIC18F4550):

  1. Open the project in MPLAB X IDE and build using the XC8 compiler.
  2. Start the debugger using Debug > Debug Project (F5).
  3. Go to: Window > Target Memory Views > File Registers.
  4. Check address range:
     - `0x30` to `0x34` → should contain sorted array in ascending order: [1, 3, 4, 5, 6]
     - `0x40` to `0x44` → should contain same array in descending order: [6, 5, 4, 3, 1]
  5. Use memory view to verify the written data in those RAM locations.
*/

