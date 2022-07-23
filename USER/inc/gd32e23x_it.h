/*!
    \file    gd32e23x_it.h
    \brief   the header file of the ISR
    
    \version 2019-02-19, V1.0.0, firmware for GD32E23x
    \version 2020-12-12, V1.1.0, firmware for GD32E23x
*/

/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef GD32E23X_IT_H
#define GD32E23X_IT_H

#include "gd32e23x.h"

/* function declarations */

/*  NMI �жϷ����� */
void NMI_Handler(void);
/*  HardFault �жϷ����� */
void HardFault_Handler(void);
/*  MemManage �жϷ����� */
void MemManage_Handler(void);
/*  BusFault �жϷ����� */
void BusFault_Handler(void);
/*  UsageFault �жϷ����� */
void UsageFault_Handler(void);
/*  SVC �жϷ����� */
void SVC_Handler(void);
/*  DebugMon �жϷ����� */
void DebugMon_Handler(void);
/*  PendSV �жϷ����� */
void PendSV_Handler(void);
/*  SysTick �жϷ����� */
void SysTick_Handler(void);


/* EXTI0_1 �жϷ����� */
void EXTI0_1_IRQHandler(void);
/*  EXTI2_3 �жϷ����� */
void EXTI2_3_IRQHandler(void);
/*  EXTI4_15 �жϷ����� */
void EXTI4_15_IRQHandler(void);
/*  TIMER0_Channel �жϷ����� */
void TIMER0_Channel_IRQHandler(void);
/*  TIMER2 �жϷ����� */
void TIMER2_IRQHandler(void);
/*  TIMER5 �жϷ����� */
void TIMER5_IRQHandler(void);
/*  TIMER13 �жϷ����� */
void TIMER13_IRQHandler(void);
/*  TIMER14 �жϷ����� */
void TIMER14_IRQHandler(void);
/*  TIMER15 �жϷ����� */
void TIMER15_IRQHandler(void);
/*  TIMER16 �жϷ����� */
void TIMER16_IRQHandler(void);
/*  I2C0_EV �жϷ����� */
void I2C0_EV_IRQHandler(void);
/*  I2C1_EV �жϷ����� */
void I2C1_EV_IRQHandler(void);
/*  SPI0 �жϷ����� */
void SPI0_IRQHandler(void);
/*  SPI1 �жϷ����� */
void SPI1_IRQHandler(void);
/*  USART0 �жϷ����� */
void USART0_IRQHandler(void);
/*  USART1 �жϷ����� */
void USART1_IRQHandler(void);

#endif /* GD32E23X_IT_H */