#pragma once
#include "Object.h"
#include<iostream>
#include "TEvent.h"

using namespace std;
class Human :
	public Object
{
public:
	
	Human(void);
	Human(string, int);
	Human(const Human&);
	~Human(void);
	void Show();
	void Input();
	string Get_name() { return name; }
	int Get_age() { return age; }
	void Set_name(string);
	void Set_age(int);
	Human& operator=(const Human&);
	void HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};