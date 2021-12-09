#include <iostream>

using namespace std;

void merge(int input[], int start, int end){

  int size = end - start + 1;
  int mid = (start + end) / 2;
  int* output = new int[size];
  int i = start;
  int j = mid + 1;
  int k = 0;


  while(i <= mid & j <= end){
    if (input[i] < input[j])
    {
      output[k] = input[i];
      i++;
      k++;
    }
    else{
      output[k] = input[j];
      j++;
      k++;
    }
  }

  while (i <= mid)
  {
    output[k] = input[i];
    i++;
    k++;
  }

  while (j <= end)
  {
    output[k] = input[j];
    j++;
    k++;
  }

  int m = 0;

  for (int i = start; i <= end; i++)
  {
    input[i] = output[m];
    m++;
  }

}

void merge_sort(int input[], int start, int end){

  if (start >= end)
  {
    return;
  }
  

  int mid = (start + end) / 2;

  merge_sort(input, start, mid);
  merge_sort(input, mid + 1, end);
  merge(input, start, end);

}

void mergeSort(int input[], int size){

  int start = 0;
  int end = size - 1;

  merge_sort(input, start, end);

}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}