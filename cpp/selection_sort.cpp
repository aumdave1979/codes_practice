#include <iostream>
using namespace std;
void selection_sort(int a[], int size)
{
    for (int pass = 0; pass < size; pass++)
    {
        int mIndex = pass;
        for (int i = pass + 1; i < size; i++)
        {
            if (a[i] < a[mIndex])
            {
                mIndex = i;
            }
        }
        swap(a[pass], a[mIndex]);
    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter size";
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value of index " << i;
        cin >> arr[i];
    }
    printArray(arr,5);

    cout << "after sorting" << endl;

    selection_sort(arr,5);
    printArray(arr,5);
    return 0;
}