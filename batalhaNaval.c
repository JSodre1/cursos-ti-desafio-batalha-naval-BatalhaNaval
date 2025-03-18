/* 
Desafio Batalha Naval - Estácio de Sá
Disciplina - Introdução à Programação de Computadores
Aluno: Jairçon Freitas Sodré Pereira Júnior
Nível MESTRE
*/


#include <stdio.h>

// Dimensões do Tabuleiro
#define LINHA 10
#define COLUNA 10
#define LIMITE 10

// Dimnensões dos Navios e Habilidades
#define NAVIO 3 // Dimensões e número impresso no tabuleiro
#define HABILIDADE 5 // Número impresso no tabuleiro
#define iHABILIDADE 1 // Define o número que aparece no raio de influencia da habilidade

int main() {

    char linha[LINHA];
    int coluna[COLUNA];
    int tabuleiro[LINHA][COLUNA];
    
/* Variáveis de Posicionamento dos Navios
O posicionamento leva em consideração o Índice central dos Navios
*/

    // Horizontal
    char navioHorizontalLetra = 'b';
    int navioHorizontalNumero = 2;
    
    // Vertical
    char navioVerticalLetra = 'a';
    int navioVerticalNumero = 5;
    
    // Diagonal/Baixo
    char navioDiagonalBaixoLetra = 'd';
    int navioDiagonalBaixoNumero = 6;
    
    // Diagonal/Cima
    char navioDiagonalCimaLetra = 'f';
    int navioDiagonalCimaNumero = 4;

/*  
    Variáveis de Posicionamento das Habilidades Especiais
    O posicionamento leva em consideração o Índice central onde ficará posicionado a Habilidade Especial
*/

    // Cone
    char coneLetra = 'h';
    int coneNumero = 5;
    
    // Cruz
    char cruzLetra = 'g';
    int cruzNumero = 9;
    
    // Octaedro
    char octaedroLetra = 'i';
    int octaedroNumero = 2;

// Criação do Tabuleiro
    
    for (int i = 0; i < LINHA; i++) // Preenchendo vetor "coluna"
        {
            coluna[i] = i + 1;
        }

    for (int i = 0; i < LINHA; i++) // Preenchendo matriz principal e gerando o Tabuleiro
    {

        for (int j = 0; j < COLUNA; j++)
            {
                tabuleiro[i][j] = 0;
            }

    }

// Correção do tipo Char e ajuste para inicio no Índex 0

    navioHorizontalLetra -= 98; navioHorizontalNumero -= 1;
    navioVerticalLetra -= 97; navioVerticalNumero -= 2;
    navioDiagonalBaixoLetra -= 98; navioDiagonalBaixoNumero -= 2;
    navioDiagonalCimaLetra -= 98; navioDiagonalCimaNumero -= 0;
    coneLetra -= 97; coneNumero -= 2;
    cruzLetra -= 97; cruzNumero -= 1;
    octaedroLetra -= 97; octaedroNumero -= 1;

    if (navioDiagonalBaixoLetra > LIMITE || navioVerticalNumero > LIMITE || navioDiagonalCimaLetra > LIMITE || navioDiagonalCimaNumero > LIMITE ||
        navioHorizontalLetra > LIMITE || navioHorizontalNumero > LIMITE || navioVerticalLetra > LIMITE || navioVerticalNumero > LIMITE)
    {
       printf("Escolha uma posição que não ultrapasse %d linhas ou colunas\n\n", LIMITE);
       
    }
    

    int navioHorizontal[2] =    {navioHorizontalNumero, navioHorizontalLetra};
    int navioVertical[2] =      {navioVerticalNumero, navioVerticalLetra};
    int navioDiagonalBaixo[2] = {navioDiagonalBaixoNumero, navioDiagonalBaixoLetra};
    int navioDiagonalCima[2] =  {navioDiagonalCimaNumero, navioDiagonalCimaLetra};


// Posicionamento dos Navios

    for (int i = 0; i < NAVIO; i++)
    {
        tabuleiro[navioVertical[0] + i][navioVertical[1]] = NAVIO;      // Navio Vertical
        tabuleiro[navioHorizontal[0]][navioHorizontal[1] + i] = NAVIO;  // Navio Horizontal
        tabuleiro[navioDiagonalCima[0] - i][navioDiagonalCima[1] + i] = NAVIO;  // Navio Diagonal/Subindo
        tabuleiro[navioDiagonalBaixo[0] + i][navioDiagonalBaixo[1] + i] = NAVIO;  // Navio Diagonal/Descendo
    }

// Posicionamento das Hibiliades especiais

    // Cone

    for (int i = 0; i < 3; i++) {
       for (int j = coneLetra - i; j <= coneLetra + i; j++) {
           if (tabuleiro[i + coneNumero][j] != 0) // Verifica se tem navio dentro do raio da habilidade
           {
            tabuleiro[i + coneNumero][j] = iHABILIDADE;
           } else {
            tabuleiro[i + coneNumero][j] = HABILIDADE;
           }
        }
    }
   

    // Cruz

    for (int i = 0; i <= 2; i++)
    {
       if (tabuleiro[cruzNumero + i - 1][cruzLetra] != 0) // Verifica se tem navio dentro do raio da habilidade
        {
        tabuleiro[cruzNumero + i - 1][cruzLetra] = iHABILIDADE;
        } else {
        tabuleiro[cruzNumero + i - 1][cruzLetra] = HABILIDADE;
        }

        for (int j = 0; j <= 4; j++){
            if (tabuleiro[cruzNumero][cruzLetra + j - 2] > 1 && tabuleiro[cruzNumero][cruzLetra + j - 2] < HABILIDADE) // Verifica se tem navio dentro do raio da habilidade
            {
            tabuleiro[cruzNumero][cruzLetra + j - 2] = iHABILIDADE;
            } else { 
            tabuleiro[cruzNumero][cruzLetra + j - 2] = HABILIDADE;
            }
        }
    }

    // Octaedro

    for (int i = 0; i <= 2; i++)
    {
        if (tabuleiro[octaedroNumero + i - 1][octaedroLetra] != 0 || 
            tabuleiro[octaedroNumero][octaedroLetra + i - 1] != 0) // Verifica se tem navio dentro do raio da habilidade
        {
            tabuleiro[octaedroNumero + i - 1][octaedroLetra] = iHABILIDADE;
            tabuleiro[octaedroNumero][octaedroLetra + i - 1] = iHABILIDADE;
        } else 
        {
            tabuleiro[octaedroNumero + i - 1][octaedroLetra] = HABILIDADE;
            tabuleiro[octaedroNumero][octaedroLetra + i - 1] = HABILIDADE;
        }
    }


// - Impressão do Tabuleiro

printf("#\t"); // Impressão do Primeiro índice da Linha

for (char i = 0; i < LINHA; i++) // Impressão da Linha 
    {
        linha[i] = 'A' + i;
        printf("%c\t", linha[i]);

    }

printf("\n"); // Quebra de linha após cabeçalho (ABC)

for (int i = 0; i < LINHA; i++)
{
    printf("%d\t", coluna[i]); // Impressão da coluna antes do tabuleiro
    
    for (int j = 0; j < COLUNA; j++)
    {
        printf("%d\t", tabuleiro[i][j]);
    }

    printf("\n");
}
    return 0;

}
