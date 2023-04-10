# Custom-Singly-linked-list
The aim of the microproject is to implement a custom single linked list in the form
of a class with a convenient programming interface.

The class is implemented as a template, and an iterator that will allow
the use of STL is implemented as well.

Features:

usage of smart pointers,
default constructor,
copy / move constructors,
destructor,
assignment / move operators,
adding container elements,
searching for an element,
sorting content (different criteria),
serialization / deserialization (reading and writing from byte stream).

The class can be declared and initialized with different data types as the following:

![image](https://user-images.githubusercontent.com/72605819/230885415-f49981a4-0702-4f33-a44c-1f34127da623.png)


The class supports the following methods:

the push_back and push_front functions:
![image](https://user-images.githubusercontent.com/72605819/230885675-03e03eff-d57d-485c-b9a0-e949089890c4.png)


As well as the pop_back and pop_front methods:

![image](https://user-images.githubusercontent.com/72605819/230885699-9d21636d-6b29-4d56-a8e1-f3444e7e31cc.png)

Insert function:
![image](https://user-images.githubusercontent.com/72605819/230885753-6a61491c-d2e2-4529-bdd4-73a211a653e3.png)


Two delete functions (First one is deleting node based on Data so it’s more like filtering
and the second takes the position of the node as a parameter):
![image](https://user-images.githubusercontent.com/72605819/230886008-76e95414-08e6-4868-80f2-8c26c760c467.png)

Function that prints all the elements od the list and the overloaded output operator:
![image](https://user-images.githubusercontent.com/72605819/230885852-1aca61af-5034-4b76-8fca-d20bb665ce6e.png)

Input operator used to read data from a file:
![image](https://user-images.githubusercontent.com/72605819/230885881-98bf95a4-31de-42f7-85ca-5de1e567a696.png)

Search function:
![image](https://user-images.githubusercontent.com/72605819/230886057-f75f4199-9f03-4e26-84d3-cc35ca1ba1eb.png)

Clear function:
![image](https://user-images.githubusercontent.com/72605819/230886069-c1d9d437-865c-4ff7-a984-3e3ea216ca5c.png)

We can also sort the elements of the container in ascending order:
![image](https://user-images.githubusercontent.com/72605819/230886115-7563d049-bfc5-4cfc-b55e-a80a110e3a5d.png)

The container has also been tested using the “Student” class in order to
sort this type by grade.

![image](https://user-images.githubusercontent.com/72605819/230886186-0d62b97a-a1e2-499a-9736-055f58916f30.png)

And finally, a function that get the size of the list:

![image](https://user-images.githubusercontent.com/72605819/230886215-9041f9b0-08fe-4bc9-a5d6-10f65dd97869.png)

