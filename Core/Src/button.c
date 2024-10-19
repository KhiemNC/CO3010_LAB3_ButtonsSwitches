/*
 * button.c
 *
 *  Created on: Oct 17, 2024
 *      Author: nguye
 */

#include "button.h"

struct ButtonStruct button1 =
{
	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}, // keyBuffer
	500, // timeOutForPressed
	0, // isPressed
	0, // isLongPressed
	0, // flag
	BUTTON_1_GPIO_Port,
	BUTTON_1_Pin
};

struct ButtonStruct button2 =
{
	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}, // keyBuffer
	500, // timeOutForPressed
	0, // isPressed
	0, // isLongPressed
	0, // flag
	BUTTON_2_GPIO_Port,
	BUTTON_2_Pin
};

void getKeyInput(struct ButtonStruct* button)
{
	button->keyBuffer[2] = button->keyBuffer[1];
	button->keyBuffer[1] = button->keyBuffer[0];

	button->keyBuffer[0] = HAL_GPIO_ReadPin(button->PORT, button->PIN);

	if ((button->keyBuffer[0] == button->keyBuffer[1]) && (button->keyBuffer[1] == button->keyBuffer[2]))
	{
		if (button->keyBuffer[2] != button->keyBuffer[3])
		{
			button->keyBuffer[3] = button->keyBuffer[2];

			if (button->keyBuffer[3] == PRESSED_STATE)
			{
				button->timeOutForPressed = 500;

				// subKeyProcess();
				button->flag = 1;
			}
		}
		else // button->keyBuffer[2] == button->keyBuffer[3]
		{
			--button->timeOutForPressed;
			if (button->timeOutForPressed <= 0)
			{
				button->timeOutForPressed = 500;
				if (button->keyBuffer[3] == PRESSED_STATE)
				{
					// subKeyProcess();
					button->flag = 1;
				}
			}
		}
	}
}

int isButtonPressed(struct ButtonStruct* button)
{
	if (button->flag == 1)
	{
		button->flag = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(struct ButtonStruct* button)
{
	if (button->isLongPress == 1)
	{
		button->isLongPress = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(struct ButtonStruct* button)
{
	// TODO
	// HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button->flag = 1;
}
