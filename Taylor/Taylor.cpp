#include <cmath>
#include "Taylor.hpp"
using namespace std;
int sinDenom(int,int);
int cosDenom(int,int);
double calcErr(int, int, double*);
double trigTaylor(int*, double*, int(*)(int,int));

//Calculate the taylor approximation for sin(x) and cos(x)
double sinTaylor(int* N, double* x)
{
    double ans = trigTaylor(N,x,&sinDenom);
    ans = *x*(1+ans); 
    return ans;
}
double cosTaylor(int* N, double* x)
{
    double ans = trigTaylor(N,x,&cosDenom);
    ans = 1+ans;
    return ans;
}

//Calculate all but the first terms of the Taylor series for the cosine and sine using horners rule
double trigTaylor(int* N, double* x, int(*denom)(int,int))
{
    double ans = 0;
    double xsq = *x * *x;           //Calculate the square of x
    int fact = (*N%2==0)?-1:1;      //The -1 or 1 factor, initialised to -1 if N is even and otherwise to 1
    for (int n = 1; n < *N; ++n) {
        ans = xsq*(fact+ans)/denom(n,*N);
        fact = -1*fact;                     //Update the prefactor for the next  itteration
    }
    return ans;
}
//Functions for the denominators in the taylor expansin of sine and cosine using horners rule
int sinDenom(int n, int N)
{
    return 2*(2* N -2*n +1)*(N-n);//Another 2 can be factored out, but this would cause a cast to double
}
int cosDenom(int n, int N)
{
    return 2*(2* N -2*n -1)*(N-n);//Another 2 can be factored out, but this would cause a cast to double.
}

//Calculate the next term in the Taylor approximation for sine and cosine
double cosErr(int* N, double* x)
{
    return calcErr(*N, 2* *N+1, x);
}
double sinErr(int* N, double* x)
{
    return calcErr(*N+1, 2* *N+2,x);
}
double calcErr(int N, int formax, double* x)
{
    double err = abs(pow(*x,2* N));
    for (int i = 1; i < formax; i++ )
    {
        err=err/i;
    }
    return err;
}
