#include<iostream>
//#include<set>
#include<vector>
#include<algorithm>
#include<cstring>
#include <set>

#define MAX 100000
int n, m;
using namespace std;

void DFS(int node, vector<set<int>> list, bool *visited){
    cout << node << " ";
    visited[node] = true;
    for (auto v: list[node]){
        if (!visited[v]){
            DFS(v, list, visited);
        }
    }
}

//vector<pair<int, int>> Edge;
vector<set<int>> list;


int main(){

    cin >> n >> m;
    list.resize(n + 1);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        list[u].insert(v);
        list[v].insert(u);
    }
    bool * visited = new bool[n+1];
    memset(visited, false, n + 1);
    DFS(1, list, visited);
}
