/*********************************************************************************************************************
* @file            hf_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_uart.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口初始化(设置TX和RX引脚)
// @param        gpio_tx_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        tx_pin                    选择的引脚：GPIO_PIN_x(x=0..15)
// @param        gpio_rx_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        rx_pin                    选择的引脚：GPIO_PIN_x(x=0..15)
// @param        uart_periph               串口模块号：USARTx(x = 0,1)
// @param        baud                      波特率
// @return       void
// Sample usage:        uart_init(GPIOA, GPIO_PIN_9, GPIOA, GPIO_PIN_10, USART0, 115200U)
                        // 初始化串口USART0、Tx脚、Rx脚，波特率115200
//-------------------------------------------------------------------------------------------------------------------
void uart_init(uint32_t gpio_tx_periph, uint32_t tx_pin, uint32_t gpio_rx_periph, uint32_t rx_pin, uint32_t uart_periph, uint32_t baud)
{
    // Tx引脚初始化
    if(gpio_tx_periph == GPIOA)
    {
        rcu_periph_clock_enable(RCU_GPIOA);
    }
    else if(gpio_tx_periph == GPIOB)
    {
        rcu_periph_clock_enable(RCU_GPIOB);
    }
    else if(gpio_tx_periph == GPIOC)
    {
        rcu_periph_clock_enable(RCU_GPIOC);
    }
    else if(gpio_tx_periph == GPIOF)
    {
        rcu_periph_clock_enable(RCU_GPIOF);
    }
    if(gpio_tx_periph == GPIOB && tx_pin == GPIO_PIN_6)
    {
        gpio_af_set(gpio_tx_periph, GPIO_AF_0, tx_pin);
    }
    if(gpio_tx_periph == GPIOA && tx_pin == GPIO_PIN_9)
    {
        gpio_af_set(gpio_tx_periph, GPIO_AF_1, tx_pin);
    }
    gpio_mode_set(gpio_tx_periph, GPIO_MODE_AF, GPIO_PUPD_PULLUP, tx_pin);
    gpio_output_options_set(gpio_tx_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, tx_pin);

    // Rx引脚初始化
    if(gpio_rx_periph == GPIOA)
    {
        rcu_periph_clock_enable(RCU_GPIOA);
    }
    else if(gpio_rx_periph == GPIOB)
    {
        rcu_periph_clock_enable(RCU_GPIOB);
    }
    else if(gpio_rx_periph == GPIOC)
    {
        rcu_periph_clock_enable(RCU_GPIOC);
    }
    else if(gpio_rx_periph == GPIOF)
    {
        rcu_periph_clock_enable(RCU_GPIOF);
    }
    if(gpio_rx_periph == GPIOB && rx_pin == GPIO_PIN_7)
    {
        gpio_af_set(gpio_rx_periph, GPIO_AF_0, rx_pin);
    }
    if(gpio_rx_periph == GPIOA && rx_pin == GPIO_PIN_10)
    {
        gpio_af_set(gpio_rx_periph, GPIO_AF_1, rx_pin);
    }
    gpio_mode_set(gpio_rx_periph, GPIO_MODE_AF, GPIO_PUPD_PULLUP, rx_pin);
    gpio_output_options_set(gpio_rx_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, rx_pin);

    /*配置串口时钟*/
    if(uart_periph == USART0)
    {
        rcu_periph_clock_enable(RCU_USART0);
    }
    else if(uart_periph == USART1)
    {
        rcu_periph_clock_enable(RCU_USART1);
    }
    /*串口初始化*/
    usart_deinit(uart_periph);
    /*配置波特率*/
    usart_baudrate_set(uart_periph, baud);
    /*使能接收*/
    usart_receive_config(uart_periph, USART_RECEIVE_ENABLE);
     /*使能发送*/
    usart_transmit_config(uart_periph, USART_TRANSMIT_ENABLE);
     /*使能串口*/
    usart_enable(uart_periph);                 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口字节输出
// @param        uart_periph              串口模块号：USARTx(x = 0,1)
// @param        dat                      需要发送的字节
// @return       void        
// Sample usage:        uart_putchar(USART0,0xA5);								
//                        // 串口USART0发送0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_putchar(uint32_t uart_periph, uint8_t dat)
{
    /*写入数据*/
    usart_data_transmit(uart_periph, dat);
    /*等待发送完成*/    
    while(!(usart_flag_get(uart_periph,USART_FLAG_TBE)));
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口发送数组
// @param        uart_periph              串口模块号：USARTx(x = 0,1)
// @param        *buff                    要发送的数组地址
// @param        len                      发送长度
// @return       void
// Sample usage:        uart_putbuff(USART0,&a[0],5);
//-------------------------------------------------------------------------------------------------------------------
void uart_putbuff(uint32_t uart_periph, uint32_t *buff, uint32_t len)
{
    /*循环到发送完*/
    while(len)																			
    {
        /*写入数据*/
        usart_data_transmit(uart_periph, *buff++);    
        /*等待发送完成*/
        while(!(usart_flag_get(uart_periph,USART_FLAG_TBE)));								
        len--;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口发送字符串
// @param        uart_periph            串口模块号：USARTx(x = 0,1）
// @param        *str			        要发送的字符串地址
// @return       void
// Sample usage：        uart_putstr(USART0,"i lvoe you"); 
//-------------------------------------------------------------------------------------------------------------------
void uart_putstr(uint32_t uart_periph, uint8_t *str)
{
    /*一直循环到结尾*/
    while(*str)																			
    {
        /*发送数据*/
        usart_data_transmit(uart_periph, *str++);										
        while(RESET == usart_flag_get(uart_periph, USART_FLAG_TBE));
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        读取串口接收的字节（whlie等待）
// @param        uart_periph            串口模块号：USARTx(x = 0,1)
// @param        dat                    接收的字节
// @return       uint8_t
// Sample usage:         uint8_t dat; dat = uart_getchar(USART0);
//                       //串口USART0接收值并返回给dat
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_getchar(uint32_t uart_periph)
{
    uint8_t dat;
    /*等待读取到一个数据*/
    while(!(usart_flag_get(uart_periph,USART_FLAG_RBNE)));
    /* 清除标志位 */
    usart_flag_clear(uart_periph, USART_FLAG_RBNE);								
    dat = usart_data_receive(uart_periph);
    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        读取串口接收的数据（whlie等待）
// @param        uart_periph            串口模块号：USARTx(x = 0,1)
// @param        *dat                   接收数据的地址
// @return       void        
// Sample usage:         uint32_t dat; uart_getchar(USART0,&dat);
//                       //接收串口1数据，存放在dat变量里
//-------------------------------------------------------------------------------------------------------------------
void uart_getstr(uint32_t uart_periph, uint16_t *dat)
{
    /*等待读取到一个数据*/
    while(!(usart_flag_get(uart_periph,USART_FLAG_RBNE)));
    /* 清除标志位 */
    usart_flag_clear(uart_periph, USART_FLAG_RBNE);								
    *dat = usart_data_receive(uart_periph);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        读取串口接收的数据（查询接收）
// @param        uart_periph            串口模块号：USARTx(x = 0,1)
// @param        *dat                   接收数据的地址
// @return       uint8                  1：接收成功   0：未接收到数据
// Sample usage:        uint8_t dat; uart_query(USART0,&dat);					
//                      // 接收串口1数据  存在在dat变量里
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_query(uint32_t uart_periph, uint16_t *dat)
{
    /*读取到一个数据*/
    if(usart_flag_get(uart_periph,USART_FLAG_RBNE))											
	{
        /*存储一个数据*/
        *dat = usart_data_receive(uart_periph);										
		return 1;
	}
	return 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        串口中断设置
// @param        uart_periph            串口模块号：USARTx(x = 0,1)
// @param        int_flag               串口中断名称
//                                      只能选择以下参数：
// @arg          USART_INT_IDLE:        IDLE线检测中断
// @arg          USART_INT_RBNE:        读数据缓冲区非空中断
// @arg          USART_INT_TC:          发送完成中断
// @arg          USART_INT_TBE:         发送缓冲区空中断
// @arg          USART_INT_PERR:        校验错误中断
// @arg          USART_INT_AM:          ADDR匹配中断
// @arg          USART_INT_RT:          接收超时事件中断
// @arg          USART_INT_EB:          块结束事件中断
// @arg          USART_INT_LBD:         LIN断开信号检测中断
// @arg          USART_INT_ERR:         错误中断
// @arg          USART_INT_CTS:         CTS中断
// @arg          USART_INT_WU:          从深度睡眠模式唤醒中断
// @arg          USART_INT_RFF:         接收FIFO满中断
// @param        status                 1：打开中断   0：关闭中断
// @param        uart_irq               串口中断号：USARTx_IRQn(x = 0,1)
// @return       void
// Sample usage:        usat_interrupt_init(USART0, USART_INT_TC, 1, USART0_IRQn);	
                        // 打开串口1发送完成中断,默认设置为高优先级
//-------------------------------------------------------------------------------------------------------------------
void uart_interrupt_init(uint32_t uart_periph, usart_interrupt_enum int_flag, uint32_t status, uint32_t uart_irq)
{
    if(status)
        /*使能串口中断*/
        usart_interrupt_enable(uart_periph, int_flag);			                        
    else
        /*关闭串口中断*/
        usart_interrupt_disable(uart_periph, int_flag);							   		

    /*设置抢占优先级和响应优先级*/
    nvic_irq_enable(uart_irq, 0);													
}
