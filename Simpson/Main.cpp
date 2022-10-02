#include <iostream>
#include <cmath>
#include "ASI.hpp"
using namespace std;

double f(double);

int main()
{
    //Get all the variables and function evaluations to kickstart the algorithm
    double a = -1, c = 1;
    double b = (a+c)/2;
    double fa = f(a), fb = f(b), fc = f(c);
    
    double I1 = simp(fa,fb,fc,a,c);

    //Calculate the integral for different tollerances
    double tol = 1e-2;
    double ans2 = ASI(&f,a,b,c,tol,fa,fb,fc,I1);
    tol = 1e-3;
    double ans3 = ASI(&f,a,b,c,tol,fa,fb,fc,I1);
    tol = 1e-8;
    double ans4 = ASI(&f,a,b,c,tol,fa,fb,fc,I1);

    //Print the results and compare them to the result from matlab
    double matlab = 2.50080911033617;
    cout << scientific;
    cout <<"Matlab reference (abstol = 1e-8): "<<matlab<<endl;
    cout <<"tol\tI\t\tMatlab difference"<<endl;
    cout <<"1e-2\t"<<ans2<<"\t"<<abs(ans2-matlab)<<endl;
    cout <<"1e-3\t"<<ans3<<"\t"<<abs(ans3-matlab)<<endl;
    cout <<"1e-4\t"<<ans4<<"\t"<<abs(ans4-matlab)<<endl;
    
    return 0;
}

double f (double x)
{
    return 1+ sin(exp(3* x));
}