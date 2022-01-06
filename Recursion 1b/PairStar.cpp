#include <iostream>
#include <cstring>

using namespace std;

void pairStar(char input[]) {
	if(input[0] == '\0'){
       return; 
    }
    if(input[0] == input[1]){
        for(int i = strlen(input); i != 0; i--){
            input[i+1] = input[i];
        }
        input[1] = '*';
        pairStar(input);
    }
    pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
