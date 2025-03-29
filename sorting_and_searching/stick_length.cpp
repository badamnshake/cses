#include <vector>
#include <iostream>
#include <algorithm>

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
    sort(a.begin(), a.end());

    int m = n / 2;
    m = a[m];
    long int ans = 0;

    for(auto x: a)
    {
        ans += abs(x - m);
    }
    cout << ans << endl;



    return 0;
}