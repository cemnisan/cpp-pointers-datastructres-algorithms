#include <iostream>
using namespace std;

namespace ns{
    
    template<class T>
    class vector{
        T* data;
        int cap;
        int index;

            // dynamic growth
            void growth(){
                if(size() >= capacity()){
                    cap *= 2;
                    T* tmp = new T[cap];

                    for(int i=0; i < size(); i++ ){
                        tmp[i] = data[i];
                    }

                    delete[] data;
                    data = tmp;
                }
            }

            // dynamic shrink
            void shrink(){
                if (size() <= capacity() / 2){
                    cap /= 2;
                    T* tmp = new T[cap];

                    for(int i=0; i < size(); i++){
                        tmp[i] = data[i];
                    }

                    delete[] data;
                    data = tmp;
                }
            }

        public:
            vector() : data(NULL),index(0),cap(1){
                data = new T[cap];
            }

            int size()const{ return index; }
            int capacity()const{ return cap; }

            void push_back(const T& value){
                growth();
                data[index++] = value;

            }

            void pop_back(){
                if(isEmpty()){
                    throw "Error : Vector is empty.";
                }
        
                index--;
                shrink();
            }

            bool isEmpty()const{
                return size() == 0;
            }

            T front()const{
                if(isEmpty()){
                    throw "Error : Vector is empty.";
                }

                return data[0];
            }

            T back()const{
                if(isEmpty()){
                    throw "Error : Vector is empty.";
                }

                return data[index - 1];
            }
    };   
}

int main(){
    ns::vector<int> obj;

    try{
       
       obj.pop_back();

    }catch(const char* exception){
        cout << exception;
    }
    
    return 0;
}