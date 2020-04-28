#include <stdio.h>
#include <math.h>
double kesme(double normalize, int basamaksistemi)
{
    /*  --ALGORİTMA--
    1.  normalize edilmiş float sayı(ör. 0.123456) ve basamak sistemi paramatre olarak alınır.
    2.  basamak sistemi kaç ise o kadar 10 ile çarpılarak nokta sağa kaydırılır.(4 için 1234.56)
    3.  elde edilen sayı tam kısım ve floatlı kısımdan oluşur.Float kısmı kesmeden dolayı yok
        sayılacak kısımdır.
    4.  integer ın çalışma prensibinden faydalanırak atama yapılır.Ve float kısım kaybedilir.
    5.  Kaçkez 10 ile çarpıldıysa sayı bu sefer, o kadar 10 a bölünür ve kesmeye maruz kalan
        sayı elde edilmiş olur.
    */
    int tmp = normalize * pow(10, basamaksistemi);
    normalize = tmp / (pow(10, basamaksistemi) * 1.0);
    return normalize;
}

double yuvarla(double normalize, int basamaksistemi)
{
    /*  --ALGORİTMA--
    1.  normalize edilmiş float sayı(ör. 0.123456) ve basamak sistemi paramatre olarak alınır.
    2.  yuvarlamada basamak sistemi kaç ise bir sonraki basamağın değeri önemlidir.O yüzden bir
        değişkende tutulur.
    3.  basamak sistemi kaç ise 1 fazlası kadar 10 ile çarpılarak nokta sağa kaydırılır.(4 için 12345.6)
    4.  integer ın çalışma prensibinden faydalanırak atama yapılır.Ve float kısım kaybedilir.
    5.  sayının 10 a bölümünden kalan değişekene alınır.
    6.  10 bölünerek sayı istenilen basamak sistemine uygun hale gelir.
    7.  yuvarlamaya karar verilmek için değişkene alınan değer eğer 5'ten büyük ve eşitse değeri bir artılır.
        değilse bir işlem yapılmaz.
    8.  Kaçkez 10 ile çarpıldıysa sayı bu sefer, o kadar 10 a bölünür ve yuvarlamaya maruz kalan
        sayı elde edilmiş olur.
    */
    int yuvarlamabasamagi;
    int tmp = normalize * pow(10, basamaksistemi + 1);
    yuvarlamabasamagi = tmp % 10;
    tmp /= 10;
    if (yuvarlamabasamagi >= 5)
    {
        tmp++;
    }
    normalize = tmp / (pow(10, basamaksistemi) * 1.0);
    return normalize;
}

int main(int argc, char const *argv[])
{
    int kuvvet = 0;
    double sayi = exp(0.5);
    double normalize;
    int basamaksistemi;
    printf("basamak sistemini giriniz. \n");
    scanf("%d", &basamaksistemi);
    normalize = sayi;
    while (normalize > 1)
    {
        kuvvet++;
        normalize /= 10;
    }
    printf("sayının  normalize  hali: %lfx10^%d\n", normalize, kuvvet);
    sayi = kesme(normalize, basamaksistemi);
    printf("sayının   kesilmiş  hali: %gx10^%d\n", sayi, kuvvet);
    sayi = yuvarla(normalize, basamaksistemi);
    printf("sayının yuvarlanmış hali: %gx10^%d\n", sayi, kuvvet);

    return 0;
}
