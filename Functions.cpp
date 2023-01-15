#include "Functions.h"

void DataInitialization()
{
	//создадим временный файл, в котором будет храниться актуальная информация. Т.е. создадим буфер
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;

	_buf.close();
}

void DataEntry()
{
	//ввод данных вручную

	//временные переменные
	string _surname;
	string _software;
	int _sum;
	int n;

	cout << "Введите количество заказов (Целые числа): ";
	cin >> n;

	//открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введите Фамилию: ";
			cin >> _surname;

			cout << "Введите название ПО: ";
			cin >> _software;

			cout << "Введите сумму заказа: ";
			cin >> _sum;

			record << _surname << endl;
			record << _software << endl;
			if (i < n - 1)
				record << _sum << endl;
			else
				record << _sum;

			cout << "_____________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}

void DataReading(string fileName)
{
	//чтение данных из файла

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			//временные переменные
			string _surname;
			string _software;
			int _sum;
			int n;

			//считываем данные из файла

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;

				reading >> _software;

				reading >> _sum;

				record << _surname << endl;
				record << _software << endl;
				if (i < n - 1)
					record << _sum << endl;
				else
					record << _sum;
			}

			cout << "Данные считаны!" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрытие файла
	reading.close();
	record.close();

}

void Print()
{
	ifstream reading("Buffer.txt");

	if (reading) {

		//временные переменные
		string _surname;
		string _software;
		int _sum;
		int n;

		//выводим данные об указаной единице
		reading >> n;
		cout << "Количество данных: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "Данные об заказе №" << i + 1 << endl;

			reading >> _surname;
			cout << "Фамилия: " << _surname << endl;

			reading >> _software;
			cout << "Название ПО: " << _software << endl;

			reading >> _sum;
			cout << "Сумма заказа: " << _sum << endl;

			cout << "_________________________________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрываем файл
	reading.close();
}

bool DataCleaning()
{
	//очистка буфера

	bool clear = false;

	//открываем файл
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "Ошибка открытия буферного файла" << endl;

	//очищаем
	_buf.clear();

	//проверка, что файл чист
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

void DataChange()
{
	//изменение данных

	//сохраним еще раз данные
	//очистим буфер и снова начнем записывать данные в него
	//дойдем до необходимого и изменим его данные

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			string _software;
			int _sum;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _software;
						record << _software << endl;

						reading >> _sum;
						if (i < n - 1)
							record << _sum << endl;
						else
							record << _sum;
					}
					else {
						cout << "Введите фамилию: ";
						cin >> _surname;

						cout << "Введите название ПО: ";
						cin >> _software;

						cout << "Введите сумму заказа: ";
						cin >> _sum;

						record << _surname << endl;
						record << _software << endl;
						if (i < n - 1)
							record << _sum << endl;
						else
							record << _sum;

						reading >> _surname;
						reading >> _software;
						reading >> _sum;

					}
				}

				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//копирование в новый файл

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			string _software;
			int _sum;
			int n;

			//считываем из буферного файла в новый
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _software;
				record << _software << endl;

				reading >> _sum;
				if (i < n - 1)
					record << _sum << endl;
				else
					record << _sum;
			}
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

}

int AmountOfData()
{
	//выводит количество данных из файла
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.close();

	return n;
}

void DeleteData()
{
	//удаление данных

	//запоминаем данные
	//перезаписываем в исходный буфер
	//кроме удаляемого

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			string _software;
			int _sum;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;
			int b = n - 1;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;
						reading >> _software;
						record << _software << endl;
						reading >> _sum;
						if (i < n - 1)
							record << _sum << endl;
						else
							record << _sum;
					}
					else {
						reading >> _surname;
						reading >> _software;
						reading >> _sum;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");

}

void AddData()
{
	//добавить данные

	//временные переменные
	string _surname;
	string _software;
	int _sum;
	int n = AmountOfData() + 1;

	//открываем буферный файл
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (record) {
		record << endl;

		cout << "Введите фамилию: ";
		cin >> _surname;

		cout << "Введите замеры: ";
		cin >> _software;

		cout << "Введите тип изделия: ";
		cin >> _sum;

		record << _surname << endl;
		record << _software << endl;
		record << _sum;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName)
{
	//сохранение данных

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {

			//временные переменные
			string _surname;
			string _software;
			int _sum;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _software;
				record << _software << endl;

				reading >> _sum;
				if (i < n - 1)
					record << _sum << endl;
				else
					record << _sum;
			}

			cout << "Данные сохранены в файле " << fileName << endl;

		}
		else
			cout << "Ошибка открытия буферного файла " << endl;
	}
	else
		cout << "Ошыбка открытия файла" << endl;

	record.close();
	reading.close();

}