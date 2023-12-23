//#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

namespace dijiktra{
    // Bài toán tìm đường đi ngắn nhất với hệ số không âm
    // dijiktra::printResult(int t)
    #define MAX 100001
    #define ll long long
    #define INT_FAST64_MAX 9223372036854775807LL
    int n, m;
    vector<pair<int, int>> adj[MAX];
    vector<ll> d;

    void init(){
        // Nhập n đỉnh và m cạnh
        // m dòng còn lại nhập {u,v,c}
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].emplace_back(v,c);
        }
    }

    void solve(int s){
        d.clear();
        d.resize(n + 1, INT_FAST64_MAX);
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.emplace(0, s);
        while (!Q.empty()){
            pair<int, int> top = Q.top();
            Q.pop();
            int u = top.second;
            int kc = top.first;
            if (kc > d[u]) continue;
            for (auto it: adj[u]){
                int v = it.first;
                int w = it.second;
                if (d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    Q.emplace(d[v], v);
                }
            }
        }
    }

    void printResult(int t){
        printf("%d", d[t]);
    }

}

//int main(){
//    int s, t;
//    dijiktra::init();
//    cin >> s >> t;
//    dijiktra::solve(s);
//    dijiktra::printResult(t);
//}
