//phone directory 

#include <string>
#include <iostream>
#include <cctype>

class PhoneDir
{
public:
    static std::string find_name(std::string &str)
    {
        std::string name;
        bool is_name = false;
        for(int i = 0; i <= str.size(); ++i)
        {
            if(str[i] == '<')
            {
                is_name = true;
                continue;
            }
            if(is_name)
            {
                name += str[i];
            }
            if(str[i + 1] == '>')
            {
                break;
            }
        }
        return name;
    }

    static std::string find_string(const std::string &dr, int index_tp)
    {
        int index_begin = index_tp;
        while(dr[index_begin - 1] != '\n' && index_begin != 0)
        {
            --index_begin;
        }
        while(dr[index_tp + 1] != '\n' && index_tp != dr.size())
        {
            ++index_tp;
        }
        return dr.substr(index_begin, index_tp - index_begin + 1);
    }

    static std::string find_address(std::string &str)
    {
        std::string address;
        for(int i = 0; i < str.size(); ++i)
        {
            if(isalpha(str[i]) or isdigit(str[i]) or str[i] == '-' or str[i] == '.')
            {
                address += str[i];
            }
            else if(str[i] == ' ' or str[i] == '_')
            {
                if(address.size() > 0 and address.back() != ' ')
                {
                    address += ' ';
                }
            }
        }
        while(address.front() == ' ')
        {
            address.erase(0, 1);
        }
        while(address.back() == ' ')
        {
            address.erase(address.size() - 1, 1);
        }
        return address;
    }

    static std::string phone(const std::string& orgdr, std::string num)
    {
        int index_tp = orgdr.find(num);
        std::string name = "";
        std::string address = "";
        if(index_tp == std::string::npos)
        {
            return "Error => Not found: " + num;
        }
        else
        {
            while(true)
            {
                std::string str = find_string(orgdr, index_tp);
                str.erase(str.find(num), num.size());
                if(name == "")
                {
                    name = find_name(str);
                }
                else
                {
                    if(name != find_name(str))
                    {
                        return "Error => Too many people: " + num;
                    }
                }
                str.erase(str.find(name) - 1, name.size() + 1);
                if(address == "")
                {
                    address = find_address(str);
                }
                else
                {
                    if(address != find_address(str))
                    {
                        return "Error => Too many people: " + num;
                    }
                }
                index_tp = orgdr.find(num, index_tp + 1);
                if(index_tp == std::string::npos)
                {
                    break;
                }
            }
        }
        return "Phone => " + num + ", Name => " + name + ", Address => " + address;
    }
};