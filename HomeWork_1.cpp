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

	cout << "Оберіть номер завдання:"
		<< endl
		<< "1  Розряди трицифрового числа"
		<< endl
		<< "2  Значення логічного виразу"
		<< endl
		<< "3  Координати та прямокутники"
		<< endl
		<< "4  Квадрати дійсних невід'ємних чисел"
		<< endl
		<< "5  Значення синуса"
		<< endl
		<< "6  Середня врожайність"
		<< endl
		<< "7  Мінімальна та максимальна цифра"
		<< endl
		<< "8  Наявність заданих цифр в числі"
		<< endl
		<< "9  Наявність а та b в числі"
		<< endl
		<< "10 Сума дійсних чисел"
		<< endl
		<< "11 Відстань до міста"
		<< endl
		<< "12 Послідовність одиниць та нулів"
		<< endl
		<< "13 Таблиця балів"
		<< endl
		<< "14 Сума n доданків у степені від 0 до n"
		<< endl;
	int numTask;
	cin >> numTask;

	switch (numTask)
	{
	case 1:
	{
		int a, num_o, num_t, num_h;
		cout << "Введіть довільне трицифрове число ";
		cin >> a;
		num_o = a % 10;
		num_t = a % 100 / 10;
		num_h = a / 100;

		cout << "Кількість одиниць = "
			<< num_o
			<< endl
			<< "Кількість десятків = "
			<< num_t
			<< endl
			<< "Сума цифр = "
			<< num_h + num_t + num_o
			<< endl
			<< "Добуток цифр = "
			<< num_h * num_t * num_o
			<< endl;
		break;
	}
	case 2:
	{
		cout << "Розрахувати значення логічного виразу:\n"
			<< "а) (не А або не В) та не С;\n"
			<< "б) (не А або не В) та (А або В);\n"
			<< "в) А та В або А та С або не С.\n"
			<< "За замовчуванням А = False, B = False, C = True\n"
			<< "Натисніть 1, щоб розрахувати вирази за замовчуванням, або натисніть 2, щоб ввести свої значення"
			<< endl;

		int task;
		cin >> task;

		if (task != 1 && task != 2)
		{
			cout << "Введіть значення 1 або 0" << endl;
		}

		bool a = 0, b = 0, c = 1;

		if (task == 2)
		{
			cout << "Щоб ввести значення False, натисніть 0.\n"
				<< "Щоб ввести значення True, натисніть 1.\n"
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
			<< "\nб) "
			<< ((!a || !b) && (a || b))
			<< "\nв) "
			<< ((a && b || a) && c || !c)
			<< endl;
			
		break;
	}
	case 3:
	{
		cout << "Є два прямокутники зі сторонами, паралельними вісям координат.\n"
			<< "Застосунок знаходить координату нижнього лівого та верхнього правого кутів прямокутника, що обмежує дані.\n"
			<< "Для розрахунку введіть координати лівих нижніх кутів та довжини сторін прямокутників.\n";
		// l - length, w - width
		//0 2 індекси для першого прямокутника
		//1 3 індекси для другого прямокутника
		// l[0] w[0] first
		// l[1] w[1] second
		
		double x[4], y[4], l[2], w[2];

		cout << "ПЕРШИЙ ПРЯМОКУТНИК\n"
			<< "Координати: ";
		cin >> x[0] >> y[0];
		cout << "Довжина і ширина: ";
		cin >> l[0] >> w[0];
		cout << "ДРУГИЙ ПРЯМОКУТНИК\n"
			<< "Координати: ";
		cin >> x[1] >> y[1];
		cout << "Довжина і ширина: ";
		cin >> l[1] >> w[1];

		//знайшли координати правих верхніх кутів
		for (int i = 0; i < 2; i++)
		{
			x[i + 2] = x[i] + l[i];
			y[i + 2] = y[i] + w[i];
		}

		//лівий нижній загальний res_x0 res_y0
		//правий верхній загальний res_x1 res_y1
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

		cout << "Координати лівого нижнього кута: ( "
			<< res_x0
			<< " ; "
			<< res_y0
			<< " )\nКоординати правого верхнього кута: ( "
			<< res_x1
			<< " ; "
			<< res_y1
			<< " )\nДовжина: "
			<< res_x1 - res_x0
			<< "\nШирина: "
			<< res_y1 - res_y0
			<< endl;
		break;
	}
	case 4:
	{
		double arr[3];
		cout << "Введіть 3 дійсних числа\n";
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
		cout << "Розрахунок sin(x) з кроком h\n"
			<< "Натисніть 1 для значень за замовчуванням або 2 - для вводу x та h."
			<< endl;

		int task;
		cin >> task;

		if (task != 1 && task != 2)
		{
			cout << "Натисніть 1 або 2" << endl;
		}

		double i = 0.1, x = 1.1, h = 0.1;
		
		if (task == 2)
		{
			cout << "Початкове значення x = ";
			cin >> i;
			cout << "Кінцеве значення x = ";
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
		cout << "Для десяти районів випишіть в перший рядок площі, у другий - середню врожайність.\n"
			<< "Програма порахує кількість пшениці, зібраної в області, та середню врожайність по області.\n";
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
		
		cout << "Зібрано пшениці: "
			<< sum
			<< " ц/га\nСередня врожайність: "
			<< sum / area
			<< " ц/га";
		break;
	}
	case 7:
	{
		int num;
		cout << "Введіть натуральне число." << endl;
		cin >> num;
		vector<int> arr;

		for (int i = 0; num > 0; i++)
		{
			//arr[i] = num % 10;
			arr.insert(arr.begin(), (num % 10));
			num /= 10;
		}
		sort(arr.begin(), arr.end());

		cout << "Максимальна цифра: "
			<< arr[arr.size() - 1]
			<< "\nМінімальна цифра: "
			<< arr[0];

		break;
	}
	case 8:
	{
		cout << "Застосунок перевіре наявність у числі цифри 3 (а) та пари цифр 2 та 5 (б).\n"
			<< "Введіть натуральне число." 
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
			cout << "а) У числі є цифра "
				<< mas[0]
				<< "."
				<< endl;
		}
		else
		{
			cout << "а) У числі нема цифри "
				<< mas[0]
				<< "."
				<< endl;
		}

		if (mas_b[1] && mas_b[2])
		{
			cout << "б) У числі є цифри "
				<< mas[1]
				<< " та "
				<< mas[2]
				<< "."
				<< endl;
		}
		else
		{
			cout << "б) У числі нема цифр "
				<< mas[1]
				<< " та "
				<< mas[2]
				<< "."
				<< endl;
		}

		break;
	}
	case 9:
	{
		cout << "Введіть натуральне число" << endl;
		int num;
		cin >> num;
		vector<int> arr;

		for (int i = 0; num > 0; i++)
		{
			//arr[i] буде переписаним задом наперед числом 
			arr.push_back(num % 10);
			num /= 10;
		}

		//mas - масив для а та b
		//mas_b - зберігає факт наявності або відсутності числа
		//masInd - зберігає індекс знайденого числа
		const int sizeMas = 2;
		int mas[sizeMas];
		cout << "Введіть 2 числа, що збираєтесь шукати" << endl;
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
				cout << "Число "
					<< mas[0]
					<< " знаходиться зліва від числа "
					<< mas[1]
					<< endl;
			}
			else
			{
				cout << "Число "
					<< mas[1]
					<< " знаходиться зліва від числа "
					<< mas[0]
					<< endl;
			}
		}
		else if (mas_b[0] && !mas_b[1])
		{
			cout << "У числі є лише цифра "
				<< mas[0]
				<< endl;
		}
		else if (!mas_b[0] && mas_b[1])
		{
			cout << "У числі є лише цифра "
				<< mas[1]
				<< endl;
		}
		else if (!mas_b[0] && !mas_b[1])
		{
			cout << "У числі нема цифр "
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

		cout << "Введіть масив з 15-ти елементів. Застосунок знайде суму всіх непарний елементів, помножених на -1." << endl;
		for (int i = 0; i < sizeArr; i++)
		{
			cin >> arr[i];
		}

		float sum = 0;
		for (int i = 0; i < sizeArr; i += 2)
		{
			sum -= arr[i];
		}

		cout << "Сума непарних елементів масиву "
			<< sum
			<< endl;
		break;
	}
	case 11:
	{
		cout << "Скільки міст ви бажаєте ввести?" << endl;
		
		int cityNum;
		cin >> cityNum;
		
		vector<string> city;
		city.resize(cityNum);
		vector<float> dist;
		dist.resize(cityNum);
		
		cout << "Введіть по черзі назву міста та відстань до нього (в км.)" << endl;
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

		cout << "Найвіддаленіше місто: "
			<< city[max]
			<< "\nВідстань до цього міста: "
			<< dist[max]
			<< " км."
			<< endl;

		break;
	}
	case 12:
	{
		cout << "Введіть послідовність нулів та одиниць:" << endl;
		string base;
		cin >> base;

		int min = base.length(), seq = 0;

		//cout << base.length() << endl;

		if (base.find('0') == string::npos)
		{
			cout << "У послідовності нема нулів." << endl;
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

		cout << "Найменша послідовність нулів: "
			<< min
			<< endl;

		break;
	}
	case 13:
	{
		const int numRow = 8;
		const int numCol = 5;
		int arr[numRow][numCol];

		cout << "Введіть 1, якщо бажаєте вводити значення за стовпцями\n"
			<< "Введіть 2, якщо бажаєте вводити значення за рядками"
			<< endl;
		int task;
		cin >> task;

		switch (task)
		{
		case 1:
		{
			for (int i = 0; i < numCol; i++)
			{
				cout << "Введіть бали всіх учасників за змагання №" << i + 1 << endl;
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
				cout << "Введіть бали по всіх змаганням для учасника №" << i + 1 << endl;
				for (int j = 0; j < numCol; j++)
				{
					cin >> arr[i][j];
				}
			}
		}
		default:
		{
			cout << "Введіть значення 1 або 2." << endl;
			break;
		}
		}

		cout << "Отримана таблиця балів:\n"
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
		cout << "Введіть значення кількості доданків:\n"
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
		cout << "Введіть номер завдання від 1 до 14";
		break;
	}
	}

}