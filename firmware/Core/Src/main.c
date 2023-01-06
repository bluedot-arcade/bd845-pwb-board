/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t Inputs_State;
uint8_t Lights_State;
uint8_t Pads_State;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void ShiftOut_Lights(uint8_t data);
void Update_Inputs_State(void);
void Update_Lights_State(void);
void Update_Pads_State(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  	Update_Inputs_State();
  	Update_Lights_State();
  	Update_Pads_State();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL3;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, PADS_SER_Pin|PADS_RCLK_Pin|PADS_SRCLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LIGHTS_SRCLK_Pin|LIGHTS_RCLK_Pin|LIGHTS_SER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PADS_SER_Pin PADS_RCLK_Pin PADS_SRCLK_Pin */
  GPIO_InitStruct.Pin = PADS_SER_Pin|PADS_RCLK_Pin|PADS_SRCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LIGHTS_SRCLK_Pin LIGHTS_RCLK_Pin LIGHTS_SER_Pin */
  GPIO_InitStruct.Pin = LIGHTS_SRCLK_Pin|LIGHTS_RCLK_Pin|LIGHTS_SER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : CH5_S4_Pin CH5_S3_Pin CH5_S2_Pin CH5_S1_Pin
                           CH4_S4_Pin CH2_S2_Pin CH2_S1_Pin CH1_S4_Pin
                           CH1_S3_Pin CH1_S2_Pin OPT_DEBOUNCE_Pin */
  GPIO_InitStruct.Pin = CH5_S4_Pin|CH5_S3_Pin|CH5_S2_Pin|CH5_S1_Pin
                          |CH4_S4_Pin|CH2_S2_Pin|CH2_S1_Pin|CH1_S4_Pin
                          |CH1_S3_Pin|CH1_S2_Pin|OPT_DEBOUNCE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : CH4_S3_Pin CH4_S2_Pin CH4_S1_Pin CH3_S4_Pin
                           CH3_S3_Pin CH3_S2_Pin CH3_S1_Pin CH2_S4_Pin
                           CH2_S3_Pin OPT_LEGACY_Pin COMM_TEST_Pin COMM_FL5_Pin
                           COMM_FL4_Pin COMM_FL3_Pin COMM_FL2_Pin COMM_FL1_Pin */
  GPIO_InitStruct.Pin = CH4_S3_Pin|CH4_S2_Pin|CH4_S1_Pin|CH3_S4_Pin
                          |CH3_S3_Pin|CH3_S2_Pin|CH3_S1_Pin|CH2_S4_Pin
                          |CH2_S3_Pin|OPT_LEGACY_Pin|COMM_TEST_Pin|COMM_FL5_Pin
                          |COMM_FL4_Pin|COMM_FL3_Pin|COMM_FL2_Pin|COMM_FL1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : CH1_S1_Pin */
  GPIO_InitStruct.Pin = CH1_S1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(CH1_S1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OPT_LIGHT_Pin */
  GPIO_InitStruct.Pin = OPT_LIGHT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OPT_LIGHT_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void Update_Inputs_State(void)
{
	uint32_t State = 0;

	//Update CH1 States
	State |= HAL_GPIO_ReadPin(CH1_S1_GPIO_Port, CH1_S1_Pin) << 0;
	State |= HAL_GPIO_ReadPin(CH1_S2_GPIO_Port, CH1_S2_Pin) << 1;
	State |= HAL_GPIO_ReadPin(CH1_S3_GPIO_Port, CH1_S3_Pin) << 2;
	State |= HAL_GPIO_ReadPin(CH1_S4_GPIO_Port, CH1_S4_Pin) << 3;

	//Update CH2 States
	State |= HAL_GPIO_ReadPin(CH2_S1_GPIO_Port, CH2_S1_Pin) << 4;
	State |= HAL_GPIO_ReadPin(CH2_S2_GPIO_Port, CH2_S2_Pin) << 5;
	State |= HAL_GPIO_ReadPin(CH2_S3_GPIO_Port, CH2_S3_Pin) << 6;
	State |= HAL_GPIO_ReadPin(CH2_S4_GPIO_Port, CH2_S4_Pin) << 7;

	//Update CH3 States
	State |= HAL_GPIO_ReadPin(CH3_S1_GPIO_Port, CH3_S1_Pin) << 8;
	State |= HAL_GPIO_ReadPin(CH3_S2_GPIO_Port, CH3_S2_Pin) << 9;
	State |= HAL_GPIO_ReadPin(CH3_S3_GPIO_Port, CH3_S3_Pin) << 10;
	State |= HAL_GPIO_ReadPin(CH3_S4_GPIO_Port, CH3_S4_Pin) << 11;

	//Update CH4 States
	State |= HAL_GPIO_ReadPin(CH4_S1_GPIO_Port, CH4_S1_Pin) << 12;
	State |= HAL_GPIO_ReadPin(CH4_S2_GPIO_Port, CH4_S2_Pin) << 13;
	State |= HAL_GPIO_ReadPin(CH4_S3_GPIO_Port, CH4_S3_Pin) << 14;
	State |= HAL_GPIO_ReadPin(CH4_S4_GPIO_Port, CH4_S4_Pin) << 15;

	//Update CH5 States
	State |= HAL_GPIO_ReadPin(CH5_S1_GPIO_Port, CH5_S1_Pin) << 16;
	State |= HAL_GPIO_ReadPin(CH5_S2_GPIO_Port, CH5_S2_Pin) << 17;
	State |= HAL_GPIO_ReadPin(CH5_S3_GPIO_Port, CH5_S3_Pin) << 18;
	State |= HAL_GPIO_ReadPin(CH5_S4_GPIO_Port, CH5_S4_Pin) << 19;

	//Update COMM states
	State |= HAL_GPIO_ReadPin(COMM_FL1_GPIO_Port, COMM_FL1_GPIO_Port) << 20;
	State |= HAL_GPIO_ReadPin(COMM_FL2_GPIO_Port, COMM_FL2_GPIO_Port) << 21;
	State |= HAL_GPIO_ReadPin(COMM_FL3_GPIO_Port, COMM_FL3_GPIO_Port) << 22;
	State |= HAL_GPIO_ReadPin(COMM_FL4_GPIO_Port, COMM_FL4_GPIO_Port) << 23;
	State |= HAL_GPIO_ReadPin(COMM_FL5_GPIO_Port, COMM_FL5_GPIO_Port) << 24;
	State |= HAL_GPIO_ReadPin(COMM_TEST_GPIO_Port, COMM_TEST_GPIO_Port) << 25;

	State |= ~HAL_GPIO_ReadPin(OPT_LIGHT_GPIO_Port, OPT_LIGHT_Pin) << 26;
	State |= ~HAL_GPIO_ReadPin(OPT_DEBOUNCE_GPIO_Port, OPT_DEBOUNCE_Pin) << 27;
	State |= ~HAL_GPIO_ReadPin(OPT_LEGACY_GPIO_Port, OPT_LEGACY_Pin) << 28;

	Inputs_State = ~State;
}

void Update_Lights_State(void)
{
	//TODO
	uint8_t State = 0;

	if(Inputs_State & OPT_LIGHT)
  {
		if(Inputs_State & CH1_OR) State |= STATUS_LED;

	}

	Lights_State = State;

	ShiftOut_Lights(Lights_State);
}

void Update_Pads_State(void)
{
	//TODO
}

void ShiftOut_Lights(uint8_t data)
{
	//MSBFirst
	for(int8_t i = 7; i >= 0; i--)
	{
		HAL_GPIO_WritePin(LIGHTS_SER_GPIO_Port, LIGHTS_SER_Pin, (data >> i) & 0x01);

		//Shift
		HAL_GPIO_WritePin(LIGHTS_SRCLK_GPIO_Port, LIGHTS_SRCLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LIGHTS_SRCLK_GPIO_Port, LIGHTS_SRCLK_Pin, GPIO_PIN_RESET);
	}

	// Latch
	HAL_GPIO_WritePin(LIGHTS_RCLK_GPIO_Port, LIGHTS_RCLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LIGHTS_RCLK_GPIO_Port, LIGHTS_RCLK_Pin, GPIO_PIN_RESET);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  	//Blink status LED indefinitely
	  ShiftOut_Lights(0x00);
	  HAL_Delay(500);
	  ShiftOut_Lights(STATUS_LED);
	  HAL_Delay(500);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
