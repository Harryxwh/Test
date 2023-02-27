#ifndef IsingSystem_hpp
#define IsingSystem_hpp

#include <iostream>

class IsingSpin {
private:
	int sz; /* will be restricted to +/- 1 */

public:
	IsingSpin() : sz(1) {};
	~IsingSpin() {};

	int _sz() const { return sz; };

	void set_sz(int sz_spec) {
		assert(sz_spec == 1 || sz_spec == -1);
		sz = sz_spec;
	};

	void flip() { sz *= -1; };
};

#endif /* IsingSystem_hpp */
