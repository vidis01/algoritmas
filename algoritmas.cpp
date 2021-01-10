// algoritmas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Veiksmai_Su_Matricomis.h"
#include "Strassen_Algoritmas.h"

int main() {
    int n, n_geras;
    int** matA, ** matB, ** matC;
    int chose;

    while (true) {
        cout << "Pasirinkite kokiu budu norite sudauginti matricas: " << endl;
        cout << "Standartiniu metodu iveskite 1, Strassen metodu iveskite 2" << endl;
        cin >> chose;

        switch (chose)
        {
        case 1:
            cout << "Iveskite kokios eiles yra kvadratines matricos: " << endl;
            cin >> n;

            matA = matricosSukurimas(n);
            matB = matricosSukurimas(n);

            ivedimas(matA, n);
            cout << "Matrica A: " << endl;
            matricosSpausdinimas(matA, n);

            ivedimas(matB, n);
            cout << "Matrica B: " << endl;
            matricosSpausdinimas(matB, n);

            matC = matricosSudauginimas(matA, matB, n);
            cout << "Sudauginimo rezultatas: " << endl;
            matricosSpausdinimas(matC, n);

            break;
        case 2:
            cout << "Iveskite kokios eiles yra kvadratines matricos: " << endl;
            cin >> n;

            n_geras = find_geras_matricos_laipsnis(n);

            matA = matricosSukurimas(n_geras);
            nunulinimas(matA, n_geras);
            matB = matricosSukurimas(n_geras);
            nunulinimas(matB, n_geras);

            ivedimas(matA, n);
            cout << "A matrica:" << endl;
            matricosSpausdinimas(matA, n_geras);

            ivedimas(matB, n);
            cout << "B matrica:" << endl;
            matricosSpausdinimas(matB, n_geras);

            matC = matricosSukurimas(n_geras);
            nunulinimas(matC, n_geras);
            matC = Strassen_Algoritmas(matA, matB, n_geras);
            cout << "Sudauginimo rezultatas:" << endl;
            matricosSpausdinimas(matC, n_geras);

            break;
        default:
            break;
        }
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
