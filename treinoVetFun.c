#include <stdio.h>
#include <locale.h>
#define ex10

//Utilize em todos os exercícios: vetores (como variáveis globais) e funções com passagens de parâmetros e retorno de valores.
// As demais variáveis deverão ser locais às funções.


/*Exercício 1 - Receba doze números positivos e armazene no vetor A. Após a alimentação de todos os números mostre
apenas os números maiores que 121 que estão armazenados no vetor.*/
#ifdef ex01
int A[12];

void alimentacao(int n);
int maiores(int n);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int k, count;

    printf("Digite 12 numeros\n");
    alimentacao(k);
    count = maiores(k);

    printf("Os números maiores que 121 são: ");
    for(k=0;k<count;k++)
    {
        printf("%d ", A[k]);
    }
}

void alimentacao(int n)
{
    for(n=0;n<12;n++)
    {
        scanf("%d", &A[n]);
        while(A[n]<0)
        {
            printf("O numero deve ser positivo\n");
            scanf("%d", &A[n]);
        }
    }

}

int maiores(int n)
{
    int c = 0;
    for(n=0;n<12;n++)
    {
        if(A[n]>121)
        {
            A[c] = A[n];
            c++;
        }
    }
    return c;
}
#endif // ex01

#ifdef ex02
/*Leia oito elementos e armazene-os no vetor A. Construa o vetor B de mesma dimensão com os elementos do vetor A multiplicados
por 3. Apresente o conteúdo dos dois vetores.*/
int A[8];

void alimentacao(int* n);
int* multiplicacao(int* n);

//Eu gostaria de treinar um pouco de ponteiros :)

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int k;

    printf("Digite oito numeros para fazer a multiplicação\n");
    alimentacao(&k);
    int* B = multiplicacao(&k);

    printf("\nAqui estão os elementos de A que foram digitados: ");
    for(k=0;k<8;k++)
    {
        printf("%d ", A[k]);
    }

    printf("\nAqui estão elementos de A multiplicados por 3: ");
    for(k=0;k<8;k++)
    {
        printf("%d ", B[k]);
    }

}

void alimentacao(int* n)
{
    for(*n=0;*n<8;(*n)++)
    {
        scanf("%d", &A[*n]);
        while(A[*n]<0)
        {
            printf("O numero deve ser positivo\n");
            scanf("%d", &A[*n]);
        }
    }

}

int* multiplicacao(int* n)
{
    static int vetor[8];

    for(*n=0;*n<8;(*n)++)
    {
        vetor[*n] = A[*n] * 3;
    }
    return vetor;
}
#endif // ex02

#ifdef ex03
/*Faça um programa que armazene num vetor 6 números negativos. Calcule a soma dos seus quadrados; se a soma for
inferior a 1000 solicite novos dados. Mostre somente a soma que satisfaz a condição.*/

int A[6];

void alimentacao(int n);
int* exp(int *n);
int soma(int *e, int s);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int k=0;

    printf("Digite 6 números negativos\n");
    alimentacao(k);
    return 0;
}

void alimentacao(int n)
{
    int t=0, sum=0;
    while(sum<1000)
    {
        for(n=0;n<6;(n)++)
        {
            scanf("%d", &A[n]);
            while(A[n]>0)
            {
            printf("O numero deve ser negativo\n");
            scanf("%d", &A[n]);
            }
        }
        int* E = exp(&n);
        sum = soma(E, t);
        if(sum<1000)
        {
            printf("A soma dos quadrados não chegaram em 1000, mande novos dados\n");
        }
    }
    printf("A soma dos quadrados destes números negativos é %d", sum);
}

int* exp(int *n)
{
    static int quadrado[6];
    for(*n=0;*n<6;(*n)++)
        {
            quadrado[*n] = A[*n] * A[*n];
        }
    return quadrado;
}

int soma(int *e, int s)
{
    for(int i=0;i<6;i++)
    {
        s = e[i] + s;
    }
    return s;
}
#endif // ex03

#ifdef ex04
/*Armazene num vetor dez números positivos. Exiba o conteúdo do vetor. Mostre o maior número, quantas vezes ele foi
digitado e em que posições ele apareceu dentro do vetor.*/

int A[10];

void alimentacao(int n);
int MaiorPos(int n);
int quant(int n, int m);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int k, maior, cont;
    printf("Digite 10 numeros positivos\n");
    alimentacao(k);
    maior = MaiorPos(k);
    cont = quant(k, maior);
    printf("Sendo o maior número, o %d que foi digitado %d vezes", maior, cont);
    return 0;
}

int MaiorPos(int n)
{
    int m=0, p;
    for(n=0;n<10;n++)
    {
        if(m<A[n])
        {
            m = A[n];
            p = n;
        }
    }
    printf("O maior número está no índice %d\n", p);
    return m;
}

int quant(int n, int m)
{
    int v=0;
    for(n=0;n<10;n++)
    {
        if(A[n]==m)
        {
           v++;
        }
    }
    return v;
}

void alimentacao(int n)
{
    for(n=0;n<10;n++)
    {
        scanf("%d", &A[n]);
        while(A[n]<0)
        {
            printf("O numero deve ser positivo\n");
            scanf("%d", &A[n]);
        }
    }

}
#endif // ex04

#ifdef ex05
/*Armazene no vetor A 10 elementos positivos. Construa o vetor B do mesmo tipo e dimensão. Cada elemento do vetor B deve ser o
valor negativo do elemento correspondente do vetor A. Desta forma, se em A [1] estiver armazenado o elemento 8 deve estar em
B [1] o valor –8, e assim por diante. Apresentar o conteúdo dos dois vetores*/

int A[10];

void alimentacao(int n);
int* negativo(int n);
void vetA(int n);
void vetB(int n, int *b);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int k;

    printf("Digite 10 números:\n");
    alimentacao(k);
    int* B = negativo(k);

    printf("Estes são os números digitados: ");
    vetA(k);
    printf("\nEstes são os números inversos: ");
    vetB(k, B);
}

int* negativo(int n)
{
    static int N[10];
    for(n=0;n<10;n++)
    {
        N[n] = A[n] * (-1);
    }
    return N;
}

void alimentacao(int n)
{
    for(n=0;n<10;n++)
    {
        scanf("%d", &A[n]);
        while(A[n]<0)
        {
            printf("O numero deve ser positivo\n");
            scanf("%d", &A[n]);
        }
    }

}

void vetA(int n)
{
    for(n=0;n<10;n++)
    {
        printf("%d ", A[n]);
    }
}

void vetB(int n, int *b)
{
    for(n=0;n<10;n++)
    {
        printf("%d ", b[n]);
    }
}
#endif // ex05

#ifdef ex06
/*Crie a função Divisão que receba da função main dois números que possibilitem o cálculo da divisão do primeiro
pelo segundo. Exiba na função main os números e o resultado obtido na função Divisão.*/

float A[2];
void alimentacao();
float Divisao(float r);

float main()
{
    float d;
    setlocale(LC_ALL, "Portuguese");
    alimentacao();
    float div = Divisao(d);
    printf("A divisão é %.2f", div);

    return 0;
}

void alimentacao()
{
    printf("Digite um numerador\n");
    scanf("%f", &A[0]);
    printf("\nAgora um denominador\n");
    scanf("%f", &A[1]);
}

float Divisao(float r)
{
    r = A[0]/A[1];
    return r;
}
#endif // ex06

#ifdef ex07
/*Crie a função ParImpar que receba da função main, valores do tipo inteiro e maior que zero que verifique se o número
 é par ou ímpar. Exiba no interior da função Parimpar*/

 int A[10];
 int verificacao();
 void alimentacao(tamanho);
 void ParImpar(tamanho);

 int main()
 {
     setlocale(LC_ALL, "Portuguese");
     printf("Quantos números deseja verificar? (Deve ser de 1 a 10)\n");
     int tamanho = verificacao();
     printf("Quais seriam esses números?\n");
     alimentacao(tamanho);
     ParImpar(tamanho);
     return 0;
 }

 int verificacao()
 {
     int tam;
     scanf("%d", &tam);
     while(tam>10 || tam<1)
     {
         printf("Valor inválido, tente novamente\n");
         scanf("%d", &tam);
     }
     return tam;
 }

 void alimentacao(int n)
{
    int k;
    for(k=0;k<n;k++)
    {
        scanf("%d", &A[k]);
        while(A[k]<0)
        {
            printf("O numero deve ser positivo\n");
            scanf("%d", &A[k]);
        }
    }

}

void ParImpar(int n)
{
    int k;
    for(k=0;k<n;k++)
    {
        if(A[k] % 2 == 0)
        {
            printf("\nO número %d é par", A[k]);
        }
        else
        {
            printf("\nO número %d é ímpar", A[k]);
        }
    }
}
#endif // ex07

#ifdef ex08
/*Leia quatro valores referentes às notas escolares de um aluno e exiba uma mensagem dizendo que ele foi aprovado
se a média for maior ou igual a 6. Caso contrário informe que ele está reprovado. Apresente junto à mensagem o valor
da média obtida pelo aluno independente de ter sido aprovado ou não. As notas deverão ser maiores ou iguais a zero e
menores ou iguais a dez.*/

float A[4];
void alimentacao();
float calculo();
void med(float t);

float main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Coloque as quatro notas do aluno\n");
    alimentacao();
    float total = calculo();
    med(total);
    return 0;
}

void alimentacao()
{
    int k;
    for(k=0;k<4;k++)
    {
        scanf("%f", &A[k]);
        while(A[k]<0 || A[k]>10)
        {
            printf("Nota inválida, tente outra\n");
            scanf("%f", &A[k]);
        }
    }
}

float calculo()
{
    float t;
    t = (A[0]+A[1]+A[2]+A[3])/4;
    return t;
}

void med(float t)
{
    if(t>=6.0)
    {
        printf("O aluno está aprovado com a nota %.2f", t);
    }
    else{
        printf("O aluno está reprovado com a nota %.2f", t);
    }
}
#endif // ex08

#ifdef ex09
/*Receba dois números, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser maior ou igual a zero,
o terceiro deve ser a soma dos dois primeiros e o quarto é o produto dos três números anteriores. Calcule e exiba a
soma dos quadrados dos quatro números.*/
int A[4];

void alimentacao();
void quadrado(int n);
int sum(int n);

int main()
{
    int k;
    setlocale(LC_ALL, "Portuguese");
    alimentacao();
    quadrado(k);
    int soma = sum(k);
    printf("O resultado da soma dos quadrados desses números deu: %d", soma);
    return 0;
}

void alimentacao()
{
    printf("Digite um número entre 10 e 25\n");
    scanf("%d", &A[0]);
    while(10>=A[0] || 25<=A[0])
    {
        printf("Valor inválido, tente outro:\n");
        scanf("%d", &A[0]);
    }
    printf("Digite um número que seja maior ou igual a 0:\n");
    scanf("%d", &A[1]);
    while(A[1]<0)
    {
        printf("Valor inválido, tente outro:\n");
        scanf("%d", &A[1]);
    }
    printf("Digite um número que seja a soma dos 2 primeiros números:\n");
    scanf("%d", &A[2]);
    while(A[2] != (A[1]+A[0]))
    {
        printf("Valor inválido, tente outro:\n");
        scanf("%d", &A[1]);
    }
    printf("Digite um número que seja o produto dos 3 anteriores:\n");
    scanf("%d", &A[3]);
    while(A[3] != (A[1]*A[2]*A[0]))
    {
        printf("Valor inválido, tente outro:\n");
        scanf("%d", &A[1]);
    }
}

void quadrado(int n)
{
    for(n=0;n<4;n++)
    {
        A[n] = (A[n]*A[n]);
    }
}

int sum(int n)
{
    int s;
    for(n=0;n<4;n++)
    {
        s = (A[n]+s);
    }
    return s;
}
#endif // ex09

#ifdef ex10
/*Leia cinco números inteiros e mostre o maior deles, exibindo o seu quadrado.*/
int A[5];

void alimentacao(int n);
int maior(int n);
int quadrado(int q);

int main()
{
    int k;
    setlocale(LC_ALL, "Portuguese");
    alimentacao(k);
    int m = maior(k);
    int quad = quadrado(m);
    printf("O maior número entre eles é o %d que elevado ao quadrado fica %d", m, quad);
}

void alimentacao(int n)
{
    printf("Digite 5 números:\n");
    for(n=0;n<5;n++)
    {
        scanf("%d", &A[n]);
    }
}

int maior(int n)
{
    int g;
    for(n=0;n<5;n++)
    {
        if(g<A[n])
        {
            g = A[n];
        }
    }
    return g;
}

int quadrado(int q)
{
    int r;
    r = (q*q);
    return r;
}
#endif // ex10
