#include <iostream>
#include <stdio.h>
#include <string>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
using namespace std;


float hexstrtoflo1(string content)
{
	const char* myString = content.c_str();
	uint32_t num;
	float f;
	sscanf(myString, "%x", &num);  // assuming you checked input
	f = *((float*)&num);
	return f;
}

int main() {
	char incstr[100] = {'\0'};
	while (cin.getline(incstr, 100)) {
		string instr = incstr;

		auto st = instr.find("0x");
		size_t ed = 0;
		while ((int)st > 0) {
			size_t ed1 = instr.find(' ', st + 1);
			size_t ed2 = instr.find('}', st + 1);
			if (ed1 >= 0 || ed2 >= 0) {
				//if (ed1 < 0) ed1 = 10000000;
				//if (ed2 < 0) ed2 = 10000000;
				ed = ed1 < ed2 ? ed1 : ed2;
				string res = instr.substr(st + 2, ed - st - 2);
				printf("%.25f   ", hexstrtoflo1(res));
				st = instr.find("0x", ed);
			}
			else {
				break;
			}
		}
		cout << endl;
		cout << "-----------------------------------------" << endl;
	}
	

	
	//float r0x= hexstrtoflo1("0x47006f09");
	//float r0y= hexstrtoflo1("0xc407ff20");
	//float r0z= hexstrtoflo1("0x46fbd673");
	//float r0w= hexstrtoflo1("0x3f800000");

	//
	//float cb0x = hexstrtoflo1("0x387cdbaa");
	//float cb0y = hexstrtoflo1("0x0");
	//float cb0z = hexstrtoflo1("0x387cdbaa");
	//float cb0w = hexstrtoflo1("0xc07cd7dc");

	//float o2x = r0x * cb0x + r0y * cb0y + r0z * cb0z + r0w * cb0w;

	//printf("0x%08X\n", o2x);
	//printf("float: %.25f\n", o2x);

	//printf("float vs: %.25f\n", hexstrtoflo1("0xbcce6180"));

	system("pause");
}