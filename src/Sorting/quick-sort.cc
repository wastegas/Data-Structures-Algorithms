#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

size_t partition(std::vector<std::string>& A, size_t p, size_t r)
{
  auto q = p;
  for (auto u = p; u <= (r - 1); u++) {
	  if (A[u] <= A[r]) {
		  std::swap(A[u], A[q]);
		  q++;
	  }
  }
  std::swap(A[q], A[r]);
  return q;
}

void quick_sort(std::vector<std::string>& A, size_t p, size_t r)
{
  if ((p - r) > 1) {
	auto q = partition(A, p, r);
	quick_sort(A, p, q - 1);
	quick_sort(A, q + 1, r);
  }
}

int main()
{
  std::vector<std::string> A;
  std::string in;
  while (std::cin >> in)
	A.push_back(in);
  quick_sort(A, 0, A.size() - 1);
  std::copy(A.begin(), A.end(),
			std::ostream_iterator<std::string>(std::cout, "\n"));
}
