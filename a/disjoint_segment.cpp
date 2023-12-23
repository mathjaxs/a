#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace disjoint_segment{
    /*
     * Sử dụng thuật toán tham lam để giải, sắp xếp theo thời gian kết thúc trước
     */

    vector<pair<int, int>> s;
    int n;
    int tmp1, tmp2;
    int count;
    vector<pair<int, int>> solution;

    void input(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> tmp1 >> tmp2;
            s.push_back({tmp1, tmp2});
        }
    }

    void solve(){
        sort(s.begin(), s.end(), [](const pair<int,int>& a, const pair<int,int>& b){
//            if (a.second == b.second){
//                return a.first > b.first;
//            }
            return a.second < b.second;
        });
        int last = s[0].second;
        solution.push_back({s[0].first, s[0].second});
        for (int i = 1; i < n; ++i){
            if (last < s[i].first){
                solution.push_back({s[i].first, s[i].second});
                last = s[i].second;
            }
        }
    }

    void printResult(){
        cout << solution.size() << endl;
    }

    void printTrace(){
        for (int i = 0; i < n; ++i){
            cout << solution[i].first << " " << solution[i].second << endl;
        }
    }
}
