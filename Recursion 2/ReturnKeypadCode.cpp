#include <iostream>
#include <string>

using namespace std;

// Version 1 :-

// string dialer[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

// int keypad(int num, string output[]){
//     /* Insert all the possible combinations of the integer number into the output string array. You do not need to
//     print anything, just return the number of strings inserted into the array.
//     */

//    if (num == 0 || num == 1)
//    {
//        output[0] = "";
//        return 1;
//    }
   
//    int lastDigit = num % 10;
//    int smallNumber = num/10;
   
//    // tells us how many rows are filled
//    int smallOutputSize = keypad(smallNumber, output);

//    string options = dialer[lastDigit];

//     // loop1(i) makes copies and loop2(j) copies each elements within the copies
//    for (int i = 0; i < options.length() - 1; i++)
//    {
//        for (int j = 0; j < smallOutputSize; j++)
//        {
//            output[j + ((i + 1) * smallOutputSize)] = output[j]; 
//        }
//    }

//    int k = 0;
   
//    // loop for simultaneously attaching each elements of options string
//    for (int i = 0; i < options.length(); i++)
//    {
//        for (int j = 0; j < smallOutputSize; j++)
//        {
//            output[k] = output[k] + options[i];
//            k++;
//        }
//    }
   
//    return smallOutputSize * options.length();

// }

// --------------------------------------------------------------------------------

// Version 2 :-

// string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
// 			//0 , 1,  2  ,3    ,4    , 5   ,6    ,7     ,8    ,9 
// int i=0;
// void keypad(int num,string o,string output[])
// {
//     if(num==0)
//     { 
//         output[i++]=o;
//         return ;
//     }
//     string temp=key[num%10];  // taking string corresponding to last digit
//     for(int i=0;i<temp.size();i++)
//         keypad(num/10,temp[i]+o,output);    //  taking every ch of temp in output 
// }
// int keypad(int num, string output[])
// {
//     string o="";
//     keypad(num,o,output);
//     return 100000;
// }

// --------------------------------------------------------------------------------

// version 3 

string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    
    int smallNum = num / 10;
    int lastDigit = num % 10;
    
    string smallString = key[lastDigit];
    int smallStringSize = smallString.size();
    
    int smallKeypadSize = keypad(smallNum, output);
    
    // Make copies of rows
    for(int i = 0; i < smallStringSize - 1; i++){
        for(int j = 0; j < smallKeypadSize; j++){
            output[j + (i + 1)*smallKeypadSize] = output[j];
        }    
    }
    
    int k = 0;
    
    // Attach string element of last digit in every copy respectively
    for(int i = 0; i < smallStringSize; i++){
        for(int j = 0; j < smallKeypadSize; j++){
            output[k] = output[k] + smallString[i];
            k++;
        }
    }
    
    return smallKeypadSize * smallStringSize;
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