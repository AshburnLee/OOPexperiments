#include"Hyper.h"
#include"Street.h"

class Mustang:public Hyper,public Street
{
public:
	Mustang(std::string engine, int turbo, std::string name);
	virtual ~Mustang();
};