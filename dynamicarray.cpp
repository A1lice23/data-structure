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
        // 생성자, 소멸자, operator= 
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

        // Capacity: size, max_size, resize, capacity, empty, reserve, shrink_to_fit

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

        // Element access: operator[], at, front, back, data

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

        // Modifiers: assign, push_back, pop_back, insert, erase, swap, clear, emplace, emplace_back

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

// new 대신 allocate를 사용한 이유 : 메모리 공간 확보와 객체 생성을 따로 조절해서 사용해야 하기 때문
// 새로운 메모리 할당 공간으로 기존 객체들을 옮길 때 복사나 이동을 사용. 복사하면 이동보다 비효율적일 때가 있고, 
// 복사 생성 중 예외 발생 시 기존 복사한 객체들의 소멸자가 호출되지 않아 할당된 메모리가 해제되지 않을 위험이 존재
// std::move()로 이동가능, int와 같이 소유한 자원이 없는 타입은 이동이나 복사나 같은 효과
// std::move_if_noexcept()와 같은 함수가 존재해서 상황에 따라 복사나 이동을 선택할 수 있음
