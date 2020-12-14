// burrows wheeler tranformation

#include <vector>
#include <algorithm>

std::pair<std::string, int> encode(const std::string &str)
{
    std::vector<std::string> matrix;
    matrix.reserve(str.size());
    
    for (int i = 0; i < static_cast<int>(str.length()); ++i)
    {
        matrix.push_back(std::string(str.end() - i, str.end()) + std::string(str.begin(), str.end() - i));
    }

    std::sort(matrix.begin(), matrix.end());

    auto pos = std::distance(matrix.begin(), std::find(matrix.begin(), matrix.end(), str));
    std::string result;

    for (std::string row : matrix)
        result += row.back();

    return { result, pos };
}

std::string decode(const std::string &str, unsigned int row)
{
    if (str.empty()) return std::string();

    std::vector<std::string> matrix(str.size());
    for (unsigned int j = 0; j < str.size(); ++j)
    {
        for (unsigned int i = 0; i < str.size(); ++i)
        {
            matrix[i].insert(0, str.substr(i, 1));
        }
        std::sort(matrix.begin(), matrix.end());
    }
    return  matrix.at(row);
}