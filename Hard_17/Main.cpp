#include <iostream>
#include <iomanip>

using namespace std;

int** create_matrix(int row, int col);                                 // �������� �������
void input_matrix(int** matrix, int row, int col);                     // ���������� � ����� ��������� �������
void calc_char(int** matrix, int row, int col, int* sum);              // ���������� � ����� ������������� ��������
void sort_col(int **matrix, int row, int col, int* sum);               // ���������� �������� �� �� ���������������
void output_matrix(int **matrix, int row, int col);                    // ����� ������� �� �������


int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int row, col;
	
	cout << "������� ����������� ����� �������: ";
	cin >> row;
    cout << "������� ����������� �������� �������: ";
	cin >> col;

	int** matrix;
    matrix = create_matrix(row, col);

	cout << "�������� ������:" << endl << endl;
	input_matrix(matrix, row, col);

	cout << endl << "�������������� �������� �������: " << endl << endl;
	int* sum = new int[col] {};                                        // ������ ��� �������� ������������� ���������
	calc_char(matrix, row, col, sum);
	
	cout << endl << endl << "������ ����� ������������ ��������: " << endl << endl;
	sort_col(matrix, row, col, sum);
	output_matrix(matrix, row, col);

	
	for (int i = 0; i < row; i++)                                      // ������� ������ ������������ ���������
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