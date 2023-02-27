#include "catch2/catch_amalgamated.hpp"
#include "../IsingSystem.hpp"

TEST_CASE("IsingSpin Init") {
	IsingSpin spin;
	REQUIRE(spin._sz() == 1);

	spin.set_sz(-1);
	REQUIRE(spin._sz() == -1);
	
	spin.flip();
	REQUIRE(spin._sz() == 1);
}
