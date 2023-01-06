#include <iostream>
using namespace std;

int main()
{
    string A="AAACA";
    string B="AAA";

    int t_A= A.length();
    int t_B= B.length();

    if(t_A > t_B)
    {
        if(t_A-2==t_B)
        {
            cout<<"g"<<endl;
            for(auto i=A.begin(), j=B.begin(); i< A.end(), j < B.end() ;i++,j++)
            {
                if(A[i] != B[j])
                {
                    A.erase(i);
                    cout<<"g"<<endl;
                }
                    

            }
        }
        else
            cout<<"ERROR"<<endl;
    }
    cout<<A;

}