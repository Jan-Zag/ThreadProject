#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int a, int b) //emulation of a complex task in 11 seconds (a little more)
{
	this_thread::sleep_for(chrono::milliseconds(3000));

	cout << "============\t" << "DoWork STARTED\t============" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "a+b = " << a + b << endl;

	this_thread::sleep_for(chrono::milliseconds(3000));

	cout << "============\t" << "DoWork STOPED\t============" << endl;
}

int main()
{
	thread th(DoWork, 2, 3);

	for (size_t i = 0; true; i++)
	{
		cout << "ID of Thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));										//0.5 sec stop (task execution emulation)
	}

	th.join();
	return 0;
}