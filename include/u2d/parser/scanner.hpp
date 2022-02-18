// Generated by Flexc++ V2.08.01 on Fri, 18 Feb 2022 00:26:39 +0100

#ifndef u2dscanner_H_INCLUDED_
#define u2dscanner_H_INCLUDED_

// $insert baseclass_h
#include "scanner-base.hpp"

// $insert namespace-open
namespace u2d
{

// $insert classHead
class scanner: public scannerBase
{
    public:
        explicit scanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

        scanner(std::string const &infile, std::string const &outfile);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

// $insert scannerConstructors
inline scanner::scanner(std::istream &in, std::ostream &out)
:
    scannerBase(in, out)
{}

inline scanner::scanner(std::string const &infile, std::string const &outfile)
:
    scannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int scanner::lex()
{
    return lex_();
}

inline void scanner::preCode() 
{
    // optionally replace by your own code
}

inline void scanner::postCode([[maybe_unused]] PostEnum_ type) 
{
    // optionally replace by your own code
}

inline void scanner::print() 
{
    print_();
}

// $insert namespace-close
}

#endif // scanner_H_INCLUDED_

