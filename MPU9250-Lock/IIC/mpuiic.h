#ifndef __MPUIIC_H
#define __MPUIIC_H

#include "MPU9250_Config.h"		//移植所需要配置的文件

//IO方向设置
#define SDA_IN()  		Config_SDA_IN() 	//输入模式
#define SDA_OUT() 		Config_SDA_OUT() //输出模式
//IO操作函数	 
#define IIC_SCL(x)    Config_IIC_SCL(x) //SCL
#define IIC_SDA(x)    Config_IIC_SDA(x)  //SDA	 
#define READ_SDA   		Config_READ_SDA  //输入SDA 

//IIC所有操作函数
void IIC_Delay(void);				//MPU IIC延时函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

#endif
















