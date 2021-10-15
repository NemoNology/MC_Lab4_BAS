// Функция для вывода матрицы
void Show_matr(double** p, unsigned n, unsigned m);

// 0-ой шаг - "Проверка ранга" матрицы
unsigned step0(double** p, unsigned k, unsigned n, unsigned m);

// 1-ый шаг метода Жаргана-Гаусса - проверка на a[k][k] == 0
void step1(double** p, unsigned k, unsigned n, unsigned m, unsigned line);


// 2-ой шаг метода Жаргана-Гаусса - вычисление a[i][j], при i != k & j > k & "Обнуление" элементов под a[k][k] 
void step2(double** p, unsigned k, unsigned n, unsigned m);


// 3-ий шаг метода Жаргана-Гаусса - "Обнуление" элементов в столбце k
void step3(double** p, unsigned k, unsigned n, unsigned m);


// 4-ый шаг метода Жаргана-Гаусса - Вычисление a[k][j]
void step4(double** p, unsigned k, unsigned n, unsigned m);


// Метод Жордана-Гаусса в виде модуля, состоящего из множества функций (Шагов)
void Jordan_Gauss_L3(double** aop, const unsigned n, const unsigned m);