// boj 19644 좀비 떼가 기관총 진지에도 오다니
// 안 됨.-2022/12/18
#include <iostream>
#include <deque>
#include <utility>
#include <climits>
#include <vector>
#include <stack>

struct kilo_hecto // 킬로와 헥토 구조체. 좀비가 queue[0]에 도착하면, 죽는다. 
{
    int is_alive = true;
};
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
    int usage = 0; // 지뢰를 사용한 경우 usage를 올린다. 
};
int main()
{
    int encampment_length, effective_range, damage, cammo;
    std::cin >> encampment_length;
    //일병 이강욱 등장
    kilo_hecto private_soldier_dlrkddnr;
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
    // 각 index별 좀비가 사격을 몇 회 당하는지 결정할 vector 선언. 
    std::vector<int> fire_num;
    if(K6.effective_range > zombies.size()) // 사격 범위보다 좀비의 수가 더 적은 경우. 그냥 좀비의 현재 (index + 1) 을 기관총 데미지에 곱해서 빼면 된다. 
    {
        for(int i = 0; i < zombies.size(); i++)
        {
            fire_num.push_back(i + 1);
        }
        for(int i = 0; i < fire_num.size(); i++)
        {
            if((zombies[i].health - (fire_num[i] * K6.damage) > 0) && claymore.count > 0) // 지뢰를 사용할 수 있는 경우. 
            {
                zombies[i].health -= claymore.damage;
                claymore.count--;
                claymore.usage++;
            }
            else // 지뢰를 사용할 수 없는 경우.
            {
                if(claymore.usage <= 0)
                {
                    zombies[i].health -= (fire_num[i] * K6.damage);
                    if(zombies[i].health > 0)
                    {
                        std::cout << "NO";
                        return 0;
                    }
                }
                else if(claymore.usage > 0)
                {
                    if(fire_num[i] < K6.effective_range)
                    {
                        zombies[i].health -= ((fire_num[i] - claymore.usage) * K6.damage);
                        if(zombies[i].health > 0)
                        {
                            std::cout << "NO";
                            return 0;
                        }
                    }
                    else
                    {
                        zombies[i].health -= (fire_num[i] * K6.damage);
                        if(zombies[i].health > 0)
                        {
                            std::cout << "NO";
                            return 0;
                        }
                    }
                }
            }
        }
        std::cout << "YES";
        return 0;
    }
    else if(K6.effective_range < zombies.size()) // 사격 범위보다 좀비의 수가 더 많은 경우. 
    {
        int max_fire_count = K6.effective_range;
        int fire_count = 1;
        for(int i = 0; i < zombies.size(); i++)
        {
            if(fire_count < max_fire_count)
            {
                fire_num.push_back(fire_count);
                fire_count++;
            }
            if(fire_count == max_fire_count)
            {
                fire_num.push_back(fire_count);
            }
        }
        for(int i = 0; i < fire_num.size(); i++)
        {
            if((zombies[i].health - (fire_num[i] * K6.damage) > 0) && claymore.count > 0) // 지뢰를 사용할 수 있는 경우. 
            {
                zombies[i].health -= claymore.damage;
                claymore.count--;
            }
            if(zombies[i].health - (fire_num[i] * K6.damage) < 0)
            {
                if(claymore.usage <= 0)
                {
                    zombies[i].health -= (fire_num[i] * K6.damage);
                    if(zombies[i].health > 0)
                    {
                        std::cout << "NO";
                        return 0;
                    }
                }
                else if(claymore.usage > 0)
                {
                    if(fire_num[i] < K6.effective_range)
                    {
                        zombies[i].health -= ((fire_num[i] - claymore.usage) * K6.damage);
                        if(zombies[i].health > 0)
                        {
                            std::cout << "NO";
                            return 0;
                        }
                    }
                    else
                    {
                        zombies[i].health -= (fire_num[i] * K6.damage);
                        if(zombies[i].health > 0)
                        {
                            std::cout << "NO";
                            return 0;
                        }
                    }
                } 
            }
        }
        std::cout << "YES";
        return 0;
    }
}
