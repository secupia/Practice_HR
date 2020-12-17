//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STM32F103RCT6,����ԭ��MiniSTM32������,��Ƶ72MHZ������12MHZ
//QDtech-OLEDҺ������ for STM32
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtft.com
//�Ա���վ��http://qdtech.taobao.com
//wiki������վ��http://www.lcdwiki.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//����֧��QQ:3002773612  3002778157
//��������QQȺ:324828016
//��������:2018/9/13
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================��Դ����================================================//
// OLEDģ��               STM32��Ƭ��
//   VCC         ��       DC 5V/3.3V      //OLED����Դ��
//   GND         ��          GND          //OLED����Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������ΪIIC
// OLEDģ��               STM32��Ƭ��
//   SDA         ��          PB15         //OLED��IIC�����ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��               STM32��Ƭ��
//   SCL         ��          PB13         //OLED��IICʱ���ź�
//=========================================����������=========================================//
//��ģ�鲻���������ܣ����Բ���Ҫ����������
****************************************************************************************************/	
/***************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
****************************************************************************************************/	

/**
  * Original Source Link : http://www.lcdwiki.com/1.3inch_IIC_OLED_Module_SKU:MC130VX, 
  *                        1.3inch IIC_OLED Module Package
	*                        \1-Demo\Demo_STM32\Demo_OLED_STM32F103RCT6_Software_IIC
  *
  * Target board : STM32-BSKO Board
  * I2C SDA PB15 --> PB11
	* I2C SCL PB13 --> PB10
	*
  */

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"
int main(void)
{	
	delay_init();	    	       //��ʱ������ʼ��	  
	NVIC_Configuration(); 	   //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	
	OLED_Init();			         //��ʼ��OLED  
	OLED_Clear(0);             //������ȫ�ڣ�
	while(1) 
	{	
		TEST_MainPage();         //Display main interface
		OLED_Clear(0); 
		Test_Color();            //Update display
		OLED_Clear(0); 
		Test_Rectangular();      //Draw rectangle
		OLED_Clear(0); 
		Test_Circle();           //Draw circle
		OLED_Clear(0); 
		Test_Triangle();         //Draw triangle
		OLED_Clear(0);  
		TEST_English();          //Display english
		OLED_Clear(0); 
		TEST_Number_Character(); //Display number and special characters
		OLED_Clear(0); 
		TEST_Chinese();          //Display chinese
		OLED_Clear(0); 
		TEST_BMP();              //Display BMP monochrome picture
		OLED_Clear(0); 
		TEST_Menu1();            //Display menu1
		OLED_Clear(0); 
		TEST_Menu2();            //Display menu1
		OLED_Clear(0); 
	}
}
