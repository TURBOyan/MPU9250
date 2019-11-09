#ifndef _MPU_FORUSER_H_
#define _MPU_FORUSER_H_

#include "mpu9250.h"
#include "MPU9250_Config.h"		//移植所需要配置的文件

/*
 * 定义坐标结构体
 */
typedef struct
{
      float x;
      float y;
      float z;
}FLOAT_XYZ;

typedef struct
{
      int32 x;
      int32 y;
      int32 z;
}INT32_XYZ;

typedef struct
{
      int16 x;
      int16 y;
      int16 z;
}INT16_XYZ;

//所有MPU的数据均保存在此结构体内，可以被所有包含了MPU_ForUser.h的文件所调用
extern struct MPU_Typedef		
{
		int16 TEMP;		//温度值
		
		INT16_XYZ
			GYRO,				// 陀螺仪原始数据
			GYRO_Last,	// 陀螺仪历史数据
			ACC, 				// 加速度计原始数据
			ACC_Last,		// 加速度计历史数据
			MAG,				//磁力计原始数据
			MAG_Last;		//磁力计历史数据
	
/************************************************/
//滤波函数需要你们自己添加，添加完成了以后可以激活这三个数据来用
//		FLOAT_XYZ 		
//			GYRO_Real,		// 陀螺仪滤波后的数据
//			ACC_Real,			// 加速度计滤波后的数据
//			MAG_Real;			//磁力计滤波以后的数据
	
		float	
			Pitch,		//俯仰角原始值
			Roll,			//翻滚角原始值
			Yaw,			//偏航角原始值

/************************************************/
		//这里的数据用在三态角重设零点和归为0-360度用，只适用于-180到180的数据，不适用与俯仰角，因为俯仰角范围为-90到90
			Yaw_Real,		//归为0-360度以后的偏航角值
			Yaw_Save,		//保存当前角度的偏航角原始值，用作重设零点
		
			Roll_Real,		//归为0-360度以后的翻滚角值
			Roll_Save,		//保存当前角度的翻滚角原始值，用作重设零点
/************************************************/
		
			Pitch_Last,		//历史俯仰角
			Roll_Last,		//历史翻滚角
			Yaw_Last;			//历史偏航角

}MPU_Data;


typedef enum
{
	ACC,			//三轴加速度
	GYRO,			//三轴角速度
	MAG,			//三轴磁力计
	TEMP,		  //温度
	DMP_MPL,	//三态角
}MPU_DataTeam_TypeDef;


/*!!!***********************************!!!*/
//MPU初始化函数，一般主函数内只需要调用此函数
//形参    ：  无
//返回值  ：成功--0，失败--1
//调用示例：	while(MPU_Init_ForUser());
uint8 MPU_Init_ForUser(void);

/*!!!***********************************!!!*/
//MPU自检函数，只有在MPU芯片正面朝上，且保持静止时，自检才能通过
//形参    ：  无
//返回值  ：成功--0，失败--其他
//调用示例：	while(MPU_Selftest());
uint8 MPU_Selftest(void);

/*!!!***********************************!!!*/
//MPU数据读取函数，调用一次，则刷新一次数据，刷新的数据保存在MPU_Data结构体内
//形参    ：  参照枚举体MPU_DataTeam_TypeDef，写枚举体里的什么，刷新的就是什么数据，
//						例如写DMP_MPL,则刷新三态角，数据保存在结构体的yaw，pitch，roll原始数据中
//返回值  ：成功--0，失败--无
//调用示例：	Refresh_MPUTeam(DMP_MPL);	//刷新三态角，调用这句话，则立即刷新三态角至MPU_Data.Yaw、MPU_Data.Pitch、MPU_Data.roll，
//																			由于结构体为全局结构体，所以这三个数据可以在任何包括了MPU_ForUser.h的文件内调用
//备注
/*pitch:俯仰角 精度:0.1°   范围:-90.0° <---> +90.0°
  roll:横滚角  精度:0.1°   范围:-180.0°<---> +180.0°
  yaw:航向角   精度:0.1°   范围:-180.0°<---> +180.0°*/
uint8 Refresh_MPUTeam(MPU_DataTeam_TypeDef MPU_DataTeam);	//更新MPU数据

/*!!!***********************************!!!*/
//顾名思义，保存MPU数据，操作方法和Refresh_MPUTeam函数相同
//形参    ：参照枚举体MPU_DataTeam_TypeDef
//返回值  ：成功--0，失败--其他
//调用示例：	Refresh_MPUTeam(DMP_MPL);	//保存三态角值，至MPU_Data.Yaw_Last..等等
uint8 Save_MPUTeam(MPU_DataTeam_TypeDef MPU_DataTeam);		//保存MPU上次数据

/*!!!***********************************!!!*/
//将传入的当前偏航角或翻滚角值作为零点，重新定义三态坐标，并且将值从-180到180归为0到360
//形参    ：Mpu_Value-实时传入偏航角或翻滚角原始值
//				  Mpu_Zero -设置的偏航角或翻滚角零点
//返回值  ：重新定义的偏航角或翻滚角值
//调用示例：	Mpu_Normalization(MPU_Data.Yaw,MPU_Data.Yaw_Save); 	//MPU_Data.Yaw_Save为执行此函数之前就已经保存的当前车模偏航角值
//																																最后的输出值即以此偏航角原始值为零点
float Mpu_Normalization(float Mpu_Value,float Mpu_Zero);  //Mpu三态角值归为0-360

#endif


//**********************************written by TURBO*******************************************************/
//**********************************公众号:特博工坊*******************************************************/