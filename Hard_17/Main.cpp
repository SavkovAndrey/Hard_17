#include <iostream>
#include <iomanip>

using namespace std;

int** create_matrix(int row, int col);                                 // Создание матрицы
void input_matrix(int** matrix, int row, int col);                     // Заполнение и вывод стартовой матрицы
void calc_char(int** matrix, int row, int col, int* sum);              // вычисление и вывод характеристик столбцов
void sort_col(int **matrix, int row, int col, int* sum);               // сортировка столбцов по их характеристикам
void output_matrix(int **matrix, int row, int col);                    // вывод матрицы на консоль


int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int row, col;
	
	cout << "Введите колличество строк матрицы: ";
	cin >> row;
    cout << "Введите колличество столбцов матрицы: ";
	cin >> col;

	int** matrix;
    matrix = create_matrix(row, col);

	cout << "Исходный массив:" << endl << endl;
	input_matrix(matrix, row, col);

	cout << endl << "Характеристики столбцов массива: " << endl << endl;
	int* sum = new int[col] {};                                        // массив для хранения характеристик столюбцов
	calc_char(matrix, row, col, sum);
	
	cout << endl << endl << "Массив после перестановеи столбцов: " << endl << endl;
	sort_col(matrix, row, col, sum);
	output_matrix(matrix, row, col);

	
	for (int i = 0; i < row; i++)                                      // очищаем память динамических массивово
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] sum;

	system("pause");
	return 0;
}



//---------------------------------------------------------------------------------------------------
int** create_matrix(int row, int col)
{
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	return matrix;
}

//----------
void input_matrix(int** matrix, int row, int col)
{
	for (int i = 0; i < row; i++)                               
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % (201) - 100;
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

//----------
void calc_char(int** matrix, int row, int col, int* sum)
{
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			if (matrix[i][j] < 0 && abs(matrix[i][j]) % 2 == 1)
			{
				sum[j] += abs(matrix[i][j]);
			}
		}
		cout << setw(5) << sum[j];
	}
}

//----------
void sort_col(int** matrix, int row, int col, int* sum)          
{
	int temp = 0;
	int* temp_mass = new int[row];

	for (int k = 0; k < col; k++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			if (sum[j] > sum[j + 1])
			{
				temp = sum[j];
				sum[j] = sum[j + 1];
				sum[j + 1] = temp;

				for (int i = 0; i < row; i++)
				{
					temp_mass[i] = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = temp_mass[i];
				}

			}
		}
	}

	delete[] temp_mass;
}

//----------
void output_matrix(int **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}