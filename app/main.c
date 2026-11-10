/*
 * app/main.c — Template stub.
 *
 * Replace the body with your project. This file exists only so that
 * `make` works on a fresh clone before you've written any code.
 *
 * It blinks PD12 in a busy loop — the same "hello, world" as the
 * original blinky project. If you see the LED blink, the toolchain,
 * linker script, startup code, and register map are all correct.
 */
#include "stm32f407_regs.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3U << (12 * 2));
    GPIOD->MODER |=  (GPIO_MODER_OUTPUT << (12 * 2));

    while (1) {
        GPIOD->ODR ^= (1U << 12);
        for (volatile uint32_t i = 0; i < 1000000U; i++) { }
    }
}
