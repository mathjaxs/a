#include <iostream>
#include <set>

using namespace std;

struct cmp
{
    bool operator() (int x, int y)
    {
        return x > y;
    }
};

int main()
{
    int arr[] = {1, 5, 2, 4, 3};
    set < int, cmp > integers(arr, arr + 5); // integers = {5, 4, 3, 2, 1}.
    int x = 1;

    // find
    integers.find(x);

    // erase
    integers.erase(id);

    // count
    integers.count(key);

    // lower_bound
    integers.lower_bound(key);

    // upper_bound
    integers.upper_bound(key);

    // count
    integers.count(key);	


    return 0;
}
