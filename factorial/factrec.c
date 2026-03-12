#include <stdio.h>
#include <windows.h>

long long fact(int x)
{
    if(x == 0 || x == 1)
        return 1;
    else
        return x * fact(x - 1);
}

int main()
{
    LARGE_INTEGER t1, t2, f;
    QueryPerformanceFrequency(&f);

    printf("Input\tFactorial\tExecutionTime(ns)\n");

    for(int n = 1; n <= 21; n++)
    {
        long long value;

        QueryPerformanceCounter(&t1);

        int repeat = 100000;
        while(repeat--)
        {
            value = fact(n);
        }

        QueryPerformanceCounter(&t2);

        long long duration =
        (t2.QuadPart - t1.QuadPart) * 1000000000LL / f.QuadPart;

        printf("%d\t%lld\t\t%lld\n", n, value, duration);
    }

    return 0;
}
