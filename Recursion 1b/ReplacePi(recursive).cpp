#include <iostream> 

using namespace std;

void replacePi(char input[]) {
    
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'p'){
        if(input[1] == 'i'){
            int size = strlen(input);
            for(int i = size; i != 0; i--){
                input[i+2] = input[i];
            }
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
        }
    }
    replacePi(input+1);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
    