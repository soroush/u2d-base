// Generated by Bisonc++ V4.01.00 on Sat, 04 Aug 2012 16:54:23 +0430

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <vector>
#include <iostream>


namespace // anonymous
{
    struct PI__;
}



class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens__
    {
        DOUBLE = 257,
        INTEGER,
        BOOL,
        STRING,
        INIT,
        SERVER,
        LP,
        RP,
        SIDE,
        ACD,
        AM,
        BDR,
        BP,
        BAM,
        BD,
        BR,
        BS,
        BSM,
        BSA,
        BW,
        CBC,
        CP,
        CAL,
        CAW,
        CM,
        CADW,
        CDEFW,
        CDELW,
        CIW,
        CMD,
        CMPC,
        CMW,
        CRW,
        CWS,
        CO,
        COP,
        CWR,
        CW,
        CR,
        DAS,
        DPR,
        DBT,
        ED,
        EDT,
        EIN,
        EIT,
        EI,
        EM,
        EHT,
        ES,
        FKO,
        FC,
        FDP,
        FE,
        FKF,
        FSP,
        FWP,
        FL,
        FR,
        GLC,
        GLD,
        GLDIR,
        GLF,
        GLFN,
        GLV,
        GL,
        GOW,
        GW,
        GMM,
        GG,
        HT,
        HD,
        HI,
        HM,
        IM,
        K,
        KL,
        KLD,
        KLDIR,
        LKF,
        KLFN,
        KLG,
        KS,
        KW,
        KOW,
        KPR,
        KR,
        KRFL,
        KRFR,
        KM,
        LF,
        LDF,
        LT,
        MBTP,
        MAXDA,
        MDP,
        MGK,
        MTP,
        MAXM,
        MAXNA,
        MAXNM,
        MAXP,
        MINDA,
        MINDP,
        MINM,
        MINNA,
        MINNM,
        MINP,
        NEH,
        NNH,
        OAAS,
        OKM,
        OP,
        OCH,
        PAMK,
        PBSW,
        PCMP,
        PDX,
        PMET,
        PMGDX,
        PNK,
        PRW,
        PRWA,
        PSW,
        PTW,
        PSO,
        PAM,
        PD,
        PR,
        PS,
        PSM,
        PSMM,
        PW,
        PTB,
        PTD,
        P,
        PFL,
        PFR,
        PROF,
        PGK,
        QS,
        QSL,
        RM,
        RD,
        RDT,
        RI,
        RMIN,
        RS,
        RCP,
        SCCM,
        SCMS,
        SMS,
        SM,
        SS,
        SVS,
        SBS,
        SDR,
        SIMS,
        SDF,
        SOTFLT,
        SOTFRT,
        SC,
        SIM,
        SMAX,
        SGL,
        SGR,
        SBV,
        SMICS,
        SMOD,
        SO,
        SSO,
        TBD,
        TC,
        TD,
        TE,
        TPR,
        TRF,
        TW,
        TAN,
        TLS,
        TRS,
        TLC,
        TLD,
        TLDIR,
        TLF,
        TLFN,
        TL,
        UO,
        V,
        VA,
        VD,
        WA,
        WD,
        WF,
        WN,
        WR,
        WRA,
        PP,
        AMDT,
        CALSMAX,
        CALSMIN,
        DPRDMAX,
        DPRDMIN,
        EMAXDF,
        EMINDF,
        ESDMAX,
        ESDMIN,
        FDPDF,
        IMDF,
        KPRDMAX,
        KPRDMIN,
        KPRDF,
        KMDMAX,
        KMDMIN,
        NDPRDMAX,
        NDPRDMIN,
        NSIMAXDF,
        PDDMAX,
        PDDMIN,
        PSDF,
        PSMAXDMAX,
        PSMAXDMIN,
        PT,
        PTM,
        RANS,
        SIMAXDF,
        SUBMAX,
        PTY,
        ID,
        EMAX,
        CALS,
        PM_BKO,
        PM_PO,
        PM_TO,
        PM_KOL,
        PM_KOR,
        PM_KIL,
        PM_KIR,
        PM_FKL,
        PM_FKR,
        PM_CKL,
        PM_CKR,
        PM_GKL,
        PM_GKR,
        PM_GOALL,
        PM_GOALR,
        PM_DB,
        PM_OL,
        PM_OR,
        SEN,
        VM,
        VQ_L,
        VQ_H,
        VW_NA,
        VW_NO,
        VW_WI,
        ST,
        SP,
        HA,
        KICK,
        DASH,
        TURN,
        SAY,
        TNECK,
        CATCH,
        MOVE,
        CHVIEW,
        ARM,
        MOVABLE,
        EXP,
        TAR,
        COUNT,
        FOCUS,
        NONE,
        TACKLE,
        COLL,
        BALL,
        PLAYER,
        POST,
        FOUL,
        CHARGED,
        CARD,
        YELLOW,
    };

// $insert STYPE
union STYPE__
{
double d;
int i;
bool b;
std::string* s;
};


    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


