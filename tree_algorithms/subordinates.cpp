#include <vector>
#include <iostream>

using namespace std;

int children(int v, vector<vector<int>> &adj, vector<int> &memo);

int main()
{
    int n, t;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> sub(n, -1);

    for (int i = 1; i < n; i++)
    {
        cin >> t;
        adj[--t].push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (sub[i] == -1)
            children(i, adj, sub);

    for (int i = 0; i < n; i++)
        cout << sub[i] << " ";

    return 0;
}

int children(int v, vector<vector<int>> &adj, vector<int> &memo)
{
    if (adj[v].size() == 0)
        memo[v] = 0;

    if (memo[v] != -1)
        return memo[v];

    int ans = adj[v].size();

    for (auto u : adj[v])
        ans += children(u, adj, memo);

    return memo[v] = ans;
}