#include <iostream>
#include <cmath>

using namespace std;

int subsequence(string input, string output[]){
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);

    int smallStringSize = subsequence(smallString, output);

    for (int i = 0; i < smallStringSize; i++)
    {
        output[i + smallStringSize] = input[0] + output[i];
    }
    
    return 2 * smallStringSize;
    
}

int main(){
    string input;
    cin >> input;

    int size = pow(2,input.size());

    string* output = new string[size];

    int count = subsequence(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    

}