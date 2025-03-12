#ifndef DERIVED_HPP
#define DERIVED_HPP

#include "Base.hpp"

class A: public Base 
{
	public:
		virtual ~A(void);
};

class B: public Base 
{
	public:
		virtual ~B(void);
};

class C: public Base 
{
	public:
		virtual ~C(void);
};

#endif