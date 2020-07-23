#include <iostream>
#include <stdio.h>
#include <string>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace std;


struct HeadlessImpl {
	enum EHeadlessType {
		EHeadless_Lookaround = 0,
		Eheadless_NUMBER = EHeadless_Lookaround+1
	};
	HeadlessImpl(int argc, char* argv[]) { // parsing
		if (argc < 1) return;
		m_args.emplace(wd, argv[0]);
		for (int i = 1; i < argc; i++) {
			std::string key;
			if (!IsArgKey(argv[i], key))
				continue;
			std::string notKey;
			if (i + 1 < argc && !IsArgKey(argv[i + 1], notKey)) {
				m_args.emplace(key, argv[i + 1]);
				i++;
			}
			else
				m_args.emplace(key, "");
		}
	}
	static bool IsArgKey(char* arg, std::string& keyin) {
		std::string key = arg;
		if (key.size() > 1&&key.at(0)=='-') {
			keyin = key.substr(1);
			return true;
		}
		return false;
	}

	bool isHeadlessState() {
		return m_args.find(mark) != m_args.end() && getHeadlessState() != Eheadless_NUMBER;
	}
	EHeadlessType getHeadlessState() {
		if (m_args.find(mark) == m_args.end())
			return Eheadless_NUMBER;
		if (stricmp(m_args.find(mark)->second.c_str() ,"Lookaround")==0)
			return EHeadless_Lookaround;
		// extension
		return Eheadless_NUMBER;
	}
	bool isKeyExisted(const std::string& key) {
		return m_args.find(key) != m_args.end();
	}
	std::string getKeyValue(const std::string& key) {
		if (!isKeyExisted(key)) return "";
		return m_args.find(key)->second;
	}
	bool isKeyEqualValue(const std::string& key, const std::string& value) {
		return isKeyExisted(key) && getKeyValue(key) == value;
	}


	std::map<std::string, std::string> m_args;
	const std::string mark = "Headless";
	const std::string wd = "-WD";
};

int main(int argc, char* argv[]) {
}