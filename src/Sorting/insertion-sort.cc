/* insertion-sort
 * just as bad as selection sort
 * O(n^2)
 */
#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int>& A, size_t n)
{
  for (size_t i = 0; i < n; i++) {
	size_t j = i;
	while (j > 0 && A[j-1] > A[i]) {
	  std::swap(A[j],A[j-1]);
	  j--;
	}
  }
}

int main()
{
  std::vector<int> A{12, 9, 3, 7, 14, 11};
  sort(A, A.size());
  for (int &n : A)
	std::cout << n << " ";
  std::cout << '\n';
}
