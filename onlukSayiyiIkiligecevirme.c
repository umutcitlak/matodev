#include <stdio.h>
#include <math.h>
/*
1-) sayı sıfırda while
2-) sayının ikiye bölümünde  kalanı diziye ekle
3-) sayıyı ikiye böl
4-) adım bire git
5-) diziyi ters çevir
*/
short binaryreverse[32];
short binary[32];
int main(int argc, char const *argv[])
{
    int decimal = 5;

    int i = 0;
    //döngüde ikilik sayı ters olarak bulunur
    while (decimal != 0)
    {
        binaryreverse[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    // ters sayımızı düzeltiğimiz kod bloğu
    for (int i = 0; i < 32; i++)
    {
        binary[i] = binaryreverse[31 - i];
    }

    for (int i = 0; i < 32; i++)
    {
        printf("%d", binary[i]);
    }

    return 0;
}
