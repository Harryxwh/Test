#ifndef Lattice_hpp
#define Lattice_hpp

#include <iostream>
#include <vector>

class Site {
public:
	static void set_lattice_info(int N_SL_spec, const std::vector<int>& L_spec) {
		/* set dim, L, N_SL */
		dim = static_cast<int>(L_spec.size());
		L = L_spec;
		N_SL = N_SL_spec;
	};
	
	static int eval_site_index(int sl_index, const std::vector<int>& n) {
		/*
		 s_idx = (n[d-1], n[d-2], ..., n[0], sl_index)
		 */
		int s_idx = n[dim - 1];
		for ( int a = dim - 2; a >= 0; a-- ) {
			assert(n[a] < L[a] && n[a] >= 0);
			s_idx *= L[a];
			s_idx += n[a];
		}
		assert(sl_index < N_SL && sl_index >= 0);
		s_idx *= N_SL;
		s_idx += sl_index;
		
		return s_idx;
	};
	
	static void eval_position_at(int s_idx, int& sl_index, std::vector<int>& n) {
		sl_index = s_idx % N_SL;
		s_idx /= N_SL;
		for (int a = 0; a < dim; a++) {
			n[a] = s_idx % L[a];
			s_idx /= L[a];
		}
	};

private:
	static int dim; /* dimension */
	static int N_SL; /* number of sublattices */
	static std::vector<int> L; /* system size */
	
	int site_index;
	int sublattice_index;
	std::vector<int> coordinate;
	int z; /* coordination number */
	std::vector<int> NN; /* nearest neighbor sites */

public:
	Site() : z(0) {
		/* constructor */
	};
	
	virtual ~Site() {
		/* destructor */
	};
	
	int get_site_index() const { return site_index; };
	
	void set_site_index() {
		site_index = eval_site_index(sublattice_index, coordinate);
	};
	
	void get_position(int& sl_index, std::vector<int>& r) const {
		sl_index = sublattice_index;
		r = coordinate;
	};
	
	void set_position(int sl_index, const std::vector<int>& r) {
		sublattice_index = sl_index;
		coordinate = r;
		set_site_index();
	};

	int get_z() const { return z; };
	
	void set_z(int z_spec) {
		z = z_spec;
		NN.resize(z);
	};
	
	int get_NN(int bond_index) const {
		assert(bond_index < z && bond_index >= 0);
		return NN[bond_index];
	};
	
	void set_NN(int bond_index, int i_site) {
		assert(bond_index < z && bond_index >= 0);
		NN[bond_index] = i_site;
	};
	
	void print_info() const {
		std::cout
		<< "Site #" << site_index << ": "
		<< "sublattice " << sublattice_index << "; coordinate ("
		<< coordinate[0];
		for (int a = 1; a < dim; a++) {
			std::cout << ", " << coordinate[a];
		}
		std::cout << "); NN sites (if any) ..." << std::endl;
		for (int mu = 0; mu < z; mu++) {
			std::cout << NN[mu] << ' ';
		}
		std::cout << std::endl;
	};
};

#endif /* Lattice_hpp */
