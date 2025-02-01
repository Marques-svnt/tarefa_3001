#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"

extern bool led_active; // Exportação do booleano que foi inicializado na função interrupt.c

static volatile uint LED_PINO = 11; // Váriavel para controle de qual pino desligar 

// Função de callback para desligar os LEDs após o tempo programado e realizar 3 repetições
int64_t turn_off_callback(alarm_id_t id, void *user_data)
{
    if (LED_PINO != 13)
    {
        gpio_put(LED_PINO, false);
        LED_PINO++;
        return 3000*1000;
    }
    else
    {
        gpio_put(LED_PINO, false);
        LED_PINO = 11;
        led_active = false;
        return 0;
    }
}
