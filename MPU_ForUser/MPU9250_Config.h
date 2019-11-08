#ifndef _MPU9250_CONFIG_H_
#define _MPU9250_CONFIG_H_

/*************************************/
//包含此头文件目的为兼容数据类型，因为此库内unsign char定义为u8，需要将他宏定义为所要移植的平台所兼容的类型
#include "common.h"			
#define u8  uint8
#define u16 uint16
#define u32 uint32
/*************************************/

/*!!!***********************************!!!*/
//包含此头文件目的为引入单片机的GPIO操作头文件
//如果报错gpio操作则要检查是否引入GPIO操作头文件，例如此处的LPC546XX_gpio
//如果报错上下拉电阻，则要检查端口复用头文件，例如此处的LPC546XX_iocon
#include "LPC546XX_gpio.h"
#include "LPC546XX_iocon.h"


/*!!!***********************************!!!*/
//包含此头文件的目的为引入延时功能
//引入延时功能头文件后则需要将函数名传入下方的delay_us和delay_ms,需要注意形参量，形参量只允许有一个
#include "LPC546XX_pll.h"
#include "LPC546XX_systick.h"


/*!!!***********************************!!!*/
//此处如果定义USE_DMP则输出的三态角不融合磁力计进行计算
//此处如果定义USE_MPL则输出的三态角融合磁力计
//一般都用USE_MPL，因为不融合磁力计的偏航角会漂
//如果不使用偏航角，则可以考虑使用USE_DMP，可以节省时间

//#define USE_DMP
#define USE_MPL	

/*!!!***********************************!!!*/
//此处将外部的延时操作函数传入
//注意形参量只能有一个，例如delay_us(1)为延时1us
#define delay_us systick_delay_us
#define delay_ms systick_delay_ms 

/*!!!***********************************!!!*/
//MPU9250的IIC通讯引脚，最重要的两个引脚
#define MY_SCL_GPIO   A9 	//MPU的SCL脚
#define MY_SDA_GPIO   A8	//MPU的SDA脚

/*!!!***********************************!!!*/
//此处将外部的GPIO操作函数传入
//需要将引脚配置为输出模式，且带上拉电阻
#define PIN_Init(x)   gpio_init(x, GPO, 1,PULLUP)

/*!!!***********************************!!!*/
//此处将外部的GPIO操作函数传入
//IO方向设置
#define Config_SDA_IN()  		gpio_dir(MY_SDA_GPIO, GPI)	//将SDA配置为输入模式
#define Config_SDA_OUT() 		gpio_dir(MY_SDA_GPIO, GPO) 	//将SDA配置为输出模式
//IO操作函数	 
#define Config_IIC_SCL(x)    gpio_set(MY_SCL_GPIO, x) //设置SCL电平
#define Config_IIC_SDA(x)    gpio_set(MY_SDA_GPIO, x) //设置SDA电平
#define Config_READ_SDA   	 gpio_get(MY_SDA_GPIO)    //读取SDA电平

#endif
