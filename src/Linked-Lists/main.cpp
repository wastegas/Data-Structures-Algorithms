#include <iostream>
#include "singly.h"

int main()
{
    try {
        singly::list<int> sl;
        for (int i = 10; i <= 50; i += 10) {
            sl.add_to_head(i);
        }
        for (;!sl.is_empty();) {
            std::cout << sl.pop_front() << std::endl;
        }
        if (sl.find(100)) {
            sl.delete_node(100);
        }
        else {
            std::cout << 100 << " not found\n";
        }
        sl.pop_front(); // should throw
    }
    catch (const char *e) {
        std::cerr << e << std::endl;
    }
}
