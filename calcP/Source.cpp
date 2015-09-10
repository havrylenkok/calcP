#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <locale.h>
#include <iomanip>
using namespace std;

//������������� ������� 
double func(double x)
{
	return ( (4) / ( 1 + (x * x) ));
}

//������� ��� ���������� ��������� ������� ����� ��������������� 
double integr_lefttriangle(int n, double a, double b)
{
	double sum = 0;
	double step = (b - a) / n;//���
	for (double i = a; i < b; i = i + step)
		sum += func(i);//��������� �������� ������� � ������� ������
	return sum*step;//������ �� �������� ���� � ���������� � ���������� �������


}


int main()
{
	setlocale(LC_ALL, "rus");//��� ������� ���� � �������
	
	int n = 20;//���������� ����� ���������

	ofstream fout;
	fout.open("result.txt");
	fout << "n\t\ttime\t\t\t\tPi value" << endl;

	int baseIntCounter = 9;
	int amax = baseIntCounter + 100;


	for (baseIntCounter; baseIntCounter < amax; baseIntCounter++)
	{
		clock_t time;
		time = clock();
		auto result = integr_lefttriangle(n, 0, 1);
		auto mytime = (float)time / CLOCKS_PER_SEC;
		fout.setf(ios::fixed);
		fout.precision(20);
		time = clock() - time;
		fout << baseIntCounter << "\t\t" << mytime << "\t\t";
		fout.precision(20);
		fout << result << endl;
	}
	
	fout.close();
	return 0;
}