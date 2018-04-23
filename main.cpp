#include <iostream>

#include <vector>
#include <map>

#include <algorithm>

template<class V, class Predicate>
void vector_remove_if(std::vector<V> &v, Predicate p) {
    v.erase(std::remove_if(v.begin(), v.end(), p), v.end());
};

template<class K, class V, class Predicate>
void map_remove_if(std::map<K, V> &m, Predicate p) {
    for (auto it = m.begin(); it != m.end(); (it = (p(*it) ? m.erase(it) : ++it)));
};

int main() {

    constexpr int SIZE = 30;
    std::vector<int> v(SIZE);

    for (auto i = 0; i < SIZE; ++i) { v[i] = i; }

    std::for_each(v.begin(), v.end(), [](int value) { std::cout << "Value before: " << value << std::endl; });
    vector_remove_if(v, [](int value) { return value % 2; });
    std::for_each(v.begin(), v.end(), [](int value) { std::cout << "Value after: " << value << std::endl; });

    std::map<int, float> m;

    for (auto i = 0; i < SIZE; ++i) { m.emplace(i, i * 12.1); }
    std::for_each(m.begin(), m.end(),
                  [](std::pair<int, float> entry) { std::cout << entry.first << ":" << entry.second << std::endl; });
    map_remove_if(m, [](std::pair<int, float> entry) { return entry.first % 2; });
    std::for_each(m.begin(), m.end(),
                  [](std::pair<int, float> entry) { std::cout << entry.first << ":" << entry.second << std::endl; });

    return 0;
}