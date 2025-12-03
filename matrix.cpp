#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

float** create2DArray(int rows, int cols) {
	float** array = new float* [rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new float[cols];
	}
	return array;
}

void delete2DArray(float** array, int rows) {
	if (array != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
    } else
        delete[] array;
}

void input2DArray(float** array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << i+1 << ".\t";
		for (int j = 0; j < cols; j++) {
			cin >> array[i][j];
		}
	}
}

void output2DArray(float** array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << i + 1 << ".\t";
		for (int j = 0; j < cols; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

float** additionMatrix(float** matrixA, float** matrixB, int rows, int cols) {
        float** result = create2DArray(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
		return result;
}

float** multiplyMatrix(float** matrixA, int rowsA, int colsA, float** matrixB, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Невозможно умножить матрицы: несовместимые размеры.\n";
        return nullptr;
    }
    float** result = create2DArray(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

float** transposeMatrix(float** matrix, int rows, int cols) {
    float** result = create2DArray(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
	setlocale(LC_ALL, "Russian");

    int action;
    while(true) {
        cout << "Выберите действие над матрицами:\n";
        cout << "1. Сложение матриц\n2. Умножение матриц\n3. Транспонирование матрицы\n4. Выход из программы (любой символ)" << endl;
        cout << ">";
        cin >> action;

        switch (action) {
            case 1:
            {
                int rows, cols;

                while(true) {
                cout << "Введите кол-во строк и столбцов для матриц (два числа через пробел): ";
                cin >> rows >> cols;
                if (rows <= 0 || cols <= 0) {
                    cout << "Кол-во строк и стобцов должно быть положительным числом.\n";
                } else
                    break;
                }
                cout << endl;
                float** matrixA = create2DArray(rows, cols);
                cout << "Матрица A создана (" << rows << " x " << cols << "). Заполните матрицу:\n";
                input2DArray(matrixA, rows, cols);
                cout << endl;

                float** matrixB = create2DArray(rows, cols);
                cout << "Матрица B Создана (" << rows << " x " << cols << "). Заполните матрицу:\n";
                input2DArray(matrixB, rows, cols);
                cout << endl;

                float** matrixC = additionMatrix(matrixA, matrixB, rows, cols);
                cout << "Матрицы сложены!\n";
                output2DArray(matrixC, rows, cols);
                cout << endl;
                

                delete2DArray(matrixA, rows);
                delete2DArray(matrixB, rows);
                delete2DArray(matrixC, rows);
                break;
            }
            
            case 2:
            {
                int rowsA, colsA;
                int rowsB, colsB;

                while(true) {
                    cout << "Введите размер матрицы A (строки столбцы): ";
                    cin >> rowsA >> colsA;
                    if (rowsA <= 0 || colsA <= 0) {
                    cout << "Кол-во строк и стобцов должно быть положительным числом.\n";
                    } else
                        break;
                }
                cout << endl;
                float** matrixA = create2DArray(rowsA, colsA);
                cout << "Матрица A создана (" << rowsA << " x " << colsA << "). Заполните матрицу:\n";
                input2DArray(matrixA, rowsA, colsA);
                cout << endl;

                while(true) {
                    cout << "Введите размер матрицы B (строки столбцы): ";
                    cin >> rowsB >> colsB;
                    if (rowsB <= 0 || colsB <= 0) {
                    cout << "Кол-во строк и стобцов должно быть положительным числом.\n";
                    } else
                        break;
                }
                cout << endl;
                float** matrixB = create2DArray(rowsB, colsB);
                cout << "Матрица B Создана (" << rowsB << " x " << colsB << "). Заполните матрицу:\n";
                input2DArray(matrixB, rowsB, colsB);
                cout << endl;

                float** matrixC = multiplyMatrix(matrixA, rowsA, colsA, matrixB, rowsB, colsB);
                if (matrixC != nullptr) {
                    cout << "Произведение матриц A x B\n";
                    output2DArray(matrixC, rowsA, colsB);
                    cout << endl;
                }

                delete2DArray(matrixA, rowsA);
                delete2DArray(matrixB, rowsB);
                delete2DArray(matrixC, rowsA);
                break;
            }
            
            case 3:
            {
                int rows, cols;

                while(true) {
                    cout << "Введите размер матрицы A (строки столбцы): ";
                    cin >> rows >> cols;
                    if (rows <= 0 || cols <= 0) {
                    cout << "Кол-во строк и стобцов должно быть положительным числом.\n";
                    } else
                        break;
                }
                cout << endl;
                float** matrixA = create2DArray(rows, cols);
                cout << "Матрица A создана (" << rows << " x " << cols << "). Заполните матрицу:\n";
                input2DArray(matrixA, rows, cols);
                cout << endl;
                float** matrixAT = transposeMatrix(matrixA, rows, cols);
                cout << "Транспонированная матрица A\n";
                output2DArray(matrixAT, cols, rows);
                cout << endl;

                delete2DArray(matrixA, rows);
                delete2DArray(matrixAT, cols);
                break;
            }

            default:
            {
                exit(0);
            }
                break;
        }
    }

	return 0;
}