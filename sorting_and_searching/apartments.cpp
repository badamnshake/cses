#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // number of applicants;
    int n;

    // number of apartments;
    int m;

    // allowed difference
    int k;

    cin >> n;
    cin >> m;
    cin >> k;

    // desired apartment size of each applicant
    vector<int> a(n);
    

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // sizes of apartments
    vector<int> b(m);

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }


    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // pointer for applicants
    int i = 0;
    // pointer for apartments
    int j = 0;

    int ans = 0;

    while(i < n && j < m)
    {
        while(i < n && b[j] > a[i] + k )
            i++;

        if(i == n) break;

        if(b[j] >= a[i] - k)
        {
            i++;
            ans++;
        }

        j++;
    }

    cout << ans << "\n";
    return 0;




}