#include <iostream>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
namespace cbus{
    /*
     * Bài toán cbus trên programming daotao ai
     * Giải bằng nhánh cận
     */
    bool visited[25] = {0};
    int load = 0;
    int n, k;
    int b;
    int c[25][25];
    int sol = 100000000;
    int cur = 0;
    int c_min = 1e9;
    int x[25];
    int s[25];
    int tmp;


    void input(){
        visited[0] = true;
        FAST_IO;
        cin >> n >> k;
        b = 2 * n;
        for (int i = 0; i <= b; ++i){
            for (int j = 0; j <= b; ++j){
                cin >> c[i][j];
                if (i != j){
                    c_min = min(c_min, c[i][j]);
                }

            }
        }
    }

    bool check(int i){
        if (visited[i]) return false;
        if (i > n) return visited[i - n];
        return load < k;
    }

    void backtrack(int i, int p){
        if (cur + c_min * (b - i) > sol){
            return;
        }
        if (i == b + 1){
    //        cur += c[p][0];  // ya fuck cur is global variable
            tmp = cur + c[p][0];
            if (tmp < sol){
                sol = tmp;
                for (int j = 1; j <= b; ++j){
                    s[j] = x[j];
                }
            }

        }
        else {
            for (int j = 1; j <= b; ++j){
                if (check(j)){
                    cur += c[p][j];
                    x[i] = j;
                    visited[j] = true;

                    if (j > n) {
                        load--;
                    }
                    else {
                        load++;
                    }

                    backtrack(i+1, j);

                    if (j > n) {
                        load++;
                    }
                    else {
                        load--;
                    }
                    visited[j] = false;
                    cur -= c[p][j];

                }
            }
        }
    }

    void solve(){
        backtrack(1, 0);
    }

    void print_length(){
        // In độ dài đường đi ngắn nhất
        cout << sol << endl;
    }

    void print_route(){
        // In đường đi
        for (int i = 1; i <= b; ++i){
            cout << s[i] << " ";
        }
        cout << endl;
    }
}
