#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void eliminarRepetidos(vector<int> &v){ 
    sort(v.begin(), v.end());           
    for(int i=1; i<v.size(); i++){      
        if(v[i]==v[i-1]){               
            v.erase(v.begin()+i);       
            i--;                        
        }
    }
}
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> coleccion = {4,12,55,12,33,4,56,3,3,3,7,5,5,66,8,1,1};
    print(coleccion);
    eliminarRepetidos(coleccion);
    print(coleccion);
}