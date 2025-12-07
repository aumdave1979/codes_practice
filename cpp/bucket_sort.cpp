#include <iostream>
#include <vector>
using namespace std;
int maximum(int a[], int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int digitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
int main()
{
    int size;
    cout << "Enter total elements count:";
    cin >> size;

    int a[size];
    // scan array from user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for index " << i;
        cin >> a[i];
    }
    int totalItr = digitCount(maximum(a, size));
    //  2D array of 10 rows/bucket with n possible values
    vector<vector<int>> buckets(10);
    int div = 1;
    for (int i = 0; i < totalItr; i++)
    {
        for (int j = 0; j < size; j++)
        {
            buckets[((a[j] / div) % 10)].push_back(a[j]);
        }
        div *= 10;
        for (int k = 0, j = 0; k < 10; k++)
        {
            for (int l = 0; l < buckets[k].size(); l++)
            {
                a[j++] = buckets[k][l];
            }
            buckets[k].clear();
        }
    }
    return 0;
}