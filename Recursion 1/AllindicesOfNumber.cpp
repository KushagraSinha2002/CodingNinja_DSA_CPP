#include<iostream>

using namespace std;


int helper (int input[], int size, int x, int output[], int index)
{
    if(size==0){
        return 0;
    }
    int s;
    if(input[0]==x){
        output[0]=index;
        s=helper(input + 1, size - 1, x, output+1, ++index)+1;
    }
    else
    {
        s=helper(input + 1, size - 1, x, output, ++index);
    }
    return s;
    
}
int allIndexes(int input[], int size, int x, int output[]) {
  
  return helper(input, size, x, output, 0);

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


