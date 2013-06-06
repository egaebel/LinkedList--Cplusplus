#ifndef ITERATOR_H_
#define ITERATOR_H_

/*
 * Iterator abstraction for a List. Only iterates "forward".
 *
 *     Author: egaebel
 */
template<class T>
class Iterator {

    public:
        //~Constructors/Destructors------------//
        /*
         * Destroys necessary resources.
         */
        virtual ~Iterator() {};

        //~Methods-------------------//
        /*
         * Informs the user whether there are more elements to be iterated
         * over in a List.
         *
         * @return true if there are more elements to iterate over, false otherwise.
         */
        virtual bool hasNext() = 0;

        /*
         * Gets the next element to iterate over.
         *
         * @return the next element in the iteration.
         */
        virtual T * next() = 0;

        /*
         * Adds an element to the List being iterated over.
         *
         * @param element the element to add.
         * @return true if successful, false otherwise.
         */
        virtual bool add(const T & element) = 0;

        /*
         * Removes the element last returned by next from
         * the List being iterated over.
         *
         * @return true if successful, false otherwise.
         */
        virtual bool remove() = 0;
};

#endif /* Iterator */
