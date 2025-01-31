#include <stdio.h>
#include "pico/stdlib.h"
#include "init.h"
#include "temporizador.h"

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time_A = 0; // Armazena o tempo do último evento (em microssegundos)

bool led_active = false;    // Indica se o LED está atualmente aceso (para evitar múltiplas ativações).
absolute_time_t turn_off_time;  // Variável para armazenar o tempo em que o LED deve ser desligado (não utilizada neste código).

// Função responsável pelo debounce
bool debounce(volatile uint32_t *last_time, uint32_t debounce_time) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - *last_time > debounce_time) {
        *last_time = current_time;
        return true;
    }
    return false;
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Incrementação do número da matriz de leds
    if (gpio == BUTTON_A && debounce(&last_time_A, 200000) && !led_active)
    {
        last_time_A = current_time;
        printf("A: %d\n", a); // Para controle quando se usa o monitor serial para verificar se há bouncing
        a++;
        // Liga o LED configurando o pino LED_PIN para nível alto.
        gpio_put(VERDE, true);
        gpio_put(AZUL, true);
        gpio_put(VERMELHO, true);

        // Define 'led_active' como true para indicar que o LED está aceso.
        led_active = true;

        // Agenda um alarme para desligar o LED após 3 segundos (3000 ms).
        // A função 'turn_off_callback' será chamada após esse tempo.
        add_alarm_in_ms(3000, Led, turn_off_callback, NULL, false);
    }
}