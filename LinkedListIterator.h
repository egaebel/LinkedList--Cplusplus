#ifndef LINKEDLISTITERATOR_H_
#define LINKEDLISTITERATOR_H_

#include "Iterator.h"

template<class T>
class LinkedList;

 /*
 * Iterator for this LinkedList.
 *
 * All operations run in O(1) time.
 *
 * Provides functions:
 *     hasNext
 *     next
 *     add
 *     remove
 */
template<class T>
class LinkedListIterator : public Iterator<T> {

    private:
        //~Data Fields---------------------------------//
        /*
         * Pointer to the node that the iterator is currently at.
         */
        Node<T> * current;
        /*
         * Pointer to the LinkedList being iterated through.
         */
        LinkedList<T> * list;
        /*
         * Boolean value indicating whether next has been called since
         * the last remove operation.
         */
        bool nextCalled;

    public:
        //~Constructors/Destructors------------------//
        /*
         * Constructor for LinkedListIterator, takes in a pointer to a Node
         * to initialize current to point to (intended to be the head of the
         * the LinkedList).
         *
         * @param theList pointer to the LinkedList being iterated through.
         */
        LinkedListIterator(LinkedList<T>* theList) {

            current = theList->head;
            list = theList;
            nextCalled = false;
        }

        /*
         * Destructor, resets pointer values to 0.
         */
        ~LinkedListIterator() {

            current = 0;
            list = 0;
        }

        //~Methods-------------------------------------//
        /*
         * Checks to see if there are any elements left to be iterated
         * over. Returns true if there are, false otherwise.
         *
         * @return true if there are elements remaining to be iterated over,
         *           false otherwise.
         */
        bool hasNext() {

            if (current->next != list->tail) {

                return true;
            }

            return false;
        }

        /*
         * Returns the value of the element in the next node.
         *
         * If the iterator is pointing at the tail, returns 0.
         *
         * @return the value of the element in the next node. Or 0 if
         *          the end of the list has been reached.
         */
        T * next() {

            T * returnValue = NULL;

            if (current != list->tail) {

                current = current->next;

                //If the tail is now pointed to.
                if (current == list->tail) {

                    //nextCalled must be false so that remove doesn't try
                        //to remove the tail node
                    nextCalled = false;
                }
                //Otherwise.
                else {

                    T & temp = current->getData();
                    returnValue = &temp;
                    nextCalled = true;
                }
            }

            return returnValue;
        }

        /*
         * Adds the passed in element as the next node from the element the
         * iterator is currently pointing at. This alters the iterator's
         * current pointer to point to the Node that is added as a result
         * of this add call. This is done to avoid unnecessary iteration
         * over a just added member whose information is already held by
         * the user.
         *
         * NOTE: If the iterator is currently pointing to tail, this operation
         *          will not run. If you need to add to the end, you should use
         *          addEnd().
         *
         * @param element the element to add to the LinkedList.
         * @return true if the operation succeeded, false otherwise.
         */
        bool add(const T & element) {

            //If the iterator is not pointing at the tail node.
            if(current != list->tail) {

                Node<T> * newNode = new Node<T>(element);
                current->join(newNode->join(current->split()));

                //Move current to the newly inserted node so that
                    //on the next call to next() the node after the
                    //newly inserted one becomes the current target of
                    //the iterator.
                current = current->next;

                list->incrementSize();

                return true;
            }

            return false;
        }

        /*
         * Removes the node the iterator is currently at.
         *
         * NOTE: If next has not been called since remove was last called,
         *          this operation will fail, and return false.
         *          This avoids undesired behavior, such as calling remove
         *          until the head is reached, and removing it.
         *
         * @return true if successful, false otherwise.
         */
        bool remove() {

            bool value = false;

            if (nextCalled) {

                value = true;

                current = current->prev;
                current->join(current->split()->split());

                nextCalled = false;
                list->decrementSize();
            }

            return value;
        }
};



#endif /* LINKEDLISTITERATOR_H_ */
