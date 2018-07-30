
#include"bst.h"
#include<list>
#include<vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <locale>

using std::cout;
using std::endl;
using std::vector;
using std::list;

//Class to handle timing 
class Timer {
public:
	void start() { ref_start = highc.now(); }
	void stop() { duration = std::chrono::duration_cast<std::chrono::nanoseconds>(highc.now() - ref_start).count(); }
	void report() { cout << "Time: " << duration << "ns" << endl; }
	void report(int size) { cout << "Time/element: " << duration / size << "ns/element" << endl; }
	long long getDuration() { return duration; }
private:
	std::chrono::high_resolution_clock highc;
	std::chrono::high_resolution_clock::time_point ref_start;
	long long duration;
};


void test_insert(int test_size) {

	// Create an array for to insert into data structures
	vector<int> input_vector;
	for (int i = 0; i < test_size; i++) {
		input_vector.push_back(i);
	}
	//Shuffle the elements randomly
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(input_vector.begin(), input_vector.end(), g);

	//for (vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); ++i)
	//	cout << *i << ' ';
	cout << endl << input_vector.size() << endl;

	Timer timer;

	// Data structures
	// List<int> list;
	// SortedLinkeList slist;
	BinarySearchTree bst;
	list<int> stlList1, stlList2;
	vector<int> v1;

	cout << endl << "-------------- Testing Insert " << test_size << " ---------------" << endl;

	{ // Test Insertions

	  //Start timing
	  //
		cout << endl << "Testing bst insertions: " << endl;
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			bst.insert(input_vector[i]);

		// End timing
		timer.stop();
		timer.report(test_size);

		cout << endl << "Testing stl linked list insertions back: " << endl;
		//Start timing
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			stlList1.push_back(input_vector[i]);

		// End timing
		timer.stop();
		timer.report(test_size);

		cout << endl << "Testing stl linked list insertions front: " << endl;
		//Start timing
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			stlList2.push_front(input_vector[i]);

		// End timing
		timer.stop();
		timer.report(test_size);


		cout << endl << "Testing stl vector insertions back: " << endl;
		//Start timing
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			v1.push_back(input_vector[i]);

		// End timing
		timer.stop();
		timer.report(test_size);
	}
}
void test_search(int test_size) {
	// Create an array for to insert into data structures
	vector<int> input_vector;
	for (int i = 0; i < test_size; i++) {
		input_vector.push_back(i);
	}
	//Shuffle the elements randomly
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(input_vector.begin(), input_vector.end(), g);

	//for (vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); ++i)
	//	cout << *i << ' ';
	cout << endl << input_vector.size() << endl;

	Timer timer;

	// Data structures
	// List<int> list;
	// SortedLinkeList slist;
	BinarySearchTree bst;
	list<int> stlList1;
	vector<int> v1;

	//Populate for searching
	for (int i = 0; i < input_vector.size(); i++) {
		bst.insert(input_vector[i]);
		stlList1.push_back(input_vector[i]);
		v1.push_back(input_vector[i]);

	}

	cout << endl << "-------------- Testing Search " << test_size << " ---------------" << endl;

	{ // Test Search

	  //Start timing
	  //
		cout << endl << "Testing bst search: " << endl;
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			bst.search(input_vector[i]);

		// End timing
		timer.stop();
		timer.report(test_size);

		cout << endl << "Testing stl linked list searching using algorithm find: " << endl;
		//Start timing
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			std::find(stlList1.begin(), stlList1.end(), i);

		// End timing
		timer.stop();
		timer.report(test_size);


		cout << endl << "Testing stl vector searching using algorithm find:" << endl;
		//Start timing
		timer.start();

		for (int i = 0; i < input_vector.size(); i++)
			std::find(v1.begin(), v1.end(), i);

		// End timing
		timer.stop();
		timer.report(test_size);


		cout << endl << "Testing stl vector sorting first then binary search:" << endl;
		//Start timing
		timer.start();

		std::sort(v1.begin(), v1.end());
		for (int i = 0; i < input_vector.size(); i++)
			std::binary_search(v1.begin(), v1.end(), i);

		// End timing
		timer.stop();
		timer.report(test_size);
	}

}
