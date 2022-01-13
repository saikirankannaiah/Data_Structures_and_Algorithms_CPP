#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "Node.h"
#include <vector>

using std::vector;

template<class ItemType>
class LinkedBag
{
    private:
    Node<ItemType>* headPtr;
    int itemCount;

    // Returns either a pointer to the node containing a given entry 
    // or the null pointer if the entry is not in the bag
    Node<ItemType>* getPointerTo(const ItemType& target) const;
    
    public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);
    virtual ~LinkedBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
};

#endif