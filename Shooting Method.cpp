#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
using std::cout;
double f(double t, double x, double x1) // Writing our 2nd order ODE as system of first orders
{
 return x1; // x1 is dx/dt
}
double g(double t, double x, double x1)
{
 return (-30.0 * x)/(2.0 + pow(t, 2.0)*pow(x,2.0));
}
double RK(double x1) // RK function
{
 int n = 1000; // Size of our steps
 int m;
 double h = 10 / double (n);
 // Initialising variables for RK
 double i1 = 0, i2 = 0, i3 = 0, i4 = 0, i = 0;
 double j1 = 0, j2 = 0, j3 = 0, j4 = 0, j = 0;
 // Starting conditions
 double x = 3.0/4.0, t = 0;
 // Runge Kutta to Solve
 for (int m = 0; m<n; m++)
 {
 i1 = h * f(t,x,x1);
 j1 = h * g(t,x,x1);
 i2 = h * f(t + (h / 2.0), x + (i1 / 2.0), x1 + (j1 / 2.0));
 j2 = h * g(t + (h / 2.0), x + (i1 / 2.0), x1 + (j1 / 2.0));
 i3 = h * f(t + (h / 2.0), x + (i2 / 2.0), x1 + (j2 / 2.0));
 j3 = h * g(t + (h / 2.0), x + (i2 / 2.0), x1 + (j2 / 2.0));
 i4 = h * f(t + h, x + i3, x1 + j3);
 j4 = h * g(t + h, x + i3, x1 + j3);
 //Formatting
 i = (1.0/6.0) * (i1 + (2.0 * i2) + (2.0 * i3) + i4);
 j = (1.0/6.0) * (j1 + (2.0 * j2) + (2.0 * j3) + j4);
 x = x + i;
 t = t + h;
 x1 = x1 + j;
 cout << x << "\n";
 }
 return x + 1; // x + 1 as x(10) is -1
 cout << x + 1.0 << "\n";
}
// Use bisection method to find roots of the function
double bisec(double c_neg, double c_pos)
{
 double b_neg = RK(c_neg);
 double b_pos = RK(c_pos);
 double c_mid;
 do
 {
 c_mid = 0.5 * (c_pos + c_neg);
 double b_mid = RK(c_mid);
 if (b_mid * b_neg > 0.0)
 {
 c_neg = c_mid; b_neg = b_mid;
 }
 else
 {
 c_pos = c_mid; b_pos = b_mid;
 }
 cout << c_neg << " - " << c_mid << " - " << c_pos << "\n";
 }
 while (c_pos - c_neg > 1.0e-10);
 return 0.5 * (c_pos + c_neg);
}
int main()
{
 RK(- 17.8325);
 return 0;
}
