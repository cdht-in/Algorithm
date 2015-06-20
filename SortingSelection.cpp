/*
  selection sort that takes O(n^2)
*/



//O(n^2)
void SelectionSort (int* data, int size)
{
  int tmp = 0;
  for (int i = 0; i < size - 1; i++) {
    int k = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[k])
        k = j;
    }
    tmp = data[i];
    data[i] = data[k];
    data[k] = tmp;
  }
}
