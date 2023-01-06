#include <iostream>

using namespace std;

string find_path(int map[][],int  input_point,int  output_point){
    string path = "";
    int  current_point = input_point;
    while(current_point != output_point){
        if(map[current_point][current_point+1] == '~'){
            path += "Por Agua";
            current_point += 1;
        }
        else if(map[current_point][current_point-1] == '~'){
            path += "Por Agua";
            current_point -= 1;
        }
        else if(map[current_point][current_point+10] == '~'){
            path += "Por Agua";
            current_point += 10;
        }
        else if(map[current_point][current_point-10] == '~'){
            path += "Por Agua";
            current_point -= 10;
        }
    }
    return path; 
    
}
int main()
{
    return 0;
}