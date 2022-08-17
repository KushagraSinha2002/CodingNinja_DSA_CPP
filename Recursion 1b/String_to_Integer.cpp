#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

int helper(char input[], int num){
    if(input[0] == '\0'){
        return num;
    }
    return helper(input+1,num + (input[0]-48) * pow(10,strlen(input)-1));
}
int stringToNumber(char input[]) {
    if(input[0] == '\0'){
        return 0;
    }
    return helper(input,0);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
