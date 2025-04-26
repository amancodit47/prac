#include <pic18f4550.h>
#include <xc.h>

// Define buzzer pin as RA5
#define buzzer LATAbits.LATA5

// Global counter variable to keep track of Timer1 overflows
unsigned int count = 0;

// Interrupt Service Routine for Timer1
void interrupt Timer1_ISR(void) {
    if (TMR1IF == 1) {          // Check if Timer1 overflow interrupt occurred
        TMR1L = 0x20;           // Reload Timer1 Low Byte
        TMR1H = 0xD1;           // Reload Timer1 High Byte
        count++;                // Increment overflow count
    }

    if (count >= 1000) {        // After 1000 overflows (approx 1s depending on prescaler)
        buzzer = ~buzzer;       // Toggle the buzzer pin
        count = 0;              // Reset counter
    }

    TMR1IF = 0;                 // Clear Timer1 interrupt flag
}

void main(void) {
    // Set RA5 (buzzer pin) as output
    TRISAbits.TRISA5 = 0;

    // Enable global and peripheral interrupts
    GIE = 1;
    PEIE = 1;

    // Enable Timer1 interrupt
    TMR1IE = 1;
    TMR1IF = 0;

    // Timer1 configuration: 16-bit read/write, internal clock (Fosc/4)
    T1CON = 0x80;

    // Load Timer1 with initial values
    TMR1L = 0x20;
    TMR1H = 0xD1;

    // Turn on Timer1
    TMR1ON = 1;

    while (1);  // Main loop does nothing, logic handled in ISR
    return;
}
