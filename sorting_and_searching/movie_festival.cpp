#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

#define mod 1000000007

using namespace std;

int main()
{
    int n;

    cin >> n;

    map<int, int> m;

    vector<int> l(n);
    int s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cin >> l[i];

        if (m.find(l[i]) == m.end())
        {
            m[l[i]] = s;
        }
        else
        {
            m[l[i]] = max(m[l[i]], s);
        }
    }

    sort(l.begin(), l.end());

    int ans = 1;
    int t = l[0];

    for (int i = 1; i < n; i++)
    {
        if (m[l[i]] >= t)
        {
            t = l[i];
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}