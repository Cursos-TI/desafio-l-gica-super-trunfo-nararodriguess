#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char estado[10];        
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int nPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Cidade;

void distribuirCartas(int cartas[3]) {
    for (int i = 0; i < 3; i++) {
        int jaExiste;
        int sorteado;

        do {
            jaExiste = 0;
            sorteado = rand() % 6;

            for (int j = 0; j < i; j++) { // verifica se cartas ja foi preenchido ou o valor em cartas foi repetido
                if (cartas[j] == sorteado) {
                    jaExiste = 1;
                }
            }
        } while (jaExiste);

        cartas[i]= sorteado;
    }
}

void escolherCartasAtributos(int *atributo, int *cartaJogador, int *cartaComputador) {
    int vez = rand() % 2;

    if (vez == 1){
        printf("\nVocê começa!\n");
        printf("\nEscolha um atributo para competir (Populacao = 1 | Area = 2 | PIB = 3 | Qtd Pontos Turísticos = 4 | Densidade Populacional = 5| PIB per Capita= 6): ");
        scanf("%d", atributo);
        printf("Agora escolha uma carta para competir (Digite 1, 2 ou 3): ");
        scanf("%d", cartaJogador);
        *cartaComputador = rand() % 3;
    } else {
        printf("\nComputador começa!\n");
        *atributo = rand() % 6;
        *cartaComputador = rand() % 3;
        printf("\nEscolha uma carta para competir (Digite 1, 2 ou 3): ");
        scanf("%d", cartaJogador);

    }
   
}

void compararCartas(Cidade cidades[6], int cidadeJogador, int cidadeComputador, int atributo ) {
    switch (atributo) {
        case 1:
            printf("\n-----  Atributo: População  -----\n");
            printf("Sua carta (%s): %d\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].populacao);
            printf("Computador (%s): %d\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].populacao);
            if (cidades[cidadeJogador].populacao > cidades[cidadeComputador].populacao) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].populacao == cidades[cidadeComputador].populacao){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
        case 2:
            printf("\n-----  Atributo: Área  -----\n");
            printf("Sua carta (%s): %.2f\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].area);
            printf("Computador (%s): %.2f\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].area);
            if (cidades[cidadeJogador].area > cidades[cidadeComputador].area) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].area == cidades[cidadeComputador].area){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
        case 3:
            printf("\n-----  Atributo: PIB  -----\n");
            printf("Sua carta (%s): %.2f\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].pib);
            printf("Computador (%s): %.2f\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].pib);
            if (cidades[cidadeJogador].pib > cidades[cidadeComputador].pib) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].pib == cidades[cidadeComputador].pib){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
        case 4:
            printf("\n-----  Atributo: Quantidade de Pontos Turísticos  -----\n");
            printf("Sua carta (%s): %d\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].nPontosTuristicos);
            printf("Computador (%s): %d\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].nPontosTuristicos);
            if (cidades[cidadeJogador].nPontosTuristicos > cidades[cidadeComputador].nPontosTuristicos) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].nPontosTuristicos == cidades[cidadeComputador].nPontosTuristicos){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
        case 5:
            printf("\n-----  Atributo: Densidade Populacional  -----\n");
            printf("Sua carta (%s): %.2f\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].densidadePopulacional);
            printf("Computador (%s): %.2f\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].densidadePopulacional);
            if (cidades[cidadeJogador].densidadePopulacional < cidades[cidadeComputador].densidadePopulacional) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].densidadePopulacional == cidades[cidadeComputador].densidadePopulacional){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
        case 6:
            printf("\n-----  Atributo: PIP per Capita  -----\n");
            printf("Sua carta (%s): %.2f\n", cidades[cidadeJogador].nomeCidade, cidades[cidadeJogador].pibPerCapita);
            printf("Computador (%s): %.2f\n", cidades[cidadeComputador].nomeCidade, cidades[cidadeComputador].pibPerCapita);
            if (cidades[cidadeJogador].pibPerCapita > cidades[cidadeComputador].pibPerCapita) {
                printf("\nParabéns, você venceu!\n");
            } else if (cidades[cidadeJogador].pibPerCapita == cidades[cidadeComputador].pibPerCapita){
                printf("\nEmbate!\n");
            } else { 
                printf("\nVocê perdeu :( Game over!\n");
            }
            break;
    }
}

int main() {
    Cidade cidades[6] = {
        {"SP", "São Paulo", 12300000, 1521.11, 699000000, 100},
        {"RJ", "Rio de Janeiro", 6200000, 1200, 360000000, 100},
        {"MG", "Belo Horizonte", 2300000, 331, 105000000, 60},
        {"PR", "Curitiba", 1900000, 435, 98000000, 50},
        {"BA", "Salvador", 22400000, 693, 80000000, 80},
        {"CE", "Fortaleza", 2700000, 315, 73000000, 60},

    };
  
    // Calcula densidade populacional e PIB per Capita
    for (int i = 0; i <6; i++) {
        cidades[i].densidadePopulacional = (float)cidades[i].populacao / cidades[i].area;
        cidades[i].pibPerCapita = (float)cidades[i].pib / cidades[i].populacao;
    }

    int cartasJogador[3];
    int cartasComputador[3];

    srand(time(NULL));

    distribuirCartas(cartasJogador);
    distribuirCartas(cartasComputador);

    printf("Suas cartas : \n");
    for (int i = 0; i < 3; i++) {
        printf("Carta: %d | Estado: %s | Cidade: %s | Populacao: %d | Área: %.2f | PIB: %.2f | Qtd Pontos Turísticos: %d | Densidade Populacional: %.2f | PIB per Capita: %.2f \n",
        i + 1,
        cidades[cartasJogador[i]].estado,
        cidades[cartasJogador[i]].nomeCidade,
        cidades[cartasJogador[i]].populacao,
        cidades[cartasJogador[i]].area,
        cidades[cartasJogador[i]].pib,
        cidades[cartasJogador[i]].nPontosTuristicos,
        cidades[cartasJogador[i]].densidadePopulacional,
        cidades[cartasJogador[i]].pibPerCapita
        );
    }

    int atributo, indiceCartaJogador, indiceCartaComputador;
    escolherCartasAtributos(&atributo, &indiceCartaJogador, &indiceCartaComputador);    

    int cidadeJogador = cartasJogador[indiceCartaJogador - 1];
    int cidadeComputador = cartasComputador[indiceCartaComputador - 1];

    compararCartas(cidades, cidadeJogador, cidadeComputador, atributo);

    return 0;
}