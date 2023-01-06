#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
}

void coincidencia(string str1, string str2)
{
    std::vector<std::vector<int>> aux(str1.size() + 1, std::vector<int>(str2.size() + 1));
    int count=0;
    for (int i = 0; i <= str1.size(); i++)
    {
        for (int j = 0; j <= str2.size(); j++)
        {

            if (i == 0)
                aux[i][j] = j;

            else if (j == 0)
                aux[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                aux[i][j] = aux[i - 1][j - 1];

            else{
                aux[i][j] = 1 + min(aux[i][j - 1],aux[i - 1][j],aux[i - 1][j - 1]);
                count++;
            }
        }
    }

    int aux;

    aux = count/str2.size();
    if(aux>=0.6)
        cout<<"SUERTE";
    else
        cout<<"NO";
}
int main()
{
    //  0 =  "↑"
    //  1=  "↓"
    //  2 =  " →"
    //  3 =  "←"
    //  4 =  "↗"
    //  5 =  "↖"

    string cad_1="0001";
    string cad_2="0001";
    coincidencia(cad_1,cad_2);
    
}