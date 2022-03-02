#include <iostream>
#include "Dictionary.h"

int main()
{
	Dictionary<const char*, int> testDictionary = Dictionary<const char*, int>();
	Dictionary<const char*, int> testDictionary2 = Dictionary<const char*, int>();

	testDictionary.addItem("A", 1);
	testDictionary.addItem("B", 2);
	testDictionary.addItem("C", 3);
	int value;

	testDictionary.tryGetValue("C", value);

	/*testDictionary.remove("B", value);*/

	if (value == 3)
		std::cout << "Success" << std::endl;

	system("pause");

	/*testDictionary.remove("A");*/
	testDictionary.clear();

	if (testDictionary.containsValue(2))
		std::cout << "VALUE YES" << std::endl;
	else
		std::cout << "VALUE NO" << std::endl;

	if (testDictionary.containsKey("A"))
		std::cout << "KEY YES" << std::endl;
	else
		std::cout << "KEY NO" << std::endl;

	system("pause");

	testDictionary.addItem("E", 1);
	testDictionary.addItem("F", 2);
	testDictionary.addItem("G", 3);
	testDictionary.addItem("H", 4);
	testDictionary.addItem("I", 5);

	if (testDictionary.containsValue(2))
		std::cout << "VALUE YES" << std::endl;
	else
		std::cout << "VALUE NO" << std::endl;

	if (testDictionary.containsKey("H"))
		std::cout << "KEY YES" << std::endl;
	else
		std::cout << "KEY NO" << std::endl;

	system("pause");

	testDictionary2 = testDictionary;


	return 0;
}