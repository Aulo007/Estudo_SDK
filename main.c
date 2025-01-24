#include <stdio.h>
#include "pico/stdlib.h"
#include "stdlib.h"
#include "menu.h"
#include "keypad.h"
#include "leds.h"
#include "buzzer.h"

MenuOption main_menu[] = {
    {'1', "Buzzer"},
    {'2', "Led sequencial"}};

int main()
{

    stdio_init_all();
    busy_wait_us(1000000); // Aguarda 1 segundo para garantir que o stdio está pronto
    keypad_init();
    buzzer_init();
    led_init();

    menu_display(main_menu, sizeof(main_menu) / sizeof(MenuOption));
    bool mostra_menu = true;

    do
    {
        char tecla = keypad_read();

        if (menu_is_valid_option(main_menu, sizeof(main_menu) / sizeof(MenuOption), tecla))
        {
            switch (tecla)
            {
            case '1':
                printf("Buzzer tocando...\n");
                buzzer_beep();
                mostra_menu = true;
                break;

            case '2':
                printf("Leds piscando de forma sequencial...\n");
                Sequential_led();
                mostra_menu = true;
                break;

                if (mostra_menu)
                {
                    menu_display(main_menu, sizeof(main_menu) / sizeof(MenuOption));
                    mostra_menu = false;
                }
            }
        }
    } while (true);

    return EXIT_SUCCESS;
}
