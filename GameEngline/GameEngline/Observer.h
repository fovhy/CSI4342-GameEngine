/*
the interface for observer pattern. All class use observer pattern should use this interface.

Author: Dean He
Date: 9/9/2016
*/
#pragma once
class Observer
{
public:
	virtual void attach() = 0;
	virtual void detach() = 0;
	Observer();
	~Observer();
};

