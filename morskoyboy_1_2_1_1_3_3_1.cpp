//������� ��� ������ ������� ���� � ������������.
// ���� ������� ��� �������, �� ��� �� ������� � �� ������ �������� �� ������� �� �������, � ������� ���� ������ ������� // ��� ������������

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
int n4 = 1; // ���������� �� ������� �������
int f = 10; // ����� ��������
bool sl = 0; //���������
int nvr = 20, nmo = 20; // ��� �������/���������
bool endf = false;//win/lose
bool popaly = 1; // �����/�� ����� � ������� ����
///���� ���///
bool again = 1;
bool restdir = 0; // ��������� �����������
int dir1;// ����������� � ����
int vr_x = 0, vr_y = 0; // ��������� ����������
bool stopy = 1; // ������ ����
bool rest = 0; // ������� ���� ���� ��� �������
bool continuef = 0; // ����������� ������ �����������
bool prod = 0;
int dircount = 0; // ����� ����� �� �����
///���� ���////

void hardmode(int map1[N][N]) //������� ���������� ��������� ���������� ��� ����
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
				cout << "������1" << endl;
				Sleep(500);
				stopy = 1;
				rest = 0;
				again = 0;
				nmo--;
				continuef = 1;
				if ((map1[j + 1][i] != 1) and (map1[j - 1][i] != 1) and (map1[j][i + 1] != 1) and (map1[j][i - 1] != 1))
				{
					cout << "�������1";
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
void hardmodedir(int map1[N][N]) // ������� ������ �����������
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
			cout << "������2" << endl; // ����
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
			cout << "������2";
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
void hardcont(int map1[N][N]) // ����������� �������� ��� ���������� ������ ����-�
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
		cout << "������3" << endl; // ����
		Sleep(500);
		continuef = 0;
		rest = 0;
		nmo--;
	}
	if ((map1[x + 1][y] != 1) and (map1[x - 1][y] != 1) and (map1[x][y + 1] != 1) and (map1[x][y - 1] != 1))
	{
		cout << "�������3";
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
		cout << "������3";
		Sleep(500);
		rest = 1;
		again = 1;
		system("cls");
	}
}
void ezmode(int map1[N][N]) //������
{
	srand(time(NULL));
	int x, y; //���������� ��������� ���������� �������
	while (true)
	{
		//��������� �������
		x = rand() % N;
		y = rand() % N;
		if (map1[x][y] == 1)
		{
			cout << "������" << endl;
			Sleep(1000);
			nmo--;
			map1[x][y] = 2;
			rest = 0;
			popaly = 1;
			break;
		}
		else
		{
			cout << "������" << endl;
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
void tvoikorablisam(int map1[N][N], int p1, int p2, int dir1, int size_ship1) //p1==x p2==y dir1=napravleniet �����������
{ //��������������� ����� 
	srand(time(NULL));

	int count_ship1 = 0;
	int temp_p1 = p1;//�������� ������ �
	int temp_p2 = p2;//�������� ������ y
	for (int i = 0; i < size_ship1; i++)
	{
		bool setting_is_possible = 1;

		if (p1 < 0 or p2 < 0 or p1 >= N or p2 >= N)
		{
			setting_is_possible = 0;
			cout << "������ ��� �������" << endl; //������� ���� ����� �������� �� ���������� #FIXED
			Sleep(500);
			break;
		}
		//�������� ����� ������ ���� ������� �� �����������
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
				cout << "������ ��� �������" << endl;
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
				cout << "������ ��� �������" << endl;
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
			cout << "������ ��� �������" << endl; //������� ���� ����� �������� �� ���������� #FIXED
			Sleep(500);
			break;
		}
		if (n1 == 0 and size_ship1 == 1)
		{ //�������� ��������� ��������
			cout << "���������� ������������ ����� �������� ������� ����";
			Sleep(2000);
			break;
		}
		if (n2 == 0 and size_ship1 == 2)
		{
			cout << "���������� ������������ ����� �������� ������� ����";
			Sleep(2000);
			break;
		}
		if (n3 == 0 and size_ship1 == 3)
		{
			cout << "���������� ������������ ����� �������� ������� ����";
			Sleep(2000);
			break;
		}
		if (n4 == 0 and size_ship1 == 4)
		{
			cout << "���������� ������������ ����� �������� ������� ����";
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
void tvoikorabliauto(int map1[N][N], int size_ship, int num_ships) // ��������������� ����� ���������
{
	srand(time(NULL));

	int x, y; //���������� ��������� ���������� �������
	int dir = 0; // �����������
	int count_ship = 0;
	while (count_ship < num_ships)
	{
		//��������� �������
		x = rand() % N;
		y = rand() % N;

		int temp_x = x;//�������� ������ �
		int temp_y = y;//�������� ������ y

		//��������� �����������
		dir = rand() % 4;

		bool setting_is_possible = 1; //�������� ����������� ��������� �������

		for (int i = 0; i < size_ship; i++)
		{

			if (x < 0 or y < 0 or x >= N or y >= N)
			{
				setting_is_possible = 0;
				break;
			}
			//�������� ����� ������ ���� ������� �� �����������
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

		//���� ���� �������� ���� ������, �� ������
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
void xotbkakayatografika1(int map1[N][N], int mask1[N][N], int p1, int p2) //���������
{

	srand(time(NULL));
	//���������� ���� ������
	cout << ' ';//����� ������ � �������  �����������
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
void random_korablya(int map[N][N], int size_ship, int num_ships) //���������
{ //������� ������
	srand(time(NULL));
	int x, y; //���������� ��������� ���������� �������
	int dir = 0; // �����������
	int count_ship = 0;
	while (count_ship < num_ships)
	{
		//��������� �������
		x = rand() % N;
		y = rand() % N;

		int temp_x = x;//�������� ������ �
		int temp_y = y;//�������� ������ y

		//��������� �����������
		dir = rand() % 4;

		bool setting_is_possible = 1; //�������� ����������� ��������� �������

		for (int i = 0; i < size_ship; i++)
		{

			if (x < 0 or y < 0 or x >= N or y >= N)
			{
				setting_is_possible = 0;
				break;
			}
			//�������� ����� ������ ���� ������� �� �����������
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

		//���� ���� �������� ���� ������, �� ������
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
void xotbkakayatografika(int map[N][N], int mask[N][N]) //���������
{
	srand(time(NULL));
	//���������� ���� ������
	cout << ' ';//����� ������ � �������  �����������
	cout << "0 1 2 3 4 5 6 7 8 9";
	cout << endl;


	for (int i = 0; i < N; i++)
	{
		cout << i;//��������� �� ���������
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

		int map[N][N] = { 0 }; // ���� ����
		int map1[N][N] = { 0 }; // ��� ����
		int mask[N][N] = { 0 }; // ��� ���� �� ����
		int mask1[N][N] = { 0 };//��� ���� � ����
		int p1 = 0, p2 = 0; //x,y
		int dir1 = 0;//�����������

		bool rej = -1; //�����;
		cout << "������ ����� ���������� ���� ����������� �������, ������� �����(0=���������������/1=��� ������� �������� ������)" << endl;
		while (!(cin >> rej))
		{
			cin.clear();
			cin.ignore();
			cout << "�������� ����, �����(0=���������������/1=��� ������� �������� ������) : ";
		}
		cout << "������ ���������: 0:����� ��� ������� 1:����� ��� ����� �����" << endl;;
		while (!(cin >> sl))
		{
			cin.clear();
			cin.ignore();
			cout << "�������� ����, ���������: 0:����� ��� ������� 1:����� ��� ����� ����� : ";
		}
		if (rej == 1) {
			while (f != 0)
			{

				xotbkakayatografika1(map1, mask1, p1, p2);
				cout << endl;
				cout << endl << "1=1 ������ " << n1 << " ��" << endl << "2=2 ������ " << n2 << " ��" << endl << "3=3 ������ " << n3 << " ��" << endl << "4=4 ������ " << n4 << " ��" << endl;
				int size_ship1 = 1; // ������ �������
				while ((!(cin >> size_ship1)) or size_ship1 < 1 or size_ship1>4)
				{
					cin.clear();
					cin.ignore();
					cout << "�������� ����, 1=1 ������, 2=2 ������, 3=3 ������, 4=4 ������ : ";
				}
				cout << "������� ���������� ������� ����� �������" << endl << "x= ";
				cin >> p1;
				cout << endl << "y= ";
				cin >> p2;
				if (size_ship1 != 1) {

					cout << "������� �����������(0=�������,1=����,2=������,3=�����)" << endl;
					while ((!(cin >> dir1)) or dir1 < 0 or dir1>3)
					{
						cin.clear();
						cin.ignore();
						cout << "�������� ����, 0=�������,1=����,2=������,3=����� : ";
					}

				}
				if (size_ship1 == 1)
				{

					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					Sleep(500);
					system("cls"); //������� �������

				}
				if (size_ship1 == 2)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //������� �������
				}
				if (size_ship1 == 3)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //������� �������
				}
				if (size_ship1 == 4)
				{
					tvoikorablisam(map1, p1, p2, dir1, size_ship1);
					system("cls"); //������� �������
				}
			}
		}
		else
		{
			tvoikorabliauto(map1, 4, 1);//��� ����� � �������� 

			tvoikorabliauto(map1, 3, 2);

			tvoikorabliauto(map1, 2, 3);

			tvoikorabliauto(map1, 1, 4);
		}
		//���� ����� ������� � ���� ��� 4
		{
			random_korablya(map, 4, 1);//��� ����� � �������� 

			random_korablya(map, 3, 2);

			random_korablya(map, 2, 3);

			random_korablya(map, 1, 4);
		}
		int x = 0, y = 0;
		while (true)
		{
			if (nmo == 0)
			{
				cout << "������, � �������";
				Sleep(2000);
				endf = 1;
				break;
				break;
				exit(3);
			}
			if (nvr == 0)
			{
				cout << "���� ������� ��������";
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
				cout << "��� ����" << endl;
				xotbkakayatografika1(map1, mask1, p1, p2);
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "��������� ����" << endl;
				xotbkakayatografika(map, mask);
				popal = 0;
				cout << endl << "������ ���� ����� �� ��� ������� � �������" << endl;

				while ((!(cin >> x >> y)) or map[x][y] == 2 or map[x][y] == 3)
				{
					cin.clear();
					cin.ignore();
					cout << "������������ ���� : ";
				}
				if (map[x][y] == 1)
				{
					cout << endl << "���� ��������" << endl;
					Sleep(500);
					nvr--;
					popal = 1;
					system("cls"); //������� �������
				}
				else
				{
					cout << "�� ������" << endl;
					map[x][y] = 2;
					popal = 0;
				}
				mask[x][y] = 1;
				cin.clear();
				cin.ignore();
			}
			cout << "������ ������� �����" << endl;
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


//C������ ����� �����


