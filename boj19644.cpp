// boj 19644 좀비 떼가 기관총 진지에도 오다니
//2022.12.19, TLE
#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <iterator>
#include <climits>

struct zombie // 좀비 구조체. 살아 있는지를 나타내는 변수, 체력을  멤버 변수로 갖는다. 
{
    bool is_alive = false;
    int health = 0;
};
struct machine_gun // 기관총 구조체. 사격 횟수를 나타내는 fire_num과, 유효 사거리, 데미지를 멤버로 갖는다. 
{
    int effective_range;
    int damage;
};
struct KM_18A1 // 수평세열지향성지뢰 구조체. 데미지는 INT_MAX으로 초기화한다. 
{
    int damage = INT_MAX;
    int count = 0;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int encampment_length, effective_range, damage, cammo;
    std::cin >> encampment_length;
    // 좀비를 담을 deque 생성
    std::deque<zombie> zombies;
    // 기관총 객체를 만들고, 유효 사거리와 데미지를 초기화한다. 
    std::cin >> effective_range >> damage;
    machine_gun K6;
    K6.effective_range = effective_range;
    K6.damage = damage;
    // 수평세열지향성지뢰 객체를 만들고, 갯수를 초기화한다. 
    std::cin >> cammo;
    KM_18A1 claymore;
    claymore.count = cammo;
    // 좀비를 생성한다.
    for(int i = 0; i < encampment_length; i++)
    {
        int zombie_health;
        std::cin >> zombie_health;
        zombies.push_back({true, zombie_health});
    }
    std::vector<int> fire_num; // 사격 횟수를 전달받을 vector 선언. 
    int max_fire_num = K6.effective_range; // 사격만 한다는 가정 하에 좀비들이 받을 수 잇는 최대 사격 횟수.
    for(int i = 0; i < zombies.size(); i++)
    {
        if(i < max_fire_num)
        {
            fire_num.push_back(i + 1);
        }
        if(i >= max_fire_num)
        {
            fire_num.push_back(max_fire_num);
        }
    }
    for(int i = 0; i < zombies.size(); i++) // 좀비들이 받는 사격 횟수를 출력한다. 
    {
        if(zombies[i].health - (fire_num[i] * K6.damage) > 0) // 사격으로는 좀비가 죽지 않는 경우. 
        {
            if(claymore.count > 0) // claymore 사용 가능한 경우.
            {
                fire_num[i] = -1; // 사격 횟수가 -1인 경우는, claymore를 사용해야 하는 경우이다. 
                for(int j = 1; j < K6.effective_range; j++) // claymore를 터트리면, 사격이 불가능해지므로 사격 횟수가 줄어든다.
                {
                    fire_num[i + j] -= 1;
                }
                claymore.count--;
            }
            else // claymore 사용 불가능한 경우. 
            {
                std::cout << "NO";
                return 0;
            }
        }
    }
    for(int i = 0; i < zombies.size(); i++) // 좀비 무리에게 공격을 진행한다. 
    {
        if(fire_num[i] == -1)
            zombies[i].health -= claymore.damage;
        else
            zombies[i].health -= (fire_num[i] * K6.damage);
    }
    for(int i = 0; i < zombies.size(); i++) // 좀비의 체력으로 생존 여부를 판단한다. 
    {
        if(zombies[i].health > 0)
        {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}
