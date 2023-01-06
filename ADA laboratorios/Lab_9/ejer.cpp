
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
}

int editDistaux(string str1, string str2)
{
    std::vector<std::vector<int>> aux(str1.size() + 1, std::vector<int>(str2.size() + 1));

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

            else
                aux[i][j] = 1 + min(aux[i][j - 1],aux[i - 1][j],aux[i - 1][j - 1]);
        }
    }

    return aux[str1.size()][str2.size()];
}
void Verificacion(string str1, string str2)
{
    int check = editDistaux(str1, str2);
    if (check > 2)
    {
        cout << "Distinto" << endl;
    }
    else if (check >= 0 || check <= 2)
    {
        cout << "Similar" << endl;
    }
}
int main()
{
    string str1 = "AAAAAATTTTTTTTTAACGTAAAAAAAAAACGTCGTCGTAAAAAAAAAAAAAAAAAAACGTCGTCGTAAAAAAAAAAAT";
    string str2 = "AAAAAATTTTTTTTTAACGTAAAAAAAAAACGTCGTCGTAAAAAAAAAAAAAAAAAAACGTCGTCGTAAAAAAAAAAAAA";

    auto start = std::chrono::high_resolution_clock::now();
    Verificacion(str1, str2);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<< duration.count() << " microseg" << std::endl;
    return 0;
}