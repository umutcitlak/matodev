#include <stdio.h>
#include <math.h>
double f(double x)
{
    
    return 2* pow(x, 3) - 2 * x -5;
}

int main(int argc, char const *argv[])
{
    int iterasyon = 0;
    double xlower = 1.0, xupper = 2.0, xr = 0.0, hata = 0.0, tolerans = 0.01;

    if ((f(xlower) * f(xupper)) < 0)
    {
        hata = fabs(xupper - xlower);
        double sonkok = xupper;
        while (hata > tolerans)
        {
            iterasyon++;
            xr = (xlower * f(xupper) - xupper * f(xlower)) / (f(xupper) - f(xlower));
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
