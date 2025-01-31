#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"
#include "temporizador.h"

int main()
{
    stdio_init_all();
    init();
    // Configura o temporizador repetitivo para 3000ms
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (true) {
        sleep_ms(1000); // Reduz o uso da CPU
        printf("Tempo passando...\n");
    }
}
