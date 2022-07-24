/*********************************************************************************************************************
* @file            hf_i2c_software.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_I2C_SOFTWARE_H
#define _HF_I2C_SOFTWARE_H

#include "headfile.h"

/* �궨������ */
#define I2C_PORT    GPIOA

#define SCL_PIN     GPIO_PIN_11
#define SDA_PIN     GPIO_PIN_12

#define SCL_Get()   gpio_get_output(I2C_PORT, SCL_PIN)
#define SCL_Clr()   gpio_bit_output(I2C_PORT, SCL_PIN, 0)//OLED_SCL
#define SCL_Set()   gpio_bit_output(I2C_PORT, SCL_PIN, 1)

#define SDA_Get()   gpio_get_output(I2C_PORT, SDA_PIN)
#define SDA_Clr()   gpio_bit_output(I2C_PORT, SDA_PIN, 0)//OLED_SDA
#define SDA_Set()   gpio_bit_output(I2C_PORT, SDA_PIN, 1)

#define CMD         0x40
#define DAT         0x00


/* �������� */

/* ģ��I2C���͵��ֽ� */
void i2c_sim_send_byte(uint8_t data);
/* ģ��I2C��ȡ���ֽ� */
uint8_t i2c_sim_read_byte(void);
/* ģ��I2C��Ĵ���д�뵥�ֽ� */
void i2c_sim_write_reg_byte(uint8_t addr, uint8_t reg, uint8_t dat);
/* ģ��I2C��Ĵ���д����ֽ����� */
void i2c_sim_write_reg_bytes(uint8_t addr, uint8_t reg, uint8_t *dat, uint8_t length);
/* ģ��I2C�ӼĴ�����ȡ���ֽ� */
void i2c_sim_read_reg_bytes(uint8_t addr, uint8_t reg, uint8_t *dat, uint8_t length);

//�ڲ����ã��û������ע
/* ģ��I2C��ʱ ʱ������ */
void i2c_sim_delay(uint16_t time);
/* ģ��I2C��ʼ�ź� */
void i2c_sim_start(void);
/* ģ��I2C��ֹ�ź� */
void i2c_sim_stop(void);
/* ģ��I2C�ȴ�Ӧ���ź� */
void i2c_sim_waitack(void);
/* ģ��I2CӦ���ź� */
void i2c_sim_ack(void);
/* ģ��I2C��Ӧ���ź� */
void i2c_sim_nack(void);

#endif