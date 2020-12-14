//strings mix

class Mix
{
    static std::map<char, int> histogram(const std::string& str)
    {
        std::map<char, int> result{};
    
        for (auto ch : str) {
            if (ch >= 'a' && ch <= 'z') {
                ++result[ch];
            }
        }
    
        return result;
    }
    
    static std::map<char, std::pair<int, int>> histogram(
        const std::string& s1, 
        const std::string& s2
    )
    {
        std::map<char, std::pair<int, int>> result;
    
        for (auto e1 : histogram(s1)) {
            if (e1.second <= 1) {
                continue;
            }
            result[e1.first] = std::make_pair(1, e1.second);
        }
        for (auto e2 : histogram(s2)) {
            if (e2.second <= 1) {
                continue;
            }
    
            auto& e = result[e2.first];
            if (e.second < e2.second) {
                e = std::make_pair(2, e2.second);
            } else if (e.second == e2.second) {
                e.first = 3;
            }
        }
    
        return result;
    }
  
public:
    static std::string mix(const std::string& s1, const std::string& s2)
    {
        std::vector<std::string> parts;

        auto src = [](const std::pair<char, std::pair<int, int>>& x) {
            switch (x.second.first) {
                case 1: return "1:";
                case 2: return "2:";
                case 3: return "=:";
                default: return "";
            }
        };
    
        for (auto e : histogram(s1, s2)) {
            parts.emplace_back(src(e));
            parts.back().resize(2 + e.second.second, e.first);
        }
    
        std::sort(
            parts.begin(), 
            parts.end(),
            [](auto& lhs, auto& rhs) {
                if (int ldiff = lhs.size() - rhs.size()) {
                    return ldiff >= 0;
                }
    
                auto [l, r] = std::mismatch(lhs.begin(), lhs.end(), rhs.begin());
                return *l < *r;
            }
        );
    
        std::ostringstream result;
        if (parts.empty()) {
            return result.str();
        }
       
        auto it = parts.begin();
        result << *it;
        for (++it; it != parts.end(); ++it) {
            result << "/" << *it;
        }
    
        return result.str();
    }
};