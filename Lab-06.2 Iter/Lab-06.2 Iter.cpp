
// Lab-06.2-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційним способом
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву
void Create(int a[], const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];

    cout << endl;
}

// Пошук індексу найменшого парного елемента
int FindMinEven(const int a[], const int n)
{
    int minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (minIndex == -1 || a[i] < a[minIndex])
                minIndex = i;
        }
    }

    return minIndex;
}

// Обмін першого елемента з найменшим парним
void ProcessArray(int a[], const int n)
{
    if (n <= 0)
        return;

    int minIndex = FindMinEven(a, n);

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

    Create(a, n, Low, High);

    cout << "Original array:" << endl;
    Print(a, n);

    ProcessArray(a, n);

    cout << "Modified array:" << endl;
    Print(a, n);

    return 0;
}
