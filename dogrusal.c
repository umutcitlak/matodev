#include <stdio.h>
#include <math.h>

/*  --ALGORİTMA--
1.  Start
2.  Verileri al
3.  Verilen iki kökü fonksiyona koy ve çıkan değerleri çarp
4.  Sonucun sıfırdan küçük olup olmadığını kontrol et küçükse bu aralıkta kök vardır. Adım 5' e
    geç. Küçük değilse aralıkta kök yoktur adım 16'ya git.
5.  En son bulunan iki kök arasındaki farkı bul.Bulunan değer hatapayıdır.son kökü değikene
    al ezilip kaybolmaması için
6.  Hata payı toleranstan büyükse döngüye gir(Adım 7 den devam).Değilse Adım 15 e git.
7.  Yeni kökü (xlower * f(xupper) - xupper * f(xlower)) / (f(xupper) - f(xlower) formülünü
    kullanarak bul.
8.  Lower kök ile yeni bulunan kökün fonksiyonlardaki değerlerini çarp
9.  Sonuç sıfırdan küçükse upper kökü yeni bulunan kök olarak kabul et.
10. Büyükse  lower kökü yeni bulunan kök olarak kabul et.
11. Sıfıra eşitse kök zaten bulunmuş demektir.adım 15'e git.
12. Son iki kökün farkını alarak hata payını bul.
13. Son bulunan kökü değişkende tut.
14. Adım 6 ya git.
15. Bulunan kökü yazdır.
16. Stop
 */




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
