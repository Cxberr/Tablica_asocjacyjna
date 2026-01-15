#include "Employee.h"
#include "books.h"
#include "Map.h"														// Defines template Map<Key, Value>
#include <iostream>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees
typedef std::string author;
typedef Map<std::string, book> library;
using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

int main() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;

	cout << endl << endl;;

	library newLibrary;
	newLibrary.add("Harry Potter",book("Harry Potter", "J.K. Rowling", "Fantasy",  300, available));
	newLibrary.add("Władca Pierścieni",book("Władca Pierścieni", "J.R.R. Tolkien", "Fantasy",  1216, available));
	newLibrary.add("Zbrodnia i kara",book("Zbrodnia i kara", "Fiodor Dostojewski", "Powieść psychologiczna",  671, available));
	newLibrary.add("Czysty kod",book("Czysty kod", "Robert C. Martin", "Programowanie", 464, available));
	cout << "original library: " << newLibrary << endl;

	book* bookPtr = newLibrary.find("Harry Potter");
	bookPtr->rent("Jan Kowalski");
	book* lotrPointer = newLibrary.find("Władca Pierścieni");
	lotrPointer->rent("Anna Zaradna");
	cout << "Modified library: " << newLibrary << endl;
	bookPtr->rent("");
	lotrPointer->rent("Jan Kowalski");
};

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";



	// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}
