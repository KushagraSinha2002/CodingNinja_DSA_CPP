#include <iostream>
#include <string>

using namespace std;

string dialer[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */

   if (num == 0 || num == 1)
   {
       output[0] = "";
       return 1;
   }
   
   int lastDigit = num % 10;
   int smallNumber = num/10;
   
   // tells us how many rows are filled
   int smallOutputSize = keypad(smallNumber, output);

   string options = dialer[lastDigit];

    // loop1(i) makes copies and loop2(j) copies each elements within the copies
   for (int i = 0; i < options.length() - 1; i++)
   {
       for (int j = 0; j < smallOutputSize; j++)
       {
           output[j + ((i + 1) * smallOutputSize)] = output[j]; 
       }
   }

   int k = 0;
   
   // loop for simultaneously attaching each elements of options string
   for (int i = 0; i < options.length(); i++)
   {
       for (int j = 0; j < smallOutputSize; j++)
       {
           output[k] = output[k] + options[i];
           k++;
       }
   }
   
   return smallOutputSize * options.length();

}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
