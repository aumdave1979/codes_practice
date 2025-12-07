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

int remove_dupli_from_sorted_array(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

void left_rotate(vector<int> &nums, int times)
{
    auto method1 = [&](vector<int> &nums, int times)
    {
        int n = nums.size();
        times = times % n;
        while (times > 0)
        {
            int temp = nums[0];
            for (int i = 0; i < n - 1; i++)
            {
                nums[i] = nums[i + 1];
            }
            nums[n - 1] = temp;
            times--;
        }
    };
    auto method2 = [&](vector<int> &nums, int times)
    {
        int n = nums.size();
        times = times % n;
        vector<int> temp;
        for (int i = 0; i < times; i++)
        {
            temp.push_back(nums[i]);
        }
        for (int i = times; i < n; i++)
        {
            nums[i - times] = nums[i];
        }
        for (int i = n - times; i < n; i++)
        {
            nums[i] = temp[i - (n - times)];
        }
    };
    auto method3 = [&](vector<int> &nums, int times)
    {
        // for left rotate will make reverse start times element and then remaining & full reverse
        int n = nums.size();
        times = times % n;
        reverse(nums.begin(), nums.begin() + times);
        reverse(nums.begin() + times, nums.end());
        reverse(nums.begin(), nums.end());
    };

    method3(nums, times);
    for (auto it : nums)
    {
        cout << it << " ";
    }
}

void right_rotate(vector<int> &nums, int times)
{
    // for right rotate it will rotate the starting element excpet the last elements from end to times , and then remaining & full reverse
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + (n - times));
    reverse(nums.begin() + (n - times), nums.end());
    reverse(nums.begin(), nums.end());

    for (auto it : nums)
    {
        cout << it << " ";
    }
}

void move_zeros(vector<int> &nums)
{
    int j = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[j], nums[i]);
            j++;
        }
    }

    for (auto it : nums)
    {
        cout << it << " ";
    }
}

int linear_search(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

void union_arr(vector<int> &nums1, vector<int> &nums2)
{
    set<int> result;
    int i =0, j =0;
    while (i < nums1.size() && j<nums2.size())
    {
        if (nums1[i]<nums2[j])
        {
            result.insert(nums1[i]);
            i++;
        }
        else if (nums1[i]==nums2[j])
        {
            result.insert(nums1[i]);
            i++;
            j++;
        }
        else
        {
            result.insert(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        result.insert(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        result.insert(nums2[j]);
        j++;
    }
    for (auto it : result)
    {
        cout << it << " ";
    }
}

int missing_element(vector<int> &nums)
{
    int n = nums.size();
    int curr_sum = 0;
    for (int x : nums)
    {
        curr_sum += x;
    }
    int sum = n * (n + 1) / 2;
    return sum - curr_sum;
}

int max_consi_one(vector<int> &nums)
{
    int count0 = 0;
    int count1 = 0;
    int max_consi1 = 0;
    int max_consi0 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count1++;
            count0 = 0;
            if (count1 >= max_consi1)
            {
                max_consi1 = count1;
            }
        }
        else
        {
            count0++;
            count1 = 0;
            if (count0 >= max_consi0)
            {
                max_consi0 = count0;
            }
        }
    }
    if(max_consi0>max_consi1) return 0;
    else if(max_consi0==max_consi1) return -1;
    return 1;
}

int single_nums(vector<int> &nums){
    map<int,int> mpp ;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return 0;
}



int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 1, 1, 0};
   cout << max_consi_one(nums);
}