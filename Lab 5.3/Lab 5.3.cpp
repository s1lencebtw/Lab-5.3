#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x);

int main()
{
	double tp, tk, o;
	int n;
	cout << "gp = "; cin >> tp;
	cout << "gk = "; cin >> tk;
	cout << "n = "; cin >> n;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(7) << "qp" << " |"
		<< setw(10) << "qk" << " |"
		<< setw(10) << "z" << " |"
		<< setw(10) << "q" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	double dk = (tk - tp) / n;
	double t = tp;
	while (t <= tk)
	{
		o = f(pow(t, 2)) + 2 * f(2 * t + 1);
		cout << "|" << setw(7) << setprecision(2) << tp << " |"
			<< setw(10) << setprecision(5) << tk << " |"
			<< setw(10) << o << " |"
			<< setw(10) << t << " |"
			<< endl;
		t += dk;

	}
	return 0;
}

double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(x) + 1) / (sin(x) + cos(x));
	else
	{
		double S = 0;
		int i = 0;
		double a = x;
		S = a;
		do
		{
			i++;
			double g = (x * x) / ((2 * i - 1) * (2 * i));
			a *= g;
			S += a;
		} while (i <= 8);
		return S;
	}
}