//histogram v1

#include <string>
#include <vector>
using namespace std;

std::string histogram(std::vector<int> results)
{
    vector <string> histogram;
    string str = "";
    str = "1 2 3 4 5 6\n";
    histogram.push_back(str);
    str = "-----------\n";
    histogram.push_back(str);
    int max = 0;
    for(int i = 0;i < results.size();i++) {
        if(max < results[i]) {
            max = results[i];
        }
    }

    if(max != 0) {
    for(int i = 1;i <= max + 1;i++) {
        str = "";
        for(int j = 0;j < results.size();j++) {
            if(i <= results[j]) {
                str += '#';
                str += ' ';
            }
            else 
				if(i == results[j]+1 && results[j] != 0)  {
					str += to_string(results[j]);
						if(results[j] < 10)
							str += ' ';
            }
            else
                str += "  ";
        }   
            while(isspace(str[str.size()-1])) {
               str.erase(str.begin()+str.size()-1);
            }

        str += '\n';
        histogram.push_back(str);
    }
}
    string res = "";
    for(int i = histogram.size() - 1;i >= 0;i--)
    {
        res += histogram[i];
    }
    return res;
}