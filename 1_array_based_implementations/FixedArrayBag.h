#ifndef _Array_Bag_
#define _Array_Bag_

//#include "BagInterface.h"
#include <vector>

template<class ItemType>
class FixedArrayBag
{
    private:
    static const int DEFAULT_CAPACITY = 6;
    ItemType items[DEFAULT_CAPACITY];
    int itemCount, maxItems; // Current count of bag items, Max capacity of the bag

    // Returns either the index of the element in the array items that 
    // contains the given target or -1, if the array does not contain 
    // the target

    int getIndexOf(const ItemType& target) const;

    public:
    FixedArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry);
    std::vector<ItemType> toVector() const;

};

#endif