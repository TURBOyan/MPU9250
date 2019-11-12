#ifndef _MPU9250_CONFIG_H_
#define _MPU9250_CONFIG_H_

/*************************************/
//������ͷ�ļ�Ŀ��Ϊ�����������ͣ���Ϊ�˿���unsign char����Ϊu8����Ҫ�����궨��Ϊ��Ҫ��ֲ��ƽ̨�����ݵ�����
#include "common.h"			
#define u8  uint8
#define u16 uint16
#define u32 uint32
/*************************************/

/*!!!***********************************!!!*/
//������ͷ�ļ�Ŀ��Ϊ���뵥Ƭ����GPIO����ͷ�ļ�
//�������gpio������Ҫ����Ƿ�����GPIO����ͷ�ļ�������˴���LPC546XX_gpio
//����������������裬��Ҫ���˿ڸ���ͷ�ļ�������˴���LPC546XX_iocon
#include "LPC546XX_gpio.h"
#include "LPC546XX_iocon.h"


/*!!!***********************************!!!*/
//������ͷ�ļ���Ŀ��Ϊ������ʱ����
//������ʱ����ͷ�ļ�������Ҫ�������������·���delay_us��delay_ms,��Ҫע���β������β���ֻ������һ��
#include "LPC546XX_pll.h"
#include "LPC546XX_systick.h"


/*!!!***********************************!!!*/
//�˴��������USE_DMP���������̬�ǲ��ںϴ����ƽ��м���
//�˴��������USE_MPL���������̬���ںϴ�����
//һ�㶼��USE_MPL����Ϊ���ںϴ����Ƶ�ƫ���ǻ�Ư
//�����ʹ��ƫ���ǣ�����Կ���ʹ��USE_DMP�����Խ�ʡʱ��

//#define USE_DMP
#define USE_MPL	

/*!!!***********************************!!!*/
//�˴����ⲿ����ʱ������������
//ע���β���ֻ����һ��������delay_us(1)Ϊ��ʱ1us
#define delay_us systick_delay_us
#define delay_ms systick_delay_ms 

/*!!!***********************************!!!*/
//MPU9250��IICͨѶ���ţ�����Ҫ����������
#define MY_SCL_GPIO   A14 	//MPU��SCL��
#define MY_SDA_GPIO   A13	//MPU��SDA��

/*!!!***********************************!!!*/
//�˴����ⲿ��GPIO������������
//��Ҫ����������Ϊ���ģʽ���Ҵ���������
#define PIN_Init(x)   gpio_init(x, GPO, 1,PULLUP)

/*!!!***********************************!!!*/
//�˴����ⲿ��GPIO������������
//IO��������
#define Config_SDA_IN()  		gpio_dir(MY_SDA_GPIO, GPI)	//��SDA����Ϊ����ģʽ
#define Config_SDA_OUT() 		gpio_dir(MY_SDA_GPIO, GPO) 	//��SDA����Ϊ���ģʽ
//IO��������	 
#define Config_IIC_SCL(x)    gpio_set(MY_SCL_GPIO, x) //����SCL��ƽ
#define Config_IIC_SDA(x)    gpio_set(MY_SDA_GPIO, x) //����SDA��ƽ
#define Config_READ_SDA   	 gpio_get(MY_SDA_GPIO)    //��ȡSDA��ƽ

#endif


//**********************************written by TURBO*******************************************************/
//**********************************���ں�:�ز�����*******************************************************/
