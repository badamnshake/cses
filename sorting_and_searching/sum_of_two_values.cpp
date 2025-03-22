
#include <map>
#include <iostream>
#include <algorithm>

#define mod 1000000007

using namespace std;

int main()
{
    int n, t, target;
    cin >> n;
    cin >> target;
    
    map<int, int> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> t;

        

        if(target > t && m.find(target - t) != m.end())
        {
            cout << m[target - t] << " " << i << "\n";
            return 0;
        }

        m[t] = i;
    }
    

    cout << "IMPOSSIBLE\n" << endl;
    

    return 0;
}