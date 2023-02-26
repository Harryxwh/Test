#include "catch2/catch_amalgamated.hpp"
#include "Lattice.hpp"

double SquareLattice_N_sites(int L0, int L1) {
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = L0;
	L[1] = L1;
	SquareLattice lattice(L);
	return lattice._N_sites();
}

TEST_CASE("SquareLattice", "test") {
    REQUIRE(SquareLattice_N_sites(4, 4) == 16);
}
