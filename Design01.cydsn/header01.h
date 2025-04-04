#ifndef L298N_H
#define L298N_H

#include <stdint.h>

void L298N_Init(void);
void L298N_Forward(void);
void L298N_Backward(void);
void L298N_Stop(void);

#endif /* L298N_H */
