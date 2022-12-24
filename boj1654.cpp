// boj 1654 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int k, n; // 오영식이 갖고 있는 랜선의 개수 k, 필요한 랜선의 개수 n
    std::cin >> k >> n;
    std::vector<int> LAN(k + 1, 0);
    int max_length;
    for(int i = 1; i <= k; i++)
    {
        std::cin >> LAN[i];
    }
    std::sort(LAN.begin(), LAN.end());
    long long int start = 1, end = LAN.back(), mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        int sum = 0;
        for(int i = 1; i <= k; i++)
        {
            sum += (LAN[i] / mid);
        }
        if(sum < n)
            end = mid - 1;
        else
        {
            start = mid + 1;
            max_length = mid;
        }
    }
    std::cout << max_length;
    return 0;
}