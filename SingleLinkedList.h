

#ifndef PROJECT_SINGLELINKEDLIST_H
#define PROJECT_SINGLELINKEDLIST_H

#include <iostream>
#include <memory>
#include <fstream>
#include "Exceptions.h"
#include<cstring>
#include <sstream>

/**
 * struct Node.
 * Represent a node of the single linked list.
 */
template<class T>
struct Node {
	//! data of the Node.
	T data;

	//! pointer to the next node.
	std::shared_ptr<Node> next{};

	//! default constructor
	Node() = default;

	//!One Argument Constructor that assigns the Node data.
	//!@param _data Node data.
	explicit Node(T _data) {
		data = _data;
	}

};


//! Single linked list iterator
template<class T>
class S_Iterator {
public:
	//! Default constructor.
	S_Iterator() = default;


	//! Constructor that assigns the current Node.
	//! @param ptr Node pointer.
	S_Iterator(std::shared_ptr<Node<T>> ptr) : Current_Node(ptr) {};

	//!Pre-increment operator
	//! Increments the operator and returns the reference to the result
	//! @return reference to the result
	S_Iterator &operator++() {
		this->Current_Node = Current_Node->next;
		return *this;
	}

	//!Post-increment operator
	//! Increments the operator and returns the iterator before the incrementation
	//! @return old iterator

	S_Iterator operator++(int) {
		return ++(*this);
	}

	//!operator +
	//! Advances the operator and returns the reference of the result
	//! @return reference to the result
	S_Iterator operator+(int i) {
		while (i != 0) { ;
			(*this)++;
			i--;
		}
		return *this;
	}

	//!comparison operator.
	//!@param iterator the iterator to compare with.
	//! @return True id the iterators are different, otherwise false
	bool operator!=(const S_Iterator<T> &iterator) {
		return Current_Node != iterator.Current_Node;
	}

	//!comparison operator.
	//!@param iterator the iterator to compare with.
	//! @return True id the iterators are different, otherwise false

	bool operator==(const S_Iterator<T> &iterator) {
		return Current_Node == iterator.Current_Node;
	}
	//!Square bracket operator.
	//!@param index index of the element starting from where the iterator is pointing to.
	//! @return reference to the data

	T &operator[](int index) {
		auto tmp = Current_Node;
		while (index != 0) {
			tmp = tmp->m_nextNode;
			index--;
		}
		return *tmp->m_data;
	}

	//! Dereference operator.
	//! @return The data of the element at which the iterator is pointing to.
	T &operator*() { return Current_Node->data; }

	//! Pointer operator
	//! @return Pointer to T
	T *operator->() { return &Current_Node->data; } // returns the address to this data

private:
	std::shared_ptr<Node<T>> Current_Node;//!< Pointer to the Current Node.
};

//!Single Linked list class.
template<class T>
class SingleLinkedList {


	int SIZE{};//! Size of the list.
	std::shared_ptr<Node<T>> head{};//!< Pointer to the head of the list.

public:

	typedef S_Iterator<T> Iterator;

	//!<Begin Iterator.
	Iterator begin() { return Iterator(head); }

	//!<End Iterator.
	Iterator end() { return Iterator(nullptr); }


public:

	//!Output stream operator
	//!The operator is used to output the elements of the either to Console or to an output file
	//!@param os std::ostream
	//!@param s Single linked list Object
	//!@return std::ostream
	template<class s_type>
	friend std::ostream &operator<<(std::ostream &os, const SingleLinkedList<s_type> &s);

	//!Input stream operator.
	//!The operator is used to read the elements of the list either to Console or to an output file.
	//!@param is std::istream.
	//!@param s Single linked list Object.
	//!@return std::istream.
	template<class s_type>
	friend std::istream &operator>>(std::istream &input, SingleLinkedList<s_type> &s);

	//!Default constructor.
	//!Setting the head to a Null-pointer When the list is created.
	SingleLinkedList();

	//!
	//!
	SingleLinkedList(std::initializer_list<T> init) {
		for (auto x: init)
			push_back(x);
	};

	//!Copy constructor.
	//!@param s A single linked list to copy from.
	SingleLinkedList(SingleLinkedList<T> &);


	//!Move constructor.
	//!@param s A single linked list to Move from.
	SingleLinkedList(SingleLinkedList<T> &&) noexcept;


	//!Copy operator.
	//!@param other A single linked list to copy from.
	SingleLinkedList &operator=(const SingleLinkedList<T> &);


	//!Move operator.
	//!@param other A single linked list to Move from.
	SingleLinkedList &operator=(SingleLinkedList<T> &&);

	//!Square Bracket operator.
	//!@param index The index of the element.
	T &operator[](int index) {
		auto tmp = head;
		while (index) {
			tmp = tmp->next;
			index--;
		}
		return tmp->data;
	}

	//!Function that return the size of a the list.
	//!@return The size of the list.
	int size() { return SIZE; }

	//!Push_back.
	//!Adding a new node at the the end of the list.
	//!@param data The element to add.
	void push_back(T data);

	//!Push_front.
	//!Adding a new node at the the beginning of the list.
	//!@param data The element to add.
	void push_front(T data);


	//!Pop_Front.
	//!Deleting the node at the beginning of the list.
	void pop_front();

	//!Pop_Front.
	//!Deleting the node at the the end of the list.
	void pop_back();

	//!Function that deletes a node at a certain index.
	//!@param position Index od the element to be deleted.
	void deleteByNode(int position);

	//!Function that inserts a node at a certain index.
	//!@param position The Position where to add the element.
	//!@param data The element to be added.
	void insert(T data, int pos);

	//!Function the filters the list by data.
	//!@param _data Element to be deleted.
	void deleteByData(T _data);

	//!Function that prints the elements of the list.
	void print();

	//!Search function.
	//!@param _data The element to search.
	//!@return Returns true if the element exists, otherwise false.
	bool search(T _data);

	//!Sort function.
	//!Sorts the elements of the list using Bubble sort algorithm.
	void sort();

	//!Function that deletes all the elements of the list.
	void clear();

	//!Serialize function.
	//!stores data in binary format
	//!@param filename


	void serialize(const std::string &filename);

	//!Deserialize function.
	//!reads data in binary format
	//!@param filename
	void deserialize(const std::string &filename);

};


template<class T>
SingleLinkedList<T>::SingleLinkedList() {
	std::cout << "Single linked list is created\n";
	head = nullptr;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList<T> &s) {

	auto n = s.head;
	while (n != nullptr) {
		push_back(n->data);
		n = n->next;
	}
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList<T> &&s) noexcept {
	head = std::move(s.head);
	SIZE = std::move(s.SIZE);
	s.SIZE = 0;
}


template<class T>
SingleLinkedList<T> &SingleLinkedList<T>::operator=(const SingleLinkedList<T> &other) {

	if (this != &other) {
		auto n = other.head;
		while (n != nullptr) {
			push_back(n->data);
			n = n->next;
		}
	}
	return *this;
}

template<class T>

SingleLinkedList<T> &SingleLinkedList<T>::operator=(SingleLinkedList<T> &&other) {
	if (this != &other) {
		head = std::move(other.head);
		SIZE = std::move(other.SIZE);
		other.SIZE = 0;
	}
	return *this;
}


template<class T>
void SingleLinkedList<T>::push_back(T data) {

	auto n = std::make_shared<Node<T>>(data);

	if (head == NULL) {
		head = n;
		SIZE++;
	} else {
		std::shared_ptr<Node<T>> tmp_ptr = head;
		while (tmp_ptr->next != NULL) {
			tmp_ptr = tmp_ptr->next;
		}
		tmp_ptr->next = n;
		SIZE++;
	}

}

template<class T>
void SingleLinkedList<T>::push_front(T data) {

	auto n = std::make_shared<Node<T>>(data);

	if (head == NULL) {
		head = n;
		SIZE++;
	} else {
		n->next = head;
		head = n;
		SIZE++;

	}


}


template<class T>
void SingleLinkedList<T>::print() {
	auto tmp = head;
	std::cout << "The elements of the list:\n";
	while (tmp != NULL) {
		std::cout << "Data: " << tmp->data << "\n";
		tmp = tmp->next;
	}
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const SingleLinkedList<T> &s) {
	{
		auto tmp = s.head;
		std::cout << "The elements of the list:\n";
		while (tmp != NULL) {
			os << "Data: " << tmp->data << "\n";
			tmp = tmp->next;
		}
		return os;
	}
}

template<class T>
void SingleLinkedList<T>::pop_front() {
	if (head == NULL) {
		std::cout << "The container is already empty\n";
	} else {
		head = head->next;
		SIZE--;
	}
}


template<class T>
void SingleLinkedList<T>::pop_back() {

	if (head == NULL) {
		std::cout << "The container is already empty\n";
	} else {
		auto tmp = head;
		std::shared_ptr<Node<T>> prev_node;
		while (tmp->next != NULL) {
			prev_node = tmp;
			tmp = tmp->next;
		}
		prev_node->next = NULL;
		SIZE--;

	}
}

template<class T>
void SingleLinkedList<T>::deleteByNode(int position) {
	if (position ==0){
		pop_front();
		return;
	}

	if (head == NULL) {
		std::cout << "The container is already empty (Nothing to delete)\n";
	} else {

		auto tmp = head;
		std::shared_ptr<Node<T>> prev_node;
		while (position != 0) {
			prev_node = tmp;
			tmp = tmp->next;
			position--;
		}
		prev_node->next = tmp->next;
		SIZE--;
	}
}

template<class T>
void SingleLinkedList<T>::deleteByData(T _data) {

	while (head->data==_data){
		head=head->next;
		SIZE--;
	}
	auto tmp = head;
	std::shared_ptr<Node<T>> prev_node;

	while (tmp != NULL) {
		if (tmp->data == _data) {
			prev_node->next = tmp->next;
			tmp = tmp->next;
			SIZE--;
		} else {
			prev_node = tmp;
			tmp = tmp->next;
		}

	}
}

template<class T>
void SingleLinkedList<T>::insert(T data, int pos) {

	if (pos ==0){
		push_front(data);
		return;
	}

	if (pos ==SIZE){
		push_back(data);
		return;
	}


	auto tmp = head;
	auto n = std::make_shared<Node<T>>(data);
	if (pos < 0 || pos > SIZE) {
		throw OutOfRange(pos);
	} else {
		while ((pos -1)  != 0) {
			tmp = tmp->next;
			pos--;
		}

		n->next = tmp;
		tmp->next = n;
		SIZE++;
	}
}

template<class T>
std::istream &operator>>(std::istream &is, SingleLinkedList<T> &s) {
	T tmp;
	while (is >> tmp) {
		s.push_back(tmp);
		s.SIZE++;
	}
	return is;
}

template<class T>
void SingleLinkedList<T>::clear() {
	head = NULL;
	SIZE = 0;
}

template<class T>
void SingleLinkedList<T>::sort() {
	if (head == NULL) {
		return;
	}
	auto tmp = head;
	bool swapped = true;
	while (swapped) {
		swapped = false;
		while (tmp->next != NULL) {

			if (tmp->data > tmp->next->data) {
				std::swap(tmp->data, tmp->next->data);
				swapped = true;
			}
			tmp = tmp->next;

		}
		tmp = head;
	}
}

template<>
inline void SingleLinkedList<std::string>::sort() {
	if (head == nullptr) {
		return;
	}
	auto tmp = head;
	bool swapped = true;
	while (swapped) {
		swapped = false;
		while (tmp->next != nullptr) {

			if (tmp->data.length() > tmp->next->data.length()) {
				std::swap(tmp->data, tmp->next->data);
				swapped = true;
			}
			tmp = tmp->next;

		}
		tmp = head;
	}
}

template<class T>
bool SingleLinkedList<T>::search(T _data) {
	auto tmp = head;
	while (tmp != nullptr) {
		if (tmp->data == _data) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;

}

template<class T>
void SingleLinkedList<T>::serialize(const std::string &filename) {
	std::ofstream OutFile(filename,
						  std::ios::out | std::ios::binary);
	if (OutFile) {
		for (const auto &e: *this) {
			std::stringstream ss;
			ss<<e;
			std::string s(ss.str());
			size_t length =s.length();

			OutFile.write((char *)&length, sizeof(length));
			OutFile.write((char *) s.data(), sizeof(char)*length);
		}
		OutFile.close();
	}

}



template<class T>
void SingleLinkedList<T>::deserialize(const std::string &filename) {
	std::ifstream InFile(filename, std::ios::in | std::ios::binary);
	//
	if (InFile) {

		size_t length;

		while (InFile.read((char *) &length, sizeof(length))) {
			T tmp;
			std::stringstream ss;
			std::string s;
			for (size_t i=0;i<length; i++){
				s+=InFile.get();
			}
			ss<<s;
			ss>>tmp;
			push_back(tmp);
		}
		InFile.close();

	}
}


#endif //PROJECT_SINGLELINKEDLIST_H
