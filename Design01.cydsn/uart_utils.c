#include "uart_utils.h"
#include "project.h"

void UART_GetString(char *buffer, uint8_t maxLength) {
    uint8_t i = 0;
    char c;

    while (i < maxLength - 1) {
        c = UART_GetChar(); // Lee un carácter desde UART
        if (c == '\r' || c == '\n') {
            break; // Termina si se recibe Enter
        }
        if (c != 0) { // Ignora caracteres nulos
            buffer[i++] = c;
        }
    }
    buffer[i] = '\0'; // Añade el terminador de cadena
}
