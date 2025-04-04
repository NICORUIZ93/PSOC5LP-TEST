#include "L298N.h"
#include "project.h"

// Definir pines para el control del motor B
#define IN3  P0_0
#define IN4  P0_1

void L298N_Init(void) {
    // Inicializar pines como salidas
    IN3_Write(0);
    IN4_Write(0);
}

void L298N_Forward(void) {
    IN3_Write(1); // Motor B hacia adelante
    IN4_Write(0);
}

void L298N_Backward(void) {
    IN3_Write(0); // Motor B hacia atrás
    IN4_Write(1);
}

void L298N_Stop(void) {
    IN3_Write(0); // Motor B parado
    IN4_Write(0);
}
