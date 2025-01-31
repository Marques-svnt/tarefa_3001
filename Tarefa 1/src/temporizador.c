#include <stdio.h>
#include "pico/stdlib.h"
#include "init.h"

typedef enum {
    ESTADO_VERMELHO,
    ESTADO_AMARELO,
    ESTADO_VERDE
} EstadoSemaforo;

EstadoSemaforo estado_atual = ESTADO_VERMELHO;

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado_atual) {
        case ESTADO_VERMELHO:
            gpio_put(VERMELHO, true);
            gpio_put(AMARELO, false);
            gpio_put(VERDE, false);
            estado_atual = ESTADO_AMARELO;
            printf("Semáforo: Vermelho ligado\n");
            break;
        case ESTADO_AMARELO:
            gpio_put(VERMELHO, false);
            gpio_put(AMARELO, true);
            gpio_put(VERDE, false);
            estado_atual = ESTADO_VERDE;
            printf("Semáforo: Amarelo ligado\n");
            break;
        case ESTADO_VERDE:
            gpio_put(VERMELHO, false);
            gpio_put(AMARELO, false);
            gpio_put(VERDE, true);
            estado_atual = ESTADO_VERMELHO;
            printf("Semáforo: Verde ligado\n");
            break;
    }
    return true; // Continua o temporizador
}

void temporizador(){
    // Configura o temporizador repetitivo para 3000ms
    struct repeating_timer timer;
    if (!add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer)) {
        printf("Erro ao configurar o temporizador!\n");
    }
}