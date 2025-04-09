#include "L298N.h"
#include "project.h"

uint8_t pwm_value;

void L298N_Init(void) {
    PWM1_WriteCompare(0);
    PWM2_WriteCompare(0);
}

void L298N_Forward(uint8_t pwm_value) {
    PWM1_WriteCompare(pwm_value);
    PWM2_WriteCompare(0);
}

void L298N_Backward(uint8_t pwm_value) {
    PWM1_WriteCompare(0);
    PWM2_WriteCompare(pwm_value);
}

void L298N_Stop(void) {
    PWM1_WriteCompare(0);
    PWM2_WriteCompare(0);
}
