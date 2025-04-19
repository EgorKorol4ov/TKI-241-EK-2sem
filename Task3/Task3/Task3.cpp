#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

void CountAndPrint(const std::vector<int>& V) 
{
    std::map<int, int> M;
    std::for_each(V.begin(), V.end(), [&M](int val) {
        M[val]++;
        });
    std::for_each(M.begin(), M.end(), [](const std::pair<const int, int>& p) {
        std::cout << p.first << " " << p.second << std::endl;
        });
}

int main() 
{
    std::vector<int> V1 = { 1, 2, 2, 3, 1, 4, 2 };
    std::cout << "Результат:\n";
    CountAndPrint(V1);

    return 0;
}