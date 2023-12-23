#include <stdio.h>

namespace rmq {
    // Bài toán range minimum query
    // M[j][i] là giá trị nhỏ nhất trong đoạn [i, i + 2^j]
#define MAX 1000005
    int n;
    int M[21][MAX];
    int a[MAX];
    int i, j, l;

    int log2(int pow){
        int res = 0;
        while (pow >>= 1){
            res++;
        }
        return res;
    }

    void init(){
        scanf("%d", &n);
        for (i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; ++i){
            M[0][i] = a[i];
        }
        for (j = 1; j < 21; ++j) {
            for (i = 0; i + (1 << (j)) <= n; ++i) {
                // M[j][i] = min(M[j - 1][i], M[j - 1][i + (1 << (j - 1))]);
                M[j][i] = (M[j - 1][i] < M[j - 1][i + (1 << (j - 1))]) ? M[j - 1][i] : M[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    int rmq(int &ii, int &jj){
        l = log2(jj - ii + 1);
        return (M[l][ii] < M[l][jj - (1 << l) + 1]) ? M[l][ii] : M[l][jj - (1 << l) + 1];
    }

}

//int main(){
//    int i, j, m;
//    rmq::init();
//    scanf("%d", &m);
//    int Q = 0;
//    for (int k = 0; k < m; ++k){
//        scanf("%d %d", &i, &j);
//        Q += rmq::rmq(i, j);
//    }
//    printf("%d", Q);
//}

