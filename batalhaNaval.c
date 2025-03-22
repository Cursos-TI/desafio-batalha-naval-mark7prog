#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com água (0)

  // Posiciona o navio horizontalmente
  int navio_horizontal_linha = 2;
  int navio_horizontal_coluna = 3;
  for (int i = 0; i < TAMANHO_NAVIO; i++) {
    tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3; // 3 representa o navio
  }

  // Posiciona o navio verticalmente
  int navio_vertical_linha = 6;
  int navio_vertical_coluna = 1;
  for (int i = 0; i < TAMANHO_NAVIO; i++) {
    tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3; // 3 representa o navio
  }

  // Exibe o tabuleiro
  printf("Tabuleiro do Batalha Naval:\n");
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}