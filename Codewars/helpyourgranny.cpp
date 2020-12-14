//help your granny
#include <vector>
#include <cmath>

typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
public:
    static int tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h);
};

int Tour::tour( std::vector<std::string> & arrFriends, std::vector<std::vector<std::string> > & ftwns, stringdblmap & h )
{
    auto findTown = [&ftwns](const std::string & f) -> std::string {
        for( auto pos = 0; pos < ftwns.size(); ++pos )
            if( ftwns[pos][0] == f )
                return ftwns[pos][1];

        return std::string();
    };

    double total = 0;
    std::string town;
    std::string tmp;
    for( size_t f = 0; f < arrFriends.size(); ++f ){
        tmp = findTown(arrFriends.at(f));
        if( tmp.empty() ){
            continue;
        }
        total += town.empty() ? h.at(tmp) : std::sqrt( std::pow( h.at(tmp), 2 ) - pow( h.at(town), 2 ) );
        town = tmp;
    }

    total += h.at(town);

    return total;
}