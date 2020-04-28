#include <stdio.h>
#include <math.h>
/*  --ALGORİTMA--
1.  start
2.  değişkenlerin değerlerini ata (x, toplam, turev, x0, k)
3.  lnx in değeri alınır .
4.  serinin ilk aşaması için formulde yerine yazılır toplama eklenir.
5.  bir sonraki iterasyon için k 1 artırılır.
6.  sabit diye bir değişken oluşturulup değeri 1 yapılır.
    (sabit değişkeni türev alırken kullanılmak için kullanılıyor.) 
7.  k 4 den küçükmü kontrol edilir. true ise adım 8 e.
    false ise adım 12 ye gidilir.  
8.  türev alınır
9.  türev formülde yerine konur.sonuç toplama eklenir.  
10. k 1 artırılır.
11. adım 4 e gidilir.
12. serinin x değeri için değeri ekrana yazılır.
13. stop

*/
double fak(int a)
{
    if (a == 1 || a == 0)
        return 1;
    else
        return a * fak(a - 1);
}

int main(int argc, char const *argv[])
{
    double x = 2, toplam = 0.0, turev, x0 = 1;

    int k = 0;
    turev = log(x0);
    toplam = (pow(x - x0, k) * turev) / fak(k);
    k = 1;
    turev = 1 / x0;
    toplam += (pow(x - x0, k) * turev) / fak(k);
    k++;
    int sabit = 1;
    while (k < 4)
    {
        sabit = sabit * -(k - 1);
        turev = sabit / pow(x0, k);
        toplam += (pow(x - x0, k) * turev) / fak(k);
        k++;
    }
    printf("toplam = %lf ", toplam);

    return 0;
}
