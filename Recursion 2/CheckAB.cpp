#include <iostream>

using namespace std;

bool check;

bool helper(char input[]){
    if(input[0] == '\0'){
        return true;
    }
    if(input[0] == 'a' || (input[0] == 'b' && input[1] == 'b')){
        if(input[1] == '\0'){
        	return true;
    	}
        if(input[1] == 'a'){
            check = helper(input + 1);
        }else if(input[1] == 'b' && input[2] == 'b'){
            check = helper(input + 3);
        }else{
            return false;
        }
    }
    return check;
}

bool checkAB(char input[]) {
    if(input[0] != 'a'){
        return false;
    }
    if(input[0] == '\0'){
        return true;
    }
    
    return helper(input);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
