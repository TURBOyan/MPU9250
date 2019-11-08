#ifndef __MPUIIC_H
#define __MPUIIC_H

#include "MPU9250_Config.h"		//��ֲ����Ҫ���õ��ļ�

//IO��������
#define SDA_IN()  		Config_SDA_IN() 	//����ģʽ
#define SDA_OUT() 		Config_SDA_OUT() //���ģʽ
//IO��������	 
#define IIC_SCL(x)    Config_IIC_SCL(x) //SCL
#define IIC_SDA(x)    Config_IIC_SDA(x)  //SDA	 
#define READ_SDA   		Config_READ_SDA  //����SDA 

//IIC���в�������
void IIC_Delay(void);				//MPU IIC��ʱ����
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

#endif
















