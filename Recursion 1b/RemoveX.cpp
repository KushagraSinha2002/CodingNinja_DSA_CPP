#include <iostream> 

using namespace std;

#include <string.h>


void helper(char input[], int index, int size){
    
    if(input[index] == '\0'){
        return;
    }
    
    if(input[index] == 'x'){
        for(int i = index; i < size ; i++){
            input[i] = input[ i + 1];
        }
        size--;
    }
    else{
        index++;
    }
    
    helper(input, index, size);
    
}

void removeX(char input[]) {
    int size = strlen(input);
    helper(input, 0,size);

}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}