#include "stdafx.h"
#include "MyList.h"

CMyList::Node::Node(std::string const & data, Node * prev, std::unique_ptr<Node> && next)
	:data(data)
	, prev(prev)
	, next(std::move(next))
{
}

CMyList::CIterator::CIterator(Node * node)
	:m_node(node)
{
}

CMyList::CIterator::CIterator(Node * node, bool isReverse)
	: m_node(node)
	, m_isReverse(isReverse)
{
}


CMyList::CMyList(CMyList const & list)
{
	CMyList tmp;
	for (auto const & data : list)
	{
		Append(data);
	}
	std::swap(m_firstNode, tmp.m_firstNode);
	std::swap(m_lastNode, tmp.m_lastNode);
	m_size = tmp.m_size;
}

CMyList::CMyList(CMyList && list)
{
	m_size = list.m_size;
	m_firstNode = std::move(list.m_firstNode);
	m_lastNode = std::move(list.m_lastNode);

	list.m_size = 0;
}

CMyList::~CMyList()
{
	Clear();
}

bool CMyList::CIterator::operator==(CMyList::CIterator const & rhs) const
{
	return (m_node == rhs.m_node && m_isReverse == rhs.m_isReverse);
}

bool CMyList::CIterator::operator!=(CMyList::CIterator const & rhs) const
{
	return (m_node != rhs.m_node && m_isReverse != rhs.m_isReverse);
}

CMyList::CIterator & CMyList::CIterator::operator--()
{
	m_node = (!m_isReverse) ? (m_node->prev) : (m_node->next.get());
	return *this;
}

CMyList::CIterator & CMyList::CIterator::operator++()
{
	m_node = (!m_isReverse) ? (m_node->next.get()) : (m_node->prev);
	return *this;
}

CMyList::CIterator CMyList::CIterator::operator--(int)
{
	auto temp = *this;
	--*this;
	return temp;
}

CMyList::CIterator CMyList::CIterator::operator++(int)
{
	auto temp = *this;
	++*this;
	return temp;
}

std::string & CMyList::CIterator::operator*() const
{
	return m_node->data;
}

CMyList::Node * CMyList::CIterator::operator->() const
{
	return m_node;
}

CMyList::CIterator CMyList::begin()
{
	return CIterator(m_firstNode.get());
}

CMyList::CIterator CMyList::end()
{
	return (m_size == 0) ? begin() : CIterator(m_lastNode);
}

CMyList::CIterator const CMyList::begin() const
{
	return CIterator(m_firstNode.get());
}

CMyList::CIterator const CMyList::end() const
{
	return (m_size == 0) ? cbegin() : CIterator(m_lastNode);
}

CMyList::CIterator const CMyList::cbegin() const
{
	return CIterator(m_firstNode.get());
}

CMyList::CIterator const CMyList::cend() const
{
	return (m_size == 0) ? cbegin() : CIterator(m_lastNode);
}

CMyList::CIterator CMyList::rbegin()
{
	return CIterator(m_lastNode, true);
}

CMyList::CIterator CMyList::rend()
{
	return (m_size == 0) ? rbegin() : CIterator(m_firstNode.get(), true);
}

CMyList::CIterator const CMyList::rbegin() const
{
	return CIterator(m_lastNode, true);
}

CMyList::CIterator const CMyList::rend() const
{
	return (m_size == 0) ? rbegin() : CIterator(m_firstNode.get(), true);
}


CMyList::CIterator const CMyList::crbegin() const
{
	return CIterator(m_lastNode, true);
}

CMyList::CIterator const CMyList::crend() const
{
	return (m_size == 0) ? crbegin() : CIterator(m_firstNode.get(), true);
}

size_t CMyList::GetSize() const
{
	return m_size;
}

bool CMyList::IsEmpty() const
{
	return (m_size == 0);
}

void CMyList::Append(std::string const & data)
{
	auto newNode = std::make_unique<Node>(data, m_lastNode, nullptr);
	auto * newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = move(newNode);
	}
	else
	{
		m_firstNode = move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

void CMyList::PushFront(std::string const & data)
{
	auto newNode = std::make_unique<Node>(data, nullptr, move(m_firstNode));
	if (newNode->next)
	{
		newNode->next->prev = newNode.get();
	}
	else
	{
		m_lastNode = newNode.get();
	}
	m_firstNode = std::move(newNode);
	++m_size;
}

void CMyList::Insert(CIterator const  & it, std::string const & data)
{
	if (it == begin())
	{
		PushFront(data);
	}
	else if (it == end())
	{
		Append(data);
	}
	else
	{
		auto node = std::make_unique<CMyList::Node>(data, it->prev, move(it->prev->next));
		it->prev = std::move(node.get());
		node->prev->next = move(node);
		++m_size;
	}
}

void CMyList::Erase(CIterator const & it)
{
	if (m_size != 0)
	{
		if (m_size == 1)
		{
			Clear();
			return;
		}

		if (it == begin())
		{
			m_firstNode = std::move(m_firstNode->next);
			m_firstNode->prev = nullptr;
		}
		else if (it.m_node == m_lastNode)
		{
			m_lastNode = std::move(it->prev);
			m_lastNode->next = nullptr;
		}
		else
		{
			it->next->prev = std::move(it->prev);
			it->prev->next = std::move(it->next);
		}

		--m_size;

	}
	else
	{
		throw std::out_of_range("StringList is already empty");
	}
}

std::string const & CMyList::GetBackElement() const
{
	return m_lastNode->data;
}

std::string const & CMyList::GetFrontElement() const
{
	return m_firstNode->data;
}

void CMyList::Clear()
{
	m_lastNode = nullptr;
	m_firstNode = nullptr;
	m_size = 0;
}