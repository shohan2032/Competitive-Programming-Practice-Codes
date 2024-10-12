#include<bits/stdc++.h>
using namespace std;
double code(double x)
{
    double result= sqrt((10.0 - pow(x,5))/3.0);
    return result;
}
int main()
{
    double x;
    cin >> x;
    double e=0.0005;
    double low=code(x);
    double hi=x;
    while(1){
        if(low+e>hi) {
            cout << "Md.Shohan_C211059_Secand" << endl << low << endl;
            break;
        }
        // cout << low << " " << hi << endl;
        double ans = code(low);
        hi=low;
        low=ans;
    }
    cout << "Md.Shohan_C211059_Fixed_point" << endl << low << endl;
    return 0;
}
