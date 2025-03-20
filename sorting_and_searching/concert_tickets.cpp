// https://cses.fi/problemset/task/1091

#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> concertTickets(vector<int> &price, vector<int> &pay)
{
    // Create a multiset to store the prices of all tickets
    multiset<int> maxPrice;

    // Insert all the values of price array in the multiset
    for (int i = 0; i < price.size(); i++)
    {
        maxPrice.insert(price[i]);
    }

    // Create an array answer to store the answer for each customer
    vector<int> ans(pay.size());

    // Now iterate through every customer
    for (int i = 0; i < pay.size(); i++)
    {
        int temp = pay[i];

        // Find the upper bound of maximum price offered by customer in the multiset
        multiset<int>::iterator itr = maxPrice.upper_bound(temp);

        // If it points to the begining that means no ticket is available for the customer
        // Otherwise decrement the iterator and gets the value out of it and then erase that value from multiset
        if (itr == maxPrice.begin())
        {
            ans[i] = -1;
        }
        else
        {
            itr--;
            ans[i] = (*itr);
            maxPrice.erase(itr);
        }
    }

    // Retun the array answer
    return ans;
}

int main()
{

    int n, c;
    cin >> n;
    cin >> c;

    
    vector<int> price(n), pay(c);

    for(int i = 0; i < n; i++)
    {
        cin >> price[i];

    }

    for(int i = 0; i < c; i++)
    {

        cin >> pay[i];
    }

    // Sample input

    // Call the function to get the results
    vector<int> result = concertTickets(price, pay);

    // Print the result
    for (int i : result)
    {
        cout << i << "\n";
    }
    cout << endl;

    return 0;
}
