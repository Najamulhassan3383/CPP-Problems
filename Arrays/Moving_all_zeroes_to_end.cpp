#include <bits/stdc++.h>
using namespace std;

// approch one
//  take all the non zero elements and put them in seperate array
// put all the zero at the back of the array
// copy the array to the original array
// time complexity O(n)
// space complexity O(n)
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    for (auto it : nums)
    {
        if (it != 0)
            temp.push_back(it);
    }

    int num_of_zero = n - temp.size();
    for (int i = 0; i < num_of_zero; i++)
    {
        temp.push_back(0);
    }
    nums = temp;
}

// approch two
//  take all the non zero elements and put them in the start of array
// put all the zero at the back of the array
// time complexity O(n)
// space complexity O(1)

void moveZeroes2(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[count++] = nums[i];
        }
    }
    while (count < n)
    {
        nums[count++] = 0;
    }
}

// two pointer approch
//   take two pointer one for iterating the array and other for keeping track of the non zero elements
//  if the element is non zero then swap the element with the non zero element
//  time complexity O(n)
//  space complexity O(1)
void moveZeroes3(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[count++], nums[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {3, 12};
    moveZeroes3(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }

    return 0;
}