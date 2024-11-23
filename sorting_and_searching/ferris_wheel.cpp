
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    // num of children
    int n;
    cin >> n;

    // weight of gondola
    int x;
    cin >> x;

    vector<int> p(n);

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int i = 0;
    int j = n - 1;
    int a = 0;

    while(i <= j)
    {
        if(p[i] + p[j] <= x) {
            i += 1;
        }
        j -= 1;
        a += 1;
    }


    cout << a << "\n";


    return 0;
}