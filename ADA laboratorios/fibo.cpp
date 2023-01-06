#include <iostream>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


void respuestas(int n, int res[2])
{
    if (n == 0)
    {
        res[0] = 1; 
        res[1] = 0;
    }
    else if (n == 1)
    {
        res[0] = 0;
         res[1] = 1;
    }
    else if (n == 2)
    {
        res[0] = 1;
        res[1] = 1;
    }
    else
    {
        res[0] = fibonacci(n-1);
        res[1] = fibonacci(n);
    }
}


int main()
{
    int n;
    std::cin >> n;
    int res[2];
    respuestas(n, res);
    std::cout << res[0] << " " << res[1] << std::endl;
    
    return 0;
}