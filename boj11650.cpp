// boj 11650 좌표 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool comp(std::pair<int, int>a, std::pair<int, int>b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int main()
{
    int n; //  좌표의 개수 n
    std::cin >> n;
    std::vector<std::pair<int, int>> coordinate(n, {0, 0});
    for(int i = 0; i < n; i++)
    {
        int x_coordinate, y_coordinate;
        std::cin >> x_coordinate >> y_coordinate;
        coordinate[i] = {x_coordinate, y_coordinate};
    }
    std::sort(coordinate.begin(), coordinate.end(), comp);
    for(int i = 0; i < coordinate.size(); i++)
    {
        std::cout << coordinate[i].first << " " << coordinate[i].second;
        std::cout << "\n";
    }
    return 0;
}