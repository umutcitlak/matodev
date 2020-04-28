#include <stdio.h>
#include <math.h>
char sayi[64];
int main()
{
    //64 bit sayi
    int s;        //işaret biti
    int c = 0;    //üstel bit
    double f = 0; //kesir kısım
    int sayac1 = 0;
    int sayac2 = 0;
    int s1 = 11;
    int s2 = 12;
    printf("çevrilecek 64 bit sayiyi giriniz ");
    scanf("%s", &sayi);
    if (sayi[0] == '0')
        s = 0;
    else if (sayi[0 == '1'])
        s = 1;

    while (sayac1 < 11)
    {
        if (sayi[s1] == '1')
            c += pow(2, sayac1);
        s1--;
        sayac1++;
    }
    while (sayac2 < 52)
    {
        if (sayi[s2] == '1')
            f += pow(2, -(sayac2 + 1)); //değer taraf üsü 1 den başlatan sayac2
        s2++;
        sayac2++;
    }
    double sonuc = pow(-1, s) * pow(2, (c - 1023)) * (1 + f);
    printf("ondalık sayi=> %f", sonuc);
    return 0;
}