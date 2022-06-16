#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void Sort(std::vector<int>& arr);
void Print(std::vector<int>& arr, std::vector<int>::iterator beg, std::vector<int>::iterator end);
void copy_vec(std::vector<int>& arr, std::vector<int>& output, int index);
int maxelement(std::vector<int>::iterator beg, std::vector<int>::iterator end, int maximus);
int minelement(std::vector<int>::iterator beg, std::vector<int>::iterator end, int minimus);

int main()
{
    std::vector<int> arr = { 5, 0, -3, 8, 5, 8, -1, 10, -8, -1};
    Sort(arr);
    return 0;
}
 void Sort(std::vector<int>& arr)
{
    std::vector<int>::iterator beg = arr.begin();
    std::vector<int>::iterator end = arr.end();
    int maxi = *beg;
    int mini = *beg;
    auto max = maxelement(beg, end, maxi);
    auto min = minelement(beg, end, mini);
    int size = arr.size();
    int range = max - min + 1;
    std::vector<int> count(range);
    std::vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); i++){
        count[arr[i] - min]++;
    }
    for (int i = 1; i < count.size(); i++){
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    int index = 0;
    copy_vec(arr, output, index);
    Print (arr,beg,end);
}
int maxelement(std::vector<int>::iterator beg, std::vector<int>::iterator end, int maximus)
{
  if (beg == end){
    return maximus;
  }
  if (maximus < *beg){
    maximus = *beg;
  }  
  beg++;
  return maxelement(beg, end, maximus);
}
int minelement(std::vector<int>::iterator beg, std::vector<int>::iterator end, int minimus)
{
  if (beg == end){
    return minimus;
  } 
  if (minimus > *beg){
    minimus = *beg;
  }
  beg++;
  return minelement(beg, end, minimus);
}
void copy_vec(std::vector<int>& arr, std::vector<int>& output, int index){
   if ( index < arr.size()){
    arr[index]=output[index];
    index++;
    copy_vec(arr, output, index);
   }
}
void Print(std::vector<int>& arr, std::vector<int>::iterator beg, std::vector<int>::iterator end )
{
    if (beg != end){
        std::cout << *beg << " " ;
        beg++;
        Print(arr,beg,end);
    }
}