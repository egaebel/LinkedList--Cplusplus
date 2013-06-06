#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include "LinkedListIterator.h"
#include <sstream>

/*
 *
 * Implementation of a doubly linked list.
 *
 *     Author: egaebel
 */
template<class T>
class LinkedList {

    private:
        //Data Fields-----------------//
        /*
         * Number of elements in the LinkedList.
         */
        int size;

    public:

        //Data Fields--------------------//
        /*
         * The head of the list, sentinel node, empty.
         */
        Node<T> * head;
        /*
         * The tail end of the list, sentinel node, empty.
         */
        Node<T> * tail;

        //Constructors---------------//
        /*
         * Initializes head and tail sentinel nodes and
         * joins them together.
         */
        LinkedList() {

            head = new Node<T>();
            tail = new Node<T>();

            head->join(tail);

            size = 0;
        }

        /*
         * Initializes head and tail sentinel nodes as well
         * as another node for the passed element, and strings
         * them together.
         *
         * @param element the first data element in the list.
         */
        LinkedList (T element) {

            head = new Node<T>();
            tail = new Node<T>();
            Node<T>* temp = new Node<T>(element);
            head->split();
            head->join(temp);
            temp->join(tail);

            size = 1;
        }

        //Methods------------------//
        /*
         * Adds the passed in element to the front of the List.
         *
         * Runs in O(1) time.
         *
         * @param element the element to add.
         */
        void addFront(T element) {

            Node<T>* temp = head->next;
            Node<T>* newNode = new Node<T>(element);
            head->split();
            head->join(newNode);
            newNode->join(temp);

            size++;
        }

        /*
         * Adds the passed in element to the end of the List.
         *
         * Runs in O(1) time.
         *
         * @param element the element to add.
         */
        void addEnd(T element) {

            Node<T>* temp = tail->prev;
            Node<T>* newNode = new Node<T>(element);
            temp->split();
            temp->join(newNode);
            newNode->join(tail);

            size++;
        }

        /*
         * Removes the element at the passed in index from the List
         * and returns the piece of data that was contained in it.
         *
         * Note: For users, if elements in the LinkedList had space allocated
         * using new or malloc, you must delete the memory pointed to by the pointer
         * returned from this method. If you do not want a result, use removeIndexBoolReturn
         *
         * Runs in O(n) time where n is (index + 1).
         *
         * @param index The index of the element to remove.
         * @return the removed data element, or 0 if index was invalid.
         */
        T removeIndex(int index) {

            if (index < size && index >= 0) {

                Node<T>* temp = head;

                for (int i = 0; i <= index; i++) {

                    temp = temp->next;

                    if (i == index) {

                        Node<T>* removedNode = temp;
                        T removedData = removedNode->getData();

                        temp = temp->prev;
                        temp->join(temp->split()->split());

                        size--;

                        delete removedNode;

                        return removedData;
                    }
                }
            }

            return 0;
        }

        /*
         * Removes the node at the specified index from the LinkedList, and
         * returns true if index was valid, false otherwise.
         *
         * Runs in O(n) time where n is (index + 1).
         *
         * @param index the index of the Node to be removed.
         * @return true if the index is valid, false otherwise.
         */
        bool removeIndexBoolReturn(int index) {

            if (index < size && index >= 0) {

                Node<T>* temp = head;

                for (int i = 0; i <= index; i++) {

                    temp = temp->next;

                    if (i == index) {

                        Node<T>* removedNode = temp;
                        temp = temp->prev;
                        temp->join(temp->split()->split());

                        size--;

                        delete removedNode;

                        return true;
                    }
                }
            }

            return false;
        }

        /*
         * Removes the passed in element from the List. But only the first instance
         * of it found.
         *
         * If there are multiple elements with the value that must be
         * removed, use removeAllElements(T element).
         *
         * Runs in O(n) time in the worst case,
         * O(1) time in the best case, and
         * O(n/2) in the average case.
         *
         * @param element the element to remove.
         * @return true if the element was removed, false otherwise.
         */
        bool removeElement(T element) {

            //Loop through list until element is found,
                //or tail is reached.
            Node<T>* temp = head;
            while (temp->getData() != element
                    && temp != tail) {

                temp = temp->next;
            }

            //If loop reached end without finding a Node.
            if (temp == tail) {

                return false;
            }
            //Split off the node with element, and join the
                //surrounding Nodes.
            else {

                Node<T>* prevNode = temp->prev;
                prevNode->split();
                prevNode->join(temp->split());

                size--;
                delete temp;

                return true;
            }
        }

        /*
         * Takes in an element, and removes all instances of it from the list.
         * Returns true if at least one element was found, false otherwise.
         *
         * Runs in O(n) time in the worst case,
         * O(1) time in the best case, and
         * O(n/2) in the average case.
         *
         * @param element the element to remove instances of.
         * @return true if at least one element was found, false otherwise.
         */
        bool removeAllElements(T element) {

            bool value = false;

            Node<T>* temp = head;
            Node<T>* temp2;
            while (temp != tail) {

                temp = temp->next;

                //If a match was found, remove the Node.
                if (temp->getData() == element) {

                    temp2 = temp->next;
                    temp = temp->prev;
                    temp->split()->split();
                    temp->join(temp2);

                    value = true;
                    size--;
                }
            }

            return value;
        }

        /*
         * Removes the first element in the LinkedList.
         *
         * Runs in O(1) time.
         *
         * @return returns false if the list is empty, true otherwise.
         */
        bool removeFirst() {

            if (size > 0) {

                Node<T>* removed = head->next;
                head->join(head->split()->split());

                size--;

                delete removed;

                return true;
            }

            return false;
        }

        /*
         * Removes the last element in the LinkedList.
         *
         * Runs in O(1) time.
         *
         * @return returns false if the list is empty, true otherwise.
         */
        bool removeLast() {

            if (size > 0) {

                Node<T>* removed = tail->prev;
                Node<T>* newLast = removed->prev;
                newLast->join(newLast->split()->split());

                size--;

                delete removed;

                return true;
            }

            return false;
        }

        /*
         * Iterates through all elements in a linked list removing them.
         *
         * Runs in O(n) time, where n is the size of the list.
         */
        void removeAll(){

            if (size > 0) {

                Node<T>* temp = head;
                while (temp != tail) {

                    temp = temp->next;
                    temp->prev->split();
                    delete temp->prev;
                }
                head->join(tail);
                size = 0;
            }
        }

        /*
         * Getter for size field. The current size of this LinkedList.
         *
         * Runs in O(1) time.
         *
         * @return the size of this LinkedList.
         */
        int getSize() {

            return size;
        }

        /*
         * Increment the size of the LinkedList by one.
         * This is useful to provide the ability to increment list size
         * by 1 to an iterator, without allowing the size to be directly and
         * easily tampered with.
         */
        void incrementSize() {

            size++;
        }

        /*
         * Decrement the size of the LinkedList by one.
         * This is useful to provide the ability to decrement list size
         * by 1 to an iterator, without allowing the size to be directly,
         * and easily tampered with.
         *
         * @return true if successful (size was > 0 beforehand) and false if it is not (size <= 0).
         */
        bool decrementSize() {

            if (size > 0) {
                size--;
                return true;
            }
            else {
                return false;
            }
        }

        /*
         * Returns a string representation of the entire list, each element
         * is printed.
         *
         * Runs in O(n) time where n is the size of the list.
         *
         * @return string representation of the list.
         */
        std::string toString() {

            std::ostringstream returnString;

            if (size > 0) {
                Node<T>* temp = head->next;

                returnString << "{";
                while (temp != tail) {

                    //If the next element is tail.
                    if (temp->next == tail) {

                        //Omit the comma.
                        returnString << temp->getData();
                    }
                    else {

                        returnString << temp->getData() << ", ";
                    }

                    temp = temp->next;
                }
                returnString << "}";
            }
            else {

                returnString << "List is empty";
            }

            returnString << "\n";

            return returnString.str();
        }

        /*
         * Returns a pointer to an iterator for this LinkedList.
         *
         * NOTE: THE USER IS RESPONSIBLE FOR CALLING DELETE ON THIS ITERATOR OBJECT LATER!!
         *
         * @return iterator that iterates over this LinkedList.
         */
        Iterator<T>* getIterator() {

            Iterator<T>* it = new LinkedListIterator<T>(this);
            return it;
        }
};

#endif /* LINKEDLIST_H_ */
