/*
 * Node.h
 *
 * Node of a doubly LinkedList. Uses smart nodes approach of having
 * join and split methods instead of making the user do all of the work
 * in the list implementation.
 *
 *     Author: egaebel
 */
#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template<class T>
class Node {

    private:
        //Data Fields---------------//
        /*
         * The data that is stored in this Node.
         */
        T data;

    public:
        //Data Fields---------------//
        /*
         * The Node that comes before this one.
         */
        Node<T> * prev;
        /*
         * The Node that comes after this one.
         */
        Node<T> * next;

        //Constructors--------------//
        /*
         * Default constructor, initializes prev & next to null.
         */
        Node() {

            prev = 0;
            next = 0;
        }

        /*
         * Constructor for Node, takes in a piece of data, and sets
         * this nodes data to it. Also initializes prev & next to null.
         *
         * @param data the data to set this data to.
         */
        Node(T newData) {

            data = newData;
            prev = 0;
            next = 0;
        }

        //Destructors---------------//
        /*
         * Empty destructor.
         */
        ~Node() {

        }

        //Methods-------------------//
        /*
         * Joins this node to the passed node.
         *
         * @param newNext the node to join to this one.
         * @return this node, for chaining.
         */
        Node<T>* join(Node<T>* newNext) {

            //If nextNode is non-existent.
            if (next == 0) {

                //Set nextNode to newNext, and newNext's
                //previousNode to this.
                next = newNext;
                newNext->prev = this;
            }

            return this;
        }

        /*
         * Splits this node's next node off from this one.
         *
         * @return the old next node that is disconnected,
         *          or null if the next node is null.
         */
        Node<T>* split() {

            //If next is not null.
            if (next != 0) {

                //Nullify next's prev, and this' next.
                Node<T>* oldNext = next;
                next->prev = 0;
                next = 0;

                return oldNext;
            }

            //Otherwise return null.
            return 0;
        }

        /*
         * Setter for the data of this node.
         *
         * @param newData the thing to set data to.
         */
        void setData(T newData) {

            data = newData;
        }

        /*
         * Getter for the data of this node.
         *
         * @return data stored in this node.
         */
        T & getData() {

            return data;
        }

        /*
         * Getter for the next Node object.
         *
         * @return next, the Node that comes after this one.
         */
        Node<T> * getNext() {

            return next;
        }

        /*
         * Getter for the prev Node object.
         *
         * @return prev, the Node that comes before this one.
         */
        Node<T> * getPrevious() {

            return prev;
        }

        //Operators-------------------//
        /*
         * Overriden == operator. Two Node objects are
         * equal if they contain the same data, and are
         * surrounded by the same nodes.
         *
         * This last fact makes the == operator makes it only useful
         * for comparing Nodes that are both in a list,
         * or are both NOT in a list.
         *
         * @param node the node to check against this one for equality.
         * @return true if the two Nodes are equal, false otherwise.
         */
        bool operator == (const Node & node) const {

            //If the data is equal.
            if (node->getData() == data) {

                //If the adjacent nodes have the same addresses.
                if ((node->next) == next
                    && (node->prev) == prev) {

                    return true;
                }
            }

            return false;
        }

        /*
         * Overriden != operator. Two node objects are
         * found not to be equal if they do not contain the
         * same data, or if they are not surrounded by the
         * same nodes.
         *
         * This last fact about the != operator makes it only useful
         * for comparing Nodes that are both in a list, or are both
         * NOT in a list.
         *
         * @param node the node that is being compared with this one.
         * @return true if this node does not equal the passed one, false if they ARE equal.
         */
        bool operator != (const Node & node) const {

            //If the data is equal.
            if (node->getData() == data) {

                //If the adjacent nodes have the same addresses.
                if ((node->next) == next
                    || (node->prev) == prev) {

                    return false;
                }
            }

            return true;
        }
};

#endif /* NODE_H_ */
