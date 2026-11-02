
// Lab-06.4-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.4
// Опрацювання одновимірних динамічних масивів
// Варіант 31 — ітераційний метод

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Введення елементів масиву
void Create(double a[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Виведення масиву
void Print(const double a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(10) << a[i];

    cout << endl;
}

// Пошук індексу мінімального за модулем елемента
int MinAbsIndex(const double a[], const int n)
{
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (fabs(a[i]) < fabs(a[minIndex]))
            minIndex = i;
    }

    return minIndex;
}

// Сума модулів після першого від'ємного елемента
double SumAfterNegative(const double a[], const int n)
{
    double s = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (found)
            s += fabs(a[i]);
        else if (a[i] < 0)
            found = true;
    }

    return s;
}

// Стиснення масиву
void Compress(double a[], const int n,
    const double low, const double high)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < low || a[i] > high)
        {
            a[k] = a[i];
            k++;
        }
    }

    for (int i = k; i < n; i++)
        a[i] = 0;
}

int main()
{
    int n;
    double aBorder, bBorder;

    cout << "n = ";
    cin >> n;

    if (!cin || n <= 0)
    {
        cerr << "Invalid n!" << endl;
        return 1;
    }

    cout << "a = ";
    cin >> aBorder;

    cout << "b = ";
    cin >> bBorder;

    if (!cin || !isfinite(aBorder) || !isfinite(bBorder)
        || aBorder > bBorder)
    {
        cerr << "Invalid interval!" << endl;
        return 1;
    }

    double* a = new double[n];

    Create(a, n);

    for (int i = 0; i < n; i++)
    {
        if (!cin || !isfinite(a[i]))
        {
            cerr << "Invalid array element!" << endl;
            delete[] a;
            return 1;
        }
    }

    cout << fixed << setprecision(2);

    cout << "Original array:" << endl;
    Print(a, n);

    cout << "Min abs element index: "
        << MinAbsIndex(a, n) << endl;

    cout << "Min abs element position: "
        << MinAbsIndex(a, n) + 1 << endl;

    cout << "Sum after first negative: "
        << SumAfterNegative(a, n) << endl;

    Compress(a, n, aBorder, bBorder);

    cout << "Modified array:" << endl;
    Print(a, n);

    delete[] a;

    return 0;
}
