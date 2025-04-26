#include <xc.h>

// Define the relay control pin
#define RELAY_PIN LATAbits.LATA4

// Interrupt service routine for INT1
void __interrupt() extint_isr(void)
{
    unsigned int i;

    if (INT1IF) // Check if INT1 caused the interrupt
    {
        INT1IF = 0;             // Clear INT1 interrupt flag
        RELAY_PIN = !RELAY_PIN; // Toggle relay state

        // Debounce delay (simple delay loop)
        for (i = 0; i < 100000; i++);

        INT1IF = 1;             // Re-enable INT1 interrupt flag (if needed)
    }
}

void main(void)
{
    // Set up relay pin RA4 as digital output
    ADCON1 = 0x0F;              // All pins as digital
    TRISAbits.TRISA4 = 0;       // Set RA4 as output for relay
    RELAY_PIN = 1;              // Initial state: Relay ON

    // Configure INT1 pin (RB1) as input
    TRISBbits.TRISB1 = 1;       // INT1 pin as input

    // Enable interrupts
    GIE  = 1;                   // Global Interrupt Enable
    PEIE = 1;                   // Peripheral Interrupt Enable (if needed)
    INT1IE = 1;                 // Enable INT1 external interrupt
    INTEDG1 = 0;                // Trigger on falling edge (button press)

    while (1)
    {
        // Main loop does nothing, everything handled by interrupt
    }
}
