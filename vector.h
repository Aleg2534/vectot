#pragma once

template<typename T1>
class IteratorV {
private:
	T1* num;
public:
	IteratorV<T1>() :num(nullptr) {};
	IteratorV<T1>( T1* n) :num(n) {};
	IteratorV<T1>(IteratorV<T1>& obj)
	{
		num = obj.num;
	}
	IteratorV<T1>(IteratorV<T1>&& obj)
	{
		num = obj.num;
		obj.num = nullptr;
	}
	IteratorV<T1>& operator++() {
		++num;
		return *this;
	}
	IteratorV<T1>& operator++(int) {
		IteratorV<T1> ret(*this);
		++num;
		return ret;
	}

	IteratorV<T1>& operator--() {
		--num;
		return *this;
	}
	IteratorV<T1>& operator--(int) {
		IteratorV<T1> ret(*this);
		--num;
		return ret;
	}
	IteratorV<T1>& operator= ( IteratorV<T1>& rhs)
	{
		num = rhs.num;
		return *this;
	}

	IteratorV<T1>& operator= (IteratorV<T1>&& rhs)
	{
		this->num = rhs.num;
		rhs.num = nullptr;
		return *this;
	}

	T1& operator*() {

		return *num;
	}
	bool operator==(const IteratorV<T1>& rhs)
	{
		return num == rhs.num;
	}

	bool operator==(std::nullptr_t rhs)
	{
		return num == rhs;
	}

	bool operator!=(const IteratorV<T1>& rhs)
	{
		return num != rhs.num;
	}

	bool operator!=(std::nullptr_t rhs)
	{
		return num != rhs;
	}

	bool operator<(const IteratorV<T1>& rhs)
	{
		return num < rhs.num;
	}

	bool operator<=(const IteratorV<T1>& rhs)
	{
		return num <= rhs.num;
	}

	bool operator>(const IteratorV<T1>& rhs)
	{
		return num > rhs.num;
	}

	bool operator>=(const IteratorV<T1>& rhs)
	{
		return num >= rhs.num;
	}
};

template<typename T1>

IteratorV<T1> operator+(IteratorV<T1>& lhs, int a)
{
	if (lhs == nullptr)
		return lhs;
	IteratorV<T1> obj(lhs);
	for (int i = 0; i < a; i++)
	{
		++obj;
	}
	return obj;
}

template<typename T1>

IteratorV<T1> operator+= ( IteratorV<T1>& lhs, int a)
{
	if (lhs == nullptr)
		return lhs;
	lhs = lhs + a;
	return lhs;
}

template<typename T1>
class Vector {
private:
	T1* v;
	int size;
public:
	Vector<T1>() :v(nullptr), size(0) {};
	Vector<T1>(int s)
	{
		size = s;
		v = new T1[size];
	}
	Vector<T1>(int s,T1* arr)
	{
		size = s;
		v = arr;
	}
	Vector<T1>(const Vector<T1>& obj)
	{
		size = obj.size;
		v = new T1[size];
		for (int i = 0; i < size; i++)
		{
			v[i] = obj.v[i];
		}
	}

	Vector<T1>(Vector<T1>&& obj)
	{
		size = obj.size;
		v = obj.v;
		
		obj.size = 0;
		obj.v = nullptr;
	}

	~Vector()
	{
		size = 0;
		delete[] v;
		v = nullptr;
	}

	Vector<T1>& operator=( Vector<T1>& rhs)
	{
		if (*this == rhs)
			return *this;
		size = rhs.size;
		delete[] v;
		v = new T1[size];
		for (int i = 0; i < size; i++)
		{
			v[i] = rhs.v[i];
		}
		return *this;
	}

	Vector<T1>& operator=( Vector<T1>&& rhs)
	{
		if (*this == rhs)
		{
			delete[] rhs.v;
			rhs.v = nullptr;
			rhs.size = 0;
			return *this;
		}
		size = rhs.size;
		delete[] v;
		v = rhs.v;
		rhs.v = nullptr;
		rhs.size = 0;
		return *this;
	}

	bool operator==(Vector<T1>& rhs)
	{
		if (size != rhs.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (v[i] != rhs.v[i])
				return false;
		}
		return  true;
	}

	T1& at(int n)
	{
		if (size <= 0)
			throw "size = 0";
		if ((n < 0) || (n >= size))
			throw "wrong index";
		return v[n];
	}

	T1& at(int n) const
	{
		if (size <= 0)
			throw "size = 0";
		if ((n < 0) || (n >= size))
			throw "wrong index";
		return v[n];
	}

	T1& operator[](int n)
	{
		return v[n];
	}

	T1& operator[](int n) const
	{
		return v[n];
	}

	T1& front()
	{
		return *v;
	}

	T1& front() const
	{
		return *v;
	}

	T1& back()
	{
		return v[size - 1];
	}

	T1& back() const
	{
		return v[size - 1];
	}

	T1* date()
	{
		return v;
	}

	IteratorV<T1> begin()
	{
		IteratorV<T1> obj(v);
		return obj;
	}

	IteratorV<T1> end()
	{
		IteratorV<T1> obj(v + size - 1);
		return obj;
	}

	bool empty()
	{
		return end()==begin();
	}

	int sizee() const
	{
		return size;
	}

	void clear()
	{
		size = 0;
		delete[] v;
		v = nullptr;
	}

	IteratorV<T1> insert(IteratorV<T1> it, T1 a)
	{
		Vector<T1> vec(size+1);
		int b,i = 0;
		IteratorV<T1> obj;
		for (obj=begin(); obj != it; obj++)
		{
			vec.v[i] = *obj;
			i++;
		}
		vec.v[i] = a;
		b = i;
		i++;
		for (obj; obj <= end(); obj++)
		{
			vec.v[i] = *obj;
			i++;
		}

		*this = vec;
		it = begin() + b;
		return it;
	}

	IteratorV<T1> erase(IteratorV<T1> it)
	{
		Vector<T1> vec(size - 1);
		int a,i = 0;
		IteratorV<T1> obj;
		for (obj = begin(); obj != it; obj++)
		{
			vec.v[i] = *obj;
			i++;
		}
		if (i == size-1)
			a = i - 1;
		else
			a = i;
		obj++;
		for (obj; obj <= end(); obj++)
		{
			vec.v[i] = *obj;
			i++;
		}

		*this = vec;
		it = begin() + a;
		return it;
	}

	bool operator ==(const Vector<T1>& rhs)
	{
		if (size != rhs.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (v[i] != rhs.v[i])
				return false;
		}
		return true;
	}

	bool operator <(const Vector<T1>& rhs)
	{
		if (size != rhs.size)
			return size < rhs.size;
		for (int i = 0; i < size; i++)
		{
			if (v[i] >= rhs.v[i])
				return false;
		}
		return true;
	}

	bool operator >(const Vector<T1>& rhs)
	{
		if (size != rhs.size)
			return size > rhs.size;
		for (int i = 0; i < size; i++)
		{
			if (v[i] <= rhs.v[i])
				return false;
		}
		return true;
	}

	bool operator <=(const Vector<T1>& rhs)
	{
		return !(*this > rhs);
	}

	bool operator >=(const Vector<T1>& rhs)
	{
		return !(*this < rhs);
	}

	bool operator !=(const Vector<T1>& rhs)
	{
		return !(*this == rhs);
	}
};

