#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
#define N 12

int producto_matriz(int A[N][N], int B[N][N],int C[N][N])
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                C[i][j] += A[i][k] * B[k][j];    
}
void mostrar_matriz(int A[N][N],int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
void suma_matriz (int A[N][N], int B[N][N], int C[N][N], int n) 
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j]=A[i][j]+B[i][j];
}

void resta_matriz (int A[N][N], int B[N][N], int C[N][N], int n) 
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j]=A[i][j]-B[i][j];
}
 

 
void strassen(int A[N][N],int B[N][N],int C[N][N],int n)
{
    int A11[N][N],A12[N][N],A21[N][N],A22[N][N]; 
    int B11[N][N],B12[N][N],B21[N][N],B22[N][N];
    int C11[N][N],C12[N][N],C21[N][N],C22[N][N];
    int S1[N][N],S2[N][N],S3[N][N],S4[N][N],S5[N][N],S6[N][N],S7[N][N];
    int aux_1[N][N],aux_2[N][N];
    if (n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        for(int i=0;i<n/2;++i)
            for(int j=0;j<n/2;++j)
            {
                A11[i][j]=A[i][j];
                A12[i][j]=A[i][j+n/2];
                A21[i][j]=A[i+n/2][j];
                A22[i][j]=A[i+n/2][j+n/2];
 
                B11[i][j]=B[i][j];
                B12[i][j]=B[i][j+n/2];
                B21[i][j]=B[i+n/2][j];
                B22[i][j]=B[i+n/2][j+n/2];
            }
        //S1=(A11+A22)×(B11+B22)
        suma_matriz(A11,A22,aux_1,n/2);
        suma_matriz(B11,B22,aux_2,n/2);
        strassen(aux_1,aux_2,S1,n/2);

        //S2=(A21+A22)×B11
        suma_matriz(A21,A22,aux_1,n/2);
        strassen(aux_1,B11,S2,n/2);

        //S3=A11*(B12+B22)
        resta_matriz(B12,B22,aux_1,n/2);
        strassen(A11,aux_1,S3,n/2);

        //S4=A22×(B21+B11)
        resta_matriz(B21,B11,aux_1,n/2);
        strassen(A22,aux_1,S4,n/2);

        //S5=(A11+A12)×B22
        suma_matriz(A11,A12,aux_1,n/2);
        strassen(aux_1,B22,S5,n/2);

        //S6=(A11+A22)×(B11+B22)
        resta_matriz(A21,A11,aux_1,n/2);
        suma_matriz(B11,B12,aux_2,n/2);
        strassen(aux_1,aux_2,S6,n/2);

        //S7=(A12+A22)×(B21+B22)
        resta_matriz(A12,A22,aux_1,n/2);
        suma_matriz(B21,B22,aux_2,n/2);
        strassen(aux_1,aux_2,S7,n/2);

        //C11 = S1+S4-S5+S7
        suma_matriz(S1,S4,aux_1,n/2);
        resta_matriz(S7,S5,aux_2,n/2);
        suma_matriz(aux_1,aux_2,C11,n/2);

        //C12 = S3+S5
        suma_matriz(S3,S5,C12,n/2);

        //C21 = S2+S4
        suma_matriz(S2,S4,C21,n/2);
        
        //C22 = S1-S2+S3+S6
        resta_matriz(S1,S2,aux_1,n/2);
        suma_matriz(S3,S6,aux_2,n/2);
        suma_matriz(aux_1,aux_2,C22,n/2);
    
        for (int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++)
            {
                C[i][j]=C11[i][j];
                C[i][j+n/2]=C12[i][j];
                C[i+n/2][j]=C21[i][j];
                C[i+n/2][j+n/2]= C22[i][j];
            }
        }
    }
}
void rellenar_matriz(int A[N][N],int size)
{
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            A[i][j]=rand()%10;
    }
}
int main()
{
    int A[N][N];
    int B[N][N];
    int C[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            C[i][j]=0;
    }
    rellenar_matriz(A,N);
    rellenar_matriz(B,N);

    cout << "Matriz A" <<endl;
    mostrar_matriz(A,N);
    cout << "Matriz B" <<endl;
    mostrar_matriz(B,N);
    cout << "Matriz C" <<endl;
    auto start = std::chrono::system_clock::now();
    strassen(A,B,C,N);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    mostrar_matriz(C,N);
    cout<<"Tiempo de ejecucion: "<<duration.count()<<" ms"<<std::endl;
    return 0;
}