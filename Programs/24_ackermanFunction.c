#include <stdio.h>

int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main()
{
    int m = 3, n = 4;
    int result = ackermann(m, n);
    printf("The Ackermann value for (%d, %d) is %d\n", m, n, result);

    return 0;
}