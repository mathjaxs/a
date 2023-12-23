#include<algorithm>

using namespace std;

int main(){
    sort(l, r, greater < {Kiểu_phần_tử} >());
    sort(l, r, less < {Kiểu_phần_tử} >());
}

void sort_example(){

    int a[] = {5, 2, 10, 3, 1};

    sort(a, a + 4 + 1); // a = {1, 2, 3, 5, 10}.

    // In ra kết quả sắp xếp.
    cout << "Sắp xếp tăng dần: " << endl;
    for (int i = 0; i < 5; ++i)
        cout << a[i] << ' ';
    cout << endl;

    sort(a, a + 4 + 1, greater < int >()); // a = {10, 5, 3, 2, 1}.

    cout << "Sắp xếp giảm dần: " << endl;
    for (int i = 0; i < 4; ++i)
        cout << a[i] << ' ';

    return 0;

}

bool cmp({Tham_số_thứ_nhất}, {Tham_số_thứ_hai}){
    {Định_nghĩa_quan_hệ_so_sánh_giữa_hai_tham_số};
}

using namespace std;

bool cmp(int A, int B)
{
    return A > B;
}

int sort_with_custom()
{
    int a[] = {5, 2, 10, 3, 1};

    // Sắp xếp mảng.
    sort(a, a + 5, cmp); // a = {10, 5, 3, 2, 1}.

    // In ra kết quả sắp xếp.
    cout << "Kết quả sắp xếp: " << endl;
    for (int i = 0; i < 5; ++i)
        cout << a[i] << ' ';

    return 0;
}

void find_upper_bound(){
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = upper_bound(v.begin(), v.end(), 3);
    cout << *it << endl; // 4
}

void find_lower_bound(){
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = lower_bound(v.begin(), v.end(), 3);
    cout << *it << endl; // 3
}

void find_equal_range(){
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = equal_range(v.begin(), v.end(), 3);
    cout << *it.first << ' ' << *it.second << endl; // 3 4
}

void find_binary_search(){
    vector<int> v = {1, 2, 3, 4, 5};
    bool found = binary_search(v.begin(), v.end(), 3);
    cout << found << endl; // 1
}



