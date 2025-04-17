#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int n, mx = 1e5 + 1;

    cin >> n;

    vector<int> coins(n);
    vector<bool> combs(mx, false);
    vector<bool> mine(mx, false);
    vector<bool> mt(mx, false);
    int ans = 0;
    combs[0] = true;

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for (auto c : coins)
    {
        mine = mt;
        for (int i = 0; i + c < mx; i++)
        {
            if(!combs[i] || mine[i]) continue;

            if(!combs[i + c])
            {
                mine[i + c] = true;
                combs[i + c] = true;
                ans += 1;
            }
        }
    }

    cout << ans << "\n";
    for (int i = 1; i < mx; i++)
    {
        if (combs[i])
            cout << i << " ";
    }


    return 0;
}