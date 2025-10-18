#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

		//class LIST
class SingleList{
	private:
		//Node
		struct Node {
			int val;
			Node* next;
				//ctor
			Node(int _val = 0, Node* _next = nullptr) : val{_val}, next{_next} {}
		};
		Node* head;
		void copy(const SingleList& rhs);
		void clear();

	public:
		//Constructors
		SingleList();
		SingleList(size_t count, int val);
		SingleList(std::initializer_list<int> list);
		SingleList(const SingleList& rhs);
		SingleList& operator=(const SingleList& rhs);
		SingleList(SingleList&& rhs);
		SingleList& operator=(SingleList&& rhs);
		~SingleList();

		//Operator Overloading
		friend SingleList operator+(SingleList lhs, SingleList rhs);
		SingleList& operator+=(SingleList rhs);
		friend bool operator==(const SingleList& lhs, const SingleList& rhs);
		friend bool operator!=(const SingleList& lhs, const SingleList& rhs);
		int& operator[](size_t index);
		friend std::ostream& operator<<(std::ostream& ost, const SingleList& obj);
		friend std::istream& operator>>(std::istream& ist, SingleList& obj);
		bool operator!() const;
		SingleList& operator++();
		SingleList operator++(int);
		SingleList& operator--();
		SingleList operator--(int);

		// Member Functions 
		void push_front(int );
		void push_back(int );
		void pop_front();
		void pop_back();
		size_t size() const;
};

#endif
