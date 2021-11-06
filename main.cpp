/***************************************************
Code written for the optimization exercises purposes
by Lukasz Sztangret, PhD
Department of Applied Computer Science and Modelling
AGH University of Science and Technology
***************************************************/

#include"opt_alg.h"

int main()
{
	srand(time(NULL));
	ofstream Se("eks_0.csv");
	ofstream Sf("fib_0.csv");
	ofstream Sl("lag_0.csv");
	



	try
	{
		cout << "LAB NUMBER " << LAB_NO << endl;
		cout << "LAB PART " << LAB_PART << endl << endl;
#if LAB_NO==0

#elif LAB_NO==1 && LAB_PART==1
		double t0 = 0, dt = 0.1, tend = 50;
		matrix Y0 = matrix(2, new double[2]{ 0,0 }); //pierwsza wartosc x1 od 0, druga wartosc predkosc od 0(??)
		matrix* Y = solve_ode(t0, dt, tend, Y0); //funkcja solve_ode zwraca dwie macierze. Pierwsza to czas, druga rozwiązania w kroku czasowym
		matrix out = hcat(Y[0], Y[1]);
		ofstream sout("wyniki.csv");
		sout << out;
		sout.close();


#elif LAB_NO==1 && LAB_PART==2

#elif LAB_NO==2 && LAB_PART==1

		double x0;
		double d = 1;
		double alpha = 2.5;		
		double epsilon = 1e-5;
		double gamma = 1e-7;
		int Nmax = 1000;

		double* results[100];

		cout << "EKSPANSJA: " << endl << endl;

		for (int i = 0; i < 100; i++) {

			int x0 = rand() % 200 - 100;

			double* p = expansion(x0, d, alpha, Nmax);

			results[i] = p;

			cout << "x0: " << x0 << " \t " << "p[" << i << "]: " << p[0] << " \t " << "p[" << i + 1 << "]: " << p[1] << "   \t   " << "calls: " << solution::f_calls << endl;

			Se<<"q"<< x0 << "\t" << "q" << p[0] << "\t" << "q" << p[1] << "\t" << solution::f_calls << "\n";


			solution::clear_calls();

		}


		double* p = expansion(x0, d, alpha, Nmax);





		cout << endl << "FIBONACCI: " << endl << endl;

		for (int i = 0; i < 100; i++) {

			solution x_fib;

			double* res = results[i];

			x_fib = fib(res[0], res[1], epsilon);

			cout << "x" << i + 1 << ": " << x_fib.x << "\ty " << i + 1 << ": " << x_fib.y << "\tcalls: " << solution::f_calls << endl;

			Sf<<"q" << x_fib.x << "\t"<<"q" << x_fib.y << "\t" << x_fib.f_calls << "\n";


			solution::clear_calls();
		}



		cout << "Lagrange" << endl << endl;
		for (int i = 0; i < 100; i++) {
			double* res = results[i];
			solution x_lag = lag(res[0], res[1], epsilon, gamma, Nmax);
			cout << "x: " << x_lag.x << "\ty: " << x_lag.y << "\t calls: " << solution::f_calls << endl;


			Sl<<"q" << x_lag.x <<"\t"<<"q" << x_lag.y <<"\t"<<"q"<< x_lag.f_calls << "\n";
			

			solution::clear_calls();
		}

		

	
		solution::clear_calls();


#elif LAB_NO==2 && LAB_PART==2 

		double epsilon = 0.000001;
		double gamma = 0.0000001;
		int Nmax = 1000;
	solution x_fib = fib(5, 100, epsilon);
	cout << x_fib;
	solution::clear_calls();
	cout << endl << endl;

	solution x_lag = lag(10, 100, epsilon, gamma, Nmax);
	cout << x_lag;
	solution::clear_calls();




#elif LAB_NO==2 && LAB_PART==3 

double epsilon = 1e-6;
double gamma = 1e-7;
int Nmax = 1000;

solution opt_F = fib(1, 100, epsilon);
cout << "FIB: \n" << opt_F << endl << endl;

solution::clear_calls();
solution opt_L = lag(1, 100, epsilon, gamma, Nmax);
cout << "LAGRANGE: \n" << opt_L << endl << endl;
solution::clear_calls();

matrix Y0 = matrix(3, new double[3]{ 5,1,10 });
matrix* Y_F = solve_ode(0, 1, 1000, Y0, nullptr, &opt_F.x);
matrix* Y_L = solve_ode(0, 1, 1000, Y0, nullptr, &opt_L.x);

matrix SYM(get_len(Y_F[0]), 7);
SYM.set_col(Y_F[0], 0);
SYM.set_col(Y_F[1][0], 1);
SYM.set_col(Y_L[1][0], 2);
SYM.set_col(Y_F[1][1], 3);
SYM.set_col(Y_L[1][1], 4);
SYM.set_col(Y_F[1][2], 5);
SYM.set_col(Y_L[1][2], 6);

ofstream part_3("problem_rzeczywisty.csv");
part_3 << SYM;
part_3.close();




#elif LAB_NO==3 && LAB_PART==1

double alpha = 0.5;				//dla hj 0.5		dla RS 0.5
double beta = 0.5;		//uzywana tylko w RS
double epsilon = 1e-3;
double s = 0.1;					//0.1 0.5  1.0 dlugosci krokow
double nmax = 1000;

for (int i = 0; i < 100; i++) {
	int x0 = rand() % 3 - 1;				//ustawić zakres na -1 do 1 
	int x1 = rand() % 3 - 1;				//tez
	cout << x0 << endl;
	cout << x1 << endl;
}



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
	catch (char* EX_INFO)
	{
		cout << EX_INFO << endl;
	}
	system("pause");
	return 0;
}
