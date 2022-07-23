/*********************************************************************************************************************
* @file            car_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
*                  -2021.10.24, V1.1
* @modify          1. uart_send_char��������Ϊ���ڷ���һ���ֽ�
********************************************************************************************************************/

#include "car_uart.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����0��ʼ��   
// @return       void
// Sample usage:        uart0_init(UART0);//����0��ʼ��
//-------------------------------------------------------------------------------------------------------------------
void uart0_init(unsigned int uart_periph)
{
    uart_init(UART0_TXD_PORT, UART0_TXD_PIN, UART0_RXD_PORT, UART0_RXD_PIN, uart_periph, UART0_BAUDRATE); 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����1��ʼ��   
// @return       void
// Sample usage:        uart1_init(UART1);//����1��ʼ��
//-------------------------------------------------------------------------------------------------------------------
void uart1_init(unsigned int uart_periph)
{
    uart_init(UART1_TXD_PORT, UART1_TXD_PIN, UART1_RXD_PORT, UART1_RXD_PIN, uart_periph, UART1_BAUDRATE); 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ڽ�������
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1)
// @return       rec_dat
// Sample usage:        rx_char = uart_receive(UART0);//����0������
//-------------------------------------------------------------------------------------------------------------------
unsigned char uart_receive(unsigned int uart_periph)
{
    unsigned char rec_dat;

    rec_dat = uart_getchar(uart_periph);    

    return rec_dat;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ڷ���һ���ֽ�
// @param        uart_periph              ����ģ��ţ�USARTx(x = 0,1)
// @param        dat                      ��Ҫ���͵��ֽ�
// @return       void        
// Sample usage:        uart_send_char(USART0,0xA5);// ����USART0����0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_send_char(unsigned int uart_periph, unsigned char dat)
{
    uart_putchar(uart_periph, dat);  
}
