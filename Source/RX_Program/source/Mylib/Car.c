#include "Car.h"
#include "Motor.h"
#include <stdio.h>
#include "main.h"
Motor_Typedef motor_left;
Motor_Typedef motor_right;

void car_control(CarState car_state, uint8_t speed)
{
		switch(car_state)
		{
			case CAR_STOP_STATE:
			{
				motor_control(&motor_left, MOTOR_STOP, 0);
				motor_control(&motor_right, MOTOR_STOP, 0);
				break;
			}
			case CAR_FORWARD_STATE:
			{
				motor_control(&motor_left, MOTOR_CW, speed);
				motor_control(&motor_right, MOTOR_CW, speed);
				break;
			}
			case CAR_BACKWARD_STATE:
			{
				motor_control(&motor_left, MOTOR_CCW, speed);
				motor_control(&motor_right, MOTOR_CCW, speed);
				break;
			}
			case CAR_LEFT_STATE:
			{
				
				motor_control(&motor_left, MOTOR_CW, 0);
				motor_control(&motor_right, MOTOR_CCW, speed);
				break;
			}
			case CAR_RIGHT_STATE:
			{
				motor_control(&motor_left, MOTOR_CCW, speed);
				motor_control(&motor_right, MOTOR_CW, 0);
				break;
			}
		}
}

void car_init(TIM_HandleTypeDef *htim)
{
	motor_init(&motor_left,MOTOR1_IN1_IO_GPIO_Port, MOTOR1_IN1_IO_Pin, htim, TIM_CHANNEL_1);
	motor_init(&motor_right, MOTOR2_IN3_IO_GPIO_Port, MOTOR2_IN3_IO_Pin, htim, TIM_CHANNEL_2);
	
	car_control(CAR_STOP_STATE, 0);
}
