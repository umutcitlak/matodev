#include <stdio.h>
#include <math.h>
/*
--ALGORİTMA--
1. start
2. sayıyı al.i değişekni sıfır yap index olarak kullan
3. sayı sıfırdan farklı ise adım 4 e git.Değilse adım 8'e git
4. dizinin i değerindeki index'e sayının ikiye bölümünden kalanı ekle
5. sayıyı iikiye böl.(float kısmı alınmayacak)
6. i değerini bir arttır
7. adım 3' e git
8. for ile diziyi ters çevir.(dizideki binary sayı tersten okunur.ters çevirerek sayı düzeltilir)
9. sayıyı ekrana yazdır
10. stop
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
