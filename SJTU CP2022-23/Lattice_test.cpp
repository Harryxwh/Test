#include "catch_amalgamated.hpp"
#include "Lattice.hpp"

double SquareLattice_N_sites(int L0, int L1) {
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = 10;
	L[1] = 10;
	SquareLattice lattice(L);
	return lattice._N_sites();
}

TEST_CASE("IsingCP2022-23", "test") {
    REQUIRE(SquareLattice_N_sites(4, 4) == -32);
}
