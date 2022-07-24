//
// Created by youssef albali on 29-Dec-21.
//

#include <memory>
#include<algorithm>
#include <utility>

#include "SingleLinkedList.h"


struct Student {
	int age{};
	std::string name;
	double grade{};

	Student() = default;

	Student(int _age, std::string _name, double _grade) {
		age = _age;
		name = _name;
		grade = _grade;
	}

	~Student() = default;
	friend std::ostream &operator<<(std::ostream &os, const Student &st){
		os<<"Name: "<<st.name<<" Age: "<<st.age<<" Grade: "<<st.grade;
		return os;
	}

	friend std::istream &operator>>(std::istream &is, Student &st){
		std::string tmp;
		is>>tmp>>st.name>>tmp>>st.age>>tmp>>st.grade;
		return is;

	}


	bool operator>(Student &st) const {
		return grade > st.grade;
	}
};



int main() {




	SingleLinkedList<int> s_int{1, 1, 54, 1, 202};
	s_int.insert(21,1);
	s_int.insert(5,6);
	s_int.deleteByNode(0);
	s_int.deleteByData(1);


	s_int.push_back(3);
	s_int.push_back(5);


	s_int.push_front(100);
	s_int.push_front(258);


	s_int.insert(5, 1);

	s_int.push_back(5);

	s_int.clear();


	s_int.push_front(44);
	s_int.push_front(14);
	s_int.push_front(5);
	s_int.push_front(7);
	s_int.insert(5, 4);
	s_int.push_front(5);
	s_int.push_back(222);
	s_int.push_front(56);
	s_int.push_back(5);
	s_int.sort();
	s_int.push_front(66);


	//filters the list based on some data
	s_int.deleteByData(7);

	//Deletes a node at a certain index
	s_int.deleteByNode(2);


	std::cout << "List of integers before adding 1: " << s_int << "\n";
	std::for_each(s_int.begin(), s_int.end(), [](int &e) { e++; });
	std::cout << "List of integers after adding 1: " << s_int << "\n";


	auto its = s_int.begin();
	std::cout << "Printing the iterator begin + 2 :" << *(its + 2) << "\n";

	SingleLinkedList<int> s_int1 (s_int);


	std::cout << "List before serialization and desirialization: " << s_int1;

	s_int1.serialize("binary.bin");
	SingleLinkedList<int> s_des;
	s_des.deserialize("binary.bin");
	std::cout << "Deserialized List : " << s_des << "\n";


	std::cout << "list of integers before insert (100,2): " << s_int1 << "\n";

	//s_int1.insert(100, 2);
	std::cout << "list of integers after insert (100,2): " << s_int1 << "\n";
	std::cout << "list of integers Size: " << s_int1.size() << "\n";


	std::cout << "Printing using the output overload operator\n";
	std::cout << s_int1;
	std::cout << "=============================================================" << "\n\n";
	std::cout << "Printing using the Iterator\n";

	for (SingleLinkedList<int>::Iterator it = s_int1.begin(); it != s_int1.end(); it++) {
		std::cout << *it << " \n";
	}


	SingleLinkedList<std::string> s_names;
	s_names.push_back("Youssef");
	s_names.push_back("Michal");
	s_names.push_back("Viktor");
	s_names.push_back("Asser");
	s_names.push_back("hmd");
	s_names.push_back("Kamil");
	s_names.push_back("Moustafa");

	s_names.serialize("binary_string.bin");

	SingleLinkedList<std::string> names;
	names.deserialize("binary_string.bin");


	std::cout << "List of strings before  sorting  " << " " << s_names << std::endl;


	s_names.sort();
	std::cout << "List of strings after  sorting by length " << " " << s_names << std::endl;

	std::cout << "Asser in the list? " << " " << s_names.search("Asser") << std::endl;

	SingleLinkedList<std::string>::Iterator it2 = s_names.begin();
	std::cout << "Incrementing the iterator .begin() by 2 result: " << *(it2 + 2) << "\n";


	s_names.pop_front();

	s_names.pop_back();


	std::cout << "Printing names before deleting\n" << s_names << std::endl;
	s_names.deleteByNode(2);


	std::cout << "Printing names after deleting the second position\n" << s_names << std::endl;

	std::cout << "=============================================================" << "\n\n";

	SingleLinkedList<std::string> s_string_2;


	std::fstream inFile("input.txt");

	inFile >> s_string_2;


	auto it = s_string_2.begin();
	for (; it != s_string_2.end(); it++) {
		std::cout << *it << " \n";
	}

	std::ofstream outFile("output.txt");
	outFile << s_names;


	inFile.close();
	outFile.close();


	SingleLinkedList<Student> s_students{
			Student(19, "Youssef", 5.0),
			Student(18, "Andrii", 4.5),
			Student(30, "Asser", 3.5),
			Student(17, "Viktor", 5)
	};
	s_students.serialize("binary_struct.bin");

	SingleLinkedList<Student> students;
	students.deserialize("binary_struct.bin");


	s_students.sort();







	std::cout<<"Students before sorting: "<<std::endl;
	for (auto it=s_students.begin(); it!=s_students.end();it++){
		std::cout<<*it<<"\n";
	}

	std::cout<<"\n";
	std::cout<<"Students after sorting: "<<std::endl;

	for (auto it=s_students.begin(); it!=s_students.end();it++){
		std::cout<<*it<<"\n";
	}
	std::cout<<"\n";

}

