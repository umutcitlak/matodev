#include <stdio.h>
#include <math.h>
double f(double x)
{
    return pow(x,3)/5-5;
}

void Secant(void)
{
    int iterasyon = 0;
    double x0 = 0, x1 = 3, x2 = 0.0, hata = 0.0, tolerans = 0.01;
    do
    {
        iterasyon++;
        x2 = x1 - ((f(x1) * (x0 - x1)) / (f(x0) - f(x1)));
        hata = fabs(x2 - x1);
        x0 = x1;
        x1 = x2;
    } while (hata > tolerans);

    printf("aranan kök -> %1f hata ->%1f  iterasyon: %d", x2, hata, iterasyon);
}
int main()
{
    Secant();
    return 0;
}
