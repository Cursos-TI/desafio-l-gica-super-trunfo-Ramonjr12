#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

float calcularDensidadePopulacional(struct Carta c) {
    return (float)c.populacao / c.area;  // Corrigido para divisão float
}

float calcularPIBPerCapita(struct Carta c) {
    return (c.pib * 1e9) / c.populacao;
}

void exibirCarta(struct Carta c) {
    printf("========== Carta ==========\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", calcularDensidadePopulacional(c));
    printf("PIB per capita: R$ %.2f\n\n", calcularPIBPerCapita(c));
}

int main() {
    struct Carta carta1 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 45};
    struct Carta carta2 = {"BA", "C03", "Salvador", 2886698, 693.83, 63.20, 30};

    exibirCarta(carta1);
    exibirCarta(carta2);

    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao);

    printf("\n");

    switch (opcao) {
        case 1:
            printf("Comparação: População\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %d\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Comparação: Área\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Comparação: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: {
            float dens1 = calcularDensidadePopulacional(carta1);
            float dens2 = calcularDensidadePopulacional(carta2);
            printf("Comparação: Densidade Populacional\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, dens1);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, dens2);
            if (dens1 < dens2)
                printf("Resultado: %s venceu! (menor densidade)\n", carta1.nomeCidade);
            else if (dens2 < dens1)
                printf("Resultado: %s venceu! (menor densidade)\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;
        }

        case 5: {
            float perCapita1 = calcularPIBPerCapita(carta1);
            float perCapita2 = calcularPIBPerCapita(carta2);
            printf("Comparação: PIB per capita\n");
            printf("%s: R$ %.2f\n", carta1.nomeCidade, perCapita1);
            printf("%s: R$ %.2f\n", carta2.nomeCidade, perCapita2);
            if (perCapita1 > perCapita2)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (perCapita2 > perCapita1)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;
        }

        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
