#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

const int maxN = 1e6;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    int d;

    for (int i = 1; i <= n; i++)
    {
        d = i;
        while (d > 0)
        {
            if (d % 10 != 0)
                dp[i] = min(dp[i], 1 + dp[i - (d % 10)]);
            d /= 10;
        }
    }

    cout << dp[n] << endl;

    return 0;
}