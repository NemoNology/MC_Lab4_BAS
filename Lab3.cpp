#include <iostream>
#include <iomanip>
#include <exception>


using namespace std;

// ������� ��� ������ �������
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



// 0-�� ��� - "�������� �����" �������
bool step0(double** p, unsigned k, unsigned n, unsigned m) {


    for (unsigned i = k; i < n; i++) { // ��������� �������� ��� p[k][k], 
                            //����� �����, �������� �� �������� ������ �������
        if (p[i][k] != 0) {

            return i; // ���������������, ���� "����" ������� �� �������

        }
    }

    // ������� ������, ���� ���� ������� ����� 0
    throw domain_error("���� ������� ����� 0"); 

}


// 

// 1-�� ��� ������ �������-������ - ������������ ������ a[k][k] � �� ������� �������
void step1(double** p, unsigned k, unsigned n, unsigned m, unsigned line) {

    if (line == k) { // �������� �� ��, ����� �� ������ ������ ������...
        return;
    }

    double temp; // �������� ���������� ��� ������������ ������� ��������� � �������...


    for (unsigned i = k; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {

            temp = p[k][j];
            p[k][j] = p[line][j];
            p[line][j] = temp;

        }
    }

}


// 2-�� ��� ������ �������-������ - ���������� a[i][j], ��� i != k & j > k & "���������" ��������� ��� a[k][k] 
void step2(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = k + 1; j < m; j++) {
            if (i != k) {

                p[i][j] = (p[i][j] * p[k][k] - p[i][k] * p[k][j]) / p[k][k];

            }
        }
    }

}


// 3-�� ��� ������ �������-������ - "���������" ��������� � ������� k
void step3(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned i = 0; i < n; i++) {
        if (i != k) {

            p[i][k] = 0;

        }
    }

}

// 4-�� ��� ������ �������-������ - ���������� a[k][j]
void step4(double** p, unsigned k, unsigned n, unsigned m) {

    for (unsigned j = m - 1; j + 1 > k; j--) {

        p[k][j] /= p[k][k];

    }
}


// ����� �������-������ � ���� ������, ���������� �� ��������� ������� (�����)
void Jordan_Gauss_L3(double** aop, const unsigned n, const unsigned m) {

    // ����� ����������� �������
    cout << "����������� �������:";
    Show_matr(aop, n, m);
    unsigned line = 0;

    // ����������� ��� �����:
    for (unsigned k = 0; k < n; k++) {

        try { line = step0(aop, k, n, m) + 1; } // ��������� "����" �������

        catch (domain_error e) { // ����� ������, ���� ���� ������� ����� 0

            cout << "\n������� �� ������������ ��������: ���� ����� 0!\n";
            break;

        }
        step1(aop, k, n, m, line);
        step2(aop, k, n, m);
        step3(aop, k, n, m);
        step4(aop, k, n, m);

    }
    
    // ����� �������� �������
    cout << "�������� �������:";
    Show_matr(aop, n, m);
}