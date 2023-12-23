#include<iostream>
#include<algorithm>

using namespace std;

namespace coinchange{
    /*
     * Bài toán đổi tiền
     */
    int n;
    int amount;
    int *L;
    int *coins;

    void input(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        cin >> amount;
        coins = new int [n + 1];
        for (int i = 0; i < n; ++i){
            cin >> coins[i];
        }
        L = new int [amount + 1];
        L[0] = 0;
        for (int j=1; j<=amount; j++){
            L[j] = amount + 1;
        }
    }

    void solve(){
        for (int i = 0; i < n; ++i){
            for (int j = coins[i]; j <= amount; ++j){
                if (L[j] > L[j-coins[i]] + 1){
                    L[j] = L[j-coins[i]] + 1;
                }
            }
        }
    }

    void printResult(){
        if (L[amount] == amount + 1){
            cout << -1;
        }
        else{
            cout << L[amount];
        }
    }

}


