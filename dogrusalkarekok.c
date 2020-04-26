// karekök bulan fonsiyonu dogrusal ent kullanarak yazınız

#include <stdio.h>
#include <math.h>

double f(double x, double a)
{
    return pow(x, 3) - a;
}

double karekokbul(double a)
{

    double xlower = 0.0, xupper = a, xr = 0.0, hata = 0.0, tolerans = 0.0000001;

    if (a >= 0)
    {
        hata = fabs(xupper - xlower);
        double sonkok = xupper;
        while (hata > tolerans)
        {
            xr = (xlower * f(xupper, a) - xupper * f(xlower, a)) / (f(xupper, a) - f(xlower, a));
            if (f(xlower, a) * f(xr, a) < 0)
            {
                xupper = xr;
            }
            else if (f(xlower, a) * f(xr, a) > 0)
            {
                xlower = xr;
            }
            else
            {
                sonkok = xr;
                break;
            }
            hata = fabs(sonkok - xr);
            sonkok = xr;
        }
    }
    else
        printf("Verilen sayının real bir karakökü yoktur\n");
    return xr;
}
int main(int argc, char const *argv[])
{
    double sayi;
    printf("hangi sayının karekökünü bulmak istiyorsunuz : ");
    scanf("%lf", &sayi);
    printf("\n%lf\n", karekokbul(sayi));
    return 0;
}
