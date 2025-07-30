#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

const short DelayMilliseconds = 70;

void slow_print(const string& str){
	for (char tmp : str) {
		cout << tmp;
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(DelayMilliseconds));
	}
}

int main(void){
	slow_print("Hello, World!");
  	return 0;
}
