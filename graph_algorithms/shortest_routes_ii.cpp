#include <vector>
#include <iostream>
#include <climits>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{

    int n, m, q, a, b;
    long long d;

    cin >> n;
    cin >> m;
    cin >> q;

    vector<vector<long long>> g(n, vector<long long>(n, -1));

    for (int i = 0; i < n; i++)
        g[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        cin >> d;

        if(g[a - 1][b - 1] == -1)
            g[a - 1][b - 1] = d;
        else  
            g[a - 1][b - 1] = min(d, g[a - 1][b - 1]);

        g[b - 1][a - 1] = g[a - 1][b - 1];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (
                    g[i][k] != -1 && g[k][j] != -1 && (g[i][j] == -1 || g[i][k] + g[k][j] < g[i][j]))
                {
                    g[i][j] = g[i][k] + g[k][j];
                    g[j][i] = g[i][j];
                }
            }
        }
    }

    vector<long long> queries(q, -1);

    for (int i = 0; i < q; i++)
    {
        cin >> a;
        cin >> b;
        queries[i] = g[a - 1][b - 1];
    }

    for (int i = 0; i < q; i++)
    {

        cout << queries[i] << "\n";
    }

    return 0;
}