#include <iostream>
using namespace std;

//Создание матрицы
class Matrix
{
private:
	int rows, cols;
	double** Array;
public:
	//Конструкторы класса
	Matrix()
	{
		rows = cols = 0;
		Array = nullptr;
	}
	//Конструктор с двумя параметрами
	Matrix(int n, int m)
	{
		SetMatrix(n, m);
	}
	//Метод создания матрицы
	void SetMatrix(int n, int m)
	{
		rows = n;
		cols = m;
		//Выделение памяти под массив
		Array = new double* [rows]; 
		for (int i = 0; i < rows; i++)
			Array[i] = new double[cols];
		//Заполнение массива случайными дробными числами от 0 до 100
		srand(time(NULL));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Array[i][j] = ((double)rand() / (double)(RAND_MAX)) * 100;
			}
		}
	}
	//Метод вывода матрицы на экран пользователя
	void GetMatrix()
	{
		cout << "Ваша матрица:\n";
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
	//Освобождение памяти
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
	cout << "Введите количество строк матрицы: ";
	cin >> n;
	cout << "Введите количество столбцов матрицы: ";
	cin >> m;
	cout << "\n";
	B.SetMatrix(n, m);
	B.GetMatrix();

	return 0;
}