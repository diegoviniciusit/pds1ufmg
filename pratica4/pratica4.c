#include <stdio.h>
#include <math.h>
#include "pratica4.h"

float paraMetrosPorSegundo(float v)
{
    return v / 3.6;
}

float areaCirculo(float raio)
{
    return 3.141592 * raio * raio;
}

int ePar(int n)
{
    return n % 2 == 0 ? 1 : 0;
}

int eDivisivelPor3ou5(int n)
{
    int divisivelPor3 = n % 3 == 0 ? 1 : 0;
    int divisivelPor5 = n % 5 == 0 ? 1 : 0;
    return divisivelPor3 + divisivelPor5 == 1 ? 1 : 0;
}

float pesoIdeal(float h, char sexo)
{
    if (sexo == 'M') {
        return (72.7 * h) - 58;
    } else if (sexo == 'F') {
        return (62.1 * h) - 44.7;
    }
    return 0.0;
}

int somaImpares(int n)
{
    int i = 1;
    int sum = 0;
    while (i <= n) {
        if (i % 2 == 1) {
            sum += i;
        }
        i++;
    }
    return sum;
}

double fatorial(int n)
{
    double i = 1;
    double fatorial = 1;
    while (i <= n) {
        fatorial *= i;
        i++;
    }
    return fatorial;
}

int somaNumerosDiv3ou5(int n)
{
    int i = 3;
    int sum = 0;
    while (i <= n) {
        if (eDivisivelPor3ou5(i) == 1) {
            sum += i;
        }
        i++;
    }
    return sum;
}

float calculaMedia(int x, int y, int z, int operacao)
{
    if (operacao == 1) {
        return (float) cbrt((double) (x * y * z));
    } else if (operacao == 2) {
        return ((float) (x + (2 * y) + (3 * z))) / 6;
    } else if (operacao == 3) {
        return 3 / ((1 / (float) x) + (1 / (float) y) + (1 / (float) z));
    } else if (operacao == 4) {
        return ((float) x + y + z) / 3;
    }
    return 0.0;
}

int numeroDivisores(int n)
{
    int i = 1;
    int divisors = 1;
    while (i < n) {
        if (n % i == 0) {
            divisors++;
        }
        i++;
    }
    return divisors;
}

int enesimoFibonacci(int n)
{
    if (n == 1) {
        return 0;
    }
    int lastTerm = 1;
    int lastButOneTerm = 0;
    int auxLastTerm = 0;
    int i = 2;
    while (i < n) {
        auxLastTerm = lastTerm;
        lastTerm += lastButOneTerm;
        lastButOneTerm = auxLastTerm;
        i++;
    }
    return lastTerm;
}

int mdc(unsigned int x, unsigned int y)
{
    int i = 2;
    int maxDivisor = 1;
    while (i <= (x < y ? x : y)) {
        if (x % i == 0 && y % i == 0) {
            maxDivisor = i;
        }
        i++;
    }
    return maxDivisor;
}

int mmc(unsigned int x, unsigned int y)
{
    int i = x > y ? x : y;
    int minMultiple = 0;
    int xMultiple = 0;
    while (minMultiple == 0) {
        if (i >= x && i % x == 0 && i >= y && i % y == 0) {
            minMultiple = i;
        }
        i++;
    }
    return minMultiple;
}
