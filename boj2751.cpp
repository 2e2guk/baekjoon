// boj 2751 수 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n, 0);
    for(int i = 0; i< n; i++)
    {
        std::cin >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());
    for(int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << "\n";
    }
    return 0;
}