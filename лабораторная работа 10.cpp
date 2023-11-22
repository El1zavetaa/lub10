#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	time_t currentTime = time(0);

	// открывает файл для записи логов
	ofstream logFile("log.txt");
	// проверяет, удалось ли открыть файл
	if (!logFile.is_open()) {
		cout << "Ошибка открытия файла логов!" << endl;
		return 1;
	}
	char* timeString = ctime(&currentTime);
	int N, k;
	cout << "Введите N (компьютер загадает число от 1 до N): ";
	cin >> N;
	// выводим данные в лог файл
	logFile << "Введенное число N: " << endl << N << endl << "Время выполнения запроса: " << timeString << endl;
	// проверка на ошибку ввода
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Ошибка!";
		logFile << "Ошибка данных!" << endl << "Время выполнения запроса: " << timeString << endl;
		return 0;
	}
	cout << "Введите k - количество ваших попыток: ";
	cin >> k;
	// выводим данные в лог файл
	logFile << "Введенное количество попыток: " << endl << k << endl << "Время выполнения запроса: " << timeString << endl;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Ошибка!";
		logFile << "Ошибка данных!" << endl << "Время выполнения запроса: " << timeString << endl;
		return 0;
	}
	srand(time(NULL)); //инициализируем генератор случайных чисел
	int randomNumber = rand() % N + 1; //генерируем случайное число от 1 до N
	cout << "Компьютер загадал число, попытайтесь отдагать!" << endl << "Введите предполагаемое число: ";
	//используем цикл, пока есть попытки, пользователь может отгадывать
	while (k > 0) {
		int a;
		cin >> a;
		// выводим данные в лог файл
		logFile << "Введенное число пользователем: " << endl << a << endl << "Время выполнения запроса: " << timeString << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1, '\n');
			cout << "Ошибка!";
			logFile << "Ошибка данных!" << endl << "Время выполнения запроса: " << timeString << endl;
			return 0;
		}
		if (a == randomNumber) {
			cout << "Вы угадали!";
			logFile << "Пользователь угадал!" << endl << "Время выполнения запроса : " << timeString << endl;
		}
		else if (a < randomNumber) {
			cout << "Введенное вами число меньше загаданного!" << endl;
			logFile << "Введенное число меньше загаданного!" << endl << "Время выполнения запроса : " << timeString << endl;
		}
		else if (a > randomNumber) {
			cout << "Введенное вами число больше загаданного!" << endl;
			logFile << "Введенное число больше загаданного!" << endl << "Время выполнения запроса : " << timeString << endl;
		}
		k = k - 1;
		if (k == 0) {
			cout << "Попытки закончились!";
			logFile << "Попытки закончились!" << endl << "Время выполнения запроса : " << timeString << endl;
			cout << "Загаданное число было: " << randomNumber << endl;
			logFile << "Загаданное число было: " << randomNumber << endl << "Время выполнения запроса : " << timeString << endl;
		}
		if (a == randomNumber)
		{
			cout << "Загаданное число было: " << randomNumber << endl;
			logFile << "Загаданное число было: " << randomNumber << endl << "Время выполнения запроса : " << timeString << endl;
			k = 0;
		}
	}
	

}