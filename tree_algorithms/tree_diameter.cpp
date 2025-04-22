#include <iostream>
#include <vector>

using namespace std;

pair<int, int> dfs(int p, int v, int d, vector<vector<int>> &tree)
{
    pair<int, int> ans = {d, v};
    pair<int, int> td;

    for (int u : tree[v])
        if (u != p)
        {
            td = dfs(v, u, d + 1, tree);
            if (td.first > ans.first)
                ans = td;
        }

    return ans;
}

int main()
{
    int n, a, b;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }
    
    auto ans = dfs(-1, 0, 0, tree);
    ans = dfs(-1, ans.second, 0, tree);
    
    cout << ans.first << "\n";
    

    return 0;
}