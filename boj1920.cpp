// boj1920 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n;
    std::vector<int> number_1(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin >> number_1[i];
    }
    std::sort(number_1.begin(), number_1.end());
    std::cin >> m;
    std::vector<int> number_2(m, 0);
    for(int i = 0; i < m; i++)
    {
        std::cin >> number_2[i];
    }
    for(int i = 0; i < number_2.size(); i++)
    {
        if(std::binary_search(number_1.begin(), number_1.end(), number_2[i]) == false)
            std::cout << 0 << "\n";
        else
            std::cout << 1 << "\n";
    }
    return 0;
}