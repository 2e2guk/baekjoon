// boj 5800 성적 통계
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int k, n; // 반의 개수 k, 각 반의 학생 수 n;
    std::cin >> k;
    std::vector<std::vector<int>> score(k);
    for(int i = 0; i < k; i++)
    {
        std::cin >> n;
        for(int j = 0; j < n; j++)
        {
            int input;
            std::cin >> input;
            score[i].push_back(input);
        }
    }
    for(int i = 0; i < k; i++)
    {
        std::cout << "Class " << (i + 1) << std::endl;
        std::sort(score[i].begin(), score[i].end());
        std::cout << "Max " << score[i].back() << ", Min " << score[i].front();
        std::vector<int> diff;
        for(int j = 0; j < score[i].size() - 1; j++)
        {
            int gap = score[i][j + 1] - score[i][j];
            diff.push_back(gap);
        }
        std::sort(diff.begin(), diff.end());
        std::cout << ", Largest gap " << diff.back() << std::endl;
        diff.clear();

    }
    return 0;
}