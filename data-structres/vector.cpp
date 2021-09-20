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

            ~vector() { reset(); }

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
                        /* 

                        data[3] = 0
                        data[2] = 5
                        
                        data[2] = 0
                        data[1] = 3 

                        Example: 
                            obj.insert(obj[1],0):
                                1 3 5 0
                                1 3 0 5
                                1 0 3 5 --> Complete.
                        */
                    }
                }
                else
                    throw "Error : Vector instert";
            }

            void insert(const T* pos, int n, const T& value){
                int index = pos - begin();
                for (int i=0; i < n; i++){
                    insert(begin() + index + i, value);
                }
            }

            void insert(const T* pos, const T* first, const T* last){
                int index = pos - begin();

                while(first != last){
                    insert(begin() + index++, *first++);
                }
            }

            void erase(const T* pos){
                if(begin() <= pos && pos <= end()){
                    int index = pos - begin(); // pointer arithmetic

                    for(int i = index ; i < size(); i++)
                        data[i] = data[i + 1]; 
                    pop_back();
                }
                else
                    throw "Error : Vector erase";
            }

            void erase(const T* first, const T* last){
                if(first == begin() && last == end()){
                    clear();
                }else{
                    int f = first - begin();
                    int l = last - begin();

                    while (f != l ){
                        erase(f + begin());
                        l--;
                    }
                }
            }
    };   
}

int main(){
    int * begin;
    int * end;

    {
        ns::vector<int> obj;
        obj.push_back(3);
        obj.push_back(5);
        obj.push_back(6);
        obj.push_back(8);
        obj.push_back(9);

        begin = obj.begin();
        end = obj.end();

    }

    while(begin != end){
        cout << *begin << " ";
        begin++;
    }

    return 0;
}