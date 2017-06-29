#ifndef __NODE__
#define __NODE__

template <typename T>
class Node{
	public:
		Node();
		Node(T);

		Node* dir;
		Node* esq;
		T info;
};

#endif
