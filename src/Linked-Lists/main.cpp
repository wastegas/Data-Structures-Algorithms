#include <iostream>
#include "singly.h"

int main()
{
    singly::list<int> sl;
    for (int i = 10; i <= 50; i += 10) {
        sl.add_to_head(i);
    }
    for (;!sl.is_empty();) {
        std::cout << sl.pop_front() << std::endl;
    }
}
