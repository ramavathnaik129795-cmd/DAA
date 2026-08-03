#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// Function to maintain heap property
void heapify(vector<int> &arr, int n, int i, bool isMaxHeap)
{
    while (true)
    {
        int target = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (isMaxHeap)
        {
            if (left < n && arr[left] > arr[target])
                target = left;
            if (right < n && arr[right] > arr[target])
                target = right;
        }
        else
        {
            if (left < n && arr[left] < arr[target])
                target = left;
            if (right < n && arr[right] < arr[target])
                target = right;
        }

        if (target == i)
            break;

        swap(arr[i], arr[target]);
        i = target;
    }
}

// Generic Heap Sort
void heapSort(vector<int> &arr, bool isMaxHeap)
{
    int n = arr.size();

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // Sorting
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }

    // Reverse for Min Heap to get ascending order
    if (!isMaxHeap)
        reverse(arr.begin(), arr.end());
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        data[i] = rand() % 100000;

    vector<int> maxHeap = data;
    vector<int> minHeap = data;

    // Max Heap Sort Timing
    auto start1 = high_resolution_clock::now();
    heapSort(maxHeap, true);
    auto end1 = high_resolution_clock::now();

    // Min Heap Sort Timing
    auto start2 = high_resolution_clock::now();
    heapSort(minHeap, false);
    auto end2 = high_resolution_clock::now();

    cout << "\n===== MAX HEAP SORT =====\n";
    cout << "Nanoseconds  : "
         << duration_cast<nanoseconds>(end1 - start1).count() << " ns\n";
    cout << "Microseconds : "
         << duration_cast<microseconds>(end1 - start1).count() << " us\n";

    cout << "\n===== MIN HEAP SORT =====\n";
    cout << "Nanoseconds  : "
         << duration_cast<nanoseconds>(end2 - start2).count() << " ns\n";
    cout << "Microseconds : "
         << duration_cast<microseconds>(end2 - start2).count() << " us\n";

    return 0;
}