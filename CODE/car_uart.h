/*********************************************************************************************************************
* @file            car_uart.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
*                  -2021.10.24, V1.1
* @modify          1. ע�������ߴ��ں����ߴ��ڶ�Ӧ�ĺ궨������
********************************************************************************************************************/

#ifndef __CAR_UART_H
#define __CAR_UART_H

#include "headfile.h"

//�궨��
//UART0Ϊ���ߴ���
#define UART0            USART0
#define UART0_TXD_PORT   GPIOA
#define UART0_TXD_PIN    GPIO_PIN_9
#define UART0_RXD_PORT   GPIOA
#define UART0_RXD_PIN    GPIO_PIN_10
#define UART0_BAUDRATE   115200

//UART1Ϊ���ߴ���
#define UART1            USART1
#define UART1_TXD_PORT   GPIOA
#define UART1_TXD_PIN    GPIO_PIN_2
#define UART1_RXD_PORT   GPIOA
#define UART1_RXD_PIN    GPIO_PIN_3
#define UART1_BAUDRATE   115200


//��������
/* ����0��ʼ�� */
void uart0_init(unsigned int uart_periph);
/* ����0��ʼ�� */
void uart1_init(unsigned int uart_periph);
/* ���ڷ���һ���ֽ� */
void uart_send_char(unsigned int uart_periph, unsigned char dat);
/* ���ڽ������� */
unsigned char uart_receive(unsigned int uart_periph);


//ȫ�ֱ�������

#endif
