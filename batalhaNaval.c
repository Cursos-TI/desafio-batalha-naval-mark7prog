#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

void posiciona_navio_horizontal(int linha, int coluna) {
  if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[linha][coluna + i] = 3;
    }
  }
}

void posiciona_navio_vertical(int linha, int coluna) {
  if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[linha + i][coluna] = 3;
    }
  }
}

void aplica_habilidade_cone(int linha, int coluna) {
  int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = TAMANHO_HABILIDADE / 2 - i; j <= TAMANHO_HABILIDADE / 2 + i; j++) {
      if (j >= 0 && j < TAMANHO_HABILIDADE) {
        habilidade[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      int tabuleiro_linha = linha + i - TAMANHO_HABILIDADE / 2;
      int tabuleiro_coluna = coluna + j - TAMANHO_HABILIDADE / 2;
      if (habilidade[i][j] == 1 && tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
      }
    }
  }
}

void aplica_habilidade_cruz(int linha, int coluna) {
  int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    habilidade[TAMANHO_HABILIDADE / 2][i] = 1;
    habilidade[i][TAMANHO_HABILIDADE / 2] = 1;
  }

  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      int tabuleiro_linha = linha + i - TAMANHO_HABILIDADE / 2;
      int tabuleiro_coluna = coluna + j - TAMANHO_HABILIDADE / 2;
      if (habilidade[i][j] == 1 && tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
      }
    }
  }
}

void aplica_habilidade_octaedro(int linha, int coluna) {
  int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
        habilidade[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      int tabuleiro_linha = linha + i - TAMANHO_HABILIDADE / 2;
      int tabuleiro_coluna = coluna + j - TAMANHO_HABILIDADE / 2;
      if (habilidade[i][j] == 1 && tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
      }
    }
  }
}

int main() {
  posiciona_navio_horizontal(2, 3);
  posiciona_navio_vertical(6, 1);

  aplica_habilidade_cone(4, 4);
  aplica_habilidade_cruz(7, 7);
  aplica_habilidade_octaedro(1, 1);

  printf("Tabuleiro do Batalha Naval:\n");
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}