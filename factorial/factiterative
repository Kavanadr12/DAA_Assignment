#include <stdio.h>
#include <windows.h>

long long computeFactorial(int num)
{
    long long res = 1;
    int j = 1;

    while (j <= num)
    {
        res = res * j;
        j++;
    }

    return res;
}

int main()
{
    LARGE_INTEGER t_start, t_end, frequency;
    QueryPerformanceFrequency(&frequency);

    printf("Input\tFactorial\tExecution Time (ns)\n");

    for (int n = 1; n <= 21; n++)
    {
        long long value;

        QueryPerformanceCounter(&t_start);

        int k = 0;
        while (k < 100000)
        {
            value = computeFactorial(n);
            k++;
        }

        QueryPerformanceCounter(&t_end);

        long long elapsed =
            (t_end.QuadPart - t_start.QuadPart) * 1000000000LL / frequency.QuadPart;

        printf("%d\t%lld\t\t%lld\n", n, value, elapsed);
    }

    return 0;
}
