/*
 * Recursive-Linear-Search
 */
#include <iostream>
#include <string>


/*
 * search(A,n,i, x)
 * A = array
 * n = size of array
 * i = index
 * x = item to search in array
 *
 * returns index of item if found or 0 if not found
 */
size_t search(std::string A[], size_t n, int i, std::string x)
{
  if (i > n) {
	return 0;
  }
  else {
	if (i <= n) {
	  if (A[i] == x) {
		return i;
	  }
	  else {
		  if (i <=n && A[i] != x)
		search(A, n, i + 1, x);
	  }
	}
  }
}

int main()
{
	std::string array[5]{"cat", "dog", "fish", "horse", "chicken"};
	int i = 0;
	std::cout << 
	  (search(array, (sizeof(array) / sizeof(array[0])), i, "chicken") ? "found" : "not found");
	std::cout << std::endl;
} 
