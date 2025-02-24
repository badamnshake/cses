#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main()
{

    int n;
    cin >> n;

    if (n > 1 && n <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }


    for(int i = n - 1; i > 0; i-= 2)
        cout << i << " ";

    for(int i = n; i > 0; i-= 2)
        cout << i << " ";


    return 0;
}