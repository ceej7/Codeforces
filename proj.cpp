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

int main(int argc, char* argv[]) {

	// in mesh convert
	struct{
		UINT16 padding;
		UINT8 nu, nv;//TODO: 
	}srcData = { 0 };

	auto quat = [](float v, UINT32 N)
	{
		const float scale = float((1 << (N - 1)) - 1);

		float round = (v >= 0 ? 0.5f : -0.5f);

		v = (v >= -1) ? v : -1;
		v = (v <= +1) ? v : +1;

		return int(v * scale + round) + ((1 << (N - 1)) - 1);//TODO
	};

	float vinx = 0.5; float viny = 0.5; float vinz = sqrt(1 - vinx * vinx - viny * viny);
	{
		float nsum = fabsf(vinx) + fabsf(viny) + fabsf(vinz);
		float nx = vinx / nsum;
		float ny = viny / nsum;
		float nz = vinz;

		float nu = nz >= 0 ? nx : (1 - fabsf(ny)) * (nx >= 0 ? 1 : -1);
		float nv = nz >= 0 ? ny : (1 - fabsf(nx)) * (ny >= 0 ? 1 : -1);

		srcData.nu = UINT8(quat(nu, 8));//TODO
		srcData.nv = UINT8(quat(nv, 8));//TODO
	}

	// in shader
	struct {
		float Norx;
		float Nory;
		float Norz;
	}vertInfo;

	UINT32 input = *(UINT*)(&srcData);

	float u = (INT32((input >> 16) & 0x00ff)-127) / 127.0f;//TODO
	float v = (INT32(((input >> 16) & 0xff00)>>8)-127) / 127.0f;//TODO
	vertInfo.Norz = 1 - abs(u) - abs(v);
	if (vertInfo.Norz >= 0)
	{
		vertInfo.Norx = u;
		vertInfo.Nory = v;
	}
	else if (u >= 0 && v >= 0)
	{
		vertInfo.Norx = 1 - v;
		vertInfo.Nory = 1 - u;
	}
	else if (u >= 0 && v < 0)
	{
		vertInfo.Norx = 1 + v;
		vertInfo.Nory = u - 1;
	}
	else if (u < 0 && v >= 0)
	{
		vertInfo.Norx = v - 1;
		vertInfo.Nory = u + 1;
	}
	else
	{
		vertInfo.Norx = (-1 - v);
		vertInfo.Nory = (-1 - u);
	}
	float normSum = std::sqrt(vertInfo.Norx * vertInfo.Norx + vertInfo.Nory * vertInfo.Nory + vertInfo.Norz * vertInfo.Norz);
	vertInfo.Norx /= normSum;
	vertInfo.Nory /= normSum;
	vertInfo.Norz /= normSum;

	system("pause");
}