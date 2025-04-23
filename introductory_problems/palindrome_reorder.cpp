#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int main()
{
    int odds = 0;
    string odd = "";
    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(26, 0);

    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'A'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            odds++;
            odd.push_back(i + 'A'); 
            
            cnt[i] -= 1;
        }
        cnt[i] /= 2;
    }


    if (odds > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    string ans = "";

    for (int i = 0; i < 26; i++)
    {
        for(int j = 0; j < cnt[i]; j++)
        {
            ans.push_back(i + 'A');
        }
    }
    
    string rev = ans;
    reverse(rev.begin(), rev.end());
    
    cout << ans + odd + rev << endl;


    return 0;
}