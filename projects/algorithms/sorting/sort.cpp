#include <iostream>
#include <vector>

using namespace std;

// 打印数组的函数
void printArray(const vector<int>& nums, const string& message) {
  cout << message << ": ";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

void bubbleSort(vector<int>& nums) {
  int n = nums.size();

  for (int i = 0; i < n - 1; ++i) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

void selectSort(vector<int>& nums) {
  int n = nums.size();

  for (int i = 0; i < n - 1; ++i) {
    int idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (nums[j] < nums[idx]) {
        idx = j;
      }
    }
    if (idx != i) {
      swap(nums[idx], nums[i]);
    }
  }
}

int partition(vector<int>& nums, int left, int right) {
  int ref = nums[right];
  int idx_mid = left;

  while (left < right) {
    if (nums[left] <= ref) {
      swap(nums[left], nums[idx_mid]);
      idx_mid++;
    }
    left++;
  }

  swap(nums[idx_mid], nums[right]);
  return idx_mid;
}

void quickSort(vector<int>& nums, int left, int right) {
  static int cnt = 0;
  if (left < right) {
    // printArray(nums, "the " + std::to_string(cnt++) + " round: ");
    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
  }
}

void quickSort(vector<int>& nums) {
  int n = nums.size();
  quickSort(nums, 0, n - 1);
}

void mergeOrderedVector(vector<int>& nums, int left, int mid, int right) {
  vector<int> result(right - left + 1);

  int il = left, ir = mid + 1, in = 0;

  while (il <= mid && ir <= right) {
    if (nums[il] < nums[ir]) result[in++] = nums[il++];
    else result[in++] = nums[ir++];
  }

  while (il <= mid) result[in++] = nums[il++];
  while (ir <= right) result[in++] = nums[ir++];

  for (int i = 0; i < right - left + 1; ++i) {
    nums[left + i] = result[i];
  }
}

void mergeSort(vector<int>& nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    mergeOrderedVector(nums, left, mid, right);
  }
}

void mergeSort(vector<int>& nums) {
  mergeSort(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums = {1, 7, 3, 5, 2, 9, 8, 4, 6};
  
  printArray(nums, "before bubbleSort: ");
  bubbleSort(nums);
  printArray(nums, "after bubbleSort: ");

  nums = {1, 7, 3, 5, 2, 6, 6, 9, 8, 4, 6};
  // nums = {4, 2, 4, 4, 3, 4, 7};
  printArray(nums, "before quickSort: ");
  quickSort(nums);
  printArray(nums, "after quickSort: ");

  nums = {1, 7, 3, 5, 2, 6, 6, 9, 8, 4, 6};
  printArray(nums, "before mergeSort: ");
  mergeSort(nums);
  printArray(nums, "after mergeSort: ");
  return 0;
}