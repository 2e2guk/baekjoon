// boj 6159 코스튬 파티
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, s, cow_pair = 0;
    std::cin >> n >> s;
    std::vector<int> cow_size(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin >> cow_size[i];
    }
    std::sort(cow_size.begin(), cow_size.end());
    for(int i = 0; i < cow_size.size() - 1; i++)
    {
        int cow_1 = cow_size[i];
        for(int j = i + 1; j < cow_size.size(); j++)
        {
            int sum = cow_1;
            sum += cow_size[j];
            if(sum <= s)
                cow_pair++;
        }
    }
    std::cout << cow_pair;
    return 0;
}