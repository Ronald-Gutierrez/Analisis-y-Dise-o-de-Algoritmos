#include <iostream>
#include <vector>
using namespace std;

void insertionSort(std::vector<int> &list);
void printVector(vector<int> &lista);

int main()
{
    vector<int> vector1={4,2,65,8,6,3};
    insertionSort(vector1);
    printVector(vector1);
    return 0;
}

void insertionSort(vector<int> &lista)
{
    for (int i = 1; i < lista.size(); i++) {
        int key = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > key) {
            lista[j + 1] = lista[j]; 
            j--;
        }
        lista[j + 1] = key;
    }
}
void printVector(vector<int> &lista)
{
    for (int i=0; i<lista.size(); i++) {
        cout << lista[i]<<" ";
    }
}