#include <iostream>
#include "SingleList.hpp"

		//Constructors & Destructor
//helper
void SingleList::copy(const SingleList& rhs) {
	if (this == &rhs) return;

		const Node *tmp = rhs.head;
		Node dummy;
		Node *d = &dummy;
		while(tmp) {
				d->next = new Node(tmp->val);
				d = d->next;
				tmp = tmp->next;
		}
		head = dummy.next;
}

//delete
void SingleList::clear() {
		while(head) {
				Node *tmp = head;
				head = head->next;
				delete tmp;
		}
}

//default ctor
SingleList::SingleList() : head{nullptr} {}

//Param constructor
SingleList::SingleList(size_t count, int val) {
	Node dummy;
	Node *tmp = &dummy;
	while(count--) {
			tmp->next = new Node(val);
			tmp = tmp->next;
	}
	this->head = dummy.next;
}

//Initializer list constructor
SingleList::SingleList(std::initializer_list<int> list) {
	Node dummy;
	Node* tmp = &dummy;
	for(int x : list) {
			tmp->next = new Node(x);
			tmp = tmp->next;
	}
	this->head = dummy.next;
}

//Copy constructor
SingleList::SingleList(const SingleList& rhs) {
	copy(rhs);
}

//dtor
SingleList::~SingleList(){clear(); }

	//Copy assignment operator
SingleList& SingleList::operator=(const SingleList& rhs) {
	if (this == &rhs) return *this;
	clear();
	copy(rhs);
	return *this;
}

//Move constructor
SingleList::SingleList(SingleList&& rhs) : head{rhs.head} {
		rhs.head = nullptr;
}

	//Move assignment operator
SingleList& SingleList::operator=(SingleList&& rhs) {
	if (this == &rhs) return *this;

	clear();
	head = rhs.head;
	rhs.head = nullptr;
	return *this;
}

		//Operator Overloading
//+ Concatenate two lists → return a new list
SingleList operator+(SingleList lhs, SingleList rhs) {
	using Node = SingleList::Node;

	if(!lhs.head) return rhs;
	Node *tmp = lhs.head;
	while(tmp->next) tmp = tmp->next;

	tmp->next = rhs.head;
	rhs.head = nullptr;
	return lhs;
}

//+= Append another list to the current list
SingleList& SingleList::operator+=(SingleList rhs) {
		if(!head) {
				head = rhs.head;
				rhs.head = nullptr;
				return *this;
		}
		Node *tmp = head;
		while(tmp->next) tmp = tmp->next;
		tmp->next = rhs.head;
		rhs.head = nullptr;
		return *this;
}

//== Compare two lists (true if same size and elements)
bool operator==(const SingleList& lhs, const SingleList& rhs) {
	using Node = SingleList::Node;

	Node *tmp1 = lhs.head;
	Node *tmp2 = rhs.head;

	while(tmp1 && tmp2) {
			if(tmp1->val != tmp2->val) return false;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
	}
	return tmp1 == nullptr && tmp2 == nullptr;
}

//!= Negation of ==
bool operator!=(const SingleList& lhs, const SingleList& rhs) {
		return !(lhs == rhs);
}

//[] Access element by index (read/write)
int& SingleList::operator[](size_t index) {
		Node *tmp = head;
		for(size_t i{0}; i < index; ++i) {
				if (!tmp) std::exit(EXIT_FAILURE);
				tmp = tmp->next;
		}
		return tmp->val;
}

//<< Print list elements (e.g., [1, 2, 3])
std::ostream& operator<<(std::ostream& ost, const SingleList& obj) {
		using Node = SingleList::Node;

		Node *tmp = obj.head;
		ost << "[";
		while(tmp) {
				ost << tmp->val << " ";
				tmp = tmp->next;
		}
		ost << "]";
		return ost;
}

//>> Input elements from cin
std::istream& operator>>(std::istream& ist, SingleList& obj) {
		using Node = SingleList::Node;

		obj.clear();
		
		std::cout << "Enter elements of List(ctrl + d for quit): ";
		Node dummy;
		Node* tmp = &dummy;

		int val{};
		while (ist >> val) {
			tmp->next = new Node(val);
			tmp = tmp->next;
		}

		obj.head = dummy.next;
		return ist;	
}

//! Return true if the list is empty
bool SingleList::operator!() const {
		return !head;
}

//++prefix
SingleList& SingleList::operator++() {
	if(!head) {
			head = new Node;
			return *this;
	}

	Node *tmp = head;
	while(tmp->next) tmp = tmp->next;
	tmp->next = new Node;

	return *this;
}

//++postfix
SingleList SingleList::operator++(int) {
	SingleList tmp = *this;
	++(*this);
	return tmp;
}

//--prefix
SingleList& SingleList::operator--() {
		if(!head) return *this;

		if(!head->next) {
			delete head;
			head = nullptr;
			return *this;
		} 

		Node *tmp = head;
		while(tmp->next->next) tmp = tmp->next;
		delete tmp->next;
		tmp->next = nullptr;

		return *this;
}

//-- postfix
SingleList SingleList::operator--(int) {
		SingleList tmp = *this;
		--(*this);
		return tmp;
}

		//Member Functions
//push_front(int)
void SingleList::push_front(int val) {
		head = new Node(val, head);
}

//push_back(int)
void SingleList::push_back(int val) {
		if(!head) {
				head = new Node(val);
				return;
		}

		Node *tmp = head;
		while(tmp->next) tmp = tmp->next;
		tmp->next = new Node(val);
}

//pop_front()
void SingleList::pop_front() {
		if(!head) return;

		Node *tmp = head;
		head = head->next;
		delete tmp;
}

void SingleList::pop_back() {
		if (!head) return;

		if(!head->next) {
				delete head;
				head = nullptr;
				return;
		}

		Node *tmp = head;
		while(tmp->next->next) tmp = tmp->next;
		delete tmp->next;
		tmp->next = nullptr;
}

//size() return the number of elements
size_t SingleList::size() const{
		size_t count{0};
		Node *tmp = head;
		while(tmp) {
				++count;
				tmp = tmp->next;
		}
		return count;
}











