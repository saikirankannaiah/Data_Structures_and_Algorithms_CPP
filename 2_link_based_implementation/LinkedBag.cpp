#include "LinkedBag.h"

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{

}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // 1. Add to the beginning of the chain and new node references the next
    Node<ItemType>* newNodePtr = new Node<ItemType>;
    // 2. Set the new node to the new entry
    newNodePtr->setItem(newEntry);
    // 3. Set the new node next to the headptr
    newNodePtr->setNext(headPtr);
    // 4. Set the headptr to the new node ptr
    headPtr = newNodePtr;
    // 5. Increment the item count
    itemCount++;

    return true;
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
    vector<ItemType> items;
    Node<ItemType> currentPtr = headPtr;
    while(currentPtr != nullptr)
    {
        items.push_back(currentPtr->getItem());
        currentPtr = currentPtr->getNext();
    }

    return items;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    Node<ItemType>* currentPtr = headPtr;
    int count = 0;

    while(currentPtr != nullptr)
    {
        if(currentPtr->getItem() == anEntry)
            count++;
        currentPtr = currentPtr->getNext();  
    }
    return count;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
    Node<ItemType>* currentPtr = headPtr;
    bool found = false;
    while(!found && currentPtr != nullptr)
    {
        if(currentPtr->getItem() == target)
            found = true;
        else
            currentPtr = currentPtr->getNext();
    }

    return currentPtr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getPointerTo(anEntry) != nullptr;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* currentPtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (currentPtr != nullptr);

    if(canRemoveItem)
    {   
        // 1. Copy data from the first node to the located node
        currentPtr->setItem(headPtr->getItem());
        // 2. Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        // 3. Freeing the memory
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
    Node<ItemType>* currentPtr = headPtr;
    while(currentPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        currentPtr->setNext(nullptr);
        delete currentPtr;
        currentPtr = headPtr;
    }

    itemCount = 0;
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
    clear();
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
    itemCount = aBag->getCurrentSize();
    Node<ItemType>* currentPtr = aBag->headPtr;

    if(currentPtr == nullptr)
        headPtr = nullptr;
    else
    {
        // Since head pointer must always point to the head
        // copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(currentPtr->getItem());

        // copy the remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        while(currentPtr != nullptr)
        {
            currentPtr = currentPtr->getNext();

            //Get the item
            ItemType nextItem = currentPtr->getItem();

            // Create a new node ptr
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node pointer to the new chain ptr
            newChainPtr->setNext(newNodePtr);

            //Advance the chain ptr
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}
