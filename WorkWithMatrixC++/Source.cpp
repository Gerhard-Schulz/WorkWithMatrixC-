#include <iostream>
using namespace std;

//�������� �������
class Matrix
{
private:
	int rows, cols;
	double** Array;
public:
	//������������ ������
	Matrix()
	{
		rows = cols = 0;
		Array = nullptr;
	}
	//����������� � ����� �����������
	Matrix(int n, int m)
	{
		SetMatrix(n, m);
	}
	//����� �������� �������
	void SetMatrix(int n, int m)
	{
		rows = n;
		cols = m;
		//��������� ������ ��� ������
		Array = new double* [rows]; 
		for (int i = 0; i < rows; i++)
			Array[i] = new double[cols];
		//���������� ������� ���������� �������� ������� �� 0 �� 100
		srand(time(NULL));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Array[i][j] = ((double)rand() / (double)(RAND_MAX)) * 100;
			}
		}
	}
	//����� ������ ������� �� ����� ������������
	void GetMatrix()
	{
		cout << "���� �������:\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << Array[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	//������������ ������
	void FreeMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] Array[i];
		}
		delete[] Array;
	}
};

int main()
{
	setlocale(0, "russian");

	Matrix A(3, 5);
	A.GetMatrix(); 

	Matrix B;
	int n, m;
	cout << "������� ���������� ����� �������: ";
	cin >> n;
	cout << "������� ���������� �������� �������: ";
	cin >> m;
	cout << "\n";
	B.SetMatrix(n, m);
	B.GetMatrix();

	return 0;
}