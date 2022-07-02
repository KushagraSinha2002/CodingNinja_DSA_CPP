#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string expression) {
    stack<char> s;
    bool ans;
    for(int i=0;i<expression.length();i++){
        if(expression[i] == ')'){
            int count=0;
            while(s.top() != '('){
                count++;
                s.pop();
            }
            if(count > 1){
                ans = false;
                s.pop();
                continue;
            }else{
                ans = true;
            }
        }
        s.push(expression[i]);
    }
    return ans;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}