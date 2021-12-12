#include<iostream>

using namespace std;

int partition(int input[], int si, int ei){

    int pivot = input[si];
    int count = 0;

    for (int i = si + 1; i <= ei; i++)
    {
        if (input[i] <= pivot)
        {
            count++;
        }
        
    }
    
    int pivotIndex = si + count;

    int temp = input[si];
    input[si] = input[pivotIndex];
    input[pivotIndex] = temp;

    int i = si, j = ei;

    while (i <= pivotIndex && j >= pivotIndex)
    {
        while (input[i] <= pivot)
        {
            i++;
        }
        while (input[j] > pivot)
        {
            j--;
        }

        if (i<pivotIndex && j>pivotIndex)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            
            i++;
            j--;
        }
        
    }
    
    return pivotIndex;
}

void quick_sort(int input[], int si, int ei){
    
    if (si >= ei)
    {
        return;
    }

    int p = partition(input, si, ei);

    quick_sort(input, si, (p - 1));

    quick_sort(input, (p + 1), ei);

}

void quickSort(int input[], int size) {

    int si = 0;
    int ei = size - 1;
    
    if (si >= ei)
    {
        return;
    }

    quick_sort(input, si, ei);

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