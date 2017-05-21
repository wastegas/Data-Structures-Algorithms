/*
 * Binary search on data
 */
#include <iostream>
#include <string>
#include <vector>

/*
 * binary_search
 * A = vector of strings
 * n = size of vector
 * x = search string
 *
 * returns index
 */
size_t binary_search(const std::vector<std::string>& A, size_t n, const std::string x)
{
  // initialization
  size_t p = 0;	  // initial begining of array
  size_t r = n;	  // initial end of array
  
  while (p <= r) {
	  // maintenance
	  size_t q = (p + r) / 2;	// get mid-point of array
	  if (A[q] == x) {			// found
		  // termination
		  return q;				// return index of x
	  }
	  else {
		  if (A[q] > x) {		// x is upper half of array
			  r = q - 1;		// reposition r to half-way point
		  }
		  else {
			  if (A[q] < x) {	// x is lower half
				  p = q + 1;	// reposition p to half-way point
			  }
		  }
	  }
  }
  // termination
  return 0;	// not found
}

int main()
{
  std::vector<std::string> A;
  std::string in;
  while (std::cin >> in)
	A.push_back(in);
  std::cout << (binary_search(A, A.size()-1, "abolish") ? A[binary_search(A, A.size()-1, "abolish")]  : "not found");
  std::cout << std::endl;
}
