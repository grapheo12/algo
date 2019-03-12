#include <stdio.h>
#define CEIL(x) ((x) == (int)(x)) ? (x) : (int)(x) + 1

void printArray(int A[], int n){
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void mergeSubset(int A[], int l1, int r1, int l2, int r2){
  //Merges in ascending order two sub-arrays
  //with indices (l1, r1) and (l2, r2) respectively and of length = size

  int buffer[(r1 - l1) + (r2 - l2)];
  int i = l1, j = l2, index = 0;

  while (i <= r1 && j <= r2){
    if (A[i] < A[j]){
      buffer[index] = A[i];
      i++;
    }else{
      buffer[index] = A[j];
      j++;
    }
    index++;
  }

  while (i <= r1){
    buffer[index] = A[i];
    i++, index++;
  }

  while (j <= r2){
    buffer[index] = A[j];
    j++, index++;
  }

  //Copy back to A.
  int k, l = 0;
  for (k = l1; k <= r1; k++)
    A[k] = buffer[l++];
  for (k = l2; k <= r2; k++)
    A[k] = buffer[l++];
}

void blockMergeAll(int A[], int size, int chunk){
  int blocks = CEIL(size / (float)chunk);
  //If number of blocks is odd, last merged with penultimate block
  if (blocks % 2 == 1){
    blockMergeAll(A, size - chunk, chunk);
    return;
  }

  //So at this stage, we are left with even number of blocks.
  //So merging will be complete.

  //Merge normally uptill the penultimate and ultimate block.
  //Since ultimate block has variable size, it requires special treatment.

  int i = 0;
  for (i = 0; i < (blocks - 2) * chunk; i += 2 * chunk)
    mergeSubset(A, i, i + chunk - 1, i + chunk, i + 2 * chunk - 1);

  //Now special treatment
  mergeSubset(A, i, i + chunk - 1, i + chunk, size - 1);
}

void blockMergeSort(int A[], int size){
  int i;
  for (i = 1; CEIL(size/i) > 1; i = i << 1){
    blockMergeAll(A, size, i);
    printArray(A, size);
  }
}

int main(){
  int A[15] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 100, -100, -230, 230, -400};
  blockMergeSort(A, 15);
  return 0;
}
