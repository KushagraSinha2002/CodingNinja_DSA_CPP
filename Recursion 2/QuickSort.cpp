#include<iostream>

using namespace std;

int helper(int input[],int s,int e){
    //chose pivot
    int pivot=input[s];
    //count elements smaller than pivot and swap
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(input[i]<=pivot){
            count++;
        }
    }
    int pivotIndex=s+count;
    int temp=input[s];
    input[s]=input[pivotIndex];
    input[pivotIndex]=temp;
    
    //ensure left half contains elements smaller than pivot and right half larger
    int i=s, j=e;
    while(i<=pivotIndex && j>=pivotIndex){
        while(input[i]<=pivot){
            i++;
        }
        while(input[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quick_sort(int input[],  int startIndex, int endIndex){

    if (startIndex >= endIndex)
    {
        return;
    }
    
   int p= helper(input, startIndex, endIndex);
    
    quick_sort(input, startIndex, p-1);
    
    quick_sort(input,p+1, endIndex);
    

}

void quickSort(int input[], int size) {
  
  int startIndex = 0;
  int endIndex = size - 1;

  if (startIndex >= endIndex)
  {
    return;
  }

  quick_sort(input, startIndex, endIndex);


}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


