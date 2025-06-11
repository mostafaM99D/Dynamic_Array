#include"Lib.h"
#include"DynamicArray.h"
using namespace std;

int* DynamicArray::_Copy(int*& OrigignalArray, int capacity, int size) {
	if (OrigignalArray == nullptr)
		return nullptr;
	int* DesArray = new int[capacity];
	for (int i = 0; i < size; ++i)
		DesArray[i] = OrigignalArray[i];
	delete[]OrigignalArray;
	OrigignalArray = DesArray;
	return OrigignalArray;
}

DynamicArray::DynamicArray() {
	_O_Array = new int[DEFAULT_CAPACITY];
	_O_Size = 0;
	_O_Capacity = DEFAULT_CAPACITY;
}

DynamicArray::DynamicArray(const DynamicArray& arr) {
	_O_Size = arr.Size();
	_O_Capacity = arr.Capacity();
	_O_Array = new int[_O_Capacity];
	for (int i = 0; i < arr.Size(); ++i)
		_O_Array[i] = arr[i];
}

DynamicArray::DynamicArray(DynamicArray&& arr)noexcept {
	_O_Size = arr._O_Size;
	_O_Capacity = arr._O_Capacity;
	_O_Array = arr._O_Array;

	arr._O_Array = nullptr;
	arr._O_Size = 0;
	arr._O_Capacity = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
	if (this == &arr)
		return *this;

	delete[] _O_Array;
	_O_Size = arr._O_Size;
	_O_Capacity = arr._O_Capacity;
	_O_Array = new int[_O_Capacity];
	for (int i = 0; i < _O_Size; ++i)
		_O_Array[i] = arr._O_Array[i];

	return *this;

}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
	if (this != &other) {
		delete[] _O_Array;

		_O_Array = other._O_Array;
		_O_Size = other._O_Size;
		_O_Capacity = other._O_Capacity;

		other._O_Array = nullptr;
		other._O_Size = 0;
		other._O_Capacity = 0;
	}
	return *this;
}

void DynamicArray::_Resize() {

	if (_O_Array == nullptr) {
		_O_Array = new int[_O_Capacity];
		return;
	}
	_O_Capacity *= DEFAULT_INCREASE;
	_O_Array = _Copy(_O_Array, _O_Capacity, _O_Size);
}

void DynamicArray::Push(const int& val) {
	if (_O_Size >= _O_Capacity)
		_Resize();
	_O_Array[_O_Size++] = val;
}

void DynamicArray::Pop() {
	if (_O_Size == 0)
		return;
	--_O_Size;
}

void DynamicArray::Clear() {
	delete[] _O_Array;
	_O_Capacity = DEFAULT_CAPACITY;
	_O_Array = new int[_O_Capacity];
	_O_Size = 0;
}

void DynamicArray::Reserve(int capacity) {
	if (capacity <= _O_Capacity || _O_Array == nullptr)
		return;
	if (_O_Array == nullptr) {
		_O_Array = new int[capacity];
		_O_Capacity = capacity;
		return;
	}
	_O_Capacity = capacity;
	_O_Array = _Copy(_O_Array, _O_Capacity, _O_Size);
}

int DynamicArray::Size()const {
	if (_O_Array != nullptr)
		return _O_Size;
	return 0;
}

int DynamicArray::Capacity()const {
	if (_O_Array != nullptr)
		return _O_Capacity;
	throw std::runtime_error("Cannot access Size(),There is no initial value in array.");
}

int DynamicArray::At(int idx) {
	if (idx < 0 || idx >= _O_Size || _O_Array == nullptr)
		throw out_of_range("Cannot access this index, It's out of range.");
	return _O_Array[idx];
}

const int& DynamicArray::operator[](int idx)const #pragma region _
{
	return _O_Array[idx];
}
#pragma endregion

int DynamicArray::Front()const {
	if (_O_Size == 0)
		throw out_of_range("Cannot access Front(): DynamicArray is empty.");
	return _O_Array[0];
}

int DynamicArray::Back()const {
	if (_O_Size == 0)
		throw out_of_range("Cannot access Back(): DynamicArray is empty.");
	return _O_Array[_O_Size - 1];
}

DynamicArray::~DynamicArray() {
	delete[]_O_Array;
}