#include <iostream>

void Counting_Sort_arr (int *array, int size);
void Print_Sort_arr (int *array, int size);

int main() {
  int array[] = { -136, 10, -9, 124, 0, 2, -9, -8, 3, 20, 4, 8, 4, -9, 6, 1, 7, 0};
  int n = sizeof(array) / sizeof(array[0]);
  Counting_Sort_arr (array, n);
  Print_Sort_arr ( array, n);
}
void Counting_Sort_arr (int *arr, int size) {
  int * output = new int [size];
  int max = arr[0];
  int min = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] > max) { 
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];  
    }    
  }
  int range = max - min + 1;
  int * count = new int [range];
  for (int i = 0; i < size; i++) {
    count[arr[i] - min]++;
  }
  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i] - min] - 1] = arr[i];
    count[arr[i] - min]--;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
  delete [] output;
  output = nullptr;
  delete [] count;
  count = nullptr;
}
void Print_Sort_arr (int *array, int size) {
  std::cout << "Sorted array : ";
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}