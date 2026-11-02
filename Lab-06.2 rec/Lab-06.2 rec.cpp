
// Lab-06.2-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивним способом
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву
void Create(int a[], const int n, const int Low,
    const int High, const int i)
{
    if (i >= n)
        return;

    a[i] = Low + rand() % (High - Low + 1);

    Create(a, n, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(const int a[], const int n, const int i)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << a[i];

    Print(a, n, i + 1);
}

// Рекурсивний пошук найменшого парного
int FindMinEven(const int a[], const int n,
    const int i, const int minIndex)
{
    if (i >= n)
        return minIndex;

    int index = minIndex;

    if (a[i] % 2 == 0)
    {
        if (index == -1 || a[i] < a[index])
            index = i;
    }

    return FindMinEven(a, n, i + 1, index);
}

// Обмін першого елемента з найменшим парним
void ProcessArray(int a[], const int n)
{
    if (n <= 0)
        return;

    int minIndex = FindMinEven(a, n, 0, -1);

    if (minIndex != -1)
    {
        int temp = a[0];
        a[0] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int n = 22;
    const int Low = -40;
    const int High = 50;

    int a[n];

    Create(a, n, Low, High, 0);

    cout << "Original array:" << endl;
    Print(a, n, 0);

    ProcessArray(a, n);

    cout << "Modified array:" << endl;
    Print(a, n, 0);

    return 0;
}
