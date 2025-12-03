/*
    fileMatrix.cpp
    Каракчиев М.А., 03.12.2025

    Программа принимает на ввод файл с именем matrix.txt,
    содержащий информацию о размере матрицы в первой строке и саму матрицу в последующих.
    Выводит транспонированную матрицу в файл matrixT.txt.
*/
#include <iostream>
#include <cstdlib>
#include <clocale>
#include <fstream>

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
    int rows, cols;
    ifstream fin("matrix.txt");
    if (!fin) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    fin >> rows >> cols;

    float** arr = create2DArray(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fin >> arr[i][j];
        }
    }
    fin.close();

    float** arrT = transposeMatrix(arr, rows, cols);

    ofstream fout("matrixT.txt");
    if (!fout) {
        cerr << "Ошибка открытия файла для записи" << endl;
        return 1;
    }

    fout << cols << " " << rows << "\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            fout << arrT[i][j] << " ";
        }
        fout << '\n';
    }
    fout.close();

    delete2DArray(arr, rows);
    delete2DArray(arrT, cols);
    return 0;
}