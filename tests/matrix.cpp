#include <cassert>
#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t<int> matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t<int> matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}
TEST_CASE("reading other type matrix")
{
    std:: string input{
        "3, 3\n"
         "1.1 1.2 1.3\n"
         "2.1 2.2 2.3\n"
         "3.1 3.2 3.3\n"};
    matrix_t<float> matrix;
    std::istringstream istream{input};
    REQUIRE( matrix.read(istream));
    REQUIRE(matrix.rows()==3);
    REQUIRE(matrix.columns()==3);
    std::ostringstream ostream;
    matrix.write(ostream);
    REQUIRE(input==ostream.str());
TEST_CASE("addings matrixs")
{
    std::string first_matrix_representation{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string second_matrix_representation{
        "1, 3\n"
        "1 1 1\n"
    };
    matrix_t<int> first_matrix = matrix( first_matrix_representation );
    matrix_t<int> second_matrix = matrix( second_matrix_representation );
    matrix_t<int> result_matrix = first_matrix + second_matrix;
    std::string expected_result_matrix_representation{
        "1, 3\n"
        "2 2 2\n"
    };
    
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}

TEST_CASE("subtracting matrixs")
{
    std::string first_matrix_representation{
        "1, 3\n"
        "3.3 4.4 5.5\n"
    };
    std::string second_matrix_representation{
        "1, 3\n"
        " 1.1 2.2 3.3\n"
    };
    matrix_t<float> first_matrix = matrix( first_matrix_representation );
    matrix_t<float> second_matrix = matrix( second_matrix_representation );
    matrix_t<float> result_matrix = first_matrix - second_matrix;

    std::string expected_result_matrix_representation{
        "1, 3\n"
        "2.2 2.2 2.2\n"
    };
    
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}

TEST_CASE("multiplying matrixs")
{
    std::string first_matrix_representation{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string second_matrix_representation{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    matrix_t<int> first_matrix = matrix( first_matrix_representation );
    matrix_t<int> second_matrix = matrix( second_matrix_representation );
    
    matrix_t<int> result_matrix = first_matrix * second_matrix;

    std::string expected_result_matrix_representation{
        "1, 1\n"
        "3"
    };
    
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}

TEST_CASE("addings matrixs 3x1")
{
    std::string first_matrix_representation{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    std::string second_matrix_representation{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    matrix_t first_matrix = matrix( first_matrix_representation );
    matrix_t second_matrix = matrix( second_matrix_representation );
    
    matrix_t result_matrix = first_matrix + second_matrix;

    std::string expected_result_matrix_representation{
        "3, 1\n"
        "2\n"
        "2\n"
        "2\n"
    };
    
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}
TEST_CASE("
