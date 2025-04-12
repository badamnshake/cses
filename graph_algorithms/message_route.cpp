#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int main()
{
    int n,  m, t1, t2;
    
    cin >> n;
    cin >> m;
    
    vector<vector<int>> g(n);
    
    vector<int> p(n, -1);
    p[0] = 0;
    
    for(int i = 0; i < m; i++)
    {
        cin >> t1;
        cin >> t2;
        g[t1 - 1].push_back(t2 - 1);
        g[t2 - 1].push_back(t1 - 1);
    }
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        t1 = q.front();
        q.pop();
        
        
        for(auto u: g[t1])
        {
            if(p[u] != -1) continue;
            p[u] = t1;
            q.push(u);
        }
    }
    
    if(p[n - 1] == -1 ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    
    vector<int> path;
    
    for(int v = n - 1; v != 0; v = p[v])
        path.push_back(v);

    path.push_back(0);

    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";

    for(auto x: path)
        cout << x + 1 << " ";

    cout << "\n";

    return 0;
}