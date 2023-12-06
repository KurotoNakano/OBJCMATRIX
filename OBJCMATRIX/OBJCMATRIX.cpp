// OBJCMATRIX.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 45 65 85

#include <iostream>
#include <vector>

using namespace std;

int findMaxInOrderedColumns(const vector<vector<int>>& matrix) 
{
    int maxInOrderedColumns = 0;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int col = 0; col < n; col++) 
    {
        bool isAscending = true;
        bool isDescending = true;

        for (int row = 1; row < m; row++) 
        {
            if (matrix[row][col] > matrix[row - 1][col]) 
            {
                isDescending = false;
            }
            else if (matrix[row][col] < matrix[row - 1][col]) 
            {
                isAscending = false;
            }

            if (!isAscending && !isDescending) 
            {
                // Этот столбец не упорядочен
                break;
            }
        }

        if (isAscending || isDescending) 
        {
            for (int row = 0; row < m; row++) 
            {
                if (matrix[row][col] > maxInOrderedColumns) 
                {
                    maxInOrderedColumns = matrix[row][col];
                }
            }
        }
    }

    return maxInOrderedColumns;
}

void removeFirstPositiveColumn(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    int columnToDelete = -1;

    for (int col = 0; col < n; col++) 
    {
        bool allPositive = true;

        for (int row = 0; row < m; row++)
        {
            if (matrix[row][col] <= 0)
            {
                allPositive = false;
                break;
            }
        }

        if (allPositive) 
        {
            columnToDelete = col;
            break;
        }
    }

    if (columnToDelete != -1) {
        for (int i = 0; i < m; i++) {
            matrix[i].erase(matrix[i].begin() + columnToDelete);
        }
    }
}

vector<double> averageOfParallelDiagonals(const vector<vector<int>>& matrix) 
{
    int n = matrix.size(); // Размер матрицы
    vector<double> averages;

    for (int k = 1 - n; k < n; k++) 
    {
        if (k != 0) { // Исключаем побочную диагональ
            int diagonalSum = 0;   // Сумма элементов на текущей диагонали
            int diagonalCount = 0; // Количество элементов на текущей диагонали

            int row, col;
            if (k < 0) {
                row = -k;
                col = 0;
            }
            else {
                row = 0;
                col = k;
            }

            while (row < n && col < n) {
                diagonalSum += matrix[row][col];
                diagonalCount++;
                row++;
                col++;
            }

            if (diagonalCount > 0) {
                double average = static_cast<double>(diagonalSum) / diagonalCount;
                averages.push_back(average);
            }
        }
    }

    return averages;
}

int main() {
    int m, n;
    cout << "Amount Lines: ";
    cin >> m;
    cout << "Amount Columns: ";
    cin >> n;

    vector<vector<int>> matrix1(m, vector<int>(n));

    cout << "Elements of matrix:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix1[i][j];
        }
    }

    int maxInOrderedColumns = findMaxInOrderedColumns(matrix1);

    if (maxInOrderedColumns > 0) {
        cout << "Max Element: " << maxInOrderedColumns << endl;
    }
    else {
        cout << "No ordered columns." << endl;
    }
    cout << "================================================" << endl;
    int z, x;
    cout << "Amount Lines: ";
    cin >> z;
    cout << "Amount Columns: ";
    cin >> x;

    vector<vector<int>> matrix2(z, vector<int>(x));

    cout << "Elements of matrix:\n";
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < x; j++) {
            cout << "B[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix2[i][j];
        }
    }

    removeFirstPositiveColumn(matrix2);

    cout << "Matrix after deleting:\n";
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < matrix2[i].size(); j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "================================================" << endl;

    int d;
    cout << "size matrix: ";
    cin >> d;

    vector<vector<int>> matrix3(d, vector<int>(d));

    cout << "elements:\n";
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            cout << "C[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix3[i][j];
        }
    }

    vector<double> averages = averageOfParallelDiagonals(matrix3);

    for (int i = 0; i < averages.size(); i++) {
        cout << "agerages of diag: " << i + 1 << " = " << averages[i] << endl;
    }

    return 0;
}



