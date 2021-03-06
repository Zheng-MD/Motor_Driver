#ifndef __AS5048A_H__
#define __AS5048A_H__
#include "main.h"

/***************ADIS_CS GPIO����******************/

#define  AS5048_CS_RCC           RCC_APB2Periph_GPIOA
#define  AS5048_CS_PORT          GPIOA
#define  AS5048_CS_Pin    			 GPIO_Pin_15

#define  AS5048_CS_LOW      GPIO_ResetBits(AS5048_CS_PORT,AS5048_CS_Pin)
#define  AS5048_CS_HIGH     GPIO_SetBits(AS5048_CS_PORT,AS5048_CS_Pin)
#define  AS5048_CS_TOGGLE  	AS5048_CS_PORT->ODR ^= AS5048_CS_Pin


#define AS5048_ANGLE					0xFFFF


typedef struct _as5048
{
    uint16_t       reg;
    _Bool     ef;
    long pos_sum;
    float       speed;
    float       speed_ef;
	  int    speed_jscop;
} as5048_t;

void AS5048_Init(void);
int as5048_read_angle(void);
int as5048_singelread_angle(void);
void as5048_data_prepare(void);

extern as5048_t as5048_A;
extern as5048_t as5048_B;

#endif
