
#include <xc.h>
#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>

#define Fosc 48000000UL

void InitUART(unsigned int baudrate){
    TRISCbits.RC6 = 0;        // RC6 as TX (output)
    TRISCbits.RC7 = 1;        // RC7 as RX (input)
    SPBRG = (unsigned char)(((Fosc/64)/baudrate)-1);  // Set baud rate
    BAUDCON = 0b00000000;     // 8-bit baud rate generator
    TXSTA = 0b00100000;       // Enable transmitter
    RCSTA = 0b10010000;       // Enable serial port and receiver
}

void SendChar(unsigned char data){
    while (TXSTAbits.TRMT == 0);  // Wait until transmit shift register is empty
    TXREG = data;                 // Send data
}

void putch(unsigned char data){
    SendChar(data);               // Used by printf internally
}

unsigned char GetChar(void){
    while (!PIR1bits.RCIF);        // Wait until a byte is received
    return RCREG;                  // Return received byte
}

void main(void){
    InitUART(9600);                            // Initialize UART at 9600 baud
    printf("\nHello MicroPIC18F: Enter any key from Keyboard\n\n");
    
    while (1){
        printf("%c", GetChar());                // Echo the received character
    }
    
    while(1);                                   // Infinite loop (never exit)
}

int main(int argc, char** argv){
    return (EXIT_SUCCESS);
}
