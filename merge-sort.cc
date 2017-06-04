/* merge-sort
 * divide and conquer
 */
#include <iostream>

void merge(int * A, size_t p, size_t q, size_t r)
{
  auto n1 = q - p + 1;
  auto n2 = r - q;
  int B[n1 + 1];
  int C[n2 + 1];
  for (auto i = 0; i < n1; i++) {
	  B[i] = A[p + i];
  }
  for (auto i = 0; i < n2; i++) {
	  C[i] = A[q + i + 1];
  }

  int i = 0;
  int j = 0;

  for (auto k = p; k <= r; k++) {
	  if (((j >= (sizeof(C) / sizeof(C[0])) - 1)) || 
		  ((i < (sizeof(B) / sizeof(B[0]) -1)) && (B[i] < C[j]))) {
		A[k] = B[i];
		i++;
	  }
	  else {
		  A[k] = C[j];
		  j++;
	  }
  }
}

void merge_sort(int * A, size_t p, size_t r)
{
  if ((r - p) > 1) {
	auto q = (p + r) / 2;
	merge_sort(A, p, q);
	merge_sort(A, q + 1, r);
	merge(A, p, q, r);
  }
}

int main()
{
  int A[10]{12, 9, 3, 7, 14, 11, 6, 2, 10, 5};
  size_t r = (sizeof(A) / sizeof(A[0]) ) - 1;
  size_t p = 0; 
  for (int i = 0; i <= r; i++) {

	  std::cout << A[i] << " ";
  }
  std::cout << '\n';
  merge_sort(A, p, r);
  for (int i = 0; i <= r; i++) {
	  std::cout << A[i] << " ";
  }
  std::cout << '\n';
}
