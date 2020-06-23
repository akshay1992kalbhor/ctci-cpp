#include <iostream>

void swap_nums_in_place(int& a, int& b) {
	std::cout << "Before: " << a << ", " << b << std::endl;
	
	a = b ^ a;
	b = a ^ b; // b = b ^ a ^ b => a
	a = a ^ b; // a = b ^ a ^ a => b

	std::cout << "After: " << a << ", " << b << std::endl;

}

int main() {
	int a = 1;
	int b = 2;

	swap_nums_in_place(a, b);
}
