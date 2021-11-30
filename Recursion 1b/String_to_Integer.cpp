#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int helper (char input[], int size, int ans){

    ans = input[0];
    ans = ans - 48;
    
    if (size == 1)
    {
        return ans;
    }

    return (ans * pow(10,size - 1) + helper(input + 1, size - 1, ans));

}

int stringToNumber(char input[]) {

    int size = strlen(input);
    int ans = 0;

    return helper(input, size, ans);
    

}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
