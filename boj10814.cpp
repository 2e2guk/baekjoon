// boj 10814 나이순 정렬
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

bool comp(std::tuple<int, std::string, int> &t1, std::tuple<int, std::string, int> &t2)
{
    if(std::get<0>(t1) == std::get<0>(t2))
        return std::get<2>(t1) < std::get<2>(t2);
    else
        return std::get<0>(t1) < std::get<0>(t2);
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, std::string, int>> subscriber(n, {0, "abcd", 0});
    for(int i = 0; i < n; i++)
    {
        int input_age;
        std::string input_name;
        std::cin >> input_age >> input_name;
        subscriber[i] = std::make_tuple(input_age, input_name, i + 1);
    }
    std::sort(subscriber.begin(), subscriber.end(), comp);
    for(int i = 0; i < subscriber.size(); i++)
    {
        std::cout << std::get<0>(subscriber[i]) << " " << std::get<1>(subscriber[i]) << "\n";
    }
    return 0;
}