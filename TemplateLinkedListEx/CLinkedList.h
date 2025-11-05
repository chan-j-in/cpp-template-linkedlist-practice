#pragma once

template<typename T>
class CListNode {
private :
	CListNode() :
		next(nullptr),
		prev(nullptr)
	{

	}
	~CListNode() { }

private:
	template<typename U>
	friend class CLinkedList;
	template<typename U>
	friend class CListIterator;
	template<typename U>
	friend class CReverseIterator;

private:
	T data;
	CListNode<T>* next;
	CListNode<T>* prev;
};

template<typename T>
class CListIterator {
public:
	CListIterator(){ }
	~CListIterator(){ }

private:
	template<typename U>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE node;

public:
	bool operator ==(const CListIterator& iter) {
		return node == iter.node;
	}
	bool operator !=(const CListIterator& iter) {
		return node != iter.node;
	}

	void operator ++() {
		node = node->next;
	}
	void operator --() {
		node = node->prev;
	}
	const T& operator *() {
		return node->data;
	}
};

template<typename T>
class CReverseIterator {
public:
	CReverseIterator() { }
	~CReverseIterator() { }

private:
	template<typename U>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE node;

public:
	bool operator ==(const CReverseIterator& iter) {
		return node == iter.node;
	}
	bool operator !=(const CReverseIterator& iter) {
		return node != iter.node;
	}

	void operator ++() {
		node = node->prev;
	}
	void operator --() {
		node = node->next;
	}
	const T& operator *() {
		return node->data;
	}
};

template<typename T>
class CLinkedList
{
public:
	CLinkedList() {
		head = new NODE;
		tail = new NODE;

		head->next = tail;
		tail->prev = head;

		size = 0;
	}

	~CLinkedList() {
		clear();
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

private:
	template<typename U>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;
	typedef CReverseIterator<T> riterator;

private:
	PNODE head;
	PNODE tail;
	unsigned int size;

public:
	void push_back(const T& data) {
		PNODE node = new NODE;
		node->data = data;

		node->prev = tail->prev;
		node->next = tail;

		tail->prev->next = node;
		tail->prev = node;

		size++;
	}

	void push_front(const T& data) {
		PNODE node = new NODE;
		node->data = data;

		node->prev = head;
		node->next = head->next;

		head->next->prev = node;
		head->next = node;

		size++;
	}

	iterator begin() {
		iterator iter;
		iter.node = head->next;
		return iter;
	}

	iterator end() {
		iterator iter;
		iter.node = tail;
		return iter;
	}

	riterator rbegin() {
		riterator riter;
		riter.node = tail->prev;
		return riter;
	}

	riterator rend() {
		riterator riter;
		riter.node = head;
		return riter;
	}


	void clear() {
		PNODE node = head->next;

		while (node != tail) {
			PNODE temp = node->next;
			delete node;
			node = temp;
		}
		head->next = tail;
		tail->prev = head;

		size = 0;
	}

	bool isEmpty() const { return size == 0; }
	int getSize() const { return size; }
};

