﻿#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


// Функция для вывода 2D матрицы
void Show_2D_Arr(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {

            cout << setw(14) << setprecision(7) << a[i][j];

        }
        cout << endl;
    }
    cout << "\n\n";
}


// Функция для вывода 1D матрицы
void Show_1D_Arr(const vector<double>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {

        cout << setprecision(7) << "\t" << a[i] << "\n";

    }
    cout << "\n\n";
}


// Генерируем изначальную матрицу для 4-ой лаб.
void Generate_Random_2D_Arr(vector<vector<double>>& a) {


    for (unsigned short i = 0; i < a.size(); i++) {

        a[i][a.size()] = (rand() % 200 - 100.0) / 100; // создание f элементов
        a[i][i] = (rand() % 200 - 100.0) / 100; // c[i][j] - диагональ

        if (i + 1 < a.size()) {
            a[i + 1][i] = (rand() % 200 - 100.0) / 100; // a[i][j]
            a[i][i + 1] = (rand() % 202 - 100.0) / 100; // b[i][j]
        }
        
        
    }

}

// ###################################################################################################################################

// 1-ый шаг метода прогонки решения трёхдиагональных СЛАУ (МПР) - Вычисление коэффицентов
vector<double> CM_Method_Lab4(const vector<vector<double>>& a) {

    // Инициальзация вектора для сохранения значения коэф-ов
    vector <double> alpha(a.size()); // Коэф-ци альфа
    vector <double> beta(a.size()); // Коэф-ци бета


    // Вычисление коэф-ов альфа & бета:
    alpha[0] = -a[0][1] / a[0][0];
    beta[0] = a[0][a.size()] / a[0][0];


    for (unsigned short i = 0; i < a.size() - 1; i++) {

        alpha[i + 1] = -a[i][i + 1] / (a[i][i] + (alpha[i] * a[i + 1][i]));
        beta[i + 1] = (a[i][a.size()] - (a[i + 1][i] * beta[i])) / (a[i][i] + (alpha[i] * a[i + 1][i]));

    }

    // Инициальзация вектора для сохранения значения x - результатов метода\решения
    vector <double> x(a.size());

    // Обратный ход алгоритма
    // Вычисление x[n]
    // Разделяю числитель и знаменатель формулы x[n] для своего удобства
    x[1] = a[a.size() - 1][a.size()] - (a[a.size() - 1][a.size() - 2] * beta[a.size() - 1]);
    x[2] = a[a.size() - 1][a.size() - 1] + (a[a.size() - 1][a.size() - 2] * alpha[a.size() - 1]);

    x[a.size() - 1] = x[1] / x[2];

    // Вычисление x[i] (i < n)
    for (unsigned short i = a.size() - 2; i > 0; i--) {

        x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];

    }

    x[0] = x[1] * alpha[1] + beta[1];


    return x; // Возвращаем 1D матрицу х - матрицу результатов решения
}

// ###################################################################################################################################

int main()
{
    setlocale(LC_ALL, "Russian");

    // Мой массив
    // ##############################################################

    vector<vector<double>> mat = {
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0} };

    /*
    {
    {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };
    */

    // ##############################################################


    // Вызов метода
    cout << "Изначальная матрица:";
    Generate_Random_2D_Arr(mat);
    Show_2D_Arr(mat);
    cout << "Итоговая матрица ответов:";
    Show_1D_Arr(CM_Method_Lab4(mat));

    system("pause"); // Окончание программы
    return 0;
}