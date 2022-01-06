#include<iostream>

using namespace std;


int n = 0;

int allIndexes(int input[], int size, int x, int output[]) {
	if(size < 0){
        return 0;
    }
    int smallOutput = allIndexes(input, size-1, x, output);
    if(input[size] == x){
        output[n] = size;
        n++;
    }
    return n;
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


