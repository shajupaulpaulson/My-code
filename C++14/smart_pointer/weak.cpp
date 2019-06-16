#include <iostream>
#include <memory>

using namespace std;
int main(){
	shared_ptr<int> p1 (new int(20));
	shared_ptr<int> p2 = p1;
	cout << "p1 and p2 are " << *p1 << ", " <<*p2 <<endl;
	p1.reset();
	cout << "p2 are " << *p2 <<endl;
	p2.reset();
	if ( (p1 == NULL) && (p2 == NULL))
		cout << "Both p1 and p2 are cleared" <<endl;

	p1 = make_shared<int>(10);
	p2 = p1;
	cout << "p1 and p2 are " << *p1 << ", " <<*p2 <<endl;

	weak_ptr <int> wp1{p1};
	{
		shared_ptr<int> p3 = wp1.lock();
		cout << "p3 : " << *p3 <<endl;	
	}

	p1.reset();
	{
		shared_ptr<int>p3 = wp1.lock();
		if (p3 != NULL)
			cout << "p3 : " << *p3 <<endl;
		else
			cout << "p3 is intiallized to null but p2 is still there" <<endl;
	}
	p2.reset();
	{
		shared_ptr<int>p3 = wp1.lock();
		if (p3 != NULL)
			cout << "p3 : " << *p3 <<endl;
		else
			cout << "p3 is intiallized to null after p2 is reset" <<endl;
	}

	return 0;
}
