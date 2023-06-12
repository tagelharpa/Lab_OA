#pragma once
#include "Student.h"

class Vector
{
public:
	Vector();
	Vector(int);
public:
	~Vector(void);
	void Add();
	void Del();
	void Show();
	void Show(int);
	int operator()();
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};