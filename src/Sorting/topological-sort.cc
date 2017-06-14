#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <iterator>

class Graph {
private:
  std::multimap<int, int> adjacencyList;
public:
  Graph(const std::multimap<int, int> e) {
	  adjacencyList = e;
  }
  void topological_sort() {
	  // step 1, 2
	  std::vector<int> in_degree(adjacencyList.size()-1, 0);
	  // step 3
	  for (auto const& a : adjacencyList) 
		  in_degree[a.second] += 1;

	  // step 4
	  std::list<int> next;
	  for (auto const& n : adjacencyList){
		  if(in_degree[n.first] == 0) {
			  next.push_back(n.first);
		  }
	  }
	  // step 5
	  std::vector<int> linear_order;
	  while(!next.empty()) {
		  linear_order.push_back(next.front()); // 5B
		  int u = next.front();					// 5A delete vertext from next
		  next.pop_front();					    // add to end of linear order
		  
		  // 5C
		  for (auto const& n : adjacencyList) {
			  if(n.first == u) {
				if((in_degree[n.second] -=1) == 0 && n.second != 0)
				  next.push_front(n.second);
			  }
		  }
	  }
	  std::copy(linear_order.cbegin(), linear_order.cend(),
				std::ostream_iterator<int>(std::cout, " "));
  }
};

int main()
{
  std::multimap<int, int> edge {
		{1,3}, {2,4}, {3,4}, {3,5},
		{4,6}, {5,6}, {6,7}, {6, 11},
		{7,8}, {8,13}, {9,10}, {10,11},
	    {11,12}, {12,13}, {13,14}, {14,0}
  };
  std::cout << "Adjacency list:\n";
  for(auto const& e : edge)
	std::cout << "u:" << e.first << " v:" << e.second<< '\n';
  Graph g(edge);
  g.topological_sort();
  std::cout << '\n';
}
