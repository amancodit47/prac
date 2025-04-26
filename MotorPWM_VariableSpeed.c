#include <p18f4550.h>

// Global Variables
unsigned char count = 0;
bit TIMER, SPEED_UP;

// Function to initialize Timer2
void timer2Init(void)
{
    T2CON = 0b00000010;   // Prescaler = 16, Timer2 OFF initially
    PR2 = 0x95;           // Period register value
}

// Simple delay function (blocking)
void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1000; j++);
}

// Main function
void main(void)
{
    unsigned int i;

    // Set RC1 and RC2 as output
    TRISCbits.TRISC1 = 0;     // RC1 = Output
    TRISCbits.TRISC2 = 0;     // CCP1 (PWM) pin = Output

    LATCbits.LATC1 = 0;       // RC1 initially LOW

    // Set CCP1 in PWM mode
    CCP1CON = 0b00001100;     // PWM mode: P1A active-high

    CCPR1L = 0x0F;            // Initial Duty Cycle ~10%

    // Initialize Timer2
    timer2Init();
    TMR2ON = 1;               // Turn ON Timer2

    // Main loop
    while (1)
    {
        // Fade IN: Increase duty cycle
        for (i = 15; i < 150; i++)
        {
            CCPR1L = i;       // Set duty cycle
            delay(100);       // Delay for smooth transition
        }

        // Fade OUT: Decrease duty cycle
        for (i = 150; i > 15; i--)
        {
            CCPR1L = i;
            delay(100);
        }
    }
}
