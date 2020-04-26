#include <stdio.h>
#include <math.h>
double kesme(double normalize, int basamaksistemi)
{
    int tmp = normalize * pow(10, basamaksistemi);
    normalize = tmp / (pow(10, basamaksistemi) * 1.0);
    return normalize;
}

double yuvarla(double normalize, int basamaksistemi)
{
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
