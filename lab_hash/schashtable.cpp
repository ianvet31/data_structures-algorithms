/**
 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 */

#include "schashtable.h"
using hashes::hash;
using hashes::secondary_hash;
using std::pair;
using std::list;
 
template <class K, class V>
SCHashTable<K, V>::SCHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new std::list<std::pair<K, V>>[size];
    elems = 0;
}

template <class K, class V>
SCHashTable<K, V>::~SCHashTable()
{
    delete[] table;
}

template <class K, class V>
SCHashTable<K, V> const& SCHashTable<K, V>::
operator=(SCHashTable<K, V> const& rhs)
{
    if (this != &rhs) {
        delete[] table;
        table = new std::list<std::pair<K, V>>[rhs.size];
        for (size_t i = 0; i < rhs.size; i++)
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K, V>::SCHashTable(SCHashTable<K, V> const& other)
{
    table = new std::list<std::pair<K, V>>[other.size];
    for (size_t i = 0; i < other.size; i++)
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     */
    elems += 1;

     if (shouldResize()) {
         resizeTable();
     }


     size_t index = hash(key, size);

     pair<K, V> p(key, value);

     table[index].push_front(p);
}

template <class K, class V>
void SCHashTable<K, V>::remove(K const& key)
{
    typename std::list<std::pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the lab spec about list iterators and the
     * erase() function on std::list!
     */
    //(void) key; // prevent warnings... When you implement this function, remove this line.
    size_t index = hash(key, size);

     for (it = table[index].begin(); it != table[index].end(); it++) {

       if (it->first == key) {

         table[index].erase(it);

         break;
       }

     }
}

template <class K, class V>
V SCHashTable<K, V>::find(K const& key) const
{

    /**
     * @todo: Implement this function.
     */

    size_t index = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++) {
        if (it->first == key)
            return it->second;
    }
    return V();
}

template <class K, class V>
V& SCHashTable<K, V>::operator[](K const& key)
{
    size_t index = hashes::hash(key, size);
    typename std::list<std::pair<K, V>>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++) {
        if (it->first == key)
            return it->second;
    }

    ++elems;
    if (shouldResize()) {
        resizeTable();
    }
   

    index = hashes::hash(key, size);

    std::pair<K, V> p(key, V());

    table[index].push_front(p);

    return table[index].front().second;
}

template <class K, class V>
bool SCHashTable<K, V>::keyExists(K const& key) const
{
    size_t idx = hashes::hash(key, size);
    typename std::list<std::pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K, V>::clear()
{
    delete[] table;
    table = new std::list<std::pair<K, V>>[17];
    size = 17;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K, V>::resizeTable()
{
    typename std::list<std::pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the spec about list iterators!
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
    size_t prime = findPrime(size * 2);


    std::list<std::pair<K, V>>* newTable = new list<pair<K, V>>[prime];

    for (size_t i = 0; i < size; i++) {
      for (it = table[i].begin(); it != table[i].end(); it++) {

        size_t index = hash(it->first, prime);
        pair<K, V> p(it->first, it->second);
        newTable[index].push_front(p);
      }
    }
    size = prime;
    delete[] table;
    table = newTable;
}
