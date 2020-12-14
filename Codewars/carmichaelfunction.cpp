//carmichael function

#include <vector>
#include <cmath>

std::vector<long long> factorize(long long n)
{
    std::vector<long long> result;
    long long i = 2;
    while (i * i <= n){
        if (n % i) i++;
        else {
            n /= i;
            result.push_back(i);
        }
    }

    if (n>1) result.push_back(n);
    return result;
}


long long  EulerTotient(long long p, long long w)
{
    return pow(p, w-1) * (p - 1);
}

long long  Carmichael(long long p, long long w)
{
    if (p < 2) return 1;
    if (p == 2 && w > 2)
        return EulerTotient(p, w)/2;
    return EulerTotient(p, w);
}

long long gcd(long long a, long long b)
{
    long long tmp;
    if (a > b){
        tmp = a;
        a = b;
        b = tmp;
    }
    long long c = b % a;

    if (c == 0) return a;
    return gcd(a, c);
}

long long Carmichael(long long n)
{
    if (n <= 0) return 0;
    std::vector<long long> factor = factorize(n);

    std::vector<long long> lcm;
    int count = 0;
    long long value = 0;
    for (int i = 0; i< factor.size(); ++i){
        if (count == 0){
            value = factor[i];
            count = 1;
        }
        else if (factor[i] == value){
            count++;
        }
        else {
            lcm.push_back(Carmichael(value, count));
            value = factor[i];
            count = 1;
        }
    }

    if (count == 0) count++;
    lcm.push_back(Carmichael(value, count));

    for (int i = 1; i < lcm.size(); ++i){
        lcm[i] = lcm[i-1]*lcm[i]/gcd(lcm[i-1], lcm [i]);
    }

    return lcm.back();
}