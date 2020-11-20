#include <stdio.h>
#include <math.h>
int main()
{
    int i = 2;
    long long num;
	 scanf("%lld",&num);
    long long sx = int(sqrt(num)+1);
    int max = 0;
    for (; i < sx; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            if (max < i)
            {
                max = i;
            }
        }
    }
    printf("%d", max);
	 return 0;
}

