#include <vector>
#include <iostream>
#include <climits>
#define mod 1000000007

using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

struct Edge
{
    int a, b;
    ll d;
};

void dfs(int i, vector<bool>& v, vector<vector<int>>& g)
{
    v[i] = true;

    for(auto u: g[i])
        if(!v[u]) dfs(u, v, g);
}

int main()
{
    int n, m, a, b;
    ll d;
    cin >> n;
    cin >> m;

    vector<Edge> edges(m);
    
    vector<vector<int>> g(n + 1), gr(n + 1); 
    vector<bool> v(n + 1, false), vr(n + 1, false); 

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        cin >> d;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].d = 0-d;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    dfs(1, v, g);
    dfs(n, vr, gr);


    vector<ll> dst(n + 1, INF);
    dst[1] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (Edge e : edges)
        {
            if (dst[e.a] != INF && dst[e.b] > dst[e.a] + e.d)
            {

                if(i == n && v[e.b] && vr[e.b]) 
                {
                    cout << "-1\n";
                    return 0;
                }
                dst[e.b] = dst[e.a] + e.d;
                
            }
        }
    }
    


    cout << 0 - dst[n] << endl;

    return 0;
}