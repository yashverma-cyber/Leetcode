#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    // Merge the two sorted halves into a temporary array.
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        // Choose the smaller value so the merged range stays sorted.
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            ++i;
        }
        else
        {
            temp.push_back(arr[j]);
            ++j;
        }
    }

    // Copy any remaining values from either half.
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        ++i;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        ++j;
    }

    // Write the sorted values back into the original array.
    for (int idx = 0; idx < size(temp); ++idx)
    {
        arr[st + idx] = temp[idx];
    }
}
void mergeSort(vector<int> &arr, int st, int end)
{
    // A range with one or no elements is already sorted.
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        // Recursively sort both halves, then merge them.
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    // Sort the complete array and print the result.
    mergeSort(arr, 0, size(arr) - 1);
    for (const int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}