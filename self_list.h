#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;
        int nodes;

    public:
        SelfList(Method method) : head(nullptr) {};

        bool insert(T data) {
            auto *nuevo = new Node<T>(data);
            Node<T> **temporal;

            nuevo->next = *temporal;
            *temporal = nuevo;
            ++this -> nodes;
            return true;
        }
             
        bool remove(T data) {
            Node<T> **temporal;
            if (find(data)!=find(temporal)){
                return false;
            }
            auto *newNode = *temporal;
            *temporal = (*temporal)->next;
            --this->nodes;
            delete newNode;
            return true;
        }  

        bool find(T data) {
            // TODO
        }

        T operator [] (int index) {
            Node<T> *temporal = head;
            for (int i = 0; i != index; i++)
                temporal = temporal->next;
            return temporal->data ;
        }
             
        int size() {
            //Cuidado con actualizar bien la variable nodes
            return this->nodes;
        }

        void print() {
            // TODO
        }

        ~SelfList() {
            head->killSelf();
        }  
};

#endif