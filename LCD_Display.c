#include <xc.h>

// Define LCD control pins
#define LCD_EN  LATAbits.LA1
#define LCD_RS  LATAbits.LA0
#define LCDPORT LATB

// Function to provide a delay
void lcd_delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 100; j++);
    }
}

// Function to send a command to the LCD
void SendInstruction(unsigned char command) {
    LCD_RS = 0;           // RS low for command
    LCDPORT = command;    // Place command on data bus
    LCD_EN = 1;           // Generate high-to-low pulse on EN
    lcd_delay(10);
    LCD_EN = 0;
    lcd_delay(10);
}

// Function to send data (characters) to the LCD
void SendData(unsigned char lcddata) {
    LCD_RS = 1;           // RS high for data
    LCDPORT = lcddata;    // Place data on data bus
    LCD_EN = 1;
    lcd_delay(10);
    LCD_EN = 0;
    lcd_delay(10);
}

// Main function
void main(void) {
    unsigned char *String1 = "Microembedded";
    unsigned char *String2 = "PIC-18F Board";

    // Set ports and pins
    ADCON1 = 0x0F;         // Configure all ports as digital
    TRISB = 0x00;          // Port B as output (LCD data)
    TRISAbits.RA0 = 0;     // RS pin as output
    TRISAbits.RA1 = 0;     // EN pin as output

    // LCD initialization commands
    SendInstruction(0x38); // 8-bit mode, 2 lines, 5x7 font
    SendInstruction(0x0C); // Display ON, cursor OFF
    SendInstruction(0x01); // Clear display
    SendInstruction(0x80); // Set DDRAM address to 1st line

    // Display first string
    while (*String1) {
        SendData(*String1);
        String1++;
    }

    SendInstruction(0xC0); // Set DDRAM address to 2nd line

    // Display second string
    while (*String2) {
        SendData(*String2);
        String2++;
    }

    while (1); // Infinite loop
}
