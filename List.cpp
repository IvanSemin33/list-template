#include "List.h"
#include <iostream>
using namespace std;

template <class Type>
List<Type>::List() : Head(NULL),Tail(NULL), count(0) {}

template <class Type>
List<Type>::List(const List &L) : Head(NULL),Tail(NULL), count(0){
    Node<Type>* temp = L.Head;
    while (temp!=0){
        add_tail(temp->Val);
        temp=temp->Next;
    }
}

template <class Type>
void List<Type>::add_head(Type n) {
    Node<Type>* temp = new Node<Type>;
    temp->Prev=0;
    temp->Val = n;
    temp->Next = Head;
    if (Head!=0)
        Head->Prev = temp;
    if (count==0)
        Head=Tail=temp;
    else
        Head=temp;
    count++;
}

template <class Type>
void List<Type>::add_tail(Type n) {
    Node<Type>* temp =new Node<Type>;
    temp->Next = 0;
    temp->Val = n;
    temp->Prev = Tail;
    if (Tail!=0)
        Tail->Next = temp;
    if(count==0)
        Head=Tail=temp;
    else
        Tail=temp;
    count++;

}

template <class Type>
void List<Type>::insert(int pos) {
    if(pos==0)
    {
        cout<<"Input position: ";
        cin>>pos;
    }
    if (pos==count+1){
        Type data;
        cout << "Input new number: ";
        cin >> data;
        add_tail(data);
        return;
    }
    else if(pos==1){
        Type data;
        cout << "Input new number: ";
        cin >> data;
        add_head(data);
        return;
    }
    int i=1;
    Node<Type>* Ins=Head;
    while (i<pos){
        Ins=Ins->Next;
        i++;
    }
    Node<Type>* PrevIns = Ins->Prev;
    Node<Type>* temp = new Node<Type>;
    cout << "Input new number: ";
    cin >> temp->data;

    if(PrevIns != 0 && count != 1)
        PrevIns->Next = temp;

    temp->Next = Ins;
    temp->Prev = PrevIns;
    Ins->Prev = temp;

    count++;
}

template <class Type>
void List<Type>::show() {
    if (count != 0) {
        cout << "( ";
        Node<Type> *temp = Head;
        while (temp->Next != 0) {
            cout << temp->Val << ", ";
            temp = temp->Next;
        }
        cout << temp->Val << " )\n";
    }
}

template <class Type>
int List<Type>::get_count() {
    return count;
}