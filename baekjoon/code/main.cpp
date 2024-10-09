#include <iostream>
#include <bitset>

char * b = new char[10];

void function1(char * & a)
{
	printf("%d\n", a);
	b[0] = 'a';
	b[1] = 'b';
	b[2] = 'c';
	b[3] = 0x00;
	b[4] = 'd';
	b[5] = 0x00;
	b[6] = 'd';
	b[7] = 'e';
	printf("%d\n", a);
}

int main()
{
	function1(b);
    std::string hi(b); // (1)
	std::cout << hi << std::endl;

	return 0;
}
