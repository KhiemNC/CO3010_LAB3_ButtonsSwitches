/*
 * traffic_light.h
 *
 *  Created on: 19 thg 10, 2024
 *      Author: nguye
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "software_timer.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE 1
#define DISABLE 0

void init_traffic_light();
void fsm_traffic_light();

#endif /* INC_TRAFFIC_LIGHT_H_ */
