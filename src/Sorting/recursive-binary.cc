/*
 * Recursive-Binary search on data
 */
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>

void build_array(std::vector<std::string>& A)
{
  std::string in;
  while (std::cin >> in)
	A.push_back(in);
}

/*
 * binary_search
 * A = vector of strings
 * p = begining of array
 * r = end of array
 * x = search string
 *
 * returns index
 */
size_t binary_search(const std::vector<std::string>& A, 
					 size_t p, size_t r, const std::string x)
{
  if (p > r) {
	return 0;	// not found
  }

  size_t q = (p + r) / 2;	// get mid-point of array
  if (A[q] == x) {			// found
	  // termination
	  return q;				// return index of x
  }
  else {
	if (A[q] > x) {		// x is upper half of array
	  return binary_search(A, p, q - 1, x);	
	}
	else {
	  if (A[q] < x) {	// x is lower half
		 return binary_search(A, q + 1, r, x); 
	  }
	}
  }
}

int main()
{
  std::vector<std::string> A;
  std::thread t(&build_array, std::ref(A));
  t.join();
  size_t p = 0;
  size_t r = 0;
  r = A.size()-1;
  auto future = std::async(std::launch::async, binary_search, A, p, r, "abolish");
  size_t q = future.get();
  std::cout << A[q] << '\n';
  std::cout << (q ? "found"  : "not found");
  std::cout << std::endl;
}
