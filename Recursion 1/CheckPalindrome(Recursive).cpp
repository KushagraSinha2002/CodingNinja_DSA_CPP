#include <iostream>

using namespace std;

#include<string.h>

bool helper(char input[], int index, bool temp){
    
    if(index == strlen(input)/2){
        return temp;
    }
    
    if(input[index] == input[strlen(input)-index - 1]){
        temp = true;
    }
    else{
        temp = false;
    }
    
    return helper(input,index + 1, temp);
    
}

bool checkPalindrome(char input[]) {
    
    if (strlen(input) == 0){
        return true;
    }
    
    return helper(input,0,false);

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
