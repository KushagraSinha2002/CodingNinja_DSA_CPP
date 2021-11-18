#include<iostream>
using namespace std;

int power(int x, int n) {
  cout << n << endl;
  if (n == 2)
  {
      return x * x;
  }
  
  int smallOutput = power(x,n-1);
  return x * smallOutput;

}


int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
}


