#include <vector>
#include <iostream>

#define mod 1000000007

using namespace std;

pair<int, int> dfs(int v, vector<int> &vis, vector<vector<int>> &g)
{
    pair<int, int> loop;
    for (auto u : g[v])
    {
        if (u == vis[v])
            continue;

        if (vis[u] != -1)
            return {u, v};

        vis[u] = v;

        loop = dfs(u, vis, g);

        if (loop.first != -1)
            return loop;
    }

    return {-1, -1};
}

int main()
{
    int n, m, t1, t2;

    cin >> n;
    cin >> m;

    vector<vector<int>> g(n);
    vector<int> vis(n, -1);

    for (int i = 0; i < m; i++)
    {
        cin >> t1;
        cin >> t2;
        g[t1 - 1].push_back(t2 - 1);
        g[t2 - 1].push_back(t1 - 1);
    }

    pair<int, int> loop;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != -1)
            continue;

        vis[i] = i;
        loop = dfs(i, vis, g);

        if (loop.first != -1)
            break;
    }

    if (loop.first == -1)
    {

        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> looparr;

    looparr.push_back(loop.first);

    for (int i = loop.second; i != loop.first; i = vis[i])
        looparr.push_back(i);

    looparr.push_back(loop.first);

    cout << looparr.size() << "\n";

    for (int i = 0; i < looparr.size(); i++)
        cout << looparr[i] + 1 << " ";

    

    return 0;
}
