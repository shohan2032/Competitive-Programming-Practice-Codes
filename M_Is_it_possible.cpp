#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    //Loop:
    //1)for loop
    //2)while loop
    //3)do while loop

    //Loop has three things
    //1)initializing
    //2)condition
    //3)increment/decrement
    //i++ = i+1
    //i-- = i-1

    // int i;
    // for(i = 5;i >= 1;i--){
    //     cout << i << endl;
    // }
    // cout << i << endl;

    // int i = 1;
    // while(i <= 10)
    // {
    //     if(i % 2 == 1)
    //         cout << i << endl;
    //     // else
    //     //     cout << i << endl;
    //     i++;
    // }
    // cout << i << endl;

    // int i = 10;//initializing
    // do
    // {
    //     cout << i << endl;

    //     i++;//increment//decrtement

    // }while(i <= 5);//condition


    // cout << i << endl;

    int n;
    cin >> n;
    for(int i = 1;i <= 10000;i++)
    {
        if(i % n == 2)
            cout<<i << endl;
    }

    return 0;
}
/*Problem_link

*/