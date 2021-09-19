#include <iostream>
using namespace std;

namespace ns2 {
    template <class T>
    void swap(T& x, T& y){
        T temp = x;
        x = y;
        y = temp;
    }
}

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

            void reset(int index = 0, int cap = 1){
                delete [] data;
                data = NULL;
                this->index = index;
                this->cap = cap;
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

            T* begin()const{
                return data;
            }

            T* end()const{
                return data + size();
            }

            T& at(int indices){
                if(indices >= 0 && indices < size()){
                    return data[indices];
                }
                throw "Error : Vector indices overflow.";
            }

            T& operator[](int indices){

                return at(indices);
            }

            void clear(){
                reset();
                data = new T[cap];
            }

            void insert(const T* pos, const T& value){
                if (begin() <= pos && pos <= end()){
                    int index = pos - begin();
                    push_back(value);
                    for(int i = size() - 1; i > index; i--){
                        ns2::swap(data[i],data[i - 1]);
                        /*Example:
                            1 2 3
                            1 2 3 0
                            1 2 0 3
                            1 0 2 3
                            0 1 2 3 --> Complete.*/
                    }
                }
                else
                    throw "Error : Vector instert";
            }

    };   
}

int main(){
    ns::vector<int> obj;
    
    try{
        /*obj.push_back(34);
        obj.push_back(32);
        obj.push_back(35);
        obj.push_back(44);
        obj.push_back(55);

        cout << "size: " << obj.size() << endl;
        cout << "capacity: " << obj.capacity() << endl;

        int* begin = obj.begin();
        int* end = obj.end();

        cout << "begin : " << begin << endl;
        cout << "end : " << end << endl;

        while(begin != end){
            cout << *begin << endl;
            begin++;
        }

        cout << "1. indices: " << obj[1] << endl;

        obj.clear();

        cout << "size: " << obj.size() << endl;
        cout << "capacity: " << obj.capacity() << endl;*/

        obj.push_back(1);
        obj.push_back(3);
        obj.push_back(5);
        obj.insert(&obj[1],2);
        int *begin = obj.begin();
        int *end = obj.end();

        while(begin != end){
            cout << *begin << " ";
            begin++;
        }

   
    }catch(const char* exception){
        cout << exception;
    }
    
    return 0;
}