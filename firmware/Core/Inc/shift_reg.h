#ifndef __SHIFT_REG_H
#define __SHIFT_REG_H

typedef struct
{
  GPIO_TypeDef Ser_GPIO_Port;
  GPIO_TypeDef Rclk_GPIO_Port;
  GPIO_TypeDef Srclk_GPIO_Port;
  uint16_t Ser_GPIO_Pin;
  uint16_t Rclk_GPIO_Pin;
  uint16_t Srclk_GPIO_Pin;
} ShiftReg_InitTypeDef;

#endif /* __STM32F0xx_HAL_GPIO_H */
