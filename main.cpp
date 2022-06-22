#include <iostream>
#include<ctime>
#include<cstdlib>

short getRandNumber()
{
	short randNumber(1 + rand() % 100);
	return randNumber;
}

enum class StatusGame
{
	WIN,
	LOOSE
};

void tryAgain();

int main()
{
link:
	using namespace std;
	srand(time(0));
	setlocale(LC_ALL, "RU");

	StatusGame statusGame;
	short attemp;
	static int randNumber = getRandNumber();

	cout << "����� ������� � ����. � ������� ����� �� 1 �� 100. � ��� ���� 7 ������� �������, ����� ��� �����." << endl;
	for (short i = 1; i < 8; i++)
	{
		cout << "������� #" << i << ':';
		while (true)
		{
			cin >> attemp;
			cin.ignore(32767, '\n');
			if (cin.fail())
			{
				cout << "�� ����� �������� ������." << endl;
				cout << "��������� �������: ";
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if ((1 <= attemp) && (attemp <= 100))
			{
				break;
			}
			else
			{
				cout << "�������� ���� ����� �� ������ � �������� �������(1-100)" << endl;
				cout << "��������� �������: ";
			}
		}

		if (attemp == randNumber)
		{
			cout << "���������, �� �������!";
			statusGame = StatusGame::WIN;
			break;
		}
		else if (attemp < randNumber)
		{
			cout << "���� ������� ������� ����." << endl;
			continue;
		}
		else if (attemp > randNumber)
		{
			cout << "���� ������� ������� ������." << endl;
			continue;
		}
		if (i == 8)
		{
			statusGame = StatusGame::LOOSE;
		}
	}

	if (statusGame == StatusGame::LOOSE)
	{
		cout << "��������, �� ���������.���������� ����� ���� " << randNumber << '.' << endl;
	}

	tryAgain();

	return 0;
}

void tryAgain()
{
link:
	using namespace std;

	char ch;
	cout << "������ ������ (y/n) / ��������� ���� (e).";
	cin >> ch;
	cin.ignore(32767, '\n');
	while (true)
	{
		if (std::cin.fail())
		{
			cout << "\n�� ����� �������� ������" << endl;
			cout << "��������� �������: ";
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else
		{
			break;
		}

	}
	switch (ch)
	{
	case 'y':
	case 'n':
		main();
		break;
	case'e':
		exit(0);
	default:
		cout << "�� ����� �������� ������" << endl;
		goto link;
		break;
	}
}