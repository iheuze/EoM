#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
#define G 1
// Let G = 1
// a = postion
// b = velocity
// x = number of bodies
double dist(double a[][3], int i, int j)
{
 return sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] -
 a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]));
}
void update(double a[][3], double b[][3], double h, int x, int q)
{
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < 3; ++j)
 {
 if (q == 0)
 {
 a[i][j] = a[i][j] + b[i][j] * h / 2;
 }
 else
 {
 a[i][j] = a[i][j] + b[i][j] * h;
 }
 }
 }
}
// acceleration calculation
// b = acceleration
void cc_acc(double a[][3], double b[][3], double m[], int x)
{
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < 3; ++j)
 {
 b[i][j] = 0;
 }
 }
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < x; ++j)
 {
 if (j != i)
 {
 for (int k = 0; k < 3; ++k)
 {
 b[i][k] -= (G * m[j] * (a[i][k] -
 a[j][k])) / (dist(a, i, j) * dist(a, i, j) * dist(a, i, j));
 }
 }
 }
 }
}
int main()
{
 const int n = 4;
 double h = 0.0001, time = 0;
 double xb[n][3], vb[n][3], ab[n][3], m[n];
 m[0] = 2.2; xb[0][0] = -0.5; xb[0][1] = 0.1; vb[0][0] = -0.84; vb[0][1] = 0.65;
 m[1] = 0.8; xb[1][0] = -0.6; xb[1][1] = -0.2; vb[1][0] = 1.86; vb[1][1] = 0.7;
 m[2] = 0.9; xb[2][0] = 0.5; xb[2][1] = 0.1; vb[2][0] = -0.44; vb[2][1] = -1.5;
 m[3] = 0.4; xb[3][0] = 0.5; xb[3][1] = 0.4; vb[3][0] = 1.15; vb[3][1] = -1.6;
 // Originally did it in 3 dimensions so just letting the third dimension = 0
 xb[0][2] = xb[1][2] = xb[2][2] = xb[3][2] = 0;
 vb[0][2] = vb[1][2] = vb[2][2] = vb[3][2] = 0;
 while (time <= 5)
 {
 update(xb, vb, h, n, 0);
 cc_acc(xb, ab, m, n);
 update(vb, ab, h, n, 1);
 update(xb, vb, h, n, 0);
 time += h;
 }
 cout << "Planets position at time, t = " << " " << time << endl;
 for (int j = 0; j < 4; ++j)
 {
 cout << "Planet " << j << ": " << " ";
 cout << setprecision(3) << fixed << xb[j][0] << ", ";
 cout << setprecision(3) << fixed << xb[j][1] << endl;
 }
 return 0;
}
