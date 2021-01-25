#include <iostream>
#include <stdio.h>
#include <string>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <set>
#include <d3d12.h>
#include <wrl.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <guiddef.h>
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

struct Allocation {
	Allocation(UINT64 _offset, UINT64 _size) :
		offset(_offset), size(_size) {}
	Allocation(UINT64 _offset) :
		offset(_offset), size(0){}

	UINT64 offset;
	UINT64 size;

	bool operator<(const Allocation& allocation)const {
		if (this->size != 0 && allocation.size != 0) // both a and b are full allocation 
			return this->offset < allocation.offset;
		// std::set depends on stick lessthen; a is full allocation, b is a place in some allocation
		// b allocation's size equal to zero, but has a place in the form of "offset"
		//-----------------b1--------------b2-----------------b3----------
		//---------------------||aaaaaaaaaaaaaaaaaaaaa||----------------
		//---------------------||--this is the full alloc a--||----------------
		// when a compared with b, return aOffset+aSize < bOffset
		// when b compared with a, return bOffset < aOffset
		/*OffsetType aOffset = this->size != 0 ? this->offset : allocation.offset;
		SizeType aSize = this->size != 0 ? this->size : allocation.size;
		OffsetType bOffset */
		if (this->size != 0) {//this is a, a compared with b
			return this->offset + this->size-1 < allocation.offset;
		}
		else {//this is b, b compared with a 
			return this->offset < allocation.offset;
		}

	}
};

UINT32 PackDrawMletPrimId(UINT32 drawId, UINT32 use32Index, UINT32 meshletId, UINT32 primitiveId)
{
	UINT32 drawId_mletId_primId = ((drawId << 25) & 0xFE000000) | ((use32Index << 24) & 0x01000000) | ((meshletId << 5) & 0x00FFFFE0) | ((primitiveId << 0) & 0x0000001F);
	return drawId_mletId_primId;
}

int main(int argc, char* argv[]) {

	//std::vector<int> vec(4);
	//vec[0] = 99; vec[1] = 99;
	//vec[2] = 97;
	//vec[3] = 95;
	//vec.resize(1);
	//vec.resize(10);




	//std::cout<<"----------------------------------" << std::endl;
	//std::set<Allocation> allocations;

	//allocations.emplace(Allocation(0, 16));
	//allocations.emplace(Allocation(16, 16));

	//for (auto it = allocations.begin(); it != allocations.end(); it++) {
	//	printf("%d--%d\n", it->offset, it->size);
	//}
	//printf("------------------------------\n");
	//auto it = allocations.find(Allocation(16));
	//printf("%d, %d\n", it->offset, it->size);
	
//#define PARTICLE_OIT_MAX_DEPTH 8
//	int layerCount = 0;
//	int layers[PARTICLE_OIT_MAX_DEPTH] = { 0,1,7,2,4,5,6,3 };
//	std::srand(std::time(nullptr));
//	for (int i = 0; i < PARTICLE_OIT_MAX_DEPTH; i++) {
//		layers[i]=std::rand() / ((RAND_MAX + 1u) / 36);
//	}
//	for (; layerCount < PARTICLE_OIT_MAX_DEPTH; layerCount++) {
//		int tmpLayer = layers[layerCount];
//		//insertion sort
//		int j = layerCount - 1;
//		for (; j >= 0&&layers[j] > tmpLayer; j--) {
//			layers[j + 1] = layers[j];
//		}
//		layers[j + 1] = tmpLayer;
//	}
//	printf("aa\n");

	//UINT32 a = 98;
	//UINT32 b = 0;
	//UINT32 c = 454324;
	//UINT32 d = 27;
	//UINT32 packedId = PackDrawMletPrimId(a, b, c, d);
	//UINT32 a1 = (packedId & 0xFE000000) >> 25;
	//UINT32 b1 = (packedId & 0x01000000) >> 24;
	//UINT32 c1 = (packedId & 0x00FFFFE0) >> 5;
	//UINT32 d1 = (packedId & 0x0000001F) >> 0;
	//printf("%d-%d-%d-%d\n", a1, b1, c1, d1);

	void* a[2][5] = {
		{reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1)},
		{reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1),reinterpret_cast<void*>(1)}
	};

	int b = sizeof(a);
	int c = sizeof(a) / sizeof(a[0][0]);

	memset(a, 0, b - 1* sizeof(a[0][0]));


	//std::vector<UINT> m_vec;
	//m_vec.reserve(10);
	//std::cout << m_vec.capacity() << std::endl;
	//m_vec.push_back(1);
	//m_vec.push_back(1);
	//m_vec.push_back(1);
	//std::cout << m_vec.capacity() << std::endl;
	//m_vec.clear();
	//std::cout << m_vec.capacity() << std::endl;

	struct SMiscData {
		UINT g_LoadVertexInfo[4];
		UINT g_BatchOffset;
		UINT g_PackedSamplerId;
		UINT padding[2];
	};

	std::cout << sizeof(SMiscData) << std::endl;


	system("pause");
	//uint4 UnpackDrawMletPrimId(uint packedId) {
	//	return uint4((packedId & 0xFE000000) >> 25, (packedId & 0x01000000) >> 24, (packedId & 0x00FFFFE0) >> 5, (packedId & 0x0000001F) >> 0);
	//}

}