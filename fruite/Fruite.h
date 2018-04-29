#include<string>

class Fruite
{
public:
	Fruite(std::string name = "fruite_is_sweet");
	virtual ~Fruite();
	void grow();
protected:
	std::string m_strName;
};