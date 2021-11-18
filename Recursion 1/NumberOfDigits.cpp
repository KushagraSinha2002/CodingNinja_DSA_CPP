#include<iostream>

using namespace std;

int count(int n){
    
    if (n == 0)
    {
        return 0;
    }
    
    int smallOutput = count(n/10);
    return  smallOutput + 1;

}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


