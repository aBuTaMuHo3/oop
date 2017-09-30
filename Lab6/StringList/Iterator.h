#pragma once
#include "stdafx.h" 
#include "StringList.h"
#include <string>
#include <memory>
class Node
{
public:
	Node::Node(std::string const & data, Node * prev, std::unique_ptr<Node> && next)
		:data(data)
		, prev(prev)
		, next(std::move(next))
	{
	}
	//Node(std::string const & data, Node * prev, std::unique_ptr<Node> && next);
	std::string data;
	Node * prev;
	std::unique_ptr<Node> next;
};

template <typename ValueType>
class CIterator : public std::iterator<std::bidirectional_iterator_tag, ValueType>
{
public:
	CIterator() = default;

	CIterator(Node * node)
		: m_node(node)
	{
	}

	bool operator==(CIterator const& other) const
	{
		return m_node == other.m_node;
	}

	bool operator!=(CIterator const& other) const
	{
		return !(m_node == other.m_node);
	}

	typename reference operator*() const
	{
		if (m_node != nullptr && m_node->next != nullptr && m_node->prev != nullptr)
		{
			return m_node->data;
		}
		else
		{
			throw std::runtime_error("Can't get value of this iterator");
		}
	}

	CIterator& operator++()
	{
		if (m_node != nullptr && m_node->next != nullptr)
		{
			m_node = m_node->next.get();
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
		return *this;
	}

	CIterator& operator--()
	{
		if (m_node != nullptr && m_node->prev != nullptr)
		{
			m_node = m_node->prev;
		}
		else
		{
			throw std::out_of_range("Can't get decrement of this iterator");
		}
		return *this;
	}

	CIterator operator++(int)
	{
		CIterator tmp = *this;
		++*this;
		return tmp;
	}

	CIterator operator--(int)
	{
		CIterator tmp = *this;
		--*this;
		return tmp;
	}

	pointer operator->()const
	{
		return std::pointer_traits<pointer>::pointer_to(**this);
	}
private:
	Node* m_node = nullptr;
	friend class CStringList;
};