#include <stdio.h>

/*A normal function with an int parameter and void return type*/

void fun(int a);

int main()
{
	/*fun_ptr is a pointer to function fun()*/
	//void (*fun_ptr) (int) = &fun;
	void (*fun_ptr) (int);
	//fun_ptr = &fun;
	fun_ptr = fun;
	
	/*now we are calling the function pointer. If using * you must use the ( ) 
	 *around the pointer itself.*/
	(*fun_ptr)(10);
	/*This format does not require the ( ) around the pointer b/c we are not 
	 *using the *  */
	fun_ptr(15);


	return 0;
}

void fun(int a)
{
	printf("Value of 'a' is %d\n", a);

}