#include<string>
using namespace std;

class Computer
{
public:
	Computer(int ram);
	virtual ~Computer();
	void Datamining();
protected:
	std::string m_strCPU;
	int m_iRAM;
};