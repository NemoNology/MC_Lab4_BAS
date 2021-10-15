#include <iostream>
#include <iomanip>
#include <exception>


using namespace std;

// Функция для вывода матрицы
void Show_matr(double** p, unsigned n, unsigned m) {
    cout << "\n\n";
    for (unsigned i = 0; i < n; i++) {
        cout << "\t";
        for (unsigned j = 0; j < m; j++) {
            cout << setw(14) << setprecision(8) << p[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}



// 0-ой шаг - "Проверка ранга" матрицы
bool step0(double** p, unsigned k, unsigned n, unsigned m) {


    for (unsigned i = k; i < n; i++) { // Проверяем элементы под p[k][k], 
                            //чтобы знать, возможно ли поменять строки местами
        if (p[i][k] != 0) {

            return i; // Останавливаемся, если "ранг" матрицы не нулевой

        }
    }

    // Бросаем ошибку, если ранг матрицы равен 0
    throw domain_error("Ранг матрицы равен 0"); 

}


// 

// 1-ый шаг метода Жаргана-Гаусса - перестановка строки a[k][k] с не нулевой строкой
void step1(double** p, unsigned k, unsigned n, unsigned m, unsigned line) {

    if (line == k) { // Проверка на то, нужно ли вообще менять строку...
        return;
    }

    double temp; // Создание переменной для перестановки местами элемонтов в строках...


    for (unsigned i = k; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {

            temp = p[k][j];
            p[k][j] = p[line][j];
            p[line][j] = temp;

        }
    }

}


// 2-ой шаг метода Жаргана-Гаусса - вычисление a[i][j], при i != k & j > k & "Обнуление" элементов под a[k][k] 
void step2(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = k + 1; j < m; j++) {
            if (i != k) {

                p[i][j] = (p[i][j] * p[k][k] - p[i][k] * p[k][j]) / p[k][k];

            }
        }
    }

}


// 3-ий шаг метода Жаргана-Гаусса - "Обнуление" элементов в столбце k
void step3(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned i = 0; i < n; i++) {
        if (i != k) {

            p[i][k] = 0;

        }
    }

}

// 4-ый шаг метода Жаргана-Гаусса - Вычисление a[k][j]
void step4(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned j = m - 1; j + 1 > k; j--) {

        p[k][j] /= p[k][k];

    }
}


// Метод Жордана-Гаусса в виде модуля, состоящего из множества функций (Шагов)
void Jordan_Gauss_L3(double** aop, const unsigned n, const unsigned m) {

    // Вывод изначальной матрицы
    cout << "Изначальная матрица:";
    Show_matr(aop, n, m);
    unsigned line = 0;

    // Сообственно сам метод:
    for (unsigned k = 0; k < n; k++) {

        try { line = step0(aop, k, n, m) + 1; } // Проверяем "ранг" матрицы

        catch (domain_error e) { // Ловим ошибку, если ранг матрицы равен 0

            cout << "\nМатрица не соответсвует условиям: ранг равен 0!\n";
            break;

        }
        step1(aop, k, n, m, line);
        step2(aop, k, n, m);
        step3(aop, k, n, m);
        step4(aop, k, n, m);

    }
    
    // Вывод итоговой матрицы
    cout << "Итоговая матрица:";
    Show_matr(aop, n, m);
}