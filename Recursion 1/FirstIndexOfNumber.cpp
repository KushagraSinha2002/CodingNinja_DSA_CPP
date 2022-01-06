#include<iostream>

using namespace std;

int firstIndex(int input[], int size, int x){
    if(size == 0){
        return -1;
    }
    int smallOutput = firstIndex(input+1,size-1,x);
    if(input[0] == x){
        return 0;
    }
    if(smallOutput != -1){
        return smallOutput + 1;
    }
    else{
        return -1;
    }
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
    
    cout << firstIndex(input, n, x) << endl;

}


