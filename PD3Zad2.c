#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<math.h>

float Leibniz(int n)
{
    float wynik = 0;
    float suma = 0;
    int i;
    for (i=1; i<=n; i++)
    {
        suma = powf(-1, i-1) / (2 * i - 1);
        wynik += suma;
    }
    return 4 * wynik;
}

int main()
{
    int proc;
    printf("Podaj ilosc procesow: ");
    scanf("%d", &proc);
    int i;
    for(i=0; i<proc; i++)
    {
        if(fork()==0)
        {
            srand(time(NULL) ^ (getpid()<<16));
            int n = 100 + rand()%5000+1;
            printf("N = %d\n", n);
            float wynik = Leibniz(n);
            printf("Przyblizenie liczby Pi z wozru Leibniza = %f\n", wynik);
            exit(0);
        }
    }
}
