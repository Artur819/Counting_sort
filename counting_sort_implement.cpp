#include <iostream>

void Counting_Sort_arr(int *array, int size);
void Print_Sort_arr(int *array, int size );
int main() {
  int array[] = {136,9,124,2,0,13,20,4,4,6,1,0};
  int n = sizeof(array) / sizeof(array[0]);
  Counting_Sort_arr(array, n);
  Print_Sort_arr( array, n);
}
void Counting_Sort_arr (int *array, int size) {
  int output[size + 1];
  int max_elem = array[0];
  int min_elem = array[0];
  for (int i = 1; i < size; ++i) {
    if (array[i] > max_elem)
      max_elem = array[i];
    if (array[i] < min_elem){
      min_elem = array[i];  
    }    
  }
 int * new_arr = new int [max_elem-min_elem+1];
  for (int i = 0; i < size; ++i) {
    new_arr[array[i]] = new_arr[array[i]]+1;
  }
  for (int i = 1; i <= max_elem; ++i) {
    new_arr[i] += new_arr[i - 1]; 
  }
  for (int i = size - 1; i >= 0; --i) {   
    output[new_arr[array[i]] - 1] = array[i];
    new_arr[array[i]]--;
  }
  for (int i = 0; i < size; ++i) {
    array[i] = output[i];
  }
  delete [] new_arr;
}
void Print_Sort_arr (int *array, int size) {
  std::cout << "Sorted array: ";
  for (int i = 0; i < size; ++i){
    std::cout << array[i] << " " ; 
  }
  std::cout << std::endl;
}
