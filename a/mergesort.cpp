#include <vector>
#include <algorithm>

using namespace std;

namespace mergesort{
    /*
     * Mergesort
     */
    void merge(vector<int>&nums, int left, int middle, int right){
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

    }

    void mergeSort(vector<int>&nums, int left, int right){
        if (left >= right){
            return;
        }
        int middle = (left + right) / 2;
        mergeSort(nums, left, middle);
        mergeSort(nums, middle + 1, right);
        merge(nums, left, middle, right);
    }

    void sort(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
    }
}