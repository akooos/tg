/*opciok*/
%option noyywrap c++ yylineno
%{

#include <iostream>
#include <fstream>
        using namespace std;
%}

        /* makrok */
string  \"[^\n"]+\"

ws      [ \t]+

alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}

%%


%%

        /*C++kód*/
int main(int argc, char* argv[] )
{
        if ( argc < 2 ){

             std::cout << "Bad number of arguments!" << std::endl;
             return -1;
        }
        ifstream in(argv[1]);
        yyFlexLexer fl( &in, &cout );
        fl.yylex();
        return 0;
}
