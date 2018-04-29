#include<string>
using namespace std;

class Gamestation
{
public:
	Gamestation(int dram); //
	virtual ~Gamestation();
	void Gaming();
protected:
	std::string m_strGPU;
	int m_iDRAM;
};