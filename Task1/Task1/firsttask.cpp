#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

struct Greater {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    std::ifstream file1("name1");
    std::ifstream file2("name2");

    if (!file1 || !file2) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::istream_iterator<int> it1(file1), it2(file2), end;
    std::vector<int> v1(it1, end), v2(it2, end), result;

    result.resize(v1.size() + v2.size());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin(), Greater());

    std::ostream_iterator<int> out_it(std::cout, " ");
    std::copy(result.begin(), result.end(), out_it);
    std::cout << std::endl;

    std::ofstream outfile("output.txt");
    if (!outfile) {
        std::cerr << "Ошибка открытия выходного файла!" << std::endl;
        return 1;
    }

    std::ostream_iterator<int> file_out_it(outfile, " ");
    std::copy(result.begin(), result.end(), file_out_it);

    return 0;
}
