/*
 * i2c.h
 *
 *  Created on: 2020. 12. 7.
 *      Author: Marshall
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdbool.h>
#include "main.h"

#define TRUE  1
#define FALSE 0

#define OLED_CMD       0x00
#define OLED_DATA      0x40
#define I2C_SLAVE_ADDR 0x78

#define I2C_READ     0x01
#define READ_CMD     1
#define WRITE_CMD    0

//#define SW_I2C_WAIT_TIME  26 //100Khz(11.4us)
//#define SW_I2C_WAIT_TIME  25 //(11.0us)
//#define SW_I2C_WAIT_TIME  23 //(10.4us)
#define SW_I2C_WAIT_TIME        22 //100Khz(10.0us) 100Khz == 10us
//#define SW_I2C_WAIT_TIME  10 //195Khz
//#define SW_I2C_WAIT_TIME  9 //205Khz 200Khz == 5us
//#define SW_I2C_WAIT_TIME  8 //237Khz
//#define SW_I2C_WAIT_TIME  7 //240Khz 250Khz == 4us
//#define SW_I2C_WAIT_TIME  6 //275Khz
//#define SW_I2C_WAIT_TIME  5 //305Khz
//#define SW_I2C_WAIT_TIME  4 //350Khz(3.84us)
//#define SW_I2C_WAIT_TIME  3 //400Khz(3.44us)
//#define SW_I2C_WAIT_TIME  2 //425Khz(3.04us) 333Khz == 3us
//#define SW_I2C_WAIT_TIME  1 //425Khz(2.64us) 400Khz == 2.5us

//void    TIMER__Wait_us(volatile uint nCount);
uint8_t OLED_WR_Byte(uint8_t data, uint8_t command);
void    OLED_Display_on(void);
void    OLED_Display_off(void);

uint8_t SW_I2C_ReadVal_SDA();
void SW_I2C_Write_Data(uint8_t data);

void i2c_clk_data_out(void);
void scl_high(void);
void scl_low(void);
void sda_high(void);
void sda_low(void);
void sda_in_mode(void);
void sda_out_mode(void);
uint8_t i2c_check_ack(void);
void i2c_slave_address(uint8_t IICID, uint8_t readwrite);
void i2c_start_condition(void);
void i2c_stop_condition(void);

#endif /* I2C_H_ */
