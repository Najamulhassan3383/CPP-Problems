#include <bits/stdc++.h>
using namespace std;

vector<int> union_of_two_sorted_array(vector<int> &num1, vector<int> &num2)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    int last_element = INT_MIN;

    while (i < num1.size() && j < num2.size())
    {
        if (num1[i] < num2[j])
        {
            if (num1[i] != last_element)
            {
                ans.push_back(num1[i]);
                last_element = num1[i];
            }
            i++;
        }
        else if (num1[i] > num2[j])
        {
            if (num2[j] != last_element)
            {
                ans.push_back(num2[j]);
                last_element = num2[j];
            }
            j++;
        }
        else
        {
            if (num1[i] != last_element)
            {
                ans.push_back(num1[i]);
                last_element = num1[i];
            }
            i++;
            j++;
        }
    }
    while (i < num1.size())
    {
        if (num1[i] != last_element)
        {
            ans.push_back(num1[i]);
            last_element = num1[i];
        }
        i++;
    }
    while (j < num2.size())
    {
        if (num2[j] != last_element)
        {
            ans.push_back(num2[j]);
            last_element = num2[j];
        }
        j++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> num1 = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> num2 = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> ans = union_of_two_sorted_array(num1, num2);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}