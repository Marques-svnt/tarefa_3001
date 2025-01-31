#include <stdio.h>
#include "pico/stdlib.h"
#include "init.h"

void init(){
    // Inicializa todos os pinos
    gpio_init(VERMELHO);
    gpio_init(AZUL);
    gpio_init(VERDE);
    gpio_set_dir(VERMELHO, GPIO_OUT);
    gpio_set_dir(AZUL, GPIO_OUT);
    gpio_set_dir(VERDE, GPIO_OUT);

    // Inicializa o semáforo com o vermelho ligado
    gpio_put(VERMELHO, true);
    gpio_put(AZUL, false);
    gpio_put(VERDE, false);
}