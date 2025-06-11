#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
using namespace std;

void PrintArray(const DynamicArray& arr, const string& name) {
	cout << name << " (size: " << arr.Size() << ", capacity: " << arr.Capacity() << "): ";
	for (int i = 0; i < arr.Size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	try {
		cout << " Push\n";
		DynamicArray arr;
		arr.Push(10);
		arr.Push(20);
		arr.Push(30);
		PrintArray(arr, "arr");

		cout << "\ Front & Back\n";
		cout << "Front: " << arr.Front() << endl;
		cout << "Back: " << arr.Back() << endl;

		cout << "\ Pop\n";
		arr.Pop();
		PrintArray(arr, "arr after pop");

		cout << "\n At(idx)\n";
		cout << "Element at index 0: " << arr.At(0) << endl;

		cout << "\n Copy Constructor\n";
		DynamicArray copyArr = arr;
		PrintArray(copyArr, "copyArr");

		cout << "\n Move Constructor\n";
		DynamicArray moveArr = std::move(arr);
		PrintArray(moveArr, "moveArr");

		cout << "\n Copy Assignment\n";
		DynamicArray arr2;
		arr2 = copyArr;
		PrintArray(arr2, "arr2");

		cout << "\n Move Assignment\n";
		DynamicArray arr3;
		arr3 = std::move(copyArr);
		PrintArray(arr3, "arr3");

		cout << "\n Clear\n";
		arr2.Clear();
		PrintArray(arr2, "arr2 after clear");

		cout << "\n Reserve\n";
		arr3.Reserve(20);
		cout << "New Capacity after Reserve(20): " << arr3.Capacity() << endl;

		cout << "\nTesting Exception: Front on empty array\n";
		arr2.Front();

	}
	catch (const exception& e) {
		cout << "Exception : " << e.what() << endl;
	}

	return 0;
}
