#pragma once
#include"Lib.h"

const int DEFAULT_CAPACITY = 10;
const short DEFAULT_INCREASE = 2;

class DynamicArray {


private:

	int* _O_Array;
	int _O_Size;
	int _O_Capacity;
	void _Resize();
	int* _Copy( int*& OrigignalArray, int capacity,int size);

public:

	DynamicArray();
	DynamicArray(const DynamicArray& arr);
	DynamicArray( DynamicArray&& arr)noexcept;
	~DynamicArray();


	void Push(const int& value);
	void Pop();
	void Clear();
	void Reserve(int capacity);

	int Size()const;
	int Capacity()const;
	int At(int idx);
	int Front()const;
	int Back()const;

	const int& operator[](int idx)const;
	DynamicArray& operator=(const DynamicArray& arr);
	DynamicArray& operator=(DynamicArray&& arr)noexcept;





};