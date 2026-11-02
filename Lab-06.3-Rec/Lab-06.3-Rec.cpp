
// Lab-06.3-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.3
// Опрацювання масивів за допомогою функцій та шаблонів
// Варіант 31 — рекурсивний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int a[], const int n, const int Low,
    const int High, const int i)
{
    if (i >= n)
        return;

    a[i] = Low + rand() % (High - Low + 1);

    Create(a, n, Low, High, i + 1);
}

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

// Звичайна рекурсивна функція
int SumOdd(const int a[], const int n, const int i)
{
    if (i >= n)
        return 0;

    if (a[i] % 2 != 0)
        return a[i] + SumOdd(a, n, i + 1);

    return SumOdd(a, n, i + 1);
}

// Рекурсивний шаблон функції
template <typename T>
T SumOdd(const T a[], const int n, const int i)
{
    if (i >= n)
        return T();

    if (a[i] % 2 != 0)
        return a[i] + SumOdd<T>(a, n, i + 1);

    return SumOdd<T>(a, n, i + 1);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int n = 22;
    const int Low = -40;
    const int High = 50;

    int a[n];

    Create(a, n, Low, High, 0);

    cout << "Array:" << endl;
    Print(a, n, 0);

    cout << "Sum (function): "
        << SumOdd(a, n, 0) << endl;

    cout << "Sum (template): "
        << SumOdd<int>(a, n, 0) << endl;

    return 0;
}
