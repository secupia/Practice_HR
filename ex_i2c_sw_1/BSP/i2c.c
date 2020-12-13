/*
 * i2c.c
 *
 *  Created on: 2020. 12. 7.
 *      Author: Marshall
 */

#include "i2c.h"

void TIMER__Wait_us(uint nCount)
{
    for (; nCount != 0;nCount--);
}


uint8_t OLED_WR_Byte(uint8_t data, uint8_t command)
{
    uint8_t returnack = TRUE;

    i2c_start_condition();

    i2c_slave_address(I2C_SLAVE_ADDR, WRITE_CMD);
    if (!i2c_check_ack())
    {
        returnack = FALSE;
    }

    TIMER__Wait_us(SW_I2C_WAIT_TIME);

    SW_I2C_Write_Data(command);
    if (!i2c_check_ack())
    {
        returnack = FALSE;
    }

    TIMER__Wait_us(SW_I2C_WAIT_TIME);

    SW_I2C_Write_Data(data);
    if (!i2c_check_ack())
    {
        returnack = FALSE;
    }

    TIMER__Wait_us(SW_I2C_WAIT_TIME);

    i2c_stop_condition();

    return returnack;
}

void    OLED_Display_on(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC√¸¡Ó
    OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
    OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}

void    OLED_Display_off(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC√¸¡Ó
    OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
    OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}

void i2c_start_condition(void)
{

    sda_high();
    scl_high();

    TIMER__Wait_us(SW_I2C_WAIT_TIME);
    sda_low();
    TIMER__Wait_us(SW_I2C_WAIT_TIME);
    scl_low();

    TIMER__Wait_us(SW_I2C_WAIT_TIME << 1);

}

void sda_high(void)
{

    HAL_GPIO_WritePin(I2C1_SW_SDA_GPIO_Port, I2C1_SW_SDA_Pin, GPIO_PIN_SET);

}

void sda_low(void)
{

    HAL_GPIO_WritePin(I2C1_SW_SDA_GPIO_Port, I2C1_SW_SDA_Pin, GPIO_PIN_RESET);

}

void sda_out(uint8_t out)
{
    if (out)
    {
        sda_high();
    }
    else
    {
        sda_low();
    }
}

void scl_high(void)
{
    HAL_GPIO_WritePin(I2C1_SW_SCL_GPIO_Port, I2C1_SW_SCL_Pin, GPIO_PIN_SET);
}

void scl_low(void)
{
    HAL_GPIO_WritePin(I2C1_SW_SCL_GPIO_Port, I2C1_SW_SCL_Pin, GPIO_PIN_RESET);
}

void i2c_slave_address(uint8_t IICID, uint8_t readwrite)
{
    int x;

    if (readwrite)
    {
        IICID |= I2C_READ;
    }
    else
    {
        IICID &= ~I2C_READ;
    }

    scl_low();

    for (x = 7; x >= 0; x--)
    {
        sda_out(IICID & (1 << x));
        TIMER__Wait_us(SW_I2C_WAIT_TIME);
        i2c_clk_data_out();
        // TIMER__Wait_us(SW_I2C_WAIT_TIME);
    }
}

void i2c_clk_data_out(void)
{
    scl_high();
    TIMER__Wait_us(SW_I2C_WAIT_TIME);
    scl_low();
    // TIMER__Wait_us(SW_I2C_WAIT_TIME>>2);
}

uint8_t i2c_check_ack(void)
{
    uint8_t ack;
    int i;
    unsigned int temp;

    sda_in_mode();

    scl_high();

    ack = FALSE;
    TIMER__Wait_us(SW_I2C_WAIT_TIME);

    for (i = 10; i > 0; i--)
    {
        temp = !(SW_I2C_ReadVal_SDA()); //0=ack , 1=nack
        if (temp) // if ack, enter
        {
            ack = TRUE;
            break;
        }
    }
    scl_low();
    sda_out_mode(); //during setting, sda signal high

    TIMER__Wait_us(SW_I2C_WAIT_TIME);
    return ack;
}

void sda_in_mode(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT; //IPD->IPU
    GPIO_InitStructure.Pin = I2C1_SW_SDA_Pin;
    //GPIO_Init(I2C1_SW_SDA_GPIO_Port, &GPIO_InitStructure);
    HAL_GPIO_Init(I2C1_SW_SDA_GPIO_Port, &GPIO_InitStructure);
}

void sda_out_mode(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD; // error point GPIO_Mode_Out_PP
    GPIO_InitStructure.Pin = I2C1_SW_SDA_Pin;
    //GPIO_Init(I2C1_SW_SDA_GPIO_Port, &GPIO_InitStructure);
    HAL_GPIO_Init(I2C1_SW_SDA_GPIO_Port, &GPIO_InitStructure);
}

uint8_t SW_I2C_ReadVal_SDA()
{

    return HAL_GPIO_ReadPin(I2C1_SW_SDA_GPIO_Port, I2C1_SW_SDA_Pin);

}

void SW_I2C_Write_Data(uint8_t data)
{

    int x;

    scl_low();

    for (x = 7; x >= 0; x--)
    {
        sda_out(data & (1 << x));
        TIMER__Wait_us(SW_I2C_WAIT_TIME);
        i2c_clk_data_out();
        // TIMER__Wait_us(SW_I2C_WAIT_TIME);
    }

}

void i2c_stop_condition(void)
{
    sda_low();
    scl_high();

    TIMER__Wait_us(SW_I2C_WAIT_TIME);
    sda_high();
    TIMER__Wait_us(SW_I2C_WAIT_TIME);
}
