#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // ���� �� ���������� ��������� �������
        TEST_METHOD(TestCreateRows)
        {
            const int k = 3;
            const int n = 3;
            int Low = 1, High = 10;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            // ��������� ������� ��� ��������� �����
            CreateRows(a, k, n, Low, High);

            // ����������, �� �� �������� � ����� �� Low �� High
            for (int i = 0; i < k; i++)
                for (int j = 0; j < n; j++)
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

            // ������� ���'��� ���� �����
            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }

        // ���� �� ���������� ������ ������������� ������� � �������
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
            FindMaxIndex(a, k, 1, maxIdx); // ������ �������� � ������� 1

            Assert::AreEqual(maxIdx, 2); // �������� ����������� � ����� 2

            // ������� ���'��� ���� �����
            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }
    };
};