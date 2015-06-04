#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"

enum ErrorCode
{
	SUCCESS, UNDERFLOW, OVERFLOW
};

template<class QueueEntry>
class LinkedQueue
{
public:
	LinkedQueue ();
	~LinkedQueue ();
	bool empty () const;
	size_t size () const;
	ErrorCode front (QueueEntry &item) const;
	ErrorCode push (const QueueEntry &item);
	ErrorCode pop ();
	void clear ();
protected:
	Node<QueueEntry> *_front = nullptr;
	Node<QueueEntry> *_rear = nullptr;
	size_t _count = 0;
};

template<class QueueEntry>
LinkedQueue<QueueEntry>::LinkedQueue ()
{
	_front = nullptr;
	_rear = nullptr;
	_count = 0;
}

template<class QueueEntry>
LinkedQueue<QueueEntry>::~LinkedQueue ()
{
	clear ();
}

template<class QueueEntry>
bool LinkedQueue<QueueEntry>::empty () const
{
	return _front == nullptr; // TODO: what if _rear != nullptr or _count != 0
}

template<class QueueEntry>
size_t LinkedQueue<QueueEntry>::size () const
{
	return _count;
}

template<class QueueEntry>
ErrorCode LinkedQueue<QueueEntry>::front (QueueEntry &item) const
{
	if (empty ())
		return UNDERFLOW;
	else {
		item = _front->entry;
		return SUCCESS;
	}
}

template<class QueueEntry>
ErrorCode LinkedQueue<QueueEntry>::push (const QueueEntry &item)
{
	Node<QueueEntry> *tmp = new Node<QueueEntry> (item);
	if (tmp == nullptr)
		return OVERFLOW;
	else {
		if (empty ())
			_front = tmp;
		else
			_rear->next = tmp;
		_rear = tmp;
		++_count;
		return SUCCESS;
	}
}

template<class QueueEntry>
ErrorCode LinkedQueue<QueueEntry>::pop ()
{
	if (empty ())
		return UNDERFLOW;
	else {
		Node<QueueEntry> *oldFront = _front;
		_front = _front->next;
		delete oldFront;
		--_count;
		return SUCCESS;
	}
}

template<class QueueEntry>
void LinkedQueue<QueueEntry>::clear ()
{
	while (!empty ())
		pop ();
}

#endif