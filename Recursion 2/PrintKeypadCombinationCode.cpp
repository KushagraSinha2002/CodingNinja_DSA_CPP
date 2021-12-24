#include <iostream>
#include <string>

using namespace std;

string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void helper(int num, string output){
    if(num == 0){
        cout << output << endl;
        return;
    }
    
    int smallNum = num/10;
    int lastDigit = num % 10;
    
    string smallString = key[lastDigit];
    
    for(int i = 0; i < smallString.size(); i++){
        helper(smallNum, smallString[i] + output);
    }
    
    
}

void printKeypad(int num){
    helper(num, "");
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
