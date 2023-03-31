#include <bits/stdc++.h>
using namespace std;
void PrintSub(int index, vector<int> &a, int arr[], int n)
{
    if (index == n)
    {
        for (auto i : a)
        {
            cout << i;
        }
        cout << endl;
        return;
    }
    a.push_back(arr[index]);
    PrintSub(index + 1, a, arr, n);

    a.pop_back();
    PrintSub(index + 1, a, arr, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3};
    vector<int> ds;
    PrintSub(0, ds, arr, 3);

    return 0;
}