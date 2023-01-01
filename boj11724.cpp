// boj 11724 연결 요소의 개수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void create_Graph(int M, vector<int> *G) // 인접 행렬로 그래프 표현하기
{
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void BFS(vector<int> *G, bool *check, int start) // BFS 구현
{
    queue<int> q;
    check[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();

        for (int i = 0; i < G[current_vertex].size(); i++)
        {
            int next = G[current_vertex][i];
            if (!check[next]) // 인접한 정점을 방문하지 않은 경우, 큐에 정점을 추가한다. 
            {
                q.push(next);
                check[next] = true;
            }
        }
    }
}
int connected_component_num(int N, vector<int> *G) // 연결 요소의 개수를 구하는 함수
{
    bool check[N + 1] = {false};
    int connected_element_num = 0;

    for (int i = 1; i <= N; i++)
    {
        if (check[i]) // 만약, 현재 정점을 방문한 경우, BFS탐색을 하지 않는다. 
            continue;

        BFS(G, check, i); // BFS탐색을 할 때마다, 연결 요소의 개수를 하나씩 늘려준다. 
        connected_element_num++;
    }
    return connected_element_num;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> G[N + 1]; // 인접 행렬로 구성된 그래프
    create_Graph(M, G);
    cout << connected_component_num(N, G);
}