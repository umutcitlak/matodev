#include <stdio.h>
#include <math.h>

double fak(int a)
{
    if (a == 1 || a == 0)
        return 1;
    else
        return a * fak(a - 1);
}

int main(int argc, char const *argv[])
{
    double x = 2, toplam = 0.0, turev, x0 = 1;

    int k = 0;
    turev = log(x0);
    toplam = (pow(x - x0, k) * turev) / fak(k);
    k = 1;
    turev = 1 / x0;
    toplam += (pow(x - x0, k) * turev) / fak(k);
    k++;
    int sabit = 1;
    while (k < 4)
    {
        sabit = sabit * -(k - 1);
        turev = sabit / pow(x0, k);
        toplam += (pow(x - x0, k) * turev) / fak(k);
        k++;
    }
    printf("toplam = %lf ", toplam);

    return 0;
}
