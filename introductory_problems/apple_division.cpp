#include <vector>
#include <algorithm>
#include <iostream>
#define mod 1000000007

using namespace std;

long long two_groups(int i, vector<long long>& nums, long long a = 0, long long b = 0)
{
    if(i == nums.size())
        return abs(a - b);
    
    return min(two_groups(i + 1, nums, a + nums[i], b), two_groups(i + 1, nums, a, b + nums[i]));
}

int main()
{
    
    int n;
    cin >> n;
    
    vector<long long> nums(n);
    
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    cout << two_groups(0, nums) << endl;

    return 0;
}
