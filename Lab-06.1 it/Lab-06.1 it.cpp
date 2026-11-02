
// Lab-06.1.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void ProcessArray(int a[], const int N)
{
    for (int i = 0; i < N; i++)
    {
        a[i] = a[i] + 5;
    }
}

int main()
{
    const int N = 22;
    int a[N];

    srand(static_cast<unsigned int>(time(nullptr)));

    // Заповнення масиву випадковими числами від -40 до 50
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 91 - 40;
    }

    // Виведення початкового масиву
    cout << "Original array:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << setw(5) << a[i];
    }

    cout << endl;

    // Обробка масиву
    ProcessArray(a, N);

    // Виведення зміненого масиву
    cout << "Modified array:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << setw(5) << a[i];
    }

    cout << endl;

    return 0;
}
