/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PADS_SER_Pin GPIO_PIN_13
#define PADS_SER_GPIO_Port GPIOC
#define PADS_RCLK_Pin GPIO_PIN_14
#define PADS_RCLK_GPIO_Port GPIOC
#define PADS_SRCLK_Pin GPIO_PIN_15
#define PADS_SRCLK_GPIO_Port GPIOC
#define LIGHTS_SRCLK_Pin GPIO_PIN_0
#define LIGHTS_SRCLK_GPIO_Port GPIOA
#define LIGHTS_RCLK_Pin GPIO_PIN_1
#define LIGHTS_RCLK_GPIO_Port GPIOA
#define LIGHTS_SER_Pin GPIO_PIN_2
#define LIGHTS_SER_GPIO_Port GPIOA
#define CH5_S4_Pin GPIO_PIN_3
#define CH5_S4_GPIO_Port GPIOA
#define CH5_S3_Pin GPIO_PIN_4
#define CH5_S3_GPIO_Port GPIOA
#define CH5_S2_Pin GPIO_PIN_5
#define CH5_S2_GPIO_Port GPIOA
#define CH5_S1_Pin GPIO_PIN_6
#define CH5_S1_GPIO_Port GPIOA
#define CH4_S4_Pin GPIO_PIN_7
#define CH4_S4_GPIO_Port GPIOA
#define CH4_S3_Pin GPIO_PIN_0
#define CH4_S3_GPIO_Port GPIOB
#define CH4_S2_Pin GPIO_PIN_1
#define CH4_S2_GPIO_Port GPIOB
#define CH4_S1_Pin GPIO_PIN_2
#define CH4_S1_GPIO_Port GPIOB
#define CH3_S4_Pin GPIO_PIN_10
#define CH3_S4_GPIO_Port GPIOB
#define CH3_S3_Pin GPIO_PIN_11
#define CH3_S3_GPIO_Port GPIOB
#define CH3_S2_Pin GPIO_PIN_12
#define CH3_S2_GPIO_Port GPIOB
#define CH3_S1_Pin GPIO_PIN_13
#define CH3_S1_GPIO_Port GPIOB
#define CH2_S4_Pin GPIO_PIN_14
#define CH2_S4_GPIO_Port GPIOB
#define CH2_S3_Pin GPIO_PIN_15
#define CH2_S3_GPIO_Port GPIOB
#define CH2_S2_Pin GPIO_PIN_8
#define CH2_S2_GPIO_Port GPIOA
#define CH2_S1_Pin GPIO_PIN_9
#define CH2_S1_GPIO_Port GPIOA
#define CH1_S4_Pin GPIO_PIN_10
#define CH1_S4_GPIO_Port GPIOA
#define CH1_S3_Pin GPIO_PIN_11
#define CH1_S3_GPIO_Port GPIOA
#define CH1_S2_Pin GPIO_PIN_12
#define CH1_S2_GPIO_Port GPIOA
#define CH1_S1_Pin GPIO_PIN_6
#define CH1_S1_GPIO_Port GPIOF
#define OPT_LIGHT_Pin GPIO_PIN_7
#define OPT_LIGHT_GPIO_Port GPIOF
#define OPT_DEBOUNCE_Pin GPIO_PIN_15
#define OPT_DEBOUNCE_GPIO_Port GPIOA
#define OPT_LEGACY_Pin GPIO_PIN_3
#define OPT_LEGACY_GPIO_Port GPIOB
#define COMM_TEST_Pin GPIO_PIN_4
#define COMM_TEST_GPIO_Port GPIOB
#define COMM_FL5_Pin GPIO_PIN_5
#define COMM_FL5_GPIO_Port GPIOB
#define COMM_FL4_Pin GPIO_PIN_6
#define COMM_FL4_GPIO_Port GPIOB
#define COMM_FL3_Pin GPIO_PIN_7
#define COMM_FL3_GPIO_Port GPIOB
#define COMM_FL2_Pin GPIO_PIN_8
#define COMM_FL2_GPIO_Port GPIOB
#define COMM_FL1_Pin GPIO_PIN_9
#define COMM_FL1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define CH1_S1 0x00000001U
#define CH1_S2 0x00000002U
#define CH1_S3 0x00000004U
#define CH1_S4 0x00000008U
#define CH1_OR 0x0000000FU

#define CH2_S1 0x00000010U
#define CH2_S2 0x00000020U
#define CH2_S3 0x00000040U
#define CH2_S4 0x00000080U
#define CH2_OR 0x000000F0U

#define CH3_S1 0x00000100U
#define CH3_S2 0x00000200U
#define CH3_S3 0x00000400U
#define CH3_S4 0x00000800U
#define CH3_OR 0x00000F00U

#define CH4_S1 0x00001000U
#define CH4_S2 0x00002000U
#define CH4_S3 0x00004000U
#define CH4_S4 0x00008000U
#define CH4_OR 0x0000F000U

#define CH5_S1 0x00010000U
#define CH5_S2 0x00020000U
#define CH5_S3 0x00040000U
#define CH5_S4 0x00080000U
#define CH5_OR 0x000F0000U

#define COMM_FL1	0x00100000U
#define COMM_FL2  0x00200000U
#define COMM_FL3  0x00400000U
#define COMM_FL4  0x00800000U
#define COMM_FL5  0x01000000U
#define COMM_TEST 0x02000000U

#define OPT_LIGHT 	 0x04000000U
#define OPT_DEBOUNCE 0x08000000U
#define OPT_LEGACY	 0x10000000U

#define CH1_LIGHT  0x20U
#define CH2_LIGHT  0x10U
#define CH3_LIGHT  0x08U
#define CH4_LIGHT  0x04U
#define CH5_LIGHT  0x02U
#define STATUS_LED 0x01U
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
