#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void embaralhartabuleiro(char tabuleiro[], int embaralhar[]);

void imprimirTabuleiro(const char tabuleiro[], const int revelado[]);

int verificarpar(const char tabuleiro[], int revelado[], int pos1, int pos2);

int jogoCompleto(const int revelado[]);

int main()
{
 char player1[50];
 char player2[50];
 char tabuleiro[16];
 int revelado[16];
 int pos1, pos2;
 time_t start, current, current2;
 double seconds1, seconds2;
 
 embaralhartabuleiro(tabuleiro, revelado);

 time(&start);

 printf("Insira o nome do player1: ");
 gets(player1);
 
 while(!jogoCompleto(revelado))
 {
  time(&current);
  imprimirTabuleiro(tabuleiro, revelado);
  
  printf("Escolha a primeira carta entre 0 e 15: ");
  scanf("%d", &pos1);
  printf("Escolha a segunda carta entre 0 e 15: ");
  scanf("%d", &pos2);
  
  if(pos1 < 0 || pos1 > 15 || pos2 < 0 || pos2 > 15 )
  {
   printf("Posicoes Invalidas. Tente Novamente");
   continue;
  }
  if(verificarpar(tabuleiro, revelado, pos1, pos2))
  {
   printf("Par encontrado!\n");
  }else{
   printf("Nao eh par. Tente novamente");
  }
 }

    seconds1 = difftime(current, start);
    printf("Parabens voce encontrou todos os pares!\n");
    printf("Seu tempo foi: %.2f segundos\n", seconds1);

    while (getchar() != '\n');

    printf("Insira o nome do player2: ");
    gets(player2);

    embaralhartabuleiro(tabuleiro, revelado);
    
    while (!jogoCompleto(revelado))
    {
      time(&current2);
      imprimirTabuleiro(tabuleiro, revelado);
  
      printf("Escolha a primeira carta entre 0 e 15: ");
      scanf("%d", &pos1);
      printf("Escolha a segunda carta entre 0 e 15: ");
      scanf("%d", &pos2);
  
      if(pos1 < 0 || pos1 > 15 || pos2 < 0 || pos2 > 15 )
      {
        printf("Posicoes Invalidas. Tente Novamente");
        continue;
      }
      if(verificarpar(tabuleiro, revelado, pos1, pos2))
      {
        printf("Par encontrado!\n");
      }else{
      printf("Nao eh par. Tente novamente");
      }   
    }
    seconds2 = difftime(current2, start);

    printf("Parabens voce encontrou todos os pares!\n");
    printf("Seu tempo foi: %.2f segundos\n", seconds2);

    if (seconds1 < seconds2)
    {
      printf("%s ganhou de %s por uma diferença de %.2f segundos", player1, player2, seconds2-seconds1);
    }else{
      printf("%s ganhou de %s por uma diferença de %.2f segundos", player2, player1, seconds1-seconds2);
    }
    
    
    return 0;
}

void embaralhartabuleiro(char tabuleiro[], int revelado[]){
 char cartas[] = {'A', 'B', 'C','D','E','F','G','H','A','B','C','D','E','F','G','H'};
 int i, j;
 char tempcarta;
 
 srand(time(0));
 
 for(i = 15 ; i > 0 ; i--)
 {
  j = rand() % (i+1);
  tempcarta = cartas[i];
  cartas[i] = cartas[j];
  cartas[j] = tempcarta;
 }
 for(i = 0 ; i < 16 ; i++)
 {
  tabuleiro[i] = cartas[i];
  revelado[i] = 0;
 }
 }
 void imprimirTabuleiro(const char tabuleiro[], const int revelado[]){
  int i;
  for(i=0 ; i<16 ; i++)
  {
   if(i % 4 == 0)
    printf("\n");
    
    if(revelado[i]){
    printf("%c ", tabuleiro[i]);
  }else{
  printf("* ");
  }
 }
printf("\n");
}
int verificarpar(const char tabuleiro[], int revelado[], int pos1, int pos2){
 if(tabuleiro[pos1] == tabuleiro[pos2]){
  revelado[pos1] = 1;
  revelado[pos2] = 1;
  
  return 1;
 }
 return 0;
}
int jogoCompleto(const int revelado[]){
 int i;
  for(i=0 ; i < 16 ; i++)
  {
   if(!revelado[i])
    return 0;
  }
  return 1;
}