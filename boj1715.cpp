// boj 1715 카드 정렬하기
#include <iostream>
#include <queue>
#include <vector> 
#include <numeric>
int main()
{
    int n;
    unsigned long long int compare_num;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; // 최소 힙 구성하기
    std::vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        min_pq.push(input);
    }
    if(min_pq.size() == 1) // 카드 더미가 1개인 경우, 비교 횟수는 0이다. 
    {
        std::cout << 0;
        return 0;
    }
    else
    {
        while(true)
        {
            compare_num = 0;
            compare_num += min_pq.top();
            min_pq.pop();
            compare_num += min_pq.top();
            min_pq.pop();
            ans.push_back(compare_num);
            if(min_pq.empty())
            {
                break;
            }
            min_pq.push(compare_num);
        }
    }
    std::cout << std::accumulate(ans.begin(), ans.end(), 0);
    return 0;
}
