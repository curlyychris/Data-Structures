
//Christy 18249 Assignment on Linked Lists
#include <iostream>
using namespace std;

//declaring the class FU_Student
class FU_Student {
public:
	char S_surn[15];
	char S_name[14];
	int S_reg_no;
	float S_gpa;
	int S_age;
	char S_addr[25];
	FU_Student* next;
};

class list {
	int count = 1;
public:
	FU_Student* first, * last;
	//constructor function 
	list()
	{
		first = NULL;
		last = NULL;
	}
	//function prototypes
	void cons();
	void print(class FU_Student* head);
	bool is_Empty();
	float classAverage();
	void first_Insert();
	void best_Student();
	void head();
	void tail();
	void append();
	int length();
	void sort_gpa();
	void sort_age();
	void delete_list();
	void append_List(list* listToAppend);
	void get_nth(int position);
	void reverse();
	void delete_element();
	void copy_list(list* listToCopy);
	void young_student();
	void remove_duplicate();
	void sort_insert();
	bool same_housing();
	void split_List(list* listOne, list* listTwo);
	//extra functions
	void swap_stud(FU_Student* student1, FU_Student* student2);
	void addElements(FU_Student* stud);
};


// function which given a list, splits it into two sublists; one for the front half and one for the back half.
// If the number of its elements is odd, the extra element should go in the front list
void list::split_List(list* listOne, list* listTwo)
{
	if (is_Empty() == false)
	{
		listOne->delete_list();
		listTwo->delete_list();
		int count = 0;
		int midpoint = length() / 2;
		if (length() % 2 != 0)
		{
			midpoint++;
		}
		for (FU_Student* curr = first; curr != NULL; curr = curr->next)
		{
			if (count < midpoint)
			{
				listOne->addElements(curr);
			}
			else
			{
				listTwo->addElements(curr);
			}
			count++;

		}
	}
	else
	{
		cout << "List is empty..." << endl;
	}

}

//functions checks whether two or more students stay in the same address/house
bool list::same_housing()
{
	if (is_Empty() == false) {
		int peopleNum = 0;
		for (FU_Student* current = first; current != NULL; current = current->next)
		{
			peopleNum = 0;
			for (FU_Student* checkCurr = first; checkCurr != NULL; checkCurr = checkCurr->next)
			{
				if (current->S_addr == checkCurr->S_addr)
				{
					cout << "found" << endl;
					peopleNum++;
					if (peopleNum == 2)
					{
						cout << "There are students who stay in the same house" << endl;
						return true;
					}
				}
			}
		}
		cout << "No one lives in the same house" << endl;
		return false;
	}
	else {
		cout << "List is empty" << endl;
		return false;
	}

}

//used for split list  
void list::addElements(FU_Student* stud)
{
	FU_Student* newNode = new FU_Student();
	*newNode = *stud;
	newNode->next = NULL;
	if (is_Empty() == true)
	{
		last = newNode;
		first = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
}

// function which takes two lists, ‘a’ and ‘b’, appends ‘b’(listToAppend) onto the end of ‘a’, and then sets ‘b’ to NULL
void list::append_List(list* listToAppend)
{
	last->next = listToAppend->first;
	last = listToAppend->last;
	listToAppend->first = NULL;
}

// function which inserts a new element in your sorted linked list, 
//its order is preserved(either gpa or age depending which one is worked out)
void list::sort_insert()
{
	append();
	//sorting based on gpa in this case
	sort_gpa();
}

//function which takes the linked list and returns a complete 2nd copy of this list
void list::copy_list(list* listToCopy)
{
	if (is_Empty() == false) {
		delete_list();
		for (FU_Student* current = listToCopy->first; current != NULL; current = current->next)
		{
			FU_Student* newStudent = new FU_Student();
			*newStudent = *current;
			newStudent->next = NULL;
			if (first == NULL)
			{
				first = newStudent;
				last = newStudent;
			}
			else
			{
				last->next = newStudent;
				last = newStudent;
			}
		}
	}
	else {
		cout << "List is empty, nothing to copy...." << endl;
	}

}

//takes a sorted linked list in increasing order in terms of ‘s_gpa’ and deletes 
//any duplicate nodes from the list; i.e. same name and same gpa. 
//Ideally, the list should be traversed only once
void list::remove_duplicate() {
	if (is_Empty() == false)
	{
		cout << "Sorted list before removing duplicates" << endl;
		sort_gpa();
		FU_Student* current = first;
		bool removed;
		while (current->next != NULL)
		{
			removed = false;
			if ((strcmp(current->S_name, current->next->S_name) == 0) && current->S_gpa == current->next->S_gpa)
			{
				FU_Student* deleteStud = current->next;
				current->next = deleteStud->next;
				delete deleteStud;
				removed = true;
			}
			if (removed == false)
			{
				current = current->next;
			}
		}
		cout << "After removing duplicates: " << endl;
		print(first);
	}
	else
	{
		cout << "List is empty, no duplicates..." << endl;
	}
}

//function which sorts the linked list in ascending order according to students ‘s_gpa’
void list::sort_gpa() {
	if (is_Empty() == false)
	{
		bool listChanged = true;
		do
		{
			listChanged = false;
			for (FU_Student* current = first; current->next != NULL; current = current->next)
			{
				if (current->S_gpa > current->next->S_gpa)
				{
					swap_stud(current, current->next);
					listChanged = true;
				}
			}
		} while (listChanged == true);
	}
	else
	{
		cout << "List is empty, nothing to sort..." << endl;
	}
}

//function which sorts the linked list in ascending order according to their ‘s_age’
void list::sort_age() {
	if (is_Empty() == false)
	{
		bool listchanged = true;
		do
		{
			listchanged = false;
			for (FU_Student* current = first; current->next != NULL; current = current->next)
			{
				if (current->S_age > current->next->S_age)
				{
					swap_stud(current, current->next);
					listchanged = true;
				}
			}
		} while (listchanged == true);
	}
	else
	{
		cout << "List is empty, nothing to sort..." << endl;
	}
}

//used to swap students (for sort gpa and sort age)
void list::swap_stud(FU_Student* student1, FU_Student* student2)
{
	FU_Student tempStudent = *student1;
	*student1 = *student2;
	*student2 = tempStudent;
	student2->next = student1->next;
	student1->next = tempStudent.next;
}

//function which finds and prints the name of the youngest student in the class
void list::young_student() {
	if (is_Empty() == false) {
		FU_Student* student = first;
		FU_Student* youngest = student;

		while (student != NULL)
		{
			if (student->S_age < youngest->S_age)
			{
				youngest = student;
			}
			student = student->next;
		}
		cout << "Youngest student is: " << youngest->S_name << " " << youngest->S_surn << endl;
		cout << "Age: " << youngest->S_age << endl;
	}
	else {
		cout << "List is empty..." << endl;
	}
}

//function which deletes a specific element of the linked list given the name or the registration number of the student
void list::delete_element() {
	if (is_Empty() == false)
	{
		char option;
		char name[14];
		int reg;
		FU_Student* curr = first;
		FU_Student* previous = first;
		cout << "To delete a student enter either a.) name  OR  b.) registration number" << endl;
		cout << "Enter option a or b: ";
		cin >> option;
		if (option == 'a' || option == 'A')
		{
			bool nameFound = false;
			cout << "Enter first name of student you would like to delete: " << endl;
			cin >> name;
			for (int i = 0; i < length(); i++)
			{
				int pos = i;
				if (strcmp(curr->S_name, name) == 0)
				{
					nameFound = true;

					previous->next = curr->next;

					delete curr;
					break;
				}
				previous = curr;
				curr = curr->next;
			}
			if (nameFound == false)
			{
				cout << "Name was not found in the list" << endl;
			}
		}
		else if (option == 'b' || option == 'B')
		{
			bool regFound = false;
			cout << "please enter registration number of student you would like to delete: ";
			cin >> reg;
			FU_Student* curr = first;
			int pos = 1;
			for (int i = 0; i < length(); i++)
			{
				int pos = i;
				if (curr->S_reg_no == reg)
				{
					regFound = true;

					previous->next = curr->next;

					delete curr;
					break;
				}
				previous = curr;
				curr = curr->next;
			}
			if (regFound == false)
			{
				cout << "Registration number not found in list" << endl;
			}
		}
		else
		{
			cout << "List is empty..." << endl;
		}
	}
}

//function which reverses a linked list by rearranging all the elements 
void list::reverse() {
	if (is_Empty() == false) {
		FU_Student* current = first;
		FU_Student* prev = NULL;
		FU_Student* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		first = prev;
		print(first);
	}
	else
	{
		cout << "List is empty, cant reverse..." << endl;
	}

}

//function which when given the linked list and a number, returns the data, i.e. the student’s name etc, contained in the nth node of the list
void list::get_nth(int position) {
	int pos = position;
	if (is_Empty() == false)
	{
		if (position == 1)
		{
			head();
		}
		else if (position > length() || position <= 0)
		{
			cout << "Student " << position << " is not valid..." << endl;
		}
		else
		{
			FU_Student* curr = first;
			for (int i = 1; i < position; i++)
			{
				curr = curr->next;
			}
			cout << "\tStudent: " << pos << endl;
			cout << "\tSurname: " << curr->S_surn << endl;
			cout << "\tName: " << curr->S_name << endl;
			cout << "\tRegistration Number: " << curr->S_reg_no << endl;
			cout << "\tGPA: " << curr->S_gpa << endl;
			cout << "\tAge: " << curr->S_age << endl;
			cout << "\tAddress: " << curr->S_addr << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "List is empty, cant get nth position..." << endl;
	}
}

//function which gives the number of elements of your linked list (no. of students)
int list::length() {
	int len = 0;
	if (is_Empty() == true)
	{
		cout << "List is empty..." << endl;
		return 0;
	}
	else
	{
		FU_Student* curr = first;
		while (curr != NULL)
		{
			len++;
			curr = curr->next;
		}
		return len;
	}
}

//function which inserts an element (student) at the end of the linked list
void list::append() {
	if (is_Empty() == true)
	{
		cons();
	}
	else
	{
		FU_Student* newNode = new FU_Student;
		last->next = newNode;
		last = newNode;
		last->next = NULL;
		cout << "Student: " << endl;
		cout << "Enter Surname: ";
		cin >> last->S_surn;
		cout << "Enter Name: ";
		cin >> last->S_name;
		cout << "Enter Registration Number: ";
		cin >> last->S_reg_no;
		cout << "Enter GPA: ";
		cin >> last->S_gpa;
		cout << "Enter Age: ";
		cin >> last->S_age;
		cout << "Enter Address: ";
		cin >> last->S_addr;
		cout << endl;
	}
}

//function which returns the first element of the linked list (first student)
void list::head() {
	if (is_Empty() == true)
	{
		cout << "Linked list is empty, cant return head...." << endl;
	}
	else
	{
		FU_Student* curr = first;
		cout << "\tStudent 1: " << endl;
		cout << "\tSurname: " << curr->S_surn << endl;
		cout << "\tName: " << curr->S_name << endl;
		cout << "\tRegistration Number: " << curr->S_reg_no << endl;
		cout << "\tGPA: " << curr->S_gpa << endl;
		cout << "\tAge: " << curr->S_age << endl;
		cout << "\tAddress: " << curr->S_addr << endl;
		count++;
		cout << endl;
	}
}

//function which returns the original linked list without the head element (rest of the students)
void list::tail() {
	if (is_Empty() == true)
	{
		cout << "Linked list is empty, no tail...." << endl;
	}
	else
	{
		FU_Student* curr = first->next;
		print(curr);
	}
}

//function which creates the linked list of students (new list)
void list::cons()
{
	FU_Student* newNode = new FU_Student;
	first = newNode;
	last = newNode;
	last->next = NULL;
	cout << "Student: " << endl;
	cout << "Enter Surname: ";
	cin >> first->S_surn;
	cout << "Enter Name: ";
	cin >> first->S_name;
	cout << "Enter Registration Number: ";
	cin >> first->S_reg_no;
	cout << "Enter GPA: ";
	cin >> first->S_gpa;
	cout << "Enter Age: ";
	cin >> first->S_age;
	cout << "Enter Address: ";
	cin >> first->S_addr;
	cout << endl;
}

//function which inserts a new element (new student) at the beginning of your linked list
void list::first_Insert() {
	FU_Student* newNode = new FU_Student;
	if (is_Empty() == true)
	{
		cons();
	}
	else
	{
		newNode->next = first;
		first = newNode;
		cout << "Student: " << endl;
		cout << "Enter Surname: ";
		cin >> first->S_surn;
		cout << "Enter Name: ";
		cin >> first->S_name;
		cout << "Enter Registration Number: ";
		cin >> first->S_reg_no;
		cout << "Enter GPA: ";
		cin >> first->S_gpa;
		cout << "Enter Age: ";
		cin >> first->S_age;
		cout << "Enter Address: ";
		cin >> first->S_addr;
		cout << endl;
	}
}

//function which finds the great point average (gpa) of the whole class
float list::classAverage() {
	if (is_Empty() == false)
	{
		float count = 0.0;
		float sum = 0.0;
		FU_Student* curr = first;
		while (curr != NULL)
		{
			sum = sum + curr->S_gpa;
			curr = curr->next;
			count++;
		}
		return (sum / count);
	}
	else
	{
		cout << "List is empty, no average calculated...." << endl;
		return 0;
	}
}

//function which prints the contents of the linked list (all students)
void list::print(class FU_Student* head)
{
	if (is_Empty() == false)
	{
		FU_Student* curr = head;
		int counter = 1;
		while (curr != NULL)
		{
			cout << "\tStudent: " << counter << endl;
			cout << "\tSurname: " << curr->S_surn << endl;
			cout << "\tName: " << curr->S_name << endl;
			cout << "\tRegistration Number: " << curr->S_reg_no << endl;
			cout << "\tGPA: " << curr->S_gpa << endl;
			cout << "\tAge: " << curr->S_age << endl;
			cout << "\tAddress: " << curr->S_addr << endl;
			curr = curr->next;
			counter++;
			cout << endl;
		}
	}
	else
	{
		cout << "List is empty..." << endl;
	}
}

//function which checks if list is empty or not
bool list::is_Empty() {
	if (first == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//function which finds and prints the name of the best student in the class 
void list::best_Student() {
	if (is_Empty() == false)
	{
		FU_Student* curr = first;
		FU_Student* max = first;
		if (is_Empty() == false) {
			while (curr != NULL) {
				if (curr->S_gpa > max->S_gpa) {
					max = curr;
				}
				curr = curr->next;
			}
		}
		cout << "Best student: " << max->S_name << " " << max->S_surn;
	}
	else
	{
		cout << "List is empty, no best student..." << endl;
	}
}

//function which takes the linked list, deallocates all of its memory and sets its head pointer to NULL (the empty list)
void list::delete_list() {
	if (is_Empty() == false) {
		FU_Student* temp = new FU_Student;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
		cout << "List has successfully been deleted" << endl;
	}
	else {
		cout << "List is empty, nothing to delete..." << endl;
	}
}

//function which displays the menu
void menu() {
	cout << "\nMENU" << endl;
	cout << "1. returns the head of a linked list" << endl;
	cout << "2. returns the tail of a linked list" << endl;
	cout << "3. inserts a new student at the beginning of the linked list" << endl;
	cout << "4. sorts the linked list in ascending order according to students gpa" << endl;
	cout << "5. sorts the linked list in ascending order according to students age" << endl;
	cout << "6. inserts a student at the end of the linked list" << endl;
	cout << "7. gives the number of students elements of your linked list" << endl;
	cout << "8. prints the contents of the linked list(all students) " << endl;
	cout << "9. copies the linked list and returns a complete 2nd copy of this list" << endl;
	cout << "10. prints information about a the nth student" << endl;
	cout << "11. deletes the whole list" << endl;
	cout << "12. deletes a specific element based on name or registration number" << endl;
	cout << "13. appends one list on to the end of the other" << endl;
	cout << "14. splits the list in 2" << endl;
	cout << "15. removes duplicates (people with the same gpa and first name) from a sorted linked list " << endl;
	cout << "16. reverses a linked list " << endl;
	cout << "17. finds the gpa of the whole class" << endl;
	cout << "18. prints the name of the best student in the class " << endl;
	cout << "19. prints the name of the youngest student in the class " << endl;
	cout << "20. checks if 2 or more students stay in the same house (have the same address) " << endl;
	cout << "21. inserts a new element in your sorted linked list, its order is preserved(either gpa or age depending which one is worked out)" << endl;
	cout << "22. Exit" << endl << endl;
}

//inserting data about students into empty list (for appending list b to a)
void emptyListInsert(list* listToAppend)
{
	cout << "Inserting data to list to append which is currently empty" << endl;
	listToAppend->append();
	listToAppend->append();
}

//main program starts here
int main() {
	list linkedList;
	menu();
	int choice;
	list listTwo;
	list split1;
	list split2;
	list listToAppend;
	emptyListInsert(&listToAppend);

	do {
		cout << "Please enter your option: ";
		cin >> choice;
		switch (choice)
		{
		case 1: linkedList.head();
			break;
		case 2: linkedList.tail();
			break;
		case 3: linkedList.first_Insert();
			break;
		case 4: linkedList.sort_gpa();
			break;
		case 5: linkedList.sort_age();
			break;
		case 6: linkedList.append();
			break;
		case 7: linkedList.length();
			break;
		case 8: linkedList.print(linkedList.first);
			break;
		case 9: linkedList.copy_list(&listTwo);
			break;
		case 10:
			cout << "Enter the position of the student you want information about";
			int pos;
			cin >> pos;
			linkedList.get_nth(pos);
			break;
		case 11: linkedList.delete_list();
			break;
		case 12: linkedList.delete_element();
			break;
		case 13:
			linkedList.append_List(&listToAppend);
			break;
		case 14: linkedList.split_List(&split1, &split2);
			cout << "First half" << endl;
			split1.print(split1.first);
			cout << "Second half" << endl;
			split2.print(split2.first);
			break;
		case 15: linkedList.remove_duplicate();
			break;
		case 16: linkedList.reverse();
			break;
		case 17: linkedList.classAverage();
			break;
		case 18: linkedList.best_Student();
			break;
		case 19: linkedList.young_student();
			break;
		case 20: linkedList.same_housing();
			break;
		case 21: linkedList.sort_insert();
			break;
		case 22: cout << "You chose to exit" << endl;
			break;
		default: cout << "Invalid choice" << endl;

		}
	} while (choice != 22);

	system("pause");
	return 0;
}


