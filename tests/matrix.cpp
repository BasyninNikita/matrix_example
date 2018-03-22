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
         "3.1 3.2 3.3"};
    matrix_t<float> matrix;
    std::istringstream istream{input};
    REQUIRE( matrix.read(istream));
    REQUIRE(matrix.rows()==3);
    REQUIRE(matrix.collumns()==3);
    std::ostringstream ostream;
    matrix.write(ostream);
    REQUIRE(input==ostream.str());
}
TEST_CASE("adding matrixs")
{
    std::string input1{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string input2{
        "1, 3\n"
        "2 2 2\n"
    };
    matrix_t<int> matrix1,matrix2,matrixr;
   std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrixr=matrix1+matrix2;
    std::string result_str{
        "1, 3\n"
        "3 3 3"
    };
    std::ostringstream ostream;
    matrixr.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("subtracting matrixs")
{
    std::string input1{
        "1, 3\n"
        "3.3 4.4 5.5\n"
    };
    std::string input2{
        "1, 3\n"
        " 1.1 2.2 3.3\n"
    };
     matrix_t<float> matrix1,matrix2,matrixr;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrixr=matrix1-matrix2;

    std::string result_str{
        "1, 3\n"
        "2.2 2.2 2.2"
    };
    std::ostringstream ostream;
    matrixr.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("multiplying matrixs")
{
    std::string input1{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string input2{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    matrix_t<int> matrix1,matrix2,matrixr;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrixr=matrix1*matrix2;

    std::string result_str{
        "1, 1\n"
        "3"
    };
   std::ostringstream ostream;
    matrixr.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("error adding matrixs")
{
    std::string input1{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    std::string input2{
        "2, 1\n"
        "1\n"
        "1"
    };
   matrix_t<int> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1+matrix2), std::invalid_argument );
}
TEST_CASE("error subtrakting matrixs")
{
    std::string input1{
        "3, 2\n"
        "2.2 2.2\n"
        "2.2 2.2\n"
        "2.2 2.2\n"
    };
    std::string input2{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "1.1 1.1 1.1"
    };
   matrix_t<float> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1-matrix2), std::invalid_argument );
}
    TEST_CASE("error multiplying matrixs")
{
    std::string input1{
        "3, 2\n"
        "2 2\n"
        "2 2\n"
        "2 2\n"
    };
    std::string input2{
        "1, 3\n"
        "1 1 1"
    };
   matrix_t<int> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1*matrix2), std::invalid_argument );
}
   TEST_CASE("adding= matrixs")
{
    std::string input1{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string input2{
        "1, 3\n"
        "2 2 2\n"
    };
    matrix_t<int> matrix1,matrix2;
   std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrix1+=matrix2;
    std::string result_str{
     "1, 3\n"
     "3 3 3"
    };
    std::ostringstream ostream;
    matrix1.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("subtracting= matrixs")
{
    std::string input1{
        "1, 3\n"
        "3.3 4.4 5.5\n"
    };
    std::string input2{
        "1, 3\n"
        " 1.1 2.2 3.3\n"
    };
     matrix_t<float> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrix1-=matrix2;
    std::string result_str{
        "1, 3\n"
        "2.2 2.2 2.2"
    };
    std::ostringstream ostream;
    matrix1.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("multiplying= matrixs")
{
    std::string input1{
        "1, 3\n"
        "1 1 1\n"
    };
    std::string input2{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    matrix_t<int> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);
    matrix1*=matrix2;
    std::string result_str{
        "1, 1\n"
        "3"
    };
   std::ostringstream ostream;
    matrix1.write(ostream);
    REQUIRE( result_str == ostream.str());
}

TEST_CASE("error adding= matrixs")
{
    std::string input1{
        "3, 1\n"
        "1\n"
        "1\n"
        "1\n"
    };
    std::string input2{
        "2, 1\n"
        "1\n"
        "1"
    };
   matrix_t<int> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1+=matrix2), std::invalid_argument );
}
TEST_CASE("error subtrakting= matrixs")
{
    std::string input1{
        "3, 2\n"
        "2.2 2.2\n"
        "2.2 2.2\n"
        "2.2 2.2\n"
    };
    std::string input2{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "1.1 1.1 1.1"
    };
   matrix_t<float> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1-=matrix2), std::invalid_argument );
}
    TEST_CASE("error multiplying= matrixs")
{
    std::string input1{
        "3, 2\n"
        "2 2\n"
        "2 2\n"
        "2 2\n"
    };
    std::string input2{
        "1, 3\n"
        "1 1 1"
    };
   matrix_t<int> matrix1,matrix2;
    std::istringstream istream1{input1};
    matrix1.read(istream1);
    std::istringstream istream2{input2};
    matrix2.read(istream2);    
    REQUIRE_THROWS_AS( (matrix1*=matrix2), std::invalid_argument );
}
    
