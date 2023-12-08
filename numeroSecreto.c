#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {

    printf("\n\n");
    printf("          P  /_\\  P                               \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n");
    printf("    |" "  |  |_|  |"  " |                          \n");
    printf("    |_____| ' _ ' |_____|                          \n");
    printf("          \\__|_|__/                               \n");
    printf("\n\n");

 


    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Qual o Nível de Dificuldade que deseja?\n");
    printf("(1) Fácil; (2) Médio; (3) Difícil;\n\n");
    scanf("%d", &nivel);

    int numeroTentativas;

    switch(nivel){
        
        case 1:
        numeroTentativas = 14;
        break;

        case 2:
        numeroTentativas = 7;
        break;

        default:
        numeroTentativas = 4;
        break;

    }

    for (int i = 1; i <= numeroTentativas; i++){

        printf("Tentativa %d\n", tentativas);
        printf("Qual o seu Chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n\n", chute);

        int maior = (chute > numeroSecreto);

        if (chute < 0){
            printf("Você Não pode chutar números negativos!\n");
       
        }

        acertou = (chute == numeroSecreto);

        if (acertou){
            break;
        }

        else if(maior){

            printf("SEU CHUTE FOI MAIOR QUE O NÚMERO SECRETO!\n\n");

        }

        else{

            printf("SEU CHUTE FOI MENOR QUE O NÚMERO SECRETO\n\n");

        }

        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        
        pontos = pontos - pontosPerdidos;
        
    }
    
    if (acertou){
        printf("Fim de Jogo! Você acertou em %d tentativas!\n\n", tentativas);
        printf("Obrigado por Jogar! Sua pontuação foi de: %.1f", pontos);
    } else{
        printf("Você Perdeu! O número secreto era %d. Tente Novamente!\n\n", numeroSecreto);

        printf("     \\|/ ____ \\|/    \n");   
        printf("      @~/ ,. \\~@      \n");   
        printf("     /_( \\__/ )_\\    \n");   
        printf("        \\__U_/        \n");
        
    }
    
}
