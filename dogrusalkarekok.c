// karekök bulan fonsiyonu dogrusal ent kullanarak yazınız

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


// Algoritma Aynıdır tek farklılık kullanılan fonsiyondaki sabit değer 
// kullanıcıdan alınarak dinamiklik kazandırılmıştır.
double f(double x, double a)
{
    return pow(x, 2) - a;
}

double karekokbul(double a)
{

    double xlower = 0.0, xupper = a, xr = 0.0, hata = 0.0, tolerans = 0.1;

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
