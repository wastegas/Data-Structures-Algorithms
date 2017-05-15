/*
 * Linear-Search
 * Search an array from left to right
 * return true if item is found
 */
#include <iostream>
#include <string>

/*
 * search(A,n,x)
 * A = array
 * n = size of array
 * x = item to search in array
 *
 * returns boolean, true if found else false
 */
bool search(std::string array[], size_t size, std::string item)
{
  bool answer = false;					// Step 1	once
  for (int i = 0; i < size; i++){		// Step 2	i< size;1+n times
										//			i++; n times
										//			i=0 once
	  if (array[i] == item)				// Step 2A	n times
		answer = true;					// once
  }
  return answer;						// Step 3	once
}

int main()
{
  std::string array[5]{"cat", "dog", "fish", "horse", "chicken"};
  std::cout <<  (search(array, (sizeof(array) / sizeof(array[0])), "horse") ? "found" : "not found");
  std::cout << std::endl;
} 
