#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"
#include <iostream>
using namespace std;

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
            auto *nuevo = *temporal;
            *temporal = (*temporal)->next;
            --this->nodes;
            delete nuevo;
            return true;
        }  

        bool find(T data) {
            switch (this->method) {
                case Transpose: {

                }
                case Move: {
                    auto *temporal = head;

                    if(head->data==data) {
                        return true;
                    }

                    if(temporal==nullptr){
                        return false;
                    }

                    if (nodes > 1) {
                        while (temporal->next!=nullptr) {
                            if (temporal->next->data==data) {
                                break;
                            }
                            temporal=temporal->next;
                        }
                        auto *nuevo=temporal->next;
                        nuevo->next=head;
                        head=nuevo;
                        return true;
                    }
                }

                case Count: {

                }
                }
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
            if(head!= nullptr) {
                auto *temporal = head;
                while (temporal != nullptr) {
                    cout << temporal->data << " ";
                    temporal = temporal->next;
                }
            }
        }

        ~SelfList() {
            head->killSelf();
        }  
};

#endif