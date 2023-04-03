#include <bits/stdc++.h>
using namespace std;

vector<int> union_of_two_sorted_array(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    int last_element = INT_MIN;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (arr1[i] != last_element)
            {
                ans.push_back(arr1[i]);
                last_element = arr1[i];
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (arr2[j] != last_element)
            {
                ans.push_back(arr2[j]);
                last_element = arr2[j];
            }
            j++;
        }
        else
        {
            if (arr1[i] != last_element)
            {
                ans.push_back(arr1[i]);
                last_element = arr1[i];
            }
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (arr1[i] != last_element)
        {
            ans.push_back(arr1[i]);
            last_element = arr1[i];
        }
        i++;
    }
    while (j < m)
    {
        if (arr2[j] != last_element)
        {
            ans.push_back(arr2[j]);
            last_element = arr2[j];
        }
        j++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr1[] = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> ans = union_of_two_sorted_array(arr1, arr2, 10, 10);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}