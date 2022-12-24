// boj 1931 회의실 배정
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(std::pair<int, int>a, std::pair<int, int>b) 
{
	if (a.second == b.second) 
    {
		return a.first < b.first;
	}
	else 
    {
		return a.second < b.second;
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> meetings(n, {0, 0}); // 시작 시간과 종료 시각이 0으로 초기화된 n개의 회의 정보
    std::vector<int> meetings_num;
    for(int i = 0; i < n; i++)
    {
        std::cin >> meetings[i].first >> meetings[i].second;
    }
    std::sort(meetings.begin(), meetings.end(), compare);
    int avaliable_meetings = 1, end_time = meetings.front().second;
    for(int i = 1; i < n; i++)
    {
        if(end_time <= meetings[i].first)
        {
            avaliable_meetings++;
            end_time = meetings[i].second;
        }
    }
    std::cout << avaliable_meetings;
    return 0;
}