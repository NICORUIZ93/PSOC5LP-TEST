#ifndef L298N_H
#define L298N_H

#include <stdint.h>

void L298N_Init(void);
void L298N_Forward(uint8_t pwm_value);
void L298N_Backward(uint8_t pwm_value);
void L298N_Stop(void);

#endif /* L298N_H */
