#include <stdio.h>
#include <math.h>


/*  --ALGORİTMA--
1.  start
2.  değişkenlerin değerlerini ata (x, toplam, turev, x0, k)
3.  fonksiyon 4 katlarında tekrarlayan bir rutin içinde ilerlemektedir.
4.  k 4 den küçükmü kontrol edilir. true ise adım 5 e. değilse adım 8 e git
5.  k nın mod 4 ü alınır. modun sonucuna göre turev değeri alınır
6.  bulunan değerler formülde yazılarak serinin geçerli aşamadaki
    değeri bulunur toplama eklenir.
7.  bir sonraki iterasyon için k 1 artırılır.Adım 4 e git.
8.  serinin x değeri için değeri ekrana yazılır.
9.  stop

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
    double x = 0.2, toplam = 0.0, turev, x0 = 0;
    int k = 0;
    while (k < 4)
    {
        int mod = k % 4;
        if (mod == 0)
        {
            turev = sin(x0);
        }
        else if (mod == 1)
        {
            turev = cos(x0);
        }
        else if (mod == 2)
        {
            turev = -sin(x0);
        }
        else if (mod == 3)
        {
            turev = -cos(x0);
        }

        toplam += (pow(x - x0, k) * turev) / fak(k);
        k++;
    }
    printf("toplam = %lf ", toplam);

    return 0;
}
