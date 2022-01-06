#include<iostream>

using namespace std;

// Version 1 :-

// int lastIndex(int input[], int size, int x) {
// 	if(size == 0){
//         return -1;
//     }
//     int smallOutput = lastIndex(input+1,size-1,x);
//     if(smallOutput != -1){
//         return smallOutput+1;
//     }
//     if(input[0] == x){
//         return 0;
//     }
//     else{
//         return -1;
//     }
// }

// Version 2:-

int lastIndex(int input[], int size, int x) {
	if(size < 0){
        return -1;
    }
    if(input[size-1] == x){
        return size-1;
    }
    int smallOutput = lastIndex(input, size-1, x);
    return smallOutput;
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
    
    cout << lastIndex(input, n, x) << endl;

}