#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Прототипи функцій
void CreateRow(int* row, const int n, const int Low, const int High, int j = 0);
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int i = 0);

void PrintRow(int* row, const int n, int j = 0);
void PrintRows(int** a, const int k, const int n, int i = 0);

void FindMaxIndex(int** a, const int k, int col, int& maxIdx, int i = 1);
void FindMinIndex(int** a, const int k, int col, int& minIdx, int i = 1);
void SwapMinMaxOddColumns(int** a, const int k, const int n, int j = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low, High, k, n;

    // Введення меж для генерації випадкових чисел
    cout << "Low: "; cin >> Low;
    cout << "High: "; cin >> High;

    // Введення кількості рядків і стовпців
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, k, n, Low, High);
    PrintRows(a, k, n); 

    SwapMinMaxOddColumns(a, k, n);

    cout << "Zminena matrutsya:\n";
    PrintRows(a, k, n); 

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція для створення одного рядка
void CreateRow(int* row, const int n, const int Low, const int High, int j)
{
    if (j < n) { // перевіряємо умову
        row[j] = Low + rand() % (High - Low + 1); // генеруємо елемент
        CreateRow(row, n, Low, High, j + 1); // рекурсія для наступного елемента
    }
}

// Функція для створення всіх рядків
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int i)
{
    if (i < k) { // перевіряємо умову
        CreateRow(a[i], n, Low, High); // створюємо рядок
        CreateRows(a, k, n, Low, High, i + 1); // рекурсія для наступного рядка
    }
}

// Функція для виведення одного рядка
void PrintRow(int* row, const int n, int j)
{
    if (j < n) { // перевіряємо умову
        cout << setw(4) << row[j]; // виводимо елемент
        PrintRow(row, n, j + 1); // рекурсія для наступного елемента
    }
}

// Функція для виведення всіх рядків
void PrintRows(int** a, const int k, const int n, int i)
{
    if (i < k) { // перевіряємо умову
        PrintRow(a[i], n); // виводимо рядок
        cout << endl;
        PrintRows(a, k, n, i + 1); // рекурсія для наступного рядка
    }
}

// Функція для знаходження індексу максимального елемента в стовпці
void FindMaxIndex(int** a, const int k, int col, int& maxIdx, int i)
{
    if (i < k) { 
        if (a[i][col] > a[maxIdx][col]) {
            maxIdx = i;
        }
        FindMaxIndex(a, k, col, maxIdx, i + 1); // рекурсивний виклик
    }
}

// Функція для знаходження індексу мінімального елемента в стовпці
void FindMinIndex(int** a, const int k, int col, int& minIdx, int i)
{
    if (i < k) { 
        if (a[i][col] < a[minIdx][col]) {
            minIdx = i;
        }
        FindMinIndex(a, k, col, minIdx, i + 1); // рекурсивний виклик
    }
}

// Функція для заміни місцями максимальних і мінімальних елементів у непарних стовпцях
void SwapMinMaxOddColumns(int** a, const int k, const int n, int j)
{
    if (j < n) { 
        if (j % 2 == 0) { 
            int maxIdx = 0, minIdx = 0;
            FindMaxIndex(a, k, j, maxIdx);
            FindMinIndex(a, k, j, minIdx);

            // Міняємо місцями максимальний і мінімальний елементи, якщо вони знайдені
            if (maxIdx != minIdx) {
                int temp = a[maxIdx][j];
                a[maxIdx][j] = a[minIdx][j];
                a[minIdx][j] = temp;
            }
        }
        SwapMinMaxOddColumns(a, k, n, j + 1); // рекурсивний виклик для наступного стовпця
    }
}
