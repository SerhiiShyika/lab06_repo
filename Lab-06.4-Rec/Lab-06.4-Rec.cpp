
// Lab-06.4-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.4
// Опрацювання одновимірних динамічних масивів
// Варіант 31 — рекурсивний метод

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Рекурсивне введення масиву
bool Create(double a[], const int n, const int i)
{
    if (i >= n)
        return true;

    cout << "a[" << i << "] = ";

    if (!(cin >> a[i]) || !isfinite(a[i]))
        return false;

    return Create(a, n, i + 1);
}

// Рекурсивне виведення масиву
void Print(const double a[], const int n, const int i)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(10) << a[i];

    Print(a, n, i + 1);
}

// Пошук індексу мінімального за модулем
int MinAbsIndex(const double a[], const int n,
    const int i, const int minIndex)
{
    if (i >= n)
        return minIndex;

    int index = minIndex;

    if (fabs(a[i]) < fabs(a[index]))
        index = i;

    return MinAbsIndex(a, n, i + 1, index);
}

// Сума модулів після першого від'ємного
double SumAfterNegative(const double a[], const int n,
    const int i, const bool found)
{
    if (i >= n)
        return 0;

    if (found)
        return fabs(a[i]) +
        SumAfterNegative(a, n, i + 1, true);

    return SumAfterNegative(a, n, i + 1, a[i] < 0);
}

// Рекурсивне заповнення вільних місць нулями
void FillZeros(double a[], const int n, const int i)
{
    if (i >= n)
        return;

    a[i] = 0;

    FillZeros(a, n, i + 1);
}

// Рекурсивне стиснення масиву
void Compress(double a[], const int n, const double low,
    const double high, const int i, const int k)
{
    if (i >= n)
    {
        FillZeros(a, n, k);
        return;
    }

    if (a[i] < low || a[i] > high)
    {
        a[k] = a[i];
        Compress(a, n, low, high, i + 1, k + 1);
    }
    else
    {
        Compress(a, n, low, high, i + 1, k);
    }
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

    if (!Create(a, n, 0))
    {
        cerr << "Invalid array element!" << endl;
        delete[] a;
        return 1;
    }

    cout << fixed << setprecision(2);

    cout << "Original array:" << endl;
    Print(a, n, 0);

    int minIndex = MinAbsIndex(a, n, 1, 0);

    cout << "Min abs element index: "
        << minIndex << endl;

    cout << "Min abs element position: "
        << minIndex + 1 << endl;

    cout << "Sum after first negative: "
        << SumAfterNegative(a, n, 0, false) << endl;

    Compress(a, n, aBorder, bBorder, 0, 0);

    cout << "Modified array:" << endl;
    Print(a, n, 0);

    delete[] a;

    return 0;
}
