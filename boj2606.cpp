//boj2606 바이러스
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;
template<typename T>
struct Edge
{
    unsigned src;
    unsigned dst;
    T weight;
};
template<typename T>
class Graph
{
public:
    // N개의 정점으로 구성된 그래프
    Graph(unsigned N) : V(N){}
    // 그래프의 정점 개수 반환
    auto vertices() const {return V;}
    // 전체 에지 리스트 반환
    auto& edges() const {return edge_list;}
    //정점 v에서 나가는 모든 에지를 반환
    auto edges(unsigned v) const
    {
        vector<Edge<T>> edges_from_v;
        for(auto&e : edge_list)
        {
            if(e.src == v)
                edges_from_v.emplace_back(e);
        }
        return edges_from_v;
    }
    void add_edge(Edge<T>&& e)
    {
        //에지 양 끝 정점 ID가 유효한지 검사. 
        if(e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
            edge_list.emplace_back(e);
        else 
            cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
    }
private:
    unsigned V; // 정점 개수
    vector<Edge<T>> edge_list;
};
template<typename T>
auto create_graph(int n, int link) //  그래프 객제를 생성한다. 
{
    Graph<T> G(n);
    map<unsigned, unsigned> edge_map; 
    for(int i = 0; i < link; i++)
    {
        unsigned com1, com2;
        cin >> com1 >> com2;
        edge_map.insert({com1, com2});
        G.add_edge(Edge<T>{com1, com2});
        G.add_edge(Edge<T>{com2, com1}); // com1, com2 를 양쪽으로 전부 연결하기 위해서 add_edge 함수를 두번 호출한다. 
    }
    return G;
}
template<typename T>
auto BFS(const Graph<T>& G, unsigned start)
{
    queue<unsigned> queue;
    set<unsigned> visited;
    vector<unsigned> visit_order;
    queue.push(start);
    while(!queue.empty())
    {
        auto current_vertex = queue.front();
        queue.pop();
        // 현재 정점을 이전에 방문하지 않은 경우.
        if(visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);
            for(auto& e : G.edges(current_vertex))
            {
                // 인접한 정점 중에서 방문하지 않은 정점이 있다면 큐에 추가. 
                if(visited.find(e.dst) == visited.end())
                {
                    queue.push(e.dst);
                }
            }
        }
    }
    return visit_order;
}
int main()
{
    using T = unsigned;
    int n, link;
    cin >> n >> link;
    auto G = create_graph<T>(n, link);
    auto visit_order = BFS(G, 1);
    cout << (visit_order.size() - 1) << endl; /// 1번 컴퓨터를 제외하고 감염된 컴퓨터의 수를 구하는 것이므로 1을 뺀다. 
}
