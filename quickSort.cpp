#include<iostream>

using namespace std;

int partition(int *A, int start, int end){
  int pivot = A[end];
  int partitionIndex = start; // set partition index as start initially
  for(int i= start; i<end;++i){
    if(A[i] < A[pivot]){
      swap(A[i], A[partitionIndex]); // swap if element is lesser than pivot
      ++partitionIndex;
    }
  }
  swap(A[partitionIndex], A[end]); // swap pivot with element at partition index
  return partitionIndex;
}
 
void quickSort(int *A, int start, int end){
  if(start < end){
    int partitionIndex = partition(A, start, end);
    quickSort(A, start, partitionIndex-1);
    quickSort(A, partition+1, end);
  }
}

int main(){
  int A[] = {7,6,5,4,3,2,1,0};
  quickSort(A, 0 , 7);
  for(i =0;i<8;++i){
    cout<< A[i] << " ";
  }
  return 0;
}
