#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// ��������� �������
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

    // �������� ��� ��� ��������� ���������� �����
    cout << "Low: "; cin >> Low;
    cout << "High: "; cin >> High;

    // �������� ������� ����� � ��������
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

// ������� ��� ��������� ������ �����
void CreateRow(int* row, const int n, const int Low, const int High, int j)
{
    if (j < n) { // ���������� �����
        row[j] = Low + rand() % (High - Low + 1); // �������� �������
        CreateRow(row, n, Low, High, j + 1); // ������� ��� ���������� ��������
    }
}

// ������� ��� ��������� ��� �����
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int i)
{
    if (i < k) { // ���������� �����
        CreateRow(a[i], n, Low, High); // ��������� �����
        CreateRows(a, k, n, Low, High, i + 1); // ������� ��� ���������� �����
    }
}

// ������� ��� ��������� ������ �����
void PrintRow(int* row, const int n, int j)
{
    if (j < n) { // ���������� �����
        cout << setw(4) << row[j]; // �������� �������
        PrintRow(row, n, j + 1); // ������� ��� ���������� ��������
    }
}

// ������� ��� ��������� ��� �����
void PrintRows(int** a, const int k, const int n, int i)
{
    if (i < k) { // ���������� �����
        PrintRow(a[i], n); // �������� �����
        cout << endl;
        PrintRows(a, k, n, i + 1); // ������� ��� ���������� �����
    }
}

// ������� ��� ����������� ������� ������������� �������� � �������
void FindMaxIndex(int** a, const int k, int col, int& maxIdx, int i)
{
    if (i < k) { 
        if (a[i][col] > a[maxIdx][col]) {
            maxIdx = i;
        }
        FindMaxIndex(a, k, col, maxIdx, i + 1); // ����������� ������
    }
}

// ������� ��� ����������� ������� ���������� �������� � �������
void FindMinIndex(int** a, const int k, int col, int& minIdx, int i)
{
    if (i < k) { 
        if (a[i][col] < a[minIdx][col]) {
            minIdx = i;
        }
        FindMinIndex(a, k, col, minIdx, i + 1); // ����������� ������
    }
}

// ������� ��� ����� ������ ������������ � ��������� �������� � �������� ��������
void SwapMinMaxOddColumns(int** a, const int k, const int n, int j)
{
    if (j < n) { 
        if (j % 2 == 0) { 
            int maxIdx = 0, minIdx = 0;
            FindMaxIndex(a, k, j, maxIdx);
            FindMinIndex(a, k, j, minIdx);

            // ̳����� ������ ������������ � ��������� ��������, ���� ���� �������
            if (maxIdx != minIdx) {
                int temp = a[maxIdx][j];
                a[maxIdx][j] = a[minIdx][j];
                a[minIdx][j] = temp;
            }
        }
        SwapMinMaxOddColumns(a, k, n, j + 1); // ����������� ������ ��� ���������� �������
    }
}
