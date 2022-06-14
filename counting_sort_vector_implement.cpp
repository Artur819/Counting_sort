#include <iostream>
#include <vector>
#include <algorithm>

void Sort(std::vector<int>& arr);
void Print(std::vector<int>& arr); 

int main()

{
    std::vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
    Sort(arr);
    Print(arr);
    return 0;
}
void Sort(std::vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
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
    for (int i = 0; i < arr.size(); i++){
        arr[i] = output[i];
    }
}
void Print(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++){
       std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
