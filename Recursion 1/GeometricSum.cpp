#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double geometricSum(int k){
    
    if(k < 0){
        return 0;
    }
    
    double power = pow(2,k);
    
    return 1.0/power + geometricSum(k-1);
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
