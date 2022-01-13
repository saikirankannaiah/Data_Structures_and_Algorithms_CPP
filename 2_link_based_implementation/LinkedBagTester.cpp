#include <iostream>
#include <string>
#include "LinkedBag.h"

using std::cout;
using std::endl;
using std::string;


void displayBag(const LinkedBag<string>* bag)
{
    std::cout << "The bag contains " << bag->getCurrentSize() << " items."<< std::endl;
    std::vector<string> bagItems = bag->toVector();

    for(int i = 0; i < bagItems.size(); i++)
        std::cout << bagItems[i] << "  ";
    std::cout << std::endl << std::endl;
}


void bagTester(LinkedBag<string>* bag) {
cout << "isEmpty: returns " << bag->isEmpty() << "; should be 1 (true)" << endl; 
displayBag(bag);
string items[] = {"one", "two", "three", "four", "five", "one"}; 
cout << "Add 6 items to the bag: " << endl; 
for ( int i = 0; i < 6; i++) 
{
bag->add(items[i]);
} // end for displayBag(bag);
cout << "isEmpty: returns " << bag->isEmpty() << "; should be 0 (false)" << endl;
cout << "getCurrentSize: returns " << bag->getCurrentSize() << "; should be 6" << endl;
cout << "Try to add another entry: add(\"extra\") returns " << bag->add("extra") << endl;
} // end bagTester


int main() {
LinkedBag<string>* bagPtr = new LinkedBag<string>();
cout << "Testing the LinkedList-Based Bag:" << endl; cout << "The initial bag is empty." << endl; 
bagTester(bagPtr);
delete bagPtr;
bagPtr = nullptr;
cout << "All done!" << endl; return 0;
} // end main