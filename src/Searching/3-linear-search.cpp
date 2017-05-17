/*
 * Sentinel-Linear-Search (item is known to be in array)
 * Save last item in array to a variable, replace last elem with item
 * search through array until found and restore last item in array 
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
  std::string last = array[size-1];
  size_t i = 0;
  while (array[i] != item) {
	i++;	
  }
  array[size-1] = last;
  if (i < size || array[size-1] == item)
	return i;
  return 0;
}

int main()
{
  std::string array[5]{"cat", "dog", "fish", "horse", "chicken"};
  std::cout <<  (search(array, (sizeof(array) / sizeof(array[0])), "chicken") ? "found" : "not found");
  std::cout << std::endl;
} 
