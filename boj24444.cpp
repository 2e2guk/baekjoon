// boj 24444 알고리즘 수업 - 너비 우선 탐색 1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

auto BFS(vector<vector<int>> graph, bool *visited, int start, vector<int> visit_order) // BFS 순회를 하는 함수. 각 정점의 방문 순서를 출력한다. 
{
    int order = 1;
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    visit_order[start] = order;
    while(!queue.empty())
    {
        int current_vertex = queue.front();
        queue.pop();
        for(int i = 0; i < graph[current_vertex].size(); i++)
        {
            int next = graph[current_vertex][i];
            if(visited[next] == false)
            {
                order++;
                visit_order[next] = order;
                queue.push(next);
                visited[next] = true;
            }
        }
    }
    visit_order.erase(visit_order.begin());
    return visit_order;
}

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> graph(N + 1);
    vector<int> visit_order(N + 1, 0);
    bool visited[N + 1] = {false};
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for(int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    auto bfs_visit_order = BFS(graph, visited, R, visit_order);
    for(auto v : bfs_visit_order)
    {
        cout << v << "\n";
    }
    return 0;
}