#ifndef MAP_H
#define MAP_H
#include "Employee.h"
#include <vector>
template <typename K, typename V>
class Map {
    private:
        struct node {
            K key;
            V value;
        };

    std::vector<node> data;
    public:
        void add(K key, V value) {
            node temp{key,value};
            data.push_back(temp);
        }
        V* find(K key) {
            for (auto &i  : data) {
                if (i.key == key) {
                    return &i.value;
                }
            }
            return nullptr;
        }
        friend std::ostream& operator<<(std::ostream& os, const Map& map) {
            for (auto &i : map.data) {
                os << i.value;
            }
            return os;
        }
};

















#endif