/*
 * Selection-soft
 * worst of the sorting algorithms
 * runs O(n^2)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>


void build_array(std::vector<std::string>& A)
{
  std::string in;
  while (std::cin >> in)
	A.push_back(in);
}

void sort(std::vector<std::string>& A, size_t n)
{
  for (size_t i = 0; i < n; i++) {
	  size_t smallest = i;
	  for (size_t j = i + 1; j < n; j++) {
		  if (A[j] < A[smallest]) smallest = j;
	  }
	  std::swap(A[i], A[smallest]);
  }
}

int  main()
{
  std::vector<std::string> A;
  std::thread t(&build_array, std::ref(A));
  t.join();
  size_t n = A.size();
  std::thread t2(&sort, std::ref(A), std::ref(n));
  t2.join();
  for (std::string &w : A)
	std::cout << w << '\n';
}
