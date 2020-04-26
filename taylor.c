#include <stdio.h>
#include <math.h>

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
