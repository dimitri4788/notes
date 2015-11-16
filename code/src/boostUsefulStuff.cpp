#include <stdio.h>

#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <string>
#include <vector>

boost::optional<int> func(const std::string &str)
{
    boost::optional<int> value;
    int tmp = 0;

    if(sscanf(str.c_str(), "%d", &tmp) == 1)
        value.reset(tmp);

    return value;
}

int main(int argc, char **argv)
{
    //BOOST_FOREACH
    std::cout << "Boost's BOOST_FOREACH" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::string hello("Hello, world!");
    BOOST_FOREACH(char ch, hello)
    {
        std::cout << ch;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //boost::optional
    std::cout << "Boost's boost::optional" << std::endl;
    std::cout << "-----------------------" << std::endl;
    boost::optional<int> v1 = func("31245");
    boost::optional<int> v2 = func("hello");
    if(v1)
        printf("%d\n", v1.get());
    else
        printf("v1 not valid\n");

    if(v2)
        printf("%d\n", v2.get());
    else
        printf("v2 not valid");

    std::cout << std::endl;
    std::cout << std::endl;

    //boost::lexical_cast
    std::cout << "Boost's boost::lexical_cast" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::string strNum = "12345";
    int num;
    try
    {
        num = boost::lexical_cast<int>(strNum);
        std::cout << "String \"12345\" in integer form is: " << num << std::endl;
    }
    catch( const boost::bad_lexical_cast & )
    {
        std::cout << "Unable to convert" << std::endl;
    }
    std::cout << std::endl;

    //boost::algorithm
    std::cout << "Boost's boost::algorithm" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::string lowerCase = "boost c++ libraries";
    std::cout << "lowerCase: " << lowerCase << std::endl;
    std::cout << "boost::algorithm::to_upper_copy(lowerCase): " << boost::algorithm::to_upper_copy(lowerCase) << std::endl;
    std::cout << std::endl;

    //boost::algorithm (split string on delimiter)
    std::cout << "Boost's boost::algorithm (split string with delimiter \"-\")" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::string lineToSplit("test1-test2-test3");
    std::cout << "lineToSplit: " << lineToSplit << std::endl;
    std::vector<std::string> tokens;
    boost::split(tokens, lineToSplit, boost::is_any_of("-"));
    std::cout << "Size of the vector: " << tokens.size() << std::endl;
    for(size_t i = 0; i < tokens.size(); i++)
        std::cout << "token " << i+1 << ": " <<tokens[i] << std::endl;
    std::cout << std::endl;

    //boost::algorithm (split string and eliminate/ignore spaces in words)
    std::cout << "Boost's boost::algorithm (split string with unwanted spaces)" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    lineToSplit = "test1          test2  test3                              test4";
    std::cout << "lineToSplit: " << lineToSplit << std::endl;
    //boost::split(tokens, lineToSplit, boost::is_any_of("-"));
    boost::split(tokens, lineToSplit, boost::is_any_of(" "), boost::token_compress_on);
    std::cout << "Size of the vector: " << tokens.size() << std::endl;
    for(size_t i = 0; i < tokens.size(); i++)
        std::cout << "token " << i+1 << ": " <<tokens[i] << std::endl;
    std::cout << std::endl;

    return 0;
}


/*
 * NOTES:
 *
 * boost::optional
 *  Using boost::optional can be an advantage in certain situation. In C++ it effectivly
 *  works by being able to turn any datatype into a nullable value. It works much the same
 *  way as returning a null pointer to an object but without using a pointer. Instead this
 *  will work by being able to return an object which may or may not valid.
 *
 * boost::lexical_cast
 *  The lexical_cast function template offers a convenient and consistent form for supporting common
 *  conversions to and from arbitrary types when they are represented as text. The simplification
 *  it offers is in expression-level convenience for such conversions. For more involved conversions,
 *  such as where precision or formatting need tighter control than is offered by the default behavior
 *  of lexical_cast, the conventional std::stringstream approach is recommended. Where the conversions
 *  are numeric to numeric, boost::numeric_cast may offer more reasonable behavior than lexical_cast.
 *
 * boost::algorithm
 *  More can be found here: http://theboostcpplibraries.com/boost.stringalgorithms
 *
 */
