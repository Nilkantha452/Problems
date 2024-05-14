/* Find the highest common factor of two numbers provided. */

#include <iostream>
#include <climits>

int getHCF(int m, int n)
{
    int mini = std::min(m, n);
    int hcf = 1;
    for (int i = 1; i <= mini; i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
}

int getHCFBetter(int m, int n)
{
    /* This is slightly better method. */
    int mini = min(m, n);
    int hcf = 1;
    for (int i = mini; i >= 1; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            hcf = i;
            break;
        }
    }
    return hcf;
}

int EuclideanMethod(int m, int n)
{
    if (m == n) return m;
    while (m != 0 && n != 0)
    {
        if (m > n)
        {
            m = m % n;
        }
        else
        {
            n = n % n;
        }
    }
    if (m == 0) return n;
    return m;
}

int main()
{
    int m = 12;
    int n = 15;
    std::cout << "HCF of " << m << " and " << n << " is : " << getHCF(m, n);
}