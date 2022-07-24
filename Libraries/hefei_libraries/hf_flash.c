/*********************************************************************************************************************
* @file            hf_flash.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_flash.h"

//-------------------------------------------------------------------------------------------------------------------
//@brief        д uint32_t ����
//@param        ���� name
//@param        ƫ�Ƶ�ַ
//@param        Ҫд�������
//@param        Ҫд������ݳ���
//@return       ����0Ϊʧ�ܣ�1Ϊ�ɹ�
//Sample usage��        flash_WritePage_uint32_t(3, 0, 0x05, 1);
                        //�����ҳд��һ��32λ������0x05��ƫ�Ƶ�ַΪ0
//-------------------------------------------------------------------------------------------------------------------int flash_WritePage_uint32_t(uint32_t pageName,
uint8_t flash_WritePage_uint32_t(uint32_t pageName,
    uint32_t offset,
    uint32_t* writeData,
    uint16_t length)
{
    uint32_t i, page_start_address, page_end_address;

    /* �����׵�ַ��ĩ��ַ*/
    page_start_address = offset + (FMC_START_ADDRESS + pageName * SIZE_1KB);
    page_end_address = page_start_address + 4 * length;

    //����ֵ�����³�����
    if ((page_end_address - page_start_address) >= SIZE_1KB)
    {
        return 0;
    }

    //����FLASH�������Ƶ�Ԫ
    fmc_unlock();
    //��ձ�־λ
    fmc_flag_clear(FMC_FLAG_END | FMC_FLAG_WPERR | FMC_FLAG_PGERR);

    //��ҳΪ��λ����
    while (FMC_READY != fmc_page_erase(page_start_address))
    {
        ;
    }

    //д��32λ����
    for (i = 0; i < length; i++) 
    {
        while (FMC_READY != fmc_word_program(page_start_address, writeData[i]))
        {
            ;
        }
        page_start_address = page_start_address + 4;
    }

    //����FLASH�������Ƶ�Ԫ
    fmc_lock();
    return 1;
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        �� uint32_t ����
//@param        ���� name
//@param        ƫ�Ƶ�ַ
//@param        ��ȡ������
//@param        Ҫ��ȡ�����ݳ���
//@return       ����0Ϊʧ�ܣ�1Ϊ�ɹ�
//Sample usage��        flash_ReadPage_uint32_t(2, 0, read, 5)
                        //�ӵڶ�������ȡ5��32λ�����ݣ�ƫ�Ƶ�ַΪ0�������readָ��ĵ�ַ��
//-------------------------------------------------------------------------------------------------------------------
uint8_t flash_ReadPage_uint32_t(uint32_t pageName,
    uint32_t  offset,
    uint32_t* readData,
    uint16_t  length)
{
    uint32_t i, page_start_address, page_end_address;

    /* �����׵�ַ��ĩ��ַ*/
    page_start_address = offset + (FMC_START_ADDRESS + pageName * SIZE_1KB);
    page_end_address = page_start_address + 4 * length;

    /* ���FMCæµ��־λ */
    while(fmc_flag_get(FMC_FLAG_BUSY))
    {
        ;
    }

    //����ֵ�����³�����
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
//@brief        ���ҳ���Ƿ��������
//@param        ҳ name
//@return       ������ʼ��ַ
//Sample usage��        flash_getPageStartAddress(5);
                        //��ȡ����ҳ��ҳ��ʼ��ַ
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
