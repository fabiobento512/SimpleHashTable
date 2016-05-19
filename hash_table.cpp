#include "hash_table.h"

hash_table::hash_table():hash_table(bucket_size){}

hash_table::hash_table(uint size_bucket): bucket_size(size_bucket)
{
    this->buckets.reserve(this->bucket_size);

    // fill buckets with empty lists
    for(uint i=0; i<this->bucket_size; i++){
        this->buckets.push_back( list< pair<string,int> >() );
    }
}

void hash_table::add(string key, int value)
{
    pair<string,int> curr_pair(key,value);

    this->buckets[get_bucket(key)].push_back(curr_pair);
}

int hash_table::get(string key)
{
    int curr_bucket;

    curr_bucket = get_bucket(key);

    const list< pair<string,int> > &curr_list = this->buckets[curr_bucket];

    if(curr_list.size() == 0){
        return -1; // not found
    }
    else if(curr_list.size() == 1){
        return curr_list.front().second;
    }
    else{ // if there's one more element a colision has occurred... in this case we need to do a sequencial search

        for(const pair<string, int> &curr_pair : curr_list){
            if(curr_pair.first == key){
                return curr_pair.second;
            }
        }

    }

    return -2; // something very wrong happened!!
}

void hash_table::remove(std::string key)
{
    int curr_bucket;

    curr_bucket = get_bucket(key);

    list< pair<string,int> > &curr_list = this->buckets[curr_bucket];

    if(curr_list.size() == 0){
        throw runtime_error("Key " + key + " not found to remove");
    }
    else if(curr_list.size() == 1){
        curr_list.pop_back();
        return;
    }
    else{ // if there's one more element a colision has occurred... in this case we need to do a sequencial search

        list< pair<string,int> >::iterator it;

        for(it=curr_list.begin(); it!=curr_list.end(); ++it){
            if( (*it).first == key ){
                curr_list.erase(it);
                return;
            }
        }

    }

    throw runtime_error("something very wrong happened while trying to remove Key " + key); // something very wrong happened!!
}

void hash_table::print_table()
{
    using std::cout;
    using std::endl;

    for(uint i=0; i<this->buckets.size(); i++){

        if(this->buckets[i].size() != 0){

            cout << "Bucket " << i << ":\n";

            for(auto const &curr_pair : this->buckets[i]){
                cout << "key: " << curr_pair.first << " value: " << curr_pair.second << "\n";
            }
            cout << endl;
        }

    }
}

int hash_table::get_bucket(string key)
{
    return hash_function(string_to_int(key));
}

int hash_table::string_to_int(string key)
{
    int res = 0;

    for(char c : key){
        res+=int(c);
    }

    return res;
}

int hash_table::hash_function(int value)
{
    return value % this->bucket_size;
}
