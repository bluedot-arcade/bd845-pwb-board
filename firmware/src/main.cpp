#include "mbed.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);

int main()
{
    while (true)
    {
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}