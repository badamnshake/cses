#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

vector<int> dsta;
vector<int> dstb;

int dfs(int p, int v, int d, vector<vector<int>> &t, vector<int> &dst)
{
    dst[v] = d;
    int mxd = -1;

    for (int u : t[v])
    {
        if (u == p)
            continue;
        int x = dfs(v, u, d + 1, t, dst);
        if (mxd == -1 || dst[x] > dst[mxd])
            mxd = x;
    }

    return mxd == -1 ? v : mxd;
}

int main()
{
    int n, a, b;
    cin >> n;

    vector<vector<int>> tr(n);
    dsta = vector<int>(n, 0);
    dstb = vector<int>(n, 0);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        --a;
        --b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    a = dfs(0, 0, 0, tr, dsta);
    b = dfs(a, a, 0, tr, dsta);
    dfs(b, b, 0, tr, dstb);

    for (int i = 0; i < n; i++)
    {
        cout << max(dsta[i], dstb[i]) << " ";
    }

    return 0;
}