// boj 24446 알고리즘 수업 - 너비 우선 탐색 3
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

auto BFS(vector<vector<int>> graph, bool *visited, int start, vector<int> vertex_depth) // BFS 순회를 하는 함수. 각 정점의 깊이를 반환한다. 
{
    int depth = 0;
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    vertex_depth[start] = depth;
    while(!queue.empty())
    {
        int current_vertex = queue.front();
        queue.pop();
        for(int i = 0; i < graph[current_vertex].size(); i++)
        {
            int next = graph[current_vertex][i];
            if(visited[next] == false)
            {
                vertex_depth[next] = vertex_depth[current_vertex] + 1; // 현재 vertex의 높이보다 1 더 깊음
                queue.push(next);
                visited[next] = true;
            }
        }
    }
    vertex_depth.erase(vertex_depth.begin());
    return vertex_depth;
}

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> graph(N + 1);
    vector<int> vertex_depth(N + 1, -1);
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
    auto bfs_vertex_depth = BFS(graph, visited, R, vertex_depth);
    for(auto v : bfs_vertex_depth)
    {
        cout << v << "\n";
    }
    return 0;
}