#include "project.h"
#include "stdio.h"
#include "L298N.h"
#include "SSD1306.h"

int32_t conversion;
float32 ADCVoltaje;
char mensaje[256];
uint8_t pwm_value;
uint8_t direccion = 0; // 0: derecha, 1: izquierda, 2: stop
uint8_t stop_button_pressed = 0;

void init() {
    CyGlobalIntEnable;
    SSD1306_Init();
    UART_Start();
    UART_PutString("Sistema inicializado.\r\n");
    UART_PutString("Use el potenciometro para ajustar la velocidad.\r\n");
    UART_PutString("Presione el boton para cambiar la direccion/parar.\r\n");
    ADC_Start();
    Opamp_Start();
    PWM1_Start();
    PWM2_Start();
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
    char dir_str[20];
    if (direccion == 0) {
        sprintf(dir_str, "Dir: Derecha");
    } else if (direccion == 1) {
        sprintf(dir_str, "Dir: Izquierda");
    } else {
        sprintf(dir_str, "Dir: STOP");
    }
    SSD1306_SetCursor(0, 8);
    SSD1306_WriteString(dir_str);

    // Mostrar Voltaje en la tercera línea del OLED
    sprintf(mensaje, "Voltaje: %.2f V", ADCVoltaje);
    SSD1306_SetCursor(0, 16);
    SSD1306_WriteString(mensaje);
}

void actualizarPWM() {
    // Iniciar conversión ADC
    ADC_StartConvert();
    while (!ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {}

    // Calcular voltaje (suponiendo ADC de 20 bits y referencia de 5V)
    conversion = ADC_GetResult32();
    ADCVoltaje = (conversion * 5.0) / 1048575.0;

    // Calcular valor PWM
    pwm_value = (uint8_t)((ADCVoltaje / 5.0) * 255);
    if (pwm_value > 255) pwm_value = 255; // Limitar valor máximo
}

void controlDireccion() {
    if (DIRECCION_Read() == 0) { // Leer estado del botón
        CyDelay(50); // Anti-rebote
        if (DIRECCION_Read() == 0) {
            // Cambiar dirección/parar
            if (direccion == 0) {
                direccion = 1; // Izquierda
            } else if (direccion == 1) {
                direccion = 2; // STOP
            } else {
                direccion = 0; // Derecha
            }

            // Imprimir dirección en UART
            char dir_str[30];
            if (direccion == 0) {
                sprintf(dir_str, "Direccion: Derecha\r\n");
            } else if (direccion == 1) {
                sprintf(dir_str, "Direccion: Izquierda\r\n");
            } else {
                sprintf(dir_str, "Direccion: STOP\r\n");
            }
            UART_PutString(dir_str);
        }
        while (DIRECCION_Read() == 0); // Esperar que se suelte el botón
        SSD1306_Clear();
    }

    // Controlar el motor según la dirección
    if (direccion == 0) {
        L298N_Forward(pwm_value);
    } else if (direccion == 1) {
        L298N_Backward(pwm_value);
    } else {
        L298N_Stop();
    }
}


int main(void) {
    init();
    SSD1306_Clear();

    for (;;) {
        actualizarPWM();  // Actualizar el valor de pwm_value
        printData();      // Actualizar datos del PWM, voltaje y dirección
        controlDireccion(); // Controlar dirección del motor

        CyDelay(10);      // Pausa para evitar actualizaciones demasiado rápidas
    }
}
