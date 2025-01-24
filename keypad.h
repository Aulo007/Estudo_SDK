#ifndef KEYPAD_H
#define KEYPAD_H

#include "pico/stdlib.h"

// Configuração das portas GPIO para linhas e colunas
#define COL1 9
#define COL2 8
#define COL3 7
#define COL4 6
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10

// Função para inicializar o teclado
void keypad_init(void);

// Função para ler tecla pressionada
char keypad_read(void);

#endif // KEYPAD_H