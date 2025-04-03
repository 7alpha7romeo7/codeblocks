#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fração
typedef struct {
    int num;
    int den;
} Racional;

// Função para calcular o MDC (Máximo Divisor Comum) - Usado para simplificar frações
int calcular_mdc(int a, int b) {
    if (b == 0)
        return a;
    return calcular_mdc(b, a % b);
}

// Função para simplificar a fração
Racional simplificar(Racional r) {
    int divisor = calcular_mdc(r.num, r.den);
    r.num /= divisor;
    r.den /= divisor;
    if (r.den < 0) { // Garante que o denominador sempre seja positivo
        r.num = -r.num;
        r.den = -r.den;
    }
    return r;
}

// Função para somar duas frações
Racional somar(Racional r1, Racional r2) {
    Racional resultado;
    resultado.num = r1.num * r2.den + r2.num * r1.den;
    resultado.den = r1.den * r2.den;
    return simplificar(resultado);
}

// Função para subtrair duas frações
Racional subtrair(Racional r1, Racional r2) {
    Racional resultado;
    resultado.num = r1.num * r2.den - r2.num * r1.den;
    resultado.den = r1.den * r2.den;
    return simplificar(resultado);
}

// Função para multiplicar duas frações
Racional multiplicar(Racional r1, Racional r2) {
    Racional resultado;
    resultado.num = r1.num * r2.num;
    resultado.den = r1.den * r2.den;
    return simplificar(resultado);
}

// Função para dividir duas frações
Racional dividir(Racional r1, Racional r2) {
    Racional resultado;
    resultado.num = r1.num * r2.den;
    resultado.den = r1.den * r2.num;
    return simplificar(resultado);
}

// Função principal (main)
int main() {
    Racional r1, r2, resultado;
    char operador;

    // Entrada do usuário
    printf("Digite o primeiro numerador e denominador: ");
    scanf("%d %d", &r1.num, &r1.den);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operador);
    printf("Digite o segundo numerador e denominador: ");
    scanf("%d %d", &r2.num, &r2.den);

    // Verifica e executa a operação desejada
    switch (operador) {
        case '+':
            resultado = somar(r1, r2);
            break;
        case '-':
            resultado = subtrair(r1, r2);
            break;
        case '*':
            resultado = multiplicar(r1, r2);
            break;
        case '/':
            if (r2.num == 0) {
                printf("Erro: Divisão por zero não é permitida!\n");
                return 1;
            }
            resultado = dividir(r1, r2);
            break;
        default:
            printf("Operação inválida!\n");
            return 1;
    }

    // Exibe o resultado simplificado
    printf("Resultado: %d/%d\n", resultado.num, resultado.den);
    return 0;
}
