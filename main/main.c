#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"


int main()
{
    stdio_init_all();
    init();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
