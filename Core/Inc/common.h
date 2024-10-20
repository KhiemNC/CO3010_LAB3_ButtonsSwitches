/*
 * common.h
 *
 *  Created on: Oct 19, 2024
 *      Author: nguye
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include "main.h"

// BUTTON
#define NORMAL_STATE 1
#define PRESSED_STATE 0

// LED CONTROL
#define LED_ON 0
#define LED_OFF 1
#define ENABLE 1
#define DISABLE 0

extern int led_7seg_buffer[4];

extern int counter_way0;
extern int counter_way1;

extern int red_time;
extern int yel_time;
extern int grn_time;

extern int red_temp_time;
extern int yel_temp_time;
extern int grn_temp_time;


#endif /* INC_COMMON_H_ */
