/*
 * led_7_segment.h
 *
 *  Created on: Oct 19, 2024
 *      Author: nguye
 */

#ifndef INC_LED_7_SEGMENT_H_
#define INC_LED_7_SEGMENT_H_

#include "main.h"
#include "common.h"

void update_led_7seg_buffer();
void display_a_digit(int digit, int num);
void display_number(int num);
void enable_digit(int digit);


#endif /* INC_LED_7_SEGMENT_H_ */
