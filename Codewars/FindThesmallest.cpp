//Find the smallest

#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>


class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n);
    
private:
    static std::vector<long long> toVector(long long n);
    static long long toLongLong(std::vector<long long> vec);
    
};

std::vector<long long> ToSmallest::smallest(long long n)
{
    std::vector<long long> number = toVector(n);
    std::vector<long long> result = { n, 0, 0 };
    
    int mainIndex = 0;
    while(mainIndex < number.size())
    {
        long long testDigit = number[mainIndex];
        
        std::vector<long long> test = number;
        test.erase(test.begin() + mainIndex);
        
        for(int index = 0; index < number.size(); index++)
        {
            test.insert(test.begin() + index, testDigit);
            long long x = toLongLong(test);
            
            if(x < result[0])
            {
                result[0] = x;
                result[1] = mainIndex;
                result[2] = index;
            }
            
            test.erase(test.begin() + index);
        }
        mainIndex++;
    }
    
    return result;
}
std::vector<long long> ToSmallest::toVector(long long n)
{
    std::vector<long long> result;
    long long remainingNumber = n;
    
    while(remainingNumber > 0)
    {
        result.insert(result.begin(), (remainingNumber % 10));
        remainingNumber /= 10;
    }
    
    return result;
}
long long ToSmallest::toLongLong(std::vector<long long> vec)
{
    long long result = 0;
    
    for(int index = 0; index < vec.size(); index++)
    {
        result += vec[index] * pow(10, (vec.size() - index - 1));
    }
    
    return result;
}