#include <iostream>
#include <cmath>

using namespace std;

int a, num, n;
int stringToNumber(char input[]) {
	if(input[0] == '\0'){
        n = -1;
        return 0;
    }
	int smallOutput = stringToNumber(input+1);
	n++;
	a = input[0] - 48;
	num = a * (pow(10,n));
	
	return smallOutput + num;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
