/*
==================================================================================================
Construa um programa que declare uma matriz de float 5x4. Em cada linha ser�o                    |
armazenadas tr�s notas e a m�dia calculada para um aluno.                                        |
Ex.: O programa deve ler do teclado as notas do aluno 0, armazenar na linha 0 (nas colunas 0,    |
1 e 2) e calcular a m�dia dele. A m�dia ser� armazenada na coluna 3. O mesmo deve ser feito      |
para os demais alunos.                                                                           |
O programa deve ser capaz de mostrar na tela:                                                    |
                                                                                                 |
(X)� As notas e as m�dias dos alunos (cada aluno � identificado pelo �ndice da respectiva           |
coluna � 0, 1 etc.)                                                                              |
(X)� Se os alunos foram aprovados ou n�o (a m�dia � 6.0)                                            |
(X)� A maior de todas as m�dias                                                                     |
(X)� A menor de todas as m�dias                                                                     |
                                                                                                 |
Orienta��es:                                                                                     |
� Todo o programa deve ser constru�do no main, ou seja, n�o podem ser usadas                     |
fun��es separadas porque isso n�o foi visto nas aulas.                                           |
� Use as estruturas de repeti��o (while, do while ou for) para a leitura dos valores e           |
para a realiza��o dos c�lculos.                                                                  |
� Ap�s a realiza��o dos c�lculos para um grupo de 5 alunos (a capacidade da matriz) o            |
professor pode escolher se sai do programa ou se realiza novos c�lculos                          |
==================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <unistd.h>

int main()
{
    float soma=0, med=0, maior, menor;
    int i, j, opcao, sair = 0;

    float mtz [5][4];
        /*

         n1  n2   n3  media
    Al1  0   0    0     0
    Al2  0   0    0     0
    Al3  0   0    0     0
    Al4  0   0    0     0
    Al5  0   0    0     0

         */

    while (!sair)
    {

        // INSERINDO AS NOTAS E VALORES PARA CADA ALUNO //

        for(i=0; i<=4; i++) // PARA - TODAS AS LINHAS
        {
            mtz[i][3]=0; // ORGANIZANDO O VALOR PRA 0 NA COLUNA DAS M�DIAS

            for(j=0; j<=2; j++) // PARA - PRIMEIRAS TR�S COLUNAS [0][0], [0][1], [0][2];
            {
                printf("\nDigite a nota %i do Aluno %i: ", j+1,i+1); // J+1, I+1 - PARA SOMAR NO %i E N�O FICAR DATADO NO 0 COMO DE COSTUME
                scanf("%f", &mtz[i][j]);
                mtz[i][3]+=mtz[i][j]; // SOLU��O QUE ACHEI PARA SALVAR NA COLUNA [i][3] A SOMA DAS NOTAS
            }

            mtz[i][3]/=3; // calcula a media

            printf("\nO aluno possui a media de: %.1f\n\n", mtz[i][3]); // DIVIDINDO O VALOR TOTAL QUE ALOQUEI NA MATRIZ [i][3]

            if ((mtz[i][3])<6.0) // COMANDO IF - VERIFICAR SE O VALOR DA SOMA DAS NOTAS/ 3 � MAIOR OU MENOR QUE A M�DIA
            {
                printf("\n===============================\n");
                printf("|\tAluno REPROVADO!      |");
                printf("\n===============================\n");
                system("pause");
                system("cls");
             }
            else
            {
                printf("\n===============================\n");
                printf("|\t Aluno APROVADO!      |");
                printf("\n===============================\n");
                system("pause");
                system("cls");
             }

        }

        // CALCULAR A MAIOR E MENOR M�DIA //

        maior = mtz [0][3];
        menor = mtz [0][3];

        for (i=0; i<=4; i++) // COLUNA DE M�DIA
        {
            if (mtz[i][3] > maior) // IF MAIOR
            {
                maior=mtz[i][3];
                printf("\n");
            }

            if (mtz[i][3] < menor) // IF MENOR
            {
                menor=mtz[i][3];
                printf("\n");
            }
        }
        printf("A maior media entre as notas: %.1f\n", maior);
        printf("A menor media entre as notas: %.1f\n", menor);


            //BOT�ES - FINALIZA��O TRABALHO
        printf("\n\n");
        printf("==========Console==========\n");
        printf("| 1 | Sair                |\n");
        printf("| 2 | Reiniciar           |\n");
        printf("===========================\n");

        printf("\nSelecione uma das opcoes: ");
        scanf("%d", &opcao);
        switch (opcao)
            {
            case 1:
                sair = 1;
                system("cls");
                break;
            case 2:
                sair = 0;
                system("cls");
            }
    }
}


