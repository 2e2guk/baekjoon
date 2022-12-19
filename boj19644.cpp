// boj 19644 좀비 떼가 기관총 진지에도 오다니
#include <iostream>
#include <deque>
#include <utility>
#include <climits>
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
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
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
    for(int i = 0; i < encampment_length; i++) // 선 사격, 후 덱 오른쪽 회전. 
    {
        if((zombies[0].health - K6.damage) > 0) // 지뢰를 사용해야 하는 경우. 
        {
            if(claymore.count > 0)
            {
                zombies[0].health -= claymore.damage;
                claymore.count--;
            }
        }
        else // 사격을 해야 하는 경우. 
        {
            for(int i = 0; i < K6.effective_range; i++)
            {
                zombies[i].health -= K6.damage;
            }
        }
        if(zombies[0].health > 0)
        {
            std::cout << "NO";
            return 0;
        }
        else // 덱을 오른쪽으로 회전시킨다. 
        {
            zombie container = zombies.front();
            zombies.pop_front();
            zombies.push_back(container);
        }
    }
    std::cout << "YES";
    return 0;
}
