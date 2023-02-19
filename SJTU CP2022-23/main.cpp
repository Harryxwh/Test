//
//  main.cpp
//  SJTU CP2022-23
//
//  Created by Yoshi Kamiya on 2023/02/16.
//

#include <iostream>

class Messenger {
private:
	std::string GreetingPhrase;
	
public:
	Messenger() {
		/* constructor */
		GreetingPhrase = "Hello";
		GreetingPhrase2 = "Hello2";
	}
	~Messenger() {
		/* destructor */
	}
	
	void setGreetingPhrase(std::string spec) { GreetingPhrase = spec; };
	void speak() const {
		std::cout << GreetingPhrase << ", World!\n";
	};
	
	std::string GreetingPhrase2;
};

int main(int argc, const char * argv[]) {
	/* Usual "Hello, World" */
	std::cout << "Hello, World!\n";
	std::cout << "Go to ***, World!\n"; /* ??? */

	/*
		Do the same thing as above using an object Messenger,
		so that the intention of the programmer is hopefully clearer.
	*/
	Messenger WhoeverMaybe;
	WhoeverMaybe.speak();
	WhoeverMaybe.setGreetingPhrase("Nihao");
	WhoeverMaybe.speak();

	/*
		A private (public) member of an object cannot (can) be accessed from outside.
		This can be used to control which information to be disclosed and which information
		to be hidden. Usually, unnecessary access to the data is better to be restricted,
		which makes the maintenance/debug easier.
	*/
	std::cout << WhoeverMaybe.GreetingPhrase2 << std::endl;
	std::cout << WhoeverMaybe.GreetingPhrase << std::endl; /* error */
	
	return 0;
}
