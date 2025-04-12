#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int main()
{
    int n,  m, t1, t2, v;
    
    cin >> n;
    cin >> m;
    
    vector<vector<int>> g(n);
    vector<int> side(n, -1);
    
    for(int i = 0; i < m; i++)
    {
        cin >> t1;
        cin >> t2;
        g[t1 - 1].push_back(t2 - 1);
        g[t2 - 1].push_back(t1 - 1);
    }
    
    queue<int> q;

    bool not_bipart = false;
    
    for(int t = 0; t < n; t++)
    {
        if(not_bipart) break;
        // if already vissited
        if(side[t] > -1) continue;
        q.push(t);
        side[t] = 0;
        
        while(!q.empty())
        {
            v = q.front();
            q.pop();
            
            for(auto u: g[v])
            {
                if(side[u] == -1)
                {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                }
                else
                {
                    if(side[u] == side[v])
                    {
                        not_bipart = true;
                        break;
                    }
                }
            }
        }
        
    }
    
    
    if(not_bipart) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++)
        cout << side[i] + 1 << " ";
    

    cout << "\n";
    

    return 0;
}