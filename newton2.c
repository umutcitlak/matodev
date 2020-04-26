#include <stdio.h>
#include <math.h>

double f(double x)
{
    return pow(x, 3) - 7;
}
double f1(double x)
{
    return 3 * pow(x, 2);
}

int main()
{

    int i = 0;
    int iterasyon;
    double x0 = 2, x = 0.0, y = 0.0, hata = 0.0;
    printf("iterasyon sayısını giriniz\n");
    scanf("%d", &iterasyon);
    do
    {
        i++;
        x = x0 - f(x0) / f1(x0);
        hata = fabs(x - x0);
        x0 = x;

    } while (i < iterasyon);

    printf("Kok -> %lf\nHata -> %lf", x, hata);
    return 0;
}
