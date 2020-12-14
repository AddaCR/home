//sum of intervals
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool comp (pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
		return (a.second < b.second);
    return (a.first < b.first);
}

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    int sum = 0;
    int x = intervals.size();
    sort(intervals.begin(), intervals.end(), comp);
    for (int i = 1; i < x; i++)
    {
        if (intervals[i].first <= intervals[i-1].second)
        {
            if (intervals[i].second > intervals[i-1].second)
            {
                intervals[i-1].second = intervals[i].second;
                intervals.erase(intervals.begin()+i);
                x--;
                i--;
            }
            else
            {
                intervals.erase(intervals.begin()+i);
                x--;
                i--;
            }
        }
    }
    for (int i = 0; i < intervals.size(); i++)
    {
        sum += intervals[i].second - intervals[i].first;
    }

    return sum;
}