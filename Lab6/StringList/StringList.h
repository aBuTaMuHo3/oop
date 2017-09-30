#pragma once
#include "Iterator.h"

class CStringList
{

public:

	CStringList();
	CStringList(CStringList & list);
	CStringList(CStringList && list);
	~CStringList();

	size_t GetSize() const;
	bool IsEmpty() const;

	void Append(std::string const & data);
	void PushFront(std::string const & data);

	void Insert(const CIterator<std::string> & it, std::string const & data);
	void Erase(const CIterator<std::string> & it);
	
	void Clear();

	CIterator<std::string> begin();
	CIterator<const std::string> CStringList::begin() const;
	CIterator<std::string> end();
	CIterator<const std::string> CStringList::end() const;
	CIterator<const std::string> cbegin() const;
	CIterator<const std::string> cend() const;


	std::reverse_iterator<CIterator<std::string>> rbegin();
	std::reverse_iterator<CIterator<std::string>> rend();
	std::reverse_iterator<CIterator<const std::string>> rbegin() const;
	std::reverse_iterator<CIterator<const std::string>> rend() const;
	std::reverse_iterator<CIterator<const std::string>> crbegin() const;
	std::reverse_iterator<CIterator<const std::string>> crend() const;

	std::string const & GetBackElement() const;
	std::string const & GetFrontElement() const;

private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node * m_lastNode = nullptr;
};