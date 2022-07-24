/*********************************************************************************************************************
* @file            hf_flash.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_FLASH_H
#define _HF_FLASH_H

#include "headfile.h"

/* 宏定义声明 */

/* 定义1KB的大小 */
#define SIZE_1KB ((uint32_t)0x00000400U) /*!< size of 1KB*/

/* FLASH起始地址 */
#define FMC_START_ADDRESS FLASH_BASE /*!< FMC start address */

#define FMC_SIZE (*(uint16_t*)0x400U) /*!< FMC SIZE 64KB*/
#define FMC_END_ADDRESS \
    (FLASH_BASE + (FMC_SIZE * 64) - 1) /*!< FMC end address */


/* 函数声明 */

/* 写 uint32_t 数据 */
uint8_t flash_WritePage_uint32_t(uint32_t pageName,
    uint32_t offset,
    uint32_t* writeData,
    uint16_t length);
/* 读 uint32_t 数据 */
uint8_t flash_ReadPage_uint32_t(uint32_t pageName,
    uint32_t offset,
    uint32_t* readData,
    uint16_t length);
/* 检查页内是否存在数据 */
uint8_t flash_check(uint32_t pageName);

#endif
