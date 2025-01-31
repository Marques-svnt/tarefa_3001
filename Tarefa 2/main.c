#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "init.h"
#include "temporizador.h"
#include "interrupt.h"

int main()
{
    // Inicializações
    stdio_init_all();
    init();

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    // Loop Principal
    while (true) {
        sleep_ms(1000); // Reduz o uso da CPU
        printf("Tempo passando...\n"); // Mensagem para verificar passagem de tempo
    }
}
