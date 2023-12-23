#include <algorithm>
#include <iostream>

using namespace std;

namespace inversion{
    /*
     * Find numbers of pair ai, aj such that i < j => a[i] > a[j]
     * Trong trường hợp này chỉ số i bắt đầu từ 1, hãy sửa lại cho phù hợp!
     */

    int n;
    int *a;

    void input(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        a = new int [n+2];
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
    }


    int merge(int *nums, int left, int middle, int right){
        int inversion = 0;
        int left_e = middle - left + 1;
        int right_e = right - middle;
        int * aleft = new int [left_e + 1];
        int * aright = new int [right_e + 1];

        for (int i = 0; i < left_e; ++i){
            aleft[i] = nums[left + i];
        }

        for (int i = 0; i < right_e; ++i){
            aright[i] = nums[middle + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while ((i < left_e) && (j < right_e)){
            if (aleft[i] <= aright[j]){
                nums[k] = aleft[i];
                i++;

            }
            else{
                nums[k] = aright[j];
                j++;
                inversion += middle + 1 - (left + i);
            }
            k++;

        }

        while (i < left_e){
            nums[k] = aleft[i];
            i++;
            k++;
        }

        while (j < right_e){
            nums[k] = aright[j];
            j++;
            k++;
        }
        return inversion;
    }

    int mergeSort(int *nums, int left, int right){
        int inversion = 0;
        if (left >= right){
            return 0;
        }
        int middle = (left + right) / 2;
        inversion += mergeSort(nums, left, middle);
        inversion += mergeSort(nums, middle + 1, right);
        inversion += merge(nums, left, middle, right);
        return inversion;
    }

    void printResult(){
        cout << mergeSort(a, 1, n);
    }

}