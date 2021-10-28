//Do not edit this file (unless you know what you are doing)

#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<random>
using namespace std;

#define SEP_SYMBOL ','

class matrix
{
	int n, m;
	double **M;
	friend int *get_size(const matrix &);
	friend int get_len(const matrix &); // throw (char*);
public:
	matrix(double = 0.0);
	matrix(int, int, double = 0.0); // throw (char*);
	matrix(int, double *); // throw (char*);
	matrix(int, int, double **); // throw (char*);
	matrix(const matrix &);
	~matrix();
	matrix &operator=(const matrix &);
	matrix operator[](int) const; // throw (char*);
	double &operator()(int = 0, int = 0); // throw (char*);
	double &operator()(int = 0, int = 0) const; // throw (char*);
	void set_col(const matrix &, int); // throw (char*);
	void set_row(const matrix &, int); // throw (char*);
	void add_col(double = 0.0);
	void add_row(double = 0.0);
	void add_col(const matrix &); // throw (char*);
	void add_row(const matrix &); // throw (char*);
};

matrix operator+(const matrix &, const matrix &); // throw (char*);
matrix operator-(const matrix &, const matrix &); // throw (char*);
matrix operator*(const matrix &, const matrix &); // throw (char*);
matrix operator/(const matrix &, const matrix &); // throw (char*);
matrix operator-(const matrix &);
bool operator<(const matrix &, const matrix &); // throw (char*);
bool operator>(const matrix &, const matrix &); // throw (char*);
bool operator<=(const matrix &, const matrix &); // throw (char*);
bool operator>=(const matrix &, const matrix &); // throw (char*);
bool operator==(const matrix &, const matrix &); // throw (char*);
bool operator!=(const matrix &, const matrix &); // throw (char*);
matrix ident_mat(int); // throw (char*);
matrix rand_mat(int, int); // throw (char*);
double det(const matrix &); // throw (char*);
matrix inv(const matrix &); // throw (char*);
matrix trans(const matrix &);
double norm(const matrix &); // throw (char*);
matrix hcat(const matrix &, const matrix &); // throw (char*);
matrix vcat(const matrix &, const matrix &); // throw (char*);
matrix get_col(const matrix &, int); // throw (char*);
matrix get_row(const matrix &, int); // throw (char*);
ostream &operator<<(ostream &, const matrix &);
istream &operator>>(istream &, matrix &); // throw (char*);
#endif