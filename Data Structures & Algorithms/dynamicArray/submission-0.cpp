class DynamicArray {
    int* data;
    int size;
    int capacity;
public:

    DynamicArray(int capacity) {
        if(capacity <=0){
            cout<<"Capacity must be greater than 0"<<endl;
        }
        this->capacity=capacity;
        this->size=0;
        this->data=new int[capacity];
    }
    ~DynamicArray(){
        delete[]data;
    }
    int get(int i) {
        if(i<0 || i>=size){
            cout<<"Index out of bounds"<<endl;
        }
        return data[i];
    }

    void set(int i, int n) {
        if(i<0 || i>=size){
            cout<<"Index out of bounds"<<endl;
        }
        data[i]=n;
    }

    void pushback(int n) {
        if(size==capacity){
            resize();
        }
        data[size]=n;
        size++;
    }

    int popback() {
        if(size==0){
            cout<<"Can not pop from empty array"<<endl;
        }
        size--;
        return data[size];
    }

    void resize() {
        int* newdata =new int[2*capacity];
        copy(data,data+size,newdata);
        delete[]data;
        data=newdata;
        capacity=2*capacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
