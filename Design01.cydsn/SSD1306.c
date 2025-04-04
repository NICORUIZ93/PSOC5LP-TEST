#include "SSD1306.h"
#include "project.h"
#include "font8x8.h"
#include <stdio.h>

#define DISPLAY_ADDRESS 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

// Initialization commands for the OLED screen
static const uint8_t init_commands[] = {
    0xAE, // Turn off the display
    0xD5, 0x80, // Clock configuration
    0xA8, 0x3F, // Multiplexing
    0xD3, 0x00, // Display offset
    0x40, // Start line
    0x8D, 0x14, // Enable charge pump
    0x20, 0x00, // Horizontal addressing mode
    0xA1, // Segment remap
    0xC8, // COM output remap
    0xDA, 0x12, // COM configuration
    0x81, 0xCF, // Contrast control
    0xD9, 0xF1, // Pre-charge period
    0xDB, 0x40, // VCOMH deselect level
    0xA4, // Output all pixels off
    0xA6, // Normal display
    0xAF  // Turn on the display
};

// Global variables to store cursor position
uint8_t cursor_x = 0;
uint8_t cursor_y = 0;

void SSD1306_Init(void) {
    I2C_Start(); // Initialize the I2C component

    for (uint8_t i = 0; i < sizeof(init_commands); i++) {
        I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
        I2C_MasterWriteByte(0x00); // Command byte
        I2C_MasterWriteByte(init_commands[i]); // Send the command
        I2C_MasterSendStop();
    }
}

void SSD1306_Clear(void) {
    for (uint8_t page = 0; page < 8; page++) {
        SSD1306_SetCursor(0, page * 8);
        for (uint8_t col = 0; col < SSD1306_WIDTH; col++) {
            I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
            I2C_MasterWriteByte(0x40); // Data byte
            I2C_MasterWriteByte(0x00); // Clear pixel
            I2C_MasterSendStop();
        }
    }
	cursor_x = 0;
    cursor_y = 0;
}

void SSD1306_WriteChar(char c) {
    if (c >= ' ' && c <= '~') { // Printable ASCII range
        uint8_t font_index = c - ' ';
        
        // Write character data
        for (uint8_t i = 0; i < FONT_WIDTH; i++) {
            I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
            I2C_MasterWriteByte(0x40); // Data byte
            I2C_MasterWriteByte(font6x8[font_index * FONT_WIDTH + i]); // Font data
            I2C_MasterSendStop();
        }

        // Add a space after the character
        I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
        I2C_MasterWriteByte(0x40);
        I2C_MasterWriteByte(0x00); // Space column
        I2C_MasterSendStop();

        cursor_x += FONT_WIDTH + 1; // Move cursor
    }
}

void SSD1306_WriteString(const char *str) {
    while (*str) {
        SSD1306_WriteChar(*str++);
    }
}

void SSD1306_SetCursor(uint8_t x, uint8_t y) {
    uint8_t command1, command2;
    command1 = 0xb0 + (y / 8);
    command2 = ((x & 0x0f));
    I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
    I2C_MasterWriteByte(0x00); // Command byte
    I2C_MasterWriteByte(command1);
	I2C_MasterSendStop();
	
	I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
    I2C_MasterWriteByte(0x00); // Command byte
    I2C_MasterWriteByte(0x00 + command2);
    I2C_MasterSendStop();
	
	I2C_MasterSendStart(DISPLAY_ADDRESS, I2C_WRITE_XFER_MODE);
    I2C_MasterWriteByte(0x00); // Command byte
    I2C_MasterWriteByte(0x10);
    I2C_MasterSendStop();	
}
