#include <vector>
#include <algorithm>
#include <iostream>
#define mod 1000000007

using namespace std;

vector<int> u;

int fin(int a)
{
    if(u[a] == a)
        return a;
    return u[a] = fin(u[a]);
}


void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);
    if(a != b)
        u[b] = a;
}



int main()
{
    int n, m, a, b, ans = -1;
    vector<int> arr;
    cin >> n;
    cin >> m;

    u = vector<int>(n);

    for(int i = 0; i < n; i++)
        u[i] = i;

    for(int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        uni(a - 1, b - 1);
    }

    for(int i = 0; i < n; i++)
    {
        u[i] = fin(i);
    }

    sort(u.begin(), u.end());
    

    for(int i = 0; i < n; i++)
    {
        if(i != 0 && u[i] == u[i - 1]) continue;
        ans += 1;
        arr.push_back(u[i] + 1);
    }

    cout << ans << "\n";

    for(int i = 1; i <= ans; i++)
    {
        cout << arr[i] << " " << arr[i - 1] << "\n";
    }



    return 0;
}