#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char arr[],int start,int end){
    if(start>end){
        return true;
    }
    if(arr[start]!=arr[end]){
        return false;
    }
    return checkPalindrome(arr,start+1,end-1);
}

bool checkPalindrome(char input[]) {
    int len = strlen(input);
    return checkPalindrome(input,0,len-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
