#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const;
	void printElem();
private:
	std::vector<T> m_Tvec;
	// T* m_pVec;
};

template <class T>
Stack<T>::Stack()
{
	// m_pVec = new T[10];
	// for(int i=0;i<10;i++){
	// 	m_pVec;
	// }
}

template <class T>
Stack<T>::~Stack(){}

template <class T>
void Stack<T>::push(T const& elem)
{
	m_Tvec.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (m_Tvec.empty()){
		cout<<"empty"<<endl;
	}
	m_Tvec.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if(m_Tvec.empty()){
		cout<<"empty"<<endl;
	}
	return m_Tvec.back();
}

template <class T>
bool Stack<T>::empty() const
{
	return m_Tvec.empty();
}

template <class T>
void Stack<T>::printElem()
{
	for (std::vector<int>::iterator itr=m_Tvec.begin();itr!=m_Tvec.end();itr++)
		cout<<*itr<<endl;
	cout<<"\n"<<endl;
}