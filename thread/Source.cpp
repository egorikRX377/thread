#include  <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>


using namespace std;




void doWork(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\t" << "doWork STARTED" << "\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\t" << "doWork ENDED" << "\t=========" << endl;
}

int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\t" << "Sum STARTED" << "\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	int result = a + b;
	cout << result << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\t" << "Sum ENDED" << "\t=========" << endl;
	return result;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int m = 0;
	int n = 0;
	[&, n](int a) mutable { m = ++n + a; }(4);
	cout << m << endl << n << endl;

	int result = 0;
	int a = 5;
	int b = 12;

	auto func = [&result](int a, int b) { result = Sum(a, b); };
	thread th(func, a, b);


	for (size_t i = 0; true; i++)
	{
		cout << "ID потока: " << this_thread::get_id() << "\t main\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();

	return 0;
}