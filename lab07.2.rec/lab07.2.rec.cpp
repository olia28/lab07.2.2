#include <iostream>
#include <ctime>

using namespace std;

int Maximum(int a, int b);
void FindSumMaxElementInEvenColRec(int** arr, int row_count, int col_count, int actual_col, int& sum);
int FindMaxInArrRec(int** arr, int col_number, int col_size);

int main()
{
    srand(time(NULL));
    int rowCount, colCount;
    //cout << "Enter rows count: "; cin >> rowCount;
    //cout << "Enter columns count: "; cin >> colCount;

    rowCount = 7;
    colCount = 11;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    cout << "Created matrix:\n";
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            matrix[i][j] = (rand() % 100) - 49;

            if (!(matrix[i][j] < 0)) cout << " ";   //add "space" if number positive    
            cout << matrix[i][j];

            if (j != colCount - 1)
            {
                cout << "\t ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
    cout << endl;

    int sum = 0;
    FindSumMaxElementInEvenColRec(matrix, rowCount, colCount, 0, sum);
    cout << "\nSum max number in even column : " << sum << endl;
}

int FindMaxInArrRec(int** arr, int col_number, int col_size)
{
    if (col_size == 1)
        return arr[0][col_number];
    return Maximum(arr[col_size - 1][col_number], FindMaxInArrRec(arr, col_number, col_size - 1));
}

int Maximum(int a, int b)
{
    return a > b ? a : b;
}

void FindSumMaxElementInEvenColRec(int** arr, int row_count, int col_count, int actual_col, int& sum)
{
    if (actual_col < col_count)
    {
        if (actual_col % 2 == 0)
        {
            int max = FindMaxInArrRec(arr, actual_col, row_count);
            cout << max << "\t"; //max number in each even col
            sum += max;
        }
        actual_col++;
        FindSumMaxElementInEvenColRec(arr, row_count, col_count, actual_col, sum);
    }
}