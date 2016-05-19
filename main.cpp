#include <iostream>
#include "hash_table.h"

using std::cout;
using std::endl;

/**
 * @brief Created by Fábio Bento - 08/05/2016 @ random-guy github
 * A really simple implementation of a hash table using constant or user defined bucket size
 *
 * Based in the theory of this article: http://www.linuxjournal.com/content/hash-tables—theory-and-practice?page=0,0
 *
 * This hash table implementation was only for learning purposes, it is not intended for general use,
 * use std::unordered_map instead.
 */

int main()
{
    try{
        hash_table my_hash_table;
        my_hash_table.add("ola",1);
        my_hash_table.add("xarope",9);
        my_hash_table.add("sapo",27);
        my_hash_table.add("blabla",1000);
        my_hash_table.add("notebook",500);
        my_hash_table.add("headphones",1000);
        my_hash_table.add("surround",24);
        my_hash_table.add("tree",77);

        my_hash_table.print_table();
        cout << my_hash_table.get("blabla") << endl;

        cout << "-----------------------------\n";

        my_hash_table.remove("xarope");
        my_hash_table.remove("blabla");
        my_hash_table.print_table();
    }
    catch(const std::exception &e){
        cout << e.what() << endl;
    }

    return 0;
}

