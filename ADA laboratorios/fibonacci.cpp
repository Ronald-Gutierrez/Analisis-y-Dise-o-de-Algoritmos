#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int num, vector<int>& list) {
    if (num == 0) {
        list[0]++;
        return 0;
    }
    if (num == 1) {
        list[1]++;
        return 1;
    }
    return fibonacci(num - 1, list) + fibonacci(num - 2, list);
}
int main() {
    vector<int> list(2, 0);
    cout << "CASO INPUT 0: ";
    fibonacci(0, list);
    cout << list[0] << " " << list[1] << endl;

    cout << "CASO INPUT 3: ";
    list.clear();
    list.resize(2, 0);
    fibonacci(3, list);
    cout << list[0] << " " << list[1] << endl;

    cout << "CASO INPUT 6: ";
    list.clear();
    list.resize(2, 0);
    fibonacci(6, list);
    cout << list[0] << " " << list[1] << endl;
    
    cout << "CASO INPUT 22: ";
    list.clear();
    list.resize(2, 0);
    fibonacci(22, list);
    cout << list[0] << " " << list[1] << endl;
}