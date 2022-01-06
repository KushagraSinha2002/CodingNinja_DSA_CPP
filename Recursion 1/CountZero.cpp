#include <iostream>

using namespace std;

int n = 0;
int countZeros(int n) {
	if(n == 0){
        return 1;
    }
    if(n%10 == 0){
        n++;
    }
    int smallOutput = countZeros(n/10);
    
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
