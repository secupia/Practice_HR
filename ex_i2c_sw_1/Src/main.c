/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "i2c.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    uint8_t OLED_buffer[1024];
    uint8_t i, j;

    memset(OLED_buffer, 0xF0, sizeof(OLED_buffer));
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
    HAL_Delay(200);

  /************** Initialize SH1106 *****************/
    OLED_WR_Byte(0xAE,OLED_CMD);    /* display off */
    OLED_WR_Byte(0x02,OLED_CMD);    /*set lower column address*/
    OLED_WR_Byte(0x10,OLED_CMD);    /*set higher column address*/
    OLED_WR_Byte(0x40,OLED_CMD);    /*set display start line*/
    OLED_WR_Byte(0xB0,OLED_CMD);    /*set page address*/
    OLED_WR_Byte(0x81,OLED_CMD);    /*contract control*/
    OLED_WR_Byte(0xFF,OLED_CMD);    /*128*/
    OLED_WR_Byte(0xA1,OLED_CMD);    /*set segment remap*/
    OLED_WR_Byte(0xA6,OLED_CMD);    /*normal / reverse*/
    OLED_WR_Byte(0xA8,OLED_CMD);    /*multiplex ratio*/
    OLED_WR_Byte(0x3F,OLED_CMD);    /*duty = 1/64*/
    OLED_WR_Byte(0xAD,OLED_CMD);    /*set charge pump enable*/
    OLED_WR_Byte(0x8B,OLED_CMD);    /*    0x8B    ÄÚ¹©VCC   */
    OLED_WR_Byte(0x32,OLED_CMD);    /*0X30---0X33  set VPP   8V */
    OLED_WR_Byte(0xC8,OLED_CMD);    /*Com scan direction*/
    OLED_WR_Byte(0xD3,OLED_CMD);    /*set display offset*/
    OLED_WR_Byte(0x00,OLED_CMD);    /*   0x20  */
    OLED_WR_Byte(0xD5,OLED_CMD);    /*set osc division*/
    OLED_WR_Byte(0x80,OLED_CMD);
    OLED_WR_Byte(0xD9,OLED_CMD);    /*set pre-charge period*/
    OLED_WR_Byte(0x1F,OLED_CMD);    /*0x22*/
    OLED_WR_Byte(0xDA,OLED_CMD);    /*set COM pins*/
    OLED_WR_Byte(0x12,OLED_CMD);
    OLED_WR_Byte(0xDB,OLED_CMD);    /*set vcomh*/
    OLED_WR_Byte(0x40,OLED_CMD);
    OLED_WR_Byte(0xAF,OLED_CMD);    /*display ON*/

    for(i = 0; i < 8; i++)
    {
        OLED_WR_Byte(0xB0+i, OLED_CMD);
        OLED_WR_Byte(0x02, OLED_CMD);
        OLED_WR_Byte(0x10, OLED_CMD);
        for(j=0; j<128; j++)
        {
             OLED_WR_Byte(OLED_buffer[i*128+j], OLED_DATA);
        }
    }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);    // check for run
      OLED_Display_off();
      HAL_Delay(1000);
      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
      OLED_Display_on();
      HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
