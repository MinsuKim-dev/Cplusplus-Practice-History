#include <iostream>
using namespace std;

template<typename T>
class Iterator;

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			int newcapacity = static_cast<int>(_capacity * 1.5);
			if (newcapacity == _capacity)
				newcapacity++;

			reserve(newcapacity);
		}

		_data[_size] = val;
		_size++;
	}

	T& operator[](const int index)
	{
		return _data[index];
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		T* newdata = new T[_capacity];

		for (int i = 0; i < _size; i++)
			newdata[i] = _data[i];

		if (_data)
			delete[] _data;

		_data = newdata;
	}

	int size() { return _size; }
	int capacity() { return _capacity; }
	void clear() { _size = 0; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

private:
	T* _data;
	int _size;
	int _capacity;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator& iterator)
	{
		return _ptr == iterator._ptr;
	}

	bool operator!=(const Iterator& iterator)
	{
		return !(*this == iterator);
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

int main()
{
	Vector<int> v;

	v.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}
	cout << "--------------------------------------" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << "it--------------------------------------" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	v.clear();
}