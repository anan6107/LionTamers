/*
 * PWM_Test_1280.c
 *
 * Created: 2/26/2020 8:06:14 PM
 * Author : justin 
 */ 

#include <avr/io.h>
#define F_CPU	16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>

#define ms(x)		_delay_ms(x)
#define us(x)		_delay_us(x)

#define DEFAULT_SPEED_DUTY_CYCLE	50

#define SPEED_PWM_PIN		PE3
#define FWD_BCK_PIN			PE4
#define LFT_RGT_PIN			PE5

#define SPEED_OCR_REG		OCR3A
#define FWD_BCK_OCR_REG		OCR3B
#define LFT_RGT_OCR_REG		OCR3C

#define PWM_FREQ_HZ			500
#define PWM_TOP_MAX			65535
#define PWM_TOP_VAL			F_CPU / (PWM_FREQ_HZ * 2)

#define PWM_HIGHEST_MILLIVOLT	(uint32_t)5000
#define PWM_IDLE_MILLIVOLT		(uint32_t)2500
#define PWM_FWD_MILLIVOLT		(uint32_t)4000
#define PWM_BCK_MILLIVOLT		(uint32_t)1000
#define PWM_RGT_MILLIVOLT		(uint32_t)4000
#define PWM_LFT_MILLIVOLT		(uint32_t)1000

#define PWM_FWD_STATE			1
#define PWM_BCK_STATE			0
#define PWM_LFT_STATE			1
#define PWM_RGT_STATE			0

// Return 1 - Error 0 - Good
bool PWM_Init(void)
{
	// Set all 3 pins as output
	DDRE |= (1 << SPEED_PWM_PIN) | (1 << FWD_BCK_PIN) | (1 << LFT_RGT_PIN);
	
	// Enable OC3A, OC3B, and OC3C pins - clear when upcounting, set when downcounting
	TCCR3A |= (1 << COM3A1) | (1 << COM3B1) | (1 << COM3C1);
	
	// Frequency and phase corrected PWM mode, prescaler is 1
	TCCR3B |= (1 << WGM33) | (1 << CS30);
	
	// Setting TOP value in ICR3 for 500Hz freq
	if(PWM_TOP_VAL > PWM_TOP_MAX)
	{
		return 1;
	}
	ICR3 = PWM_TOP_VAL;
	
	// Sanity check
	TCNT3 = 0;
	
	return 0;
	
}

// Return 1 - Error 0 - Good
bool PWM_Speed_Update(uint8_t speed_duty)
{
	if(speed_duty > 100)
	{
		return 1;
	}
	SPEED_OCR_REG = (uint32_t)(speed_duty * PWM_TOP_VAL) / 100;
	return 0;
}

// Return 1 - Error 0 - Good
bool PWM_F_B_Update(bool F_or_B)	// Forward: 1 // Backward: 0
{
	uint8_t speed_duty = 50;
	LFT_RGT_OCR_REG = (uint32_t)(speed_duty * PWM_TOP_VAL) / 100;
	if(F_or_B == PWM_FWD_STATE)
	{
		FWD_BCK_OCR_REG = PWM_FWD_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
	}
	else if(F_or_B == PWM_BCK_STATE)
	{
		FWD_BCK_OCR_REG = PWM_BCK_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
	}
	else
	{
		return 1;
	}
	return 0;
}

// Return 1 - Error 0 - Good
bool PWM_L_R_Update(bool L_or_R)	// Left: 1 // Right: 0
{
		uint8_t speed_duty = 50;
		FWD_BCK_OCR_REG = (uint32_t)(speed_duty * PWM_TOP_VAL) / 100;
		if(L_or_R == PWM_LFT_STATE)
		{
			LFT_RGT_OCR_REG = PWM_LFT_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
		}
		else if(L_or_R == PWM_RGT_STATE)
		{
			LFT_RGT_OCR_REG = PWM_RGT_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
		}
		else
		{
			return 1;
		}
		return 0;
}

void Robot_Stop(void)
{
	FWD_BCK_OCR_REG = PWM_IDLE_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
	LFT_RGT_OCR_REG = PWM_IDLE_MILLIVOLT * (PWM_TOP_VAL / PWM_HIGHEST_MILLIVOLT);
}

void Dig_Read_Setup(uint8_t Pin)
{
	DDRA &= ~(1 << Pin);
	PORTA |= (1 << Pin);
}

bool Digital_Read(uint8_t Pin)
{
	return ((PINA & (1 << Pin)) >> Pin);
}

int main(void)
{
    
	PWM_Init();
	PWM_Speed_Update(95);
	
//	uint8_t speed_duty = 0, i = 0;
	
    while (1) 
    {
/*		if(i == 0)
		{
			while(1)
			{
				PWM_Speed_Update(speed_duty);
				ms(20);			
				speed_duty += 1;
				if(speed_duty == 100)
				{
					i = 1;
					break;
				}
			}
		}
		else if(i == 1)
		{
			while(1)
			{
				PWM_Speed_Update(speed_duty);
				ms(20);
				speed_duty -= 1;
				if(speed_duty == 0)
				{
					i = 0;
					break;
				}
			}
		}*/
		//Robot_Stop();
		//ms(3000);
		//PWM_F_B_Update(PWM_FWD_STATE);
		//ms(5000);
		//Robot_Stop();
		//ms(5000);
		//PWM_F_B_Update(PWM_BCK_STATE);
		//ms(5000);
		//Robot_Stop();
		//ms(5000);
		//PWM_L_R_Update(PWM_LFT_STATE);
		//ms(5000);
		//Robot_Stop();
		//ms(5000);
		PWM_L_R_Update(PWM_RGT_STATE);
		//ms(5000);
		//PWM_L_R_Update(PWM_RGT_STATE);
		//ms(5000);
		//Robot_Stop();
		//ms(5000);
    }
}

