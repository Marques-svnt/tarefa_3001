#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"

static volatile uint index = 1;

bool repeating_timer_callback(struct repeating_timer *t) {
    if(index == 0){
        gpio_put(VERMELHO, true);
        gpio_put(AMARELO, false);
        gpio_put(VERDE, false);
        index++;
    } else if (index == 1){
        gpio_put(VERMELHO, false);
        gpio_put(AMARELO, true);
        gpio_put(VERDE, false);
        index++;
    } else if (index == 2){
        gpio_put(VERMELHO, false);
        gpio_put(AMARELO, false);
        gpio_put(VERDE, true);
        index = 0;
    }
    return true; // Continua o temporizador
}
