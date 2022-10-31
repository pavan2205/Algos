List<int> BubbleSort(List<int> Arr) {
  bool Sorted = false;
  while (!Sorted) {
    Sorted = true;
    for (int i = 0; i < Arr.length - 1; i += 1) {
      if (Arr[i] > Arr[i + 1]) {
        dynamic Temp = Arr[i];
        Arr[i] = Arr[i + 1];
        Arr[i + 1] = Temp;
        Sorted = false;
      }
    }
  }

  return Arr;
}

void main() {
  List<int> UnSortedArr = [
    1,3,-1000,413,4,321,41,
    324,321,4,31,341,432,4,5
  ];
  
  List<int> SortedArr = BubbleSort(UnSortedArr);

  for (int i = 0; i < SortedArr.length; i += 1) {
    print(SortedArr[i]);
  }
}
