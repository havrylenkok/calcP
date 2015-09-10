#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <locale.h>
#include <iomanip>
using namespace std;

//интегрируемая функция 
long double func(double x)
{
	return (long double ( (4) / ( 1 + (x * x) ) ));
}

//функция для вычисления интеграла методом левых прямоугольников 
long double integr_lefttriangle(int n, double a, double b)
{
	long double sum = 0;
	long double step = (b - a) / n;
	for (long double i = a; i < b; i += step)
		sum += func(i);
	return sum * step;
}


int main()
{
	clock_t timeGlobal;
	timeGlobal = clock();


	ofstream fout;
	fout.open("result.txt");
	fout << "n\t\ttime\t\t\t\tPi value" << endl;

	int baseIntCounter = 9;
	int amax = 1000000000;


	for (baseIntCounter; baseIntCounter <= amax; baseIntCounter++)
	{
		clock_t time;
		time = clock();
		auto result = integr_lefttriangle(baseIntCounter, 0, 1);
		auto mytime = (float)time / CLOCKS_PER_SEC;

		fout.setf(ios::fixed);
		fout.precision(20);
		time = clock() - time;
		fout << baseIntCounter << "\t\t" << mytime << "\t\t";
		fout.precision(51);
		fout << result << endl;
		cout << "counting " << baseIntCounter << endl;
	}
	
	timeGlobal = clock() - timeGlobal;
	auto global = (float)timeGlobal / CLOCKS_PER_SEC;
	if (global > 100) {
		double seconds = global / 60;
		double minutes = seconds / 60;
		fout << endl << "Execution took: " << setprecision(10) << minutes << " minutes" << endl;
	}
	else {
		fout << endl << "Execution took: " << setprecision(27) << global << " seconds" << endl;
	}

	fout.close();
	return 0;
}