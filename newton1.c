#include <stdio.h>
#include <math.h>
/*  --ALGORİTMA--
1.  Start
2.  Verileri al
3.  yeni kökü formülü kullanarak bul.(x = x0 - f(x0) / f1(x0);)
4.  son iki kökün farkını bularak hata payını belirle.
5.  bi önceki kökü son bulduğun kökün değerine eşle
6.  hata payı büyükmü toleranstan kontrol et.büyükse adım 3'e git.değilse adım 7.
7.  bulunan kökü yazdır
8.  stop
 */

double f(double x)
{
    return 3 * pow(x, 2) + 12 * x + 7;
}
double f1(double x)
{
    return 6 * x + 12;
}

int main()
{
    int iterasyon = 0;
    double x0 = 4, x = 0.0, y = 0.0, hata = 0.0, tolerans;
    printf("Kaç hata payı ile bulmak istiyorsunuz? ");
    scanf("%lf", &tolerans);
    do
    {
        iterasyon++;
        x = x0 - f(x0) / f1(x0);
        hata = fabs(x - x0);
        x0 = x;

    } while (hata > tolerans);

    printf("Kok -> %lf", x);
    return 0;
}
