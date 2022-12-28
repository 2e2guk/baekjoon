// boj 11866 요세푸스 문제 0
#include <iostream>
#include <queue>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    std::cout << "<";
    for(int i = 0; i < (n - 1); i++)
    {
        for(int i = 0; i < (k - 1); i++)
        {
            int container = q.front();
            q.pop();
            q.push(container);
        }  
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() << ">";
    return 0;
}