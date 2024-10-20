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
#include "button.h"
#include "common.h"
#include "led_7_segment.h"

enum TrafficLightState
{
	INIT,
	AUTO_RED_GRN,
	AUTO_RED_YEL,
	AUTO_GRN_RED,
	AUTO_YEL_RED,
	MAN_RED_GRN,
	MAN_RED_YEL,
	MAN_GRN_RED,
	MAN_YEL_RED,
	RED_TIME_CONFIG,
	RED_TIME_CONFIG_CHANGE,
	YEL_TIME_CONFIG,
	YEL_TIME_CONFIG_CHANGE,
	GRN_TIME_CONFIG,
	GRN_TIME_CONFIG_CHANGE
};

void init_traffic_light();
void fsm_traffic_light();

void turn_on_red_grn();
void turn_on_red_yel();
void turn_on_grn_red();
void turn_on_yel_red();

void auto_red_grn();
void auto_red_yel();
void auto_grn_red();
void auto_yel_red();
void man_red_grn();
void man_red_yel();
void man_grn_red();
void man_yel_red();
void red_time_config();
void red_time_config_change();
void yel_time_config();
void yel_time_config_change();
void grn_time_config();
void grn_time_config_change();

#endif /* INC_TRAFFIC_LIGHT_H_ */
