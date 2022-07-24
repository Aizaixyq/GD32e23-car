/*********************************************************************************************************************
* @file            hf_i2c_hardware.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_i2c_hardware.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ʼ��
// @param        I2Cx(x=0,1)            ѡ��I2Cͨ��
// @param        bound                  ͨ��ʱ��Ƶ�ʣ�������400KHz
// @param        address                I2C�豸�����ַ
// @return       void
// Sample usage:        i2c_init(I2C1, 0x00);
                        //����I2C1,��ַΪ0x00
//-------------------------------------------------------------------------------------------------------------------
void i2c_init(uint32_t i2c_periph, uint16_t i2c_address)
{
    if (i2c_periph == I2C0)
    {
        /* ʹ��I2Cʱ�� */
        rcu_periph_clock_enable(RCU_I2C0);

        /* GPIO ��ʼ�� */
        gpio_init(GPIOB, OUT_AF_1_OD, GPIO_PIN_6 | GPIO_PIN_7);
    }

    else if (i2c_periph == I2C1)
    {
        /* ʹ��I2Cʱ�� */
        rcu_periph_clock_enable(RCU_I2C1);
        /* GPIO ��ʼ�� */
        gpio_init(GPIOA, OUT_AF_0_OD, GPIO_PIN_11 | GPIO_PIN_12);
    }

    /* ����I2Cʱ�����ʺ�ռ�ձ� */
    i2c_clock_config(i2c_periph, I2C_SPEED, I2C_DTCY_2);
    /* ����I2C��ַ */
    i2c_mode_addr_config(i2c_periph, I2C_I2CMODE_ENABLE, I2C_ADDFORMAT_7BITS, i2c_address);
    /* ʹ��I2C */
    i2c_enable(i2c_periph);
    /* I2C����Ӧ�� */
    i2c_ack_config(i2c_periph, I2C_ACK_ENABLE);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2Cд��һ���ֽ�
// @param        i2c_periph            I2Cx(x=0,1)
// @param        slave_address         �ӻ���ַ
// @param        data                  ���͵��ֽ�
// @return        void
// Sample usage:        i2c_send_byte(I2C1, 0xD0, 0x21);
                        //I2C1��ʼͨ��,���ַΪ0xD0�Ĵӻ���������0x21
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_byte(uint32_t i2c_periph, uint8_t slave_address, uint8_t data)
{
    /* �ȴ�I2C���߿��� */
    while (i2c_flag_get(i2c_periph, I2C_FLAG_I2CBSY)){;}

    /* ������ʼ�ź� */
    i2c_start_on_bus(i2c_periph);

    /* �ȴ���ʼ�źŷ������ */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_SBSEND)){;}
    /* ���ʹӻ���ַ */
    i2c_master_addressing(i2c_periph, slave_address, I2C_TRANSMITTER);

    /* �ȴ���ַ������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_ADDSEND)){;}

    /* ��ַ���ͱ�־λ��� */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    /* �ȴ��ӻ�Ӧ�� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_TBE)){;}

    /* �����ֽ� */
    i2c_data_transmit(i2c_periph, data);
    /* �ȴ�������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

    /* I2C�ſ����� */
    i2c_stop_on_bus(i2c_periph);
    /* �ȴ������ͷ� */
    while (I2C_CTL0(i2c_periph) & 0x0200){;}
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2Cд�����ֽ�
// @param        i2c_periph            I2Cx(x=0,1)
// @param        slave_address         �ӻ���ַ
// @param        reg_address           �Ĵ�����ַ
// @param        *p_buffer             д����ֽڴ�ŵ������ַ
// @param        number_of_byte        д����ֽ�����
// @return       void
// Sample usage:        i2c_send_bytes(I2C1, 0x65, 0x70, 0x12, 2);
//                      //I2C1��ʼͨ��,��ӻ���ַΪ0x65�������ڲ���ַΪ0x70�ļĴ���д��2���ֽ����ݣ����ݴ���׵�ַΪ0x12
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_bytes(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t *p_buffer, uint8_t number_of_byte)
{
    /* �ȴ�I2C���߿��� */
    while (i2c_flag_get(i2c_periph, I2C_FLAG_I2CBSY)){;}

    /* ������ʼ�ź� */
    i2c_start_on_bus(i2c_periph);

    /* �ȴ���ʼ�źŷ������ */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_SBSEND)){;}

    /* ���ʹӻ���ַ */
    i2c_master_addressing(i2c_periph, slave_address, I2C_TRANSMITTER);

    /* �ȴ���ַ������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_ADDSEND)){;}

    /* ��ַ���ͱ�־λ��� */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    /* �ȴ��ӻ�Ӧ�� */
    while (SET != i2c_flag_get(i2c_periph, I2C_FLAG_TBE)){;}

    /* �����ֽ� */
    i2c_data_transmit(i2c_periph, reg_address);

    /* �ȴ�������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

    /* �����ֽ� */
    while (number_of_byte--)
    {
        i2c_data_transmit(i2c_periph, *p_buffer);
        /* ָ����һ��Ҫд���ֽ� */
        p_buffer++;
        /* �ȴ�������� */
        while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}
    }

    /* I2C�ſ����� */
    i2c_stop_on_bus(i2c_periph);

    /* �ȴ������ͷ� */
    while (I2C_CTL0(i2c_periph) & 0x0200){;}
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ָ���Ĵ���д��һ���ֽ�
// @param        i2c_periph            I2Cx(x=0,1)
// @param        slave_address         �ӻ���ַ
// @param        reg_address           �Ĵ�����ַ
// @param        data                  ���͵��ֽ�
// @return       void
// Sample usage:        i2c_send_reg_byte(I2C1, 0xA0, 0x34, 0x21);
//                      //I2C1��ʼͨ��,��0xA0��ַ���������ͼĴ�����ַ0x34,��������0x21
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_reg_byte(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t data)
{
    /* �ȴ�I2C���߿��� */
    while (i2c_flag_get(i2c_periph, I2C_FLAG_I2CBSY)){;}

    /* ������ʼ�ź� */
    i2c_start_on_bus(i2c_periph);

    /* �ȴ���ʼ�źŷ������ */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_SBSEND)){;}

    /* ���ʹӻ���ַ */
    i2c_master_addressing(i2c_periph, slave_address, I2C_TRANSMITTER);

    /* �ȴ���ַ������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_ADDSEND)){;}

    /* ��ַ���ͱ�־λ��� */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    /* �ȴ��ӻ�Ӧ�� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_TBE)){;}

    /* ���ͼĴ�����ַ */
    i2c_data_transmit(i2c_periph, reg_address);

    /* �ȴ�������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

    /* �����ֽ� */
    i2c_data_transmit(i2c_periph, data);

    /* �ȴ�������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

    /* I2C�ſ����� */
    i2c_stop_on_bus(i2c_periph);

    /* �ȴ������ͷ� */
    while (I2C_CTL0(i2c_periph) & 0x0200){;}
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ָ���Ĵ���д������
// @param        i2c_periph            I2Cx(x=0,1)
// @param        slave_address         �ӻ���ַ
// @param        write_address         �ֽ�д���豸�ĵ�ַ
// @param        p_buffer              д����ֽڴ�ŵ������ַ
// @param        number_of_byte        д����ֽ�����
// @return       void
// Sample usage:        i2c_send_reg_buffer(I2C1, 0xA0, 0x34, data, 3);
//                      //I2C1��ʼͨ��,��0xA0��ַ���������ͼĴ�����ַ0x34,�����׵�ַΪdata��3λ����
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_reg_buffer(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t number_of_byte)
{
    uint8_t number_of_page, number_of_single, address, count;
    number_of_page = 0;
    number_of_single = 0;
    address = 0;
    count = 0;

    address = reg_address % I2C_PAGE_SIZE;
    count = I2C_PAGE_SIZE - address;
    number_of_page = number_of_byte / I2C_PAGE_SIZE;
    number_of_single = number_of_byte % I2C_PAGE_SIZE;

    /* ���д���ַ��ҳ��С����  */
    if (0 == address)
    {
        while (number_of_page--)
        {
            i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, I2C_PAGE_SIZE);
            slave_address += I2C_PAGE_SIZE;
            p_buffer += I2C_PAGE_SIZE;
        }
        if (0 != number_of_single)
        {
            i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, I2C_PAGE_SIZE);
        }
    }

    else
    {
        /* ���д���ַ��ҳ��С������ */
        if (number_of_byte < count)
        {
            i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, count);
        }

        else
        {
            number_of_byte -= count;
            number_of_page = number_of_byte / I2C_PAGE_SIZE;
            number_of_single = number_of_byte % I2C_PAGE_SIZE;

            if (0 != count)
            {
                i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, count);
                slave_address += count;
                p_buffer += count;
            }

            /* дҳ�� */
            while (number_of_page--)
            {
                i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, count);
                slave_address += I2C_PAGE_SIZE;
                p_buffer += I2C_PAGE_SIZE;
            }

            /* д�����ֽ� */
            if (0 != number_of_single)
            {
                i2c_send_bytes(i2c_periph, slave_address, reg_address, p_buffer, count);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ָ���Ĵ�����ȡ����
// @param        i2c_periph            I2Cx(x=0,1)
// @param        slave_address         �ӻ���ַ
// @param        reg_address         ��ȡ�ļĴ����ĵ�ַ
// @param        p_buffer            ��ȡ���ֽڴ�ŵ������ַ
// @param        number_of_byte      ��ȡ���ֽ�����
// @return       void
// Sample usage:        uint8_t data[3]; i2c_read_reg_buffer(I2C1, 0x68, 0x75, data, 3);
//                      //I2C1��ȡ�ӻ���ַΪ0x68�������ڲ���ַΪ0x75�ļĴ�������3λ���ݴ����dataָ��ĵ�ַ��
//-------------------------------------------------------------------------------------------------------------------
void i2c_read_reg_buffer(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t number_of_byte)
{
    /* �ȴ�I2C���߿��� */
    while (i2c_flag_get(i2c_periph, I2C_FLAG_I2CBSY)){;}

    if (2 == number_of_byte)
    {
        i2c_ackpos_config(i2c_periph, I2C_ACKPOS_NEXT);
    }

    /* ������ʼ�ź� */
    i2c_start_on_bus(i2c_periph);

    /* �ȴ���ʼ�źŷ������ */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_SBSEND)){;}

    /* ���ʹӻ���ַ */
    i2c_master_addressing(i2c_periph, slave_address, I2C_TRANSMITTER);

    /* �ȴ���ַ������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_ADDSEND)){;}

    /* ��ַ���ͱ�־λ��� */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    /* �ȴ��ӻ�Ӧ�� */
    while (SET != i2c_flag_get(i2c_periph, I2C_FLAG_TBE)){;}

    /* ʹ��I2C */
    i2c_enable(i2c_periph);

    /* ���ͼĴ�����ַ */
    i2c_data_transmit(i2c_periph, reg_address);

    /* �ȴ�������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

    /* ������ʼ�ź� */
    i2c_start_on_bus(i2c_periph);

    /* �ȴ����ݷ������ */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_SBSEND)){;}

    /* ���ʹӻ���ַ */
    i2c_master_addressing(i2c_periph, slave_address, I2C_RECEIVER);

    if (number_of_byte < 3)
    {
        /* ʧ��Ӧ���ź� */
        i2c_ack_config(i2c_periph, I2C_ACK_DISABLE);
    }

    /* �ȴ���ַ������� */
    while (!i2c_flag_get(i2c_periph, I2C_FLAG_ADDSEND)){;}

    /* ��ַ���ͱ�־λ��� */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    if (1 == number_of_byte)
    {
        /* ����ֹͣ�ź� */
        i2c_stop_on_bus(i2c_periph);
    }

    /* ��������Ҫ��ȡʱ */
    while (number_of_byte)
    {
        if (3 == number_of_byte)
        {
            /* �ȴ�������� */
            while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

            /* ʧ��Ӧ���ź� */
            i2c_ack_config(i2c_periph, I2C_ACK_DISABLE);
        }
        if (2 == number_of_byte)
        {
            /* �ȴ�������� */
            while (!i2c_flag_get(i2c_periph, I2C_FLAG_BTC)){;}

            /* ����ֹͣ�ź� */
            i2c_stop_on_bus(i2c_periph);
        }

        /* �ȴ���ȡ��ϲ������־λ */
        if (i2c_flag_get(i2c_periph, I2C_FLAG_RBNE))
        {
            /* ��ȡһ���ֽ� */
            *p_buffer = i2c_data_receive(i2c_periph);

            /* ָ�򽫱����ȡ���ֽڵ���һ��λ�� */
            p_buffer++;

            /* ���ٶ�ȡ�ֽڼ����� */
            number_of_byte--;
        }
    }

    /* �ȴ�ֹͣ������� */
    while (I2C_CTL0(i2c_periph) & 0x0200){;}

    /* ʹ��Ӧ���ź� */
    i2c_ack_config(i2c_periph, I2C_ACK_ENABLE);

    i2c_ackpos_config(i2c_periph, I2C_ACKPOS_CURRENT);
}
