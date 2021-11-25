#include <iostream>

using namespace std;

int helper(int num, int index){
    
    if(num == 0){
        return index;
    }
    
    if(num > 0){
        if(num % 10 == 0){
            index ++;;
        }
    }
    
    int smallOutput = helper(num/10,0);
    return index + smallOutput;
    
}

int countZeros(int num) {
    if(num == 0){
        return 1;
    }
    return helper(num,0);
    
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
