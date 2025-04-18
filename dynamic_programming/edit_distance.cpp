#include <vector>
#include <iostream>

#define mod 1000000007

using namespace std;

int main()
{
    string a, b;
    int n, m;
    cin >> a;
    cin >> b;
    
    n = a.size();
    m = b.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for(int r = 0; r <= n; r++)
        dp[r][0] = r;
    
    
    for(int c = 0; c <= m; c++)
        dp[0][c] = c;
    
    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= m; c++)
            dp[r][c] = min((a[r - 1] != b[c - 1]) + dp[r - 1][c - 1], (1 + min(dp[r - 1][c], dp[r][c - 1])));
        
    
    cout << dp[n][m];

    return 0;
}