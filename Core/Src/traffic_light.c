/*
 * traffic_light.c
 *
 *  Created on: 19 thg 10, 2024
 *      Author: nguye
 */

#include "traffic_light.h"

#define TIMER_READ_BTN 0
#define TIME_READ_BTN 20 // ms


#define TIMER_TRAFFIC_LIGHT 5

enum TrafficLightState TRAFFIC_LIGHT_STATE = INIT;

void init_traffic_light()
{
	setTimer(TIMER_READ_BTN, TIME_READ_BTN);

	display_a_digit(0, 11);
	display_a_digit(1, 11);
	display_a_digit(2, 11);
	display_a_digit(3, 11);
}

void fsm_traffic_light()
{
	switch (TRAFFIC_LIGHT_STATE) {
		case INIT:
			// TODO

			// CHANGE STATE
			if (1) // -> AUTO_RED_GRN
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			break;
		case AUTO_RED_GRN:
			auto_red_grn();

			// CHANGE STATE
			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_RED_YEL
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0
				setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_YEL;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				// BTN_0, red_temp_time
				red_temp_time = red_time;

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button2)) // -> MAN_RED_GRN
			{
				// BTN_1, BTN_2

				TRAFFIC_LIGHT_STATE = MAN_RED_GRN;
			}

			break;
		case AUTO_RED_YEL:
			auto_red_yel();

			// CHANGE STATE
			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_GRN_RED
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_GRN_RED;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				// BTN_0, red_temp_time
				red_temp_time = red_time;

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			break;
		case AUTO_GRN_RED:
			auto_grn_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_YEL_RED
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0
				setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_YEL_RED;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				// BTN_0, red_temp_time
				red_temp_time = red_time;

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button2)) // -> MAN_GRN_RED
			{
				// BTN_1, BTN_2

				TRAFFIC_LIGHT_STATE = MAN_GRN_RED;
			}
			break;
		case AUTO_YEL_RED:
			auto_yel_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_RED_GRN
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				// BTN_0, red_temp_time
				red_temp_time = red_time;

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			break;
		case MAN_RED_GRN:
			man_red_grn();

			if (isButtonPressed(&button1)) // -> MAN_RED_YEL
			{
				// TIMER_TRAFFIC_LIGHT
				setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

				TRAFFIC_LIGHT_STATE = MAN_RED_YEL;
			}
			else if (isButtonPressed(&button2)) // -> AUTO_RED_GRN
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			break;
		case MAN_RED_YEL:
			man_red_yel();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> MAN_GRN_RED
			{
				// BTN_1, BTN_2

				TRAFFIC_LIGHT_STATE = MAN_GRN_RED;
			}
			break;
		case MAN_GRN_RED:
			man_grn_red();

			if (isButtonPressed(&button1)) // -> MAN_YEL_RED
			{
				// TIMER_TRAFFIC_LIGHT
				setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);

				TRAFFIC_LIGHT_STATE = MAN_YEL_RED;
			}
			else if (isButtonPressed(&button2)) // -> AUTO_GRN_RED
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_GRN_RED;
			}
			break;
		case MAN_YEL_RED:
			man_yel_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> MAN_RED_GRN
			{
				// BTN_1, BTN_2

				TRAFFIC_LIGHT_STATE = MAN_RED_GRN;
			}
			break;
		case RED_TIME_CONFIG:
			red_time_config();

			if (isButtonPressed(&button0)) // -> YEL_TIME_CONFIG
			{
				// BTN_0, yel_temp_time
				yel_temp_time = yel_time;

				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			else if (red_temp_time != red_time) // -> RED_TIME_CONFIG_CHANGE
			{
				// BTN_0, BTN_2, red_temp_time

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG_CHANGE;
			}
			break;
		case RED_TIME_CONFIG_CHANGE:
			red_time_config_change();

			if (isButtonPressed(&button0)) // -> YEL_TIME_CONFIG
			{
				// BTN_0, yel_temp_time
				yel_temp_time = yel_time;

				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			else if (red_temp_time == red_time) // -> RED_TIME_CONFIG
			{
				// BTN_0, red_temp_time
				red_temp_time = red_time;

				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			break;
		case YEL_TIME_CONFIG:
			yel_time_config();

			if (isButtonPressed(&button0)) // -> GRN_TIME_CONFIG
			{
				// BTN_0, grn_temp_time
				grn_temp_time = grn_time;

				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			else if (yel_temp_time != yel_time) // -> YEL_TIME_CONFIG_CHANGE
			{
				// BTN_0, BTN_2, yel_temp_time

				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG_CHANGE;
			}
			break;
		case YEL_TIME_CONFIG_CHANGE:
			yel_time_config_change();

			if (isButtonPressed(&button0)) // -> GRN_TIME_CONFIG
			{
				// BTN_0, grn_temp_time
				grn_temp_time = grn_time;

				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			else if (yel_temp_time == yel_time) // -> YEL_TIME_CONFIG
			{
				// BTN_0, yel_temp_time
				yel_temp_time = yel_time;

				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			break;
		case GRN_TIME_CONFIG:
			grn_time_config();

			if (isButtonPressed(&button0)) // -> AUTO_RED_GRN
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (grn_temp_time != grn_time) // -> GRN_TIME_CONFIG_CHANGE
			{
				// BTN_0, BTN_2, grn_temp_time

				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG_CHANGE;
			}
			break;
		case GRN_TIME_CONFIG_CHANGE:
			grn_time_config_change();

			if (isButtonLongPressed(&button0)) // -> AUTO_RED_GRN
			{
				// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_2
				setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);

				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (grn_temp_time == grn_time) // -> GRN_TIME_CONFIG
			{
				// BTN_0, grn_temp_time
				grn_temp_time = grn_time;

				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			break;
		default:
			break;
	}

	if (isFlag(TIMER_READ_BTN))
	{
		getKeyInput(&button0);
		getKeyInput(&button1);
		getKeyInput(&button2);

		setTimer(TIMER_READ_BTN, TIME_READ_BTN);
	}

//	if (isButtonPressed(&button0))
//	{
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	}
//
//	if (isButtonPressed(&button1))
//	{
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	}
//
//	if (isButtonPressed(&button2))
//	{
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	}
}

void turn_on_red_grn()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void turn_on_red_yel()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_grn_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_ON);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_yel_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void auto_red_grn()
{
	display_a_digit(1, 1);

	turn_on_red_grn();
}
void auto_red_yel()
{
	display_a_digit(1, 2);

	turn_on_red_yel();
}
void auto_grn_red()
{
	display_a_digit(1, 3);

	turn_on_grn_red();
}
void auto_yel_red()
{
	display_a_digit(1, 4);

	turn_on_yel_red();
}
void man_red_grn()
{
	display_a_digit(1, 5);

	turn_on_red_grn();
}
void man_red_yel()
{
	display_a_digit(1, 6);

	turn_on_red_yel();
}
void man_grn_red()
{
	display_a_digit(1, 7);

	turn_on_grn_red();
}
void man_yel_red()
{
	display_a_digit(1, 8);

	turn_on_yel_red();
}
void red_time_config()
{
	display_a_digit(1, 9);

	if (isButtonPressed(&button1))
	{
		++red_temp_time;
		if (red_temp_time >= 10)
		{
			red_temp_time = 1;
		}
	}

	if (isButtonPressed(&button2))
	{
		red_time = red_temp_time;
	}
}
void red_time_config_change()
{
	display_a_digit(0, 0);

	if (isButtonPressed(&button1))
	{
		++red_temp_time;
		if (red_temp_time >= 10)
		{
			red_temp_time = 1;
		}
	}

	if (isButtonPressed(&button2))
	{
		red_time = red_temp_time;
	}
}
void yel_time_config()
{
	display_a_digit(0, 1);
}
void yel_time_config_change()
{
	display_a_digit(0, 2);
}
void grn_time_config()
{
	display_a_digit(0, 3);
}
void grn_time_config_change()
{
	display_a_digit(0, 4);
}
