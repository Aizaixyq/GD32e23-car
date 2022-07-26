/*********************************************************************************************************************
* @file            car_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
*                  -2021.10.24, V1.1
* @modify          1. uart_send_char函数名改为串口发送一个字节
********************************************************************************************************************/

#include "car_uart.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口0初始化   
// @return       void
// Sample usage:        uart0_init(UART0);//串口0初始化
//-------------------------------------------------------------------------------------------------------------------
void uart0_init(unsigned int uart_periph)
{
    uart_init(UART0_TXD_PORT, UART0_TXD_PIN, UART0_RXD_PORT, UART0_RXD_PIN, uart_periph, UART0_BAUDRATE); 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口1初始化   
// @return       void
// Sample usage:        uart1_init(UART1);//串口1初始化
//-------------------------------------------------------------------------------------------------------------------
void uart1_init(unsigned int uart_periph)
{
    uart_init(UART1_TXD_PORT, UART1_TXD_PIN, UART1_RXD_PORT, UART1_RXD_PIN, uart_periph, UART1_BAUDRATE); 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口接收数据
// @param        uart_periph            串口模块号：USARTx(x = 0,1)
// @return       rec_dat
// Sample usage:        rx_char = uart_receive(UART0);//串口0接收数
//-------------------------------------------------------------------------------------------------------------------
unsigned char uart_receive(unsigned int uart_periph)
{
    unsigned char rec_dat;

    rec_dat = uart_getchar(uart_periph);    

    return rec_dat;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口发送一个字节
// @param        uart_periph              串口模块号：USARTx(x = 0,1)
// @param        dat                      需要发送的字节
// @return       void        
// Sample usage:        uart_send_char(USART0,0xA5);// 串口USART0发送0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_send_char(unsigned int uart_periph, unsigned char dat)
{
    uart_putchar(uart_periph, dat);  
}
