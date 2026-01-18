// #pragma once
// #include <iostream>

// //declerations
// namespace final
// {
//     /**************************
//     Decleration for Node Class
//     *************************/
//     template <typename T>
//     class Node
//     {
         
//         public:
//         //properties
//             T data;
//             Node<T> *next; // = T because unknow var type
        
//             //constructor 
//             Node() : data(NULL), next(NULL){};
//             Node(T x) : data(x), next(NULL){};

//             //setters
//             void setData(T data);
//             void setNext(Node<T> *next);

//             //getters
//             T getData();
//             Node<T> getNext();
//     };

//     /********************************
//     Decleration for LinkedList Class
//     ********************************/

//     template <typename T>
//     class LinkedList // head, tail, & size
//     {
//         public:

//         //properties
//         // = T because know var type
//         final::Node<T> *head; 
//         final::Node<T> *tail;
//         int size;

//         //constructors
//         LinkedList() : head(NULL), tail(NULL), size(0){};

//         //function
//         void addToList(T data);
//         void printLinkedList();
//     };
// }

// /*****************************
// Implementation for Node Class
// *****************************/

// //setters for node class
// template <typename T>
// void final::Node<T>::setData(T data)
// {
//     this->data = data;
// }

// template <typename T>
// void final::Node<T>::setNext(Node<T> *next)
// {
//     this->next = next;
// }

// //getters for node class
// template <typename T>
// T final::Node<T>::getData()
// {
//     return this->data;
// }
// template <typename T>
// final::Node<T> final::Node<T>::getNext()
// {
//     return this->next();
// }

// /***********************************
// Implementation for Linked List Class
// ************************************/

// template <typename T>
// void final::LinkedList<T>::addToList(T data)
// {
//             final::Node<T> *newNode = new Node<T>(data);

//             //list empty
//             if (size == 0)
//             {
//                 this->head = newNode;
//                 this->tail = newNode;
//                 this->head->next = tail;
//                 this->size++;
//             }

//             //list !empty
//             else
//             {
//                 this->tail->next = newNode;
//                 this->tail = newNode;
//             }
// }

// template <typename T>
// void final::LinkedList<T>::printLinkedList()
// {
//     final::Node<T> *traverseNode = this->head;

//     while (traverseNode != NULL)
//     {
//         std::cout << traverseNode->data << std::endl;
//         traverseNode = traverseNode->next;
//     }
// } 