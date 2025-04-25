#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct less_abs : public std::binary_function<int, int, bool> 
{
    bool operator()(int a, int b) const 
	{
        return std::abs(a) < std::abs(b);
    }
};

int main() 
{
    std::vector<int> V = { 3, -2, 1, -1, 5, -6, -7 }; 

    auto it = std::adjacent_find(V.begin(), V.end(), std::not2(less_abs()));

    if (it != V.end()) 
    {
        std::cout << *it << " " << *(it + 1) << std::endl;
    }
    else 
    {
        std::cout << 0 << std::endl;
    }

    std::sort(V.begin(), V.end(), less_abs());

    std::cout << "Отсортированный вектор по модулю: ";
    for (int x : V) 
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}