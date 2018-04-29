#include"Worker.h"
#include<iostream>

Worker::Worker()
{
	std::cout<<"Worker()"<<std::endl;
}

Worker::~Worker()
{
	std::cout<<"~Worker()"<<std::endl;
}

void Worker::work()
{
	//m_strName & m_iAge are protected in Person.
	m_strName = "PO";
	m_iAge = 30;
	std::cout<<"I am working~~~"<<std::endl;
}


