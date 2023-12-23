//#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>

#define MAX 100000
int n, m;
using namespace std;

namespace halminton{
    // Kiểm tra đồ thị có halminton hay không
    // printResult() trả kết quả

    vector<vector<int>> list;
    bool* visited = new bool[n + 1];

    bool halmilton_check(int node, bool visited[], int cnt){
        if (cnt == n){
            return true;
        }
        for (int i = 0; i < list[node].size(); i++){
            int v = list[node][i];
            if (!visited[v]){
                visited[v] = true;
                if (halmilton_check(v, visited, cnt + 1)){
                    return true;
                }
                visited[v] = false;
            }
        }
        return false;
    }

    void init(){
        // Nhập đồ thị n đỉnh m cạnh
        memset(visited, false, n + 1);
        scanf("%d %d", &n, &m);
        list.clear();
        list.resize(n + 1);
        for (int i = 1; i <= m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            list[u].push_back(v);
            list[v].push_back(u);
        }
    }

    void printResult(){
        printf("%d\n", halmilton_check(1, visited, 0));
    }
}

