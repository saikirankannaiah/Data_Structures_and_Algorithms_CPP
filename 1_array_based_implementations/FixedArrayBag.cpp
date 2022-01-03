#include "FixedArrayBag.h"
#include <string>

/*
Constructor with normal assignment operator
template<class ItemType>
FixedArrayBag<ItemType>::FixedArrayBag()
{
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
}
*/

// Constructor with Initializer list
template<class ItemType>
FixedArrayBag<ItemType>::FixedArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{

}

template<class ItemType>
bool FixedArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }

    return hasRoomToAdd;
}

template<class ItemType>
std::vector<ItemType> FixedArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for(int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);
    return bagContents;
}

template<class ItemType>
int FixedArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<class ItemType>
bool FixedArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool FixedArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    return false; // STUB
}

template<class ItemType>
void FixedArrayBag<ItemType>::clear()
{
    // STUB
}

template<class ItemType>
int FixedArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry)
{
    return 0; // STUB
}

template class FixedArrayBag<std::string>;