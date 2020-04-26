#include <stdio.h>
#include <math.h>
double f(double x)
{
    return pow(4, x) - pow(3, 2 * x) + pow(2, 3 * x) - 1;
}

int main(int argc, char const *argv[])
{
    int iterasyon = 0;
    double xlower = 1.0, xupper = 2.0, xr = 0.0, hata = 0.0, tolerans = 0.1;

    if ((f(xlower) * f(xupper)) < 0)
    {
        hata = fabs(xupper - xlower);
        double sonkok = xupper;
        while (hata > tolerans)
        {
            iterasyon++;
            xr = (xlower + xupper) / 2;
            if (f(xlower) * f(xr) < 0)
            {
                xupper = xr;
            }
            else if (f(xlower) * f(xr) > 0)
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

        printf("Kök %g dir.%d iterasyonda bulundu.", sonkok, iterasyon);
    }
    else
        printf("[%g %g] aralığında kök yoktur", xlower, xupper);
    return 0;
}

