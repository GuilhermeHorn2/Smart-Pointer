#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


template <class T> class Smart_pointer{

	T* ptr;

public:
	Smart_pointer(T* ptr){
		this->ptr = ptr;
	}

	~Smart_pointer(){
		cout << "deleting..." << endl;
		free(ptr);
	}
	T* get_ptr(){
		return ptr;
	}
	void allocate(int size){
		ptr = new T[size];

	}
	void assign(T data){
		ptr = new T(data);
	}
	T get_data(){
		return *ptr;
	}

};


int main()
{
	/*  || \ */

	int*a;
	Smart_pointer<int> ptr =Smart_pointer<int>(a);
	ptr.allocate(10);
	for(int i = 0;i < 10;i++){
		ptr.get_ptr()[i] = i;
		cout << ptr.get_ptr()[i];
	}
	cout<<""<<endl;

	string *s;
	Smart_pointer<string> ptr_str = Smart_pointer<string>(s);
	ptr_str.assign("Horn");
	cout << ptr_str.get_data() << endl;



	return 0;
}


