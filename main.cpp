/***************************************************
Code written for the optimization exercises purposes
by Lukasz Sztangret, PhD
Department of Applied Computer Science and Modelling
AGH University of Science and Technology
***************************************************/

#include"opt_alg.h"

int main()
{
	try
	{
		cout << "LAB NUMBER " << LAB_NO << endl;
		cout << "LAB PART " << LAB_PART << endl << endl;
#if LAB_NO==0
		
#elif LAB_NO==1 && LAB_PART==1
		double t0 = 0, dt = 0.1, tend = 50;
		matrix Y0 = matrix(2, new double[2]{ 0,0 }); //pierwsza wartosc x1 od 0, druga wartosc predkosc od 0(??)
		matrix *Y = solve_ode(t0, dt, tend, Y0); //funkcja solve_ode zwraca dwie macierze. Pierwsza to czas, druga rozwi¹zania w kroku czasowym
		matrix out = hcat(Y[0], Y[1]);
		ofstream sout("wyniki.csv");
		sout << out;
		sout.close();


#elif LAB_NO==1 && LAB_PART==2
		
#elif LAB_NO==2 && LAB_PART==1
		// 3 rozne alfa
		//punkt startowy x0 od -100 do 100 moze by losowy
		// 100 razy kazda metoda
		//w excela to
		double x0 = -20, d = 1, alpha = 2, epsilon = 1e-5, gamma = 1e-200;
		int Nmax = 1000;

		double *p = expansion(x0, d, alpha, Nmax);
		cout << p[0] << '\t' << p[1] << endl;

		solution::clear_calls();
		solution opt_F = fib(p[0], p[1], epsilon);

		cout << opt_F << endl;
		solution::clear_calls();

		solution opt_L = lag(p[0], p[1], epsilon, gamma, Nmax);

		cout << opt_L << endl;
		solution::clear_calls();


#elif LAB_NO==2 && LAB_PART==2
		matrix ab_F(1, 1, 200);
		fib(-100, 100, 1e-5, &ab_F);
		cout << ab_F << endl;
		
#elif LAB_NO==2 && LAB_PART==3
		solution test(0.001);

		test.fit_fun();
		cout << test << endl;
		
#elif LAB_NO==3 && LAB_PART==1
		
#elif LAB_NO==3 && LAB_PART==2
		
#elif LAB_NO==3 && LAB_PART==3
		
#elif LAB_NO==4 && LAB_PART==1
		
#elif LAB_NO==4 && LAB_PART==2
		
#elif LAB_NO==5 && LAB_PART==1
		
#elif LAB_NO==5 && LAB_PART==2
		
#elif LAB_NO==5 && LAB_PART==3
		
#elif LAB_NO==6 && LAB_PART==1
		
#elif LAB_NO==6 && LAB_PART==2
		
#elif LAB_NO==7 && LAB_PART==1
		
#elif LAB_NO==7 && LAB_PART==2
		
#endif
	}
	catch (char * EX_INFO)
	{
		cout << EX_INFO << endl;
	}
	system("pause");
	return 0;
}
