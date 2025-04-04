#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>

void SSD1306_Init(void);
void SSD1306_Clear(void);
void SSD1306_SetCursor(uint8_t x, uint8_t y);
void SSD1306_WriteString(const char *str);
void SSD1306_WriteChar(char c);
#endif
