#include <iostream>
#include <deque>

void insert_before_first_half(std::deque<int>& d) {
    int N = d.size();

    for (std::deque<int>::reverse_iterator r(d.begin() + N / 2); r != d.rend(); ) {
        auto it = d.insert(--r.base(), -1);
        r = std::deque<int>::reverse_iterator(it);
    }
}

int main() {
    std::deque<int> d = { 1, 2, 3, 4, 5, 6 };

    insert_before_first_half(d);

    std::cout << "d: ";
    for (int x : d) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}