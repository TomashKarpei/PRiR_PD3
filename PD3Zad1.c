#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

float funkcja(float x)
{
    return 4*x-6*x+5;
}

float trapez(float a, float b, int n)
{
    float calka = 0;
    float dx = (b-a)/n;
    int i;
    for(i=1;i<=n-1;i++)
    {
        calka += funkcja(a+i*dx);
    }
    calka += (funkcja(a)+funkcja(b))/2;
    calka *= dx;
    return calka;
}

int main()
{
    printf("Podaj ilosc procesow: ");
    int proc;
    scanf("%d",&proc);
    int i;
    for(i=0;i<proc;i++)
    {
        if(fork()==0)
        {
            srand(time(NULL) ^ (getpid()<<16));
            int a = rand()%50;
            int b = a + 1 + rand()%50;
            int n = 50 + rand()%50;
            float wynik = trapez(a, b, n);
            printf("Przedzial a: %d\n", a);
            printf("Przedzial b: %d\n", b);
            printf("Wynik: %f\n", wynik);
            exit(0);
        }
    }
}
