#pragma once
#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;

int find_geras_matricos_laipsnis(int n) {

    double laipsnis = std::log2(n);
    double sveikas_laipsnis = (long)laipsnis;

    if (laipsnis - sveikas_laipsnis == 0 && n != 1)
    {
        return n;
    }
    else {
        while (true)
        {
            double matricos_laipsnis = std::pow(2, ++sveikas_laipsnis);
            if (matricos_laipsnis > n)
            {
                return matricos_laipsnis;
            }
        }
    }
}

int** matricosSukurimas(int n) {
    int** temp = new int* [n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

void nunulinimas(int** M, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}

void ivedimas(int** M, int n) {
    cout << "Iveskite matrica: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    cout << endl;
}

void matricos_sugeneravimas(int** M, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 3 + 1;
}

void matricos_kopijamivas(int** M, int** M1, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M1[i][j] = M[i][j];
}

int** matricosSudauginimas(int** M1, int** M2, int n) {
    int** temp = matricosSukurimas(n);
    nunulinimas(temp, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                temp[i][j] += M1[i][k] * M2[k][j];    
    return temp;
}

void matricosSpausdinimas(int** M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int** matricuSudetis(int** M1, int** M2, int n) {
    int** temp = matricosSukurimas(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int** matricuAtimtis(int** M1, int** M2, int n) {
    int** temp = matricosSukurimas(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}