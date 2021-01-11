#include <mbed.h>

volatile unsigned long _clock_counter;

void millisStart(void)
{
    SysTick_Config(SystemCoreClock / 1000);
}

extern "C" void SysTick_Handler(void)
{
    _clock_counter++;
}

unsigned long millis(void)
{
    return _clock_counter;
}