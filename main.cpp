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

	cout << "Давай сыграем в игру. Я загадал число от 1 до 100. У вас есть 7 попыток угадать, какое это число." << endl;
	for (short i = 1; i < 8; i++)
	{
		cout << "Попытка #" << i << ':';
		while (true)
		{
			cin >> attemp;
			cin.ignore(32767, '\n');
			if (cin.fail())
			{
				cout << "Вы ввели неверные данные." << endl;
				cout << "Повторите попытку: ";
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
				cout << "Введённое вами число не входит в заданный дипазон(1-100)" << endl;
				cout << "Повторите попытку: ";
			}
		}

		if (attemp == randNumber)
		{
			cout << "Правильно, ты победил!";
			statusGame = StatusGame::WIN;
			break;
		}
		else if (attemp < randNumber)
		{
			cout << "Ваша догадка слишком мала." << endl;
			continue;
		}
		else if (attemp > randNumber)
		{
			cout << "Ваша догадка слишком велика." << endl;
			continue;
		}
		if (i == 8)
		{
			statusGame = StatusGame::LOOSE;
		}
	}

	if (statusGame == StatusGame::LOOSE)
	{
		cout << "Извините, вы проиграли.Правильное число было " << randNumber << '.' << endl;
	}

	tryAgain();

	return 0;
}

void tryAgain()
{
link:
	using namespace std;

	char ch;
	cout << "Начать заново (y/n) / завершить игру (e).";
	cin >> ch;
	cin.ignore(32767, '\n');
	while (true)
	{
		if (std::cin.fail())
		{
			cout << "\nВы ввели неверный символ" << endl;
			cout << "Повторите попытку: ";
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
		cout << "Вы ввели неверный символ" << endl;
		goto link;
		break;
	}
}