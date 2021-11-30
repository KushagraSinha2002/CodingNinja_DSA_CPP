#include <iostream> 

using namespace std;

#include <string.h>

#include <string.h>

void helper(char input[], int index, int size){
    
    if(index == strlen(input)-1){
        return;
    }
    
    if(input[index] == 'p'){
        if(input[index + 1] == 'i'){
            
            size = size + 2;
            
            for ( int i = index + 4; i < size; i++) {
                input[i] = input[i - 2];
            }
            
            input[index] = '3';
            input[index + 1] = '.';
            input[index + 2] = '1';
            input[index + 3] = '4';
        }
    }
    
    helper(input,index + 1, size);
    
}

void replacePi(char input[]) {
	
	int size = strlen(input);
    helper(input,0,size);

}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
    