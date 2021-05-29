//---------------------------------------------------------------------------
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "p1common.h"
#pragma hdrstop

#include "p1manager.h"
//---------------------------------------------------------------------------
void Run(TManager *M);
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	TManager *M = new TManager(std::cin, std::cout);
	Run(M);
	delete M;
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
