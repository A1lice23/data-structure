// dynamicarray.cpp
// This file is part of the C++17 project.
// 동적 배열에 대해 구현해본 연습 목적의 코드
//push_back, pop_back, size, capacity, reserve, resize 구현 해보기

#include <iostream>

class DynamicArray {
    private:
        int* data;
        int _size;
        int _capacity;

    public:
        DynamicArray(int initial_size){
            _size = initial_size;
            data = new int[_size]; 
        }

        ~DynamicArray() {
            delete[] data;
        }

        int size() {
            return _size;
        }

        int capacity(){
            return _capacity;
        }

        bool empty(){
            return true;
        }

        int& at(int index){
            
        }





    
};

int main() {
    
    
    
    return 0;
}