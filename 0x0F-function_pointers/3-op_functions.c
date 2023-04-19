#include "3-calc.h"
#include <stdio.h>

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - returns sum of two numbers
 * @a: first number
 * @b: second number
 * Return: sum a + b
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - returns difference of two numbers
 * @a: first number
 * @b: second number
 * Return: sub a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - returns multiplication of two numbers
 * @a: first number
 * @b: second number
 * Return: mul a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - returns division of two numbers
 * @a: first number
 * @b: second number
 * Return: div a / b
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - returns mod of two numbers
 * @a: first number
 * @b: second number
 * Return: mod a % b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
