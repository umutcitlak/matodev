#include <stdio.h>
#include <math.h>

/*  --ALGORİTMA--
1.  Start
2.  Verileri al
3.  Yeni kökü x0 ve x1 değerlerini formülde yerine
    yazarak bul. (x2 = x1 - ((f(x1) * (x0 - x1)) / (f(x0) - f(x1)));)
4.  son iki kökün farkını bularak hata payını belirle.
5.  x0'a x1 kökünün değerini koy
6.  x1'e yeni kökün değerini koy
7.  Hata payı toleranstan büyükse döngüye gir(Adım 3'e git).Değilse Adım 8 e git.
8.  En son bulunan kökü yazdır.
8.  stop
 */

double f(double x)
{
    return cos(x) + 2 * sin(x) + x * x;
  
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
