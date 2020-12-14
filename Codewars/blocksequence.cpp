//block sequence

#include <string>
#include <math.h>

using namespace std;

long long cal(long long bits, long long val, long long min, long long base_len)
{
    long long cnt = val - min + 1;
    long long first = base_len + bits;
    long long last = base_len + cnt * bits;
    return (first + last) * cnt / 2;
}

int solve(long long n)
{
    if (n == 1)
    {
        return 1;
    }

    int bits = 1;
    long long last_len = 0;
    while (1)
    {
        long long cnt = 9 * pow(10, bits - 1);
        long long min_len = last_len + bits;
        long long max_len = last_len + cnt * bits;
        long long total_len = (min_len + max_len) * cnt / 2;
        if (n <= total_len)
        {
            break;
        }
        n -= total_len;
        ++bits;
        last_len = max_len;
    }

    long long f = pow(10, bits - 1);
    long long t = pow(10, bits) - 1;
    long long m = f;
    
    while (f + 1 < t)
    {
        long long mid = f + t;
        mid /= 2;

        long long fore = cal(bits, mid, m, last_len);
        if (fore >= n)
        {
            t = mid;
        }
        else
        {
            f = mid + 1;
        }
    }

    long long add_to = f;
    while (cal(bits, add_to, m, last_len) < n)
    {
        ++add_to;
    }
    n -= cal(bits, add_to - 1, m, last_len);

    int bit_group = 1;
    while (n > 9 * pow(10, bit_group - 1) * bit_group)
    {
        long long tmp = 9 * pow(10, bit_group - 1) * bit_group;
        n -= tmp;
        ++bit_group;
    }

    long long fore = (n - 1) / bit_group;
    n -= fore * bit_group;
    long long dst = pow(10, bit_group - 1) + fore;

    return to_string(dst)[n - 1] - '0';

}