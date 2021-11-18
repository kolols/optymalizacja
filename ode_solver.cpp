//Do not edit the code below (unless you know what you are doing)

#include"ode_solver.h"

matrix *solve_ode(double t0, double dt, double tend, const matrix &Y0, matrix *ud, matrix *ad)
{
	int N = static_cast<int>(floor((tend - t0) / dt) + 1);
	if (N < 2)
		throw "The time interval is defined incorrectly";
	int *s = get_size(Y0);
	if (s[1] != 1)
		throw "Initial condition must be a vector";
	int n = s[0];
	delete[]s;
	matrix *S = new matrix[2]{ matrix(N,1), matrix(n,N) };
	S[0](0) = t0;
	for (int i = 0; i < n; ++i)
		S[1](i, 0) = Y0(i);
	matrix k1(n, 1), k2(n, 1), k3(n, 1), k4(n, 1);
	//cout << N << endl;
	for (int i = 1; i < N; ++i)
	{
		S[0](i) = S[0](i - 1) + dt;
		k1 = dt*diff(S[0](i - 1), S[1][i - 1], ud, ad);
		k2 = dt*diff(S[0](i - 1) + 0.5*dt, S[1][i - 1] + 0.5*k1, ud, ad);
		k3 = dt*diff(S[0](i - 1) + 0.5*dt, S[1][i - 1] + 0.5*k2, ud, ad);
		k4 = dt*diff(S[0](i - 1) + dt, S[1][i - 1] + k3, ud, ad);
		for (int j = 0; j < n; ++j)
			S[1](j, i) = S[1](j, i - 1) + (k1(j) + 2 * k2(j) + 2 * k3(j) + k4(j)) / 6;
		//cout << S[0](i)<<endl;
	}
	S[1] = trans(S[1]);
	return S;
}

//You can edit the following code


matrix diff(double t, const matrix &Y, matrix *ud, matrix *ad) //ud to y p to ud
{
#if LAB_NO==1 && LAB_PART==1
	
#elif LAB_NO == 1 && LAB_PART == 2
	
#elif LAB_NO==2 && LAB_PART==3
	double a = 0.98, b = 0.63, g = 9.81, PA = 1, PB = 1,
		Fin = -0.01, DB = 0.00365665, Tin = 10, TA = 90, TB = 10;
	double DA = (*ad)(0);
	DA = DA / 10000;
	double VAout = Y(0) <= 0 ? 0 : -a * b * DA * sqrt(2 * g * Y(0) / PA);		//zmiana objetosi w a
	double VBout = Y(1) <= 0 ? 0 : -a * b * DA * sqrt(2 * g * Y(1) / PB);		//zmiana objetosi w b
	double TinB = (((-VAout * 1000) * 90) + (10 * 10)) / ((-VAout * 1000) + 10);	//temp wody wpadajacej do b
	double TBdt = ((Fin - VAout) / Y(1)) * (TinB - Y(2));								// zmiana temp w b

	matrix dY(Y);
	dY(0) = VAout;
	dY(1) = Fin + VBout - VAout;
	dY(2) = TBdt;
	return dY;

	
#elif LAB_NO==3 && LAB_PART==3
	matrix dY(2, 1);
	double m_c = 10.0, m_r = 1.0, l = 0.5, b = 0.5, alfa_ref = M_PI, omega_ref = 0.0, I = (m_c * l * l) + ((m_r * l * l) / 3),
		k1 = (*ud)(0), k2 =(*ud)(1);
	double M = k1 * (alfa_ref - Y(0)) + k2 * (omega_ref - Y(1));

	dY(0) = Y(1);
	dY(1) = (M - b * Y(1)) / I;
	return dY;
	
#elif LAB_NO==4 && LAB_PART==2
	
#elif LAB_NO==7 && LAB_PART==2
	
#else
	matrix dY;
	return dY;
#endif
}