using namespace std;

// Quy định phép so sánh của map là khóa giảm dần.
struct cmp
{
    bool operator() (char a, char b)
    {
        return a > b;
    }
};

signed main()
{
    map < char, int, cmp > mymap;
    mymap.insert({'a', 1});
    mymap.insert({'b', 2});
    mymap.insert({'c', 3});

    for (auto e: mymap)
        cout << e.first << ' ' << e.second << endl;

    return 0;
}
