#include <vector>
#include <iostream>
#include <queue>
#define mod 1000000007

using namespace std;

int main()
{
    int n, m, a, b, d;
    long long d1, d2;
    cin >> n;
    cin >> m;
    vector<vector<pair<int, long long>>> g(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        cin >> d;
        g[a - 1].push_back({b - 1, d});
    }

    vector<long long> dist(n, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});

    while (!q.empty())
    {

        a = q.top().second;
        d1 = q.top().first;
        q.pop();

        if (dist[a] != -1)
            continue;

        dist[a] = d1;

        for (auto p : g[a])
        {
            b = p.first;
            d2 = d1 + p.second;
            if (dist[b] == -1)
                q.push({d2, b});
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";

    return 0;
}
