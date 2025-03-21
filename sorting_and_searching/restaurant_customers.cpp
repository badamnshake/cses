// https://cses.fi/problemset/task/1619

#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cur = 0;
    int mx = 0;

    vector<pair<int, int>> v(2 * n);

    pair<int, int> p;
    for (int i = 0; i < 2 * n; i += 2)
    {
        cin >> p.first;
        p.second = 1;
        v[i] = p;

        cin >> p.first;
        p.second = -1;
        v[i + 1] = p;
    }

    sort(v.begin(), v.end());

    for (auto x : v)
    {
        cur += x.second;
        mx = max(cur, mx);
    }

    cout << mx << endl;

    return 0;
}
