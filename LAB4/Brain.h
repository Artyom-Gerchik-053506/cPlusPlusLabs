// ---------------------------------------------------------------------------

#ifndef BrainH
#define BrainH
// ---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"
#include "MyOwnStack.h"
#include "MyOwnStackForNum.h"
#include <math.h>
#include "tinyexpr.h"
#include <comdef.h>

using namespace std;

class Brain {
private:
	MyOwnStack stack;
	MyOwnStackForNum numStack;
	UnicodeString inputEquation;
	UnicodeString outputEquation;

public:

	void cleanUP() {
		stack.clearMemory();
		numStack.clearMemory();
	}

	double test(char const * inputEX, double a, double b, double c, double d,
		double e) {

		double result = 0;
		/* Store variable names and pointers. */
		te_variable vars[] = {
			{"a", &a}, {"b", &b}, {"c", &c}, {"d", &d}, {"e", &e}};

		int err;
		/* Compile the expression with variables. */
		te_expr *expression = te_compile(inputEX, vars, 5, &err);

		if (expression) {

			const double h1 = te_eval(expression); // if expr compiled eval it
			result = h1;

			te_free(expression);

		}
		else {
			ShowMessage("Parse error at " + AnsiString(err));
		}

		return result;
	}

	UnicodeString parseRPN2(UnicodeString inputStr) {

		stack.performStack(inputStr.Length());
		int currentPriority = 0;
		bool areYouWasHereLater = false;

		for (int index = 1; index < inputStr.Length() + 1; index++) {

			char letter = inputStr[index];

			if ((int)letter >= 97 && (int)letter <= 101) {
				outputEquation = outputEquation + letter;
			}
			else if (letter == '*' || letter == '/') {
				if (currentPriority == 3) {
					outputEquation += stack.pop();
				}
				currentPriority = 3;
				stack.push(letter);
			}
			else if (letter == '+' || letter == '-') {
				while (currentPriority > 1) {
					UnicodeString letter = stack.pop();
					if (letter == '*' || letter == '/') {
						currentPriority = 3;
						outputEquation += letter;
					}
					else if (letter == '+' || letter == '-') {
						currentPriority = 2;
						outputEquation += letter;
					}
					else if (letter == '(') {
						currentPriority = 1;
					}
					else {
						currentPriority = 0;
					}

				}

				currentPriority = 2;
				stack.push(letter);
			}
			else if (letter == '(') {
				currentPriority = 1;
				stack.push(letter);
			}

			else if (letter == ')') {
				while (currentPriority > 1) {
					UnicodeString letter = stack.pop();
					if (letter == '*' || letter == '/') {
						currentPriority = 3;
						outputEquation += letter;
					}

					else if (letter == '+' || letter == '-') {
						currentPriority = 2;
						outputEquation += letter;
					}

					else if (letter == '(') {

						if (areYouWasHereLater) {
							break;
						}
						else {
							areYouWasHereLater = true;
							currentPriority = 1;
						}
					}
					else {
						currentPriority = 0;
					}
				}

				areYouWasHereLater = false;
			}

			else {
				ShowMessage(
					"RedNeck, Your Equation Contains Smth Weird(a, b, c, d, e, +, -, *, /, (, ) - allowed).");
				break;
			}

			if (stack.peek() == '*' || stack.peek() == '/') {
				currentPriority = 3;
			}
			else if (stack.peek() == '+' || stack.peek() == '-') {
				currentPriority = 2;
			}
			else if (stack.peek() == '(') {
				currentPriority = 1;
			}
			else {
				currentPriority = 0;
			}

		}
		UnicodeString stackTopElement = stack.pop();

		while (stackTopElement != NULL) {
			outputEquation += stackTopElement;
			stackTopElement = stack.pop();
		}

		return outputEquation;
	}

	void clearOutput() {
		outputEquation = "";
	}

	float calculateRPN(float a, float b, float c, float d, float e) {

		numStack.performStack(outputEquation.Length() + 1);
		UnicodeString strToCalculate = outputEquation;
		for (int index = 1; index < strToCalculate.Length() + 1; index++) {

			if (strToCalculate[index] == 'a') {
				numStack.push(a);
			}
			else if (strToCalculate[index] == 'b') {
				numStack.push(b);
			}
			else if (strToCalculate[index] == 'c') {
				numStack.push(c);
			}
			else if (strToCalculate[index] == 'd') {
				numStack.push(d);
			}
			else if (strToCalculate[index] == 'e') {
				numStack.push(e);
			}
			else if (strToCalculate[index] == '+') {

				float var1 = numStack.pop();
				float var2 = numStack.pop();
				float tempResult = var2 + var1;
				numStack.push(tempResult);

			}
			else if (strToCalculate[index] == '-') {

				float var1 = numStack.pop();
				float var2 = numStack.pop();
				float tempResult = var2 - var1;
				numStack.push(tempResult);

			}
			else if (strToCalculate[index] == '*') {

				float var1 = numStack.pop();
				float var2 = numStack.pop();
				float tempResult = var2 * var1;
				numStack.push(tempResult);
			}
			else if (strToCalculate[index] == '/') {

				float var1 = numStack.pop();
				float var2 = numStack.pop();
				float tempResult = var2 / var1;
				numStack.push(tempResult);

			}

		}
		return numStack.pop();

	}

	UnicodeString testStackView() {
		return stack.viewStack();
	}
};
#endif
