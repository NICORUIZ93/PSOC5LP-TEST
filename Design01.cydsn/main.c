#include "project.h"
#include "stdio.h"
#include "L298N.h"
#include "SSD1306.h"

int32_t conversion;
float32 ADCVoltaje;
char mensaje[256];
uint8_t pwm_value;
uint8_t direccion = 0; // 0: derecha, 1: izquierda

void init() {
    CyGlobalIntEnable;
    SSD1306_Init();
    UART_Start();
    UART_PutString("Sistema inicializado.\r\n");
    UART_PutString("Use el potenciometro para ajustar la velocidad.\r\n");
    UART_PutString("Presione el boton para cambiar la direccion.\r\n");
    ADC_Start();
    Opamp_Start();
    PWM_Start();
    L298N_Init(); 
}

void printData() {
    // Iniciar conversión ADC
    ADC_StartConvert();
    while (!ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {}

    // Calcular voltaje (suponiendo ADC de 20 bits y referencia de 5V)
    conversion = ADC_GetResult32();
    ADCVoltaje = (conversion * 5.0) / 1048575.0;

    // Calcular valor PWM
    pwm_value = (uint8_t)((ADCVoltaje / 5.0) * 255);
    if (pwm_value > 255) pwm_value = 255; // Limitar valor máximo
    uint8_t pwm_percentage = (uint8_t)((pwm_value / 255.0) * 100);

    // Mostrar datos en consola UART
    sprintf(mensaje, "Voltaje: %.4f V, PWM Value: %d, PWM Percentage: %d%%\r\n", ADCVoltaje, pwm_value, pwm_percentage);
    UART_PutString(mensaje);

    // Mostrar PWM en la primera línea del OLED
    sprintf(mensaje, "PWM: %d%%", pwm_percentage);
    SSD1306_SetCursor(0, 0);
    SSD1306_WriteString(mensaje);

    // Mostrar Dirección en la segunda línea del OLED
    sprintf(mensaje, "Dir: %s", direccion ? "Izquierda" : "Derecha");
    SSD1306_SetCursor(0, 8);
    SSD1306_WriteString(mensaje);

    // Mostrar Voltaje en la tercera línea del OLED
    sprintf(mensaje, "Voltaje: %.2f V", ADCVoltaje);
    SSD1306_SetCursor(0, 16);
    SSD1306_WriteString(mensaje);

    // Actualizar valor PWM en el comparador
    PWM_WriteCompare(pwm_value);
}

void controlDireccion() {
    if (DIRECCION_Read() == 0) { // Leer estado del botón
        CyDelay(50); // Anti-rebote
        if (DIRECCION_Read() == 0) { 
            direccion = !direccion; // Cambiar dirección
            
            // Corregir la línea UART_PutString
            const char* dir_str = direccion ? "Izquierda" : "Derecha";
            char mensaje_direccion[30]; // Ajusta el tamaño según sea necesario
            sprintf(mensaje_direccion, "Direccion: %s\r\n", dir_str);
            UART_PutString(mensaje_direccion);

            if (direccion == 0) {
                L298N_Forward(); // Configurar pines para giro a la derecha
            } else {
                L298N_Backward(); // Configurar pines para giro a la izquierda
            }
        }
        while (DIRECCION_Read() == 0); // Esperar que se suelte el botón
        SSD1306_Clear();
    }
   
}


int main(void) {
    init();
    SSD1306_Clear();

    for (;;) {
        printData();      // Actualizar datos del PWM, voltaje y dirección
        controlDireccion(); // Controlar dirección del motor
        CyDelay(10);      // Pausa para evitar actualizaciones demasiado rápidas
    }
}
