/*********************************************************************************************************************
* @file            hf_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_uart.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ڳ�ʼ��(����TX��RX����)
// @param        gpio_tx_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        tx_pin                    ѡ������ţ�GPIO_PIN_x(x=0..15)
// @param        gpio_rx_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        rx_pin                    ѡ������ţ�GPIO_PIN_x(x=0..15)
// @param        uart_periph               ����ģ��ţ�USARTx(x = 0,1)
// @param        baud                      ������
// @return       void
// Sample usage:        uart_init(GPIOA, GPIO_PIN_9, GPIOA, GPIO_PIN_10, USART0, 115200U)
                        // ��ʼ������USART0��Tx�š�Rx�ţ�������115200
//-------------------------------------------------------------------------------------------------------------------
void uart_init(uint32_t gpio_tx_periph, uint32_t tx_pin, uint32_t gpio_rx_periph, uint32_t rx_pin, uint32_t uart_periph, uint32_t baud)
{
    // Tx���ų�ʼ��
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

    // Rx���ų�ʼ��
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

    /*���ô���ʱ��*/
    if(uart_periph == USART0)
    {
        rcu_periph_clock_enable(RCU_USART0);
    }
    else if(uart_periph == USART1)
    {
        rcu_periph_clock_enable(RCU_USART1);
    }
    /*���ڳ�ʼ��*/
    usart_deinit(uart_periph);
    /*���ò�����*/
    usart_baudrate_set(uart_periph, baud);
    /*ʹ�ܽ���*/
    usart_receive_config(uart_periph, USART_RECEIVE_ENABLE);
     /*ʹ�ܷ���*/
    usart_transmit_config(uart_periph, USART_TRANSMIT_ENABLE);
     /*ʹ�ܴ���*/
    usart_enable(uart_periph);                 
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        �����ֽ����
// @param        uart_periph              ����ģ��ţ�USARTx(x = 0,1)
// @param        dat                      ��Ҫ���͵��ֽ�
// @return       void        
// Sample usage:        uart_putchar(USART0,0xA5);								
//                        // ����USART0����0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_putchar(uint32_t uart_periph, uint8_t dat)
{
    /*д������*/
    usart_data_transmit(uart_periph, dat);
    /*�ȴ��������*/    
    while(!(usart_flag_get(uart_periph,USART_FLAG_TBE)));
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ڷ�������
// @param        uart_periph              ����ģ��ţ�USARTx(x = 0,1)
// @param        *buff                    Ҫ���͵������ַ
// @param        len                      ���ͳ���
// @return       void
// Sample usage:        uart_putbuff(USART0,&a[0],5);
//-------------------------------------------------------------------------------------------------------------------
void uart_putbuff(uint32_t uart_periph, uint32_t *buff, uint32_t len)
{
    /*ѭ����������*/
    while(len)																			
    {
        /*д������*/
        usart_data_transmit(uart_periph, *buff++);    
        /*�ȴ��������*/
        while(!(usart_flag_get(uart_periph,USART_FLAG_TBE)));								
        len--;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ڷ����ַ���
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1��
// @param        *str			        Ҫ���͵��ַ�����ַ
// @return       void
// Sample usage��        uart_putstr(USART0,"i lvoe you"); 
//-------------------------------------------------------------------------------------------------------------------
void uart_putstr(uint32_t uart_periph, uint8_t *str)
{
    /*һֱѭ������β*/
    while(*str)																			
    {
        /*��������*/
        usart_data_transmit(uart_periph, *str++);										
        while(RESET == usart_flag_get(uart_periph, USART_FLAG_TBE));
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ȡ���ڽ��յ��ֽڣ�whlie�ȴ���
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1)
// @param        dat                    ���յ��ֽ�
// @return       uint8_t
// Sample usage:         uint8_t dat; dat = uart_getchar(USART0);
//                       //����USART0����ֵ�����ظ�dat
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_getchar(uint32_t uart_periph)
{
    uint8_t dat;
    /*�ȴ���ȡ��һ������*/
    while(!(usart_flag_get(uart_periph,USART_FLAG_RBNE)));
    /* �����־λ */
    usart_flag_clear(uart_periph, USART_FLAG_RBNE);								
    dat = usart_data_receive(uart_periph);
    return dat;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ȡ���ڽ��յ����ݣ�whlie�ȴ���
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1)
// @param        *dat                   �������ݵĵ�ַ
// @return       void        
// Sample usage:         uint32_t dat; uart_getchar(USART0,&dat);
//                       //���մ���1���ݣ������dat������
//-------------------------------------------------------------------------------------------------------------------
void uart_getstr(uint32_t uart_periph, uint16_t *dat)
{
    /*�ȴ���ȡ��һ������*/
    while(!(usart_flag_get(uart_periph,USART_FLAG_RBNE)));
    /* �����־λ */
    usart_flag_clear(uart_periph, USART_FLAG_RBNE);								
    *dat = usart_data_receive(uart_periph);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ȡ���ڽ��յ����ݣ���ѯ���գ�
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1)
// @param        *dat                   �������ݵĵ�ַ
// @return       uint8                  1�����ճɹ�   0��δ���յ�����
// Sample usage:        uint8_t dat; uart_query(USART0,&dat);					
//                      // ���մ���1����  ������dat������
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_query(uint32_t uart_periph, uint16_t *dat)
{
    /*��ȡ��һ������*/
    if(usart_flag_get(uart_periph,USART_FLAG_RBNE))											
	{
        /*�洢һ������*/
        *dat = usart_data_receive(uart_periph);										
		return 1;
	}
	return 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        �����ж�����
// @param        uart_periph            ����ģ��ţ�USARTx(x = 0,1)
// @param        int_flag               �����ж�����
//                                      ֻ��ѡ�����²�����
// @arg          USART_INT_IDLE:        IDLE�߼���ж�
// @arg          USART_INT_RBNE:        �����ݻ������ǿ��ж�
// @arg          USART_INT_TC:          ��������ж�
// @arg          USART_INT_TBE:         ���ͻ��������ж�
// @arg          USART_INT_PERR:        У������ж�
// @arg          USART_INT_AM:          ADDRƥ���ж�
// @arg          USART_INT_RT:          ���ճ�ʱ�¼��ж�
// @arg          USART_INT_EB:          ������¼��ж�
// @arg          USART_INT_LBD:         LIN�Ͽ��źż���ж�
// @arg          USART_INT_ERR:         �����ж�
// @arg          USART_INT_CTS:         CTS�ж�
// @arg          USART_INT_WU:          �����˯��ģʽ�����ж�
// @arg          USART_INT_RFF:         ����FIFO���ж�
// @param        status                 1�����ж�   0���ر��ж�
// @param        uart_irq               �����жϺţ�USARTx_IRQn(x = 0,1)
// @return       void
// Sample usage:        usat_interrupt_init(USART0, USART_INT_TC, 1, USART0_IRQn);	
                        // �򿪴���1��������ж�,Ĭ������Ϊ�����ȼ�
//-------------------------------------------------------------------------------------------------------------------
void uart_interrupt_init(uint32_t uart_periph, usart_interrupt_enum int_flag, uint32_t status, uint32_t uart_irq)
{
    if(status)
        /*ʹ�ܴ����ж�*/
        usart_interrupt_enable(uart_periph, int_flag);			                        
    else
        /*�رմ����ж�*/
        usart_interrupt_disable(uart_periph, int_flag);							   		

    /*������ռ���ȼ�����Ӧ���ȼ�*/
    nvic_irq_enable(uart_irq, 0);													
}
