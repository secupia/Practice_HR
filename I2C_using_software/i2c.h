#ifndef __I2C_SW_H
#define __I2C_SW_H

/* includes */
#include "stm32f10x.h"
#include "stdio.h"

/* defines */
#define GPIO_SW_I2C1_SCL 		GPIOC
#define GPIO_SW_I2C1_SCL_PIN 	GPIO_Pin_0
#define GPIO_SW_I2C1_SDA 		GPIOB
#define GPIO_SW_I2C1_SDA_PIN 	GPIO_Pin_14

#define GPIO_SW_I2C2_SCL 		GPIOB
#define GPIO_SW_I2C2_SCL_PIN 	GPIO_Pin_1
#define GPIO_SW_I2C2_SDA 		GPIOC
#define GPIO_SW_I2C2_SDA_PIN 	GPIO_Pin_1

#define GPIO_SW_I2C3_SCL 		GPIOB
#define GPIO_SW_I2C3_SCL_PIN 	GPIO_Pin_6
#define GPIO_SW_I2C3_SDA 		GPIOB
#define GPIO_SW_I2C3_SDA_PIN 	GPIO_Pin_7

#define GPIO_SW_I2C4_SCL 		GPIOB
#define GPIO_SW_I2C4_SCL_PIN 	GPIO_Pin_10
#define GPIO_SW_I2C4_SDA 		GPIOB
#define GPIO_SW_I2C4_SDA_PIN 	GPIO_Pin_11

#define GPIO_SW_I2C5_SCL 		GPIOC
#define GPIO_SW_I2C5_SCL_PIN 	GPIO_Pin_6
#define GPIO_SW_I2C5_SDA 		GPIOC
#define GPIO_SW_I2C5_SDA_PIN 	GPIO_Pin_5

#define GPIO_SW_I2C6_SCL 		GPIOA
#define GPIO_SW_I2C6_SCL_PIN 	GPIO_Pin_6
#define GPIO_SW_I2C6_SDA 		GPIOC
#define GPIO_SW_I2C6_SDA_PIN 	GPIO_Pin_8

#define GPIO_SW_I2C7_SCL 		GPIOC
#define GPIO_SW_I2C7_SCL_PIN 	GPIO_Pin_10
#define GPIO_SW_I2C7_SDA 		GPIOA
#define GPIO_SW_I2C7_SDA_PIN 	GPIO_Pin_1

#define GPIO_SW_I2C8_SCL 		GPIOC
#define GPIO_SW_I2C8_SCL_PIN 	GPIO_Pin_12
#define GPIO_SW_I2C8_SDA 		GPIOC
#define GPIO_SW_I2C8_SDA_PIN 	GPIO_Pin_11

#define GPIO_SW_I2C9_SCL 		GPIOB
#define GPIO_SW_I2C9_SCL_PIN 	GPIO_Pin_12
#define GPIO_SW_I2C9_SDA 		GPIOA
#define GPIO_SW_I2C9_SDA_PIN 	GPIO_Pin_5

#define GPIO_SW_I2C10_SCL 		GPIOB
#define GPIO_SW_I2C10_SCL_PIN 	GPIO_Pin_12
#define GPIO_SW_I2C10_SDA 		GPIOA
#define GPIO_SW_I2C10_SDA_PIN 	GPIO_Pin_5

#define SW_I2C1 				1
#define SW_I2C2 				2
#define SW_I2C3 				3
#define SW_I2C4 				4
#define SW_I2C5 				5
#define SW_I2C6 				6
#define SW_I2C7 				7
#define SW_I2C8 				8
#define SW_I2C9 				9
#define SW_I2C10 				10

/* functions */
void SW_I2C_initial(void);

void i2c_port_initial(uint8_t sel);

uint8_t SW_I2C_ReadVal_SDA(uint8_t sel);

void SW_I2C_Write_Data(uint8_t sel, uint8_t data);
uint8_t SW_I2C_Read_Data(uint8_t sel);

uint8_t SW_I2C_WriteControl_8Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint8_t data);
uint8_t SW_I2C_WriteControl_8Bit_OnlyRegAddr(uint8_t sel, uint8_t IICID, uint8_t regaddr);
uint8_t SW_I2C_WriteControl_16Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint16_t data);

uint8_t SW_I2C_ReadControl_8Bit_OnlyRegAddr(uint8_t sel, uint8_t IICID, uint8_t regaddr);
uint8_t SW_I2C_ReadControl_8Bit_OnlyData(uint8_t sel, uint8_t IICID);
uint16_t SW_I2C_ReadControl_16Bit_OnlyData(uint8_t sel, uint8_t IICID);
uint8_t SW_I2C_ReadControl_8Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr);
uint16_t SW_I2C_ReadControl_16Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr);

uint8_t SW_I2C_ReadnControl_8Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint8_t rcnt, uint8_t (*pdata));
uint8_t SW_I2C_Multi_ReadnControl_8Bit(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint8_t rcnt, uint8_t (*pdata));
uint8_t SW_I2C_Check_SlaveAddr(uint8_t sel, uint8_t IICID);

uint8_t SW_I2C_UTIL_WRITE(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint8_t data);
uint8_t SW_I2C_UTIL_Read(uint8_t sel, uint8_t IICID, uint8_t regaddr);
uint8_t SW_I2C_UTIL_Read_Multi(uint8_t sel, uint8_t IICID, uint8_t regaddr, uint8_t rcnt, uint8_t (*pdata));

#endif /* __I2C_SW_H */

