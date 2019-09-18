#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"
#include <iostream>
using namespace std;

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        int nodes;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            pointer=&head;
            while(*pointer!=nullptr){
                if(!cmp(data, (*pointer)->data)){
                    //El & te permite posicionarte en la direccion que sacaste del *pointer->next
                    pointer=&((*pointer)->next);
                }
                else{
                    break;
                }
            }
            return *pointer != nullptr && (*pointer)->data == data;
        }
              
    public:
        TraitsList() : head(nullptr), nodes(0) {};
             
        bool insert(T data) {
            auto *nuevo = new Node<T>(data);
            Node<T> **temporal;
            if (find(data, temporal)){
                return false;
            }
            nuevo->next = *temporal;
            *temporal = nuevo;
            ++nodes;
            return true;
        }
             
        bool remove(T data) {
            Node<T> **temporal;
            if (!find(data, temporal)){
                return false;
            }
            auto *nuevo = *temporal;
            *temporal = (*temporal)->next;
            --nodes;
            delete nuevo;
            return true;
        }  

        //bool find(T data) {
        //    Node<T> **temporal;
        //    return find(data,temporal);
        //}

    T operator[](int index) {
        Node<T> *temporal = head;
        for (int i = 0; i != index; i++){
            temporal = temporal->next;
        }
        return temporal->data ;
        }

             
        int size() {
            return this->nodes;
        }

        void print() {
                auto *temporal = head;
                while (temporal!= nullptr) {
                    cout << temporal->data << " ";
                    temporal = temporal->next;
                }
            }

        ~TraitsList() {
            head->killSelf();
        }         
};

#endif