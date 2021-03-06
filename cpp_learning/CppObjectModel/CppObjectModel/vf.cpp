#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::dec;
using std::endl;
using std::hex;

class Base
{
public:
	virtual void a() { cout << "Base::a" << endl; }
	virtual void b() { cout << "Base::b" << endl; }
	virtual void c() { cout << "Base::c" << endl; }
	void d() { cout << "Base::d" << endl; }
};

class Base1
{
public:
	virtual void a() { cout << "Base1::a" << endl; }
	virtual void b1() { cout << "Base1::b1" << endl; }
	virtual void c1() { cout << "Base1::c1" << endl; }
	void d1() { cout << "Base1::d1" << endl; }
};

class Base2
{
public:
	virtual void a() { cout << "Base2::a" << endl; }
	virtual void b2() { cout << "Base2::b2" << endl; }
	virtual void c2() { cout << "Base2::c2" << endl; }
	void d2() { cout << "Base2::d2" << endl; }
};

class Derived : public Base, public Base1, public Base2 {
public:
	void a() { cout << "Derived::a" << endl; }
	virtual void ad() { cout << "Derived::ad" << endl; }
	virtual void bd() { cout << "Derived::bd" << endl; }
	virtual void cd() { cout << "Derived::cd" << endl; }
};

class Derived1 {
private:
	void a() { cout << "Derived1::a" << endl; }
	virtual void ad() { cout << "Derived1::ad" << endl; }
	virtual void bd() { cout << "Derived1::bd" << endl; }
	virtual void cd() { cout << "Derived1::cd" << endl; }
};

void Vf() {
  cout << endl << "instance of Base" << endl;

	Base b;

	cout << "address of vfptr:" << hex << &b << endl;
	cout << "address of vftable:" << hex << *(int*)(&b) << endl;
	cout << "address of the first function in vftable:" << hex << (int*)(*(int*)(&b)) << endl;

	void(*pf)(void) = (void(*)(void))*(int*)(*(int*)(&b));
	pf = (void(*)(void))*(int*)(*(int*)(&b));
	pf();

	pf = (void(*)(void))*((int*)*(int*)(&b) + 1);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)(&b) + 4);
	pf();

	pf = (void(*)(void))*((int*)*(int*)(&b) + 2);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)(&b) + 8);
	pf();

	Base* bd = new Derived();

  cout << endl << "instance of Derived" << endl;
  cout << endl << "by normal pointer" << endl;

	pf = (void(*)(void))*((int*)*(int*)bd);
	pf();

	pf = (void(*)(void))*((int*)*(int*)bd + 1);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)bd + 4);
	pf();

	pf = (void(*)(void))*((int*)*(int*)bd + 2);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)bd + 8);
	pf();

	pf = (void(*)(void))*((int*)*(int*)bd + 3);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)bd + 12);
	pf();

	pf = (void(*)(void))*((int*)*(int*)bd + 4);
	pf();
	pf = (void(*)(void))*(int*)(*(int*)bd + 16);
	pf();

	pf = (void(*)(void))*((int*)*(int*)bd + 5);
	pf();
	((void(*)(void))*((int*)*(int*)bd + 5))();
	pf = (void(*)(void))*(int*)(*(int*)bd + 20);
	pf();

  cout << endl << "by normal array" << endl;

  for (int i = 0; i < 6; ++i) {
    pf = (void(*)(void))(((int*)*(int*)bd)[i]);
    pf();
  }

  cout << endl << "access each vftable" << endl;

  ((void(*)(void))((int*)(((int*)bd)[0]))[0])();
  ((void(*)(void))((int*)(((int*)bd)[0]))[1])();
  ((void(*)(void))((int*)(((int*)bd)[0]))[2])();
  ((void(*)(void))((int*)(((int*)bd)[0]))[3])();
  ((void(*)(void))((int*)(((int*)bd)[0]))[4])();
  ((void(*)(void))((int*)(((int*)bd)[0]))[5])();
  ((void(*)(void))((int*)(((int*)bd)[1]))[0])();
  ((void(*)(void))((int*)(((int*)bd)[1]))[1])();
  ((void(*)(void))((int*)(((int*)bd)[1]))[2])();
  ((void(*)(void))((int*)(((int*)bd)[2]))[0])();
  ((void(*)(void))((int*)(((int*)bd)[2]))[1])();
  ((void(*)(void))((int*)(((int*)bd)[2]))[2])();

  cout << endl << "instance of Derived1" << endl;

	pf = (void(*)(void))*((int*)*((int*)bd + 1));
	pf();

	pf = (void(*)(void))*((int*)*((int*)bd + 1) + 1);
	pf();

	Derived1* bd1 = new Derived1();
	pf = (void(*)(void))*((int*)*(int*)bd1);
	pf();
}