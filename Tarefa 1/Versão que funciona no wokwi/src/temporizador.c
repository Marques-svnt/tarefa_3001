#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {

    // Desliga o LED configurando o pino LED_PIN para nível baixo.
    gpio_put(LED_PIN, false);

    // Atualiza o estado de 'led_active' para falso, indicando que o LED está desligado.
    led_active = false;

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;}