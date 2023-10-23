#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "");
    
    float valorInvestido = 0;
    int periodo = 0;
    float percentualRendimento = 0;
    
    printf("Digite o valor investido\n");
    scanf("%f", &valorInvestido);
    printf("Digite o quantidade de meses do investimento\n");
    scanf("%d", &periodo);
    printf("Digite o percentual de rendimento ao mês\n");
    scanf("%f", &percentualRendimento);
    
    float imposto = 15;
    float rendimento;
    float rendimentoBruto;
    float rendimentoLiquido;
    float potencia = 1.0;

    printf("\nR$%.2f investidos\nPeríodo %d meses\n%% Rendimento/Mês %.0f%%\n\n", valorInvestido, periodo, percentualRendimento);

    for (int i = 1; i < periodo; ++i) {
        potencia *= (1 + percentualRendimento / 100);
        rendimentoBruto = valorInvestido * potencia;
        printf("Depois do mês %d terá %.2f\n", i, rendimentoBruto);
    }
    
    rendimento = rendimentoBruto - valorInvestido;
    rendimento = rendimento - (rendimento * (imposto/100));
    rendimentoLiquido = valorInvestido + rendimento;

    printf("\nValor Saldo Final = %.2f\n\nApós o rendimento é necessário pagar 15%% de imposto sobre o lucro do investimento no ato do saque, ficando assim:\n\nValor Saldo Final - Imposto Retido na Fonte = R$%.2f\n\n", rendimentoBruto, rendimentoLiquido);
}


