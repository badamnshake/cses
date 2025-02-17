#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    n += 1;

    vector<bool> a(n, 0);
    int x;

    for(int i = 2; i < n; i++)
    {
        cin >> x;
        a[x] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        if(a[i] == 0)
        {
            cout << i << endl;
            break;
        } 
    }

    return 0;
}