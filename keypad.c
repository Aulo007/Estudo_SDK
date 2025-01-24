#include "keypad.h"

static uint colunas[4] = {COL1, COL2, COL3, COL4};
static uint linhas[4] = {ROW1, ROW2, ROW3, ROW4};

void keypad_init(void)
{
    // Inicializar colunas como entrada com pull-up
    for (int i = 0; i < 4; i++)
    {
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_IN);
        gpio_pull_up(colunas[i]);
    }

    // Inicializar linhas como saída
    for (int i = 0; i < 4; i++)
    {
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_OUT);
        gpio_put(linhas[i], 1);
    }
}

char keypad_read(void)
{
    char teclado[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

    for (int i = 0; i < 4; i++)
    {
        gpio_put(linhas[i], 0);
        sleep_ms(1);

        for (int j = 0; j < 4; j++)
        {
            if (gpio_get(colunas[j]) == 0)
            {
                gpio_put(linhas[i], 1);
                return teclado[i][j];
            }
        }

        gpio_put(linhas[i], 1);
    }

    return 'X';
}