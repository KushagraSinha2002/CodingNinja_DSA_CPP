#include <iostream>

using namespace std;

int multiplyNumbers(int x, int y){
    
    if(y == 0){
        return 0;
    }
    
    int smallOutput = multiplyNumbers(x,y - 1);
    return x + smallOutput;
    
    
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
