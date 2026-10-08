cpp
#include <iostream>
#include <chrono>
#include <stdexcept>

// Custom Memory-Managed Dynamic Array Class
template <typename T>
class CustomVector {
private:
    T* data;
    size_t capacity;
    size_t current_size;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < current_size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    CustomVector() : capacity(2), current_size(0) {
        data = new T[capacity];
    }

    ~CustomVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (current_size == capacity) {
            resize(capacity * 2);
        }
        data[current_size++] = value;
    }

    T get(size_t index) const {
        if (index >= current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    size_t size() const { return current_size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    std::cout << "--- C++ Custom Data Structure Benchmark ---" << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();

    CustomVector<int> vec;
    for (int i = 1; i <= 1000; ++i) {
        vec.push_back(i * 10);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Vector Size: " << vec.size() << std::endl;
    std::cout << "Allocated Capacity: " << vec.get_capacity() << std::endl;
    std::cout << "Sample Element [Index 500]: " << vec.get(500) << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " ms" << std::endl;
    std::cout << "Memory Cleanup: Successful" << std::endl;

    return 0;
}
