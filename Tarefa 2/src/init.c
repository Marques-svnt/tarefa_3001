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

    // Configurar o pino do botão A e habilitar o pull-up interno
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
}