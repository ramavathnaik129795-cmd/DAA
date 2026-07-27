#include <iostream>
#include <ctime>

using namespace std;

// Iterative Method
long long iterativeFactorial(int num)
{
    long long fact = 1;

    while(num > 1)
    {
        fact = fact * num;
        num--;
    }

    return fact;
}

// Recursive Method
long long recursiveFactorial(int num)
{
    if(num == 0 || num == 1)
        return 1;

    return num * recursiveFactorial(num - 1);
}

int main()
{
    int n;

    cout << "Enter a number : ";
    cin >> n;

    // Iterative Method
    clock_t start1 = clock();
    long long ans1 = iterativeFactorial(n);
    clock_t end1 = clock();

    // Recursive Method
    clock_t start2 = clock();
    long long ans2 = recursiveFactorial(n);
    clock_t end2 = clock();

    cout << "\nIterative Factorial = " << ans1 << endl;
    cout << "Time Taken = "
         << (double)(end1 - start1) / CLOCKS_PER_SEC
         << " seconds" << endl;

    cout << "\nRecursive Factorial = " << ans2 << endl;
    cout << "Time Taken = "
         << (double)(end2 - start2) / CLOCKS_PER_SEC
         << " seconds" << endl;

    return 0;
}