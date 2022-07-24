/*********************************************************************************************************************
* @file            hf_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_UART_H
#define _HF_UART_H

#include "headfile.h"
#include "gd32e23x_usart.h"

/* �������� */

/* ���ڳ�ʼ�� */
void uart_init(uint32_t gpio_tx_periph, uint32_t tx_pin, uint32_t gpio_rx_periph, uint32_t rx_pin, uint32_t uart_periph, uint32_t baud);
/* ���ڷ����ֽ� */
void uart_putchar(uint32_t uart_periph, uint8_t data);
/* ���ڷ������� */
void uart_putbuff(uint32_t uart_periph, uint32_t *buff, uint32_t len);
/* ���ڷ����ַ��� */
void uart_putstr(uint32_t uart_periph, uint8_t *str);
/* ��ȡ���ڽ��յ��ֽڣ�whlie�ȴ��� */
uint8_t uart_getchar(uint32_t uart_periph);
/* ��ȡ���ڽ��յ��ַ�����whlie�ȴ��� */
void uart_getstr(uint32_t uart_periph, uint16_t *dat);
/* ��ȡ���ڽ��յ����ݣ���ѯ���գ� */
uint8_t uart_query(uint32_t uart_periph, uint16_t *dat);
/* �����ж����� */
void uart_interrupt_init(uint32_t uart_periph, usart_interrupt_enum int_flag, uint32_t status, uint32_t uart_irq);

#endif