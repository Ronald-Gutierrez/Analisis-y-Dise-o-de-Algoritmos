#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#define FILA 5  
#define COLUMNA 5
#define MINA 'X'
#define CASILLA_SIN_DESCUBRIR '-'
#define CASILLA_DESCUBIERTA '_'
using namespace std;

void llenar_tablero(char tab[FILA][COLUMNA])
{
    for(int i=0; i<FILA; i++){
        for(int j=0; j<COLUMNA; j++)
            tab[i][j]=CASILLA_SIN_DESCUBRIR;
    }
}
void imprimir_tablero(char tab[FILA][COLUMNA])
{
    
    for(int i=0; i<FILA; i++){
        for(int j=0; j<COLUMNA; j++){
            char casilla_verdadera= CASILLA_SIN_DESCUBRIR;
            char casilla_actual= tab[i][j];
            if(casilla_actual == MINA)
            {
                tab[i][j] = CASILLA_SIN_DESCUBRIR;
            }
            else if (casilla_actual == CASILLA_DESCUBIERTA)
            {
                //Obtener las minas cercanas
                //BFS(i,j,tab);
            }
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}
void minar_tablero(char tab[FILA][COLUMNA])
{   
    srand(time(NULL));
    int cant_minas=4;
    for(int i=0;i<cant_minas;i++)
    {
        int fila = rand()%FILA;
        int columna = rand()%COLUMNA;
        tab[fila][columna]=MINA;
    }
}
int abrir_casilla(int fila, int columna, char tab[FILA][COLUMNA])
{
    if(tab[fila-1][columna-1]== MINA)
        return tab[fila-1][columna-1]=MINA;
    if (tab[fila-1][columna-1]== CASILLA_SIN_DESCUBRIR)
        return tab[fila-1][columna-1]=CASILLA_DESCUBIERTA;

    if(tab[fila-1][columna-1]== CASILLA_DESCUBIERTA)
        return tab[fila-1][columna-1] = CASILLA_DESCUBIERTA;
}

void BFS(int fila, int columna,char tab[FILA][COLUMNA])
{
    queue<int> cola;
    if(tab[fila][columna]== MINA)
    {
        cout<<tab[fila][columna];

    }

    cola.push(tab[fila][columna]);
    while(!cola.empty())
    {
        
    }
}


int main()
{

    char tablero[FILA][COLUMNA];
    llenar_tablero(tablero);
    minar_tablero(tablero);
    int casilla_abrir_f=0;
    int casilla_abrir_c=0;
    while(1)
    {
        imprimir_tablero(tablero);
        cout<<endl;
        cout<<"--Que casilla desea abrir --"<<endl;
        cin>>casilla_abrir_f;
        cin>>casilla_abrir_c;
        if (abrir_casilla(casilla_abrir_f,casilla_abrir_c,tablero)==  CASILLA_DESCUBIERTA)
        {
            cout<<"Selecciona otra casilla"<<endl;
        }
        else if (abrir_casilla(casilla_abrir_f,casilla_abrir_c,tablero)==MINA)
        {
            cout<<"PERDISTE"<<endl;
            break;
        }
        else 
            abrir_casilla(casilla_abrir_f,casilla_abrir_c,tablero);
    }
    return 0;
}