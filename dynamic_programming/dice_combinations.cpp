/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7
*/

#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<long long int> t(n + 1, 0);
    t[0] = 1;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            if(i - j < 0) continue;

            t[i] = (t[i] + t[i - j]) % mod; 
        }
    }
    cout << t[n] << "\n";


    return 0;

}