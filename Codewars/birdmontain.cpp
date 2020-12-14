//bird mountain
int peak_height(std::vector<std::string>& mountain)
{
    int height = 0;
    bool founded_height = false;
    for(int str = 0; str < mountain.size(); ++str)
    {
        for(int c = 0; c < mountain[str].size(); ++c)
        {
            if(mountain[str][c] == '^')
            {
                mountain[str][c] = 1 + '0';
                height = 1;
            }
            else
            {
                mountain[str][c] = 0 + '0';
            }
        }
    }
    while(!founded_height)
    {
        founded_height = true;
        for(int str = 1; str < mountain.size() - 1; ++str)
        {
            for(int c = 1; c < mountain[str].size() - 1; ++c)
            {
                if(mountain[str][c] != '0'  and mountain[str - 1][c] >= height + '0' and mountain[str][c - 1] >= height + '0' 
                        and mountain[str][c + 1] >= height + '0' and mountain[str + 1][c] >= height + '0')
                {
                    mountain[str][c] = (height + 1) + '0';
                    founded_height = false;
                }
            }
        }
        ++height;
    }
    return height - 1;
}