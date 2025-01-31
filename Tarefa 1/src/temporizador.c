#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"

static volatile uint index = 1; /* Váriavel que vai controlar o estado do led (a inicialização em 1
                                deve-se ao fato de que na função de init já está definido para o pino começar vermelho)*/

// Função de retorno de chamada (callback) associada a um temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer *t) {
    // Liga o led vermelho
    if(index == 0){
        gpio_put(VERMELHO, true);
        gpio_put(AMARELO, false);
        gpio_put(VERDE, false);
        index++;

    // Liga o led amarelo
    } else if (index == 1){
        gpio_put(VERMELHO, false);
        gpio_put(AMARELO, true);
        gpio_put(VERDE, false);
        index++;

    // Liga o led verde
    } else if (index == 2){
        gpio_put(VERMELHO, false);
        gpio_put(AMARELO, false);
        gpio_put(VERDE, true);
        index = 0;
    }
    return true; // Continua o temporizador
}
