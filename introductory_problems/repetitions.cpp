#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main()
{
    string s;

    cin >> s;

    int n = s.size();
    int mx = 1;
    int cur = 1;

    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
        {
            cur += 1;
        }
        else
        {
            cur = 1;
        }
        mx = max(cur, mx);
    }

    cout << mx << endl;

    return 0;
}