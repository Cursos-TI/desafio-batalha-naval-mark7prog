#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com água (0)

  // Posiciona o primeiro navio horizontalmente
  int navio_horizontal_linha = 2;
  int navio_horizontal_coluna = 3;
  if (navio_horizontal_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
    }
  }

  // Posiciona o segundo navio verticalmente
  int navio_vertical_linha = 6;
  int navio_vertical_coluna = 1;
  if (navio_vertical_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
    }
  }

  // Posiciona o primeiro navio diagonal (principal)
  int navio_diagonal1_linha = 0;
  int navio_diagonal1_coluna = 0;
  if (navio_diagonal1_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navio_diagonal1_linha + i][navio_diagonal1_coluna + i] = 3;
    }
  }

  // Posiciona o segundo navio diagonal (secundária)
  int navio_diagonal2_linha = 0;
  int navio_diagonal2_coluna = 9;
  if (navio_diagonal2_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navio_diagonal2_linha + i][navio_diagonal2_coluna - i] = 3;
    }
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