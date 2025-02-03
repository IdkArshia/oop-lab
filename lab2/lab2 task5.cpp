#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols) {
    int **mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    return mat;
}

void fillMatrix(int **mat, int rows, int cols) {
    cout << "Input matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element at position (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
}

int** addMatrices(int **mat1, int **mat2, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int **mat1, int **mat2, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int **mat1, int **mat2, int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication is not feasible." << endl;
        return nullptr;
    }
    int **result = createMatrix(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

void deleteMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void displayMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows for first matrix: ";
    cin >> r1;
    cout << "Enter columns for first matrix: ";
    cin >> c1;
    int **mat1 = createMatrix(r1, c1);
    fillMatrix(mat1, r1, c1);

    cout << "Enter rows for second matrix: ";
    cin >> r2;
    cout << "Enter columns for second matrix: ";
    cin >> c2;
    int **mat2 = createMatrix(r2, c2);
    fillMatrix(mat2, r2, c2);

    if (r1 == r2 && c1 == c2) {
        cout << "Matrix Sum:" << endl;
        int **sum = addMatrices(mat1, mat2, r1, c1);
        displayMatrix(sum, r1, c1);
        deleteMatrix(sum, r1);

        cout << "Matrix Difference:" << endl;
        int **diff = subtractMatrices(mat1, mat2, r1, c1);
        displayMatrix(diff, r1, c1);
        deleteMatrix(diff, r1);
    } else {
        cout << "Addition and subtraction cannot be performed on matrices of different sizes." << endl;
    }

    int **product = multiplyMatrices(mat1, mat2, r1, c1, r2, c2);
    if (product != nullptr) {
        cout << "Matrix Product:" << endl;
        displayMatrix(product, r1, c2);
        deleteMatrix(product, r1);
    }

    deleteMatrix(mat1, r1);
    deleteMatrix(mat2, r2);

    return 0;
}
