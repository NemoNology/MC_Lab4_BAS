#include <iostream>
#include <iomanip>
#include "Metod_of_Jordan_Gauss.h"


using namespace std;

void Long_libe() {

    for (unsigned i = 0; i < 10; i++) {

        cout << "-----------";

    }
    
    cout << "\n\n";

}



int main()
{
    setlocale(LC_ALL, "Russian");

    // Мой массив
    // ##############################################################

    const unsigned n = 5, m = 6;

    double mat[n][m] = {
    {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };

    // ##############################################################

    double* aop[n];
    for (int i = 0; i < n; i++) {
        aop[i] = mat[i];
    }


    // Вызов метода
    cout << "\n" << setw(65) << "Метод Жордана-Гаусса: 3-я Лаб.\n";
    Long_libe();
    Jordan_Gauss(aop, n, m);
    Long_libe();


    system("pause"); // Окончание программы
    return 0;
}