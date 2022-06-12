#pragma once
#include <iostream>

template <typename T, size_t N> 
class Array
{
public:
	Array() {}
	~Array();
	int size() const;
	void clear();
	const T& operator[] (int index) const;
	T& operator[] (int index);
	T& front() const;
	T& at(int index) const;
private:
	int size_arr = N;
	T* arr = new T[N];
};

template<typename T, size_t N>
inline Array<T, N>::~Array()
{
	delete[]arr;
}

template<typename T, size_t N>
inline int Array<T, N>::size() const
{
	return size_arr;
}

template<typename T, size_t N>
inline void Array<T, N>::clear()
{
	delete[]arr;
	arr = NULL;
}

template<typename T, size_t N>
inline const T& Array<T, N>::operator[](int index) const
{
	return *(arr + index);
}

template<typename T, size_t N>
inline T& Array<T, N>::operator[](int index)
{
	return *(arr + 5);
}

template<typename T, size_t N>
inline T& Array<T, N>::front() const
{
	return *arr;
}

template<typename T, size_t N>
inline T& Array<T, N>::at(int index) const
{
	return *(arr + index);
}
