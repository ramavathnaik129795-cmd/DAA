#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int> &a)
{
    int n = a.size();

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &a)
{
    int n = a.size();

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &a)
{
    int n = a.size();

    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Main Program
int main()
{
    const int SIZE = 100;

    vector<int> original(SIZE);

    srand(time(0));

    // Generate Random Numbers
    for(int i = 0; i < SIZE; i++)
    {
        original[i] = rand() % 1000;
    }

    vector<int> arr;

    // Bubble Sort
    arr = original;
    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto end = high_resolution_clock::now();

    cout << "Bubble Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // Selection Sort
    arr = original;
    start = high_resolution_clock::now();
    selectionSort(arr);
    end = high_resolution_clock::now();

    cout << "Selection Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // Insertion Sort
    arr = original;
    start = high_resolution_clock::now();
    insertionSort(arr);
    end = high_resolution_clock::now();

    cout << "Insertion Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    return 0;
}