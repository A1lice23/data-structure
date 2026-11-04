// dynamicarray.cpp
// This file is part of the C++17 project.
// 동적 배열에 대해 구현해본 연습 목적의 코드
//push_back, pop_back, size, capacity, reserve, resize 구현 해보기

#include <iostream>

class DynamicArray {
    private:
        int* data = nullptr;
        int _size;
        int _capacity;

    public:
        DynamicArray(int initial_size){
            _size = initial_size;
            _capacity = initial_size;
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
            return data[index];
        }

        int& operator[](int index){
            return data[index];
        }

        int& front(){
            return data[0];
        }

        int& back(){
            return data[_size - 1];
        }

        void push_back(int item){
            if(++_size >= _capacity){
                //capacity 늘리기
            }
            data[_size - 1] = item; 
        }

        void pop_back(){
            _size--;
        }



    
};

int main() {
    
    
    
    return 0;
}