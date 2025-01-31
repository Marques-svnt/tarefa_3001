#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"

static volatile uint LED_PINO = 11;

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data)
{
    if(LED_PINO != 14){
    gpio_put(LED_PINO, false);
    LED_PINO++;
    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 3000000;}
    else{
        return 0;
    }
}