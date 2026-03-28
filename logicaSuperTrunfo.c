#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct {
    char estado[10];        
    char codCarta[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int nPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Cidade;

// Remove o \n do final de uma linha inserida no prompt
void lerLinha(char *buffer, int tamanho) {
    fgets(buffer, tamanho, stdin);
    int i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0') i++;
    buffer[i] = '\0';
}

// Lê os atributos de uma cidade
void lerCidade(Cidade *c) {
    char buffer[100];

    printf("Estado: ");
    lerLinha(c->estado, sizeof(c->estado));

    printf("Num. da Carta: ");
    lerLinha(c->codCarta, sizeof(c->codCarta));

    printf("Nome da cidade: ");
    lerLinha(c->nomeCidade, sizeof(c->nomeCidade));

    printf("Populacao: ");
    lerLinha(buffer, sizeof(buffer)); // salva em uma variável provisória para converter
    c->populacao = atoi(buffer);   // converte string para int

    printf("Area: ");
    lerLinha(buffer, sizeof(buffer));
    c->area = atof(buffer);        // converte string para float

    printf("PIB: ");
    lerLinha(buffer, sizeof(buffer));
    c->pib = atof(buffer);

    printf("Qtd de pontos turisticos: ");
    lerLinha(buffer, sizeof(buffer));
    c->nPontosTuristicos = atoi(buffer);

    if (c->area > 0 || c->populacao > 0) {
        c->densidadePopulacional =  (float)c->populacao / c->area;
        c->pibPerCapita =  (float)c->pib / c->populacao;
    } else {
        c->densidadePopulacional = 0;
        c->pibPerCapita = 0;
    }
}

void compararCidades(Cidade c1, Cidade c2) {
    char *atributos[] = {
        "Populacao", "Area", "PIB",
        "Pontos Turisticos", "Densidade Populacional", "PIB per Capita"
    };

    float valoresC1[] = {
        c1.populacao, c1.area, c1.pib,
        c1.nPontosTuristicos, c1.densidadePopulacional, c1.pibPerCapita
    };

    float valoresC2[] = {
        c2.populacao, c2.area, c2.pib,
        c2.nPontosTuristicos, c2.densidadePopulacional, c2.pibPerCapita
    };

    srand(time(NULL));
    int sorteado = rand() % 6;

    printf("\n=== Atributo sorteado: %s ===\n", atributos[sorteado]);
    printf("%s: %.2f\n", c1.nomeCidade, valoresC1[sorteado]);
    printf("%s: %.2f\n", c2.nomeCidade, valoresC2[sorteado]);

    if (valoresC1[sorteado] > valoresC2[sorteado]) {
        printf("Vencedor: %s!\n", c1.nomeCidade);
    } else if (valoresC2[sorteado] > valoresC1[sorteado]) {
        printf("Vencedor: %s!\n", c2.nomeCidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    int opcao;
    Cidade cidade1, cidade2;

    do {
        printf("Menu Principal\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Iniciando o jogo...\n");

            printf("=== Cidade 1 ===\n");
            lerCidade(&cidade1);

            printf("\n=== Cidade 2 ===\n");
            lerCidade(&cidade2);

            compararCidades(cidade1, cidade2);
            break;
        case 2:
            printf("Regras do Jogo:\n");
            printf("1. O jogo é em dupla\n");
            printf("2. Só é permitido inserir dados de duas cidades\n");
            printf("3. Inserir dados errados encerra o jogo\n");
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}