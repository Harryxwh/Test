#include "Lattice.hpp"

int main(int argc, const char * argv[]) {

	/* square lattice */
	const int N_SL = 1;
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = 10;
	L[1] = 10;
	Site::set_lattice_info(N_SL, L);
	
	Site test;
	std::vector<int> r(dim);
	r[0] = 2;
	r[1] = 1;
	const int sl_index = 0;
	test.set_position(sl_index, r);
	test.print_info();
	
	return 0;
}
