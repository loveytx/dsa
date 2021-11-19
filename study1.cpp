#include <iostream>
#include <vector>
using namespace std;

vector<int> subset;

void search(int k, int n)
{
    if (k == n + 1)
    { // to print subset
        cout << "{";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << ",";
        }
        cout << "}";
        cout << "\n";
    }
    else
    {
        // include k in the subset
        subset.push_back(k);
        search(k + 1, n);
        subset.pop_back();
        // don’t include k in the subset
        search(k + 1, n);
    }
}
int main()
{
    int n;
    cin >> n;
    search(1, n);
    return 0;
}