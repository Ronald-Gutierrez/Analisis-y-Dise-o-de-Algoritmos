#include <iostream>

using namespace std;

void Verificacion(string palabra1, string palabra2){
    int cant=0;
    for(char c: palabra1){
        for(auto b: palabra2){
            if (c==b) {
                c= ' ';
                b= ' ';                 
                cant++;
            }  
        }
    }
    int x = (cant*100)/palabra1.size();

    if(x>=60) cout<<"Suerte";
    else cout<<"NO";
}

int main(){
    /*A =  "↑"
     B =  "↓"
     C =  " →"
     D =  "←"
     F =  "↗"
     G =  "↖"*/
    Verificacion("ACGBAAAAAAAAAAAAAAAAABB", "AFGBABBBBBBBBBBB");
    return 0;
}