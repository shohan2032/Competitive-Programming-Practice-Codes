
#include<bits/stdc++.h>
using namespace std;
double code(double x)
{
	return pow(x,3) - pow(x,2) + 2;
}
int main()
{
    double x1,x2,result;
    level:
    cout << "Give two boundary value :(x1 and x2) : ";
    cin >> x1 >> x2;
    double x0,s;
    double w = 0.0005;
    int ans=0;
    while(1)
    {
        x0= x1 - (code(x1)*(x2-x1)/(code(x2)-code(x1)));
        if(ans!=0)
        {
            if(abs(x0-s)<w)
            {
                cout << "Md.Shohan_C211059_False position" << endl << x0 << "\n";
                break;
            }
        }
        if(code(x0)*code(x1)<0)
        {
            s = x1 - (code(x1)*(x2-x1)/(code(x2)-
            code(x1)));
            x2=x0;
        }
        else
        {
            s = x1 - (code(x1)*(x2-x1)/(code(x2)-
            code(x1)));
            x1=x0;
        }
        ans++;
    }
    return 0;
}
