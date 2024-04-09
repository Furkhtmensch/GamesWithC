#include <stdio.h>
#include <stdlib.h>

#define flushbuffer while (getc(stdin) != '\n')


char quadro[7][20] = {" %c | %c | %c \t", "-%c-|-%c-|-%c-\t", " %c | %c | %c \t", "-%c-|-%c-|-%c-\t", " %c | %c | %c \t"};
char guia[7][15] = {" 1 | 2 | 3 \n", "---|---|---\n", " 4 | 5 | 6 \n", "---|---|---\n", " 7 | 8 | 9 \n"};
char vitoria[] = "O jogador %d vence! \n\n";

void desenhar(char jogada, char jogador, char* memoria) {
    if (jogador != ' ') {
        if (jogador) {
            jogador = 'O';
        } else {
            jogador = 'X';
        }
        memoria[jogada - 1] = jogador;
    }
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 1) {
            printf(quadro[i], '-', '-', '-');
        } else {
            printf(quadro[i], memoria[j], memoria[j + 1], memoria[j + 2]);
            j += 3;
        }
        printf("%s", guia[i]);
    }
    printf("\n");
    return;
}

int galo() {
    char memoria[9] = "         ";
    char jogada, jogadas = 0, jogador = 0;
    char diag1 = 0, diag2 = 0, hori1 = 0, hori2 = 0, hori3 = 0, vert1 = 0, vert2 = 0, vert3 = 0;
    desenhar(jogada, ' ', memoria);
    while (jogadas < 9) {
        jogadas++;
        printf("Jogador %d: ", jogador + 1);
        jogada = getchar() - 48;
        flushbuffer;
        printf("\n");
        if (jogada % 4 == 1) {
            diag1 += (jogador * 2) - 1;
            if (abs(diag1) == 3) {
                desenhar(jogada, jogador, memoria);
                printf(vitoria, jogador + 1);
                return diag1 > 0;
            }
        }
        if (jogada % 2 == 1 && jogada % 8 != 1) {
            diag2 += (jogador * 2) - 1;
            if (abs(diag2) == 3) {
                desenhar(jogada, jogador, memoria);
                printf(vitoria, jogador + 1);
                return diag2 > 0;
            }
        }
        switch ((jogada - 1) / 3) {
            case 0: {
                hori1 += (jogador * 2) - 1;
                if (abs(hori1) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return hori1 > 0;
                }
                break;
            } case 1: {
                hori2 += (jogador * 2) - 1;
                if (abs(hori2) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return hori2 > 0;
                }
                break;
            } case 2: {
                hori3 += (jogador * 2) - 1;
                if (abs(hori3) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return hori3 > 0;
                }
                break;
            } default: {
                break;
            }
        }
        switch (jogada % 3) {
            case 0: {
                vert1 += (jogador * 2) - 1;
                if (abs(vert1) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return vert1 > 0;
                }
                break;
            } case 1: {
                vert2 += (jogador * 2) - 1;
                if (abs(vert2) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return vert2 > 0;
                }
                break;
            } case 2: {
                vert3 += (jogador * 2) - 1;
                if (abs(vert3) == 3) {
                    desenhar(jogada, jogador, memoria);
                    printf(vitoria, jogador + 1);
                    return vert3 > 0;
                }
                break;
            } default: {
                break;
            }
        }
        desenhar(jogada, jogador, memoria);
        jogador = !jogador;
    }
    printf("Empate! \n");
    return 2;
}

int iniciargalo(int repetiu) {
    printf("\n     - JOGO DO GALO - \n\n");
    char resposta;
    if (repetiu) {
        printf("Jogar de novo?\n1 - sim\n0 - não\n");
        resposta = getc(stdin) - 48;
        if (resposta) {
            galo();
            iniciargalo(1);
            return 1;
        }
        return 0;
    } else {
        galo();
        return iniciargalo(1);
    }
}

int main() {
    iniciargalo(0);
    return 0;
}
