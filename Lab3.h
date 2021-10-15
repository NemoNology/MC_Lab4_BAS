// ������� ��� ������ �������
void Show_matr(double** p, unsigned n, unsigned m);

// 0-�� ��� - "�������� �����" �������
unsigned step0(double** p, unsigned k, unsigned n, unsigned m);

// 1-�� ��� ������ �������-������ - �������� �� a[k][k] == 0
void step1(double** p, unsigned k, unsigned n, unsigned m, unsigned line);


// 2-�� ��� ������ �������-������ - ���������� a[i][j], ��� i != k & j > k & "���������" ��������� ��� a[k][k] 
void step2(double** p, unsigned k, unsigned n, unsigned m);


// 3-�� ��� ������ �������-������ - "���������" ��������� � ������� k
void step3(double** p, unsigned k, unsigned n, unsigned m);


// 4-�� ��� ������ �������-������ - ���������� a[k][j]
void step4(double** p, unsigned k, unsigned n, unsigned m);


// ����� �������-������ � ���� ������, ���������� �� ��������� ������� (�����)
void Jordan_Gauss_L3(double** aop, const unsigned n, const unsigned m);