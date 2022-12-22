// boj 10819 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> array(n, 0);
    for(int i = 0; i < n; i++)
    {
        
        std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());
    int max_value = 0;
    do
    {
        int sum = 0;
        for(int i = 1; i < n; i++)
        {
            sum += abs(array[i] - array[i - 1]);
        }
        max_value = std::max(max_value, sum);
    }while(std::next_permutation(array.begin(), array.end()));
    std::cout << max_value;
    return 0;
}