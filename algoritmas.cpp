// algoritmas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Veiksmai_Su_Matricomis.h"
#include "Strassen_Algoritmas.h"
#include <vector>


int main() {
    int n, n_geras;
    int** matA, ** matB, ** matA2, ** matB2, ** matC;

    srand(time(NULL));

    for (size_t n = 2; n < 10; n++)
    {
        cout << "Laipsnis n = " << n << endl;
        n_geras = find_geras_matricos_laipsnis(n); //Strassen metodui

        //Standartinis budas
        matA = matricosSukurimas(n);
        matricos_sugeneravimas(matA, n);
        

        matB = matricosSukurimas(n);
        matricos_sugeneravimas(matB, n);

        auto start = std::chrono::high_resolution_clock::now();
        matC = matricosSudauginimas(matA, matB, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Standard time: " << diff.count() << endl;

        //Strassen metodu
        if (n != n_geras)
        {
            matA2 = matricosSukurimas(n_geras);
            nunulinimas(matA2, n_geras);
            matricos_kopijamivas(matA, matA2, n);
            cout << "A=" << endl;
            matricosSpausdinimas(matA2, n_geras);

            matB2 = matricosSukurimas(n_geras);
            nunulinimas(matB2, n_geras);
            matricos_kopijamivas(matB, matB2, n);
            cout << "B=" << endl;
            matricosSpausdinimas(matB2, n_geras);

            auto start = std::chrono::high_resolution_clock::now();
            matC = Strassen_Algoritmas(matA2, matB2, n_geras);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            cout << "c=" << endl;
            matricosSpausdinimas(matB2, n_geras);
            cout << "Stassen time: " << diff.count() << endl;
        }
        else {
            auto start = std::chrono::high_resolution_clock::now();
            matC = Strassen_Algoritmas(matA, matB, n);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            cout << "c=" << endl;
            matricosSpausdinimas(matC, n_geras);
            cout << "Stassen time: " << diff.count() << endl;
        }
        cout << "-------------" << endl;
    }
    
    return 0;
}

 //Run program: Ctrl + F5 or Debug > Start Without Debugging menu
 //Debug program: F5 or Debug > Start Debugging menu

 /*Tips for Getting Started: 
   1. Use the Solution Explorer window to add/manage files
   2. Use the Team Explorer window to connect to source control
   3. Use the Output window to see build output and other messages
   4. Use the Error List window to view errors
   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
   6. In the future, to open this project again, go to File > Open > Project and select the .sln file*/
