#include "test.h"
#include "math.h"
#include "student.h"
#include <stdlib.h>

/**
 * Example for demonstration at start of test.
 */

int example(){
	return 42;
}

/**
 * Warmup (but counts for credit!)
 * Square the value x points to.
 */
void easyPeasy(int* x){
	*x = (*x) * (*x);
}

/**
 * Set a's first name to "Jigglypuff".
 * Set the last name to "Ketchum".
 * Set the g number to 10, the gpa to 1.16.
 */
void one(Student* a){
	set_first_name(a, "Jigglypuff");
	set_last_name(a, "Ketchum");
	set_g_number(a, 10);
	set_gpa(a, 1.16);
}

/**
 * Copy the information from Student b to Student a.
 * (pointer parameters).
 */
void two(Student* a, Student* b){
	a->first_name = b->first_name;
	a->gpa = b->gpa;
	a->g_number = b->g_number;
	a->last_name = b->last_name;
	a->roommate = b->roommate;
}

/**
 * Copy the information from Student a to Student b.
 * (mixed variable type parameters).
 */

void three(Student a, Student* b){
	a.first_name = b->first_name;
	a.gpa = b->gpa;
	a.g_number = b->g_number;
	a.last_name = b->last_name;
	a.roommate = b->roommate;
}

/**
 * Create and return a Student.  Give it the values
 * "T. Yoshisaur" (first_name)
 * "Munchakoopas" (last_name)
 * 1990		  (g_number)
 * 3.1		  (gpa)
 * Mario	  (roommate [defined above])
 * Remember: C is pass by copy ONLY.
 */
Student four(){
	Student a;
	set_first_name(&a, "T. Yoshisaur");
	set_last_name(&a, "Munchakoopas");
	set_g_number(&a, 1990);
	set_gpa(&a, 3.1);
	a.roommate = &Mario;
	return a;
}

/**
 * Create and return a Student*.  Give it the value
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 * Remember: C is pass by copy ONLY.
 */
Student* five(){
	Student *a = (Student*)malloc(sizeof(Student));
	set_first_name(a, "Luigi");
	set_last_name(a, "Mario");
	set_g_number(a, 2);
	set_gpa(a, 3.54);
	return a;
} 

/**
 * Create a hunk of memory we can use as an array of 10
 * Students.  Set the 4th element (meaning use array
 * index 3) to
 *
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 */
Student* six(){
	Student *a = (Student*)malloc(sizeof(Student)*10);
	set_first_name(a+3, "Luigi");
	set_last_name(a+3, "Mario");
	set_g_number(a+3, 2);
	set_gpa(a+3, 3.54);
	return a;
}

/**
 * Seven will take a pointer to a pointer.  It should
 * create a hunk of memory that can be used as an array
 * of size 10, and will set the pointer correctly so
 * that the "array" is usable in main.
 * Set the 10th (index 9) element equal to
 *
 * "Luigi" (first_name)
 * "Mario" (last_name)
 * 2       ( :( )
 * 3.54    (gpa [we know he's the smart one])
 */
void seven(Student** students){
	students = (Student**)malloc(sizeof(Student*)*10);
	for(int i = 0; i < 10; i++){
		students[i] = (Student*)malloc(sizeof(Student));
	}
	set_first_name(a[9], "Luigi");
	set_last_name(a[9], "Mario");
	set_g_number(a[9], 2);
	set_gpa(a[9], 3.54);
}

/**
 * Given a, b, and c calculate the first solution for
 * the quadratic equation (given below).
 *
 * -b + sqrt(b^2 - 4ac) / (2a)
 */
double quadratic(double a, double b, double c){
	double solution = -b + sqrt(b*b - 4*a*c) ;
	solution = solution / (2*a) ;
	return solution;
}

/**
 * Given a "string" (a character array) and a length,
 * replace each lower case character with its uppercase
 * equivalent.
 *
 * Do not use any string functions provided by the library.
 * Merely check to see if each character is between the
 * range of values for a lowercase letter.  If it is,
 * replace it with the uppercase value equivalent.
 *
 * If you are writing more than five lines you are doing it wrong.
 */
#include <stdio.h>
void capitalize(char* str, size_t len){
	for (int i = 0; i < len; i++){
		if(str[i] <= 'z' && str[i] >= 'a'){
			str[i] = str[i]-'a'+ 'A';
		}
	}
}
