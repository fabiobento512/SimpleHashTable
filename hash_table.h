#ifndef HASH_TABLE_H
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>
#define HASH_TABLE_H

using std::vector;
using std::list;
using std::string;
using std::pair;
using std::runtime_error;

using uint = unsigned int;

class hash_table
{
public:
    hash_table();
    hash_table(uint size_bucket);
    const uint bucket_size = 100;
    vector
    <
        list
        <
            pair <string, int>
        >
    > buckets;
    void add(string key, int value);
    int get(string key);
    void remove(string key);
    void print_table();
private:
    int get_bucket(string key);
    int string_to_int(string key);
    int hash_function(int value);
};

#endif // HASH_TABLE_H
