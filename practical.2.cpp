#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Linear Search
int Linear(vector<int> &data, int value)
{
    int size = data.size();

    for(int i = 0; i < size; i++)
    {
        if(data[i] == value)
            return i;
    }

    return -1;
}

// Binary Search
int Binary(vector<int> &data, int value)
{
    int first = 0;
    int last = data.size() - 1;

    while(first <= last)
    {
        int middle = (first + last) / 2;

        if(data[middle] == value)
            return middle;

        if(value > data[middle])
            first = middle + 1;
        else
            last = middle - 1;
    }

    return -1;
}

int main()
{
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter elements in sorted order:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << "Enter search element: ";
    cin >> key;

    // Linear Search
    clock_t start1 = clock();
    int pos1 = Linear(numbers, key);
    clock_t end1 = clock();

    // Binary Search
    clock_t start2 = clock();
    int pos2 = Binary(numbers, key);
    clock_t end2 = clock();

    cout << "\n------ Linear Search ------\n";

    if(pos1 == -1)
        cout << "Element Not Found\n";
    else
        cout << "Element Found at Position : " << pos1 + 1 << endl;

    cout << "Execution Time : "
         << double(end1 - start1) / CLOCKS_PER_SEC
         << " seconds\n";

    cout << "\n------ Binary Search ------\n";

    if(pos2 == -1)
        cout << "Element Not Found\n";
    else
        cout << "Element Found at Position : " << pos2 + 1 << endl;

    cout << "Execution Time : "
         << double(end2 - start2) / CLOCKS_PER_SEC
         << " seconds\n";

    return 0;
}