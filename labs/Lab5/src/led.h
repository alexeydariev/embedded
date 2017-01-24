
#ifndef SRC_LED_H_
#define SRC_LED_H_
#include <avr/io.h>
#include "stdint.h"

void init_led();
void turn_on(uint32_t pin);
void turn_off(uint32_t pin);
void toogle_led(uint32_t pin);

#endif /* SRC_LED_H_ */
