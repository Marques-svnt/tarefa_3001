# Projeto: Temporizadores com Raspberry Pi Pico W

## Descrição
Este projeto utiliza a placa Raspberry Pi Pico W para demonstrar o controle de LEDs com temporizadores e interrupções. Ele explora técnicas de manipulação de GPIOs, temporizadores periódicos e de disparo único, além do uso de debounce por software para botões.

---

## Funcionalidades

### Tarefa 1: Temporizador Periódico
- **Controle de LEDs (Vermelho, Amarelo e Verde)**:
  - Os LEDs mudam de estado ciclicamente a cada 3 segundos.
- **Mensagens no Monitor Serial**:
  - Exibe mensagens a cada segundo para verificar a execução do temporizador.

### Tarefa 2: Temporizador de Um Disparo (One Shot)
- **Controle de LEDs (Azul, Vermelho e Verde)**:
  - Os LEDs são acionados ao pressionar um botão e desligados em sequência a cada 3 segundos.
- **Bloqueio do Botão Durante a Execução**:
  - O botão só pode ser pressionado novamente após o desligamento completo dos LEDs.
- **Debounce por Software**:
  - Implementa uma rotina para evitar o efeito bouncing do botão.

---

## Requisitos

- Placa Raspberry Pi Pico W
- 01 LED RGB (tarefa 1) e 03 LEDs vermelho, azul e verde (tarefa 2)
- Botão Pushbutton (para a Tarefa 2)
- Ambiente de desenvolvimento VS Code configurado com Pico SDK
- Simulador Wokwi

---

## Configuração

### Mapeamento de GPIOs

| Componente | GPIO |
|------------|------|
| LED Vermelho | GPIO 11 |
| LED Amarelo  | GPIO 12 |
| LED Verde    | GPIO 13 |
| Botão A     | GPIO 5  |

---

## Compilação e Execução

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Navegue até a extensão do **Raspberry Pi Pico Project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cell e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Configure os componentes conforme a especificação das atividades.
3. Teste o funcionamento do programa diretamente no ambiente emulado.

## Colaboradores

- [Gabriel Marques](https://github.com/Marques-svnt)

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

