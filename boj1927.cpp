// boj 1927 최소 힙
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // 최소 힙 구성하기
    std::vector<int> ans;
    int n, x; // 연산의 개수 n, 연산의 정보를 나타내는 x
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        if(x > 0)
        {
            pq.push(x);
        }
        if(x == 0)
        {
            if(pq.empty())
                ans.push_back(0);
            else
            {
                ans.push_back(pq.top());
                pq.pop();   
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << "\n";
    }
    return 0;
}