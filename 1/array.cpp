template <typename T>
struct array {
    T* data;
    int size;
    array(int size) : size(size) {
        data = new T[size];
    }
    T& operator[](int i) {
        return data[i];
    }
    ~array() {
        delete[] data;
    }
    
};


array<int> a(10);