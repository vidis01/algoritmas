#pragma once
int** Strassen_Algoritmas(int** A, int** B, int n) {
    if (n == 1) {
        int** C = matricosSukurimas(n);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int** C = matricosSukurimas(n);
    int k = n / 2;

    int** A11 = matricosSukurimas(k);
    int** A12 = matricosSukurimas(k);
    int** A21 = matricosSukurimas(k);
    int** A22 = matricosSukurimas(k);
    int** B11 = matricosSukurimas(k);
    int** B12 = matricosSukurimas(k);
    int** B21 = matricosSukurimas(k);
    int** B22 = matricosSukurimas(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    int** P1 = Strassen_Algoritmas(A11, matricuAtimtis(B12, B22, k), k);
    int** P2 = Strassen_Algoritmas(matricuSudetis(A11, A12, k), B22, k);
    int** P3 = Strassen_Algoritmas(matricuSudetis(A21, A22, k), B11, k);
    int** P4 = Strassen_Algoritmas(A22, matricuAtimtis(B21, B11, k), k);
    int** P5 = Strassen_Algoritmas(matricuSudetis(A11, A22, k), matricuSudetis(B11, B22, k), k);
    int** P6 = Strassen_Algoritmas(matricuAtimtis(A12, A22, k), matricuSudetis(B21, B22, k), k);
    int** P7 = Strassen_Algoritmas(matricuAtimtis(A11, A21, k), matricuSudetis(B11, B12, k), k);

    int** C11 = matricuAtimtis(matricuSudetis(matricuSudetis(P5, P4, k), P6, k), P2, k);
    int** C12 = matricuSudetis(P1, P2, k);
    int** C21 = matricuSudetis(P3, P4, k);
    int** C22 = matricuAtimtis(matricuAtimtis(matricuSudetis(P5, P1, k), P3, k), P7, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }
    return C;
}