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
	ofstream hjw("hj.csv");
	ofstream ros("rs.csv");
	ofstream x01("xo1.csv");


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

double alpha = 0.5;						//dla hj 0.5		dla RS 0.5
double beta = 0.5;					//uzywana tylko w RS
double epsilon = 1e-3;					//1e-3
double s = 0.5;					//0.1 0.5  1.0 dlugosci krokow
double nmax = 1000;					//1000
/*
for (int i = 0; i < 100; i++) {
	double x0 = (rand() % 201/100.f)-1;				//losowanie liczb z zakresu -1 do 1 jako double
	double x1 = (rand() % 201/100.f)-1;				
	matrix x = matrix(2, new double[2]{ x0, x1 });
	solution hj = HJ(x, s, alpha, epsilon, nmax);
	x0 = round(x0 * 100) / 100;						//czasami w funkcji rand liczba ma wiecej niz 2 miejsca po przecinku wiec ja zaokrgalmy do 2 miejsc
	x1 = round(x1 * 100) / 100;
	cout << x0 << endl;
	cout << x1 << endl;
	x01 << "q" << x0 << "q" << x1 << endl;		//q sluzy za rozdzielanie tekstu dla unikniecia bledow z bialym znakiem w excelu
	hjw << "q" << hj.x.operator()(0) << "q" << hj.x.operator()(1) << "q" << hj.y<<"q"<< solution::f_calls << "\n";
	solution::clear_calls();
	matrix ss = matrix(2, new double[2]{ s,s });				//dla rs
	solution rs = Rosen(x, ss, alpha, beta, epsilon, nmax);

	ros << "q" << rs.x.operator()(0) << "q" << rs.x.operator()(1) << "q" << rs.y << "q" << solution::f_calls << "\n";
	solution::clear_calls();

}*/solution::clear_calls();

							//do testowych funckji
double x0 = (rand() % 201 / 100.f) - 1;				//losowanie liczb z zakresu -1 do 1 jako double
double x1 = (rand() % 201 / 100.f) - 1;
matrix x = matrix(2, new double[2] { x0, x1 });
solution hj= HJ(x, s, alpha, epsilon, nmax);

cout << "x0 " << hj.x.operator()(0) << endl;
cout << "x1 " << hj.x.operator()(1) << endl;
cout << "y " << hj.y<< endl; 
cout << solution::f_calls << endl;
solution::clear_calls();
matrix ss = matrix(2, new double[2]{ s,s });				//dla rs
solution rs = Rosen(x, ss, alpha, beta, epsilon, nmax);
cout << endl << "ROsen" << endl;
cout << "x0 " << rs.x.operator()(0) << endl;
cout << "x1 " << rs.x.operator()(1) << endl;
cout << "y " << rs.y << endl;
cout << solution::f_calls << endl;
solution::clear_calls();


#elif LAB_NO==3 && LAB_PART==2


#elif LAB_NO==3 && LAB_PART==3


double alpha = 0.5;						//dla hj 0.5		dla RS 0.5
double beta = 0.5;					//uzywana tylko w RS
double epsilon = 1e-3;					//1e-3
double s = 0.5;					//0.1 0.5  1.0 dlugosci krokow
double nmax = 1000;
/*
double k1 = rand() % 1001 / 100.f;
double k2 = rand() % 1001 / 100.f;

matrix k = matrix(2, new double[2]{ k1, k2 });
solution hj = HJ(k, s, alpha, epsilon, nmax);
cout << "hj" << endl;
cout << hj << endl;
solution::clear_calls;
matrix ss = matrix(2, new double[2]{ s,s });				//dla rs
solution rs = Rosen(k, ss, alpha, beta, epsilon, nmax);
cout << "Rosen" << endl;
cout << rs << endl;
solution::clear_calls;*/


//HJ
//double k1 = 2.76883, k2 = 3.18289;
//Rosenbrock
double k1 = 2.89383, k2 = 3.40945;

double t0 = 0, dt = 0.1, tend = 100;
matrix K = matrix(2, new double[2]{ k1, k2 });
matrix Y0 = matrix(2, new double[2]{ k1,k2 });

matrix* Y = solve_ode(t0, dt, tend, Y0, &K);


//cout << Y[0]<<endl;


cout << Y[1] << endl;



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
