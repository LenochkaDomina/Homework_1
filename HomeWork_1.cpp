#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#pragma region Includes
#include "windows.h"
using namespace std;

int main()
{
#pragma region Ukrainian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	cout << "413 Domina Olena Homework" << endl;

	cout << "������ ����� ��������:"
		<< endl
		<< "1  ������� ������������ �����"
		<< endl
		<< "2  �������� �������� ������"
		<< endl
		<< "3  ���������� �� ������������"
		<< endl
		<< "4  �������� ������ ����'����� �����"
		<< endl
		<< "5  �������� ������"
		<< endl
		<< "6  ������� ����������"
		<< endl
		<< "7  ̳������� �� ����������� �����"
		<< endl
		<< "8  �������� ������� ���� � ����"
		<< endl
		<< "9  �������� � �� b � ����"
		<< endl
		<< "10 ���� ������ �����"
		<< endl
		<< "11 ³������ �� ����"
		<< endl
		<< "12 ����������� ������� �� ����"
		<< endl
		<< "13 ������� ����"
		<< endl
		<< "14 ���� n ������� � ������ �� 0 �� n"
		<< endl;
	int numTask;
	cin >> numTask;

	switch (numTask)
	{
	case 1:
	{
		int a, num_o, num_t, num_h;
		cout << "������ ������� ���������� ����� ";
		cin >> a;
		num_o = a % 10;
		num_t = a % 100 / 10;
		num_h = a / 100;

		cout << "ʳ������ ������� = "
			<< num_o
			<< endl
			<< "ʳ������ ������� = "
			<< num_t
			<< endl
			<< "���� ���� = "
			<< num_h + num_t + num_o
			<< endl
			<< "������� ���� = "
			<< num_h * num_t * num_o
			<< endl;
		break;
	}
	case 2:
	{
		cout << "����������� �������� �������� ������:\n"
			<< "�) (�� � ��� �� �) �� �� �;\n"
			<< "�) (�� � ��� �� �) �� (� ��� �);\n"
			<< "�) � �� � ��� � �� � ��� �� �.\n"
			<< "�� ������������� � = False, B = False, C = True\n"
			<< "�������� 1, ��� ����������� ������ �� �������������, ��� �������� 2, ��� ������ ��� ��������"
			<< endl;

		int task;
		cin >> task;

		if (task != 1 && task != 2)
		{
			cout << "������ �������� 1 ��� 0" << endl;
		}

		bool a = 0, b = 0, c = 1;

		if (task == 2)
		{
			cout << "��� ������ �������� False, �������� 0.\n"
				<< "��� ������ �������� True, �������� 1.\n"
				<< "A = ";
			cin >> a;
			cout << "B = ";
			cin >> b;
			cout << "C = ";
			cin >> c;
		}
	
		cout << boolalpha
			<< "a) "
			<< ((!a || !b) && !c)
			<< "\n�) "
			<< ((!a || !b) && (a || b))
			<< "\n�) "
			<< ((a && b || a) && c || !c)
			<< endl;
			
		break;
	}
	case 3:
	{
		cout << "� ��� ������������ � ���������, ������������ ���� ���������.\n"
			<< "���������� ��������� ���������� �������� ����� �� ��������� ������� ���� ������������, �� ������ ���.\n"
			<< "��� ���������� ������ ���������� ���� ����� ���� �� ������� ����� ������������.\n";
		// l - length, w - width
		//0 2 ������� ��� ������� ������������
		//1 3 ������� ��� ������� ������������
		// l[0] w[0] first
		// l[1] w[1] second
		
		double x[4], y[4], l[2], w[2];

		cout << "������ �����������\n"
			<< "����������: ";
		cin >> x[0] >> y[0];
		cout << "������� � ������: ";
		cin >> l[0] >> w[0];
		cout << "������ �����������\n"
			<< "����������: ";
		cin >> x[1] >> y[1];
		cout << "������� � ������: ";
		cin >> l[1] >> w[1];

		//������� ���������� ������ ������ ����
		for (int i = 0; i < 2; i++)
		{
			x[i + 2] = x[i] + l[i];
			y[i + 2] = y[i] + w[i];
		}

		//���� ����� ��������� res_x0 res_y0
		//������ ������ ��������� res_x1 res_y1
		double res_x0 = x[0], res_y0 = y[0], res_x1 = x[2], res_y1 = y[2];

		if (x[0] > x[1])
		{
			res_x0 = x[1];
		}

		if (y[0] > y[1])
		{
			res_y0 = y[1];
		}

		if (x[2] < x[3])
		{
			res_x1 = x[3];
		}

		if (y[2] < y[3])
		{
			res_y1 = y[3];
		}

		cout << "���������� ����� �������� ����: ( "
			<< res_x0
			<< " ; "
			<< res_y0
			<< " )\n���������� ������� ��������� ����: ( "
			<< res_x1
			<< " ; "
			<< res_y1
			<< " )\n�������: "
			<< res_x1 - res_x0
			<< "\n������: "
			<< res_y1 - res_y0
			<< endl;
		break;
	}
	case 4:
	{
		double arr[3];
		cout << "������ 3 ������ �����\n";
		cin >> arr[0] >> arr[1] >> arr[2];

		for (int i = 0; i < 3; i++)
		{
			if (arr[i] >= 0)
			{
				arr[i] *= arr[i];
			}

			cout << arr[i] << " ";
		}
		break;
	}
	case 5:
	{
		cout << "���������� sin(x) � ������ h\n"
			<< "�������� 1 ��� ������� �� ������������� ��� 2 - ��� ����� x �� h."
			<< endl;

		int task;
		cin >> task;

		if (task != 1 && task != 2)
		{
			cout << "�������� 1 ��� 2" << endl;
		}

		double i = 0.1, x = 1.1, h = 0.1;
		
		if (task == 2)
		{
			cout << "��������� �������� x = ";
			cin >> i;
			cout << "ʳ����� �������� x = ";
			cin >> x;
			cout << "h = ";
			cin >> h;
		}

		do
		{
			cout << "sin( "
				<< i
				<< " ) = "
				<< sin(i)
				<< endl;

			i += h;
		} while (i <= x);
		break;
	}
	case 6:
	{
		cout << "��� ������ ������ �������� � ������ ����� �����, � ������ - ������� ����������.\n"
			<< "�������� ������ ������� �������, ������ � ������, �� ������� ���������� �� ������.\n";
		const int numRow = 2;
		const int numCol = 10;
		double arr[numRow][numCol];

		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol; j++)
			{
				cin >> arr[i][j];
			}
		}

		double area = 0, sum = 0;

		for (int i = 0; i < numCol; i++)
		{
			area += arr[0][i];
			sum += arr[1][i];
		}
		
		cout << "ǳ����� �������: "
			<< sum
			<< " �/��\n������� ����������: "
			<< sum / area
			<< " �/��";
		break;
	}
	case 7:
	{
		int num;
		cout << "������ ���������� �����." << endl;
		cin >> num;
		vector<int> arr;

		for (int i = 0; num > 0; i++)
		{
			//arr[i] = num % 10;
			arr.insert(arr.begin(), (num % 10));
			num /= 10;
		}
		sort(arr.begin(), arr.end());

		cout << "����������� �����: "
			<< arr[arr.size() - 1]
			<< "\n̳������� �����: "
			<< arr[0];

		break;
	}
	case 8:
	{
		cout << "���������� ������� �������� � ���� ����� 3 (�) �� ���� ���� 2 �� 5 (�).\n"
			<< "������ ���������� �����." 
			<< endl;
		int num;
		cin >> num;
		vector<int> arr;

		for (int i = 0; num > 0; i++)
		{
			//arr[i] = num % 10;
			arr.insert(arr.begin(), (num % 10));
			num /= 10;
		}
		
		const int numEl = 3;
		int mas[numEl] = { 3, 2, 5 };
		bool mas_b[numEl] = { 0, 0, 0 };

		for (int j = 0; j < numEl; j++)
		{
			int i = 0;

			do
			{
				i++;
			} while (arr[i - 1] != mas[j] && i < arr.size());


			if (arr[i - 1] == mas[j])
			{
				mas_b[j] = 1;
			}			
		}
		
		if (mas_b[0])
		{
			cout << "�) � ���� � ����� "
				<< mas[0]
				<< "."
				<< endl;
		}
		else
		{
			cout << "�) � ���� ���� ����� "
				<< mas[0]
				<< "."
				<< endl;
		}

		if (mas_b[1] && mas_b[2])
		{
			cout << "�) � ���� � ����� "
				<< mas[1]
				<< " �� "
				<< mas[2]
				<< "."
				<< endl;
		}
		else
		{
			cout << "�) � ���� ���� ���� "
				<< mas[1]
				<< " �� "
				<< mas[2]
				<< "."
				<< endl;
		}

		break;
	}
	case 9:
	{
		cout << "������ ���������� �����" << endl;
		int num;
		cin >> num;
		vector<int> arr;

		for (int i = 0; num > 0; i++)
		{
			//arr[i] ���� ����������� ����� ������� ������ 
			arr.push_back(num % 10);
			num /= 10;
		}

		//mas - ����� ��� � �� b
		//mas_b - ������ ���� �������� ��� ��������� �����
		//masInd - ������ ������ ���������� �����
		const int sizeMas = 2;
		int mas[sizeMas];
		cout << "������ 2 �����, �� ��������� ������" << endl;
		for (int i = 0; i < sizeMas; i++)
		{
			cin >> mas[i];
		}
		bool mas_b[sizeMas] = { 0, 0 };
		int masInd[sizeMas];

		for (int j = 0; j < sizeMas; j++)
		{
			int i = 0;

			do
			{
				i++;
			} while (arr[i - 1] != mas[j] && i < arr.size());


			if (arr[i - 1] == mas[j])
			{
				mas_b[j] = 1;
				masInd[j] = i;
			}
		}

		if (mas_b[0] && mas_b[1])
		{
			if (masInd[0] > masInd[1])
			{
				cout << "����� "
					<< mas[0]
					<< " ����������� ���� �� ����� "
					<< mas[1]
					<< endl;
			}
			else
			{
				cout << "����� "
					<< mas[1]
					<< " ����������� ���� �� ����� "
					<< mas[0]
					<< endl;
			}
		}
		else if (mas_b[0] && !mas_b[1])
		{
			cout << "� ���� � ���� ����� "
				<< mas[0]
				<< endl;
		}
		else if (!mas_b[0] && mas_b[1])
		{
			cout << "� ���� � ���� ����� "
				<< mas[1]
				<< endl;
		}
		else if (!mas_b[0] && !mas_b[1])
		{
			cout << "� ���� ���� ���� "
				<< mas[0]
				<< ""
				<< mas[1]
				<< endl;
		}

		break;
	}
	case 10:
	{
		const int sizeArr = 15;
		float arr[sizeArr];

		cout << "������ ����� � 15-�� ��������. ���������� ������ ���� ��� �������� ��������, ���������� �� -1." << endl;
		for (int i = 0; i < sizeArr; i++)
		{
			cin >> arr[i];
		}

		float sum = 0;
		for (int i = 0; i < sizeArr; i += 2)
		{
			sum -= arr[i];
		}

		cout << "���� �������� �������� ������ "
			<< sum
			<< endl;
		break;
	}
	case 11:
	{
		cout << "������ ��� �� ������ ������?" << endl;
		
		int cityNum;
		cin >> cityNum;
		
		vector<string> city;
		city.resize(cityNum);
		vector<float> dist;
		dist.resize(cityNum);
		
		cout << "������ �� ���� ����� ���� �� ������� �� ����� (� ��.)" << endl;
		for (int i = 0; i < cityNum; i++)
		{
			cin >> city[i];
			cin >> dist[i];
		}

		int max = 0;
		for (int i = 1; i < cityNum; i++)
		{
			if (dist[i] > dist[i - 1])
			{
				max = i;
			}
		}

		cout << "������������ ����: "
			<< city[max]
			<< "\n³������ �� ����� ����: "
			<< dist[max]
			<< " ��."
			<< endl;

		break;
	}
	case 12:
	{
		cout << "������ ����������� ���� �� �������:" << endl;
		string base;
		cin >> base;

		int min = base.length(), seq = 0;

		//cout << base.length() << endl;

		if (base.find('0') == string::npos)
		{
			cout << "� ����������� ���� ����." << endl;
			break;
		}

		for (int i = 0; i < base.length(); i++)
		{
			if (base[i] == '0')
			{
				seq++;
			}
			else
			{
				if (seq < min && seq != 0)
				{
					min = seq;
				}
				seq = 0;
			}
		}

		if (seq < min && seq != 0)
		{
			min = seq;
		}

		cout << "�������� ����������� ����: "
			<< min
			<< endl;

		break;
	}
	case 13:
	{
		const int numRow = 8;
		const int numCol = 5;
		int arr[numRow][numCol];

		cout << "������ 1, ���� ������ ������� �������� �� ���������\n"
			<< "������ 2, ���� ������ ������� �������� �� �������"
			<< endl;
		int task;
		cin >> task;

		switch (task)
		{
		case 1:
		{
			for (int i = 0; i < numCol; i++)
			{
				cout << "������ ���� ��� �������� �� �������� �" << i + 1 << endl;
				for (int j = 0; j < numRow; j++)
				{
					cin >> arr[j][i];
				}
			}

			break;
		}
		case 2:
		{
			for (int i = 0; i < numRow; i++)
			{
				cout << "������ ���� �� ��� ��������� ��� �������� �" << i + 1 << endl;
				for (int j = 0; j < numCol; j++)
				{
					cin >> arr[i][j];
				}
			}
		}
		default:
		{
			cout << "������ �������� 1 ��� 2." << endl;
			break;
		}
		}

		cout << "�������� ������� ����:\n"
			<< "   1   2   3   4   5"
			<< endl;
		for (int i = 0; i < numRow; i++)
		{
			cout << i + 1 << " ";
			for (int j = 0; j < numCol; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		break;
	}
	case 14:
	{
		int n;
		cout << "������ �������� ������� �������:\n"
			<< "n = ";
		cin >> n;
		double sum = 0;

		for (int i = 1; i < n + 1; i++)
		{
			sum += pow(i, i);
		}

		cout << "Sum = "
			<< fixed
			<< setprecision(0)
			<< sum
			<< endl;
		break;
	}
	default:
	{
		cout << "������ ����� �������� �� 1 �� 14";
		break;
	}
	}

}