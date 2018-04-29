class Array
{
public:
	Array(int len);
	~Array();
	void setLen(int len);
	Array& setLen2(int len);
	Array* setLen3(int len);
	int getLen();

	Array printInfo();
	Array& printInfo2();
	Array* printInfo3();
	Array* printAddr(); //print addr of this obj
private:
	int m_iLen;
};
