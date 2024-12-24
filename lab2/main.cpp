#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <locale>

// Задание 1
void task1(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    std::vector<int> V((std::istream_iterator<int>(file)), std::istream_iterator<int>());

    std::cout << "Элементы вектора в исходном порядке: " ;
    for (const auto& elem : V)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 2
void task2(std::deque<int>& D) {
    size_t N = D.size();
    auto it = D.begin() + N / 2;

    for (size_t i = 0; i < N / 2; ++i) {
        it = D.insert(it, -1);
    }

    std::cout << "Дек после модификации: ";
    for (const auto& elem : D)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 3
void task3(std::list<int>& L1, std::list<int>& L2) {
    auto mid = std::next(L2.begin(), L2.size() / 2);
    L1.splice(L1.begin(), L2, L2.begin(), mid);

    std::cout << "Список1 после слияния: ";
    for (const auto& elem : L1)
        std::cout << elem << " ";
    std::cout << std::endl;

    std::cout << "Список2 после слияния: " ;
    for (const auto& elem : L2)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 4
void task4(const std::string& filename, int N) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    char letter = 'A';
    std::generate_n(std::ostream_iterator<char>(file), N, [&letter]() { return letter++; });
}

// Задание 5
void task5(std::list<int>& L) {
    auto first_zero = std::find(L.begin(), L.end(), 0);
    if (first_zero != L.end())
        L.erase(first_zero);

    auto last_zero = std::find(L.rbegin(), L.rend(), 0);
    if (last_zero != L.rend())
        L.erase(std::next(last_zero).base());

    std::cout << "Список после удаления нулей: ";
    for (const auto& elem : L)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 6
void task6(std::deque<int>& D, int N) {
    if (2 * N > D.size()) {
        std::cerr << "Ошибка: неподходящий размер дека" << std::endl;
        return;
    }

    auto forward_gen = [n = 1]() mutable { return n++; };
    auto backward_gen = [n = N]() mutable { return n--; };

    std::generate(D.begin(), D.begin() + N, forward_gen);
    std::generate(D.rbegin(), D.rbegin() + N, backward_gen);

    std::cout << "Дек после заполнения: ";
    for (const auto& elem : D)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 7
void task7(std::vector<int>& V) {
    if (V.size() % 3 != 0) {
        std::cerr << "Ошибка: неподходящий размер вектора" << std::endl;
        return;
    }

    size_t N = V.size() / 3;
    std::inplace_merge(V.begin(), V.begin() + N, V.begin() + 2 * N);
    std::inplace_merge(V.begin(), V.begin() + 2 * N, V.end());

    std::cout << "Вектор после сортировки: ";
    for (const auto& elem : V)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 8
void task8(const std::list<std::string>& L) {
    if (L.size() < 2) {
        std::cerr << "Ошибка: недостаточно элементов списка" << std::endl;
        return;
    }

    std::deque<std::string> D;

    auto it = L.begin();
    auto nextIt = std::next(it);

    for (; nextIt != L.end(); ++it, ++nextIt) {
        D.push_back(std::string(1, it->front()) + nextIt->back());
    }

    std::cout << "Дек после трансформации: ";
    for (const auto& elem : D)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Задание 9
void task9(const std::vector<int>& V0, const std::vector<std::vector<int>>& Vectors) {
    std::multiset<int> base(V0.begin(), V0.end());
    int count = 0;

    for (const auto& V : Vectors) {
        std::multiset<int> current(V.begin(), V.end());
        if (std::includes(current.begin(), current.end(), base.begin(), base.end()))
            ++count;
    }

    std::cout << "Количество векторов, содержащих Вектор0: " << count << std::endl;
}

// Задание 10
void task10(const std::vector<int>& V) {
    std::multimap<int, int> M;

    for (const auto& elem : V) {
        int key = elem % 10;
        M.emplace(key, elem);
    }

    std::cout << "Группированная мультимапа: \n";
    for (const auto& pair : M) {
        int key = pair.first;
        int value = pair.second;
        std::cout << key << ": " << value << "\n";
    }
}


int main() {
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    
    task1("name.txt");

    std::deque<int> D = { 1, 2, 3, 4, 5, 6 };
    task2(D);

    std::list<int> L1 = { 1, 2, 3 };
    std::list<int> L2 = { 4, 5, 6, 7 };
    task3(L1, L2);

    task4("name2.txt", 10);

    std::list<int> L = { 1, 0, 2, 3, 0, 4 };
    task5(L);

    std::deque<int> D6(10);
    task6(D6, 5);

    std::vector<int> V = { 1, 2, 3, 7, 8, 9, 4, 5, 6 };
    task7(V);

    std::list<std::string> words = { "ABC", "DEF", "KLM", "XYZ" };
    task8(words);

    std::vector<int> V0 = { 1, 2 };
    std::vector<std::vector<int>> Vectors = { {1, 2, 3}, {1, 2}, {2, 3, 4} };
    task9(V0, Vectors);

    std::vector<int> V10 = { 23, 34, 45, 56, 67, 78 };
    task10(V10);

    return 0;
}
