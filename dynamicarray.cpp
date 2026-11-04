// dynamicarray.cpp
// This file is part of the C++17 project.
// 동적 배열에 대해 구현해본 연습 목적의 코드
//push_back, pop_back, size, capacity, reserve, resize 구현 해보기

#include <iostream>
#include <memory>

template <typename T, typename Alloc = std::allocator<T>>
class DynamicArray {
    private:
        using Traits = std::allocator_traits<Alloc>;
        Alloc _alloc;

        T* _data = nullptr;
        std::size_t _size;
        std::size_t _capacity;
        T init_value = T{};

    public:
        DynamicArray(std::size_t initial_size){
            _size = initial_size;
            _capacity = initial_size;
            _data = Traits::allocate(_alloc, _capacity);

            for(std::size_t i = 0; i < _size; i++){
                Traits::construct(_alloc, _data + i, init_value);
            }
        }

        ~DynamicArray() {
            for(std::size_t i = 0; i < _size; i++){
                Traits::destroy(_alloc, _data + i);
            }
            if(_data != nullptr){
                Traits::deallocate(_alloc, _data, _capacity);
            }
        }

        std::size_t size() {
            return _size;
        }

        void resize(std::size_t new_size){
            
        }

        std::size_t capacity(){
            return _capacity;
        }

        bool empty(){
            return _size == 0;
        }

        void reserve(std::size_t new_capacity){
            if(_capacity >= new_capacity){
                return;
            }
            
            // size만큼 기본 애들은 새로 할당한 곳에 이동
            // 기존 data들 제거 및 할당한 것 풀기

            T* new_data = Traits::allocate(_alloc, new_capacity);

            for(std::size_t i = 0; i < _size; i++){
                Traits::construct(_alloc, new_data + i, _data[i]);
            }

            for(std::size_t i = 0; i < _size; i++){
                Traits::destroy(_alloc, _data + i);
            }
            if(_data != nullptr){
                Traits::deallocate(_alloc, _data, _capacity);
            }

            _data = new_data;
            _capacity = new_capacity;
        }

        T& at(std::size_t index){
            return _data[index];
        }

        T& operator[](std::size_t index){
            return _data[index];
        }

        T& front(){
            return _data[0];
        }

        T& back(){
            return _data[_size - 1];
        }

        void push_back(T item){
            if(_size >= _capacity){
                // 용량 늘리기
            }
            Traits::construct(_alloc, _data + _size++, item);
        }

        void pop_back(){
            if(_size > 0){
                Traits::destroy(_alloc, _data + --_size);
            }
        }



    
};

int main() {
    
    
    
    return 0;
}