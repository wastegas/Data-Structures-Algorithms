/*
 * Better-Linear-Search
 * Search an array from left to right
 * return immedately if found instead if 
 *		  iterating through entire array 
 */
#include <iostream>
#include <string>

/*
 * search(A,n,x)
 * A = array
 * n = size of array
 * x = item to search in array
 *
 * returns index of item if found or 0 if not found
 */
size_t search(std::string array[], size_t size, std::string item)
{
  for (int i = 0; i < size; i++) {
	  if (array[i] == item)
		return i;
  }
  return 0;
}

int main()
{
  std::string array[5]{"cat", "dog", "fish", "horse", "chicken"};
  std::cout <<  (search(array, (sizeof(array) / sizeof(array[0])), "plane") ? "found" : "not found");
  std::cout << std::endl;
} 
