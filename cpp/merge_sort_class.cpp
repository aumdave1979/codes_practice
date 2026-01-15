#include <iostream>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
    int ls = mid - low + 1;
    int rs = high - mid;
    int la[ls];
    int ra[rs];
    for (int index = 0, i = low; i <= mid; index++, i++)
    {
        la[index] = a[i];
    }
    for (int index = 0, i = mid + 1; i <= high; index++, i++)
    {
        ra[index] = a[i];
    }
    // merge logic
    int i = 0;
    int j = 0;
    int k = low;
    while (i < ls && j < rs)
    {
        if (la[i] < ra[j])
        {
            a[k] = la[i];
            i++;
        }
        else
        {
            a[k] = ra[j];
            j++;
        }
        k++;
    }
    while (i < ls)
    {
        a[k] = la[i];
        i++;
        k++;
    }
    while (j < rs)
    {
        a[k] = ra[j];
        k++;
        j++;
    }
}
void merge_sort(int a[], int low, int high)
{
    if (low == high)
        return;
    int mid = low + (high - low) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
}