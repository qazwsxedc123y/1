#pragma once

template<class Iterator, class Ref, class Ptr>
class Reserve_iterator
{
	typedef Reserve_iterator<Iterator, Ref, Ptr> Self;

public:

	Reserve_iterator(Iterator it)
		:_it(it)
	{}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}
	Ref operator*()
	{
		Iterator cur = _it;
		return *(--cur);
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	bool operator!=(const Self& s)
	{
		return _it != s._it;
	}
	bool operator==(const Self& s)
	{
		return _it == s._it;
	}
private:
	Iterator _it;
};