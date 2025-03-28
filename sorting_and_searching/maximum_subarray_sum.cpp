#include <vector>
#include <iostream>

#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int mx = -2000000000;
    long long int cur = 0;

    for(int i = 0; i < n; i++)
    {
        cur += a[i];
        mx = max(cur, mx);

        if(cur < 0)
        {
            cur = 0;
        }
    }

    cout << mx << endl;

    return 0;
}