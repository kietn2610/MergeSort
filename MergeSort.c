#include <stdio.h>

void msort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main()
{
  // test array and length
  printf("Test case 1: \n");
  int array1[] = { 1, 4, 3, 2, 10, 192, 4, -5, -7, -102};
  int length1 = 10;


  int array2[] = { -232, 232, 5, 0};
  int length2 = 4;


  int array3[] = { 256, 76, -3, 4};
  int length3 = 4;

  // sort the array using merge sort
  msort(array1, length1);
  msort(array2, length2);
  msort(array3, length3);

  // print out the array elements to verify they have been sorted
  print_array(array1, length1);
  printf("Test case 2: \n");
  print_array(array2, length2);
  printf("Test case 3: \n");
  print_array(array3, length3);

  return 0;
}

void msort(int *a, int length)
{
  merge_sort_recursion(a, 0, length - 1);
}


void merge_sort_recursion(int a[], int l, int r)
{

  if (l < r)
  {
    int m = l + (r - l) / 2;
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
  int left_length = m - l + 1;
  int right_length = r - m;

  int temp_left[left_length];
  int temp_right[right_length];

  int i, j, k;

  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];

  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];


  for (i = 0, j = 0, k = l; k <= r; k++)
{

    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
}

void print_array(int a[], int length){
    for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n\n");

}

