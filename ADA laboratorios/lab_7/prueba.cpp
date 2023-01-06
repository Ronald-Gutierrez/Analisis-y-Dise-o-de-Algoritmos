#include <iostream>
#include <climits>
#include <chrono>
using namespace std;
int main()
{
    int tmp=0;
    int num_eval=6;
    int c1=4;
    int c2=3;
    int c3=1;

    int a=num_eval%c1;
    

    if(a != 0)
    {
        tmp=tmp+a;
        int b=num_eval%c2;
        if(b != 0)
        {
            tmp=tmp+b;
            int c=num_eval%c3;
            
            if(c != 0)
                tmp=tmp+c;
            else
                tmp=tmp+1;
        }
        else
            tmp=tmp+1;
    }
    else 
        tmp=tmp+1;

    cout<<tmp;

    return 0;
}