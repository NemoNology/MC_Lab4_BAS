#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;


// ������� ��� ������ 2D �������
void Show_2D_Arr(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {
            cout << setw(8) << setprecision(7) << a[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

// ������� ��� ������ 1D �������
void Show_1D_Arr(const vector<double>& a) {
    cout << "\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << setprecision(8) << "\t" << a[i] << "\n";
    }
    cout << "\n";
}


// ���������� ����������� ������� ��� 4-�� ���.
void Generate_Random_2D_Arr(vector<vector<double>>& a) {
    srand(time(NULL));
    for (unsigned short i = 0; i < a.size(); i++) {
        a[i][a.size()] = (rand() % 200 - 100.0) / 100; // �������� f ���������
        a[i][i] = (rand() % 200 - 100.0) / 100; // c - ���������
        if (i + 1.0 < a.size()) {
            a[i + 1][i] = (rand() % 200 - 100.0) / 100; // a
            a[i][i + 1] = (rand() % 200 - 100.0) / 100; // b
        }
    }
}

// ###################################################################################################################################

// 1-�� ��� ������ �������� ������� ��������������� ���� (���) - ���������� ������������
vector <double> CM_Method_Lab4(const vector<vector<double>>& a) {
    // ������������� ������� ��� ���������� �������� ����-��
    vector <double> alpha(a.size()); // ����-�� �����
    vector <double>  beta(a.size()); // ����-�� ����
    // ���������� ����-�� ����� & ����:
    alpha[1] = -a[0][1] / a[0][0];
     beta[1] =  a[0][a.size()] / a[0][0];
    for (unsigned short i = 1; i <= a.size() - 2; i++) {
        alpha[i + 1] = -a[i][i + 1] / (a[i][i] + alpha[i] * a[i][i-1]);
         beta[i + 1] = (a[i][a.size()] - a[i][i-1] * beta[i]) / (a[i][i] + alpha[i] * a[i][i-1]);
    }

    // ������������� ������� ��� ���������� �������� x - ����������� ������\�������
    vector <double> x(a.size());
    // �������� ��� ���������
    // ���������� x[n]
    // �������� ��������� � ����������� ������� x[n] ��� ������ ��������
    x[a.size() - 1] = a[a.size() - 1][a.size()] - a[a.size() - 1][a.size() - 2] * beta[a.size() - 1];
    x[a.size() - 1] = x[a.size() - 1] / (a[a.size() - 1][a.size() - 1] + a[a.size() - 1][a.size() - 2] * alpha[a.size() - 1]);
    // ���������� x[i] (i < n)
    for (short i = a.size() - 2; i >= 0; i--) {
       x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];
    };
    return x; // ���������� 1D ������� � - ������� ����������� �������
}

// ###################################################################################################################################

int main()
{
    setlocale(LC_ALL, "Russian");

    // ��� ������
    // ##############################################################

    vector<vector<double>> mat = {
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0} };


    // ##############################################################


    // ����� ������
    cout << "����������� �������:";
    Generate_Random_2D_Arr(mat);
    Show_2D_Arr(mat);
    cout << "�������� ������� �������:\n";
    Show_1D_Arr(CM_Method_Lab4(mat));
    system("pause"); // ��������� ���������
    return 0;
}
