#pragma once

template<typename T>
class CListNode {
private :
	CListNode() :
		next(NULL),
		prev(NULL)
	{

	}
	~CListNode() { }

private:
	template<typename T>
	friend class CLinkedList;

private:
	T data;
	CListNode<T>* next;
	CListNode<T>* prev;
};

template<typename T>
class CLinkedList
{
public:
	CLinkedList() {
		begin = new NODE;
		end = new NODE;

		begin->next = end;
		end->prev = begin;

		size = 0;
	}

	~CLinkedList() { }

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE begin;
	PNODE end;
	unsigned int size;

public:
	void push_back(const T& data) {
		PNODE node = new NODE;
		node->data = data;

		node->prev = end->prev;
		node->next = end;

		end->prev->next = node;
		end->prev = node;

		size++;
	}

	void push_front(const T& data) {
		PNODE node = new NODE;
		node->data = data;

		node->prev = begin;
		node->next = begin->next;

		begin->next->prev = node;
		begin->next = node;

		size++;
	}

	void clear() {
		PNODE node = begin->next;

		while (node != end) {
			PNODE temp = node->next;
			delete node;
			node = temp;
		}
		begin->next = end;
		end->prev = begin;

		size = 0;
	}

	bool isEmpty() const { return size == 0; }
	int getSize() const { return size; }
};

