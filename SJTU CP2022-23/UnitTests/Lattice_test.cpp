#include "catch2/catch_amalgamated.hpp"
#include "../Lattice.hpp"

int SquareLattice_N_sites(int L0, int L1) {
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = L0;
	L[1] = L1;
	SquareLattice lattice(L);
	return lattice._N_sites();
}

int SquareLattice_NN(int L0, int L1, int site_idx, int bond_idx) {
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = L0;
	L[1] = L1;
	SquareLattice lattice(L);
	return lattice._NN_of_Site(site_idx, bond_idx);
}

TEST_CASE("SquareLattice") {
	REQUIRE(SquareLattice_N_sites(4, 4) == 16);
	REQUIRE(SquareLattice_NN(4, 4, 0, 0) == 1);
	REQUIRE(SquareLattice_NN(4, 4, 0, 1) == 4);
	REQUIRE(SquareLattice_NN(4, 4, 0, 2) == 3);
	REQUIRE(SquareLattice_NN(4, 4, 0, 3) == 12);
}

TEST_CASE("SquareLattice2") {
	REQUIRE(SquareLattice_N_sites(3,2) == 6);
	REQUIRE(SquareLattice_NN(3, 2, 3, 0) == 4);
	REQUIRE(SquareLattice_NN(3, 2, 3, 1) == 0);
	REQUIRE(SquareLattice_NN(3, 2, 3, 2) == 5);
	REQUIRE(SquareLattice_NN(3, 2, 3, 3) == 0);
	
}
