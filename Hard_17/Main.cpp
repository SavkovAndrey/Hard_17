#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int row, col;
	
	cout << "������� ����������� ����� �������: ";
	cin >> row;

	cout << "������� ����������� �������� �������: ";
	cin >> col;

	int** matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
    }

	cout << "�������� ������:" << endl << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % (201) - 100;
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	system("pause");
	return 0;
}