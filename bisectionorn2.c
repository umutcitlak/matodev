#include <stdio.h>
#include <math.h>

double f(double x);
int iterasyononeri(double hatapayi, double aralik1, double aralik2);

int main(int argc, char const *argv[])
{
    int secim;
    int iterasyon;
    double xlower = 1.0, xupper = 2.0, xr = 0.0, hata = 0.0, tolerans = 0.1;
    printf("\n1.) Kaç iterasyon işlem yapmak istiyorsunuz?\n2.)Hata payı girerek minimum kaç iterasyon yapılmalı öğren\n");
    scanf("%d", &secim);
    switch (secim)
    {
    case 1:
    {
    iterasyongir:
        printf("\nİterasyon sayısı:");
        scanf("%d", &iterasyon);
        goto islem;
    }
    case 2:
    {
        printf("Hata payı: ");
        scanf("%lf", &tolerans);
        printf("\n%lf hata payı için en az %d iterasyon işlem yapılmalıdır", tolerans, iterasyononeri(tolerans, xlower, xupper));
        goto iterasyongir;
        printf("");
    }
    default:
    {
        printf("\nHatalı seçim yatınız.Promram sonlandırıldı.");
        return 0;
    }
    }
islem:
    if ((f(xlower) * f(xupper)) < 0)
    {

        hata = fabs(xupper - xlower);
        double sonkok = xupper;
        while (iterasyon > 0)
        {
            iterasyon--;
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

        printf("Kök %g dir.", sonkok);
    }
    else
        printf("[%g %g] aralığında kök yoktur", xlower, xupper);
    return 0;
}

double f(double x)
{
    return pow(x, 4) - 7;
}

int iterasyononeri(double hatapayi, double aralik1, double aralik2)
{
    int n = (log10(fabs(aralik1 - aralik2)) - log10(2 * hatapayi)) / log10(2);

    /* +2 olma sebebi 
    +1 formüldeki n bulunan değerden büyük olduğu için
    diğer +1 ise formülde hep 1 eksik çıkıyor hatalı yani yada
    formül bisection algoritmasındaki ilk bulduğuz kökü iterasyondan saymıyor.
    (algoritmada ilk kök fonksiyonların çarpımının 0'dan küçük olup olamadığına bakılmadan hesaplanıyor). 
    */
    return n + 2;
}