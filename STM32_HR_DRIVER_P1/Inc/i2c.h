#ifndef __I2C_SW_H
#define __I2C_SW_H

/* includes */
//#include "stm32f10x.h"
//#include "stdio.h"

/* defines */
#define GPIO_SW_I2C_SCL 		GPIOB
#define GPIO_SW_I2C_SCL_PIN 	GPIO_PIN_14
#define GPIO_SW_I2C_SDA 		GPIOB
#define GPIO_SW_I2C_SDA_PIN 	GPIO_PIN_15

/* functions */
//void SW_I2C_initial(void);

void i2c_port_initial(uint8_t sel);
void i2c_start_condition(uint8_t sel);
void i2c_stop_condition(uint8_t sel);
//uint8_t i2c_check_ack(uint8_t sel);
//void i2c_check_not_ack(uint8_t sel);
//void i2c_slave_address(uint8_t sel, uint8_t IICID, uint8_t readwrite);
//void i2c_register_address(uint8_t sel, uint8_t addr);
void i2c_send_ack(uint8_t sel);


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

