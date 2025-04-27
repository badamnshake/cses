#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int t;
    long long a, b;

    cin >> t;

    vector<bool> ans(t);

    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;

        if(b > a) 
            swap(a, b);

        if((a + b) % 3 == 0 && b * 2 >= a)
        {
            ans[i] = 1;
        }
        else ans[i] = 0;
    }
    
    for(int i = 0; i < t; i++)
    {
        if(ans[i] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}