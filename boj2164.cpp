// boj2164 카드 2
#include <iostream>
#include <queue>

int main()
{
    int n;
    std::cin >> n;
    std::queue<int> card;
    for(int i = 1; i <= n; i++)
    {
        card.push(i);
    }
    while(!card.empty())
    {
        if(card.size() == 1)
        {
            std::cout << card.front();
            return 0;
        }
        if(card.size() == 2)
        {
            card.pop();
            std::cout << card.front();
            return 0;
        }
        card.pop();
        int container = card.front();
        card.pop();
        card.push(container);
    }
}