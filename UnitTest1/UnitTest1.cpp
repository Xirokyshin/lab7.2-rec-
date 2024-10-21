#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест на коректність створення матриці
        TEST_METHOD(TestCreateRows)
        {
            const int k = 3;
            const int n = 3;
            int Low = 1, High = 10;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            // Викликаємо функцію для створення рядків
            CreateRows(a, k, n, Low, High);

            // Перевіряємо, що всі елементи в межах від Low до High
            for (int i = 0; i < k; i++)
                for (int j = 0; j < n; j++)
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

            // Чистимо пам'ять після тесту
            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест на коректність пошуку максимального індексу в стовпці
        TEST_METHOD(TestFindMaxIndex)
        {
            const int k = 3;
            const int n = 3;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            a[0][0] = 1; a[0][1] = 5; a[0][2] = 3;
            a[1][0] = 7; a[1][1] = 2; a[1][2] = 9;
            a[2][0] = 4; a[2][1] = 8; a[2][2] = 6;

            int maxIdx = 0;
            FindMaxIndex(a, k, 1, maxIdx); // шукаємо максимум у стовпці 1

            Assert::AreEqual(maxIdx, 2); // максимум знаходиться в рядку 2

            // Чистимо пам'ять після тесту
            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }
    };
};