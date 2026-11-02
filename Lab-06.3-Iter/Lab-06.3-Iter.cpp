
// Lab-06.3-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.3
// Опрацювання масивів за допомогою функцій та шаблонів
// Варіант 31 — ітераційний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int a[], const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];

    cout << endl;
}

// Звичайна функція
int SumOdd(const int a[], const int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            s += a[i];
    }

    return s;
}

// Шаблон функції
template <typename T>
T SumOdd(const T a[], const int n)
{
    T s = T();

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            s += a[i];
    }

    return s;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int n = 22;
    const int Low = -40;
    const int High = 50;

    int a[n];

    Create(a, n, Low, High);

    cout << "Array:" << endl;
    Print(a, n);

    cout << "Sum (function): "
        << SumOdd(a, n) << endl;

    cout << "Sum (template): "
        << SumOdd<int>(a, n) << endl;

    return 0;
}
