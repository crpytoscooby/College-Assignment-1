#include<iostream>
using namespace std;

class Item
{
	private:
		static int count;
		int num;
	public:
		void getdata(int a)
		{
			num=a;
			count=count+1;
		}
		void display()
		{
			cout<<"Count="<<count<<endl;
		}
		static void statfunc()
		{
			cout<<"Satic function";
		}
};

int Item::count;	// default it takes 0

int main()
{
	Item obj1;
	Item obj2;
	Item obj3;
	obj1.getdata(10);
	obj1.display();
	obj2.getdata(20);
	obj2.display();
	obj3.getdata(30);
	obj3.display();
	
	Item::statfunc();
	return 0;
}

