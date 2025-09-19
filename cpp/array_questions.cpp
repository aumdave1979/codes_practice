#include <bits/stdc++.h>
using namespace std;

int largest_element(vector<int> &nums)
{
    int largest = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    return largest;
}

int second_largest_element(vector<int> &nums)
{
    int largest = nums[0];
    int second_largest = -1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            second_largest = largest;
            largest = nums[i];
        }
        else if (nums[i] < largest && nums[i] > second_largest)
        {
            second_largest = nums[i];
        }
    }
    return second_largest;
}

bool check_sorted(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool shifted_sorted_check(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }
    if (nums[nums.size() - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}

vector<int> remove_dupli_from_sorted_array(vector<int> &nums){
    
}

int main()
{
    vector<int> nums = {1, 2, 4, 7, 7, 5};
    cout << check_sorted(nums);
}