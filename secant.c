#include <stdio.h>
#include <math.h>
double f(double x)
{
    return cos(x) + 2 * sin(x) + x * x;
    //  return pow(x, 3) - 20 * x + 16;
    // return x * exp(x) - 2;
    //return exp(-x) - x;
    // return log(x) - cos(x);

    // return pow(x, 2) - 2;
}

void Secant(void)
{
    int iterasyon = 0;
    double x0 = 0, x1 = -0.1, x2 = 0.0, hata = 0.0, tolerans = 0.05;
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
