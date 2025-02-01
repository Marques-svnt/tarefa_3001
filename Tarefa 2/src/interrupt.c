#include <stdio.h>
#include "pico/stdlib.h"
#include "init.h"
#include "temporizador.h"

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time_A = 0; // Armazena o tempo do último evento (em microssegundos)
bool led_active = false;                  // Indica se o LED está atualmente aceso (para evitar múltiplas ativações).

// Função responsável pelo debounce
bool debounce(volatile uint32_t *last_time, uint32_t debounce_time)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - *last_time > debounce_time)
    {
        *last_time = current_time;
        return true;
    }
    return false;
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{

    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Condição que vai disparar a função apenas quando os leds estiverem desligados e realizar o debounce no press do botão
    if (gpio == BUTTON_A && debounce(&last_time_A, 200000) && led_active == false)
    {
        printf("Botão foi pressionado e está travado\n");
        last_time_A = current_time;
        printf("A: %d\n", a); // Para controle quando se usa o monitor serial para verificar se há bouncing
        a++;

        // Liga os LEDs configurando os pinos para nível alto.
        gpio_put(VERDE, true);
        gpio_put(AZUL, true);
        gpio_put(VERMELHO, true);

        // Definir o booleano para travar o botão de funcionar enquanto a rotina dos botões estiverem funcionando
        led_active = true;

        // Função que vai programar o clock do evento a cada 3 segundos
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}