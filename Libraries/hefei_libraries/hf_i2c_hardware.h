/*********************************************************************************************************************
* @file            hf_i2c_hardware.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_I2C_HARDWARE_H_
#define _HF_I2C_HARDWARE_H_

#include "headfile.h"

/* �궨������ */

#define I2C_SPEED            400000
#define I2C_PAGE_SIZE        8


/* �������� */

/* I2C���� */
void i2c_init(uint32_t i2c_periph, uint16_t i2c_address);
/* I2Cд��һ���ֽ� */
void i2c_send_byte(uint32_t i2c_periph, uint8_t slave_address, uint8_t data);
/* I2Cд�����ֽ� */
void i2c_send_bytes(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t* p_buffer, uint8_t number_of_byte);
/* I2C��ָ���Ĵ���д��һ���ֽ� */
void i2c_send_reg_byte(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t data);
/* I2C��ָ���Ĵ���д������ */
void i2c_send_reg_buffer(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t* p_buffer, uint16_t number_of_byte);
/* I2C��ָ���Ĵ�����ȡ���� */
void i2c_read_reg_buffer(uint32_t i2c_periph, uint8_t slave_address, uint8_t reg_address, uint8_t* p_buffer, uint16_t number_of_byte);

#endif
