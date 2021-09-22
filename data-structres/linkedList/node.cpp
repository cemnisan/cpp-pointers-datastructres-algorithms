#include <iostream>
using namespace std;


template <class T>
class Node{

    public:
        Node(const T& data = T(),Node<T>* next=NULL): data(data), next(next) { }
        T data;
        Node<T>* next;
};


int main(){

    Node<int>* n1 = new Node<int>(3);
    //cout << n1->data << endl;

    Node<int>* n2 = new Node<int>(5);
    n1->next = n2;
    //cout << n2-> data << endl;

    Node<int>* n3 = new Node<int>(10);
    n2->next = n3;
    //cout << n3->data << endl;

    /*cout << n1->data << " ";
    cout << n1->next->data << " ";
    cout << n1->next->next->data;*/

    Node<int>* tmp = n1;

    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
 

    return 0;
}