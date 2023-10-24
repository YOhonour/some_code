#include <iostream>
#include <string>
#include"Person.h"
using namespace std;

void test016()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}
int main() {

	test016();

	return 0;
}