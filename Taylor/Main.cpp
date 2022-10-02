#include <iostream>
#include <cmath>
#include "Taylor.hpp"
int calcSin(int, double);

int calcCos(int, double);
using namespace std;

int main()
{
    //All N and x for which the functions are evaluated and compared
    int N [] = {1,2,5,10,100};
    int x [] = {-1,1,2,3,5,10};

    //Calculate, compare and print the results for the Sine Taylor expansion
    cout << scientific;
    cout << "sin(x)"<< endl;
    cout << "x\t\tN\tP(x)\t\tf(x)\t\t|P(x)-f(x)|\tabs next  term\terror bounded by next term?"<< endl;
    //Flag that is set to 0 if at least one of the approximations is not bounded by their next term
    int sinBounded =1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            sinBounded = min(calcSin(N[i],x[j]),sinBounded);
        }
    }
    if (sinBounded == 1)
    {
        cout << "All errors of the sine taylor polynomials are bounded by their next term"<<endl;
    }
    else
    {
        cout << "Not all errors of the sine taylor polynomials are bounded by their next term. Probably something went wrong"<<endl;
    }

    //Same stuff for the Cosine
    cout <<  endl << "cos(x)" << endl;
    cout << "x\t\tN\tP(x)\t\tf(x)\t\t|P(x)-f(x)|\tabs next  term\terror bounded by next term?"<< endl;
    int cosBounded =1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            cosBounded = min(calcCos(N[i],x[j]),cosBounded);
        }
    }
    if (sinBounded == 1)
    {
        cout << "All errors of the cosine taylor polynomials are bounded by their next term"<<endl;
    }
    else
    {
        cout << "Not all errors of the cosine taylor polynomials are bounded by their next term. Probably something went wrong"<<endl;
    }
    return 0;
}

int calcSin(int N, double x)
{
    //Taylor a approximation for sin(x)
    double sintx = sinTaylor(&N,&x);
    //Reference value for sin(x)
    double sinx = sin(x);
    double err = abs(sintx-sinx);
    //Error bound for sin(x)
    double errbound = sinErr(&N,&x);
    //Return value indicates if the error is bound by the next term.
    int ret;
    string convstr;
    if (err<errbound)
    {
        convstr = "yes";
        ret = 1;
    }
    else
    {
        convstr = "no";
        ret = 0;
    }
    //Print the results
    cout << x << "\t" << N << "\t" << sintx << "\t" << sinx << "\t" << err << "\t" << errbound <<"\t"<<  convstr << endl;
    return ret;
}

//Same stuff for the cosine
int calcCos(int N, double x)
{
    double costx = cosTaylor(&N,&x);
    double cosx = cos(x);
    double err = abs(costx-cosx);
    double errbound = cosErr(&N,&x);
    int ret;
    string convstr;
    if (err<errbound)
    {
        convstr = "yes";
        ret = 1;
    }
    else
    {
        convstr = "no";
        ret = 0;
    }
    cout << x << "\t" << N << "\t" << costx << "\t" << cosx << "\t" << err << "\t" << errbound <<"\t"<<  convstr << endl;
    return ret;
}

