
#include "LinkedList.h"
#include <iostream>

/*
 * Test harness for LinkedList. Tests all functions, and has
 * verbose output to show results of functions on the LinkedList.
 *
 * @return 0
 */
int main () {

    using namespace std;

    cout << "Creating new LinkedList, list, with no elements\n";
    LinkedList<int> list;
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing the first element\n";
    bool theResult = list.removeFirst();
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing the last element\n";
    theResult = list.removeLast();
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 5 to the end of the list\n";
    list.addEnd(5);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 13 to the front of the list\n";
    list.addFront(13);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 27 to the end of the list\n";
    list.addEnd(27);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 54 to the end of the list\n";
    list.addEnd(54);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 1394 to the front of the list\n";
    list.addFront(1394);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 23 to the front of the list\n";
    list.addFront(23);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 16 to the front of the list\n";
    list.addFront(16);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 32 to the front of the list\n";
    list.addFront(32);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 29 to the front of the list\n";
    list.addFront(29);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 22 to the front of the list\n";
    list.addFront(22);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding -37 to the front of the list\n";
    list.addFront(-37);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding -24 to the front of the list\n";
    list.addFront(-24);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index 5 from the list\n";
    int result = list.removeIndex(5);
    cout << "Size is: " << list.getSize() << endl;
    cout << "Index 5 held: " << result << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index 1382 from the list (will fail)\n";
    result = list.removeIndex(1382);
    cout << "Size is: " << list.getSize() << endl;
    cout << "Index 5 held: " << result << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index -1 from the list (will fail)\n";
    result = list.removeIndex(-1);
    cout << "Size is: " << list.getSize() << endl;
    cout << "Index 5 held: " << result << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index 5 from the list, using removeIndexBoolReturn\n";
    theResult = list.removeIndexBoolReturn(5);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index 1382 from the list, using removeIndexBoolReturn (will fail)\n";
    theResult = list.removeIndexBoolReturn(1382);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing index -1 from the list, using removeIndexBoolReturn (will fail)\n";
    theResult = list.removeIndexBoolReturn(-1);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing the first element\n";
    theResult = list.removeFirst();
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing the last element\n";
    theResult = list.removeLast();
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing element 12999 (will fail)\n";
    theResult = list.removeElement(12999);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing element 22\n";
    theResult = list.removeElement(22);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing element -37\n";
    theResult = list.removeElement(-37);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing element 54\n";
    theResult = list.removeElement(54);
    cout << "Size is: " << list.getSize() << endl;
    cout << "theResult was: " << theResult << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing all elements\n";
    list.removeAll();
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing all elements\n";
    list.removeAll();
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 7 to the end of the list\n";
    list.addEnd(7);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Adding 9 to the end of the list\n";
    list.addEnd(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Removing all nodes holding the element '9' from the list\n";
    list.removeAllElements(9);
    cout << "Size is: " << list.getSize() << endl;
    cout << "list holds: " << list.toString() << endl;

    cout << "Creating new LinkedList, list2, with seed element 57\n";
    LinkedList<int> list2 = LinkedList<int>(57);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 1 to the front of list2\n";
    list2.addFront(1);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 3 to the front of list2\n";
    list2.addFront(3);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 5 to the front of list2\n";
    list2.addFront(5);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 12 to the front of list2\n";
    list2.addFront(12);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 17 to the front of list2\n";
    list2.addFront(17);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 19 to the front of list2\n";
    list2.addFront(19);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 122 to the front of list2\n";
    list2.addFront(122);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 144 to the front of list2\n";
    list2.addFront(144);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    cout << "Adding 1 to the front of list2\n";
    list2.addFront(155);
    cout << "Size is: " << list2.getSize() << endl;
    cout << "list2 holds: " << list2.toString() << endl;

    //Iteration testing
    cout << "**************************TESTING GENERAL ITERATION**************************\n";
    cout << "Getting iterator for list2\n";
    Iterator<int>* it = list2.getIterator();
    cout << "Preparing to iterate over list2...\n";

    int curVal;
    ostringstream os;
    os << "{";
    while (it->hasNext()) {

        curVal = it->next();
        cout << "curVal holds: " << curVal << endl;
        os << curVal << ", \n";
    }
    os << "}\n";
    cout << "All of the elements iterated over were:\n" << os.str() << endl;
    delete it;

    //Remove operations testing
    cout << "**************************TESTING REMOVAL DURING ITERATION**************************\n";
    cout << "Getting ANOTHER iterator for list2\n";
    it = list2.getIterator();
    cout << "Preparing to iterate over list2...\n";

    int beforeListSize = list2.getSize();
    int beforeList[beforeListSize];
    int removedList[beforeListSize];
    //clear int lists to 0
    for (int i = 0; i < beforeListSize; i++) {
        beforeList[i] = -9999999;
        removedList[i] = -9999999;
    }

    os.clear();
    os << "{";
    for (int i = 0; it->hasNext(); i++) {

        curVal = it->next();
        cout << "curVal holds: " << curVal << endl;
        beforeList[i] = curVal;

        //Remove on odd iterations (just cus)
        if ((i % 2) == 1) {

            if (it->remove()) {
                cout << curVal << " was removed from the list!\n";
                removedList[i] = curVal;
            }
        }
        else {
            os << curVal << ", \n";
        }
    }
    os << "}\n";
    cout << "All of the elements iterated over were:\n" << os.str() << endl;
    delete it;

    cout << "Getting ANOTHER iterator for list2\n";
    it = list2.getIterator();

    cout << "Were the values removed correctly??\n";
    cout << "current list2 size: " << list2.getSize() << endl;
    cout << "old list2 size: " << beforeListSize << endl;
    cout << "Iterating and comparing\n\n";
    for (int i = 0; it->hasNext(); i++) {
        cout << "value removed from " << i << " was " << removedList[i] << endl;
        cout << "Cur val in list2 is: " << it->next() << endl;
        cout << "Cur val in OLD list2 was: " << beforeList[i] << endl;
    }

    delete it;

    cout << "**************************TESTING ADDITION DURING ITERATION**************************\n";
    //Add operations testing
    it = list2.getIterator();
    cout << "list2 holds the folliwng before iterating and adding: \n";
    cout << list2.toString();
    for (int i = 0; it->hasNext(); i++) {

        if (i == 0) {
            it->add(-11111111);
        }
        else if ((i % 2) == 0) {

            it->add(-77);
        }

        it->next();
    }
    it->add(-222222);

    cout << "list2 holds the following AFTER iterating and adding: \n";
    cout << list2.toString();

    cout << "Tests finished";
    return 0;
}
