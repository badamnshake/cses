#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long int ans = 0;

    int cur = v[0];
    for(int i = 1; i < n; i++)
    {
        if(v[i] >= cur)
        {
            cur = v[i];
        }
        else
        {
            ans += cur - v[i];
        }
    }

    cout << ans << endl;

    return 0;
}