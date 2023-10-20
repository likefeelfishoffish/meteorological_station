/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart5;

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */
//#define BAUD_RATE_9600                  9600    /* 波特率取值 */
//#define DATA_BITS_8                     8       /* 数据位取值 */
//#define STOP_BITS_1                     0       /* 停止位取值 */
//#define PARITY_NONE                     0       /* 极性位取值 */
//#define BIT_ORDER_LSB                   0       /* 高低位顺序取值 */
//#define NRZ_NORMAL                      0       /* 模式取值 */
//#define RT_SERIAL_RB_BUFSZ              64      /* 接收数据缓冲区默认大小 */

//#define RT_SERIAL_CONFIG_T_RH              \
//{                                          \
//    BAUD_RATE_9600, /* 115200 bits/s */  \
//    DATA_BITS_8,      /* 8 databits */     \
//    STOP_BITS_1,      /* 1 stopbit */      \
//    PARITY_NONE,      /* No parity  */     \
//    BIT_ORDER_LSB,    /* LSB first sent */ \
//    NRZ_NORMAL,       /* Normal mode */    \
//    RT_SERIAL_RB_BUFSZ, /* Buffer size */  \
//    0                                      \
//}

/* USER CODE END Private defines */

void MX_UART5_Init(void);
void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

