#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"
#include "temporizador.h"

int main()
{
    stdio_init_all();
    init();
    temporizador();

    while (true) {
        sleep_ms(1000); // Reduz o uso da CPU
        printf("Tempo passando...\n");
    }
}
