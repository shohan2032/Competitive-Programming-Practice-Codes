Code :
//Guass Seidel Method
#include<iostream>
#include<iomanip>
#include<math.h>
/* Defining function */
#define f1(x,y,z) (58-2*y-3*z)/45
#define f2(x,y,z) (47+3*x-2*z)/22
#define f3(x,y,z) (67-5*x-y)/20
using namespace std;
/* Main function */
int main()
{
  float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
  int step=1;
  /* Setting precision and writing floating point values in fixed-point notation.
  */
  cout<< setprecision(4)<< fixed;
  /* Input */
  /* Reading tolerable error */
  cout<<"Enter tolerable error: ";
  cin>>e;
  cout<< endl<<"Count\t\tx\t\ty\t\tz"<< endl;
  do
  {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  cout<< step<<"\t\t"<< x1<<"\t\t"<< y1<<"\t\t"<< z1<< endl;
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  step++;
  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
  }while(e1>e && e2>e && e3>e);
  cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
  return 0;
}