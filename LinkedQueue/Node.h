#ifndef NODE_H
#define NODE_H

template<class NodeEntry>
struct Node
{
public:
	// data members
	NodeEntry entry;
	Node *next;
	// constructors
	Node (const NodeEntry &entry, Node<NodeEntry> *next = nullptr);
	Node (const Node<NodeEntry> &node);
};

template<class NodeEntry>
Node<NodeEntry>::Node (const NodeEntry &entry, Node<NodeEntry> *next = nullptr)
{
	this->entry = entry;
	this->next = next;
}

template<class NodeEntry>
Node<NodeEntry>::Node (const Node<NodeEntry> &node)
{
	this->entry = node.entry;
	this->next = node.next;
}

#endif