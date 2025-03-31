#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int n, x, ans = 0;
    cin >> n;
    cin >> x;
    vector<int> price(n), pages(n), dp(x + 1, -1);

    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    dp[0] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = x; i >= price[k]; i--)
        {
            if (dp[i - price[k]] >= 0 && dp[i - price[k]] + pages[k] > dp[i])
                dp[i] = dp[i - price[k]] + pages[k];
            
        }
    }
    

    for(auto d: dp)
    {
        ans = max(ans, d);
    }

    cout << ans << endl;

    return 0;
}