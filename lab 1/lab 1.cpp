#include "pch.h"
#include <iostream>             //Подключение библиотек
#include <stdlib.h>

using namespace std;                //Объявление глобальной переменной
struct Futbol               //Объявление структуры
{
	char FIO[30];           //Объявление переменных в структуре
	char Amp[30];
	int GOD;
	int Igr;
	int Gol;
};
void ShowData(Futbol *M,int N)            //Объявление функции для вывода информации
{   for (int i=0;i<N;i++)           //Цикл вывода
	{   cout<<endl;
		cout<<"Фамилия: "<<M[i].FIO<<endl;
		cout<<"Амплуа: "<<M[i].Amp<<endl;
		cout<<"Возраст: "<<M[i].GOD<<endl;
		cout<<"Количество игр: "<<M[i].Igr<<endl;
		cout<<"Количество голов: "<<M[i].Gol<<endl;
	}}
void GetData(Futbol *M, int N)       //Объявление функции ввода информации из структуры
{
	cin.ignore();
	for (int i = 0; i < N; i++)       //Цикл ввода
	{
		cout << "Фамилия: ";
		cin.getline(M[i].FIO, 30);
		cout << "Амплуа: ";
		cin.getline(M[i].Amp, 30);
		cout << "Возраст: ";
		cin >> M[i].GOD;
		cin.ignore();
		cout << "Количество игр: ";
		cin >> M[i].Igr;
		cin.ignore();
		cout << "Количество голов: ";
		cin >> M[i].Gol;
		cin.ignore();
		cout << "\n";
	}
	int max = 0;
	for (int i = 0; i < N; i++)   //Цикл определения максимального количество голов
	{

		if (M[i].Gol >= max)
			max = M[i].Gol;
	}
	cout << "Количетсво форварда = " << max;
	for (int i = 0; i < N; i++) {      //Цикл для проверки условия
		if (M[i].Igr <= 5)
			cout << "\nФамилия : " << M[i].FIO << " Амплуа: " << M[i].Amp << " Возраст: " << M[i].GOD << " Количество игр: " << M[i].Igr << " Количетсво голов: " << M[i].Gol << endl;
	}
}
void main()     //Основная функция
{
	system("CLS");      //Очистка экрана
	setlocale(LC_ALL, "RUS");    //Подключение русского языка
	int N;      //Объявление переменной для количества записей
	cout << "Введите количетсво игроков : ";
	cin >> N;
	Futbol *M = new Futbol[N];        //Вызов структуры
	GetData(M, N);           //Вызов функции ввода
	ShowData(M,N);        //Вызов функции вывода
	delete[]M;         //Очистка динамической памяти

	system("pause");
}