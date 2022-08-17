#include <iostream> 
#include<cstring>
using namespace std;

void removeX(char input[]) {
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'x'){
        int len = strlen(input);
        for(int i=0;i<=len;i++){
            input[i] = input[i+1];
        }
        if(input[0] == 'x'){
            removeX(input);
        }
    }
    removeX(input+1);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}