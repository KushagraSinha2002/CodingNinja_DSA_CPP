#include <iostream>

using namespace std;

int helper(int input[], int l, int r, int x){
    if(l > r){
        return -1;
    }
    
    int mid = (l+r)/2;
    
    if(input[mid] == x){
       return mid;
    }
    else if(input[mid] > x){
        helper(input, l, mid - 1, x);
    }
    else if(input[mid] < x){
        helper(input, mid + 1, r, x);
    }
}

int binarySearch(int input[], int size, int element) {
    return helper(input, 0, size - 1, element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
