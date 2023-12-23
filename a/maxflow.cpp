#include <cstring>
#include <queue>
#include <iostream>


using namespace std;

namespace maxflow{

#define MAX 10
    int graph[MAX][MAX];
    int n, m, s, t;
    #define INT_FAST32_MAX 2147483647

    bool bfs(int (&rGraph)[MAX][MAX], int s, int t, int parent[]) {
        queue<int> q;
        bool visited[MAX];
        memset(visited, 0, sizeof(visited));
        q.push(s);
        visited[s] = true;
        parent[s] = -1;
        int u;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int v = 0; v < MAX; ++v) {
                if (!visited[v] && rGraph[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return visited[t];
    }

    int fordFulkerson(int (&graph)[MAX][MAX], int s, int t) {
        int u, v;
        int rGraph[MAX][MAX];
        int parent[MAX];
        int maxFlow = 0;
        for (u = 0; u < MAX; ++u){
            for (v = 0; v < MAX; ++v){
                rGraph[u][v] = graph[u][v];
            }
        }
        while (bfs(rGraph, s, t, parent)) {
            int path_flow = INT_FAST32_MAX;
            v = t;
            while (v != s){
                u = parent[v];
                path_flow = path_flow > rGraph[u][v] ? rGraph[u][v] : path_flow;
                v = parent[v];
            }
            v = t;
            while (v != s){
                u = parent[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
                v = parent[v];
            }
            maxFlow += path_flow;
        }
        return maxFlow;
    }

    void init(){
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> n >> m; // n: số đỉnh, m: số cạnh
        cin >> s >> t; // s: đỉnh đầu, t: đỉnh cuối
        int u, v, c;
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; ++i){
            cin >> u >> v >> c;
            graph[u][v] = c;
        }
    }

    void printResult(){
        cout << fordFulkerson(graph, s, t);
    }
}

//int main(){
//    maxflow::init();
//    maxflow::printResult();
//}
