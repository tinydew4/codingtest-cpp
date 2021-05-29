//---------------------------------------------------------------------------
#include <iostream>
#include <assert>
#include <stdlib.h>
#pragma hdrstop

#include "p2manager.h"
//---------------------------------------------------------------------------
void Run(TManager *M);
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    TManager *M = new TManager(std::cin, std::cout);

    try
    {
        Run(M);
    }
    __finally
    {
        delete M;
    }

    return 0;
}
//---------------------------------------------------------------------------
void Run(TManager *M)
{
    assert(M);

    try
    {
        M->Run();
    }
    catch (const std::exception &E)
    {
        std::cout << E.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (const char *E)
    {
        std::cout << E << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        try
        {
            throw EUNKNOWN;
        }
        catch (const char *E)
        {
            std::cout << E << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
//---------------------------------------------------------------------------

