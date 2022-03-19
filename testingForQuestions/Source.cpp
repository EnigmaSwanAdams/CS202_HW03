

#include <fstream>
#include <string>

int main() {

	std::ofstream f;
	f.open("data.dat", std::ios::out | std::ios::binary);
	std::string myStr = "Hello";
	f.write(myStr.c_str(), myStr.size());
	f.close();

}




