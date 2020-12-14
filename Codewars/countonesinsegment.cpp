//count ones in a segment

#include <vector>
long long s(int x)
{
    long long sum = 1, i, j = 0, m, p, pdsum = 1, mn = -1;
    for (i = 2; i <= x; i *= 2)
        j++;
    i /= 2;
    vector <bool> f(j + 1);
    p = j - 1;
    m = x - i + 1;
    if (x + 1 == i * 2)
        j++;
    else
        for (long q = i / 2; q != 0; q /= 2) {
            f[p] = m / q;
            if (f[p]) {
                m -= q;
                mn++;
            }
            p--;
        }
    if (f[0]) {
        sum += mn + 1;
        mn --;
    }
    p = 1;
    for (long q = 1; q < j; ++q)
    {
        pdsum = pdsum * 2 + p;
        sum += pdsum;
        p *= 2;
        if (f[q])
        {
            sum += pdsum + p * mn;
            mn--;
        } 
    }
    if (x == 0)
        return 0;
    else
        return sum;
}

long long countOnes(int l, int r)
{
    return s(r) - s(l - 1);
}