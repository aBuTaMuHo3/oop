#include "stdafx.h"
#include "StringList.h"
#include "Iterator.h"
using namespace std;

CStringList::CStringList()
{
	m_firstNode = make_unique<Node>("", nullptr, nullptr);
	m_firstNode->next = make_unique<Node>("", m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
	m_size = 0;
}

CStringList::CStringList(CStringList & list)
	:CStringList()
{
	for (auto const & data : list)
	{
		Append(data);
	}
}

CStringList::CStringList(CStringList && list)
	:CStringList()
{
	swap(m_firstNode, list.m_firstNode);
	swap(m_lastNode, list.m_lastNode);
	swap(m_size, list.m_size);
}

CStringList::~CStringList()
{
	Clear();
}

CIterator<string> CStringList::begin()
{
	return m_firstNode->next.get();
}

CIterator<const string> CStringList::begin() const
{
	return m_firstNode->next.get();
}

CIterator<string> CStringList::end()
{
	return m_lastNode;
}

CIterator<const string> CStringList::end() const
{
	return m_lastNode;
}

CIterator<const string> CStringList::cbegin() const
{
	return m_firstNode->next.get();
}

CIterator<const string> CStringList::cend() const
{
	return m_lastNode;
}


reverse_iterator<CIterator<string>> CStringList::rbegin()
{
	return reverse_iterator<CIterator<string>>(m_lastNode);
}

reverse_iterator<CIterator<const string>> CStringList::rbegin() const
{
	return reverse_iterator<CIterator<const string>>(m_lastNode);
}

reverse_iterator<CIterator<string>> CStringList::rend()
{
	return reverse_iterator<CIterator<string>>(m_firstNode->next.get());
}

reverse_iterator<CIterator<const string>> CStringList::rend() const
{
	return reverse_iterator<CIterator<const string>>(m_firstNode->next.get());
}

reverse_iterator<CIterator<const string>> CStringList::crbegin() const
{
	return reverse_iterator<CIterator<const string>>(m_lastNode);
}

reverse_iterator<CIterator<const string>> CStringList::crend() const
{
	return reverse_iterator<CIterator<const string>>(m_firstNode->next.get());
}

size_t CStringList::GetSize() const
{
	return m_size;
}

bool CStringList::IsEmpty() const
{
	return (m_size == 0);
}

void CStringList::Append(string const & data)
{
	Insert(end(), data);
}

void CStringList::PushFront(string const & data)
{
	Insert(begin(), data);
}

void CStringList::Insert(const CIterator<std::string> & it, const string & data)
	{
		unique_ptr<Node> newNode = make_unique<Node>(data, it.m_node->prev, move(it.m_node->prev->next));
		it.m_node->prev = newNode.get();
		newNode->prev->next = move(newNode);
		m_size++;
	}



void CStringList::Erase(const CIterator<std::string> & it)
{
	if (m_size == 0)
	{
		throw std::out_of_range("List is empty");
	}
	else if (it == end())
	{
		throw std::runtime_error("Unable to erase end iterator");
	}
	it.m_node->next->prev = it.m_node->prev;
	it.m_node->prev->next = std::move(it.m_node->next);
	m_size--;
}


string const & CStringList::GetBackElement() const
{
	return m_lastNode->prev->data;
}

string const & CStringList::GetFrontElement() const
{
	return m_firstNode->next->data;
}

void CStringList::Clear()
{
	if (m_size == 0)
	{
		return;
	}
	while (m_firstNode->next->next.get())
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_lastNode = m_firstNode->next.get();
	m_lastNode->data = "";
	m_size = 0;
}