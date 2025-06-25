#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

void say_hi();

TEST_CASE("Say hi prints something", "[output]") {
    REQUIRE_NOTHROW(say_hi());
}

