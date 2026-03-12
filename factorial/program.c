#include <stdio.h>
#include <windows.h>

unsigned long long fact_rec(int n)
{
    if(n<=1) return 1;
    return n * fact_rec(n-1);
}

unsigned long long fact_itr(int n)
{
    unsigned long long f = 1;
    for(int i=1;i<=n;i++)
        f *= i;
    return f;
}

int main()
{
    LARGE_INTEGER s,e,freq;
    QueryPerformanceFrequency(&freq);

    printf("InputSize\tIterativeTime(ns)\tRecursiveTime(ns)\n");

    for(int n=1;n<=30;n+=2)
    {
        QueryPerformanceCounter(&s);
        fact_itr(n);
        QueryPerformanceCounter(&e);
        double it = (double)(e.QuadPart-s.QuadPart)*1e9/freq.QuadPart;

        QueryPerformanceCounter(&s);
        fact_rec(n);
        QueryPerformanceCounter(&e);
        double rt = (double)(e.QuadPart-s.QuadPart)*1e9/freq.QuadPart;

        printf("%d\t\t%.0f\t\t\t%.0f\n",n,it,rt);
    }

    return 0;
}
