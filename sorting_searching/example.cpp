#include <string>
#include <iostream>


void rev(const char *cs) {
}

void revstr(const std::string& s) {
}
void something(std::string s) {
}
int main() {	
	const char* cs = "dba";
	char *cs1 = static_cast<char*>("abc");
	revstr(cs1);
	something(cs);
}
