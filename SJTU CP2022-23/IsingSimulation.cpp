#include "Lattice.hpp"

int main(int argc, const char * argv[]) {

	/* Square Lattice */
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = 10;
	L[1] = 10;
	SquareLattice lattice(L);
	
	const int z = lattice._z_common();
	for (int site_idx = 0; site_idx < lattice._N_sites(); site_idx++) {
		lattice.print_info_Site(site_idx);
		for (int bond_idx = 0; bond_idx < z; bond_idx++) {
			const int j = lattice._NN_of_Site(site_idx, bond_idx);
			std::cout << "-- NN at bond " << bond_idx << ": "<< j << std::endl;
		}
	}

	return 0;
}
