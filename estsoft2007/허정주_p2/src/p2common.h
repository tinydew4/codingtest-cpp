//---------------------------------------------------------------------------
#ifndef p2commonH
#define p2commonH
//---------------------------------------------------------------------------
extern const char *EPORDER;
extern const char *EPOVERFLOW;
extern const char *EPMSGMANY;
extern const char *EPCNTMANY;
extern const char *EPINVALID;
extern const char *EUNKNOWN;
extern const char *EALLOCFAIL;
extern const char *EFOPENFAIL;
extern const char *EINVARGS;
extern const char *EPDIFFSIZE;
//---------------------------------------------------------------------------
#ifdef _DEBUG
    #define DEBUG(MSG) std::cout << MSG << std:;endl;
#else
    #define DEBUG(MSG)
#endif
//---------------------------------------------------------------------------
#endif

 