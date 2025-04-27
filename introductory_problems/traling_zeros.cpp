#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    
    long long a = 5;
    long long b = 2;
    long long n;

    cin >> n;
    
    long long ap = 0;
    long long bp = 0;
    
    while(a <= n)
    {
        ap += n / a;
        a *= 5;
    }

    while(b <= n)
    {
        bp += n / b;
        b *= 2;
    }
    
    cout << min(ap, bp) << endl;

    return 0;
}