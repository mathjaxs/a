#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<queue>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

namespace BFS{
    #define MAX 100000
    int n, m;

    void solve(vector<set<int>> list){
        bool * visited = new bool[n+1];
        memset(visited, false, n + 1);
        queue<int> q;

        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                q.push(i);
                visited[i] = true;

                while (!q.empty()){
                    int u = q.front();
                    q.pop();
                    cout << u << " ";
                    for (auto v: list[u]){
                        if (!visited[v]){
                            q.push(v);
                            visited[v] = true;
                        }

                    }
                }
            }
        }
    }
    vector<set<int>> list;
    void init(){
        FAST_IO;
        cin >> n >> m;
        list.resize(n + 1);
        for (int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            list[u].insert(v);
            list[v].insert(u);
        }
    }

}




