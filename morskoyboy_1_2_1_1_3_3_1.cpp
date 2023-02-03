//МОРСКОЙ БОЙ ПРОТИВ ЛЕГКОГО БОТА И НЕВОЗМОЖНОГО.
// Если кажется что зависло, то это не зависло и он просто выбирает на рандоме ту строчку, в которой есть палуба корабля // ДЛЯ НЕВОЗМОЖНОГО

#include <iostream>;
#include <windows.h>
#include <math.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
const int N = 10;
int n1 = 4;
int n2 = 3;
int n3 = 2;
bool popal = 1;
int n4 = 1; // поставлены ли корабли вручную
int f = 10; // число кораблей
bool sl = 0; //сложность
int nvr = 20, nmo = 20; // мои корабли/вражеские
bool endf = false;//win/lose
bool popaly = 1; // попал/не попал у легкого бота
///хард бот///
bool again = 1;
bool restdir = 0; // обнуление направления
int dir1;// Направление у бота
int vr_x = 0, vr_y = 0; // временные переменные
bool stopy = 1; // просто стоп
bool rest = 0; // рестарт хода бота при прилете
bool continuef = 0; // продолжение выбора направления
bool prod = 0;
int dircount = 0; // колво ходов по кругу
///хард бот////

void hardmode(int map1[N][N]) //функция нахождения первичной координаты для бота
{
	stopy = 0;
	srand(time(NULL));
	for (int i = rand()%N; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vr_x = j;
			vr_y = i;
			restdir = 0;
			if (map1[j][i] == 1)
			{
				map1[j][i] = 2;
				cout << "Пробил1" << endl;
				Sleep(500);
				stopy = 1;
				rest = 0;
				again = 0;
				nmo--;
				continuef = 1;
				if ((map1[j + 1][i] != 1) and (map1[j - 1][i] != 1) and (map1[j][i + 1] != 1) and (map1[j][i - 1] != 1))
				{
					cout << "Потопил1";
					Sleep(500);
					rest = 0;
					restdir = 1;
					again = 1;
					continuef = 0;
					cout << endl;
				}
				break;
			}
			if (stopy == 1)
			{
				break;
			}
		}
		if (stopy == 1)
		{
			break;
		}
	}


}
void hardmodedir(int map1[N][N]) // функция выбора направления
{
	srand(time(NULL));
	int x = vr_x;
	int y = vr_y;
	dir1 = rand() % 4;

	switch (dir1)
	{
	case 0:
		x++;
		break;
	case 1:
		y++;
		break;
	case 2:
		x--;
		break;
	case 3:
		y--;
		break;
	}
	while (true)
	{

		if (map1[x][y] == 1)
		{
			
			map1[x][y] = 2;
			cout << "Пробил2" << endl; // фикс
			Sleep(500);
			continuef = 0;
			rest = 0;
			again = 0;
			prod = 1;
			nmo--;
			break;
		}
		if (map1[x][y] == 0)
		{
			map1[x][y] = 3;
			cout << "Промах2";
			Sleep(500);
			continuef = 1;
			rest = 1;
			prod = 0;
			system("cls");
			break;
		}
		else if (map1[x][y]!= 1 or map1[x][y] != 0)
		{
			x = vr_x;
			y = vr_y;
			dir1 = rand() % 4;
			switch (dir1)
			{
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
		}
	}

}
void hardcont(int map1[N][N]) // продолжение пробитий при правильном выборе напр-я
{
	switch (dir1)
	{
	case 0:
		vr_x++;
		break;
	case 1:
		vr_y++;
		break;
	case 2:
		vr_x--;
		break;
	case 3:
		vr_y--;
		break;
	}
	int x = vr_x;
	int y = vr_y;
	if (map1[x][y] == 1)
	{
		map1[x][y] = 2;
		cout << "Пробил3" << endl; // фикс
		Sleep(500);
		continuef = 0;
		rest = 0;
		nmo--;
	}
	if ((map1[x + 1][y] != 1) and (map1[x - 1][y] != 1) and (map1[x][y + 1] != 1) and (map1[x][y - 1] != 1))
	{
		cout << "Потопил3";
		Sleep(500);
		rest = 0;
		restdir = 1;
		again = 1;
		continuef = 0;
		cout << endl;
	}
	if (map1[x][y] == 0)
	{
		map1[x][y] = 3;
		cout << "Промах3";
		Sleep(500);
		rest = 1;
		again = 1;
		system("cls");
	}
}
void ezmode(int map1[N][N]) //ЛЕГКИЦ
{
	srand(time(NULL));
	int x, y; //определяют первичную координату корабля
	while (true)
	{
		//первичная позиция
		x = rand() % N;
		y = rand() % N;
		if (map1[x][y] == 1)
		{
			cout << "Пробил" << endl;
			Sleep(1000);
			nmo--;
			map1[x][y] = 2;
			rest = 0;
			popaly = 1;
			break;
		}
		else
		{
			cout << "Промах" << endl;
			Sleep(1000);
			rest = 1;
			map1[x][y] = 3;
			popaly = 0;
			system("cls");
			break;
		}

	}
	cout << endl;
}
void tvoikorablisam(int map1[N][N], int p1, int p2, int dir1, int size_ship1) //p1==x p2==y dir1=napravleniet НЕЗАКОНЧЕНО
{ //саморасстановка твоих 
	srand(time(NULL));

	int count_ship1 = 0;
	int temp_p1 = p1;//временно хранит х
	int temp_p2 = p2;//временно хранит y
	for (int i = 0; i < size_ship1; i++)
	{
		bool setting_is_possible = 1;

		if (p1 < 0 or p2 < 0 or p1 >= N or p2 >= N)
		{
			setting_is_possible = 0;
			cout << "Нельзя так ставить" << endl; //сделать чтоб число кораблей не вычиталось #FIXED
			Sleep(500);
			break;
		}
		//проверка рядом клеток чтоб фрегаты не бабахнулись
		if (p2 != 0 and p2 != 9)
		{
			if (map1[p1][p2] == 1 or
				map1[p1][p2 + 1] == 1 or
				map1[p1][p2 - 1] == 1 or
				map1[p1 + 1][p2] == 1 or
				map1[p1 + 1][p2 + 1] == 1 or
				map1[p1 + 1][p2 - 1] == 1 or
				map1[p1 - 1][p2] == 1 or
				map1[p1 - 1][p2 + 1] == 1 or
				map1[p1 - 1][p2 - 1] == 1)
			{
				setting_is_possible = 0;
				cout << "Нельзя так ставить" << endl;
				Sleep(500);
				break;
			}
		}
		else
		{
			if (map1[p1][p2] == 1 or
				map1[p1 + 1][p2] == 1 or
				map1[p1 - 1][p2] == 1 or
				map1[p1][p2 + 1] or
				map1[p1][p2 - 1] == 1
				)

			{
				setting_is_possible = 0;
				cout << "Нельзя так ставить" << endl;
				Sleep(500);
				break;
			}
		}
		if (size_ship1 != 1) {
			switch (dir1)
			{
			case 0:
				p1++;
				break;
			case 1:
				p2++;
				break;
			case 2:
				p1--;
				break;
			case 3:
				p2--;
				break;
			}
		}
		if (p1 < 0 or p2 < 0 or p1 >= N or p2 >= N)
		{
			setting_is_possible = 0;
			cout << "Нельзя так ставить" << endl; //сделать чтоб число кораблей не вычиталось #FIXED
			Sleep(500);
			break;
		}
		if (n1 == 0 and size_ship1 == 1)
		{ //ПРОВЕРКА МАКСИМУМА КОРАБЛЕЙ
			cout << "Поставлено максимальное число кораблей данного типа";
			Sleep(2000);
			break;
		}
		if (n2 == 0 and size_ship1 == 2)
		{
			cout << "Поставлено максимальное число кораблей данного типа";
			Sleep(2000);
			break;
		}
		if (n3 == 0 and size_ship1 == 3)
		{
			cout << "Поставлено максимальное число кораблей данного типа";
			Sleep(2000);
			break;
		}
		if (n4 == 0 and size_ship1 == 4)
		{
			cout << "Поставлено максимальное число кораблей данного типа";
			Sleep(2000);
			break;
		}
		if (setting_is_possible == 1)
		{
			if (size_ship1 == 4 and n4 != 0)
			{
				n4--;
				f--;
			}
			if (size_ship1 == 3)
			{
				n3--;
				f--;
			}
			if (size_ship1 == 2)
			{
				n2--;
				f--;
			}
			if (size_ship1 == 1 and n1 > 0)
			{
				n1--;
				f--;
			}

			p1 = temp_p1;
			p2 = temp_p2;


			for (int i = 0; i < size_ship1; i++)
			{
				map1[p1][p2] = 1;

				switch (dir1)
				{
				case 0:
					p1++;
					break;
				case 1:
					p2++;
					break;
				case 2:
					p1--;
					break;
				case 3:
					p2--;
					break;
				}
			}
		}
		break;
	}
}
void tvoikorabliauto(int map1[N][N], int size_ship, int num_ships) // авторасстановка твоих ЗАКОНЧЕНО
{
	srand(time(NULL));

	int x, y; //определяют первичную координату корабля
	int dir = 0; // направление
	int count_ship = 0;
	while (count_ship < num_ships)
	{
		//первичная позиция
		x = rand() % N;
		y = rand() % N;

		int temp_x = x;//временно хранит х
		int temp_y = y;//временно хранит y

		//генерация направления
		dir = rand() % 4;

		bool setting_is_possible = 1; //проверка возможности поставить фрегата

		for (int i = 0; i < size_ship; i++)
		{

			if (x < 0 or y < 0 or x >= N or y >= N)
			{
				setting_is_possible = 0;
				break;
			}
			//проверка рядом клеток чтоб фрегаты не бабахнулись
			if (map1[x][y] == 1 or
				map1[x][y + 1] == 1 or
				map1[x][y - 1] == 1 or
				map1[x + 1][y] == 1 or
				map1[x + 1][y + 1] == 1 or
				map1[x + 1][y - 1] == 1 or
				map1[x - 1][y] == 1 or
				map1[x - 1][y + 1] == 1 or
				map1[x - 1][y - 1] == 1)
			{
				setting_is_possible = 0;
				break;
			}

			switch (dir)
			{
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
		}

		//если могу воткнуть свой фрегат, то воткну
		if (setting_is_possible == 1)
		{
			x = temp_x;
			y = temp_y;


			for (int i = 0; i < size_ship; i++)
			{
				map1[x][y] = 1;

				switch (dir)
				{
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
				}
			}

			count_ship++;
		}
	}
}
void xotbkakayatografika1(int map1[N][N], int mask1[N][N], int p1, int p2) //ЗАКОНЧЕНО
{

	srand(time(NULL));
	//прорисовка поля своего
	cout << ' ';//сдвиг строки с числами  горизонтали
	cout << "0 1 2 3 4 5 6 7 8 9";
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << i;
		Sleep(50);
		for (int j = 0; j < N; j++)
		{
			if (mask1[j][i] == 0)
			{
				if (map1[j][i] == 1)
				{
					cout << "* ";
				}
				if (map1[j][i] == 2)
				{
					cout << "+ ";
				}
				if (map1[j][i] == 3)
				{
					cout << "x ";
				}
				if (map1[j][i] == 0)
				{
					cout << ". ";
				}

			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}
void random_korablya(int map[N][N], int size_ship, int num_ships) //ЗАКОНЧЕНО
{ //корабли ботяры
	srand(time(NULL));
	int x, y; //определяют первичную координату корабля
	int dir = 0; // направление
	int count_ship = 0;
	while (count_ship < num_ships)
	{
		//первичная позиция
		x = rand() % N;
		y = rand() % N;

		int temp_x = x;//временно хранит х
		int temp_y = y;//временно хранит y

		//генерация направления
		dir = rand() % 4;

		bool setting_is_possible = 1; //проверка возможности поставить фрегата

		for (int i = 0; i < size_ship; i++)
		{

			if (x < 0 or y < 0 or x >= N or y >= N)
			{
				setting_is_possible = 0;
				break;
			}
			//проверка рядом клеток чтоб фрегаты не бабахнулись
			if (map[x][y] == 1 or
				map[x][y + 1] == 1 or
				map[x][y - 1] == 1 or
				map[x + 1][y] == 1 or
				map[x + 1][y + 1] == 1 or
				map[x + 1][y - 1] == 1 or
				map[x - 1][y] == 1 or
				map[x - 1][y + 1] == 1 or
				map[x - 1][y - 1] == 1)
			{
				setting_is_possible = 0;
				break;
			}

			switch (dir)
			{
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
		}

		//если могу воткнуть свой фрегат, то воткну
		if (setting_is_possible == 1)
		{
			x = temp_x;
			y = temp_y;


			for (int i = 0; i < size_ship; i++)
			{
				map[x][y] = 1;

				switch (dir)
				{
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
				}
			}

			count_ship++;
		}
	}
}
void xotbkakayatografika(int map[N][N], int mask[N][N]) //ЗАКОНЧЕНО
{
	srand(time(NULL));
	//прорисовка поля ботяры
	cout << ' ';//сдвиг строки с числами  горизонтали
	cout << "0 1 2 3 4 5 6 7 8 9";
	cout << endl;


	for (int i = 0; i < N; i++)
	{
		cout << i;//нумерация по вертикали
		Sleep(50);

		for (int j = 0; j < N; j++)
		{
			if (mask[j][i] == 1)
			{
				if (map[j][i] == 1 or map[j][i] == 3)
				{
					cout << "+ ";
					map[j][i] = 3;
				}
				if (map[j][i] == 2)
				{
					cout << "x ";
				}
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	while (true)
	{

		int map[N][N] = { 0 }; // поле бота
		int map1[N][N] = { 0 }; // мое поле
		int mask[N][N] = { 0 }; // для тире на боте
		int mask1[N][N] = { 0 };//для тире у себя
		int p1 = 0, p2 = 0; //x,y
		int dir1 = 0;//направление

		bool rej = -1; //режим;
		cout << "Пришло время расставить твои драгоценные корабли, выбирай режим(0=авторасстановка/1=сам ручками работать будешь)" << endl;
		while (!(cin >> rej))
		{
			cin.clear();
			cin.ignore();
			cout << "Неверный ввод, режим(0=авторасстановка/1=сам ручками работать будешь) : ";
		}
		cout << "Выбери сложность: 0:Режим для девочек 1:Режим для богов удачи" << endl;;
		while (!(cin >> sl))
		{
			cin.clear();
			cin.ignore();
			cout << "Неверный ввод, сложность: 0:Режим для девочек 1:Режим для богов удачи : ";
		}
		if (rej == 1) {
			while (f != 0)
			{

				xotbkakayatografika1(map1, mask1, p1, p2);
				cout << endl;
				cout << endl << "1=1 палуба " << n1 << " шт" << endl << "2=2 палубы " << n2 << " шт" << endl << "3=3 палубы " << n3 << " шт" << endl << "4=4 палубы " << n4 << " шт" << endl;
				int size_ship1 = 1; // размер корабля
				while ((!(cin >> size_ship1)) or size_ship1 < 1 or size_ship1>4)
				{
					cin.clear();
					cin.ignore();
					cout << "Неверный ввод, 1=1 палуба, 2=2 палубы, 3=3 палубы, 4=4 палубы : ";
				}
				cout << "введите координаты первого блока корабля" << endl << "x= ";
				cin >> p1;
				cout << endl << "y= ";
				cin >> p2;
				if (size_ship1 != 1) {

					cout << "Введите направление(0=направо,1=вниз,2=налево,3=вверх)" << endl;
					while ((!(cin >> dir1)) or dir1 < 0 or dir1>3)
					{
						cin.clear();
						cin.ignore();
						cout << "Неверный ввод, 0=направо,1=вниз,2=налево,3=вверх : ";
					}

				}
				if (size_ship1 == 1)
				{

					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					Sleep(500);
					system("cls"); //очищает сосноль

				}
				if (size_ship1 == 2)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //очищает сосноль
				}
				if (size_ship1 == 3)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //очищает сосноль
				}
				if (size_ship1 == 4)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //очищает сосноль
				}
			}
		}
		else
		{
			tvoikorabliauto(map1, 4, 1);//кол палуб и кораблей 

			tvoikorabliauto(map1, 3, 2);

			tvoikorabliauto(map1, 2, 3);

			tvoikorabliauto(map1, 1, 4);
		}
		//случ устан корабль у бота все 4
		{
			random_korablya(map, 4, 1);//кол палуб и кораблей 

			random_korablya(map, 3, 2);

			random_korablya(map, 2, 3);

			random_korablya(map, 1, 4);
		}
		int x = 0, y = 0;
		while (true)
		{
			if (nmo == 0)
			{
				cout << "Лошара, я победил";
				Sleep(2000);
				endf = 1;
				break;
				break;
				exit(3);
			}
			if (nvr == 0)
			{
				cout << "Тебе повезло победить";
				Sleep(2000);
				endf = 1;
				break;
				break;
				exit(3);
			}
			popal = 1;
			rest = 0;
			while (popal == 1)
			{
				cout << "Твоё море" << endl;
				xotbkakayatografika1(map1, mask1, p1, p2);
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Вражеское море" << endl;
				xotbkakayatografika(map, mask);
				popal = 0;
				cout << endl << "Наведи свою пушку на его корабль и стреляй" << endl;

				while ((!(cin >> x >> y)) or map[x][y] == 2 or map[x][y] == 3)
				{
					cin.clear();
					cin.ignore();
					cout << "Недопустимый ввод : ";
				}
				if (map[x][y] == 1)
				{
					cout << endl << "Есть пробитие" << endl;
					Sleep(500);
					nvr--;
					popal = 1;
					system("cls"); //очищает сосноль
				}
				else
				{
					cout << "Не пробил" << endl;
					map[x][y] = 2;
					popal = 0;
				}
				mask[x][y] = 1;
				cin.clear();
				cin.ignore();
			}
			cout << "Теперь очередь врага" << endl;
			while (rest == 0)
			{
				if (sl == 0)
				{
					popaly = 1;
					while (popaly == 1)
					{
						ezmode(map1);
					}
				}
				if (sl==1)
				{ 
				if (nmo == 0)
				{

					Sleep(2000);
					endf = 1;
					break;
					break;
					exit(3);
				}
				if (nvr == 0)
				{

					Sleep(2000);
					endf = 1;
					break;
					break;
					exit(3);
				}
				if (sl == 1)
				{
					if (again == 1)
					{
						hardmode(map1);
						if (nmo == 0)
						{

							Sleep(2000);
							endf = 1;
							break;
							break;
							exit(3);
						}
						if (nvr == 0)
						{

							Sleep(2000);
							endf = 1;
							break;
							break;
							exit(3);
						}
					}
					if (continuef == 1)
					{
						hardmodedir(map1);

					}
					if (again == 0 and continuef == 0)
					{
						hardcont(map1);
						if (nmo == 0)
						{

							Sleep(2000);
							endf = 1;
							break;
							break;
							exit(3);
						}
						if (nvr == 0)
						{

							Sleep(2000);
							endf = 1;
							break;
							break;
							exit(3);
						}
					}
				}
				}

			}
		}
		if (endf == 1)
		{
			break;
		}

	}
	return 0;
}


//CДЕЛАТЬ УДАРЫ РЯДОМ


