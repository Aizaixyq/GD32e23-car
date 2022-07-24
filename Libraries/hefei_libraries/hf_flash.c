/*********************************************************************************************************************
* @file            hf_flash.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_flash.h"

//-------------------------------------------------------------------------------------------------------------------
//@brief        写 uint32_t 数据
//@param        扇区 name
//@param        偏移地址
//@param        要写入的数据
//@param        要写入的数据长度
//@return       返回0为失败，1为成功
//Sample usage：        flash_WritePage_uint32_t(3, 0, 0x05, 1);
                        //向第三页写入一个32位的数据0x05，偏移地址为0
//-------------------------------------------------------------------------------------------------------------------int flash_WritePage_uint32_t(uint32_t pageName,
uint8_t flash_WritePage_uint32_t(uint32_t pageName,
    uint32_t offset,
    uint32_t* writeData,
    uint16_t length)
{
    uint32_t i, page_start_address, page_end_address;

    /* 计算首地址和末地址*/
    page_start_address = offset + (FMC_START_ADDRESS + pageName * SIZE_1KB);
    page_end_address = page_start_address + 4 * length;

    //避免值过大导致程序卡死
    if ((page_end_address - page_start_address) >= SIZE_1KB)
    {
        return 0;
    }

    //解锁FLASH擦除控制单元
    fmc_unlock();
    //清空标志位
    fmc_flag_clear(FMC_FLAG_END | FMC_FLAG_WPERR | FMC_FLAG_PGERR);

    //以页为单位擦除
    while (FMC_READY != fmc_page_erase(page_start_address))
    {
        ;
    }

    //写入32位数据
    for (i = 0; i < length; i++) 
    {
        while (FMC_READY != fmc_word_program(page_start_address, writeData[i]))
        {
            ;
        }
        page_start_address = page_start_address + 4;
    }

    //锁上FLASH擦除控制单元
    fmc_lock();
    return 1;
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        读 uint32_t 数据
//@param        扇区 name
//@param        偏移地址
//@param        读取的数据
//@param        要读取的数据长度
//@return       返回0为失败，1为成功
//Sample usage：        flash_ReadPage_uint32_t(2, 0, read, 5)
                        //从第二扇区读取5个32位的数据，偏移地址为0，存放在read指向的地址中
//-------------------------------------------------------------------------------------------------------------------
uint8_t flash_ReadPage_uint32_t(uint32_t pageName,
    uint32_t  offset,
    uint32_t* readData,
    uint16_t  length)
{
    uint32_t i, page_start_address, page_end_address;

    /* 计算首地址和末地址*/
    page_start_address = offset + (FMC_START_ADDRESS + pageName * SIZE_1KB);
    page_end_address = page_start_address + 4 * length;

    /* 检查FMC忙碌标志位 */
    while(fmc_flag_get(FMC_FLAG_BUSY))
    {
        ;
    }

    //避免值过大导致程序卡死
    if ((page_end_address - page_start_address) >= SIZE_1KB)
    {
        return 0;
    }

    for (i=0; i<length; i++) 
    {
        readData[i] = *(__IO int8_t*)page_start_address;
        page_start_address = page_start_address + 4;
    }
    return 1;
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        检查页内是否存在数据
//@param        页 name
//@return       扇区起始地址
//Sample usage：        flash_getPageStartAddress(5);
                        //获取第五页的页起始地址
//-------------------------------------------------------------------------------------------------------------------
uint8_t flash_check(uint32_t pageName)
{
    uint32_t buf[SIZE_1KB];
    uint16_t i;

    i = 0;
    flash_ReadPage_uint32_t(pageName, 0, buf, SIZE_1KB);
    while(buf[i] == 0xff)
    {
        i++;
        if(i >= SIZE_1KB)
        {
            return 0;
        }
    }
    return 1;
}
