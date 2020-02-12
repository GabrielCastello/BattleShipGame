//Batalha Naval versão 1.0 (somente com submarinos): Jogo para 2 usuários.
//Faça um programa para mapear uma matriz de 10x10 pontos de um mapa marítimo.
//Um usuário terá que informar a posição de cada um dos 10 submarinos (linha e coluna).
//O programa deve apagar a tela e perguntar 10 referências no mapa (linha e coluna) ao segundo jogador.
//Ao final, o programa deve imprimir a matriz 10x10 contendo as posições dos submarinos, onde indiquem se o submarino foi atingido ou não,
//bem como os “tiros” que não encontraram seu alvo.
//Deve também informar a quantidade de submarinos atingidos.
//Obs.: a marcação no mapa, a formatação das entradas e dos resultados devem ser objeto de um design proposto pelo programador,
//ou seja, faça da melhor maneira para que o jogo fique bem legal.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[10][10], player1Shots[10][10], player2Shots[10][10], mapSize = 10, submarinesQty = 10, shotsQty = 10;

void clrscr()
{
  /* 
  * Limpa a tela 
  */
  // puts("\e[1;1H\e[2J"); - Funciona apenas no Unix
  system("@cls||clear");
}

void clrMap()
{
  /* 
  * Limpa o mapa e as tentativas dos players 1 e 2
  */
  for (int line = 0; line < mapSize; line++)
  {
    for (int column = 0; column < mapSize; column++)
    {
      map[line][column] = 0;
      player1Shots[line][column] = 0;
      player2Shots[line][column] = 0;
    }
  }
}

void setSubmarines()
{
  /* 
  * Define a posição dos submarinos 
  */
  for (int i = 0; i < submarinesQty; i++)
  {
    int line, column;
    printf("Informe a linha do %i submarino(0-9): ", i);
    scanf(" %i", &line);
    printf("Informe a coluna do %i submarino(0-9): ", i);
    scanf(" %i", &column);
    map[line][column] = 1;
  }
}

void setPlayerShots(player)
{
  /* 
  * Registra as tentativas do jogador
  */
  printf("\nBem-vindo jogador %i, você terá direito a %i tentativas de achar os %i submarinos, bom jogo!\n", player, shotsQty, submarinesQty);
  switch (player)
  {
  case 1:
    for (int i = 0; i < shotsQty; i++)
    {
      int line, column;
      printf("Informe a linha do tiro %i(0-9): ", i);
      scanf(" %i", &line);
      printf("Informe a coluna do tiro %i(0-9): ", i);
      scanf(" %i", &column);
      player1Shots[line][column] = 1;
    }
    break;
  case 2:
    for (int i = 0; i < shotsQty; i++)
    {
      int line, column;
      printf("Informe a linha do tiro %i(0-9): ", i);
      scanf(" %i", &line);
      printf("Informe a coluna do tiro %i(0-9): ", i);
      scanf(" %i", &column);
      player2Shots[line][column] = 1;
    }
    break;
  default:
    break;
  }
}

void showPlayerShots(player)
{
  /* 
  * Exibie no mapa os tiros do jogador 
  */
  char submarine[] = "s", hittedSubmarine[] = "d", missedShot[] = "x", empty[] = "_";
  printf("\nO jogador %i, realizou os seguintes disparos: \n\n", player);
  for (int line = 0; line < mapSize; line++)
  {
    if (line == 0)
    {
      for (int i = 0; i <= mapSize; i++)
      {
        i == 0 ? printf("   ") : printf(" %i ", i - 1);
      }
      printf("\n\n");
    }
    for (int column = 0; column < mapSize; column++)
    {
      if (column == 0)
        printf("%i  ", line);
      switch (player)
      {
      case 1:
        if (player1Shots[line][column] == 1 && map[line][column] == 1)
        {
          printf(" %s ", hittedSubmarine);
        }
        else if (player1Shots[line][column] == 1 && map[line][column] == 0)
        {
          printf(" %s ", missedShot);
        }
        else if (player1Shots[line][column] == 0 && map[line][column] == 1)
        {
          printf(" %s ", submarine);
        }
        else
        {
          printf(" %s ", empty);
        }
        break;
      case 2:
        if (player2Shots[line][column] == 1 && map[line][column] == 1)
        {
          printf(" %s ", hittedSubmarine);
        }
        else if (player2Shots[line][column] == 1 && map[line][column] == 0)
        {
          printf(" %s ", missedShot);
        }
        else if (player2Shots[line][column] == 0 && map[line][column] == 1)
        {
          printf(" %s ", submarine);
        }
        else
        {
          printf(" %s ", empty);
        }
        break;
      default:
        break;
      }
    }
    printf("\n");
  }
  printf("\nLegenda:  d: Submarino Destruído; s: Submarino Intacto; x:Tiro em Coordenada Vazia; _:Coordenada Vazia\n");
}

void showMap()
{
  /* 
  * Exibie no mapa os submarinos  
  */
  printf("\nO mapa ficou configurado da seguinte forma:\n");
  for (int line = 0; line < mapSize; line++)
  {
    if (line == 0)
    {
      for (int i = 0; i <= mapSize; i++)
      {
        i == 0 ? printf("   ") : printf(" %i ", i - 1);
      }
      printf("\n\n");
    }

    for (int column = 0; column < mapSize; column++)
    {
      if (column == 0)
        printf("%i  ", line);
      printf(" %i ", map[line][column]);
    }
    printf("\n");
  }

  getchar();
  printf("\nPressione enter para iniciar o jogo...");
  int enter = 0;
  while (enter != '\r' && enter != '\n')
  {
    enter = getchar();
  }
}

void checkShots(player)
{
  int missedShots = 0, hits = 0;
  for (int line = 0; line < mapSize; line++)
  {
    for (int column = 0; column < mapSize; column++)
    {
      switch (player)
      {
      case 1:
        if (map[line][column] == 1 && player1Shots[line][column] == 1)
        {
          printf("\nO Jogador %i acertou o submarino localizado na coluna %i, linha %i", player, column, line);
          hits++;
        }
        else if (map[line][column] == 0 && player1Shots[line][column] == 1)
        {
          printf("\nO Jogador %i errou o tiro na coluna %i, linha %i", player, column, line);
          missedShots++;
        }

        {
        }

        break;
      case 2:
        if (map[line][column] == 1 && player2Shots[line][column] == 1)
        {
          printf("\nO Jogador %i acertou o submarino localizado na coluna %i, linha %i", player, column, line);
          hits++;
        }
        else if (map[line][column] == 0 && player2Shots[line][column] == 1)
        {
          printf("\nO Jogador %i errou o tiro na coluna %i, linha %i", player, column, line);
          missedShots++;
        }
        break;
      default:
        break;
      }
    }
  }
  printf("\nQuantidade de acertos do Jogador %i: %i", player, hits);
  printf("\nQuantidade de erros do Jogador %i: %i\n", player, missedShots);
}

int main(void)
{
  clrMap();
  setSubmarines();
  showMap();
  clrscr();
  setPlayerShots(2);
  showPlayerShots(2);
  checkShots(2);
  system("pause");
  return 0;
}
