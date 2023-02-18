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
	std::cout << "Go to ***, World 2!\n";
	
	Messenger WhoeverMaybe;
	WhoeverMaybe.speak();
	WhoeverMaybe.setGreetingPhrase("Nihao");
	WhoeverMaybe.speak();
	std::cout << WhoeverMaybe.GreetingPhrase2 << std::endl;
	std::cout << WhoeverMaybe.GreetingPhrase << std::endl; /* error */
	
	return 0;
}
