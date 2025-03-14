/* spice.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ielmnt, isbckt, nsbckt, iunsat, nunsat, itemps, numtem, isens, 
	    nsens, ifour, nfour, ifield, icode, idelim, icolum, insize, 
	    junode, lsbkpt, numbkp, iorder, jmnode, iur, iuc, ilc, ilr, 
	    numoff, isr, nmoffc, iseq, iseq1, neqn, nodevs, ndiag, iswap, 
	    iequa, macins, lvnim1, lx0, lvn, lynl, lyu, lyl, lx1, lx2, lx3, 
	    lx4, lx5, lx6, lx7, ld0, ld1, ltd, imynl, imvn, lcvn, nsnod, 
	    nsmat, nsval, icnod, icmat, icval, loutpt, lpol, lzer, irswpf, 
	    irswpr, icswpf, icswpr, irpt, jcpt, irowno, jcolno, nttbr, nttar, 
	    lvntmp;
} tabinf_;

#define tabinf_1 tabinf_

struct {
    doublereal atime, aprog[3], adate, atitle[10], defl, defw, defad, defas, 
	    rstats[50];
    integer iwidth, lwidth, nopage;
} miscel_;

#define miscel_1 miscel_

struct {
    doublereal achar, afield[15], oldlin[15];
    integer kntrc, kntlim;
} line_;

#define line_1 line_

struct {
    integer locate[50], jelcnt[50], nunods, ncnods, numnod, nstop, nut, nlt, 
	    nxtrm, ndist, ntlin, ibr, numvs, numalt, numcyc;
} cirdat_;

#define cirdat_1 cirdat_

struct {
    doublereal vto, beta, gamma, phi, phib, cox, xnsub, xnfs, xd, xj, xld, 
	    xlamda, uo, uexp, vbp, utra, vmax, xneff, xl, xw, vbi, von, vdsat,
	     qspof, beta0, beta1, cdrain, xqco, xqc, fnarrw, fshort;
    integer lev;
} mosarg_;

#define mosarg_1 mosarg_

struct {
    doublereal omega, time, delta, delold[7], ag[7], vt, xni, egfet, xmu, 
	    sfactr;
    integer mode, modedc, icalc, initf, method, iord, maxord, noncon, iterno, 
	    itemno, nosolv, modac, ipiv, ivmflg, ipostp, iscrch, iofile;
} status_;

#define status_1 status_

struct {
    integer iprnta, iprntl, iprntm, iprntn, iprnto, limtim, limpts, lvlcod, 
	    lvltim, itl1, itl2, itl3, itl4, itl5, itl6, igoof, nogo, keof;
} flags_;

#define flags_1 flags_

struct {
    doublereal twopi, xlog2, xlog10, root2, rad, boltz, charge, ctok, gmin, 
	    reltol, abstol, vntol, trtol, chgtol, eps0, epssil, epsox, pivtol,
	     pivrel;
} knstnt_;

#define knstnt_1 knstnt_

struct {
    doublereal cpyknt;
    integer istack[1], lorg, icore, maxcor, maxuse, memavl, ldval, numblk, 
	    loctab, ltab, ifwa, nwoff, ntab, maxmem, memerr, nwd4, nwd8, 
	    nwd16;
} memmgr_;

#define memmgr_1 memmgr_

struct {
    doublereal tcstar[2], tcstop[2], tcincr[2];
    integer icvflg, itcelm[2], kssop, kinel, kidin, kovar, kidout;
} dc_;

#define dc_1 dc_

struct {
    doublereal fstart, fstop, fincr, skw2, refprl, spw2;
    integer jacflg, idfreq, inoise, nosprt, nosout, nosin, idist, idprt;
} ac_;

#define ac_1 ac_

struct {
    doublereal tstep, tstop, tstart, delmax, tdmax, forfre;
    integer jtrflg;
} tran_;

#define tran_1 tran_

struct {
    doublereal xincr, string[15], xstart, yvar[8];
    integer itab[8], itype[8], ilogy[8], npoint, numout, kntr, numdgt;
} outinf_;

#define outinf_1 outinf_

struct {
    integer maxtim, itime, icost;
} cje_;

#define cje_1 cje_

struct {
    integer idebug[20];
} debug_;

#define debug_1 debug_

struct {
    doublereal value[200000];
} blank_;

#define blank_1 blank_

/* Table of constant values */

static integer c__50 = 50;
static integer c_n1 = -1;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__7 = 7;
static integer c__20 = 20;
static integer c__10 = 10;
static integer c__72 = 72;
static integer c__15 = 15;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c__23 = 23;
static integer c__24 = 24;
static integer c__12 = 12;
static integer c__48 = 48;
static doublereal c_b2663 = 0.;
static integer c__13 = 13;

/* SPICE VERSION 2G.6  SCCSID=root.ma 3/15/83 */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_30 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_30)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_31 = { "JOB STATISTICS SUMMARY          ", 0. };

#define acctit ((doublereal *)&equiv_31)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_32 = { "  SPICE ", 0. };

#define ahdr1 (*(doublereal *)&equiv_32)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_33 = { "2G.6    ", 0. };

#define ahdr2 (*(doublereal *)&equiv_33)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_34 = { "3/15/83 ", 0. };

#define ahdr3 (*(doublereal *)&equiv_34)


    /* Format strings */
    static char fmt_301[] = "(\0020\002,9x,\002***** JOB ABORTED\002)";
    static char fmt_306[] = "(\0020\002,9x,\002***** THIS PARAMETER CHANGE I"
	    "S ILLEGAL\002)";
    static char fmt_311[] = "(\0020\002,/,9x,\002JOB CONCLUDED\002)";
    static char fmt_361[] = "(\002   NUNODS NCNODS NUMNOD NUMEL  DIODES  BJT"
	    "S  JFETS  MFETS\002//,i9,2i7,i6,i8,i6,2i7)";
    static char fmt_371[] = "(/\0020  NUMTEM ICVFLG JTRFLG JACFLG INOISE  ID"
	    "IST   NOGO\002/,\0020 \002,7i7)";
    static char fmt_381[] = "(/\0020  NSTOP   NTTBR   NTTAR   IFILL    IOPS "
	    "   PERSPA\002//,1x,5f8.0,f9.3)";
    static char fmt_391[] = "(/\0020  NUMTTP  NUMRTP  NUMNIT  MAXMEM  MEMUSE"
	    "  COPYKNT\002,//,2x,3f8.0,2x,i6,2x,i6,2x,f8.0)";
    static char fmt_401[] = "(/,\0020\002,9x,\002READIN  \002,12x,f10.2/,"
	    "\0020\002,9x,\002SETUP   \002,12x,f10.2/,\0020\002,9x,\002TRCURV"
	    "  \002,12x,f10.2,10x,f6.0/,\0020\002,9x,\002DCAN    \002,12x,f10"
	    ".2,10x,f6.0/,\0020\002,9x,\002DCDCMP  \002,12x,f10.3,10x,f6.0/"
	    ",\0020\002,9x,\002DCSOL   \002,12x,f10.3/,\0020\002,9x,\002ACAN "
	    "   \002,12x,f10.2,10x,f6.0/,\0020\002,9x,\002TRANAN  \002,12x,f1"
	    "0.2,10x,f6.0/,\0020\002,9x,\002OUTPUT  \002,12x,f10.2)";
    static char fmt_402[] = "(\0020\002,9x,\002LOAD    \002,12x,f10.3/,\002"
	    "0\002,9x,\002CODGEN  \002,12x,f10.3,10x,f6.0/,\0020\002,9x,\002C"
	    "ODEXC  \002,12x,f10.3/,\0020\002,9x,\002MACINS  \002,12x,f10.3)";
    static char fmt_801[] = "(\0020\002,9x,\002OVERHEAD\002,12x,f10.2)";
    static char fmt_811[] = "(\0020\002,9x,\002TOTAL JOB TIME      \002,f10."
	    "2)";
    static char fmt_901[] = "(\0021WARNING:  FURTHER ANALYSIS STOPPED DUE TO"
	    " CPU TIME LIMIT\002/)";
    static char fmt_1001[] = "(/1x,\002INPUT DECK (FILE) CONTAINS NO DATA"
	    ".\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double atan2(doublereal, doublereal), log(doublereal), sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal et;
    extern /* Subroutine */ int acan_(void), dcop_(void);
    static doublereal time1, time2;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static doublereal ohead;
    extern integer iargc_(void);
    extern /* Subroutine */ int xtime_(doublereal *), xdate_(doublereal *), 
	    setup_(void), alter_(void);
    static integer numel;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static doublereal tcost;
    static integer icost1;
    extern /* Subroutine */ int getcje_(void), readin_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern integer iopraw_(void);
    static integer nodata;
    extern /* Subroutine */ int second_(doublereal *), setmem_(integer *, 
	    integer *), errchk_(void), tmpupd_(void), dctran_(void), ovtpvt_(
	    void);

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_306, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_311, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_361, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_371, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_381, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_391, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_402, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_801, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_811, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_901, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_1001, 0 };


/* ...  CRAY NOTES: */
/* .. CHANGE DATA FILNAM TO 5LSPICE */
/* .. CHANGE CALL OVERLAY .. REMOVE LAST ZERO */
/* .. CHANGE ??????PROGRAM TO SUBROUTINE IN ALL BUT THIS OVERLAY */
/* .. DELETE OVERLAY SPICE,0,0 CARD BELOW */
/* .. */


/* SPICE VERSION 2G.6  SCCSID=root.ma 3/15/83 */

/*     SPICE IS AN ELECTRONIC CIRCUIT SIMULATION PROGRAM THAT WAS DEVE- */
/* LOPED BY THE INTEGRATED CIRCUITS GROUP OF THE ELECTRONICS RESEARCH */
/* LABORATORY AND THE DEPARTMENT OF ELECTRICAL ENGINEERING AND COMPUTER */
/* SCIENCES AT THE UNIVERSITY OF CALIFORNIA, BERKELEY, CALIFORNIA.  THE */
/* PROGRAM SPICE IS AVAILABLE FREE OF CHARGE TO ANY INTERESTED PARTY. */
/* THE SALE, RESALE, OR USE OF THIS PROGRAM FOR PROFIT WITHOUT THE */
/* EXPRESS WRITTEN CONSENT OF THE DEPARTMENT OF ELECTRICAL ENGINEERING */
/* AND COMPUTER SCIENCES, UNIVERSITY OF CALIFORNIA, BERKELEY, CALIFORNIA, */
/* IS FORBIDDEN. */


/*     THE PRESENT VERSION IS BASED ON THE SPICE2 PROGRAM VERSIONS 2E.3 */
/* AND 2F.1 DEVELOPED AT THE UNIVERSITY OF CALIFORNIA BERKELEY AND THE */
/* HEWLETT-PACKARD SPICE VERSION 2.7. */
/*     THIS VERSION IS DESIGNED TO BE TRANSPORTABLE ON MOST COMPUTERS */
/* WITH AN ANSI FORTRAN COMPILER AND ENOUGH MEMORY SPACE FOR CODE AND */
/* DATA. THE MEMORY MANAGER USES THE FUNCTION 'LOCF' TO FIND THE */
/* ADDRESS OF A POINTER; THIS FUNCTION MUST BE PROVIDED. */


/* IMPLEMENTATION NOTES: */

/*     SUBROUTINES MCLOCK AND MDATE RETURN THE TIME (AS HH:MM:SS) AND */
/* THE DATE (AS DD MMM YY), RESPECTIVELY.  SUBROUTINE GETCJE RETURNS IN */
/* COMMON BLOCK /CJE/ VARIOUS ATTRIBUTES OF THE CURRENT JOB ENVIRONMENT. */
/* SPICE EXPECTS GETCJE TO SET /CJE/ VARIABLES MAXTIM, ITIME, AND ICOST. */
/* MAXTIM IS THE MAXIMUM CPU TIME IN SECONDS, ITIME IS THE ELAPSED CPU */
/* TIME IN SECONDS, AND ICOST IS THE JOB COST IN CENTS. */
/* SUBROUTINE MEMORY IS USED TO CHANGE THE NUMBER OF MEMORY WORDS */
/* ALLOCATED TO SPICE.  IF THE AMOUNT OF MEMORY ALLOCATED TO A JOBSTEP */
/* IS FIXED, SUBROUTINE MEMORY NEED NOT BE CHANGED. */
/*     SUBROUTINE SECOND(T) RETURNS THE TIME IN SECONDS AND IS USED */
/* FOR TIMING PURPOSES. IT MUST BE PROVIDED WHERE NOT AVAILABLE. */
/*     IFAMWA (SET IN A DATA STATEMENT BELOW) SHOULD BE SET TO THE */
/* ADDRESS OF THE FIRST AVAILABLE WORD OF MEMORY (FOLLOWING OVERLAYS, IF */
/* ANY).  THE PROPER VALUE SHOULD BE EASILY OBTAINABLE FROM ANY LOAD MAP. */
/* IFAMWA IS USED ONLY ON COMPUTERS WHERE THE PROGRAM (SPICE) CAN CHANGE */
/* THE ALLOCATED MEMORY DYNAMICALLY AT RUN TIME ACCORDING TO CIRCUIT SIZE. */
/* (SEE ALSO COMMENTS UNDER SUBROUTINE SETMEM). */
/*     ALL BERKELEY SPICE2.F RELEASE VERSIONS DO NOT IMPLEMENT THE IFAMWA */
/* FEATURE DUE TO ITS DEPENDENCE ON OPERATING SYSTEM. */
/*     WITH THE EXCEPTION OF MOST FLAGS, ALL DATA IN SPICE ARE STORED IN */
/* THE FORM OF MANAGED TABLES ALLOCATED IN THE /BLANK/ ARRAY VALUE(). */
/* ARRAY VALUE() CAN BE REDIMENSIONED IN THE MAIN PROGRAM ACCORDING TO */
/* MEMORY AVAILABILITY AT EACH USER SITE. IT SHOULD BE NOTED AGAIN THAT */
/* THE PROGRAM DYNAMICALLY MANAGES ITS DATA WITHIN THE BOUNDS OF ARRAY */
/* VALUE(). */
/*     THE VAX RELEASE VERSIONS ASSUME THE VIRTUAL MEMORY FEATURE AND */
/* DIMENSION VALUE() TO 200,000 DOUBLE PRECISION WORDS. */
/*     THE CDC AND IBM VERSIONS DIMENSION VALUE() TO 20000 REAL OR */
/* REAL*8 WORDS, RESPECTIVELY. */
/*     SPICE IS PARTICULARLY WELL-SUITED TO BEING RUN USING A ONE-LEVEL */
/* OVERLAY STRUCTURE BEGINNING WITH ROUTINES SPICE (THE OVERLAY ROOT), */
/* READIN, ERRCHK, SETUP, DCTRAN, DCOP, ACAN, AND OVTPVT.  THE ORDER OF */
/* THE ROUTINES IN THIS LISTING CORRESPONDS TO THAT STRUCTURE.  NOTE */
/* THAT IF CDC EXPLICIT OVERLAYING IS TO BE USED, AN OVERLAY DIRECTIVE */
/* CARD MUST BE INSERTED BEFORE THE FIRST LINE OF EACH OF THE JUST-NAMED */
/* ROUTINES. */


/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */





    status_1.ipostp = 0;
/*     CHECK IF A RAW DATA FILE SHOULD BE WRITTEN */
/*     OPEN FILE IF SO REQUIRED */
    if (iargc_() > 0) {
	status_1.ipostp = iopraw_();
    }
    memmgr_1.maxmem = 400000;
    cje_1.maxtim = 1e8f;
    cje_1.icost = 0;
    status_1.iofile = 6;

/*  INITIALIZATION */

    miscel_1.aprog[0] = ahdr1;
    miscel_1.aprog[1] = ahdr2;
    miscel_1.aprog[2] = ahdr3;
    line_1.achar = ablnk;
    flags_1.keof = 0;
    xtime_(&miscel_1.atime);
    xdate_(&miscel_1.adate);
    knstnt_1.boltz = 1.3806226e-23;
    knstnt_1.charge = 1.6021918e-19;
    knstnt_1.ctok = 273.15;
    knstnt_1.eps0 = 8.854214871e-12;
    knstnt_1.epssil = knstnt_1.eps0 * 11.7;
    knstnt_1.epsox = knstnt_1.eps0 * 3.9;
    knstnt_1.twopi = atan2(1., 1.) * 8.;
    knstnt_1.rad = 360. / knstnt_1.twopi;
    knstnt_1.xlog2 = log(2.);
    knstnt_1.xlog10 = log(10.);
    knstnt_1.root2 = sqrt(2.);
    nodata = 1;

/*  BEGIN JOB */

L10:
    if (flags_1.keof == 1) {
	goto L1000;
    }
    getcje_();
    second_(&time1);
    icost1 = cje_1.icost;
    flags_1.igoof = 0;
    status_1.mode = 0;
    flags_1.nogo = 0;
    setmem_(nodplc, &memmgr_1.maxmem);
    if (flags_1.nogo != 0) {
	goto L1000;
    }
    zero8_(miscel_1.rstats, &c__50);

/*  READ REMAINDER OF DATA DECK AND CHECK FOR INPUT ERRORS */

    readin_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    if (flags_1.keof == 1) {
	goto L1000;
    }
    nodata = 0;
/* L50: */
    errchk_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    setup_();
    if (flags_1.nogo != 0) {
	goto L300;
    }

/*  CHANGE PARAMETERS AND RE-ANALISIS */

    if (cirdat_1.numcyc == 0) {
	goto L90;
    }
L70:
    if (cirdat_1.numcyc >= cirdat_1.numalt) {
	goto L310;
    }
    ++cirdat_1.numcyc;
    alter_();
    if (flags_1.nogo != 0) {
	goto L305;
    }

/*  CYCLE THROUGH TEMPERATURES */

L90:
    status_1.itemno = 1;
    if (tabinf_1.numtem == 1) {
	goto L110;
    }
L100:
    if (status_1.itemno == tabinf_1.numtem) {
	goto L70;
    }
    ++status_1.itemno;
    tmpupd_();

/*  DC TRANSFER CURVES */

L110:
    if (dc_1.icvflg == 0) {
	goto L150;
    }
/* ...  SEE ROUTINE *DCTRAN* FOR EXPLANATION OF *MODE*, ETC. */
    status_1.mode = 1;
    status_1.modedc = 3;
    dctran_();
    ovtpvt_();
    if (flags_1.nogo != 0) {
	goto L300;
    }

/*  SMALL SIGNAL OPERATING POINT */

L150:
    if (dc_1.kssop > 0) {
	goto L170;
    }
    if (ac_1.jacflg != 0) {
	goto L170;
    }
    if (dc_1.icvflg + tran_1.jtrflg > 0) {
	goto L250;
    }
L170:
    status_1.mode = 1;
    status_1.modedc = 1;
    dctran_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    dcop_();
    if (flags_1.nogo != 0) {
	goto L300;
    }

/*  AC SMALL SIGNAL ANALYSIS */

/* L200: */
    if (ac_1.jacflg == 0) {
	goto L250;
    }
    status_1.mode = 3;
    acan_();
    ovtpvt_();
    if (flags_1.nogo != 0) {
	goto L300;
    }

/*  TRANSIENT ANALYSIS */

L250:
    if (tran_1.jtrflg == 0) {
	goto L100;
    }
    status_1.mode = 1;
    status_1.modedc = 2;
    dctran_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    dcop_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    status_1.mode = 2;
    dctran_();
    ovtpvt_();
    if (flags_1.nogo != 0) {
	goto L300;
    }
    goto L100;

/*  JOB CONCLUDED */

L300:
    io___11.ciunit = status_1.iofile;
    s_wsfe(&io___11);
    e_wsfe();
    nodata = 0;
    goto L320;
L305:
    io___12.ciunit = status_1.iofile;
    s_wsfe(&io___12);
    e_wsfe();
L310:
    io___13.ciunit = status_1.iofile;
    s_wsfe(&io___13);
    e_wsfe();

/*  JOB ACCOUNTING */

L320:
    numel = 0;
    for (i__ = 1; i__ <= 18; ++i__) {
/* L360: */
	numel += cirdat_1.jelcnt[i__ - 1];
    }
/* Computing MAX */
    i__1 = tabinf_1.numtem - 1;
    tabinf_1.numtem = max(i__1,1);
    ac_1.idist = min(ac_1.idist,1);
    if (flags_1.iprnta == 0) {
	goto L800;
    }
    title_(&c_n1, &miscel_1.lwidth, &c__1, acctit);
    io___16.ciunit = status_1.iofile;
    s_wsfe(&io___16);
    do_fio(&c__1, (char *)&cirdat_1.nunods, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&cirdat_1.ncnods, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&cirdat_1.numnod, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&numel, (ftnlen)sizeof(integer));
    for (i__ = 11; i__ <= 14; ++i__) {
	do_fio(&c__1, (char *)&cirdat_1.jelcnt[i__ - 1], (ftnlen)sizeof(
		integer));
    }
    e_wsfe();
    io___17.ciunit = status_1.iofile;
    s_wsfe(&io___17);
    do_fio(&c__1, (char *)&tabinf_1.numtem, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&dc_1.icvflg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tran_1.jtrflg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ac_1.jacflg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ac_1.inoise, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ac_1.idist, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.nogo, (ftnlen)sizeof(integer));
    e_wsfe();
    io___18.ciunit = status_1.iofile;
    s_wsfe(&io___18);
    do_fio(&c__1, (char *)&miscel_1.rstats[19], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[20], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[21], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[22], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[25], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[26], (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___19.ciunit = status_1.iofile;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&miscel_1.rstats[29], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[30], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[31], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&memmgr_1.maxmem, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.maxuse, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.cpyknt, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___20.ciunit = status_1.iofile;
    s_wsfe(&io___20);
    for (i__ = 1; i__ <= 6; ++i__) {
	do_fio(&c__1, (char *)&miscel_1.rstats[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    do_fio(&c__1, (char *)&miscel_1.rstats[49], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[48], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[45], (ftnlen)sizeof(doublereal));
    for (i__ = 7; i__ <= 11; ++i__) {
	do_fio(&c__1, (char *)&miscel_1.rstats[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    io___21.ciunit = status_1.iofile;
    s_wsfe(&io___21);
    do_fio(&c__1, (char *)&miscel_1.rstats[44], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[47], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[46], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[43], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.rstats[42], (ftnlen)sizeof(doublereal));
    e_wsfe();
L800:
    getcje_();
    second_(&time2);
    et = time2 - time1;
    tcost = (doublereal) (cje_1.icost - icost1) / 100.;
    if (flags_1.iprnta == 0) {
	goto L810;
    }
    ohead = et - (miscel_1.rstats[0] + miscel_1.rstats[1] + miscel_1.rstats[2]
	     + miscel_1.rstats[4] + miscel_1.rstats[6] + miscel_1.rstats[8] + 
	    miscel_1.rstats[10]);
    io___26.ciunit = status_1.iofile;
    s_wsfe(&io___26);
    do_fio(&c__1, (char *)&ohead, (ftnlen)sizeof(doublereal));
    e_wsfe();
L810:
    io___27.ciunit = status_1.iofile;
    s_wsfe(&io___27);
    do_fio(&c__1, (char *)&et, (ftnlen)sizeof(doublereal));
    e_wsfe();
    miscel_1.rstats[32] = memmgr_1.cpyknt;
    miscel_1.rstats[33] = et;
    miscel_1.rstats[34] = tcost;
    miscel_1.rstats[35] = ohead;
/* L900: */
    if (cje_1.maxtim - cje_1.itime >= flags_1.limtim) {
	goto L10;
    }
    io___28.ciunit = status_1.iofile;
    s_wsfe(&io___28);
    e_wsfe();
L1000:
    if (nodata != 0) {
	io___29.ciunit = status_1.iofile;
	s_wsfe(&io___29);
	e_wsfe();
    }
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

#undef cvalue
#undef nodplc
#undef ahdr3
#undef ahdr2
#undef ahdr1
#undef acctit
#undef ablnk


/* Subroutine */ int tmpupd_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_98 = { "TEMPERATURE-ADJUSTED VALUES     ", 0. };

#define tmptit ((doublereal *)&equiv_98)


    /* Format strings */
    static char fmt_21[] = "(//\0020**** RESISTORS\002,/,\0020NAME\002,8x"
	    ",\002VALUE\002,//)";
    static char fmt_31[] = "(1x,a8,1p6d11.3)";
    static char fmt_101[] = "(//\0020**** DIODE MODEL PARAMETERS\002,/,\0020"
	    "NAME\002,9x,\002IS\002,9x,\002VJ\002,8x,\002CJO\002,//)";
    static char fmt_201[] = "(//\0020**** BJT MODEL PARAMETERS\002,/,\0020NA"
	    "ME\002,9x,\002JS\002,8x,\002BF \002,7x,\002ISE\002,7x,\002BR "
	    "\002,7x,\002ISC\002,7x,\002VJE\002,7x,\002CJE\002,7x,\002VJC\002"
	    ",7x,\002CJC\002,//)";
    static char fmt_211[] = "(1x,a8,1p9d10.3)";
    static char fmt_301[] = "(//\0020**** JFET MODEL PARAMETERS\002,/,\0020N"
	    "AME\002,9x,\002IS\002,9x,\002PB\002,8x,\002CGS\002,8x,\002CGD"
	    "\002,//)";
    static char fmt_401[] = "(//\0020**** MOSFET MODEL PARAMETERS\002,/,\002"
	    "0NAME\002,8x,\002VTO\002,8x,\002PHI\002,9x,\002PB\002,7x,\002IS("
	    "JS)\002,7x,\002KP\002,9x,\002UO\002//)";

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double log(doublereal), sqrt(doublereal), exp(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static doublereal tb, xn, tc1, tc2, vt1, arg;
    static integer loc;
    static doublereal vfb, pbo, phi, vte, xkt, arg1, xkt1, delt, csat, phio;
    static integer locv;
    static doublereal rnew, type__, fact1, fact2, temp1, temp2, oldeg, oldpb, 
	    dtemp, pbrat, ratio, oldvt;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer iprnt;
    static doublereal egfet1, pbfat1, ratio1, ratio4, cjfact, pbfact, bfactr, 
	    oldcjf, gmaold, coeold, factor;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal reftmp, ratlog, deltsq;
    static integer ititle;
    static doublereal gmanew, factln, oldphi, coenew;

    /* Fortran I/O blocks */
    static cilist io___64 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___66 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___67 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___76 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___77 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___81 = { 0, 0, 0, fmt_211, 0 };
    static cilist io___82 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___85 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___88 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___97 = { 0, 0, 0, fmt_31, 0 };



/*     THIS ROUTINE UPDATES THE TEMPERATURE-DEPENDENT PARAMETERS IN THE */
/* DEVICE MODELS.  IT ALSO UPDATES THE VALUES OF TEMPERATURE-DEPENDENT */
/* RESISTORS.  THE UPDATED VALUES ARE PRINTED. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    reftmp = 27. + knstnt_1.ctok;
    temp1 = blank_1.value[tabinf_1.itemps + status_1.itemno - 2] + 
	    knstnt_1.ctok;
    temp2 = blank_1.value[tabinf_1.itemps + status_1.itemno - 1] + 
	    knstnt_1.ctok;
    xkt = knstnt_1.boltz * temp2;
    oldvt = status_1.vt;
    status_1.vt = xkt / knstnt_1.charge;
    oldeg = status_1.egfet;
    status_1.egfet = 1.16 - temp2 * 7.02e-4 * temp2 / (temp2 + 1108.);
    arg = -status_1.egfet / (xkt + xkt) + 1.1150877 / (knstnt_1.boltz * (
	    reftmp + reftmp));
    ratio = temp2 / temp1;
    ratlog = log(ratio);
    ratio1 = ratio - 1.;
    dtemp = temp2 - reftmp;
    delt = blank_1.value[tabinf_1.itemps + status_1.itemno - 1] - 
	    blank_1.value[tabinf_1.itemps];
    deltsq = delt * delt;
    fact2 = temp2 / reftmp;
    status_1.xni = fact2 * 1.45e16 * sqrt(fact2) * exp(knstnt_1.charge * arg);
    pbfact = status_1.vt * -2 * (log(fact2) * 1.5 + knstnt_1.charge * arg);
    xkt1 = knstnt_1.boltz * temp1;
    vt1 = xkt1 / knstnt_1.charge;
    egfet1 = 1.16 - temp1 * 7.02e-4 * temp1 / (temp1 + 1108.);
    arg1 = -egfet1 / (xkt1 + xkt1) + 1.1150877 / (knstnt_1.boltz * (reftmp + 
	    reftmp));
    fact1 = temp1 / reftmp;
    pbfat1 = vt1 * -2 * (log(fact1) * 1.5 + knstnt_1.charge * arg1);
/* L5: */
    title_(&c__0, &miscel_1.lwidth, &c__1, tmptit);

/*  RESISTORS */

    loc = cirdat_1.locate[0];
    ititle = 0;
L10:
    if (loc == 0) {
	goto L100;
    }
    locv = nodplc[loc];
    tc1 = blank_1.value[locv + 2];
    tc2 = blank_1.value[locv + 3];
    if (tc1 != 0.) {
	goto L20;
    }
    if (tc2 == 0.) {
	goto L40;
    }
L20:
    if (ititle != 0) {
	goto L30;
    }
    io___64.ciunit = status_1.iofile;
    s_wsfe(&io___64);
    e_wsfe();
    ititle = 1;
L30:
    rnew = blank_1.value[locv + 1] * (tc1 * delt + 1. + tc2 * deltsq);
    blank_1.value[locv] = 1. / rnew;
    io___66.ciunit = status_1.iofile;
    s_wsfe(&io___66);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&rnew, (ftnlen)sizeof(doublereal));
    e_wsfe();
L40:
    loc = nodplc[loc - 1];
    goto L10;

/*  DIODE MODEL */

L100:
    loc = cirdat_1.locate[20];
    if (loc == 0) {
	goto L200;
    }
    io___67.ciunit = status_1.iofile;
    s_wsfe(&io___67);
    e_wsfe();
L110:
    if (loc == 0) {
	goto L200;
    }
    locv = nodplc[loc];
/* ...  IS(T2)=IS(T1)*DEXP(EG/(N*VT)*(T2/T1-1))*(T2/T1)**(XTI/N) */
    xn = blank_1.value[locv + 2];
    factor = ratio1 * blank_1.value[locv + 7] / (xn * status_1.vt) + 
	    blank_1.value[locv + 8] / xn * ratlog;
    factor = exp(factor);
    blank_1.value[locv] *= factor;
    oldpb = blank_1.value[locv + 5];
    pbo = (blank_1.value[locv + 5] - pbfat1) / fact1;
    gmaold = (oldpb - pbo) / pbo;
    blank_1.value[locv + 4] /= blank_1.value[locv + 6] * ((temp1 - reftmp) * 
	    4e-4 - gmaold) + 1.;
/* L120: */
    blank_1.value[locv + 5] = fact2 * pbo + pbfact;
    gmanew = (blank_1.value[locv + 5] - pbo) / pbo;
    blank_1.value[locv + 4] *= blank_1.value[locv + 6] * (dtemp * 4e-4 - 
	    gmanew) + 1.;
    pbrat = blank_1.value[locv + 5] / oldpb;
    blank_1.value[locv + 11] *= pbrat;
    blank_1.value[locv + 14] *= pbrat;
    vte = blank_1.value[locv + 2] * status_1.vt;
    blank_1.value[locv + 17] = vte * log(vte / (knstnt_1.root2 * 
	    blank_1.value[locv]));
    io___76.ciunit = status_1.iofile;
    s_wsfe(&io___76);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 5], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 4], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
    loc = nodplc[loc - 1];
    goto L110;

/*  BIPOLAR TRANSISTOR MODEL */

L200:
    loc = cirdat_1.locate[21];
    if (loc == 0) {
	goto L300;
    }
    io___77.ciunit = status_1.iofile;
    s_wsfe(&io___77);
    e_wsfe();
L210:
    if (loc == 0) {
	goto L300;
    }
    locv = nodplc[loc];
/* ...  IS(T2)=IS(T1)*DEXP(EG/VT*(T2/T1-1))*(T2/T1)**XTI */
    factln = ratio1 * blank_1.value[locv + 41] / status_1.vt + blank_1.value[
	    locv + 42] * ratlog;
    factor = exp(factln);
    blank_1.value[locv] *= factor;
    tb = blank_1.value[locv + 40];
    bfactr = exp(tb * ratlog);
    blank_1.value[locv + 1] *= bfactr;
    blank_1.value[locv + 7] *= bfactr;
    blank_1.value[locv + 5] = blank_1.value[locv + 5] * exp(factln / 
	    blank_1.value[locv + 6]) / bfactr;
    blank_1.value[locv + 11] = blank_1.value[locv + 11] * exp(factln / 
	    blank_1.value[locv + 12]) / bfactr;
    oldpb = blank_1.value[locv + 21];
    pbo = (blank_1.value[locv + 21] - pbfat1) / fact1;
    gmaold = (oldpb - pbo) / pbo;
    blank_1.value[locv + 20] /= blank_1.value[locv + 22] * ((temp1 - reftmp) *
	     4e-4 - gmaold) + 1.;
/* L220: */
    blank_1.value[locv + 21] = fact2 * pbo + pbfact;
    gmanew = (blank_1.value[locv + 21] - pbo) / pbo;
    blank_1.value[locv + 20] *= blank_1.value[locv + 22] * (dtemp * 4e-4 - 
	    gmanew) + 1.;
    pbrat = blank_1.value[locv + 21] / oldpb;
    blank_1.value[locv + 45] *= pbrat;
    blank_1.value[locv + 46] *= pbrat;
    oldpb = blank_1.value[locv + 29];
    pbo = (blank_1.value[locv + 29] - pbfat1) / fact1;
    gmaold = (oldpb - pbo) / pbo;
    blank_1.value[locv + 28] /= blank_1.value[locv + 30] * ((temp1 - reftmp) *
	     4e-4 - gmaold) + 1.;
/* L230: */
    blank_1.value[locv + 29] = fact2 * pbo + pbfact;
    gmanew = (blank_1.value[locv + 29] - pbo) / pbo;
    blank_1.value[locv + 28] *= blank_1.value[locv + 30] * (dtemp * 4e-4 - 
	    gmanew) + 1.;
    pbrat = blank_1.value[locv + 29] / oldpb;
    blank_1.value[locv + 49] *= pbrat;
    blank_1.value[locv + 50] *= pbrat;
    blank_1.value[locv + 53] = status_1.vt * log(status_1.vt / (
	    knstnt_1.root2 * blank_1.value[locv]));
    io___81.ciunit = status_1.iofile;
    s_wsfe(&io___81);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 5], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 7], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 11], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 21], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 20], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 29], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 28], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    loc = nodplc[loc - 1];
    goto L210;

/*  JFET MODEL */

L300:
    loc = cirdat_1.locate[22];
    if (loc == 0) {
	goto L400;
    }
    io___82.ciunit = status_1.iofile;
    s_wsfe(&io___82);
    e_wsfe();
L310:
    if (loc == 0) {
	goto L400;
    }
    locv = nodplc[loc];
    blank_1.value[locv + 8] *= exp(ratio1 * 1.11 / status_1.vt);
    oldpb = blank_1.value[locv + 7];
    pbo = (blank_1.value[locv + 7] - pbfat1) / fact1;
    gmaold = (oldpb - pbo) / pbo;
    oldcjf = ((temp1 - reftmp) * 4e-4 - gmaold) * .5 + 1.;
    blank_1.value[locv + 5] /= oldcjf;
    blank_1.value[locv + 6] /= oldcjf;
/* L320: */
    blank_1.value[locv + 7] = fact2 * pbo + pbfact;
    gmanew = (blank_1.value[locv + 7] - pbo) / pbo;
    cjfact = (dtemp * 4e-4 - gmanew) * .5 + 1.;
    blank_1.value[locv + 5] *= cjfact;
    blank_1.value[locv + 6] *= cjfact;
    pbrat = blank_1.value[locv + 7] / oldpb;
    blank_1.value[locv + 11] *= pbrat;
    blank_1.value[locv + 12] *= pbrat;
    blank_1.value[locv + 15] = status_1.vt * log(status_1.vt / (
	    knstnt_1.root2 * blank_1.value[locv + 8]));
    io___85.ciunit = status_1.iofile;
    s_wsfe(&io___85);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 8], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 7], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 5], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 6], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
    loc = nodplc[loc - 1];
    goto L310;

/*  MOSFET MODEL */

L400:
    loc = cirdat_1.locate[23];
    iprnt = 1;
L410:
    if (loc == 0) {
	goto L1000;
    }
    locv = nodplc[loc];
    type__ = (doublereal) nodplc[loc + 1];
    if (iprnt != 0) {
	io___88.ciunit = status_1.iofile;
	s_wsfe(&io___88);
	e_wsfe();
    }
    iprnt = 0;
    ratio4 = ratio * sqrt(ratio);
    blank_1.value[locv + 2] /= ratio4;
    blank_1.value[locv + 28] /= ratio4;
    oldphi = blank_1.value[locv + 4];
    phio = (blank_1.value[locv + 4] - pbfat1) / fact1;
/* L415: */
    blank_1.value[locv + 4] = fact2 * phio + pbfact;
    phi = blank_1.value[locv + 4];
    vfb = blank_1.value[locv + 43] - type__ * .5 * oldphi;
    vfb += (oldeg - status_1.egfet) * .5;
    blank_1.value[locv + 43] = vfb + type__ * .5 * phi;
    blank_1.value[locv + 1] = blank_1.value[locv + 43] + type__ * 
	    blank_1.value[locv + 3] * sqrt(phi);
    blank_1.value[locv + 10] *= exp(-status_1.egfet / status_1.vt + oldeg / 
	    oldvt);
    blank_1.value[locv + 20] *= exp(-status_1.egfet / status_1.vt + oldeg / 
	    oldvt);
    oldpb = blank_1.value[locv + 11];
    pbo = (blank_1.value[locv + 11] - pbfat1) / fact1;
    gmaold = (oldpb - pbo) / pbo;
    coeold = blank_1.value[locv + 17] * ((temp1 - reftmp) * 4e-4 - gmaold) + 
	    1.;
    blank_1.value[locv + 8] /= coeold;
    blank_1.value[locv + 9] /= coeold;
    blank_1.value[locv + 16] /= coeold;
    blank_1.value[locv + 18] /= blank_1.value[locv + 19] * ((temp1 - reftmp) *
	     4e-4 - gmaold) + 1.;
/* L420: */
    blank_1.value[locv + 11] = fact2 * pbo + pbfact;
    gmanew = (blank_1.value[locv + 11] - pbo) / pbo;
    coenew = blank_1.value[locv + 17] * (dtemp * 4e-4 - gmanew) + 1.;
    blank_1.value[locv + 8] *= coenew;
    blank_1.value[locv + 9] *= coenew;
    blank_1.value[locv + 16] *= coenew;
    blank_1.value[locv + 18] *= blank_1.value[locv + 19] * (dtemp * 4e-4 - 
	    gmanew) + 1.;
    pbrat = blank_1.value[locv + 11] / oldpb;
    blank_1.value[locv + 36] *= pbrat;
    blank_1.value[locv + 37] *= pbrat;
/* Computing MAX */
    d__1 = blank_1.value[locv + 10], d__2 = blank_1.value[locv + 20];
    csat = max(d__1,d__2);
    io___97.ciunit = status_1.iofile;
    s_wsfe(&io___97);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 4], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 11], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&csat, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 2], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 28], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
/* L430: */
    loc = nodplc[loc - 1];
    goto L410;

/*  FINISHED */

L1000:
    return 0;
} /* tmpupd_ */

#undef cvalue
#undef nodplc
#undef tmptit


/* Subroutine */ int find_(doublereal *aname, integer *id, integer *loc, 
	integer *iforce)
{
    /* Initialized data */

    static integer lnod[50] = { 10,14,16,8,15,16,15,16,13,8,18,38,27,35,8,8,
	    35,5,5,5,5,5,5,5,0,0,0,0,0,0,21,21,21,21,21,21,21,21,21,21,8,8,8,
	    8,8,0,0,0,0,0 };
    static integer lval[50] = { 5,4,4,2,1,1,1,1,4,4,3,4,4,16,1,1,9,2,1,1,19,
	    55,17,46,0,0,0,0,0,0,1,1,1,1,1,17,17,17,17,17,1,1,1,1,1,0,0,0,0,0 
	    };
    static struct {
	char e_1[4];
	integer e_2;
	} equiv_114 = { ".U  ", 0 };

#define ndefin (*(integer *)&equiv_114)


    /* Format strings */
    static char fmt_26[] = "(\0020*ERROR*:  ABOVE LINE ATTEMPTS TO REDEFINE"
	    " \002,a8/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal anam;
    static integer locn, loct, locv, ktmp, iptr;
    extern integer xxor_(doublereal *, doublereal *);
    extern /* Subroutine */ int zero4_(integer *, integer *), zero8_(
	    doublereal *, integer *);
    static integer itemp, isize, nword;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    extern integer nxtevn_(integer *);
    extern /* Subroutine */ int extmem_(integer *, integer *), undefi_(
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___109 = { 0, 0, 0, fmt_26, 0 };



/*     THIS ROUTINE SEARCHES THE LIST WITH NUMBER 'ID' FOR AN ELEMENT */
/* WITH NAME 'ANAME'.  LOC IS SET TO POINT TO THE ELEMENT.  IF IFORCE IS */
/* NONZERO, THEN FIND EXPECTS TO HAVE TO ADD THE ELEMENT TO THE LIST, AND */
/* REPORTS A FATAL ERROR IF THE ELEMENT IS FOUND.  IF SUBCIRCUIT DEFINI- */
/* TION IS IN PROGRESS (NONZERO VALUE FOR NSBCKT), THEN FIND SEARCHES THE */
/* CURRENT SUBCIRCUIT DEFINITION LIST RATHER THAN THE NOMINAL ELEMENT */
/* LIST. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  INDEX TO THE CONTENTS OF THE VARIOUS LISTS: */

/*        LIST      CONTENTS */
/*        ----      -------- */

/*          1       RESISTORS */
/*          2       NONLINEAR CAPACITORS */
/*          3       NONLINEAR INDUCTORS */
/*          4       MUTUAL INDUCTORS */
/*          5       NONLINEAR VOLTAGE CONTROLLED CURRENT SOURCES */
/*          6       NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */
/*          7       NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */
/*          8       NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */
/*          9       INDEPENDENT VOLTAGE SOURCES */
/*         10       INDEPENDENT CURRENT SOURCES */
/*         11       DIODES */
/*         12       BIPOLAR JUNCTION TRANSISTORS */
/*         13       JUNCTION FIELD-EFFECT TRANSISTORS (JFETS) */
/*         14       METAL-OXIDE-SEMICONDUCTOR JUNCTION FETS (MOSFETS) */
/*         15       S-PARAMETER 2-PORT NETWORK */
/*         16       Y-PARAMETER 2-PORT NETWORK */
/*         17       TRANSMISSION LINES */
/*         18       USED FOR TEMPERATURE SWEEPING */
/*         19       SUBCIRCUIT CALLS */
/*         20       SUBCIRCUIT DEFINITIONS */
/*         21       DIODE MODEL */
/*         22       BJT MODEL */
/*         23       JFET MODEL */
/*         24       MOSFET MODEL */
/*      25-30       <UNUSED> */
/*         31       .PRINT DC */
/*         32       .PRINT TRAN */
/*         33       .PRINT AC */
/*         34       .PRINT NOISE */
/*         35       .PRINT DISTORTION */
/*         36       .PLOT DC */
/*         37       .PLOT TR */
/*         38       .PLOT AC */
/*         39       .PLOT NOISE */
/*         40       .PLOT DISTORTION */
/*         41       OUTPUTS FOR DC */
/*         42       OUTPUTS FOR TRANSIENT */
/*         43       OUTPUTS FOR AC */
/*         44       OUTPUTS FOR NOISE */
/*         45       OUTPUTS FOR DISTORTION */
/*      46-50       <UNUSED> */



    anam = *aname;
    sizmem_(&tabinf_1.ielmnt, &isize);
    locn = tabinf_1.ielmnt + isize + 2;
    if (tabinf_1.nsbckt == 0) {
	goto L10;
    }
    loct = nodplc[tabinf_1.isbckt + tabinf_1.nsbckt - 1];
    *loc = nodplc[loct + 2];
    if (*loc != 0) {
	goto L20;
    }
    nodplc[loct + 2] = locn;
    goto L60;
L10:
    *loc = cirdat_1.locate[*id - 1];
    if (*loc != 0) {
	goto L20;
    }
    cirdat_1.locate[*id - 1] = locn;
    goto L50;

/*  SEARCH LIST FOR A NAME MATCH */

L20:
    locv = nodplc[*loc];
    if (xxor_(&anam, &blank_1.value[locv - 1]) != 0) {
	goto L30;
    }
    if (cirdat_1.numalt != 0) {
	goto L30;
    }
    if (tabinf_1.nsbckt == 0) {
	goto L25;
    }
    if (nodplc[*loc - 2] != *id) {
	goto L30;
    }
L25:
    if (nodplc[*loc + 1] == ndefin) {
	goto L200;
    }
    if (*iforce == 0) {
	goto L200;
    }
    io___109.ciunit = status_1.iofile;
    s_wsfe(&io___109);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.nogo = 1;
L30:
    if (nodplc[*loc - 1] == 0) {
	goto L40;
    }
    *loc = nodplc[*loc - 1];
    goto L20;

/*  RESERVE SPACE FOR THIS ELEMENT */

L40:
    nodplc[*loc - 1] = locn;
    if (tabinf_1.nsbckt != 0) {
	goto L60;
    }
L50:
    if (cirdat_1.numalt == 0) {
	++cirdat_1.jelcnt[*id - 1];
    }
L60:
    *loc = locn;
    itemp = *loc + lnod[*id - 1] * memmgr_1.nwd4 - 1;
    i__1 = itemp - 1;
    locv = nxtevn_(&i__1) + 1;
    itemp = locv - itemp;
    ktmp = lnod[*id - 1] * memmgr_1.nwd4 + lval[*id - 1] * memmgr_1.nwd8 + 
	    itemp;
    extmem_(&tabinf_1.ielmnt, &ktmp);
    locv = (locv - 1) / memmgr_1.nwd8 + 1;
    iptr = 0;
    if (tabinf_1.nsbckt == 0) {
	goto L80;
    }
    iptr = *id;
L80:
    if (*id <= 24) {
	nodplc[*loc + lnod[*id - 1] - 3] = cirdat_1.numalt;
    }
    nodplc[*loc - 2] = iptr;
    nodplc[*loc - 1] = 0;
    nodplc[*loc] = locv;
    blank_1.value[locv - 1] = anam;

/*  BACKGROUND STORAGE */

/* L100: */
    nodplc[*loc + 1] = ndefin;
    nword = lnod[*id - 1] - 4;
    if (*id <= 24) {
	--nword;
    }
    if (nword < 1) {
	goto L120;
    }
    zero4_(&nodplc[*loc + 2], &nword);
L120:
    nword = lval[*id - 1] - 1;
    if (nword < 1) {
	goto L200;
    }
    zero8_(&blank_1.value[locv], &nword);
    if (*id >= 21 && *id <= 24) {
	undefi_(&blank_1.value[locv], &nword);
    }

/*  EXIT */

L200:
    return 0;
} /* find_ */

#undef cvalue
#undef nodplc
#undef ndefin


/* Subroutine */ int alter_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_130 = { "CHANGE FOLLOWING PARAMETERS     ", 0. };

#define chtitl ((doublereal *)&equiv_130)

    static integer lnod[50] = { 10,14,16,8,15,16,15,16,13,8,18,38,27,35,8,8,
	    35,5,5,5,5,5,5,5,0,0,0,0,0,0,21,21,21,21,21,21,21,21,21,21,8,8,8,
	    8,8,0,0,0,0,0 };
    static integer lval[50] = { 5,4,4,2,1,1,1,1,4,4,3,4,4,16,1,1,9,2,1,1,19,
	    55,17,46,0,0,0,0,0,0,1,1,1,1,1,17,17,17,17,17,1,1,1,1,1,0,0,0,0,0 
	    };

    /* Format strings */
    static char fmt_110[] = "(\002********      \002,a8,\002      *******"
	    "*\002)";
    static char fmt_360[] = "(//)";
    static char fmt_401[] = "(\0020*ERROR*:  PARAMETER CHANGE FAILED\002,/"
	    ",\0020*******:  \002,a8,\002 IS NOT IN THE ORIGINAL CIRCUIT\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer id, loc, loc1, itab, locv, nogo;
    extern integer xxor_(doublereal *, doublereal *);
    static integer locv1;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *),
	     title_(integer *, integer *, integer *, doublereal *), cpytb4_(
	    integer *, integer *), cpytb8_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern logical memptr_(integer *);
    extern /* Subroutine */ int clrmem_(integer *);

    /* Fortran I/O blocks */
    static cilist io___125 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___127 = { 0, 0, 0, fmt_360, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_401, 0 };



/*     THIS ROUTINE CHANGES THE ELEMENT OR DEVICE PARAMETERS */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */


    title_(&c__0, &miscel_1.lwidth, &c__1, chtitl);
    for (id = 1; id <= 24; ++id) {
	loc = cirdat_1.locate[id - 1];
L10:
	if (loc == 0) {
	    goto L350;
	}
	if (nodplc[loc + lnod[id - 1] - 3] != cirdat_1.numcyc) {
	    goto L300;
	}
	locv = nodplc[loc];
	loc1 = cirdat_1.locate[id - 1];
L50:
	if (loc1 == 0) {
	    goto L400;
	}
	if (nodplc[loc1 + lnod[id - 1] - 3] != 0) {
	    goto L400;
	}
	locv1 = nodplc[loc1];
	if (xxor_(&blank_1.value[locv - 1], &blank_1.value[locv1 - 1]) == 0) {
	    goto L100;
	}
	loc1 = nodplc[loc1 - 1];
	goto L50;

/*  COPY CHANGED VALUES TO THE ORIGINAL TABLES */

/*  COPY REAL PART */

L100:
	copy8_(&blank_1.value[locv - 1], &blank_1.value[locv1 - 1], &lval[id 
		- 1]);
	io___125.ciunit = status_1.iofile;
	s_wsfe(&io___125);
	do_fio(&c__1, (char *)&blank_1.value[locv1 - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();

/*  TREAT NON-NODE TABLES SPECIALLY */

/* L200: */
	if (id >= 11) {
	    goto L300;
	}
	switch (id) {
	    case 1:  goto L300;
	    case 2:  goto L210;
	    case 3:  goto L220;
	    case 4:  goto L300;
	    case 5:  goto L230;
	    case 6:  goto L240;
	    case 7:  goto L230;
	    case 8:  goto L240;
	    case 9:  goto L260;
	    case 10:  goto L260;
	}
L210:
	if (nodplc[loc + 3] == 1) {
	    goto L300;
	}
	if (memptr_(&nodplc[loc1 + 6])) {
	    clrmem_(&nodplc[loc1 + 6]);
	}
	i__1 = loc + 7;
	i__2 = loc1 + 7;
	cpytb8_(&i__1, &i__2);
	goto L300;
L220:
	if (nodplc[loc + 3] == 1) {
	    goto L300;
	}
	if (memptr_(&nodplc[loc1 + 9])) {
	    clrmem_(&nodplc[loc1 + 9]);
	}
	i__1 = loc + 10;
	i__2 = loc1 + 10;
	cpytb8_(&i__1, &i__2);
	goto L300;
L230:
	itab = 5;
	goto L250;
L240:
	itab = 6;
L250:
	if (id <= 6) {
	    goto L255;
	}
	if (memptr_(&nodplc[loc1 + itab])) {
	    clrmem_(&nodplc[loc1 + itab]);
	}
	i__1 = loc + itab + 1;
	i__2 = loc1 + itab + 1;
	cpytb4_(&i__1, &i__2);
L255:
	if (memptr_(&nodplc[loc1 + itab + 1])) {
	    clrmem_(&nodplc[loc1 + itab + 1]);
	}
	i__1 = loc + itab + 2;
	i__2 = loc1 + itab + 2;
	cpytb4_(&i__1, &i__2);
	if (memptr_(&nodplc[loc1 + itab + 2])) {
	    clrmem_(&nodplc[loc1 + itab + 2]);
	}
	i__1 = loc + itab + 3;
	i__2 = loc1 + itab + 3;
	cpytb8_(&i__1, &i__2);
	if (memptr_(&nodplc[loc1 + itab + 3])) {
	    clrmem_(&nodplc[loc1 + itab + 3]);
	}
	i__1 = loc + itab + 4;
	i__2 = loc1 + itab + 4;
	cpytb8_(&i__1, &i__2);
	if (memptr_(&nodplc[loc1 + itab + 4])) {
	    clrmem_(&nodplc[loc1 + itab + 4]);
	}
	i__1 = loc + itab + 5;
	i__2 = loc1 + itab + 5;
	cpytb4_(&i__1, &i__2);
	if (memptr_(&nodplc[loc1 + itab + 5])) {
	    clrmem_(&nodplc[loc1 + itab + 5]);
	}
	i__1 = loc + itab + 6;
	i__2 = loc1 + itab + 6;
	cpytb8_(&i__1, &i__2);
	goto L300;
L260:
	if (memptr_(&nodplc[loc1 + 4])) {
	    clrmem_(&nodplc[loc1 + 4]);
	}
	i__1 = loc + 5;
	i__2 = loc1 + 5;
	cpytb8_(&i__1, &i__2);

L300:
	loc = nodplc[loc - 1];
	goto L10;
L350:
	;
    }
    io___127.ciunit = status_1.iofile;
    s_wsfe(&io___127);
    e_wsfe();
    goto L500;

L400:
    io___128.ciunit = status_1.iofile;
    s_wsfe(&io___128);
    do_fio(&c__1, (char *)&blank_1.value[nodplc[loc1] - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    nogo = 1;

L500:
    return 0;
} /* alter_ */

#undef cvalue
#undef nodplc
#undef chtitl


/* Subroutine */ int title_(integer *ifold, integer *len, integer *icom, 
	doublereal *coment)
{
    /* Format strings */
    static char fmt_31[] = "(\0021\002,16(\002*\002),a8,1x,24(\002*\002),3a8"
	    ",24(\002*\002),a8,16(\002*\002),//\0020\002,15a8/)";
    static char fmt_36[] = "(\0020****\002,17x,4a8,21x,\002TEMPERATURE =\002"
	    ",f9.3,\002 DEG C\002/)";
    static char fmt_41[] = "(\0020\002,121(\002*\002)//)";
    static char fmt_101[] = "(\0021\002,7(\002*\002),a8,1x,8(\002*\002),3a8,"
	    "8(\002*\002),a8,5(\002*\002)//\0020\002,10a8/)";
    static char fmt_106[] = "(\0020****     \002,4a8,\002 TEMPERATURE =\002,"
	    "f9.3,\002 DEG C\002/)";
    static char fmt_111[] = "(\0020\002,71(\002*\002)//)";
    static char fmt_161[] = "(\0020\002,3a8,/)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

    /* Fortran I/O blocks */
    static cilist io___133 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___135 = { 0, 0, 0, fmt_36, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___137 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___138 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___139 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___140 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___141 = { 0, 0, 0, fmt_161, 0 };



/*     THIS ROUTINE WRITES A TITLE ON THE OUTPUT FILE.  IFOLD INDICATES */
/* WHETHER THE PAGE EJECT SHOULD BE TO THE NEXT CONCAVE, CONVEX, OR ANY */
/* PAGE FOLD DEPENDING ON WHETHER ITS VALUE IS <0, >0, OR =0.  THE PAGE */
/* EJECT IS SUPPRESSED (AS IS MUCH OF THE HEADING) IF THE VARIABLE NOPAGE */
/* IS NONZERO. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    /* Parameter adjustments */
    --coment;

    /* Function Body */
    if (miscel_1.nopage == 1) {
	goto L150;
    }

/* L30: */
    if (*len <= 80) {
	goto L100;
    }
    io___133.ciunit = status_1.iofile;
    s_wsfe(&io___133);
    do_fio(&c__1, (char *)&miscel_1.adate, (ftnlen)sizeof(doublereal));
    do_fio(&c__3, (char *)&miscel_1.aprog[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.atime, (ftnlen)sizeof(doublereal));
    for (i__ = 1; i__ <= 10; ++i__) {
	do_fio(&c__1, (char *)&miscel_1.atitle[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    if (*icom == 0) {
	goto L40;
    }
    io___135.ciunit = status_1.iofile;
    s_wsfe(&io___135);
    do_fio(&c__4, (char *)&coment[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.itemps + status_1.itemno - 
	    1], (ftnlen)sizeof(doublereal));
    e_wsfe();
L40:
    io___136.ciunit = status_1.iofile;
    s_wsfe(&io___136);
    e_wsfe();
    goto L200;


L100:
    io___137.ciunit = status_1.iofile;
    s_wsfe(&io___137);
    do_fio(&c__1, (char *)&miscel_1.adate, (ftnlen)sizeof(doublereal));
    do_fio(&c__3, (char *)&miscel_1.aprog[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.atime, (ftnlen)sizeof(doublereal));
    for (i__ = 1; i__ <= 10; ++i__) {
	do_fio(&c__1, (char *)&miscel_1.atitle[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    if (*icom == 0) {
	goto L110;
    }
    io___138.ciunit = status_1.iofile;
    s_wsfe(&io___138);
    do_fio(&c__4, (char *)&coment[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.itemps + status_1.itemno - 
	    1], (ftnlen)sizeof(doublereal));
    e_wsfe();
L110:
    io___139.ciunit = status_1.iofile;
    s_wsfe(&io___139);
    e_wsfe();
    goto L200;


L150:
    if (*icom == 0) {
	goto L160;
    }
    io___140.ciunit = status_1.iofile;
    s_wsfe(&io___140);
    do_fio(&c__4, (char *)&coment[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.itemps + status_1.itemno - 
	    1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L200;
L160:
    io___141.ciunit = status_1.iofile;
    s_wsfe(&io___141);
    do_fio(&c__3, (char *)&miscel_1.aprog[0], (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  FINISHED */

L200:
    return 0;
} /* title_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int dcdcmp_(void)
{
    /* Format strings */
    static char fmt_51[] = "(\0020*ERROR*:  MAXIMUM ENTRY IN THIS COLUMN AT "
	    "STEP \002,i4,\002 (\002,1pd12.6,\002) IS LESS THAN PIVTOL\002)";
    static char fmt_92[] = "(\0020*ABORT*:  PIVOT NOT IN DCDCMP\002)";
    static char fmt_221[] = "(\002 PIVOT CHANGE ON FLY: N= \002,i5,\002 NXTI"
	    "= \002,i5,\002 NXTJ= \002,i5,\002 ITERNO= \002,i5,\002 TIME= "
	    "\002,1pd12.5)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, n, i1, j1, n1, n2;
    static doublereal t1, t2;
    static integer lc, no, lr, loc, nop, load, locc, loci, noff, locr, iops;
    static doublereal vmax;
    static integer nxti, nxtj, noffc, locij, ifill, locnn, noffr, minop, 
	    ispot;
    extern integer indxx_(integer *, integer *);
    static integer isize1, isize2, nstop1;
    extern /* Subroutine */ int second_(doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int dmpmat_(char *, ftnlen);
    static doublereal epsrel;
    extern /* Subroutine */ int swapij_(integer *, integer *, integer *, 
	    integer *), sizmem_(integer *, integer *), reserv_(integer *, 
	    integer *), extmem_(integer *, integer *), matloc_(void);
    static doublereal perspa;

    /* Fortran I/O blocks */
    static cilist io___153 = { 0, 0, 0, fmt_51, 0 };
    static cilist io___161 = { 0, 0, 0, fmt_92, 0 };
    static cilist io___181 = { 0, 0, 0, fmt_221, 0 };



/*     THIS ROUTINE SWAPS ROWS AND COLUMNS IN THE COEFFICIENT MATRIX ACCOR- */
/* DING TO THE NUMERICAL PIVOTING AND MINIMUM FILLIN TERMS.IT THEN PERFORMS */
/* AN IN-PLACE LU FACTORIZATION OF THE COEFFICIENT MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

    second_(&t1);
    if (status_1.ipiv <= 0) {
	goto L12;
    }
    if (debug_1.idebug[10] <= 0) {
	goto L3;
    }
    dmpmat_("DCDCMP", (ftnlen)6);
    --debug_1.idebug[10];
L3:
    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	no = 0;
	loc = nodplc[tabinf_1.jcpt + i__ - 1];
L5:
	if (loc == 0) {
	    goto L7;
	}
	++no;
	loc = nodplc[tabinf_1.jcpt + loc - 1];
	goto L5;
L7:
	nodplc[tabinf_1.numoff + i__ - 1] = no;
	no = 0;
	loc = nodplc[tabinf_1.irpt + i__ - 1];
L8:
	if (loc == 0) {
	    goto L9;
	}
	++no;
	loc = nodplc[tabinf_1.irpt + loc - 1];
	goto L8;
L9:
	nodplc[tabinf_1.nmoffc + i__ - 1] = no;
/* L10: */
    }
L12:
    n = 1;

/*     FIND NEXT PIVOT */

L15:
    ++n;
    if (status_1.ipiv > 0) {
	goto L20;
    }
    if (debug_1.idebug[12] <= 0) {
	goto L17;
    }
    dmpmat_("DCDCM2", (ftnlen)6);
    --debug_1.idebug[12];
L17:
    if (debug_1.idebug[13] <= 0) {
	goto L18;
    }
    if (status_1.mode != 2) {
	goto L18;
    }
    dmpmat_("DCDCM3", (ftnlen)6);
    --debug_1.idebug[13];
L18:
    if (debug_1.idebug[14] <= 0 || status_1.icalc <= 10) {
	goto L19;
    }
    dmpmat_("DCDCM4", (ftnlen)6);
    --debug_1.idebug[14];
L19:
    nxti = n;
    nxtj = n;
    goto L120;

/*     SEARCH THE CORESPONDING COLUMN FOR MAX ENTRY */

L20:
    vmax = 0.;
    loci = n;
L25:
    loci = nodplc[tabinf_1.irpt + loci - 1];
    if (loci == 0) {
	goto L50;
    }
    i__ = nodplc[tabinf_1.irowno + loci - 1];
    if (i__ < n) {
	goto L25;
    }
/* L30: */
    if ((d__1 = blank_1.value[tabinf_1.lvn + loci - 1], abs(d__1)) <= vmax) {
	goto L25;
    }
    vmax = (d__1 = blank_1.value[tabinf_1.lvn + loci - 1], abs(d__1));
    goto L25;
L50:
    if (vmax > knstnt_1.pivtol) {
	goto L60;
    }
    io___153.ciunit = status_1.iofile;
    s_wsfe(&io___153);
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&vmax, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.igoof = 1;
    return 0;
L60:
/* Computing MAX */
    d__1 = knstnt_1.pivrel * vmax;
    epsrel = max(d__1,knstnt_1.pivtol);
    if (n >= cirdat_1.nstop) {
	goto L200;
    }
    if (status_1.ipiv <= 0) {
	goto L120;
    }

/*     PIVOTING ON THE DIAGONAL */

    minop = 100000;
    nxti = 0;
    i__1 = cirdat_1.nstop;
    for (i__ = n; i__ <= i__1; ++i__) {
	i1 = nodplc[tabinf_1.irswpf + i__ - 1];
	j1 = nodplc[tabinf_1.icswpf + i__ - 1];
	ispot = indxx_(&i1, &j1);
	if (ispot == 1) {
	    goto L70;
	}
	if ((d__1 = blank_1.value[tabinf_1.lvn + ispot - 1], abs(d__1)) < 
		epsrel) {
	    goto L70;
	}
	nop = (nodplc[tabinf_1.numoff + i__ - 1] - 1) * (nodplc[
		tabinf_1.nmoffc + i__ - 1] - 1);
	if (nop >= minop) {
	    goto L70;
	}
	minop = nop;
	nxti = i__;
	nxtj = i__;
	if (minop <= 0) {
	    goto L95;
	}
L70:
	;
    }
    if (nxti <= 0) {
	goto L75;
    }
    if (nxti - n <= 0) {
	goto L120;
    } else {
	goto L100;
    }

/*     PIVOTING ON THE ENTIRE MATRIX */

L75:
    i__1 = cirdat_1.nstop;
    for (i__ = n; i__ <= i__1; ++i__) {
	loc = i__;
L80:
	loc = nodplc[tabinf_1.jcpt + loc - 1];
	if (loc == 0) {
	    goto L90;
	}
	j = nodplc[tabinf_1.jcolno + loc - 1];
	if (j < n) {
	    goto L80;
	}
	if ((d__1 = blank_1.value[tabinf_1.lvn + loc - 1], abs(d__1)) < 
		epsrel) {
	    goto L80;
	}
	nop = (nodplc[tabinf_1.numoff + i__ - 1] - 1) * (nodplc[
		tabinf_1.nmoffc + j - 1] - 1);
	if (nop >= minop) {
	    goto L80;
	}
	minop = nop;
	nxti = i__;
	nxtj = j;
	if (minop <= 0) {
	    goto L95;
	}
L90:
	;
    }
    if (nxti > 0) {
	goto L95;
    }
    io___161.ciunit = status_1.iofile;
    s_wsfe(&io___161);
    e_wsfe();
    flags_1.igoof = 1;
    goto L200;
L95:
    if (nxti == n && nxtj == n) {
	goto L120;
    }
    if (nxti == n) {
	goto L105;
    }

/*     A PIVOT HAS BEEN FOUND */

L100:
    load = nodplc[tabinf_1.irswpf + nxti - 1];
    lr = nodplc[tabinf_1.irswpf + n - 1];
    nodplc[tabinf_1.irswpf + nxti - 1] = lr;
    nodplc[tabinf_1.irswpr + lr - 1] = nxti;
    nodplc[tabinf_1.irswpf + n - 1] = load;
    nodplc[tabinf_1.irswpr + load - 1] = n;
    noff = nodplc[tabinf_1.numoff + nxti - 1];
    nodplc[tabinf_1.numoff + nxti - 1] = nodplc[tabinf_1.numoff + n - 1];
    nodplc[tabinf_1.numoff + n - 1] = noff;
    if (nxtj == n) {
	goto L110;
    }
L105:
    load = nodplc[tabinf_1.icswpf + nxtj - 1];
    lc = nodplc[tabinf_1.icswpf + n - 1];
    nodplc[tabinf_1.icswpf + nxtj - 1] = lc;
    nodplc[tabinf_1.icswpr + lc - 1] = nxtj;
    nodplc[tabinf_1.icswpf + n - 1] = load;
    nodplc[tabinf_1.icswpr + load - 1] = n;
    noff = nodplc[tabinf_1.nmoffc + nxtj - 1];
    nodplc[tabinf_1.nmoffc + nxtj - 1] = nodplc[tabinf_1.nmoffc + n - 1];
    nodplc[tabinf_1.nmoffc + n - 1] = noff;
L110:
    swapij_(&nxti, &n, &nxtj, &n);
    nxti = n;
    nxtj = n;

/*     CALCULATE CONTRIBUTION FROM NXTI, NXTJ AND FIND FILL-INS */

L120:
    if (n >= cirdat_1.nstop) {
	goto L200;
    }
    n1 = nodplc[tabinf_1.irswpf + nxti - 1];
    n2 = nodplc[tabinf_1.icswpf + nxtj - 1];
    locnn = indxx_(&n1, &n2);
    if (status_1.ipiv <= 0 && (d__1 = blank_1.value[tabinf_1.lvn + locnn - 1],
	     abs(d__1)) < knstnt_1.pivtol) {
	goto L220;
    }

/*     DOWN COL J */

    locr = nodplc[tabinf_1.irpt + locnn - 1];
L125:
    if (locr == 0) {
	goto L180;
    }
    i__ = nodplc[tabinf_1.irowno + locr - 1];
    blank_1.value[tabinf_1.lvn + locr - 1] /= blank_1.value[tabinf_1.lvn + 
	    locnn - 1];
    locc = nodplc[tabinf_1.jcpt + locnn - 1];

/*     FOR EACH COLUMN ELEMENT LOOK UP ROW NXTI */

L130:
    if (locc == 0) {
	goto L170;
    }
    j = nodplc[tabinf_1.jcolno + locc - 1];

/*     CHECK FOR FILL-IN (I,J) */

    if (status_1.ipiv <= 0) {
	goto L135;
    }
    sizmem_(&tabinf_1.jcpt, &isize1);
    reserv_(&i__, &j);
    sizmem_(&tabinf_1.jcpt, &isize2);
    if (isize1 == isize2) {
	goto L135;
    }
    extmem_(&tabinf_1.lvn, &c__1);
    ++tabinf_1.nttbr;
    blank_1.value[tabinf_1.lvn + cirdat_1.nstop + tabinf_1.nttbr - 1] = 0.;

/*     LOCATE ELEMENT (I,J) */

L135:
    if (j < i__) {
	goto L145;
    }
    locij = locc;
L140:
    locij = nodplc[tabinf_1.irpt + locij - 1];
    if (nodplc[tabinf_1.irowno + locij - 1] == i__) {
	goto L155;
    }
    goto L140;
L145:
    locij = locr;
L150:
    locij = nodplc[tabinf_1.jcpt + locij - 1];
    if (nodplc[tabinf_1.jcolno + locij - 1] == j) {
	goto L155;
    }
    goto L150;
L155:
    blank_1.value[tabinf_1.lvn + locij - 1] -= blank_1.value[tabinf_1.lvn + 
	    locc - 1] * blank_1.value[tabinf_1.lvn + locr - 1];
/* L160: */
    locc = nodplc[tabinf_1.jcpt + locc - 1];
    goto L130;
L170:
    locr = nodplc[tabinf_1.irpt + locr - 1];
    if (status_1.ipiv <= 0) {
	goto L125;
    }
    --nodplc[tabinf_1.numoff + i__ - 1];
    goto L125;

/*     REDUCE NMOFFC FOR EACH ELEMENT IN COL NXTI */

L180:
    if (status_1.ipiv <= 0) {
	goto L15;
    }
    locc = nodplc[tabinf_1.jcpt + locnn - 1];
L185:
    if (locc == 0) {
	goto L15;
    }
    j = nodplc[tabinf_1.jcolno + locc - 1];
    --nodplc[tabinf_1.nmoffc + j - 1];
    locc = nodplc[tabinf_1.jcpt + locc - 1];
    goto L185;

/*     DONE */

L200:
    if (status_1.ipiv == 0) {
	goto L210;
    }
    if (debug_1.idebug[16] <= 0) {
	goto L202;
    }
    dmpmat_("DCDCM5", (ftnlen)6);
    --debug_1.idebug[16];
L202:
    matloc_();
    miscel_1.rstats[48] += 1.;
    status_1.ipiv = 0;
    if (flags_1.lvlcod == 2) {
	flags_1.lvlcod = 3;
    }
    ifill = tabinf_1.nttbr - tabinf_1.nttar;
    perspa = (1. - (doublereal) tabinf_1.nttbr / (doublereal) (cirdat_1.nstop 
	    * cirdat_1.nstop)) * 100.;

/*  CALCULATION OF OPERATION COUNT (OPERATION := `*' or `/'): */

/*     NOFFR := OFF-DIAGONAL ELEMENTS IN ROW, NOT INCLUDING DIAGONAL, */
/*                COUNTING ONLY THOSE ELEMENTS IN THE REMAINDER MATRIX */
/*     NOFFC := OFF-DIAGONAL ELEMENTS IN COLUMN, NOT INCLUDING DIAGONAL, */
/*                COUNTING ONLY THOSE ELEMENTS IN THE REMAINDER MATRIX */

/*     THEN WE HAVE */

/*        LU DECOMPOSITION     REQUIRES SIGMA(2,NSTOP-1) {NOFFC + NOFFC*NOFFR} */
/*        FORWARD SUBSTITUTION          SIGMA(2,NSTOP-1) {NOFFC + 1}   +   1 */
/*        BACKWARD SUBSTITUTION         SIGMA(2,NSTOP-1) {NOFFR} */

/*     WHICH SUMS TO */

/*               SIGMA(2,NSTOP-1) {NOFFC + NOFFC*NOFFR + (NOFFC+1) + NOFFR} + 1 */
/*         OR */
/*               SIGMA(2,NSTOP-1) {NOFFC*(NOFFR+2) + NOFFR + 1}   +   1 */

    iops = 1;
    nstop1 = cirdat_1.nstop - 1;
    i__1 = nstop1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	noffr = nodplc[tabinf_1.numoff + i__ - 1] - 1;
	noffc = nodplc[tabinf_1.nmoffc + i__ - 1] - 1;
	iops = iops + noffr + noffc * (noffr + 2) + 1;
/* L205: */
    }
    miscel_1.rstats[19] = (doublereal) cirdat_1.nstop;
    miscel_1.rstats[20] = (doublereal) tabinf_1.nttar;
    miscel_1.rstats[21] = (doublereal) tabinf_1.nttbr;
    miscel_1.rstats[22] = (doublereal) ifill;
    miscel_1.rstats[23] = 0.;
    miscel_1.rstats[24] = (doublereal) tabinf_1.nttbr;
    miscel_1.rstats[25] = (doublereal) iops;
    miscel_1.rstats[26] = perspa;
    goto L215;
L210:
    if (debug_1.idebug[17] <= 0) {
	goto L212;
    }
    dmpmat_("DCDCM6", (ftnlen)6);
    --debug_1.idebug[17];
L212:
    if (debug_1.idebug[18] <= 0 || status_1.icalc <= 10) {
	goto L215;
    }
    dmpmat_("DCDCM7", (ftnlen)6);
    --debug_1.idebug[18];
L215:
    second_(&t2);
    miscel_1.rstats[49] = miscel_1.rstats[49] + t2 - t1;
    return 0;
L220:
    status_1.ipiv = 1;
    io___181.ciunit = status_1.iofile;
    s_wsfe(&io___181);
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nxti, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nxtj, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.iterno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.time, (ftnlen)sizeof(doublereal));
    e_wsfe();
    miscel_1.rstats[48] += 1.;
    goto L20;
} /* dcdcmp_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int dcsol_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
    static doublereal t1, t2;
    static integer loc, iord, jord, locnn;
    extern integer indxx_(integer *, integer *);
    extern /* Subroutine */ int second_(doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE SOLVES THE SYSTEM OF CIRCUIT EQUATIONS BY PERFORMING */
/* A FORWARD AND BACKWARD SUBSTITUTION STEP USING THE PREVIOUSLY-COMPUTED */
/* LU FACTORS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  FORWARD SUBSTITUTION */

    second_(&t1);
    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	loc = i__;
	iord = nodplc[tabinf_1.irswpf + i__ - 1];
L10:
	loc = nodplc[tabinf_1.jcpt + loc - 1];
	if (nodplc[tabinf_1.jcolno + loc - 1] >= i__) {
	    goto L20;
	}
	j = nodplc[tabinf_1.jcolno + loc - 1];
	jord = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.lvn + iord - 1] -= blank_1.value[tabinf_1.lvn 
		+ loc - 1] * blank_1.value[tabinf_1.lvn + jord - 1];
	goto L10;
L20:
	;
    }

/*     BACK SUBSTITUTION */

    i__ = cirdat_1.nstop;
    iord = nodplc[tabinf_1.irswpf + i__ - 1];
    jord = nodplc[tabinf_1.icswpf + i__ - 1];
    locnn = indxx_(&iord, &jord);
L30:
    blank_1.value[tabinf_1.lvn + iord - 1] /= blank_1.value[tabinf_1.lvn + 
	    locnn - 1];
    --i__;
    if (i__ <= 1) {
	goto L100;
    }
    iord = nodplc[tabinf_1.irswpf + i__ - 1];
    loc = i__;
L35:
    loc = nodplc[tabinf_1.jcpt + loc - 1];
/* L40: */
    if (nodplc[tabinf_1.jcolno + loc - 1] != i__) {
	goto L35;
    }
    locnn = loc;
L50:
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L30;
    }
    j = nodplc[tabinf_1.jcolno + loc - 1];
    jord = nodplc[tabinf_1.irswpf + j - 1];
    blank_1.value[tabinf_1.lvn + iord - 1] -= blank_1.value[tabinf_1.lvn + 
	    loc - 1] * blank_1.value[tabinf_1.lvn + jord - 1];
    goto L50;
L100:
    second_(&t2);
    miscel_1.rstats[45] = miscel_1.rstats[45] + t2 - t1;
    return 0;
} /* dcsol_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int dmpmat_(doublereal *anam)
{
    /* Format strings */
    static char fmt_10[] = "(\0020*DEBUG*:  DMPMT CALLED BY \002,a8,/,\002 *"
	    "DEBUG*:  MODE, MDC, TIME, DELTA, ICALC, ITR#, INITF,\002,\002 PI"
	    "V, ORD, NCON, IGOOF, NOGO =\002,/,\002 *DEBUG*:  \002,2i5,1p2d10"
	    ".2,8i5)";
    static char fmt_16[] = "(\002 *DEBUG*:  NSTOP, NTTBR, SIZE(IRPT) = \002,"
	    "3i6,/,\002 *DEBUG*:   INDEX  IRPT  IROW  JCOL  JCPT       VALU"
	    "E\002,10x,\002 INDEX  IRPT  IROW  JCOL  JCPT       VALUE\002)";
    static char fmt_26[] = "(\002 *DEBUG*:  \002,5i6,1pd12.4,10x,5i6,1pd12.4)"
	    ;
    static char fmt_71[] = "(\002 *DEBUG*:  IRSWPF = \002,18i6)";
    static char fmt_76[] = "(\002 *DEBUG*:  IRSWPR = \002,18i6)";
    static char fmt_81[] = "(\002 *DEBUG*:  ICSWPF = \002,18i6)";
    static char fmt_86[] = "(\002 *DEBUG*:  ICSWPR = \002,18i6)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, irpts, istop;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int dmpmem_(char *, ftnlen), sizmem_(integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___194 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___196 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___200 = { 0, 0, 0, fmt_26, 0 };
    static cilist io___201 = { 0, 0, 0, fmt_71, 0 };
    static cilist io___202 = { 0, 0, 0, fmt_76, 0 };
    static cilist io___203 = { 0, 0, 0, fmt_81, 0 };
    static cilist io___204 = { 0, 0, 0, fmt_86, 0 };



/*      THIS ROUTINE DUMPS OUT THE MATRIX AND ASSOCIATED POINTERS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    io___194.ciunit = status_1.iofile;
    s_wsfe(&io___194);
    do_fio(&c__1, (char *)&(*anam), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&status_1.mode, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.modedc, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.time, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&status_1.delta, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&status_1.icalc, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.iterno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.initf, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.ipiv, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.iord, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.noncon, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.igoof, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.nogo, (ftnlen)sizeof(integer));
    e_wsfe();
    dmpmem_("DMPMT", (ftnlen)5);

/*  DUMP OUT THE *WHOLE* THING */

    sizmem_(&tabinf_1.irpt, &irpts);
    io___196.ciunit = status_1.iofile;
    s_wsfe(&io___196);
    do_fio(&c__1, (char *)&cirdat_1.nstop, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tabinf_1.nttbr, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&irpts, (ftnlen)sizeof(integer));
    e_wsfe();
    j = (irpts + 1) / 2;
    istop = j;
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++j;
	io___200.ciunit = status_1.iofile;
	s_wsfe(&io___200);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irpt + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irowno + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.jcolno + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.jcpt + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvn + i__ - 1], (ftnlen)
		sizeof(doublereal));
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irpt + j - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irowno + j - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.jcolno + j - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.jcpt + j - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvn + j - 1], (ftnlen)
		sizeof(doublereal));
	e_wsfe();
/* L30: */
    }
/* C 51 FORMAT(" *DEBUG*:  IRPT   = ",18I6) */
/* C    WRITE (IOFILE,56) (NODPLC(IROWNO+I),I=1,IRPTS) */
/* C 56 FORMAT(" *DEBUG*:  IROWNO = ",18I6) */
/* C    WRITE (IOFILE,61) (NODPLC(JCOLNO+I),I=1,IRPTS) */
/* C 61 FORMAT(" *DEBUG*:  JCOLNO = ",18I6) */
/* C    WRITE (IOFILE,66) (NODPLC(JCPT  +I),I=1,IRPTS) */
/* C 66 FORMAT(" *DEBUG*:  JCPT   = ",18I6) */
    io___201.ciunit = status_1.iofile;
    s_wsfe(&io___201);
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irswpf + i__ - 1], (ftnlen)
		sizeof(integer));
    }
    e_wsfe();
    io___202.ciunit = status_1.iofile;
    s_wsfe(&io___202);
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&nodplc[tabinf_1.irswpr + i__ - 1], (ftnlen)
		sizeof(integer));
    }
    e_wsfe();
    io___203.ciunit = status_1.iofile;
    s_wsfe(&io___203);
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&nodplc[tabinf_1.icswpf + i__ - 1], (ftnlen)
		sizeof(integer));
    }
    e_wsfe();
    io___204.ciunit = status_1.iofile;
    s_wsfe(&io___204);
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&nodplc[tabinf_1.icswpr + i__ - 1], (ftnlen)
		sizeof(integer));
    }
    e_wsfe();


/* L500: */
    return 0;
} /* dmpmat_ */

#undef cvalue
#undef nodplc


integer indxx_(integer *node1, integer *node2)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer n1, n2, loc;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE MAPS A (ROW, COLUMN) MATRIX TERM SPECIFICATION INTO */
/* THE OFFSET FROM THE ORIGIN OF THE MATRIX STORAGE AT WHICH THE TERM IS */
/* ACTUALLY LOCATED. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

    if (*node1 == 1) {
	goto L100;
    }
    if (*node2 == 1) {
	goto L100;
    }

    n1 = nodplc[tabinf_1.irswpr + *node1 - 1];
    n2 = nodplc[tabinf_1.icswpr + *node2 - 1];
    if (n1 - n2 <= 0) {
	goto L10;
    } else {
	goto L30;
    }

/*     SEARCH COL N2 */

L10:
    loc = n2;
L15:
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L100;
    }
    if (nodplc[tabinf_1.irowno + loc - 1] - n1 != 0) {
	goto L15;
    } else {
	goto L20;
    }
L20:
    ret_val = loc;
    return ret_val;

/*     SEARCH ROW N1 */

L30:
    loc = n1;
L35:
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L100;
    }
    if (nodplc[tabinf_1.jcolno + loc - 1] - n2 != 0) {
	goto L35;
    } else {
	goto L40;
    }
L40:
    ret_val = loc;
    return ret_val;

/*     UNUSED LOCATION */

L100:
    ret_val = 1;
    return ret_val;
} /* indxx_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int swapij_(integer *i1, integer *i2, integer *j1, integer *
	j2)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, loc, loc1, loc2, lsav1, lsav2, ktype;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*     SWAP ROWS I1 AND I2 */

    loc1 = nodplc[tabinf_1.jcpt + *i1 - 1];
    loc2 = nodplc[tabinf_1.jcpt + *i2 - 1];
    nodplc[tabinf_1.jcpt + *i1 - 1] = loc2;
    nodplc[tabinf_1.jcpt + *i2 - 1] = loc1;

/*     CHECK IF END OF ROW */

L5:
    if (loc1 <= 0 && loc2 <= 0) {
	goto L80;
    }

/*     CHECK SWAP TYPE */

    if (loc1 == 0) {
	goto L20;
    }
    if (loc2 == 0) {
	goto L10;
    }
    if ((i__1 = nodplc[tabinf_1.jcolno + loc1 - 1] - nodplc[tabinf_1.jcolno + 
	    loc2 - 1]) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L15;
    } else {
	goto L20;
    }
L10:
    ktype = -1;
    j = nodplc[tabinf_1.jcolno + loc1 - 1];
    goto L25;
L15:
    ktype = 0;
    j = nodplc[tabinf_1.jcolno + loc1 - 1];
    goto L25;
L20:
    ktype = 1;
    j = nodplc[tabinf_1.jcolno + loc2 - 1];

/*     FIND POINTER TO ENTRY (I1,J) */

L25:
    loc = j;
L30:
    lsav1 = loc;
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L40;
    }
    if (nodplc[tabinf_1.irowno + loc - 1] - *i1 < 0) {
	goto L30;
    }

/*     FIND POINTER TO ENTRY (I2,J) */

L40:
    loc = j;
L45:
    lsav2 = loc;
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L55;
    }
    if (nodplc[tabinf_1.irowno + loc - 1] - *i2 < 0) {
	goto L45;
    }

/*     BRANCH FOR COL J IN ROW I1, IN BOTH ROW I1 AND I2, OR IN ROW I2 */

L55:
    if (ktype < 0) {
	goto L60;
    } else if (ktype == 0) {
	goto L70;
    } else {
	goto L75;
    }

/*     ENTRY (I1,J) */

L60:
    if (lsav1 == lsav2) {
	goto L65;
    }
    loc = nodplc[tabinf_1.irpt + lsav2 - 1];
    nodplc[tabinf_1.irpt + lsav2 - 1] = loc1;
    nodplc[tabinf_1.irpt + lsav1 - 1] = nodplc[tabinf_1.irpt + loc1 - 1];
    nodplc[tabinf_1.irpt + loc1 - 1] = loc;
L65:
    nodplc[tabinf_1.irowno + loc1 - 1] = *i2;
    loc1 = nodplc[tabinf_1.jcpt + loc1 - 1];
    goto L5;

/*     ENTRIES (I1,J) AND (I2,J) */

L70:
    nodplc[tabinf_1.irpt + lsav1 - 1] = loc2;
    nodplc[tabinf_1.irpt + lsav2 - 1] = loc1;
    loc = nodplc[tabinf_1.irpt + loc1 - 1];
    nodplc[tabinf_1.irpt + loc1 - 1] = nodplc[tabinf_1.irpt + loc2 - 1];
    nodplc[tabinf_1.irpt + loc2 - 1] = loc;
    nodplc[tabinf_1.irowno + loc1 - 1] = *i2;
    nodplc[tabinf_1.irowno + loc2 - 1] = *i1;
    loc1 = nodplc[tabinf_1.jcpt + loc1 - 1];
    loc2 = nodplc[tabinf_1.jcpt + loc2 - 1];
    goto L5;

/*     ENTRY (I2,J) */

L75:
    if (lsav1 == lsav2) {
	goto L78;
    }
    loc = nodplc[tabinf_1.irpt + lsav1 - 1];
    nodplc[tabinf_1.irpt + lsav1 - 1] = loc2;
    nodplc[tabinf_1.irpt + lsav2 - 1] = nodplc[tabinf_1.irpt + loc2 - 1];
    nodplc[tabinf_1.irpt + loc2 - 1] = loc;
L78:
    nodplc[tabinf_1.irowno + loc2 - 1] = *i1;
    loc2 = nodplc[tabinf_1.jcpt + loc2 - 1];
    goto L5;

/*     SWAP COLUMNS J1 AND J2 */

L80:
    loc1 = nodplc[tabinf_1.irpt + *j1 - 1];
    loc2 = nodplc[tabinf_1.irpt + *j2 - 1];
    nodplc[tabinf_1.irpt + *j1 - 1] = loc2;
    nodplc[tabinf_1.irpt + *j2 - 1] = loc1;

/*     CHECK FOR END OF COLUMN */

L85:
    if (loc1 <= 0 && loc2 <= 0) {
	goto L160;
    }

/*     CHECK SWAP TYPE */

    if (loc1 == 0) {
	goto L100;
    }
    if (loc2 == 0) {
	goto L90;
    }
    if ((i__1 = nodplc[tabinf_1.irowno + loc1 - 1] - nodplc[tabinf_1.irowno + 
	    loc2 - 1]) < 0) {
	goto L90;
    } else if (i__1 == 0) {
	goto L95;
    } else {
	goto L100;
    }
L90:
    ktype = -1;
    i__ = nodplc[tabinf_1.irowno + loc1 - 1];
    goto L105;
L95:
    ktype = 0;
    i__ = nodplc[tabinf_1.irowno + loc1 - 1];
    goto L105;
L100:
    ktype = 1;
    i__ = nodplc[tabinf_1.irowno + loc2 - 1];

/*     FIND POINTER TO ENTRY (I,J1) */

L105:
    loc = i__;
L110:
    lsav1 = loc;
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L120;
    }
    if (nodplc[tabinf_1.jcolno + loc - 1] - *j1 < 0) {
	goto L110;
    }

/*     FIND POINTER TO ENTRY (I,J2) */

L120:
    loc = i__;
L125:
    lsav2 = loc;
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L135;
    }
    if (nodplc[tabinf_1.jcolno + loc - 1] - *j2 < 0) {
	goto L125;
    }

/*     BRANCH FOR ROW I IN COL J1, IN BOTH COL"S J1 AND J2, OR IN COL J2 */

L135:
    if (ktype < 0) {
	goto L140;
    } else if (ktype == 0) {
	goto L150;
    } else {
	goto L155;
    }

/*     ENTRY (I,J1) */

L140:
    if (lsav1 == lsav2) {
	goto L145;
    }
    loc = nodplc[tabinf_1.jcpt + lsav2 - 1];
    nodplc[tabinf_1.jcpt + lsav2 - 1] = loc1;
    nodplc[tabinf_1.jcpt + lsav1 - 1] = nodplc[tabinf_1.jcpt + loc1 - 1];
    nodplc[tabinf_1.jcpt + loc1 - 1] = loc;
L145:
    nodplc[tabinf_1.jcolno + loc1 - 1] = *j2;
    loc1 = nodplc[tabinf_1.irpt + loc1 - 1];
    goto L85;

/*     ENTRIES (I1,J) AND (I2,J) */

L150:
    nodplc[tabinf_1.jcpt + lsav1 - 1] = loc2;
    nodplc[tabinf_1.jcpt + lsav2 - 1] = loc1;
    loc = nodplc[tabinf_1.jcpt + loc1 - 1];
    nodplc[tabinf_1.jcpt + loc1 - 1] = nodplc[tabinf_1.jcpt + loc2 - 1];
    nodplc[tabinf_1.jcpt + loc2 - 1] = loc;
    nodplc[tabinf_1.jcolno + loc1 - 1] = *j2;
    nodplc[tabinf_1.jcolno + loc2 - 1] = *j1;
    loc1 = nodplc[tabinf_1.irpt + loc1 - 1];
    loc2 = nodplc[tabinf_1.irpt + loc2 - 1];
    goto L85;

/*     ENTRY (I,J2) */

L155:
    if (lsav1 == lsav2) {
	goto L158;
    }
    loc = nodplc[tabinf_1.jcpt + lsav1 - 1];
    nodplc[tabinf_1.jcpt + lsav1 - 1] = loc2;
    nodplc[tabinf_1.jcpt + lsav2 - 1] = nodplc[tabinf_1.jcpt + loc2 - 1];
    nodplc[tabinf_1.jcpt + loc2 - 1] = loc;
L158:
    nodplc[tabinf_1.jcolno + loc2 - 1] = *j1;
    loc2 = nodplc[tabinf_1.irpt + loc2 - 1];
    goto L85;
L160:
    return 0;
} /* swapij_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int reserv_(integer *node1, integer *node2)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer loc, loci, locj, isize;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern logical memptr_(integer *);
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    static integer newloc;
    extern /* Subroutine */ int extmem_(integer *, integer *);


/*     THIS ROUTINE RECORDS THE FACT THAT THE (NODE1, NODE2) ELEMENT OF */
/* THE CIRCUIT EQUATION COEFFICIENT MATRIX IS NONZERO. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    if (flags_1.nogo != 0) {
	goto L300;
    }
/* ...  TEST FOR GROUND */
    if (*node1 == 1) {
	goto L300;
    }
    if (*node2 == 1) {
	goto L300;
    }

/*     RESERVE (NODE1,NODE2) IN ROW NODE1 AT COL POSN NODE2 */

    loc = *node1;
L10:
    locj = loc;
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L20;
    }
    if ((i__1 = nodplc[tabinf_1.jcolno + loc - 1] - *node2) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L300;
    } else {
	goto L20;
    }
L20:
    sizmem_(&tabinf_1.jcpt, &isize);
    newloc = isize + 1;
    ++nodplc[tabinf_1.numoff + *node1 - 1];
    ++nodplc[tabinf_1.nmoffc + *node2 - 1];
    extmem_(&tabinf_1.jcpt, &c__1);
    extmem_(&tabinf_1.jcolno, &c__1);
    nodplc[tabinf_1.jcpt + locj - 1] = newloc;
    nodplc[tabinf_1.jcpt + newloc - 1] = loc;
    nodplc[tabinf_1.jcolno + newloc - 1] = *node2;

/*     RESERVE (NODE1,NODE2) IN COL NODE2 AT ROW POSN NODE1 */

    loc = *node2;
L30:
    loci = loc;
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L40;
    }
    if ((i__1 = nodplc[tabinf_1.irowno + loc - 1] - *node1) < 0) {
	goto L30;
    } else if (i__1 == 0) {
	goto L300;
    } else {
	goto L40;
    }
L40:
    extmem_(&tabinf_1.irpt, &c__1);
    extmem_(&tabinf_1.irowno, &c__1);
    nodplc[tabinf_1.irpt + loci - 1] = newloc;
    nodplc[tabinf_1.irpt + newloc - 1] = loc;
    nodplc[tabinf_1.irowno + newloc - 1] = *node1;

/*     MARK DIAGONAL */

    if (*node1 != *node2) {
	goto L300;
    }
    if (memptr_(&tabinf_1.ndiag)) {
	nodplc[tabinf_1.ndiag + *node1 - 1] = 1;
    }

/*     FINISHED */

L300:
    return 0;
} /* reserv_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int matloc_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ni1, ni2, nl1, nl2, loc, kbr, ibr1, ibr2, ndim, lnod, 
	    lmat, iptr, node1, node2, node3, node4, node5, node6, node7;
    extern integer indxx_(integer *, integer *);
    static integer locvs;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer locvst;


/*     THIS ROUTINE STORES THE LOCATIONS OF THE VARIOUS MATRIX TERMS TO */
/* WHICH THE DIFFERENT CIRCUIT ELEMENTS CONTRIBUTE. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  RESISTORS */

    loc = cirdat_1.locate[0];
L690:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L700;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    nodplc[loc + 3] = indxx_(&node1, &node2);
    nodplc[loc + 4] = indxx_(&node2, &node1);
    nodplc[loc + 5] = indxx_(&node1, &node1);
    nodplc[loc + 6] = indxx_(&node2, &node2);
    loc = nodplc[loc - 1];
    goto L690;

/*  CAPACITORS */

L700:
    loc = cirdat_1.locate[1];
L710:
    if (loc == 0 || nodplc[loc + 11] != 0) {
	goto L720;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    nodplc[loc + 4] = indxx_(&node1, &node2);
    nodplc[loc + 5] = indxx_(&node2, &node1);
    nodplc[loc + 9] = indxx_(&node1, &node1);
    nodplc[loc + 10] = indxx_(&node2, &node2);
    loc = nodplc[loc - 1];
    goto L710;

/*  INDUCTORS */

L720:
    loc = cirdat_1.locate[2];
L730:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L740;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    cirdat_1.ibr = nodplc[loc + 4];
    nodplc[loc + 5] = indxx_(&node1, &cirdat_1.ibr);
    nodplc[loc + 6] = indxx_(&node2, &cirdat_1.ibr);
    nodplc[loc + 7] = indxx_(&cirdat_1.ibr, &node1);
    nodplc[loc + 8] = indxx_(&cirdat_1.ibr, &node2);
    nodplc[loc + 12] = indxx_(&cirdat_1.ibr, &cirdat_1.ibr);
    loc = nodplc[loc - 1];
    goto L730;

/*  MUTUAL INDUCTANCES */

L740:
    loc = cirdat_1.locate[3];
L750:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L760;
    }
    nl1 = nodplc[loc + 1];
    nl2 = nodplc[loc + 2];
    ibr1 = nodplc[nl1 + 4];
    ibr2 = nodplc[nl2 + 4];
    nodplc[loc + 3] = indxx_(&ibr1, &ibr2);
    nodplc[loc + 4] = indxx_(&ibr2, &ibr1);
    loc = nodplc[loc - 1];
    goto L750;

/*  NONLINEAR VOLTAGE CONTROLLED CURRENT SOURCES */

L760:
    loc = cirdat_1.locate[4];
L762:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L764;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    lnod = nodplc[loc + 5];
    lmat = nodplc[loc + 6];
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node3 = nodplc[lnod];
	node4 = nodplc[lnod + 1];
	lnod += 2;
	nodplc[lmat] = indxx_(&node1, &node3);
	nodplc[lmat + 1] = indxx_(&node1, &node4);
	nodplc[lmat + 2] = indxx_(&node2, &node3);
	nodplc[lmat + 3] = indxx_(&node2, &node4);
	lmat += 4;
/* L763: */
    }
    loc = nodplc[loc - 1];
    goto L762;

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L764:
    loc = cirdat_1.locate[5];
L766:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L768;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    cirdat_1.ibr = nodplc[loc + 5];
    lnod = nodplc[loc + 6];
    lmat = nodplc[loc + 7];
    nodplc[lmat] = indxx_(&node1, &cirdat_1.ibr);
    nodplc[lmat + 1] = indxx_(&node2, &cirdat_1.ibr);
    nodplc[lmat + 2] = indxx_(&cirdat_1.ibr, &node1);
    nodplc[lmat + 3] = indxx_(&cirdat_1.ibr, &node2);
    lmat += 4;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node3 = nodplc[lnod];
	node4 = nodplc[lnod + 1];
	lnod += 2;
	nodplc[lmat] = indxx_(&cirdat_1.ibr, &node3);
	nodplc[lmat + 1] = indxx_(&cirdat_1.ibr, &node4);
	lmat += 2;
/* L767: */
    }
    loc = nodplc[loc - 1];
    goto L766;

/*  NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */

L768:
    loc = cirdat_1.locate[6];
L770:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L772;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    locvs = nodplc[loc + 5];
    lmat = nodplc[loc + 6];
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locvst = nodplc[locvs + i__ - 1];
	cirdat_1.ibr = nodplc[locvst + 5];
	nodplc[lmat] = indxx_(&node1, &cirdat_1.ibr);
	nodplc[lmat + 1] = indxx_(&node2, &cirdat_1.ibr);
	lmat += 2;
/* L771: */
    }
    loc = nodplc[loc - 1];
    goto L770;

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L772:
    loc = cirdat_1.locate[7];
L774:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L780;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    cirdat_1.ibr = nodplc[loc + 5];
    locvs = nodplc[loc + 6];
    lmat = nodplc[loc + 7];
    nodplc[lmat] = indxx_(&node1, &cirdat_1.ibr);
    nodplc[lmat + 1] = indxx_(&node2, &cirdat_1.ibr);
    nodplc[lmat + 2] = indxx_(&cirdat_1.ibr, &node1);
    nodplc[lmat + 3] = indxx_(&cirdat_1.ibr, &node2);
    lmat += 4;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locvst = nodplc[locvs + i__ - 1];
	kbr = nodplc[locvst + 5];
	nodplc[lmat + i__ - 1] = indxx_(&cirdat_1.ibr, &kbr);
/* L775: */
    }
    loc = nodplc[loc - 1];
    goto L774;

/*  VOLTAGE SOURCES */

L780:
    loc = cirdat_1.locate[8];
L790:
    if (loc == 0 || nodplc[loc + 10] != 0) {
	goto L800;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    iptr = nodplc[loc + 5];
    nodplc[loc + 6] = indxx_(&node1, &iptr);
    nodplc[loc + 7] = indxx_(&node2, &iptr);
    nodplc[loc + 8] = indxx_(&iptr, &node1);
    nodplc[loc + 9] = indxx_(&iptr, &node2);
    loc = nodplc[loc - 1];
    goto L790;

/*  DIODES */

L800:
    loc = cirdat_1.locate[10];
L810:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L820;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    nodplc[loc + 6] = indxx_(&node1, &node3);
    nodplc[loc + 7] = indxx_(&node2, &node3);
    nodplc[loc + 8] = indxx_(&node3, &node1);
    nodplc[loc + 9] = indxx_(&node3, &node2);
    nodplc[loc + 12] = indxx_(&node1, &node1);
    nodplc[loc + 13] = indxx_(&node2, &node2);
    nodplc[loc + 14] = indxx_(&node3, &node3);
    loc = nodplc[loc - 1];
    goto L810;

/*  TRANSISTORS */

L820:
    loc = cirdat_1.locate[11];
L830:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L840;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    node7 = nodplc[loc + 29];
    nodplc[loc + 9] = indxx_(&node1, &node4);
    nodplc[loc + 10] = indxx_(&node2, &node5);
    nodplc[loc + 11] = indxx_(&node3, &node6);
    nodplc[loc + 12] = indxx_(&node4, &node1);
    nodplc[loc + 13] = indxx_(&node4, &node5);
    nodplc[loc + 14] = indxx_(&node4, &node6);
    nodplc[loc + 15] = indxx_(&node5, &node2);
    nodplc[loc + 16] = indxx_(&node5, &node4);
    nodplc[loc + 17] = indxx_(&node5, &node6);
    nodplc[loc + 18] = indxx_(&node6, &node3);
    nodplc[loc + 19] = indxx_(&node6, &node4);
    nodplc[loc + 20] = indxx_(&node6, &node5);
    nodplc[loc + 23] = indxx_(&node1, &node1);
    nodplc[loc + 24] = indxx_(&node2, &node2);
    nodplc[loc + 25] = indxx_(&node3, &node3);
    nodplc[loc + 26] = indxx_(&node4, &node4);
    nodplc[loc + 27] = indxx_(&node5, &node5);
    nodplc[loc + 28] = indxx_(&node6, &node6);
    nodplc[loc + 30] = indxx_(&node7, &node7);
    nodplc[loc + 31] = indxx_(&node4, &node7);
    nodplc[loc + 32] = indxx_(&node7, &node4);
    nodplc[loc + 33] = indxx_(&node2, &node4);
    nodplc[loc + 34] = indxx_(&node4, &node2);
    loc = nodplc[loc - 1];
    goto L830;

/*  JFETS */

L840:
    loc = cirdat_1.locate[12];
L850:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L860;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    nodplc[loc + 8] = indxx_(&node1, &node4);
    nodplc[loc + 9] = indxx_(&node2, &node4);
    nodplc[loc + 10] = indxx_(&node2, &node5);
    nodplc[loc + 11] = indxx_(&node3, &node5);
    nodplc[loc + 12] = indxx_(&node4, &node1);
    nodplc[loc + 13] = indxx_(&node4, &node2);
    nodplc[loc + 14] = indxx_(&node4, &node5);
    nodplc[loc + 15] = indxx_(&node5, &node2);
    nodplc[loc + 16] = indxx_(&node5, &node3);
    nodplc[loc + 17] = indxx_(&node5, &node4);
    nodplc[loc + 19] = indxx_(&node1, &node1);
    nodplc[loc + 20] = indxx_(&node2, &node2);
    nodplc[loc + 21] = indxx_(&node3, &node3);
    nodplc[loc + 22] = indxx_(&node4, &node4);
    nodplc[loc + 23] = indxx_(&node5, &node5);
    loc = nodplc[loc - 1];
    goto L850;

/*  MOSFETS */

L860:
    loc = cirdat_1.locate[13];
L870:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L900;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    nodplc[loc + 9] = indxx_(&node1, &node5);
    nodplc[loc + 10] = indxx_(&node2, &node4);
    nodplc[loc + 11] = indxx_(&node2, &node5);
    nodplc[loc + 12] = indxx_(&node2, &node6);
    nodplc[loc + 13] = indxx_(&node3, &node6);
    nodplc[loc + 14] = indxx_(&node4, &node2);
    nodplc[loc + 15] = indxx_(&node4, &node5);
    nodplc[loc + 16] = indxx_(&node4, &node6);
    nodplc[loc + 17] = indxx_(&node5, &node1);
    nodplc[loc + 18] = indxx_(&node5, &node2);
    nodplc[loc + 19] = indxx_(&node5, &node4);
    nodplc[loc + 20] = indxx_(&node5, &node6);
    nodplc[loc + 21] = indxx_(&node6, &node2);
    nodplc[loc + 22] = indxx_(&node6, &node3);
    nodplc[loc + 23] = indxx_(&node6, &node4);
    nodplc[loc + 24] = indxx_(&node6, &node5);
    nodplc[loc + 26] = indxx_(&node1, &node1);
    nodplc[loc + 27] = indxx_(&node2, &node2);
    nodplc[loc + 28] = indxx_(&node3, &node3);
    nodplc[loc + 29] = indxx_(&node4, &node4);
    nodplc[loc + 30] = indxx_(&node5, &node5);
    nodplc[loc + 31] = indxx_(&node6, &node6);
    loc = nodplc[loc - 1];
    goto L870;

/*  TRANSMISSION LINES */

L900:
    loc = cirdat_1.locate[16];
L910:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L1000;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    ni1 = nodplc[loc + 5];
    ni2 = nodplc[loc + 6];
    ibr1 = nodplc[loc + 7];
    ibr2 = nodplc[loc + 8];
    nodplc[loc + 9] = indxx_(&node1, &node1);
    nodplc[loc + 10] = indxx_(&node1, &ni1);
    nodplc[loc + 11] = indxx_(&node2, &ibr1);
    nodplc[loc + 12] = indxx_(&node3, &node3);
    nodplc[loc + 13] = indxx_(&node4, &ibr2);
    nodplc[loc + 14] = indxx_(&ni1, &node1);
    nodplc[loc + 15] = indxx_(&ni1, &ni1);
    nodplc[loc + 16] = indxx_(&ni1, &ibr1);
    nodplc[loc + 17] = indxx_(&ni2, &ni2);
    nodplc[loc + 18] = indxx_(&ni2, &ibr2);
    nodplc[loc + 19] = indxx_(&ibr1, &node2);
    nodplc[loc + 20] = indxx_(&ibr1, &node3);
    nodplc[loc + 21] = indxx_(&ibr1, &node4);
    nodplc[loc + 22] = indxx_(&ibr1, &ni1);
    nodplc[loc + 23] = indxx_(&ibr1, &ibr2);
    nodplc[loc + 24] = indxx_(&ibr2, &node1);
    nodplc[loc + 25] = indxx_(&ibr2, &node2);
    nodplc[loc + 26] = indxx_(&ibr2, &node4);
    nodplc[loc + 27] = indxx_(&ibr2, &ni2);
    nodplc[loc + 28] = indxx_(&ibr2, &ibr1);
    nodplc[loc + 30] = indxx_(&node3, &ni2);
    nodplc[loc + 31] = indxx_(&ni2, &node3);
    loc = nodplc[loc - 1];
    goto L910;

/*  FINISHED */

L1000:
    return 0;
} /* matloc_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int codgen_(void)
{
    /* Local variables */
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE GENERATES MACHINE INSTRUCTIONS (FOR THE CDC 6400) TO */
/* LU-FACTOR AND SOLVE THE SET OF CIRCUIT EQUATIONS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
    return 0;
} /* codgen_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int setmem_(integer *ipntr, integer *ksize)
{
    /* Local variables */
    extern integer locf_();
    static integer nevn, icheck, ifamwa;
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int errmem_(integer *, integer *, integer *);
    extern integer nxtmem_(integer *);
    extern /* Subroutine */ int memory_(void);
    extern integer nxtevn_(integer *);


/*     THIS ROUTINE PERFORMS DYNAMIC MEMORY MANAGEMENT.  IT IS USED IN */
/*     SPICE2, AND USEABLE IN ANY PROGRAM. */

/*     MEMORY IS MANAGED WITHIN AN ARRAY SELECTED BY THE CALLING PROGRAM. */
/*     ONE MAY EITHER DIMENSION THIS ARRAY TO THE 'MAXMEM' SIZE, OR MORE */
/*     DESIRABLY, FIND THE ADDRESS OF THE FIRST AVAILABLE WORD OF MEMORY */
/*     ABOVE YOUR PROGRAM, AND DIMENSION YOUR ARRAY TO '1'.  PASSING THE */
/*     ADDRESS OF THE FIRST DATA WORD AVAILABLE PERMITS THE MANAGER TO */
/*     USE 'ILLEGAL' INDICES INTO THE DATA AREA. */

/*     THIS ROUTINE MUST HAVE ACCESS TO AN INTEGER FUNCTION CALLED 'LOCF' */
/*     WHICH RETURNS THE ADDRESS OF ITS ARGUMENT.  ADDRESSES AS USED BY THIS */
/*     PROGRAM REFER TO 'INTEGER' ADDRESSES, NOT BYTE ADDRESSES. */

/* ENTRY POINTS: */
/*      SETMEM - SET INITIAL MEMORY */
/*      GETM4  - GET BLOCK FOR TABLE OF INTEGERS */
/*      GETM8  - GET BLOCK FOR TABLE OF FLOATING POINT VARIABLES */
/*      GETM16 - GET BLOCK FOR TABLE OF COMPLEX VARIABLES */
/*      RELMEM - RELEASE PART OF BLOCK */
/*      EXTMEM - EXTEND SIZE OF EXISTING BLOCK */
/*      SIZMEM - DETERMINE SIZE OF EXISTING BLOCK */
/*      CLRMEM - RELEASE BLOCK */
/*      PTRMEM - RESET MEMORY POINTER */
/*      CRUNCH - FORCE MEMORY COMPACTION */
/*      AVLM4  - AMOUNT OF SPACE AVAILABLE (INTEGERS) */
/*      AVLM8  - AMOUNT OF SPACE AVAILABLE (REAL) */
/*      AVLM16 - AMOUNT OF SPACE AVAILABLE (COMPLEX) */

/* CALLING SEQUENCES: */
/*      CALL SETMEM(IMEM(1),MAXMEM) */
/*      CALL SETMEM(IMEM(1),MAXMEM,KFAMWA)  CDC MACHINES RUNNING UNDER */
/*                                          CALIDOSCOPE KFAMWA IS THE ADDRESS */
/*                                          OF THE FIRST AVAILABLE WORD */
/*      CALL GETM4 (IPNTR,BLKSIZ)  WHERE BLKSIZE IS THE NUMBER OF ENTRIES */
/*      CALL GETM8 (IPNTR,BLKSIZ) */
/*      CALL GETM16(IPNTR,BLKSIZ) */
/*      CALL RELMEM(IPNTR,RELSIZ) */
/*      CALL EXTMEM(IPNTR,EXTSIZ)  EXTSIZ IS THE NUMBER OF ENTRIES TO BE ADDED */
/*      CALL SIZMEM(IPNTR,BLKSIZ) */
/*      CALL CLRMEM(IPNTR) */
/*      CALL PTRMEM(IPNTR1,IPNTR2) */
/*      CALL AVLM4(ISPACE) */
/*      CALL AVLM8(ISPACE) */
/*      CALL AVLM16(ISPACE) */
/*      CALL CRUNCH */
/*      CALL SLPMEM(IPNTR,SLPSIZ)  EXPRESS DESIRE FOR *SLPSIZ* EXTRA ENTRIES */


/* GENERAL COMMENTS: */
/*      FOR EACH BLOCK WHICH IS ALLOCATED, A MULTI-WORD ENTRY IS MAINTAINED */
/* IN A TABLE KEPT IN HIGH MEMORY, OF THE FORM */

/*        WORD      CONTENTS */
/*        ----      -------- */

/*          1       INDEX OF IMEM(.) INTO ORIGIN OF BLOCK */
/*                    I.E. CONTENTS OF POINTER (USED FOR ERROR CHECK) */
/*          2       BLOCK SIZE (IN WORDS) */
/*          3       NUMBER OF WORDS IN USE */
/*          4       ADDRESS OF VARIABLE CONTAINING BLOCK ORIGIN */
/*          5       NUMBER OF WORDS USED PER TABLE ENTRY */
/*          6       SLOP SIZE (IN WORDS) */

/*      ALL ALLOCATED BLOCKS ARE AN 'EVEN' (NXTEVN) NUMBER OF WORDS IN LENGTH, */
/* WHERE A 'WORD' IS THE STORAGE UNIT REQUIRED FOR AN 'INTEGER' VARIABLE. */
/*      SINCE BLOCK REPOSITIONING MAY BE NECESSARY, THE CONVENTION THAT */
/* ONLY ONE VARIABLE CONTAIN A BLOCK ORIGIN SHOULD BE OBSERVED. */
/*      FOR *GETMEM*, *IPNTR* IS SET SUCH THAT *ARRAY(IPNTR+1)* IS THE */
/* FIRST WORD OF THE ALLOCATED BLOCK.  'IPNTR' IS SET TO ADDRESS THE FIRST */
/* ENTRY OF THE TABLE WHEN USED WITH THE APPROPRIATE VARIABLE TYPE, I.E., */
/* NODPLC(IPNTR+1), VALUE(IPNTR+1), OR CVALUE(IPNTR+1). */
/*      FOR *CLRMEM*, *IPNTR* IS SET TO 'INVALID' TO ENABLE RAPID DETECTION */
/* OF AN ATTEMPT TO USE A CLEARED BLOCK. */
/*      IF ANY FATAL ERRORS ARE FOUND, A MESSAGE IS PRINTED AND A FLAG */
/* SET INHIBITING FURTHER ACTION UNTIL *SETMEM* IS CALLED.  (IN THIS */
/* CONTEXT, INSUFFICIENT MEMORY IS CONSIDERED A FATAL ERROR.) */
/*      THROUGHOUT THIS ROUTINE, *LDVAL* ALWAYS CONTAINS THE SUBSCRIPT OF */
/* THE LAST ADDRESSABLE WORD OF MEMORY, *MEMAVL* ALWAYS CONTAINS THE */
/* NUMBER OF AVAILABLE WORDS OF MEMORY, *NUMBLK* ALWAYS CONTAINS THE */
/* NUMBER OF ALLOCATED BLOCKS, AND ISTACK(*LOCTAB* +1) ALWAYS CONTAINS */
/* THE FIRST WORD OF THE BLOCK TABLE. */

/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */


/* ...  APPROXIMATE TIME REQUIRED TO COPY *NWORDS* INTEGER VALUES */

/*  NXTEVN ROUNDS THE NUMBER UP TO THE NEXT 'EVEN' VALUE.  THE VALUE */
/*  USED FOR THIS 'EVEN' NUMBER IS THE SMALLEST NUMBER INTO WHICH ONE */
/*  CAN DIVIDE NWD4,NWD8,AND NWD16. */


/*  NXTMEM  RETURNS NEXT HIGHER MEMORY SIZE */



/* ***  SETMEM - SET INITIAL MEMORY */

    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    memmgr_1.nwd4 = 1;
    memmgr_1.nwd8 = locf_(&blank_1.value[1]) - locf_(blank_1.value);
    memmgr_1.nwd16 = locf_(&cvalue[1]) - locf_(cvalue);
    memmgr_1.memerr = 0;
    nevn = nxtevn_(&c__1);
/*     CHECK THAT NXTEVN FUNCTION RETURNS A NUMBER DIVISIBLE BY */
/*     NWD4, NWD8, NWD16; ALSO CHECK THAT THE MEMORY INCREMENT */
/*     NXTMEM(.) IS AN INTEGER MULTIPLE OF NXTEVN(1) */
    icheck = nevn % memmgr_1.nwd4 + nevn % memmgr_1.nwd8 + nevn % 
	    memmgr_1.nwd16 + nxtmem_(&c__1) % nevn;
    if (icheck == 0) {
	goto L2;
    }
    memmgr_1.memerr = 1;
    errmem_(&c__6, &memmgr_1.memerr, &ipntr[1]);
L2:
    memmgr_1.cpyknt = 0.;
    ifamwa = locf_(&ipntr[1]);
    memmgr_1.maxmem = *ksize;
    memmgr_1.ntab = nxtevn_(&c__6);
/* ... ADD 'LORG' TO AN ADDRESS AND YOU GET THE 'ISTACK' INDEX TO THAT WORD */
    memmgr_1.lorg = 1 - locf_(memmgr_1.istack);
    memmgr_1.ifwa = ifamwa + memmgr_1.lorg - 1;
    memmgr_1.nwoff = locf_(&ipntr[1]) + memmgr_1.lorg - 1;
    memmgr_1.icore = nxtmem_(&c__1);
/* ... DON'T TAKE CHANCES, BACK OFF FROM 'END OF MEMORY' BY NXTEVN(1) */
    memmgr_1.ldval = memmgr_1.ifwa + nxtmem_(&c__1) - nxtevn_(&c__1);
    memmgr_1.memavl = memmgr_1.ldval - memmgr_1.ntab - memmgr_1.ifwa;
    memmgr_1.maxcor = 0;
    memmgr_1.maxuse = 0;
    memory_();
    if (memmgr_1.memerr != 0) {
	errmem_(&c__6, &memmgr_1.memerr, &ipntr[1]);
    }
    memmgr_1.numblk = 1;
    memmgr_1.loctab = memmgr_1.ldval - memmgr_1.ntab;
    memmgr_1.istack[memmgr_1.loctab] = 0;
    memmgr_1.istack[memmgr_1.loctab + 1] = memmgr_1.memavl;
    memmgr_1.istack[memmgr_1.loctab + 2] = 0;
    memmgr_1.istack[memmgr_1.loctab + 3] = -1;
    memmgr_1.istack[memmgr_1.loctab + 4] = 1;
    memmgr_1.istack[memmgr_1.loctab + 5] = 0;
    return 0;
} /* setmem_ */

#undef cvalue


integer locf_(integer *ivar)
{
    /* Format strings */
    static char fmt_100[] = "(\0020*ERROR*: SYSTEM ERROR, ADDRESS \002,i10"
	    ",\002 IS NOT ON 4-BYTE BOUNDARY\002)";

    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    extern integer loc_(integer *);
    static integer iabsa;

    /* Fortran I/O blocks */
    static cilist io___258 = { 0, 0, 0, fmt_100, 0 };


/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
    /* Parameter adjustments */
    --ivar;

    /* Function Body */
    iabsa = loc_(&ivar[1]);
    ret_val = iabsa / 4;
    if (iabsa == ret_val << 2) {
	return ret_val;
    }
    io___258.ciunit = status_1.iofile;
    s_wsfe(&io___258);
    do_fio(&c__1, (char *)&iabsa, (ftnlen)sizeof(integer));
    e_wsfe();
    return ret_val;
} /* locf_ */

/* Subroutine */ int getm4_(integer *ipntr, integer *ksize)
{
    extern /* Subroutine */ int getmx_(integer *, integer *, integer *);
    static integer iwsize;

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    iwsize = memmgr_1.nwd4;
    getmx_(&ipntr[1], ksize, &iwsize);
    return 0;
} /* getm4_ */

/* Subroutine */ int getm8_(integer *ipntr, integer *ksize)
{
    extern /* Subroutine */ int getmx_(integer *, integer *, integer *);
    static integer iwsize;

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    iwsize = memmgr_1.nwd8;
    getmx_(&ipntr[1], ksize, &iwsize);
    return 0;
} /* getm8_ */

/* Subroutine */ int getm16_(integer *ipntr, integer *ksize)
{
    extern /* Subroutine */ int getmx_(integer *, integer *, integer *);
    static integer iwsize;

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    iwsize = memmgr_1.nwd16;
    getmx_(&ipntr[1], ksize, &iwsize);
    return 0;
} /* getm16_ */

/* Subroutine */ int getmx_(integer *ipntr, integer *ksize, integer *iwsize)
{
    static integer need, madr;
    extern integer locf_(integer *);
    static integer morg, muse, msiz, ltab1;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *);
    static integer isize, jsize;
    extern /* Subroutine */ int memadj_(void), errmem_(integer *, integer *, 
	    integer *), comprs_(integer *, integer *);
    extern logical memptr_(integer *);
    extern integer nxtmem_(integer *);
    extern /* Subroutine */ int memory_(void);
    static integer nwords;
    extern integer nxtevn_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  GETMEM - GET BLOCK */


    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    isize = *ksize * *iwsize;
/* ...  CHECK FOR VALID SIZE */
    if (isize >= 0) {
	goto L5;
    }
    memmgr_1.memerr = 2;
    errmem_(&c__3, &memmgr_1.memerr, &ipntr[1]);
/* ...  CHECK FOR ATTEMPT TO REALLOCATE EXISTING BLOCK */
L5:
    if (! memptr_(&ipntr[1])) {
	goto L8;
    }
    memmgr_1.memerr = 3;
    errmem_(&c__3, &memmgr_1.memerr, &ipntr[1]);
L8:
    jsize = nxtevn_(&isize);
    comprs_(&c__0, &memmgr_1.ldval);
/* ...  CHECK IF ENOUGH SPACE ALREADY THERE */
    need = jsize + memmgr_1.ntab - memmgr_1.memavl;
    if (need <= 0) {
	goto L10;
    }
/* ...  INSUFFICIENT SPACE -- BUMP MEMORY SIZE */
    need = nxtmem_(&need);
    memmgr_1.icore += need;
    memory_();
    if (memmgr_1.memerr != 0) {
	errmem_(&c__3, &memmgr_1.memerr, &ipntr[1]);
    }
    ltab1 = memmgr_1.ldval - memmgr_1.ntab;
    memmgr_1.istack[ltab1 + 1] += need;
/* ...  RELOCATE BLOCK ENTRY TABLE */
    nwords = memmgr_1.numblk * memmgr_1.ntab;
    memmgr_1.cpyknt += (doublereal) nwords;
    copy4_(&memmgr_1.istack[memmgr_1.loctab], &memmgr_1.istack[
	    memmgr_1.loctab + need], &nwords);
    memmgr_1.loctab += need;
    memmgr_1.ldval += need;
    memmgr_1.memavl += need;
/* ...  A BLOCK LARGE ENOUGH NOW EXISTS -- ALLOCATE IT */
L10:
    ltab1 = memmgr_1.ldval - memmgr_1.ntab;
    morg = memmgr_1.istack[ltab1];
    msiz = memmgr_1.istack[ltab1 + 1];
    muse = memmgr_1.istack[ltab1 + 2];
    muse = nxtevn_(&muse);
    madr = memmgr_1.istack[ltab1 + 3];
/* ...  CONSTRUCT NEW TABLE ENTRY */
/* L15: */
    memmgr_1.istack[ltab1 + 1] = muse;
    memmgr_1.loctab -= memmgr_1.ntab;
    nwords = memmgr_1.numblk * memmgr_1.ntab;
    memmgr_1.cpyknt += (doublereal) nwords;
    copy4_(&memmgr_1.istack[memmgr_1.loctab + memmgr_1.ntab], &
	    memmgr_1.istack[memmgr_1.loctab], &nwords);
    ++memmgr_1.numblk;
    memmgr_1.memavl -= memmgr_1.ntab;
    memmgr_1.istack[ltab1] = morg + muse;
    memmgr_1.istack[ltab1 + 1] = msiz - muse - memmgr_1.ntab;
/* ...  SET USER SIZE INTO TABLE ENTRY FOR THIS BLOCK */
/* L20: */
    memmgr_1.istack[ltab1 + 2] = isize;
    memmgr_1.istack[ltab1 + 3] = locf_(&ipntr[1]);
    memmgr_1.istack[ltab1 + 4] = *iwsize;
    memmgr_1.istack[ltab1 + 5] = 0;
    memmgr_1.memavl -= jsize;
    ipntr[1] = memmgr_1.istack[ltab1] / *iwsize;
    memadj_();
    return 0;
} /* getmx_ */

/* Subroutine */ int avlm4_(integer *iavl)
{
    extern integer nxtmem_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    *iavl = (memmgr_1.maxmem - memmgr_1.icore) / nxtmem_(&c__1) * nxtmem_(&
	    c__1) - memmgr_1.ntab + memmgr_1.memavl;
    *iavl /= memmgr_1.nwd4;
    return 0;
} /* avlm4_ */

/* Subroutine */ int avlm8_(integer *iavl)
{
    extern integer nxtmem_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    *iavl = (memmgr_1.maxmem - memmgr_1.icore) / nxtmem_(&c__1) * nxtmem_(&
	    c__1) - memmgr_1.ntab + memmgr_1.memavl;
    *iavl /= memmgr_1.nwd8;
    return 0;
} /* avlm8_ */

/* Subroutine */ int avlm16_(integer *iavl)
{
    extern integer nxtmem_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    *iavl = (memmgr_1.maxmem - memmgr_1.icore) / nxtmem_(&c__1) * nxtmem_(&
	    c__1) - memmgr_1.ntab + memmgr_1.memavl;
    *iavl /= memmgr_1.nwd16;
    return 0;
} /* avlm16_ */

/* Subroutine */ int relmem_(integer *ipntr, integer *ksize)
{
    static integer isize, jsize;
    extern /* Subroutine */ int memadj_(void), errmem_(integer *, integer *, 
	    integer *);
    extern logical memptr_(integer *);
    extern integer nxtevn_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  RELMEM - RELEASE PART OF BLOCK */


/* ...  CHECK FOR VALID POINTER */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    if (memptr_(&ipntr[1])) {
	goto L10;
    }
    memmgr_1.memerr = 5;
    errmem_(&c__5, &memmgr_1.memerr, &ipntr[1]);
L10:
    isize = *ksize * memmgr_1.istack[memmgr_1.ltab + 4];
/* ...  CHECK FOR VALID SIZE */
    if (isize >= 0) {
	goto L20;
    }
    memmgr_1.memerr = 2;
    errmem_(&c__5, &memmgr_1.memerr, &ipntr[1]);
L20:
    jsize = memmgr_1.istack[memmgr_1.ltab + 2];
    if (isize <= jsize) {
	goto L30;
    }
    memmgr_1.memerr = 6;
    errmem_(&c__5, &memmgr_1.memerr, &ipntr[1]);
L30:
    memmgr_1.istack[memmgr_1.ltab + 2] -= isize;
    memmgr_1.memavl += nxtevn_(&jsize) - nxtevn_(&memmgr_1.istack[
	    memmgr_1.ltab + 2]);
    memadj_();
    return 0;
} /* relmem_ */

/* Subroutine */ int extmem_(integer *ipntr, integer *ksize)
{
    static integer need, ltab1;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *);
    static integer isize, jsize;
    extern /* Subroutine */ int memadj_(void), errmem_(integer *, integer *, 
	    integer *), comprs_(integer *, integer *);
    extern logical memptr_(integer *);
    extern integer nxtmem_(integer *);
    extern /* Subroutine */ int memory_(void);
    static integer nwords;
    extern integer nxtevn_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  EXTMEM - EXTEND SIZE OF EXISTING BLOCK */


/* ...  CHECK FOR VALID POINTER */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    if (memptr_(&ipntr[1])) {
	goto L10;
    }
    memmgr_1.memerr = 5;
    errmem_(&c__2, &memmgr_1.memerr, &ipntr[1]);
L10:
    isize = *ksize * memmgr_1.istack[memmgr_1.ltab + 4];
/* ...  CHECK FOR VALID SIZE */
    if (isize >= 0) {
	goto L20;
    }
    memmgr_1.memerr = 2;
    errmem_(&c__2, &memmgr_1.memerr, &ipntr[1]);
/* ...  CHECK IF ENOUGH SPACE ALREADY THERE */
L20:
    if (memmgr_1.istack[memmgr_1.ltab + 1] - memmgr_1.istack[memmgr_1.ltab + 
	    2] >= isize) {
	goto L40;
    }
    need = nxtevn_(&isize) - memmgr_1.memavl;
    if (need <= 0) {
	goto L30;
    }
/* ...  INSUFFICIENT SPACE -- BUMP MEMORY SIZE */
    need = nxtmem_(&need);
    memmgr_1.icore += need;
    memory_();
    if (memmgr_1.memerr != 0) {
	errmem_(&c__2, &memmgr_1.memerr, &ipntr[1]);
    }
    ltab1 = memmgr_1.ldval - memmgr_1.ntab;
    memmgr_1.istack[ltab1 + 1] += need;
/* ...  RELOCATE BLOCK ENTRY TABLE */
    nwords = memmgr_1.numblk * memmgr_1.ntab;
    memmgr_1.cpyknt += (doublereal) nwords;
    copy4_(&memmgr_1.istack[memmgr_1.loctab], &memmgr_1.istack[
	    memmgr_1.loctab + need], &nwords);
    memmgr_1.loctab += need;
    memmgr_1.ldval += need;
    memmgr_1.memavl += need;
    memmgr_1.ltab += need;
/* ...  MOVE BLOCKS TO MAKE SPACE */
L30:
    comprs_(&c__0, &memmgr_1.ltab);
    comprs_(&c__1, &memmgr_1.ltab);
L40:
    jsize = memmgr_1.istack[memmgr_1.ltab + 2];
    memmgr_1.istack[memmgr_1.ltab + 2] += isize;
    memmgr_1.memavl -= nxtevn_(&memmgr_1.istack[memmgr_1.ltab + 2]) - nxtevn_(
	    &jsize);
    memadj_();
    return 0;
} /* extmem_ */

/* Subroutine */ int sizmem_(integer *ipntr, integer *ksize)
{
    extern /* Subroutine */ int errmem_(integer *, integer *, integer *);
    extern logical memptr_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  SIZMEM - DETERMINE SIZE OF EXISTING BLOCK */


/* ...  CHECK FOR VALID POINTER */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    if (memptr_(&ipntr[1])) {
	goto L10;
    }
    memmgr_1.memerr = 5;
    errmem_(&c__7, &memmgr_1.memerr, &ipntr[1]);
L10:
    *ksize = memmgr_1.istack[memmgr_1.ltab + 2] / memmgr_1.istack[
	    memmgr_1.ltab + 4];
    return 0;
} /* sizmem_ */

/* Subroutine */ int clrmem_(integer *ipntr)
{
    static integer muse, msiz, ltab1;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *), 
	    memadj_(void), errmem_(integer *, integer *, integer *);
    extern logical memptr_(integer *);
    static integer nwords;
    extern integer nxtevn_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  CLRMEM - RELEASE BLOCK */


/* ...  CHECK THAT POINTER IS VALID */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    if (memptr_(&ipntr[1])) {
	goto L10;
    }
    memmgr_1.memerr = 5;
    errmem_(&c__1, &memmgr_1.memerr, &ipntr[1]);
L10:
    msiz = memmgr_1.istack[memmgr_1.ltab + 1];
    muse = memmgr_1.istack[memmgr_1.ltab + 2];
    memmgr_1.memavl = memmgr_1.memavl + nxtevn_(&muse) + memmgr_1.istack[
	    memmgr_1.ltab + 5];
/* ...  ASSUMPTION:  FIRST ALLOCATED BLOCK IS NEVER CLEARED. */
    ltab1 = memmgr_1.ltab - memmgr_1.ntab;
    memmgr_1.istack[ltab1 + 1] += msiz;
/* ...  REPOSITION THE BLOCK TABLE */
    nwords = memmgr_1.ltab - memmgr_1.loctab;
    memmgr_1.cpyknt += (doublereal) nwords;
    copy4_(&memmgr_1.istack[memmgr_1.loctab], &memmgr_1.istack[
	    memmgr_1.loctab + memmgr_1.ntab], &nwords);
    --memmgr_1.numblk;
    memmgr_1.loctab += memmgr_1.ntab;
    memmgr_1.memavl += memmgr_1.ntab;
    ltab1 = memmgr_1.ldval - memmgr_1.ntab;
    memmgr_1.istack[ltab1 + 1] += memmgr_1.ntab;
    ipntr[1] = 1073741823;
    memadj_();
    return 0;
} /* clrmem_ */

/* Subroutine */ int ptrmem_(integer *ipntr, integer *ipntr2)
{
    extern integer locf_(integer *);
    extern /* Subroutine */ int memadj_(void), errmem_(integer *, integer *, 
	    integer *);
    extern logical memptr_(integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */

/* ***  PTRMEM - RESET MEMORY POINTER */

/* ...  VERIFY THAT POINTER IS VALID */
    /* Parameter adjustments */
    --ipntr2;
    --ipntr;

    /* Function Body */
    if (memptr_(&ipntr[1])) {
	goto L10;
    }
    memmgr_1.memerr = 5;
    errmem_(&c__4, &memmgr_1.memerr, &ipntr[1]);
/* ...  RESET BLOCK POINTER TO BE *IPNTR2* */
L10:
    ipntr2[1] = ipntr[1];
    memmgr_1.istack[memmgr_1.ltab + 3] = locf_(&ipntr2[1]);
    memadj_();
    return 0;
} /* ptrmem_ */

/* Subroutine */ int crunch_(void)
{
    extern /* Subroutine */ int memadj_(void), comprs_(integer *, integer *);

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    comprs_(&c__0, &memmgr_1.ldval);
    memadj_();
    return 0;
} /* crunch_ */

/* Subroutine */ int errmem_(integer *inam, integer *ierror, integer *ipntr)
{
    /* Initialized data */

    static struct {
	char e_1[56];
	doublereal e_2;
	} equiv_290 = { "CLRMEM  EXTMEM  GETMEM  PTRMEM  RELMEM  SETMEM  SIZ"
		"MEM  ", 0. };

#define errnam ((doublereal *)&equiv_290)


    /* Format strings */
    static char fmt_201[] = "(\0020MEMORY MANAGER VARIABLES NWD4-8-16 INCOMP"
	    "ATIBLE WITH NXTEVN AND NXTMEM\002)";
    static char fmt_301[] = "(\0020*ERROR*:  MEMORY REQUIREMENT EXCEEDS MACH"
	    "INE CAPACITY\002,/\0020 MEMORY NEEDS EXCEED\002,i6,\002(\002,o6"
	    ",\002B)\002/)";
    static char fmt_411[] = "(\0020SIZE PARAMETER NEGATIVE\002)";
    static char fmt_421[] = "(\0020ATTEMPT TO REALLOCATE EXISTING TABLE\002)";
    static char fmt_511[] = "(\0020TABLE POINTER INVALID\002)";
    static char fmt_531[] = "(\0020ATTEMPT TO RELEASE MORE THAN TOTAL TABL"
	    "E\002)";
    static char fmt_901[] = "(\0020*ABORT*:  INTERNAL MEMORY MANAGER ERROR A"
	    "T ENTRY \002,a7)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int dmpmem_();

    /* Fortran I/O blocks */
    static cilist io___283 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___284 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___285 = { 0, 0, 0, fmt_411, 0 };
    static cilist io___286 = { 0, 0, 0, fmt_421, 0 };
    static cilist io___287 = { 0, 0, 0, fmt_511, 0 };
    static cilist io___288 = { 0, 0, 0, fmt_531, 0 };
    static cilist io___289 = { 0, 0, 0, fmt_901, 0 };


/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */

    switch (*ierror) {
	case 1:  goto L200;
	case 2:  goto L410;
	case 3:  goto L420;
	case 4:  goto L300;
	case 5:  goto L510;
	case 6:  goto L530;
    }

/* *** ERROR(S) FOUND *** */

/* .. NXTEVN AND/OR NXTMEM INCOMPATIBLE WITH NWD4, NWD8, AND NWD16 */

L200:
    io___283.ciunit = status_1.iofile;
    s_wsfe(&io___283);
    e_wsfe();
    goto L900;

/* ...  MEMORY NEEDS EXCEED MAXIMUM AVAILABLE SPACE */
L300:
    io___284.ciunit = status_1.iofile;
    s_wsfe(&io___284);
    do_fio(&c__1, (char *)&memmgr_1.maxmem, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.maxmem, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L900;
/* ...    *ISIZE* < 0 */
L410:
    io___285.ciunit = status_1.iofile;
    s_wsfe(&io___285);
    e_wsfe();
    goto L900;
/* ...  GETMEM:  ATTEMPT TO REALLOCATE EXISTING BLOCK */
L420:
    io___286.ciunit = status_1.iofile;
    s_wsfe(&io___286);
    e_wsfe();
    goto L900;
/* ...    *IPNTR* INVALID */
L510:
    io___287.ciunit = status_1.iofile;
    s_wsfe(&io___287);
    e_wsfe();
    goto L900;
/* ...  RELMEM:  *ISIZE* LARGER THAN INDICATED BLOCK */
L530:
    io___288.ciunit = status_1.iofile;
    s_wsfe(&io___288);
    e_wsfe();
/* ...  ISSUE ERROR MESSAGE */
L900:
    io___289.ciunit = status_1.iofile;
    s_wsfe(&io___289);
    do_fio(&c__1, (char *)&errnam[*inam - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L950: */
    dmpmem_(&ipntr[1]);
/* L1000: */
    s_stop("", (ftnlen)0);
    return 0;
} /* errmem_ */

#undef errnam


/* Subroutine */ int memadj_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ltab1;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *);
    static integer memdec, memdel;
    extern /* Subroutine */ int comprs_(integer *, integer *);
    extern integer nxtmem_(integer *);
    extern /* Subroutine */ int memory_(void);
    static integer nwords;

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* L50: */
/* Computing MAX */
    i__1 = memmgr_1.maxuse, i__2 = memmgr_1.ldval - memmgr_1.memavl - 
	    memmgr_1.ifwa;
    memmgr_1.maxuse = max(i__1,i__2);
    memdec = nxtmem_(&c__1) << 1;
    if (memmgr_1.memavl < memdec) {
	return 0;
    }
/* ...  COMPRESS CURRENT ALLOCATIONS OF MEMORY */
    comprs_(&c__0, &memmgr_1.ldval);
/* ...  ADJUST MEMORY SIZE */
    memdel = 0;
L60:
    memmgr_1.icore -= memdec;
    memdel += memdec;
    memmgr_1.memavl -= memdec;
    if (memmgr_1.memavl >= memdec) {
	goto L60;
    }
    ltab1 = memmgr_1.ldval - memmgr_1.ntab;
    memmgr_1.istack[ltab1 + 1] -= memdel;
/* ...  RELOCATE BLOCK ENTRY TABLE */
    nwords = memmgr_1.numblk * memmgr_1.ntab;
    memmgr_1.cpyknt += (doublereal) nwords;
    copy4_(&memmgr_1.istack[memmgr_1.loctab], &memmgr_1.istack[
	    memmgr_1.loctab - memdel], &nwords);
    memmgr_1.loctab -= memdel;
    memmgr_1.ldval -= memdel;
    memory_();
    return 0;
} /* memadj_ */

/* Subroutine */ int slpmem_(integer *ipntr, integer *ksize)
{
    static integer islp;
    extern /* Subroutine */ int extmem_(integer *, integer *);
    extern integer nxtevn_(integer *);


/*      THIS ROUTINE MAY BE USED TO DEFINE A CERTAIN AMOUNT OF `SLOP' TO */
/* BE ASSOCIATED WITH A PARTICULAR TABLE MANAGED BY THE MEMORY MANAGER. */
/* THIS *SLOP* IS DEFINED AS A NUMBER OF ENTRIES IN THE TABLE FOR WHICH */
/* SPACE IS TO BE HELD ***IF POSSIBLE*** DURING COMPACTION OF THE MANAGED */
/* AREA OF MEMORY.  THIS FEATURE CAN ELIMINATE THE OVERHEAD INCURRED BY */
/* ALTERNATIVELY EXTENDING MORE THAN ONE TABLE AT A TIME.  (FOR EXAMPLE, */
/* IF THE PROGRAM CONTAINS A CODE SEQUENCE */

/*                  DO 100 I=1,500 */
/*                     ... */
/*                  CALL EXTMEM(TABLE1,1) */
/*                     ... */
/*                  CALL EXTMEM(TABLE2,1) */
/*                     ... */
/*              100 CONTINUE */

/* THEN THE OVERHEAD INCURRED BY THIS MEMORY MANAGER CAN BE REDUCED TO */
/* ESSENTIALLY NOTHING IF PRIOR TO THE ABOVE CODE SEQUENCE THE PROGRAM */
/* EXECUTES */

/*                  CALL SLPMEM(TABLE1,20) */
/*                  CALL SLPMEM(TABLE2,20) */

/* WHERE `20' IS A TYPICAL NUMBER (FOR THE ABOVE EXAMPLE, THE MEMORY-TO- */
/* MEMORY COPYING OVERHEAD OF THE MEMORY MANAGER WOULD BE REDUCED BY A */
/* FACTOR OF 20). */

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    islp = nxtevn_(ksize);
    extmem_(&ipntr[1], &islp);
    islp *= memmgr_1.istack[memmgr_1.ltab + 4];
    memmgr_1.istack[memmgr_1.ltab + 2] -= islp;
    memmgr_1.memavl += memmgr_1.istack[memmgr_1.ltab + 5];
    memmgr_1.istack[memmgr_1.ltab + 5] = islp;
    return 0;
} /* slpmem_ */

integer nxtevn_(integer *n)
{
    /* System generated locals */
    integer ret_val;


/* .. FUNCTION RETURNS THE SMALLEST VALUE NXTEVN GREATER THAN OR EQUAL TO */
/* .. N WHICH IS EVENLY DIVISIBLE BY 'NWD4, NWD8, AND NWD16' AS DEFINED */
/* .. IN SETMEM */

    ret_val = (*n + 3) / 4 << 2;
    return ret_val;
} /* nxtevn_ */

integer nxtmem_(integer *memwds)
{
    /* System generated locals */
    integer ret_val;


/* .. FUNCTION RETURNS THE IN NXTMEM THE NEXT AVAILABLE MEMORY SIZE */
/* .. (WHICH MUST BE EVENLY DIVISIBLE BY 'NWD4, NWD8, AND NWD16' AS */
/* .. DEFINED IN SETMEM */

    ret_val = (*memwds + 1999) / 2000 * 2000;
    return ret_val;
} /* nxtmem_ */

/* Subroutine */ int comprs_(integer *icode, integer *limit)
{
    static integer madr, nblk, mspc, morg, muse, mslp, msiz, ltab1, ltab2, 
	    madr2, morg2, muse2;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *);
    static integer muser, iwsize;
    extern integer nxtevn_(integer *);


/*      THIS ROUTINE COMPRESSES ALL AVAILABLE MEMORY INTO A SINGLE BLOCK. */
/* IF *ICODE* IS ZERO, COMPRESSION OF MEMORY FROM WORD 1 TO *LIMIT* IS */
/* DONE;  OTHERWISE, COMPRESSION FROM *LDVAL* DOWN TO *LIMIT* IS DONE. */

/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    if (*icode != 0) {
	goto L100;
    }
    nblk = memmgr_1.numblk;
    ltab2 = memmgr_1.loctab;
L10:
    ltab1 = ltab2;
    if (ltab1 >= *limit) {
	goto L200;
    }
    if (nblk == 1) {
	goto L200;
    }
    --nblk;
    ltab2 = ltab1 + memmgr_1.ntab;
    morg = memmgr_1.istack[ltab1];
    msiz = memmgr_1.istack[ltab1 + 1];
    muse = nxtevn_(&memmgr_1.istack[ltab1 + 2]);
    mslp = memmgr_1.istack[ltab1 + 5];
    if (msiz - muse <= mslp) {
	goto L10;
    }
    muse += mslp;
/* ...  MOVE SUCCEEDING BLOCK DOWN */
    morg2 = memmgr_1.istack[ltab2];
    muse2 = memmgr_1.istack[ltab2 + 2];
    madr2 = memmgr_1.istack[ltab2 + 3];
    iwsize = memmgr_1.istack[ltab2 + 4];
    if (madr2 != 0) {
	goto L15;
    }
    if (muse2 == 0) {
	goto L20;
    }
L15:
    memmgr_1.cpyknt += (doublereal) muse2;
    copy4_(&memmgr_1.istack[memmgr_1.nwoff + morg2], &memmgr_1.istack[
	    memmgr_1.nwoff + morg + muse], &muse2);
    memmgr_1.istack[memmgr_1.lorg + madr2 - 1] = (morg + muse) / iwsize;
L20:
    memmgr_1.istack[ltab1 + 1] = muse;
    memmgr_1.istack[ltab2] = morg + muse;
    memmgr_1.istack[ltab2 + 1] += msiz - muse;
    goto L10;


L100:
    nblk = memmgr_1.numblk;
    ltab2 = memmgr_1.ldval - memmgr_1.ntab;
L110:
    ltab1 = ltab2;
    if (ltab1 <= *limit) {
	goto L200;
    }
    if (nblk == 1) {
	goto L200;
    }
    --nblk;
    ltab2 = ltab1 - memmgr_1.ntab;
    morg = memmgr_1.istack[ltab1];
    msiz = memmgr_1.istack[ltab1 + 1];
    muser = memmgr_1.istack[ltab1 + 2];
    muse = nxtevn_(&muser);
    madr = memmgr_1.istack[ltab1 + 3];
    iwsize = memmgr_1.istack[ltab1 + 4];
    mslp = memmgr_1.istack[ltab1 + 5];
    if (msiz - muse <= mslp) {
	goto L110;
    }
    muse += mslp;
    mspc = msiz - muse;
    memmgr_1.cpyknt += (doublereal) muser;
    copy4_(&memmgr_1.istack[memmgr_1.nwoff + morg], &memmgr_1.istack[
	    memmgr_1.nwoff + morg + mspc], &muser);
    memmgr_1.istack[ltab1] = morg + mspc;
    memmgr_1.istack[ltab1 + 1] = muse;
    memmgr_1.istack[ltab2 + 1] += mspc;
    if (madr == 0) {
	goto L110;
    }
    memmgr_1.istack[memmgr_1.lorg + madr - 1] = (morg + mspc) / iwsize;
    goto L110;
/* ...  ALL DONE */
L200:
    return 0;
} /* comprs_ */

logical memptr_(integer *ipntr)
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer i__;
    extern integer locf_(integer *);
    static integer locpnt;


/*      THIS ROUTINE CHECKS WHETHER *IPNTR* IS A VALID BLOCK POINTER. */
/* IF IT IS VALID, *LTAB* IS SET TO POINT TO THE CORRESPONDING ENTRY IN */
/* THE BLOCK TABLE. */

/* ... IPNTR IS AN ARRAY TO AVOID 'CALL BY VALUE' PROBLEMS (SEE SETMEM) */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */
    ret_val = FALSE_;
    memmgr_1.ltab = memmgr_1.loctab;
    locpnt = locf_(&ipntr[1]);
    i__1 = memmgr_1.numblk;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (locpnt != memmgr_1.istack[memmgr_1.ltab + 3]) {
	    goto L10;
	}
	if (ipntr[1] * memmgr_1.istack[memmgr_1.ltab + 4] != memmgr_1.istack[
		memmgr_1.ltab]) {
	    goto L10;
	}
	ret_val = TRUE_;
	goto L30;
L10:
	memmgr_1.ltab += memmgr_1.ntab;
/* L20: */
    }
L30:
    return ret_val;
} /* memptr_ */

/* Subroutine */ int dmpmem_(integer *ipntr)
{
    /* Initialized data */

    static struct {
	char e_1[600];
	doublereal e_2;
	} equiv_329 = { "IELMNT  ISBCKT  NSBCKT  IUNSAT  NUNSAT  ITEMPS  NUM"
		"TEM  ISENS   NSENS   IFOUR   NFOUR   IFIELD  ICODE   IDELIM "
		" ICOLUM  INSIZE  JUNODE  LSBKPT  NUMBKP  IORDER  JMNODE  IUR"
		"     IUC     ILC     ILR     NUMOFF  ISR     NMOFFC  ISEQ   "
		" ISEQ1   NEQN    NODEVS  NDIAG   ISWAP   IEQUA   MACINS  LVN"
		"IM1  LX0     LVN     LYNL    LYU     LYL     LX1     LX2    "
		" LX3     LX4     LX5     LX6     LX7     LD0     LD1     LTD"
		"     IMYNL   IMVN    LCVN    NSNOD   NSMAT   NSVAL   ICNOD  "
		" ICMAT   ICVAL   LOUTPT  LPOL    LZER    IRSWPF  IRSWPR  ICS"
		"WPF  ICSWPR  IRPT    JCPT    IROWNO  JCOLNO  NTTBR   NTTAR  "
		" LVNTMP  ", 0. };

#define aptr ((doublereal *)&equiv_329)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_330 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_330)


    /* Format strings */
    static char fmt_5[] = "(\0020CURRENT POINTER \002,a6,\002@ = Z\002,i6,"
	    "/\002 CORSIZ=\002,i7,/\002 MAXMEM=\002,i7,/\002 AVLSPC=\002,i7,"
	    "/\002 LDVAL=\002,i7,/\0020\002,24x,\002MEMORY ALLOCATION MAP\002"
	    "/14x,\002BLKNUM MEMORG MEMSIZ\002,\002  MEMUSE USRPTR  ADDR    N"
	    "AME\002)";
    static char fmt_11[] = "(13x,5i7,3x,i7,\002Z\002,1x,a6)";
    static char fmt_21[] = "(\0020\002,24x,\002END OF ALLOCATION MAP\002/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    static doublereal anam;
    static integer iadr;
    extern integer locf_(integer *);
    static integer madr, morg, muse, ndex, jptr, msiz, ltab1, iaddr, itemp;

    /* Fortran I/O blocks */
    static cilist io___318 = { 0, 0, 0, fmt_5, 0 };
    static cilist io___327 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___328 = { 0, 0, 0, fmt_21, 0 };



/*      THIS ROUTINE PRINTS OUT THE CURRENT MEMORY ALLOCATION MAP. */
/* *IPNTR* IS THE TABLE POINTER OF THE CURRENT MEMORY MANAGER CALL */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
    /* Parameter adjustments */
    --ipntr;

    /* Function Body */

    iaddr = locf_(&tabinf_1.ielmnt) - 1;
    itemp = locf_(&ipntr[1]) - iaddr;
    anam = ablnk;
    if (itemp > 0 && itemp <= 75) {
	anam = aptr[itemp - 1];
    }
    iadr = locf_(&ipntr[1]);
    io___318.ciunit = status_1.iofile;
    s_wsfe(&io___318);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&iadr, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.icore, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.maxmem, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.memavl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&memmgr_1.ldval, (ftnlen)sizeof(integer));
    e_wsfe();
    ltab1 = memmgr_1.loctab;
    i__1 = memmgr_1.numblk;
    for (i__ = 1; i__ <= i__1; ++i__) {
	morg = memmgr_1.istack[ltab1];
	msiz = memmgr_1.istack[ltab1 + 1];
	muse = memmgr_1.istack[ltab1 + 2];
	madr = memmgr_1.istack[ltab1 + 3];
	anam = ablnk;
	ndex = madr - iaddr;
	if (ndex > 0 && ndex <= 75) {
	    anam = aptr[ndex - 1];
	}
	jptr = 0;
	if (madr > 0) {
	    jptr = memmgr_1.istack[memmgr_1.lorg + madr - 1];
	}
	io___327.ciunit = status_1.iofile;
	s_wsfe(&io___327);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&morg, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&msiz, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&muse, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jptr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&madr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
	e_wsfe();
	ltab1 += memmgr_1.ntab;
/* L20: */
    }
    io___328.ciunit = status_1.iofile;
    s_wsfe(&io___328);
    e_wsfe();
    return 0;
} /* dmpmem_ */

#undef ablnk
#undef aptr


/* Subroutine */ int memory_(void)
{
/* SPICE VERSION 2G.6  SCCSID=MEMMGR 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
    if (memmgr_1.icore <= memmgr_1.maxmem) {
	goto L10;
    }
/* L5: */
    memmgr_1.memerr = 4;
    return 0;
L10:

/*  SET JOB FIELD LENGTH TO 'ICORE+LOCF(ISTACK(IFWA))' */

    return 0;
} /* memory_ */

/* Subroutine */ int magphs_(complex *cvar, doublereal *xmag, doublereal *
	xphs)
{
    /* Builtin functions */
    double r_imag(complex *), sqrt(doublereal), atan2(doublereal, doublereal);

    /* Local variables */
    static doublereal ximag, xreal;


/*     THIS ROUTINE COMPUTES THE MAGNITUDE AND PHASE OF ITS COMPLEX ARG- */
/* UMENT CVAR, STORING THE RESULTS IN XMAG AND XPHS. */

/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */


    xreal = (doublereal) cvar->r;
    ximag = (doublereal) r_imag(cvar);
    *xmag = sqrt(xreal * xreal + ximag * ximag);
    if (*xmag >= 1e-20) {
	goto L10;
    }
    *xmag = 1e-20;
    *xphs = 0.;
    return 0;
L10:
    *xphs = knstnt_1.rad * atan2(ximag, xreal);
    return 0;
} /* magphs_ */

integer xxor_(doublereal *a, doublereal *b)
{
    /* System generated locals */
    integer ret_val;


/*     THIS ROUTINE COMPUTES A SINGLE-PRECISION INTEGER RESULT WHICH IS */
/* THE RESULT OF EXCLUSIVE-OR*ING THE TWO REAL-VALUED ARGUMENTS A AND B */
/* TOGETHER. */

    ret_val = 1;
    if (*a == *b) {
	ret_val = 0;
    }
    return ret_val;
} /* xxor_ */

/* Subroutine */ int outnam_(integer *loc, integer *ktype, doublereal *string,
	 integer *ipos)
{
    /* Initialized data */

    static struct {
	char e_1[152];
	doublereal e_2;
	} equiv_351 = { "V       VM      VR      VI      VP      VDB     I  "
		"     IM      IR      II      IP      IDB     ONOISE  INOISE "
		" HD2     HD3     DIM2    SIM2    DIM3    ", 0. };

#define aout ((doublereal *)&equiv_351)

    static integer lenout[19] = { 1,2,2,2,2,3,1,2,2,2,2,3,6,6,3,3,4,4,4 };
    static struct {
	char e_1[40];
	doublereal e_2;
	} equiv_352 = { "MAG     REAL    IMAG    PHASE   DB      ", 0. };

#define aopt ((doublereal *)&equiv_352)

    static integer lenopt[5] = { 3,4,4,5,2 };
    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_353 = { "(       ", 0. };

#define alprn (*(doublereal *)&equiv_353)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_354 = { ",       ", 0. };

#define acomma (*(doublereal *)&equiv_354)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_355 = { ")       ", 0. };

#define arprn (*(doublereal *)&equiv_355)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_356 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_356)


    /* Local variables */
    static integer i__;
    static doublereal anam;
    static integer locv;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer lout, node1, node2;
    static doublereal achar;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *);
    static integer ioutyp;


/*     THIS ROUTINE CONSTRUCTS THE 'NAME' FOR THE OUTPUT VARIABLE INDI- */
/* CATED BY LOC, ADDING THE CHARACTERS TO THE CHARACTER ARRAY 'STRING', */
/* BEGINNING WITH THE POSITION MARKED BY IPOS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

    /* Parameter adjustments */
    --string;

    /* Function Body */


    ioutyp = nodplc[(0 + (0 + (*loc + 5 - 1 << 2))) / 4];
    if (ioutyp >= 2) {
	goto L10;
    }
    lout = *ktype + ioutyp * 6;
    goto L20;
L10:
    lout = ioutyp + 11;
L20:
    move_(&string[1], ipos, &aout[lout - 1], &c__1, &lenout[lout - 1]);
    *ipos += lenout[lout - 1];
    if (ioutyp >= 2) {
	goto L200;
    }
    move_(&string[1], ipos, &alprn, &c__1, &c__1);
    ++(*ipos);
    if (ioutyp != 0) {
	goto L100;
    }
    node1 = nodplc[*loc + 1];
    alfnum_(&nodplc[tabinf_1.junode + node1 - 1], &string[1], ipos);
    node2 = nodplc[*loc + 2];
    if (node2 == 1) {
	goto L30;
    }
    move_(&string[1], ipos, &acomma, &c__1, &c__1);
    ++(*ipos);
    alfnum_(&nodplc[tabinf_1.junode + node2 - 1], &string[1], ipos);
L30:
    move_(&string[1], ipos, &arprn, &c__1, &c__1);
    ++(*ipos);
    goto L1000;

L100:
    locv = nodplc[*loc];
    anam = blank_1.value[locv - 1];
    achar = ablnk;
    for (i__ = 1; i__ <= 8; ++i__) {
	move_(&achar, &c__1, &anam, &i__, &c__1);
	if (achar == ablnk) {
	    goto L120;
	}
	move_(&string[1], ipos, &achar, &c__1, &c__1);
	++(*ipos);
/* L110: */
    }
L120:
    move_(&string[1], ipos, &arprn, &c__1, &c__1);
    ++(*ipos);
    goto L1000;

L200:
    if (*ktype == 1) {
	goto L1000;
    }
    move_(&string[1], ipos, &alprn, &c__1, &c__1);
    ++(*ipos);
    move_(&string[1], ipos, &aopt[*ktype - 2], &c__1, &lenopt[*ktype - 2]);
    *ipos += lenopt[*ktype - 2];
    move_(&string[1], ipos, &arprn, &c__1, &c__1);
    ++(*ipos);

/*  FINISHED */

L1000:
    return 0;
} /* outnam_ */

#undef cvalue
#undef nodplc
#undef ablnk
#undef arprn
#undef acomma
#undef alprn
#undef aopt
#undef aout


/* Subroutine */ int alfnum_(integer *number, doublereal *string, integer *
	ipos)
{
    /* Initialized data */

    static struct {
	char e_1[80];
	doublereal e_2;
	} equiv_365 = { "0       1       2       3       4       5       6  "
		"     7       8       9       ", 0. };

#define adigit ((doublereal *)&equiv_365)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_366 = { "-       ", 0. };

#define aminus (*(doublereal *)&equiv_366)


    static integer num;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer istop, idigit;
    static doublereal tmpdgt;
    static integer istart, numtmp;


/*     THIS ROUTINE CONVERTS NUMBER INTO CHARACTER FORM, STORING THE */
/* CHARACTERS IN THE CHARACTER ARRAY STRING, BEGINNING WITH THE POSITION */
/* INDICATED BY IPOS. */

/* **** NOTE THAT THE 'IPOS' VARIABLE IS CHANGED TO INDICATE THE POSITION */
/*      OF THE NEXT UNWRITTEN CHARACTER.  THIS COULD CLOBBER CONSTANTS IF */
/*      IPOS IS NOT A VARIABLE IN THE CALLING PROGRAM */

    /* Parameter adjustments */
    --string;

    /* Function Body */


    num = *number;

/*  CHECK FOR NUMBER < 0 */

    if (num >= 0) {
	goto L10;
    }
    num = -num;
/* ...  NEGATIVE NUMBER:  INSERT MINUS SIGN */
    move_(&string[1], ipos, &aminus, &c__1, &c__1);
    ++(*ipos);

/*  CONVERT NUMBER ONE DIGIT AT A TIME, IN REVERSE ORDER */

L10:
    istart = *ipos;
L20:
    numtmp = num / 10;
    idigit = num - numtmp * 10;
    move_(&string[1], ipos, &adigit[idigit], &c__1, &c__1);
    ++(*ipos);
    num = numtmp;
    if (num != 0) {
	goto L20;
    }
    istop = *ipos - 1;

/*  NOW REVERSE THE ORDER OF THE DIGITS */

L30:
    if (istop <= istart) {
	goto L40;
    }
    move_(&tmpdgt, &c__1, &string[1], &istart, &c__1);
    move_(&string[1], &istart, &string[1], &istop, &c__1);
    move_(&string[1], &istop, &tmpdgt, &c__1, &c__1);
    ++istart;
    --istop;
    goto L30;

/*  CONVERSION COMPLETE */

L40:
    return 0;
} /* alfnum_ */

#undef aminus
#undef adigit


/* Subroutine */ int undefi_(doublereal *array, integer *length)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_369 = { ".U      ", 0. };

#define aundef (*(doublereal *)&equiv_369)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/*     THIS ROUTINE UNDEFINES THE MEMORY LOCATIONS INDICATED BY ARRAY(1) */
/* THROUGH ARRAY(LENGTH). */

    /* Parameter adjustments */
    --array;

    /* Function Body */
    if (*length == 0) {
	return 0;
    }
    i__1 = *length;
    for (i__ = 1; i__ <= i__1; ++i__) {
	array[i__] = aundef;
/* L10: */
    }
    return 0;
} /* undefi_ */

#undef aundef


/* Subroutine */ int getcje_(void)
{
    static doublereal xtime;
    extern /* Subroutine */ int second_(doublereal *);

/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
    second_(&xtime);
    cje_1.itime = (integer) xtime;
    return 0;
} /* getcje_ */

/* Subroutine */ int cpytb4_(integer *itabo, integer *itabn)
{
    /* Local variables */
    static integer locn, loco;
    extern /* Subroutine */ int getm4_(integer *, integer *), copy4_(integer *
	    , integer *, integer *);
    static integer isize;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int sizmem_(integer *, integer *);


/*     THIS ROUTINE COPIES A TABLE.  ITS USE IS MADE NECESSARY BY THE */
/* FACT THAT ONLY ONE POINTER IS ALLOWED PER TABLE. */

/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    sizmem_(&nodplc[*itabo - 1], &isize);
    getm4_(&nodplc[*itabn - 1], &isize);
    loco = nodplc[*itabo - 1];
    locn = nodplc[*itabn - 1];
    copy4_(&nodplc[loco], &nodplc[locn], &isize);
    return 0;
} /* cpytb4_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int cpytb8_(integer *itabo, integer *itabn)
{
    /* Local variables */
    static integer locn, loco;
    extern /* Subroutine */ int getm8_(integer *, integer *), copy8_(
	    doublereal *, doublereal *, integer *);
    static integer isize;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int sizmem_(integer *, integer *);


/*     THIS ROUTINE COPIES A TABLE.  ITS USE IS MADE NECESSARY BY THE */
/* FACT THAT ONLY ONE POINTER IS ALLOWED PER TABLE. */

/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    sizmem_(&nodplc[*itabo - 1], &isize);
    getm8_(&nodplc[*itabn - 1], &isize);
    loco = nodplc[*itabo - 1];
    locn = nodplc[*itabn - 1];
    copy8_(&blank_1.value[loco], &blank_1.value[locn], &isize);
    return 0;
} /* cpytb8_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int second_(doublereal *t1)
{
    static integer ibuff[4];
    extern /* Subroutine */ int times_(integer *);

    times_(ibuff);
    *t1 = (doublereal) ibuff[0] / 60.;
    return 0;
} /* second_ */

/* SPICE VERSION 2G.6  SCCSID=readin.ma 3/22/83 */
/* Subroutine */ int readin_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_486 = { "INPUT LISTING                   ", 0. };

#define titinp ((doublereal *)&equiv_486)

    static integer naidc = 22;
    static struct {
	char e_1[176];
	doublereal e_2;
	} equiv_487 = { "AC      DC      DISTORTIEND     ENDS    FOURIER MOD"
		"EL   NOISE   OP      OPTIONS PLOT    PRINT   SUBCKT  SENSITI"
		"VTRANSIENTF      TEMPERATWIDTH   NODESET IC      :DEBUG: ALT"
		"ER   ", 0. };

#define aidc ((doublereal *)&equiv_487)

    static struct {
	char e_1[136];
	doublereal e_2;
	char e_3[8];
	doublereal e_4;
	} equiv_488 = { "R       C       L       K       G       E       F  "
		"     H       V       I       D       Q       J       M      "
		" S       Y       T       ", 0., "X       ", 0. };

#define aide ((doublereal *)&equiv_488)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_489 = { "AC      ", 0. };

#define alsac (*(doublereal *)&equiv_489)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_490 = { "PU      ", 0. };

#define alspu (*(doublereal *)&equiv_490)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_491 = { "EX      ", 0. };

#define alsex (*(doublereal *)&equiv_491)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_492 = { "SI      ", 0. };

#define alssi (*(doublereal *)&equiv_492)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_493 = { "OFF     ", 0. };

#define alsoff (*(doublereal *)&equiv_493)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_494 = { "DC      ", 0. };

#define alsdc (*(doublereal *)&equiv_494)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_495 = { "PW      ", 0. };

#define alspw (*(doublereal *)&equiv_495)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_496 = { "Z0      ", 0. };

#define alsz0 (*(doublereal *)&equiv_496)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_497 = { "ZO      ", 0. };

#define alszo (*(doublereal *)&equiv_497)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_498 = { "NL      ", 0. };

#define alsnl (*(doublereal *)&equiv_498)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_499 = { "F       ", 0. };

#define alsf (*(doublereal *)&equiv_499)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_500 = { "TD      ", 0. };

#define alstd (*(doublereal *)&equiv_500)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_501 = { "L       ", 0. };

#define alsl (*(doublereal *)&equiv_501)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_502 = { "W       ", 0. };

#define alsw (*(doublereal *)&equiv_502)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_503 = { "AS      ", 0. };

#define alsas (*(doublereal *)&equiv_503)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_504 = { "AD      ", 0. };

#define alsad (*(doublereal *)&equiv_504)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_505 = { "PD      ", 0. };

#define alspd (*(doublereal *)&equiv_505)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_506 = { "PS      ", 0. };

#define alsps (*(doublereal *)&equiv_506)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_507 = { "NRD     ", 0. };

#define alsrds (*(doublereal *)&equiv_507)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_508 = { "NRS     ", 0. };

#define alsrss (*(doublereal *)&equiv_508)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_509 = { "XQC     ", 0. };

#define alsxqc (*(doublereal *)&equiv_509)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_510 = { "ZX      ", 0. };

#define alszx (*(doublereal *)&equiv_510)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_511 = { "SF      ", 0. };

#define alssf (*(doublereal *)&equiv_511)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_512 = { "POLY    ", 0. };

#define apoly (*(doublereal *)&equiv_512)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_513 = { "IC      ", 0. };

#define aic (*(doublereal *)&equiv_513)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_514 = { "AREA    ", 0. };

#define area (*(doublereal *)&equiv_514)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_515 = { "TC      ", 0. };

#define alstc (*(doublereal *)&equiv_515)

    static integer numic[4] = { 1,2,2,3 };
    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_516 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_516)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_517 = { ".       ", 0. };

#define aper (*(doublereal *)&equiv_517)

    static integer nnods[20] = { 2,2,2,0,2,2,2,2,2,2,2,3,3,4,4,4,4,0,0,0 };
    static integer ntnods[20] = { 2,2,2,0,2,2,2,2,2,2,3,6,5,6,4,4,4,0,0,0 };
    static integer l2nod[24] = { 8,12,14,6,13,14,13,14,11,6,16,36,25,33,6,6,
	    33,0,3,3,3,3,3,3 };
    static struct {
	char e_1[56];
	doublereal e_2;
	} equiv_518 = { "D       NPN     PNP     NJF     PJF     NMOS    PMO"
		"S    ", 0. };

#define aidm ((doublereal *)&equiv_518)

    static integer ipolar[7] = { 0,1,-1,1,-1,1,-1 };
    static integer modid[7] = { 1,2,2,3,3,4,4 };
    static integer ipar[5] = { 0,14,60,72,114 };
    static struct {
	char e_1[912];
	doublereal e_2;
	} equiv_519 = { "IS      RS      N       TT      CJO     VJ      M  "
		"     EG      XTI     KF      AF      FC      BV      IBV    "
		" IS      BF      NF      VAF     IKF     ISE     NE      BR "
		"     NR      VAR     IKR     ISC     NC      0       0      "
		" RB      IRB     RBM     RE      RC      CJE     VJE     MJE"
		"     TF      XTF     VTF     ITF     PTF     CJC     VJC    "
		" MJC     XCJC    TR      0       0       0       0       CJS"
		"     VJS     MJS     XTB     EG      XTI     KF      AF     "
		" FC      VTO     BETA    LAMBDA  RD      RS      CGS     CGD"
		"     PB      IS      KF      AF      FC      LEVEL   VTO    "
		" KP      GAMMA   PHI     LAMBDA  RD      RS      CBD     CBS"
		"     IS      PB      CGSO    CGDO    CGBO    RSH     CJ     "
		" MJ      CJSW    MJSW    JS      TOX     NSUB    NSS     NFS"
		"     TPG     XJ      LD      UO      UCRIT   UEXP    UTRA   "
		" VMAX    NEFF    XQC     KF      AF      FC      DELTA   THE"
		"TA   ETA     KAPPA   ", 0. };

#define ampar ((doublereal *)&equiv_519)


    /* Format strings */
    static char fmt_6[] = "(\0020WARNING:  INPUT LINE-WIDTH SET TO 72 COLUMN"
	    "S BECAUSE\002,/1x,\002POSSIBLE SEQUENCING APPEARS IN COLS 73-8"
	    "0\002)";
    static char fmt_86[] = "(\0020WARNING:  ABOVE LINE NOT ALLOWED WITHIN SU"
	    "BCIRCUIT -- \002,\002IGNORED\002/)";
    static char fmt_91[] = "(\0020*ERROR*:  UNKNOWN DATA CARD:  \002,a8/)";
    static char fmt_96[] = "(\0020*ERROR*:  UNRECOGNIZABLE DATA CARD\002/)";
    static char fmt_141[] = "(\0020WARNING:  COEFFICIENT OF COUPLING RESET T"
	    "O 1.0D0\002/)";
    static char fmt_379[] = "(\0020*ERROR*:  Z0 MUST BE SPECIFIED\002/)";
    static char fmt_381[] = "(\0020*ERROR*:  EITHER TD OR F MUST BE SPECIF"
	    "IED\002/)";
    static char fmt_391[] = "(\0020*ERROR*:  ELEMENT TYPE NOT YET IMPLEMEN"
	    "TED\002/)";
    static char fmt_401[] = "(\0020*ERROR*:  NEGATIVE NODE NUMBER FOUND\002/)"
	    ;
    static char fmt_411[] = "(\0020*ERROR*:  NODE NUMBERS ARE MISSING\002/)";
    static char fmt_421[] = "(\0020*ERROR*:  VALUE IS MISSING OR IS NONPOSIT"
	    "IVE\002/)";
    static char fmt_431[] = "(\0020*ERROR*:  MUTUAL INDUCTANCE REFERENCES AR"
	    "E MISSING\002/)";
    static char fmt_441[] = "(\0020*ERROR*:  MODEL NAME IS MISSING\002/)";
    static char fmt_451[] = "(\0020*ERROR*:  UNKNOWN SOURCE FUNCTION:  \002,"
	    "a8)";
    static char fmt_461[] = "(\0020*ERROR*:  UNKNOWN PARAMETER:  \002,a8/)";
    static char fmt_471[] = "(\0020*ERROR*:  VOLTAGE SOURCE NOT FOUND ON ABO"
	    "VE LINE\002/)";
    static char fmt_481[] = "(\0020*ERROR*:  VALUE IS ZERO\002/)";
    static char fmt_491[] = "(\0020*ERROR*:  EXTRA NUMERICAL DATA ON MOSFET "
	    "CARD\002/)";
    static char fmt_651[] = "(\0020*ERROR*:  MODEL TYPE IS MISSING\002/)";
    static char fmt_661[] = "(\0020*ERROR*:  UNKNOWN MODEL TYPE:  \002,a8/)";
    static char fmt_671[] = "(\0020*ERROR*:  UNKNOWN MODEL PARAMETER:  \002,"
	    "a8,/)";
    static char fmt_761[] = "(\0020*ERROR*:  SUBCIRCUIT DEFINITION DUPLICATE"
	    "S NODE \002,i5,/)";
    static char fmt_771[] = "(\0020*ERROR*:  NONPOSITIVE NODE NUMBER FOUND I"
	    "N SUBCIRCUIT \002,\002DEFINITION\002/)";
    static char fmt_781[] = "(\0020*ERROR*:  SUBCIRCUIT NAME MISSING\002/)";
    static char fmt_791[] = "(\0020*ERROR*:  SUBCIRCUIT NODES MISSING\002/)";
    static char fmt_881[] = "(\0020*ERROR*:  UNKNOWN SUBCIRCUIT NAME:  \002,"
	    "a8/)";
    static char fmt_891[] = "(\0020WARNING:  NO SUBCIRCUIT DEFINITION KNOWN "
	    "-- LINE IGNORED\002/)";
    static char fmt_991[] = "(\0020*ERROR*:  SUBCIRCUIT NAME MISSING\002/)";
    static char fmt_5001[] = "(\0020*ERROR*:  .ENDS  CARD MISSING\002/)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal t1, t2;
    static integer id;
    static doublereal xk;
    static integer loc;
    static doublereal xnl;
    extern /* Subroutine */ int card_(void);
    static doublereal anam;
    static integer ifld;
    extern /* Subroutine */ int find_(doublereal *, integer *, integer *, 
	    integer *);
    static integer ltab;
    static doublereal aval;
    static integer ndim, nmat;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer locv, iknt, lnod, loct, ibit, locm, ipol, node, irel;
    extern /* Subroutine */ int getm4_(integer *, integer *), getm8_(integer *
	    , integer *), copy8_(doublereal *, doublereal *, integer *), 
	    zero4_(integer *, integer *), zero8_(doublereal *, integer *), 
	    title_(integer *, integer *, integer *, doublereal *);
    static integer istop, ispot, icloc;
    static doublereal tfreq;
    static integer jtype, nopar;
    extern doublereal alias_(doublereal *);
    static doublereal anams;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int second_(doublereal *), getlin_(void), keysrc_(
	    doublereal *, integer *, doublereal *, integer *), runcon_(
	    integer *), extmem_(integer *, integer *), extnam_(doublereal *, 
	    integer *);
    static integer nssnod, maxknt;
    extern /* Subroutine */ int relmem_(integer *, integer *), clrmem_(
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___428 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___431 = { 0, 0, 0, fmt_86, 0 };
    static cilist io___432 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___433 = { 0, 0, 0, fmt_96, 0 };
    static cilist io___442 = { 0, 0, 0, fmt_141, 0 };
    static cilist io___455 = { 0, 0, 0, fmt_379, 0 };
    static cilist io___456 = { 0, 0, 0, fmt_381, 0 };
    static cilist io___457 = { 0, 0, 0, fmt_391, 0 };
    static cilist io___458 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___459 = { 0, 0, 0, fmt_411, 0 };
    static cilist io___460 = { 0, 0, 0, fmt_421, 0 };
    static cilist io___461 = { 0, 0, 0, fmt_431, 0 };
    static cilist io___462 = { 0, 0, 0, fmt_441, 0 };
    static cilist io___463 = { 0, 0, 0, fmt_451, 0 };
    static cilist io___464 = { 0, 0, 0, fmt_461, 0 };
    static cilist io___465 = { 0, 0, 0, fmt_471, 0 };
    static cilist io___466 = { 0, 0, 0, fmt_481, 0 };
    static cilist io___467 = { 0, 0, 0, fmt_491, 0 };
    static cilist io___471 = { 0, 0, 0, fmt_651, 0 };
    static cilist io___472 = { 0, 0, 0, fmt_661, 0 };
    static cilist io___473 = { 0, 0, 0, fmt_671, 0 };
    static cilist io___475 = { 0, 0, 0, fmt_761, 0 };
    static cilist io___476 = { 0, 0, 0, fmt_771, 0 };
    static cilist io___477 = { 0, 0, 0, fmt_781, 0 };
    static cilist io___478 = { 0, 0, 0, fmt_791, 0 };
    static cilist io___481 = { 0, 0, 0, fmt_881, 0 };
    static cilist io___482 = { 0, 0, 0, fmt_891, 0 };
    static cilist io___483 = { 0, 0, 0, fmt_991, 0 };
    static cilist io___484 = { 0, 0, 0, fmt_5001, 0 };




/*     THIS ROUTINE DRIVES THE INPUT PROCESSING OF SPICE.  ELEMENT CARDS */
/* AND DEVICE MODELS ARE HANDLED BY THIS ROUTINE. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  CONTROL CARD IDENTIFIERS */


/*  ELEMENT CARD IDENTIFIERS, KEYWORDS, AND INFORMATION */


/*  MODEL CARD KEYWORDS */


/*  INITIALIZE VARIABLES */

    second_(&t1);
    zero4_(debug_1.idebug, &c__20);
    getlin_();
    if (flags_1.keof != 0) {
	goto L6000;
    }
    copy8_(line_1.afield, miscel_1.atitle, &c__10);
    getm4_(&tabinf_1.ielmnt, &c__0);
    getm8_(&tabinf_1.itemps, &c__1);
    blank_1.value[tabinf_1.itemps] = 27.;
    status_1.itemno = 1;
    miscel_1.nopage = 0;
    title_(&c_n1, &c__72, &c__1, titinp);
    miscel_1.iwidth = 80;
    for (i__ = 1; i__ <= 8; ++i__) {
	line_1.achar = ablnk;
	move_(&line_1.achar, &c__1, &miscel_1.atitle[9], &i__, &c__1);
	if (line_1.achar == ablnk) {
	    goto L8;
	}
/* L5: */
    }
    io___428.ciunit = status_1.iofile;
    s_wsfe(&io___428);
    e_wsfe();
    miscel_1.iwidth = 72;
L8:
    for (i__ = 1; i__ <= 15; ++i__) {
	line_1.afield[i__ - 1] = ablnk;
/* L10: */
    }
    copy8_(line_1.afield, line_1.oldlin, &c__15);
    getm4_(&tabinf_1.isbckt, &c__0);
    tabinf_1.nsbckt = 0;
    getm8_(&tabinf_1.iunsat, &c__0);
    tabinf_1.nunsat = 0;
    cirdat_1.numalt = 0;
    cirdat_1.numcyc = 0;
    miscel_1.lwidth = 132;
    flags_1.iprnta = 0;
    flags_1.iprntl = 0;
    flags_1.iprntm = 1;
    flags_1.iprntn = 0;
    flags_1.iprnto = 0;
    knstnt_1.gmin = 1e-12;
    knstnt_1.pivtol = 1e-13;
    knstnt_1.pivrel = .001;
    knstnt_1.reltol = .001;
    knstnt_1.abstol = 1e-12;
    knstnt_1.vntol = 1e-6;
    knstnt_1.trtol = 7.;
    knstnt_1.chgtol = 1e-14;
    miscel_1.defl = 1e-4;
    miscel_1.defw = 1e-4;
    miscel_1.defad = 0.;
    miscel_1.defas = 0.;
    outinf_1.numdgt = 4;
    tabinf_1.numtem = 1;
    flags_1.itl1 = 100;
    flags_1.itl2 = 50;
    flags_1.itl3 = 4;
    flags_1.itl4 = 10;
    flags_1.itl5 = 5000;
    flags_1.itl6 = 0;
    flags_1.limtim = 2;
    flags_1.limpts = 201;
    flags_1.lvlcod = 1;
    flags_1.lvltim = 2;
    status_1.method = 1;
    status_1.xmu = .5;
    status_1.maxord = 2;
    status_1.nosolv = 0;
    dc_1.icvflg = 0;
    dc_1.itcelm[1] = 0;
    ac_1.idist = 0;
    ac_1.idprt = 0;
    ac_1.inoise = 0;
    ac_1.jacflg = 0;
    tran_1.jtrflg = 0;
    getm4_(&tabinf_1.ifour, &c__0);
    tabinf_1.nfour = 0;
    getm4_(&tabinf_1.nsnod, &c__0);
    getm8_(&tabinf_1.nsval, &c__0);
    getm4_(&tabinf_1.icnod, &c__0);
    getm8_(&tabinf_1.icval, &c__0);
    dc_1.kinel = 0;
    dc_1.kovar = 0;
    dc_1.kssop = 0;
    ac_1.nosprt = 0;
    tabinf_1.nsens = 0;
    getm4_(&tabinf_1.isens, &c__0);
    cirdat_1.numnod = 0;
    cirdat_1.ncnods = 0;
    cirdat_1.nunods = 0;
    zero4_(cirdat_1.locate, &c__50);
    zero4_(cirdat_1.jelcnt, &c__50);
    tabinf_1.insize = 50;
    getm8_(&tabinf_1.ifield, &tabinf_1.insize);
    getm4_(&tabinf_1.icode, &tabinf_1.insize);
    getm8_(&tabinf_1.idelim, &tabinf_1.insize);
    getm4_(&tabinf_1.icolum, &tabinf_1.insize);
    goto L50;

/*  ERROR ENTRY */

L40:
    flags_1.nogo = 1;

/*  READ AND DECODE NEXT CARD IN INPUT DECK */

L50:
    flags_1.igoof = 0;
    card_();
    if (flags_1.keof != 0) {
	goto L5000;
    }
    if (flags_1.igoof != 0) {
	goto L40;
    }
    if (nodplc[tabinf_1.icode] == 0) {
	goto L95;
    }
    anam = blank_1.value[tabinf_1.ifield];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam != aper) {
	goto L70;
    }
    move_(&anam, &c__1, &blank_1.value[tabinf_1.ifield], &c__2, &c__7);
    keysrc_(aidc, &naidc, &anam, &id);
    if (id <= 0) {
	goto L90;
    }
    if (id == 4) {
	goto L5000;
    }
    if (id == 5) {
	goto L800;
    }
    if (id == 7) {
	goto L500;
    }
    if (id == 13) {
	goto L700;
    }
    if (id == 22) {
	++cirdat_1.numalt;
    }
    if (tabinf_1.nsbckt >= 1) {
	goto L85;
    }
    if (id != 22) {
	runcon_(&id);
    }
    if (flags_1.igoof != 0) {
	goto L40;
    }
    goto L50;
L70:
    id = 0;
L80:
    ++id;
    if (id > 20) {
	goto L90;
    }
    if (anam == aide[id - 1]) {
	goto L100;
    }
    goto L80;
L85:
    io___431.ciunit = status_1.iofile;
    s_wsfe(&io___431);
    e_wsfe();
    goto L50;
L90:
    io___432.ciunit = status_1.iofile;
    s_wsfe(&io___432);
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.ifield], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L40;
L95:
    io___433.ciunit = status_1.iofile;
    s_wsfe(&io___433);
    e_wsfe();
    goto L40;

/*  ELEMENT AND DEVICE CARDS */

L100:
    find_(&blank_1.value[tabinf_1.ifield], &id, &loc, &c__1);
    locv = nodplc[loc];
    if (id == 4) {
	goto L140;
    }
    if (id == 19) {
	goto L900;
    }
    istop = nnods[id - 1] + 1;
    if (nodplc[loc + l2nod[id - 1] - 1] != 0) {
	goto L113;
    }
    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (nodplc[tabinf_1.icode + i__ - 1] != 0) {
	    goto L410;
	}
	if (blank_1.value[tabinf_1.ifield + i__ - 1] < 0.) {
	    goto L400;
	}
/* L110: */
	nodplc[loc + i__ - 1] = (integer) blank_1.value[tabinf_1.ifield + i__ 
		- 1];
    }
    goto L115;
L113:
    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	nodplc[loc + i__ - 1] = 0;
/* L114: */
    }
L115:
    switch (id) {
	case 1:  goto L120;
	case 2:  goto L130;
	case 3:  goto L130;
	case 4:  goto L140;
	case 5:  goto L150;
	case 6:  goto L150;
	case 7:  goto L180;
	case 8:  goto L180;
	case 9:  goto L200;
	case 10:  goto L200;
	case 11:  goto L300;
	case 12:  goto L300;
	case 13:  goto L300;
	case 14:  goto L300;
	case 15:  goto L390;
	case 16:  goto L390;
	case 17:  goto L350;
	case 18:  goto L390;
	case 19:  goto L390;
	case 20:  goto L390;
    }

/*  RESISTOR */

L120:
    if (nodplc[tabinf_1.icode + 3] != 0) {
	goto L420;
    }
    if (blank_1.value[tabinf_1.ifield + 3] == 0.) {
	goto L480;
    }
    blank_1.value[locv + 1] = blank_1.value[tabinf_1.ifield + 3];
    ifld = 4;
L122:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L122;
    } else {
	goto L124;
    }
L124:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != alstc) {
	goto L460;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L126;
    } else {
	goto L124;
    }
L126:
    blank_1.value[locv + 2] = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L128;
    } else {
	goto L124;
    }
L128:
    blank_1.value[locv + 3] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L50;

/*  CAPACITOR OR INDUCTOR */

L130:
    iknt = 0;
    ltab = 7;
    if (id == 3) {
	ltab = 10;
    }
    if ((i__1 = nodplc[tabinf_1.icode + 3]) < 0) {
	goto L420;
    } else if (i__1 == 0) {
	goto L131;
    } else {
	goto L132;
    }
L131:
    if (blank_1.value[tabinf_1.ifield + 3] <= 0.) {
	goto L420;
    }
    blank_1.value[locv] = blank_1.value[tabinf_1.ifield + 3];
    nodplc[loc + 3] = 1;
    ifld = 5;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L420;
    } else {
	goto L139;
    }
L132:
    getm8_(&nodplc[loc + ltab - 1], &c__0);
    anam = blank_1.value[tabinf_1.ifield + 3];
    if (anam != apoly) {
	goto L450;
    }
    ifld = 4;
L134:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L136;
    } else {
	goto L138;
    }
L136:
    extmem_(&nodplc[loc + ltab - 1], &c__1);
    ++iknt;
    ispot = nodplc[loc + ltab - 1] + iknt;
    blank_1.value[ispot - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L134;
L138:
    if (iknt == 0) {
	goto L420;
    }
L139:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != aic) {
	goto L460;
    }
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L50;
    }
    blank_1.value[locv + 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L50;

/*  MUTUAL INDUCTANCE */

L140:
    if (nodplc[tabinf_1.icode + 1] != 1) {
	goto L430;
    }
    anam = blank_1.value[tabinf_1.ifield + 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam != aide[2]) {
	goto L430;
    }
    extnam_(&blank_1.value[tabinf_1.ifield + 1], &nodplc[loc + 1]);
    if (nodplc[tabinf_1.icode + 2] != 1) {
	goto L430;
    }
    anam = blank_1.value[tabinf_1.ifield + 2];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam != aide[2]) {
	goto L430;
    }
    extnam_(&blank_1.value[tabinf_1.ifield + 2], &nodplc[loc + 2]);
    if (nodplc[tabinf_1.icode + 3] != 0) {
	goto L420;
    }
    xk = blank_1.value[tabinf_1.ifield + 3];
    if (xk <= 0.) {
	goto L420;
    }
    if (xk <= 1.) {
	goto L145;
    }
    xk = 1.;
    io___442.ciunit = status_1.iofile;
    s_wsfe(&io___442);
    e_wsfe();
L145:
    blank_1.value[locv] = xk;
    goto L50;

/*  VOLTAGE CONTROLLED (NONLINEAR) SOURCES */

L150:
    ndim = 1;
    ifld = 3;
    if ((i__1 = nodplc[tabinf_1.icode + 3]) < 0) {
	goto L410;
    } else if (i__1 == 0) {
	goto L156;
    } else {
	goto L152;
    }
L152:
    anam = blank_1.value[tabinf_1.ifield + 3];
    if (anam != apoly) {
	goto L450;
    }
    if (nodplc[tabinf_1.icode + 4] != 0) {
	goto L420;
    }
    ndim = (integer) blank_1.value[tabinf_1.ifield + 4];
    if (ndim <= 0) {
	goto L420;
    }
    ifld = 5;
L156:
    nodplc[loc + 3] = ndim;
    ltab = id + 1;
    nssnod = ndim << 1;
    nmat = ndim << 2;
    if (id == 6) {
	nmat = (ndim << 1) + 4;
    }
    getm4_(&nodplc[loc + ltab - 1], &nssnod);
    getm4_(&nodplc[loc + ltab], &nmat);
    getm8_(&nodplc[loc + ltab + 1], &c__0);
    getm8_(&nodplc[loc + ltab + 2], &ndim);
    getm4_(&nodplc[loc + ltab + 3], &ndim);
    getm8_(&nodplc[loc + ltab + 4], &ndim);
    ispot = nodplc[loc + ltab + 4];
    zero8_(&blank_1.value[ispot], &ndim);
    lnod = nodplc[loc + ltab - 1];
    i__1 = nssnod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++ifld;
	if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	    goto L410;
	}
	if (blank_1.value[tabinf_1.ifield + ifld - 1] < 0.) {
	    goto L400;
	}
	nodplc[lnod + i__ - 1] = (integer) blank_1.value[tabinf_1.ifield + 
		ifld - 1];
/* L158: */
    }
L160:
    iknt = 0;
L162:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L164;
    }
    extmem_(&nodplc[loc + ltab + 1], &c__1);
    ++iknt;
    ispot = nodplc[loc + ltab + 1] + iknt;
    blank_1.value[ispot - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L162;
L164:
    if (iknt == 0) {
	goto L420;
    }
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L170;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != aic) {
	goto L460;
    }
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++ifld;
	if ((i__2 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	    goto L170;
	} else if (i__2 == 0) {
	    goto L166;
	} else {
	    goto L420;
	}
L166:
	ispot = nodplc[loc + ltab + 4] + i__;
	blank_1.value[ispot - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
/* L168: */
    }
L170:
    if (ndim != 1) {
	goto L50;
    }
    if (iknt != 1) {
	goto L50;
    }
    extmem_(&nodplc[loc + ltab + 1], &c__1);
    ispot = nodplc[loc + ltab + 1];
    blank_1.value[ispot + 1] = blank_1.value[ispot];
    blank_1.value[ispot] = 0.;
    goto L50;

/*  CURRENT CONTROLLED (NONLINEAR) SOURCES */

L180:
    ndim = 1;
    ifld = 3;
    if (nodplc[tabinf_1.icode + 3] != 1) {
	goto L470;
    }
    anam = blank_1.value[tabinf_1.ifield + 3];
    if (anam != apoly) {
	goto L182;
    }
    ifld = 5;
    if (nodplc[tabinf_1.icode + 4] != 0) {
	goto L420;
    }
    ndim = (integer) blank_1.value[tabinf_1.ifield + 4];
    if (ndim <= 0) {
	goto L420;
    }
L182:
    nodplc[loc + 3] = ndim;
    ltab = id - 1;
    nmat = ndim << 1;
    if (id == 8) {
	nmat = ndim + 4;
    }
    getm4_(&nodplc[loc + ltab - 1], &ndim);
    getm4_(&nodplc[loc + ltab], &nmat);
    getm8_(&nodplc[loc + ltab + 1], &c__0);
    getm8_(&nodplc[loc + ltab + 2], &ndim);
    getm4_(&nodplc[loc + ltab + 3], &ndim);
    getm8_(&nodplc[loc + ltab + 4], &ndim);
    ispot = nodplc[loc + ltab + 4];
    zero8_(&blank_1.value[ispot], &ndim);
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++ifld;
	if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	    goto L470;
	}
	anam = blank_1.value[tabinf_1.ifield + ifld - 1];
	move_(&anam, &c__2, &ablnk, &c__1, &c__7);
	if (anam != aide[8]) {
	    goto L470;
	}
	extnam_(&blank_1.value[tabinf_1.ifield + ifld - 1], &loct);
	ispot = nodplc[loc + ltab - 1] + i__;
	nodplc[ispot - 1] = loct;
/* L184: */
    }
    goto L160;

/*  INDEPENDENT SOURCES */

L200:
    ifld = 3;
    getm8_(&nodplc[loc + 4], &c__0);
L210:
    ++ifld;
L215:
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L220;
    } else {
	goto L230;
    }
L220:
    if (ifld > 4) {
	goto L210;
    }
L225:
    blank_1.value[locv] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L210;
L230:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != alsdc) {
	goto L235;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L225;
    } else {
	goto L230;
    }
L235:
    if (anam != alsac) {
	goto L260;
    }
    blank_1.value[locv + 1] = 1.;
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L240;
    } else {
	goto L230;
    }
L240:
    blank_1.value[locv + 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L250;
    } else {
	goto L230;
    }
L250:
    blank_1.value[locv + 2] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L210;
L260:
    id = 0;
    move_(&anam, &c__3, &ablnk, &c__1, &c__6);
    if (anam == alspu) {
	id = 1;
    }
    if (anam == alssi) {
	id = 2;
    }
    if (anam == alsex) {
	id = 3;
    }
    if (anam == alspw) {
	id = 4;
    }
    if (anam == alssf) {
	id = 5;
    }
    if (id == 0) {
	goto L450;
    }
    nodplc[loc + 3] = id;
    iknt = 0;
L270:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L280;
    }
    extmem_(&nodplc[loc + 4], &c__1);
    ++iknt;
    ispot = nodplc[loc + 4] + iknt;
    blank_1.value[ispot - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L270;
L280:
    aval = 0.;
    if (id != 4) {
	goto L285;
    }
/* ...  FOR PWL SOURCE FUNCTION, FORCE EVEN NUMBER OF INPUT VALUES */
    ibit = 0;
    if (iknt != iknt / 2 << 1) {
	ibit = 1;
    }
    aval = blank_1.value[ispot - 1];
    if (ibit == 0) {
	goto L290;
    }
    extmem_(&nodplc[loc + 4], &c__1);
    aval = blank_1.value[ispot - 2];
    ++iknt;
    ispot = nodplc[loc + 4] + iknt;
    blank_1.value[ispot - 1] = aval;
    goto L290;
L285:
    if (iknt >= 7) {
	goto L215;
    }
L290:
    extmem_(&nodplc[loc + 4], &c__2);
    ispot = nodplc[loc + 4] + iknt;
    blank_1.value[ispot] = 0.;
    blank_1.value[ispot + 1] = aval;
    iknt += 2;
    goto L285;

/*  DEVICE CARDS */

L300:
    blank_1.value[locv] = 1.;
    if (id != 14) {
	goto L305;
    }
    blank_1.value[locv] = 0.;
    blank_1.value[locv + 10] = 0.;
    blank_1.value[locv + 11] = 0.;
    blank_1.value[locv + 12] = 1.;
    blank_1.value[locv + 13] = 1.;
    blank_1.value[locv + 14] = 0.;
L305:
    locm = loc + ntnods[id - 1] + 2;
    ifld = nnods[id - 1] + 2;

/*  TEMPORARILY (UNTIL MODCHK) PUT BJT'S SUBSTRATE NODE INTO NODPLC(LOC+5) */

    if (id != 12) {
	goto L308;
    }
    if (nodplc[tabinf_1.icode + 4] != 0) {
	goto L308;
    }
    ifld = 6;
    if (nodplc[loc + l2nod[id - 1] - 1] != 0) {
	goto L306;
    }
    nodplc[loc + 4] = (integer) blank_1.value[tabinf_1.ifield + 4];
    goto L308;
L306:
    nodplc[loc + 4] = 0;
L308:

/*    RESERVE DEVICE INTERNAL NODES,READ DEVICE GEOMETRY PARAMETERS */
/*    AND INITIAL CONDITIONS */

    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L440;
    }
    extnam_(&blank_1.value[tabinf_1.ifield + ifld - 1], &nodplc[locm - 1]);
L310:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L325;
    } else {
	goto L315;
    }
L315:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != alsoff) {
	goto L320;
    }
    nodplc[locm] = 1;
    goto L310;
L320:
    if (anam != area) {
	goto L330;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L325;
    } else {
	goto L315;
    }
L325:
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    if (id == 14) {
	goto L343;
    }
    blank_1.value[locv] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L310;
L330:
    if (anam != aic) {
	goto L341;
    }
    iknt = 0;
    icloc = 0;
    if (id == 14) {
	icloc = 3;
    }
    maxknt = numic[id - 11];
L335:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L340;
    } else {
	goto L315;
    }
L340:
    ++iknt;
    if (iknt > maxknt) {
	goto L335;
    }
    blank_1.value[locv + icloc + iknt] = blank_1.value[tabinf_1.ifield + ifld 
	    - 1];
    goto L335;
L341:
    if (id != 14) {
	goto L460;
    }
    ispot = 0;
    if (anam == alsl) {
	ispot = 1;
    }
    if (anam == alsw) {
	ispot = 2;
    }
    if (anam == alsad) {
	ispot = 3;
    }
    if (anam == alszx) {
	ispot = 3;
    }
    if (anam == alsas) {
	ispot = 4;
    }
    if (anam == alspd) {
	ispot = 11;
    }
    if (anam == alsps) {
	ispot = 12;
    }
    if (anam == alsrds) {
	ispot = 13;
    }
    if (anam == alsrss) {
	ispot = 14;
    }
    if (anam == alsxqc) {
	ispot = 15;
    }
    if (ispot == 0) {
	goto L460;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L342;
    } else {
	goto L315;
    }
L342:
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    blank_1.value[locv + ispot - 1] = blank_1.value[tabinf_1.ifield + ifld - 
	    1];
    goto L310;
L343:
    iknt = 0;
L344:
    ++iknt;
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    if (iknt > 15) {
	goto L490;
    }
    if (iknt == 5) {
	iknt = 11;
    }
    blank_1.value[locv + iknt - 1] = blank_1.value[tabinf_1.ifield + ifld - 1]
	    ;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L345;
    } else {
	goto L344;
    }
L345:
    if (nodplc[tabinf_1.icode + ifld - 1] <= 0) {
	goto L50;
    } else {
	goto L315;
    }

/*  TRANSMISSION LINES */

L350:
    ifld = 5;
    xnl = .25;
    tfreq = 0.;
L355:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L378;
    } else if (i__1 == 0) {
	goto L355;
    } else {
	goto L360;
    }
L360:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam == aic) {
	goto L364;
    }
    if (anam == alsnl) {
	goto L370;
    }
    if (anam == alsf) {
	goto L374;
    }
    id = 0;
    if (anam == alsz0) {
	id = 1;
    }
    if (anam == alszo) {
	id = 1;
    }
    if (anam == alstd) {
	id = 2;
    }
    if (id == 0) {
	goto L460;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L378;
    } else if (i__1 == 0) {
	goto L362;
    } else {
	goto L360;
    }
L362:
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    blank_1.value[locv + id - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L355;
L364:
    iknt = 0;
L366:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L378;
    } else if (i__1 == 0) {
	goto L368;
    } else {
	goto L360;
    }
L368:
    ++iknt;
    if (iknt > 4) {
	goto L366;
    }
    blank_1.value[locv + iknt + 3] = blank_1.value[tabinf_1.ifield + ifld - 1]
	    ;
    goto L366;
L370:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L378;
    } else if (i__1 == 0) {
	goto L372;
    } else {
	goto L360;
    }
L372:
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    xnl = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L355;
L374:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L378;
    } else if (i__1 == 0) {
	goto L376;
    } else {
	goto L360;
    }
L376:
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L420;
    }
    tfreq = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L355;
L378:
    if (blank_1.value[locv] != 0.) {
	goto L380;
    }
    io___455.ciunit = status_1.iofile;
    s_wsfe(&io___455);
    e_wsfe();
    goto L40;
L380:
    if (blank_1.value[locv + 1] != 0.) {
	goto L50;
    }
    if (tfreq != 0.) {
	goto L382;
    }
    io___456.ciunit = status_1.iofile;
    s_wsfe(&io___456);
    e_wsfe();
    goto L40;
L382:
    blank_1.value[locv + 1] = xnl / tfreq;
    goto L50;

/*  ELEMENTS NOT YET IMPLEMENTED */

L390:
    io___457.ciunit = status_1.iofile;
    s_wsfe(&io___457);
    e_wsfe();
    goto L40;

/*  ELEMENT CARD ERRORS */

L400:
    io___458.ciunit = status_1.iofile;
    s_wsfe(&io___458);
    e_wsfe();
    goto L40;
L410:
    io___459.ciunit = status_1.iofile;
    s_wsfe(&io___459);
    e_wsfe();
    goto L40;
L420:
    io___460.ciunit = status_1.iofile;
    s_wsfe(&io___460);
    e_wsfe();
    goto L40;
L430:
    io___461.ciunit = status_1.iofile;
    s_wsfe(&io___461);
    e_wsfe();
    goto L40;
L440:
    io___462.ciunit = status_1.iofile;
    s_wsfe(&io___462);
    e_wsfe();
    goto L40;
L450:
    io___463.ciunit = status_1.iofile;
    s_wsfe(&io___463);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L40;
L460:
    io___464.ciunit = status_1.iofile;
    s_wsfe(&io___464);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L40;
L470:
    io___465.ciunit = status_1.iofile;
    s_wsfe(&io___465);
    e_wsfe();
    goto L40;
L480:
    io___466.ciunit = status_1.iofile;
    s_wsfe(&io___466);
    e_wsfe();
    goto L40;
L490:
    io___467.ciunit = status_1.iofile;
    s_wsfe(&io___467);
    e_wsfe();
    goto L40;

/*  MODEL CARD */

L500:
    if (nodplc[tabinf_1.icode + 1] != 1) {
	goto L650;
    }
    if (nodplc[tabinf_1.icode + 2] != 1) {
	goto L650;
    }
    id = 0;
L510:
    ++id;
    if (id > 7) {
	goto L660;
    }
    if (blank_1.value[tabinf_1.ifield + 2] != aidm[id - 1]) {
	goto L510;
    }
    ipol = ipolar[id - 1];
    jtype = modid[id - 1];
    id = jtype + 20;
    find_(&blank_1.value[tabinf_1.ifield + 1], &id, &loc, &c__1);
    nodplc[loc + 1] = ipol;
    locv = nodplc[loc];
/* L520: */
    locm = ipar[jtype - 1];
    nopar = ipar[jtype] - locm;
    ifld = 3;
L530:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L530;
    } else {
	goto L560;
    }
L560:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (jtype == 2) {
	anam = alias_(&anam);
    }
    iknt = 0;
L570:
    ++iknt;
    if (iknt > nopar) {
	goto L670;
    }
    if (anam != ampar[locm + iknt - 1]) {
	goto L570;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L580;
    } else {
	goto L560;
    }
L580:
    blank_1.value[locv + iknt - 1] = blank_1.value[tabinf_1.ifield + ifld - 1]
	    ;
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L590;
    } else {
	goto L560;
    }
L590:
    ++iknt;
    if (iknt > nopar) {
	goto L530;
    }
    if (ablnk != ampar[locm + iknt - 1]) {
	goto L530;
    }
    goto L580;

/*  MODEL CARD ERRORS */

L650:
    io___471.ciunit = status_1.iofile;
    s_wsfe(&io___471);
    e_wsfe();
    goto L40;
L660:
    io___472.ciunit = status_1.iofile;
    s_wsfe(&io___472);
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.ifield + 2], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L40;
L670:
    io___473.ciunit = status_1.iofile;
    s_wsfe(&io___473);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.nogo = 1;
    goto L530;

/*  SUBCIRCUIT DEFINITION */

L700:
    if (nodplc[tabinf_1.icode + 1] != 1) {
	goto L780;
    }
    find_(&blank_1.value[tabinf_1.ifield + 1], &c__20, &loc, &c__1);
    extmem_(&tabinf_1.isbckt, &c__1);
    ++tabinf_1.nsbckt;
    nodplc[tabinf_1.isbckt + tabinf_1.nsbckt - 1] = loc;
    ifld = 2;
    if (nodplc[tabinf_1.icode + 2] != 0) {
	goto L790;
    }
    getm4_(&nodplc[loc + 1], &c__0);
    iknt = 0;
L710:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L720;
    } else {
	goto L710;
    }
L720:
    extmem_(&nodplc[loc + 1], &c__1);
    ++iknt;
    ispot = nodplc[loc + 1] + iknt;
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L770;
    }
    nodplc[ispot - 1] = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    node = nodplc[ispot - 1];
    i__ = iknt - 1;
L730:
    if (i__ == 0) {
	goto L710;
    }
    --ispot;
    if (nodplc[ispot - 1] == node) {
	goto L760;
    }
    --i__;
    goto L730;
L760:
    io___475.ciunit = status_1.iofile;
    s_wsfe(&io___475);
    do_fio(&c__1, (char *)&node, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L40;
L770:
    io___476.ciunit = status_1.iofile;
    s_wsfe(&io___476);
    e_wsfe();
    goto L40;
L780:
    io___477.ciunit = status_1.iofile;
    s_wsfe(&io___477);
    e_wsfe();
    goto L40;
L790:
    io___478.ciunit = status_1.iofile;
    s_wsfe(&io___478);
    e_wsfe();
    goto L40;

/*  .ENDS PROCESSING */

L800:
    if (tabinf_1.nsbckt == 0) {
	goto L890;
    }
    iknt = 1;
    if (nodplc[tabinf_1.icode + 1] <= 0) {
	goto L820;
    }
    anam = blank_1.value[tabinf_1.ifield + 1];
    iknt = tabinf_1.nsbckt;
L810:
    loc = nodplc[tabinf_1.isbckt + iknt - 1];
    locv = nodplc[loc];
    anams = blank_1.value[locv - 1];
    if (anam == anams) {
	goto L820;
    }
    --iknt;
    if (iknt != 0) {
	goto L810;
    }
    goto L880;
L820:
    irel = tabinf_1.nsbckt - iknt + 1;
    relmem_(&tabinf_1.isbckt, &irel);
    tabinf_1.nsbckt -= irel;
    goto L50;
L880:
    io___481.ciunit = status_1.iofile;
    s_wsfe(&io___481);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L40;
L890:
    io___482.ciunit = status_1.iofile;
    s_wsfe(&io___482);
    e_wsfe();
    goto L50;

/*  SUBCIRCUIT CALL */

L900:
    getm4_(&nodplc[loc + 1], &c__0);
    ifld = 1;
    iknt = 0;
L910:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L920;
    }
    extmem_(&nodplc[loc + 1], &c__1);
    ++iknt;
    ispot = nodplc[loc + 1] + iknt;
    if (blank_1.value[tabinf_1.ifield + ifld - 1] < 0.) {
	goto L400;
    }
    nodplc[ispot - 1] = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L910;
L920:
    if (iknt == 0) {
	goto L410;
    }
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L990;
    }
    extnam_(&blank_1.value[tabinf_1.ifield + ifld - 1], &nodplc[loc + 2]);
    goto L50;
L990:
    io___483.ciunit = status_1.iofile;
    s_wsfe(&io___483);
    e_wsfe();
    goto L40;

/*  END */

L5000:
    if (tabinf_1.nsbckt == 0) {
	goto L5010;
    }
    tabinf_1.nsbckt = 0;
    io___484.ciunit = status_1.iofile;
    s_wsfe(&io___484);
    e_wsfe();
    flags_1.nogo = 1;
L5010:
    clrmem_(&tabinf_1.ifield);
    clrmem_(&tabinf_1.icode);
    clrmem_(&tabinf_1.idelim);
    clrmem_(&tabinf_1.icolum);
    clrmem_(&tabinf_1.isbckt);
    if (tabinf_1.nfour == 0) {
	clrmem_(&tabinf_1.ifour);
    }
    if (tabinf_1.nsens == 0) {
	clrmem_(&tabinf_1.isens);
    }
L6000:
    second_(&t2);
    miscel_1.rstats[0] = t2 - t1;
    return 0;
} /* readin_ */

#undef cvalue
#undef nodplc
#undef ampar
#undef aidm
#undef aper
#undef ablnk
#undef alstc
#undef area
#undef aic
#undef apoly
#undef alssf
#undef alszx
#undef alsxqc
#undef alsrss
#undef alsrds
#undef alsps
#undef alspd
#undef alsad
#undef alsas
#undef alsw
#undef alsl
#undef alstd
#undef alsf
#undef alsnl
#undef alszo
#undef alsz0
#undef alspw
#undef alsdc
#undef alsoff
#undef alssi
#undef alsex
#undef alspu
#undef alsac
#undef aide
#undef aidc
#undef titinp


doublereal alias_(doublereal *anam)
{
    /* Initialized data */

    static struct {
	char e_1[112];
	doublereal e_2;
	} equiv_523 = { "VA      VB      CCS     NS      C2      PT      C4 "
		"     PE      ME      PC      MC      PS      MS      IK      "
		, 0. };

#define anam1 ((doublereal *)&equiv_523)

    static struct {
	char e_1[112];
	doublereal e_2;
	} equiv_524 = { "VAF     VAR     CJS     NSS     ISE     XTI     ISC"
		"     VJE     MJE     VJC     MJC     VJS     MJS     IKF     "
		, 0. };

#define anam2 ((doublereal *)&equiv_524)


    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static integer iknt;


/*  THIS FUNCTION RETURNS THE MGP EQUIVALENT OF THE GP PARAMETERS */
/*  (THOSE WHICH APPLY) */

    iknt = 0;
    ret_val = *anam;
L10:
    ++iknt;
    if (iknt > 14) {
	return ret_val;
    }
    if (anam1[iknt - 1] != *anam) {
	goto L10;
    }
    ret_val = anam2[iknt - 1];
    return ret_val;
} /* alias_ */

#undef anam2
#undef anam1


/* Subroutine */ int keysrc_(doublereal *keytab, integer *lentab, doublereal *
	tstwrd, integer *index)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_531 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_531)


    static integer i__;
    static doublereal akey;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    extern integer xxor_(doublereal *, doublereal *);
    static doublereal achar;
    static integer lenwrd;
    static doublereal tstchr;


/*     THIS ROUTINE SEARCHES THE KEYWORD TABLE 'KEYTAB' FOR THE POSSIBLE */
/* ENTRY 'TSTWRD'.  ABBREVIATIONS ARE CONSIDERED AS MATCHES. */

    /* Parameter adjustments */
    --keytab;

    /* Function Body */


    *index = 0;
    lenwrd = 0;
    achar = ablnk;
    for (i__ = 1; i__ <= 8; ++i__) {
	move_(&achar, &c__8, tstwrd, &i__, &c__1);
	if (achar == ablnk) {
	    goto L20;
	}
	++lenwrd;
/* L10: */
    }

L20:
    if (lenwrd == 0) {
	goto L40;
    }
    tstchr = ablnk;
    move_(&tstchr, &c__8, tstwrd, &c__1, &c__1);
L30:
    ++(*index);
    if (*index > *lentab) {
	goto L40;
    }
    akey = ablnk;
    move_(&akey, &c__1, &keytab[*index], &c__1, &lenwrd);
    if (xxor_(&akey, tstwrd) == 0) {
	goto L50;
    }
    goto L30;

L40:
    *index = -1;
L50:
    return 0;
} /* keysrc_ */

#undef ablnk


/* Subroutine */ int extnam_(doublereal *aname, integer *index)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal anam;
    extern integer xxor_(doublereal *, doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int extmem_(integer *, integer *);


/*     THIS ROUTINE ADDS 'ANAME' TO THE LIST OF 'UNSATISFIED' NAMES (THAT */
/* IS, NAMES WHICH CAN ONLY BE RESOLVED AFTER SUBCIRCUIT EXPANSION). */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    anam = *aname;
    if (tabinf_1.nunsat == 0) {
	goto L20;
    }
    i__1 = tabinf_1.nunsat;
    for (*index = 1; *index <= i__1; ++(*index)) {
	if (xxor_(&anam, &blank_1.value[tabinf_1.iunsat + *index - 1]) == 0) {
	    goto L30;
	}
/* L10: */
    }

L20:
    extmem_(&tabinf_1.iunsat, &c__1);
    ++tabinf_1.nunsat;
    *index = tabinf_1.nunsat;
    blank_1.value[tabinf_1.iunsat + *index - 1] = anam;
L30:
    return 0;
} /* extnam_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int runcon_(integer *id)
{
    /* Initialized data */

    static struct {
	char e_1[40];
	doublereal e_2;
	} equiv_610 = { "DC      TR      AC      NO      DI      ", 0. };

#define aopt ((doublereal *)&equiv_610)

    static struct {
	char e_1[272];
	doublereal e_2;
	} equiv_611 = { "ACCT    LIST    NOMOD   NODE    OPTS    ITL1    ITL"
		"2    ITL3    ITL4    ITL5    ITL6    LIMTIM  LIMPTS  LVLCOD "
		" LVLTIM  GMIN    RELTOL  ABSTOL  VNTOL   TRTOL   CHGTOL  TNO"
		"M    NUMDGT  MAXORD  METHOD  NOPAGE  MU      CPTIME  DEFL   "
		" DEFW    DEFAD   DEFAS   PIVTOL  PIVREL  ", 0. };

#define aopts ((doublereal *)&equiv_611)

    static integer lsetop[5] = { 1,1,0,1,1 };
    static struct {
	char e_1[152];
	doublereal e_2;
	} equiv_612 = { "R       C       L       K       G       E       F  "
		"     H       V       I       D       Q       J       M      "
		" S       Y       T       TEMP    X       ", 0. };

#define aide ((doublereal *)&equiv_612)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_613 = { "DEC     ", 0. };

#define alsde (*(doublereal *)&equiv_613)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_614 = { "OCT     ", 0. };

#define alsoc (*(doublereal *)&equiv_614)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_615 = { "LIN     ", 0. };

#define alsli (*(doublereal *)&equiv_615)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_616 = { "TRAP    ", 0. };

#define atrap (*(doublereal *)&equiv_616)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_617 = { "GEAR    ", 0. };

#define agear (*(doublereal *)&equiv_617)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_618 = { "UIC     ", 0. };

#define auic (*(doublereal *)&equiv_618)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_619 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_619)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_620 = { "IN      ", 0. };

#define ain (*(doublereal *)&equiv_620)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_621 = { "OUT     ", 0. };

#define aout (*(doublereal *)&equiv_621)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_622 = { "*MISSING", 0. };

#define amiss (*(doublereal *)&equiv_622)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_623 = { "MS      ", 0. };

#define ams (*(doublereal *)&equiv_623)

    static integer minpts = 1;

    /* Format strings */
    static char fmt_1131[] = "(\0020WARNING:  MISSING PARAMETER(S) ... ANALY"
	    "SIS OMITTED\002/)";
    static char fmt_1241[] = "(\0020WARNING:  UNKNOWN FREQUENCY FUNCTION: "
	    " \002,a8,\002 ... ANALYS\002,\002IS OMITTED\002/)";
    static char fmt_1251[] = "(\0020WARNING:  FREQUENCY PARAMETERS INCORRECT"
	    " ... ANALYSIS OM\002,\002ITTED\002/)";
    static char fmt_1261[] = "(\0020WARNING:  START FREQ > STOP FREQ ... ANA"
	    "LYSIS OMITTED\002/)";
    static char fmt_1431[] = "(\0020WARNING:  TIME PARAMETERS INCORRECT ... "
	    "ANALYSIS OMITTED\002/)";
    static char fmt_1441[] = "(\0020WARNING:  START TIME > STOP TIME ... ANA"
	    "LYSIS OMITTED\002/)";
    static char fmt_1541[] = "(\0020WARNING:  ILLEGAL OUTPUT VARIABLE ... AN"
	    "ALYSIS OMITTED\002/)";
    static char fmt_1611[] = "(\0020WARNING:  VOLTAGE OUTPUT UNRECOGNIZABLE "
	    "... ANALYSIS OMITTED\002/)";
    static char fmt_1621[] = "(\0020WARNING:  INVALID INPUT SOURCE ... ANALY"
	    "SIS OMITTED\002/)";
    static char fmt_1661[] = "(\0020WARNING:  DISTORTION LOAD RESISTOR MISSI"
	    "NG ... ANALYSIS \002,\002OMITTED\002/)";
    static char fmt_1671[] = "(\0020WARNING:  DISTORTION PARAMETERS INCORREC"
	    "T ... ANALYSIS O\002,\002MITTED\002/)";
    static char fmt_1721[] = "(\0020WARNING:  FOURIER PARAMETERS INCORRECT ."
	    ".. ANALYSIS OMIT\002,\002TED\002/)";
    static char fmt_1781[] = "(\0020WARNING:  OUTPUT VARIABLE UNRECOGNIZABLE"
	    " ... ANALYSIS OM\002,\002MITTED\002/)";
    static char fmt_2081[] = "(\0020WARNING:  NUMDGT MAY NOT EXCEED\002,i2"
	    ",\002;  MAXIMUM VALUE ASSUMED\002/)";
    static char fmt_2501[] = "(\0020WARNING:  UNKNOWN OPTION:  \002,a8,\002 "
	    "... IGNORED\002/)";
    static char fmt_2511[] = "(\0020WARNING:  ILLEGAL VALUE SPECIFIED FOR OP"
	    "TION:  \002,a8,\002 ... IGNORED\002/)";
    static char fmt_3951[] = "(\0020WARNING:  UNKNOWN ANALYSIS MODE:  \002,a"
	    "8,\002 ... LINE IGNORED\002/)";
    static char fmt_3971[] = "(\0020WARNING:  UNRECOGNIZABLE OUTPUT VARIABLE"
	    " ON ABOVE LINE\002/)";
    static char fmt_4171[] = "(\0020WARNING: OUT-OF-PLACE NON-NUMERIC FIELD"
	    " \002,a8,\002 SKIPPED\002/)";
    static char fmt_4181[] = "(\0020WARNING: INITIAL VALUE MISSING FOR NODE"
	    " \002,i5,/)";
    static char fmt_4191[] = "(\0020WARNING: ATTEMPT TO SPECIFY INITIAL COND"
	    "ITION FOR \002,\002GROUND INGNORED\002,/)";
    static char fmt_4271[] = "(\0020WARNING: OUT-OF-PLACE NON-NUMERIC FIELD"
	    " \002,a8,\002 SKIPPED\002/)";
    static char fmt_4281[] = "(\0020WARNING: INITIAL VALUE MISSING FOR NODE"
	    " \002,i5,/)";
    static char fmt_4291[] = "(\0020WARNING: ATTEMPT TO SPECIFY INITIAL COND"
	    "ITION FOR \002,\002GROUND IGNORED\002,/)";
    static char fmt_5931[] = "(\002 *DEBUG*:  RUNCON - IDEBUG(\002,i2,\002) "
	    "SET TO \002,i10)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    double exp(doublereal), log(doublereal);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, n, ms, nic, loc;
    static doublereal anam;
    static integer ifld;
    extern /* Subroutine */ int find_(doublereal *, integer *, integer *, 
	    integer *);
    static doublereal aval;
    static integer ival, inum;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer locs;
    static doublereal temp;
    static integer loct, locv;
    extern integer xxor_(doublereal *, doublereal *);
    extern /* Subroutine */ int getm4_(integer *, integer *);
#define dflts ((doublereal *)&miscel_1 + 15)
#define iprnt ((integer *)&flags_1)
    static integer itemp, ktype, ntype, ltype, jtype, iprpl, lspot, index;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
#define limits ((integer *)&flags_1 + 5)
#define itrlim ((integer *)&flags_1 + 9)
#define contol ((doublereal *)&knstnt_1 + 8)
    extern /* Subroutine */ int extmem_(integer *, integer *), outdef_(
	    integer *, integer *, integer *, integer *), clrmem_(integer *);
    static integer ndigit;
    static doublereal plimlo, plimhi;
    static integer nodnum;
    extern /* Subroutine */ int sizmem_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___564 = { 0, 0, 0, fmt_1131, 0 };
    static cilist io___565 = { 0, 0, 0, fmt_1241, 0 };
    static cilist io___566 = { 0, 0, 0, fmt_1251, 0 };
    static cilist io___567 = { 0, 0, 0, fmt_1261, 0 };
    static cilist io___568 = { 0, 0, 0, fmt_1431, 0 };
    static cilist io___569 = { 0, 0, 0, fmt_1441, 0 };
    static cilist io___571 = { 0, 0, 0, fmt_1131, 0 };
    static cilist io___572 = { 0, 0, 0, fmt_1541, 0 };
    static cilist io___574 = { 0, 0, 0, fmt_1611, 0 };
    static cilist io___575 = { 0, 0, 0, fmt_1621, 0 };
    static cilist io___576 = { 0, 0, 0, fmt_1661, 0 };
    static cilist io___577 = { 0, 0, 0, fmt_1671, 0 };
    static cilist io___580 = { 0, 0, 0, fmt_1721, 0 };
    static cilist io___581 = { 0, 0, 0, fmt_1781, 0 };
    static cilist io___585 = { 0, 0, 0, fmt_2081, 0 };
    static cilist io___588 = { 0, 0, 0, fmt_2501, 0 };
    static cilist io___589 = { 0, 0, 0, fmt_2511, 0 };
    static cilist io___597 = { 0, 0, 0, fmt_3951, 0 };
    static cilist io___598 = { 0, 0, 0, fmt_3971, 0 };
    static cilist io___601 = { 0, 0, 0, fmt_4171, 0 };
    static cilist io___602 = { 0, 0, 0, fmt_4181, 0 };
    static cilist io___603 = { 0, 0, 0, fmt_4191, 0 };
    static cilist io___604 = { 0, 0, 0, fmt_4271, 0 };
    static cilist io___605 = { 0, 0, 0, fmt_4281, 0 };
    static cilist io___606 = { 0, 0, 0, fmt_4291, 0 };
    static cilist io___609 = { 0, 0, 0, fmt_5931, 0 };



/*     THIS ROUTINE PROCESSES RUN CONTROL CARDS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



/*  PRINT/PLOT KEYWORDS */


/*  OPTIONS CARD KEYWORDS */





    switch (*id) {
	case 1:  goto L1200;
	case 2:  goto L1100;
	case 3:  goto L1650;
	case 4:  goto L6000;
	case 5:  goto L6000;
	case 6:  goto L1700;
	case 7:  goto L6000;
	case 8:  goto L1600;
	case 9:  goto L1550;
	case 10:  goto L2000;
	case 11:  goto L3600;
	case 12:  goto L3500;
	case 13:  goto L6000;
	case 14:  goto L1750;
	case 15:  goto L1300;
	case 16:  goto L1500;
	case 17:  goto L1800;
	case 18:  goto L4000;
	case 19:  goto L4100;
	case 20:  goto L4200;
	case 21:  goto L5900;
    }

/*  DC TRANSFER CURVES */

L1100:
    ifld = 2;
    dc_1.icvflg = 0;
    inum = 1;
L1105:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (inum > 2) {
	goto L6000;
    }
    *id = 0;
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam == aide[0]) {
	*id = 1;
    }
    if (anam == aide[8]) {
	*id = 9;
    }
    if (anam == aide[9]) {
	*id = 10;
    }
    if (anam == aide[16]) {
	goto L1108;
    }
    if (*id == 0) {
	goto L1130;
    }
    find_(&blank_1.value[tabinf_1.ifield + ifld - 1], id, &dc_1.itcelm[inum - 
	    1], &c__0);
    goto L1115;
L1108:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    move_(&anam, &c__5, &ablnk, &c__1, &c__4);
    if (anam != aide[17]) {
	goto L1130;
    }
    *id = 18;
    find_(&anam, id, &dc_1.itcelm[inum - 1], &c__1);
    locs = nodplc[dc_1.itcelm[inum - 1]];
    nodplc[dc_1.itcelm[inum - 1] + 1] = 0;
    blank_1.value[locs - 1] = anam;
    blank_1.value[locs] = blank_1.value[tabinf_1.itemps];
    extmem_(&tabinf_1.itemps, &c__2);
    blank_1.value[tabinf_1.itemps + 1] = blank_1.value[tabinf_1.itemps];
L1115:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1130;
    }
    dc_1.tcstar[inum - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1130;
    }
    dc_1.tcstop[inum - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1130;
    }
    dc_1.tcincr[inum - 1] = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (dc_1.tcincr[inum - 1] == 0.) {
	goto L1130;
    }
    temp = (dc_1.tcstop[inum - 1] - dc_1.tcstar[inum - 1]) / dc_1.tcincr[inum 
	    - 1];
    if (temp > 0.) {
	goto L1110;
    }
    dc_1.tcincr[inum - 1] = -dc_1.tcincr[inum - 1];
    temp = -temp;
L1110:
    itemp = (integer) (temp + .5) + 1;
    itemp = max(itemp,minpts);
    if (inum == 1) {
	dc_1.icvflg = itemp;
    }
    if (inum == 2) {
	dc_1.icvflg = itemp * dc_1.icvflg;
    }
    ++ifld;
    inum = 2;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L1130;
    } else {
	goto L1105;
    }
L1130:
    io___564.ciunit = status_1.iofile;
    s_wsfe(&io___564);
    e_wsfe();
    dc_1.icvflg = 0;
    goto L6000;

/*  FREQUENCY SPECIFICATION */

L1200:
    ifld = 2;
    if (nodplc[tabinf_1.icode + 1] <= 0) {
	goto L1250;
    } else {
	goto L1210;
    }
L1210:
    *id = 0;
    if (blank_1.value[tabinf_1.ifield + ifld - 1] == alsde) {
	*id = 1;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] == alsoc) {
	*id = 2;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] == alsli) {
	*id = 3;
    }
    if (*id == 0) {
	goto L1240;
    }
    ac_1.idfreq = *id;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1250;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1250;
    }
    ac_1.fincr = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1250;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1250;
    }
    ac_1.fstart = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1250;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1250;
    }
    ac_1.fstop = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (ac_1.fstart > ac_1.fstop) {
	goto L1260;
    }
    ac_1.jacflg = (integer) ac_1.fincr;
    if ((i__1 = ac_1.idfreq - 2) < 0) {
	goto L1215;
    } else if (i__1 == 0) {
	goto L1220;
    } else {
	goto L1235;
    }
L1215:
    ac_1.fincr = exp(knstnt_1.xlog10 / ac_1.fincr);
    goto L1230;
L1220:
    ac_1.fincr = exp(knstnt_1.xlog2 / ac_1.fincr);
L1230:
    temp = log(ac_1.fstop / ac_1.fstart) / log(ac_1.fincr);
    ac_1.jacflg = (integer) (temp + .999) + 1;
L1235:
    ac_1.jacflg = max(ac_1.jacflg,minpts);
    if (ac_1.idfreq != 3) {
	goto L6000;
    }
/* Computing MAX */
    i__1 = ac_1.jacflg - 1;
    ac_1.fincr = (ac_1.fstop - ac_1.fstart) / (doublereal) max(i__1,1);
    goto L6000;
L1240:
    io___565.ciunit = status_1.iofile;
    s_wsfe(&io___565);
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.ifield + ifld - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    goto L6000;
L1250:
    io___566.ciunit = status_1.iofile;
    s_wsfe(&io___566);
    e_wsfe();
    goto L6000;
L1260:
    io___567.ciunit = status_1.iofile;
    s_wsfe(&io___567);
    e_wsfe();
    goto L6000;

/*  TIME SPECIFICATION */

L1300:
    ifld = 2;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1430;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1430;
    }
    tran_1.tstep = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1430;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1430;
    }
    tran_1.tstop = blank_1.value[tabinf_1.ifield + ifld - 1];
    tran_1.tstart = 0.;
    tran_1.delmax = tran_1.tstop / 50.;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1310;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] < 0.) {
	goto L1430;
    }
    tran_1.tstart = blank_1.value[tabinf_1.ifield + ifld - 1];
    tran_1.delmax = (tran_1.tstop - tran_1.tstart) / 50.;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1310;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1430;
    }
    tran_1.delmax = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
L1310:
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1320;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] != auic) {
	goto L1320;
    }
    status_1.nosolv = 1;
L1320:
    if (tran_1.tstart > tran_1.tstop) {
	goto L1440;
    }
    if (tran_1.tstep > tran_1.tstop) {
	goto L1430;
    }
    tran_1.jtrflg = (integer) ((tran_1.tstop - tran_1.tstart) / tran_1.tstep 
	    + .5) + 1;
    tran_1.jtrflg = max(tran_1.jtrflg,minpts);
    goto L6000;
L1430:
    io___568.ciunit = status_1.iofile;
    s_wsfe(&io___568);
    e_wsfe();
    goto L6000;
L1440:
    io___569.ciunit = status_1.iofile;
    s_wsfe(&io___569);
    e_wsfe();
    goto L6000;

/*  TRANSFER FUNCTION */

L1500:
    dc_1.kssop = 1;
    ifld = 2;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1530;
    }
    outdef_(&ifld, &c__1, &dc_1.kovar, &ktype);
    if (flags_1.igoof != 0) {
	goto L1530;
    }
    if (ktype != 1) {
	goto L1540;
    }
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1530;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    *id = 0;
    if (anam == aide[8]) {
	*id = 9;
    }
    if (anam == aide[9]) {
	*id = 10;
    }
    if (*id == 0) {
	goto L1530;
    }
    find_(&blank_1.value[tabinf_1.ifield + ifld - 1], id, &dc_1.kinel, &c__0);
    dc_1.kidin = *id;
    goto L6000;
L1530:
    dc_1.kovar = 0;
    dc_1.kinel = 0;
    io___571.ciunit = status_1.iofile;
    s_wsfe(&io___571);
    e_wsfe();
    flags_1.igoof = 0;
    goto L6000;
L1540:
    dc_1.kovar = 0;
    dc_1.kinel = 0;
    io___572.ciunit = status_1.iofile;
    s_wsfe(&io___572);
    e_wsfe();
    flags_1.igoof = 0;
    goto L6000;

/*  OPERATING POINT */

L1550:
    dc_1.kssop = 1;
    goto L6000;

/*  NOISE ANALYSIS */

L1600:
    ifld = 2;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1610;
    }
    outdef_(&ifld, &c__2, &ac_1.nosout, &ntype);
    if (flags_1.igoof != 0) {
	goto L1610;
    }
    if (ntype != 1) {
	goto L1610;
    }
    if (nodplc[ac_1.nosout + 4] != 0) {
	goto L1610;
    }
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1620;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    *id = 0;
    if (anam == aide[8]) {
	*id = 9;
    }
    if (anam == aide[9]) {
	*id = 10;
    }
    if (*id == 0) {
	goto L1620;
    }
    find_(&blank_1.value[tabinf_1.ifield + ifld - 1], id, &ac_1.nosin, &c__0);
    ac_1.nosprt = 0;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1605;
    }
/* Computing MAX */
    d__1 = 0., d__2 = blank_1.value[tabinf_1.ifield + ifld - 1];
    ac_1.nosprt = (integer) max(d__1,d__2);
L1605:
    ac_1.inoise = 1;
    goto L6000;
L1610:
    io___574.ciunit = status_1.iofile;
    s_wsfe(&io___574);
    e_wsfe();
    flags_1.igoof = 0;
    goto L6000;
L1620:
    io___575.ciunit = status_1.iofile;
    s_wsfe(&io___575);
    e_wsfe();
    flags_1.igoof = 0;
    goto L6000;

/*  DISTORTION ANALYSIS */

L1650:
    ifld = 2;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1660;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam != aide[0]) {
	goto L1660;
    }
    find_(&blank_1.value[tabinf_1.ifield + ifld - 1], &c__1, &ac_1.idist, &
	    c__0);
    ac_1.idprt = 0;
    ac_1.skw2 = .9;
    ac_1.refprl = .001;
    ac_1.spw2 = 1.;
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L6000;
    }
    ac_1.idprt = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    ac_1.idprt = max(ac_1.idprt,0);
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L6000;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= .001) {
	goto L1670;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] > .999) {
	goto L1670;
    }
    ac_1.skw2 = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L6000;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] < 1e-10) {
	goto L1670;
    }
    ac_1.refprl = blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L6000;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] < .001) {
	goto L1670;
    }
    ac_1.spw2 = blank_1.value[tabinf_1.ifield + ifld - 1];
    goto L6000;
L1660:
    io___576.ciunit = status_1.iofile;
    s_wsfe(&io___576);
    e_wsfe();
    goto L6000;
L1670:
    ac_1.idist = 0;
    io___577.ciunit = status_1.iofile;
    s_wsfe(&io___577);
    e_wsfe();
    goto L6000;

/*  FOURIER ANALYSIS */

L1700:
    ifld = 2;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L1720;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= 0.) {
	goto L1720;
    }
    tran_1.forfre = blank_1.value[tabinf_1.ifield + ifld - 1];
L1705:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L1710;
    }
    outdef_(&ifld, &c__2, &loct, &ltype);
    if (flags_1.igoof != 0) {
	goto L1720;
    }
    if (ltype != 1) {
	goto L1720;
    }
    extmem_(&tabinf_1.ifour, &c__1);
    ++tabinf_1.nfour;
    nodplc[tabinf_1.ifour + tabinf_1.nfour - 1] = loct;
    goto L1705;
L1710:
    if (tabinf_1.nfour >= 1) {
	goto L6000;
    }
L1720:
    io___580.ciunit = status_1.iofile;
    s_wsfe(&io___580);
    e_wsfe();
    flags_1.igoof = 0;
    tabinf_1.nfour = 0;
    clrmem_(&tabinf_1.ifour);
    getm4_(&tabinf_1.ifour, &c__0);
    goto L6000;

/*  SENSITIVITY ANALYSIS */

L1750:
    dc_1.kssop = 1;
    ifld = 1;
L1760:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L6000;
    }
    outdef_(&ifld, &c__1, &loct, &ltype);
    if (flags_1.igoof != 0) {
	goto L1780;
    }
    if (ltype != 1) {
	goto L1780;
    }
    extmem_(&tabinf_1.isens, &c__1);
    ++tabinf_1.nsens;
    nodplc[tabinf_1.isens + tabinf_1.nsens - 1] = loct;
    goto L1760;
L1780:
    io___581.ciunit = status_1.iofile;
    s_wsfe(&io___581);
    e_wsfe();
    flags_1.igoof = 0;
    tabinf_1.nsens = 0;
    clrmem_(&tabinf_1.isens);
    getm4_(&tabinf_1.isens, &c__0);
    goto L6000;

/*  TEMPERATURE VARIATION */

L1800:
    ifld = 1;
L1810:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	goto L6000;
    }
    if (blank_1.value[tabinf_1.ifield + ifld - 1] <= -223.) {
	goto L1810;
    }
    extmem_(&tabinf_1.itemps, &c__1);
    ++tabinf_1.numtem;
    blank_1.value[tabinf_1.itemps + tabinf_1.numtem - 1] = blank_1.value[
	    tabinf_1.ifield + ifld - 1];
    goto L1810;

/*  OPTIONS CARD */

L2000:
    ifld = 1;
L2010:
    ++ifld;
L2020:
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L2010;
    } else {
	goto L2030;
    }
L2030:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    for (i__ = 1; i__ <= 5; ++i__) {
	if (anam != aopts[i__ - 1]) {
	    goto L2040;
	}
	iprnt[i__ - 1] = lsetop[i__ - 1];
	++ifld;
	if (nodplc[tabinf_1.icode + ifld - 1] != 0) {
	    goto L2020;
	}
	iprnt[i__ - 1] = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
	goto L2010;
L2040:
	;
    }
    if (anam == aopts[24]) {
	goto L2110;
    }
    if (anam == aopts[25]) {
	goto L2120;
    }
    if (anam == aopts[26]) {
	goto L2130;
    }
    if (anam == aopts[27]) {
	goto L2150;
    }
    if (anam == aopts[32]) {
	goto L2200;
    }
    if (anam == aopts[33]) {
	goto L2250;
    }
    if (nodplc[tabinf_1.icode + ifld] != 0) {
	goto L2510;
    }
    ++ifld;
    aval = blank_1.value[tabinf_1.ifield + ifld - 1];
    for (i__ = 6; i__ <= 11; ++i__) {
	if (anam != aopts[i__ - 1]) {
	    goto L2050;
	}
	if (aval <= 0. && i__ != 10) {
	    goto L2510;
	}
	itrlim[i__ - 6] = (integer) aval;
	goto L2010;
L2050:
	;
    }
    if (aval <= 0.) {
	goto L2510;
    }
    for (i__ = 12; i__ <= 15; ++i__) {
	if (anam != aopts[i__ - 1]) {
	    goto L2060;
	}
	limits[i__ - 12] = (integer) aval;
	goto L2010;
L2060:
	;
    }
    for (i__ = 16; i__ <= 21; ++i__) {
	if (anam != aopts[i__ - 1]) {
	    goto L2070;
	}
	contol[i__ - 16] = aval;
	goto L2010;
L2070:
	;
    }
    for (i__ = 29; i__ <= 32; ++i__) {
	if (anam != aopts[i__ - 1]) {
	    goto L2075;
	}
	dflts[i__ - 29] = aval;
	goto L2010;
L2075:
	;
    }
    if (anam != aopts[21]) {
	goto L2080;
    }
    if (aval < -223.) {
	goto L2510;
    }
    blank_1.value[tabinf_1.itemps] = aval;
    goto L2010;
L2080:
    if (anam != aopts[22]) {
	goto L2100;
    }
    ndigit = (integer) aval;
    if (ndigit <= 7) {
	goto L2090;
    }
    ndigit = 7;
    io___585.ciunit = status_1.iofile;
    s_wsfe(&io___585);
    do_fio(&c__1, (char *)&ndigit, (ftnlen)sizeof(integer));
    e_wsfe();
L2090:
    outinf_1.numdgt = ndigit;
    goto L2010;
L2100:
    if (anam != aopts[23]) {
	goto L2500;
    }
    n = (integer) aval;
    if (n <= 1 || n >= 7) {
	goto L2510;
    }
    status_1.maxord = n;
    goto L2010;
L2110:
    if (nodplc[tabinf_1.icode + ifld] != 1) {
	goto L2510;
    }
    ++ifld;
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    move_(&anam, &c__5, &ablnk, &c__1, &c__4);
    jtype = 0;
    if (anam == atrap) {
	jtype = 1;
    }
    if (anam == agear) {
	jtype = 2;
    }
    if (jtype == 0) {
	goto L2510;
    }
    status_1.method = jtype;
    goto L2010;
L2120:
    miscel_1.nopage = 1;
    goto L2010;
L2130:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L2140;
    } else {
	goto L2030;
    }
L2140:
    aval = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (aval < 0. || aval > .500001) {
	goto L2510;
    }
    status_1.xmu = aval;
    goto L2010;
L2150:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L2160;
    } else {
	goto L2030;
    }
L2160:
    aval = blank_1.value[tabinf_1.ifield + ifld - 1];
    cje_1.maxtim = (integer) aval;
    goto L2010;
L2200:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L2210;
    } else {
	goto L2030;
    }
L2210:
    aval = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (aval > 1.) {
	goto L2510;
    }
    knstnt_1.pivtol = aval;
    goto L2010;
L2250:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L2260;
    } else {
	goto L2030;
    }
L2260:
    aval = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (aval > 1.) {
	goto L2510;
    }
    knstnt_1.pivrel = aval;
    goto L2010;
L2500:
    io___588.ciunit = status_1.iofile;
    s_wsfe(&io___588);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L2010;
L2510:
    io___589.ciunit = status_1.iofile;
    s_wsfe(&io___589);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L2010;

/*  PRINT CARD */

L3500:
    iprpl = 0;
    goto L3610;

/*  PLOT (AND PRINT) CARD */

L3600:
    iprpl = 1;
L3610:
    ifld = 2;
/* L3613: */
    anam = amiss;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L3950;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    ms = 0;
    if (xxor_(&anam, &ams) != 0) {
	goto L3615;
    }
    ms = 1;
    ifld = 3;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L3970;
    }
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
L3615:
    move_(&anam, &c__3, &ablnk, &c__1, &c__6);
    for (i__ = 1; i__ <= 5; ++i__) {
	if (anam != aopt[i__ - 1]) {
	    goto L3620;
	}
	ktype = i__;
	goto L3630;
L3620:
	;
    }
    goto L3950;
L3630:
    *id = iprpl * 5 + 30 + ktype;
    d__1 = (doublereal) cirdat_1.jelcnt[*id - 1];
    find_(&d__1, id, &loc, &c__1);
    nodplc[loc + 1] = ktype;
    if (ms == 0) {
	goto L3635;
    }
    locv = nodplc[loc];
    blank_1.value[locv - 1] = 0.;
L3635:
    outinf_1.numout = 0;
L3640:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L3900;
    } else if (i__1 == 0) {
	goto L3640;
    } else {
	goto L3650;
    }
L3650:
    outdef_(&ifld, &ktype, &loct, &ltype);
    if (flags_1.igoof != 0) {
	goto L3970;
    }
    if (iprpl == 0) {
	goto L3660;
    }
    plimlo = 0.;
    plimhi = 0.;
    if (nodplc[tabinf_1.icode + ifld] != 0) {
	goto L3660;
    }
    if (nodplc[tabinf_1.icode + ifld + 1] != 0) {
	goto L3660;
    }
    plimlo = blank_1.value[tabinf_1.ifield + ifld];
    plimhi = blank_1.value[tabinf_1.ifield + ifld + 1];
    ifld += 2;
L3660:
    ++outinf_1.numout;
    lspot = loc + (outinf_1.numout << 1) + 2;
    nodplc[lspot - 1] = loct;
    nodplc[lspot] = ltype;
    if (iprpl == 0) {
	goto L3670;
    }
    locv = nodplc[loc];
    lspot = locv + (outinf_1.numout << 1) - 1;
    blank_1.value[lspot - 1] = plimlo;
    blank_1.value[lspot] = plimhi;
L3670:
    if (outinf_1.numout == 8) {
	goto L3900;
    }
    goto L3640;
L3900:
    nodplc[loc + 2] = outinf_1.numout;
    if (iprpl == 0) {
	goto L6000;
    }
/* ...  PROPOGATE PLOT LIMITS DOWNWARD */
    if (outinf_1.numout <= 1) {
	goto L6000;
    }
    locv = nodplc[loc];
    lspot = locv + (outinf_1.numout << 1) - 1;
    plimlo = blank_1.value[lspot - 1];
    plimhi = blank_1.value[lspot];
    i__ = outinf_1.numout - 1;
L3905:
    lspot += -2;
    if (blank_1.value[lspot - 1] != 0.) {
	goto L3910;
    }
    if (blank_1.value[lspot] != 0.) {
	goto L3910;
    }
    blank_1.value[lspot - 1] = plimlo;
    blank_1.value[lspot] = plimhi;
    goto L3920;
L3910:
    plimlo = blank_1.value[lspot - 1];
    plimhi = blank_1.value[lspot];
L3920:
    --i__;
    if (i__ >= 1) {
	goto L3905;
    }
    goto L6000;

/*     ERRORS */

L3950:
    io___597.ciunit = status_1.iofile;
    s_wsfe(&io___597);
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L6000;
L3970:
    io___598.ciunit = status_1.iofile;
    s_wsfe(&io___598);
    e_wsfe();
    flags_1.igoof = 0;
    goto L3640;

/*  WIDTH CARD */

L4000:
    ifld = 1;
L4010:
    ++ifld;
    if (nodplc[tabinf_1.icode + ifld - 1] != 1) {
	goto L6000;
    }
L4020:
    anam = blank_1.value[tabinf_1.ifield + ifld - 1];
    if (anam != ain) {
	goto L4040;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4030;
    } else {
	goto L4020;
    }
L4030:
    miscel_1.iwidth = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
/* Computing MIN */
    i__1 = max(miscel_1.iwidth,10);
    miscel_1.iwidth = min(i__1,120);
    goto L4010;
L4040:
    if (anam != aout) {
	goto L6000;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4050;
    } else {
	goto L4020;
    }
L4050:
/* Computing MIN */
/* Computing MAX */
    d__2 = blank_1.value[tabinf_1.ifield + ifld - 1];
    d__1 = max(d__2,72.);
    miscel_1.lwidth = (integer) min(d__1,132.);
    goto L4010;

/*  NODESET STATEMENT */

L4100:
    ifld = 1;
L4110:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4120;
    } else {
	goto L4110;
    }
L4120:
    nodnum = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    if (nodnum <= 0) {
	goto L4190;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L4180;
    } else if (i__1 == 0) {
	goto L4130;
    } else {
	goto L4170;
    }
L4130:
    sizmem_(&tabinf_1.nsnod, &nic);
    extmem_(&tabinf_1.nsnod, &c__1);
    extmem_(&tabinf_1.nsval, &c__1);
    nodplc[tabinf_1.nsnod + nic] = nodnum;
    blank_1.value[tabinf_1.nsval + nic] = blank_1.value[tabinf_1.ifield + 
	    ifld - 1];
    goto L4110;

/*  ERRORS ON .NODESET STATEMENT */

L4170:
    io___601.ciunit = status_1.iofile;
    s_wsfe(&io___601);
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.ifield + ifld - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    goto L4110;
L4180:
    io___602.ciunit = status_1.iofile;
    s_wsfe(&io___602);
    do_fio(&c__1, (char *)&nodnum, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L6000;
L4190:
    io___603.ciunit = status_1.iofile;
    s_wsfe(&io___603);
    e_wsfe();
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4110;
    } else {
	goto L4170;
    }

/*  INITIAL CONDITIONS STATEMENT */

L4200:
    ifld = 1;
L4210:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4220;
    } else {
	goto L4210;
    }
L4220:
    nodnum = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    if (nodnum <= 0) {
	goto L4290;
    }
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L4280;
    } else if (i__1 == 0) {
	goto L4230;
    } else {
	goto L4270;
    }
L4230:
    sizmem_(&tabinf_1.icnod, &nic);
    extmem_(&tabinf_1.icnod, &c__1);
    extmem_(&tabinf_1.icval, &c__1);
    nodplc[tabinf_1.icnod + nic] = nodnum;
    blank_1.value[tabinf_1.icval + nic] = blank_1.value[tabinf_1.ifield + 
	    ifld - 1];
    goto L4210;

/*  ERRORS ON .IC STATEMENT */

L4270:
    io___604.ciunit = status_1.iofile;
    s_wsfe(&io___604);
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.ifield + ifld - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    goto L4210;
L4280:
    io___605.ciunit = status_1.iofile;
    s_wsfe(&io___605);
    do_fio(&c__1, (char *)&nodnum, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L6000;
L4290:
    io___606.ciunit = status_1.iofile;
    s_wsfe(&io___606);
    e_wsfe();
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L4210;
    } else {
	goto L4270;
    }

/*     :DEBUG: STATEMENT */
/*     SAMPLE DEBUG LINE: .:DEBUG: 5=3 17=5 */

L5900:
    ifld = 1;
L5910:
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L5920;
    } else {
	goto L5910;
    }
L5920:
    index = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    ++ifld;
    if ((i__1 = nodplc[tabinf_1.icode + ifld - 1]) < 0) {
	goto L6000;
    } else if (i__1 == 0) {
	goto L5930;
    } else {
	goto L5910;
    }
L5930:
    ival = (integer) blank_1.value[tabinf_1.ifield + ifld - 1];
    if (index < 1) {
	goto L5910;
    }
    if (index > 20) {
	goto L5910;
    }
    io___609.ciunit = status_1.iofile;
    s_wsfe(&io___609);
    do_fio(&c__1, (char *)&index, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ival, (ftnlen)sizeof(integer));
    e_wsfe();
    debug_1.idebug[index - 1] = ival;
    goto L5910;

/*  FINISHED */

L6000:
    return 0;
} /* runcon_ */

#undef contol
#undef itrlim
#undef limits
#undef cvalue
#undef nodplc
#undef iprnt
#undef dflts
#undef ams
#undef amiss
#undef aout
#undef ain
#undef ablnk
#undef auic
#undef agear
#undef atrap
#undef alsli
#undef alsoc
#undef alsde
#undef aide
#undef aopts
#undef aopt


/* Subroutine */ int outdef_(integer *ifld, integer *mode, integer *loct, 
	integer *ltype)
{
    /* Initialized data */

    static struct {
	char e_1[152];
	doublereal e_2;
	} equiv_645 = { "V       VM      VR      VI      VP      VDB     I  "
		"     IM      IR      II      IP      IDB     ONOI    INOI   "
		" HD2     HD3     DIM2    SIM2    DIM3    ", 0. };

#define aout ((doublereal *)&equiv_645)

    static struct {
	char e_1[40];
	doublereal e_2;
	} equiv_646 = { "M       R       I       P       D       ", 0. };

#define aopts ((doublereal *)&equiv_646)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_647 = { "(       ", 0. };

#define alprn (*(doublereal *)&equiv_647)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_648 = { ",       ", 0. };

#define acomma (*(doublereal *)&equiv_648)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_649 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_649)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_650 = { "V       ", 0. };

#define aletv (*(doublereal *)&equiv_650)


    /* Local variables */
    static integer i__, n1, n2, id;
    static doublereal anam;
    extern /* Subroutine */ int find_(doublereal *, integer *, integer *, 
	    integer *), move_(doublereal *, integer *, doublereal *, integer *
	    , integer *);
    static integer ipos;
    extern integer xxor_(doublereal *, doublereal *);
    static doublereal achek, avsrc;
    static integer idout, ktype;
    static doublereal atype, adelim;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *);
    static doublereal outnam;


/*     THIS ROUTINE CONSTRUCTS THE INTERNAL LIST ELEMENT FOR AN OUTPUT */
/* VARIABLE DEFINED ON SOME INPUT CARD. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    if (nodplc[(0 + (0 + (tabinf_1.icode + *ifld - 1 << 2))) / 4] != 1) {
	goto L300;
    }
    anam = blank_1.value[tabinf_1.ifield + *ifld - 1];
    move_(&anam, &c__5, &ablnk, &c__1, &c__4);
    for (i__ = 1; i__ <= 19; ++i__) {
	if (xxor_(&anam, &aout[i__ - 1]) != 0) {
	    goto L10;
	}
	idout = i__;
	goto L20;
L10:
	;
    }
    goto L300;

/*  FURTHER ERROR CHECKING */

L20:
    if (*mode >= 3) {
	goto L25;
    }
/* ...  DC OR TRAN */
    if (idout != 1 && idout != 7) {
	goto L300;
    }
    goto L38;
L25:
    if (*mode >= 4) {
	goto L30;
    }
/* ...  AC */
    if (idout >= 13) {
	goto L300;
    }
    goto L38;
L30:
    if (*mode == 5) {
	goto L35;
    }
/* ...  NOISE */
    if (idout != 13 && idout != 14) {
	goto L300;
    }
    goto L38;
/* ...  DISTORTION */
L35:
    if (idout < 15) {
	goto L300;
    }
L38:
    ktype = 0;
    *ltype = idout;
    if (idout < 7) {
	goto L40;
    }
    ktype = 1;
    *ltype += -6;
    if (idout < 13) {
	goto L40;
    }
    ktype = idout - 11;
    *ltype = 1;

/*  VOLTAGE OUTPUT */

L40:
    id = *mode + 40;
    if (ktype != 0) {
	goto L100;
    }
    if (nodplc[tabinf_1.icode + *ifld] != 0) {
	goto L300;
    }
    ++(*ifld);
    n1 = (integer) blank_1.value[tabinf_1.ifield + *ifld - 1];
    if (n1 < 0) {
	goto L300;
    }
    if (n1 > 9999) {
	goto L300;
    }
    n2 = 0;
    adelim = blank_1.value[tabinf_1.idelim + *ifld - 1];
    if (adelim == acomma) {
	goto L45;
    }
    if (adelim != ablnk) {
	goto L50;
    }
L45:
    if (nodplc[tabinf_1.icode + *ifld] != 0) {
	goto L300;
    }
    ++(*ifld);
    n2 = (integer) blank_1.value[tabinf_1.ifield + *ifld - 1];
    if (n2 < 0) {
	goto L300;
    }
    if (n2 > 9999) {
	goto L300;
    }
L50:
    outnam = ablnk;
    ipos = 1;
    alfnum_(&n1, &outnam, &ipos);
    ipos = 5;
    alfnum_(&n2, &outnam, &ipos);
    find_(&outnam, &id, loct, &c__0);
    nodplc[*loct + 1] = n1;
    nodplc[*loct + 2] = n2;
    goto L400;

/*  CURRENT OUTPUT */

L100:
    if (ktype != 1) {
	goto L200;
    }
    if (nodplc[tabinf_1.icode + *ifld] != 1) {
	goto L300;
    }
    ++(*ifld);
    avsrc = blank_1.value[tabinf_1.ifield + *ifld - 1];
    achek = avsrc;
    move_(&achek, &c__2, &ablnk, &c__1, &c__7);
    if (achek != aletv) {
	goto L300;
    }
    find_(&avsrc, &id, loct, &c__0);
    find_(&avsrc, &c__9, &nodplc[*loct + 1], &c__0);
    nodplc[*loct + 4] = 1;
    goto L400;

/*  NOISE OR DISTORTION OUTPUTS */

L200:
    id = 44;
    if (ktype >= 4) {
	++id;
    }
    if (blank_1.value[tabinf_1.idelim + *ifld - 1] != alprn) {
	goto L220;
    }
    if (nodplc[tabinf_1.icode + *ifld] != 1) {
	goto L300;
    }
    ++(*ifld);
    atype = blank_1.value[tabinf_1.ifield + *ifld - 1];
    move_(&atype, &c__2, &ablnk, &c__1, &c__7);
    for (i__ = 1; i__ <= 5; ++i__) {
	if (atype != aopts[i__ - 1]) {
	    goto L210;
	}
	*ltype = i__ + 1;
	goto L220;
L210:
	;
    }
    goto L300;
L220:
    find_(&anam, &id, loct, &c__0);
    nodplc[*loct + 1] = 0;
    nodplc[*loct + 4] = ktype;
    goto L400;

/*  ERRORS */

L300:
    flags_1.igoof = 1;

/*  FINISHED */

L400:
    return 0;
} /* outdef_ */

#undef cvalue
#undef nodplc
#undef aletv
#undef ablnk
#undef acomma
#undef alprn
#undef aopts
#undef aout


/* Subroutine */ int card_(void)
{
    /* Initialized data */

    static struct {
	char e_1[80];
	doublereal e_2;
	} equiv_691 = { "0       1       2       3       4       5       6  "
		"     7       8       9       ", 0. };

#define adigit ((doublereal *)&equiv_691)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_692 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_692)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_693 = { ".       ", 0. };

#define aper (*(doublereal *)&equiv_693)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_694 = { "+       ", 0. };

#define aplus (*(doublereal *)&equiv_694)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_695 = { "-       ", 0. };

#define aminus (*(doublereal *)&equiv_695)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_696 = { "*       ", 0. };

#define astk (*(doublereal *)&equiv_696)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_697 = { "G       ", 0. };

#define bg (*(doublereal *)&equiv_697)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_698 = { "K       ", 0. };

#define ak (*(doublereal *)&equiv_698)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_699 = { "U       ", 0. };

#define au (*(doublereal *)&equiv_699)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_700 = { "N       ", 0. };

#define an (*(doublereal *)&equiv_700)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_701 = { "P       ", 0. };

#define ap (*(doublereal *)&equiv_701)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_702 = { "E       ", 0. };

#define ae (*(doublereal *)&equiv_702)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_703 = { "M       ", 0. };

#define am (*(doublereal *)&equiv_703)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_704 = { "F       ", 0. };

#define af (*(doublereal *)&equiv_704)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_705 = { "T       ", 0. };

#define at (*(doublereal *)&equiv_705)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_706 = { "I       ", 0. };

#define ai (*(doublereal *)&equiv_706)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_707 = { "(       ", 0. };

#define alprn (*(doublereal *)&equiv_707)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_708 = { ")       ", 0. };

#define arprn (*(doublereal *)&equiv_708)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_709 = { "=       ", 0. };

#define aequal (*(doublereal *)&equiv_709)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_710 = { ".END    ", 0. };

#define aend (*(doublereal *)&equiv_710)


    /* Format strings */
    static char fmt_16[] = "(\0020*ERROR*:  .END CARD MISSING\002/)";
    static char fmt_31[] = "(1x)";
    static char fmt_41[] = "(1x,10a8)";
    static char fmt_501[] = "(\0020*ERROR*:  ILLEGAL NUMBER -- SCAN STOPPED "
	    "AT COLUMN \002,i3/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    double exp(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, idec;
    static doublereal anam;
    static integer kchr, iexp;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer nofld, isign, itemp;
    static doublereal xsign, xmant;
    static integer jdelim;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer numfld;
    extern /* Subroutine */ int getlin_(void);
    extern integer nxtchr_(integer *);
    extern /* Subroutine */ int extmem_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___675 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___676 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___677 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___688 = { 0, 0, 0, fmt_501, 0 };
    static cilist io___689 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___690 = { 0, 0, 0, fmt_41, 0 };



/*     THIS ROUTINE SCANS THE INPUT LINES, STORING EACH FIELD INTO THE */
/* TABLES IFIELD, IDELIM, ICOLUM, AND ICODE.  WITH THE EXCEPTION OF THE */
/* '.END' LINE, CARD ALWAYS READS THE NEXT LINE TO CHECK FOR A POSSIBLE */
/* CONTINUATION BEFORE IT EXITS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


/*      NOTE:  THE VALUE OF THE FUNCTION *NXTCHR* (USED EXTENSIVELY IN */
/* THIS ROUTINE) IS AS FOLLOWS: */

/*                    <0:  END-OF-LINE */
/*                    =0:  DELIMITER FOUND */
/*                    >0:  NON-DELIMITER FOUND */

    numfld = 0;
    nofld = 10;
    goto L20;

/*  READ NEXT CARD */

L10:
    nofld = 10;
    getlin_();
    if (flags_1.keof == 0) {
	goto L20;
    }
/* ...  ERROR:  UNEXPECTED END-OF-FILE CONDITION ON INPUT */
L15:
    flags_1.keof = 1;
    nofld = 1;
    numfld = 0;
    flags_1.igoof = 1;
    io___675.ciunit = status_1.iofile;
    s_wsfe(&io___675);
    e_wsfe();
    goto L1000;

/*  ELIMINATE TRAILING BLANKS RAPIDLY */

L20:
    if (line_1.afield[nofld - 1] != ablnk) {
	goto L40;
    }
    if (nofld == 1) {
	goto L30;
    }
    --nofld;
    goto L20;
/* ...  WRITE BLANK CARD */
L30:
    io___676.ciunit = status_1.iofile;
    s_wsfe(&io___676);
    e_wsfe();
    goto L10;
/* ...  COPY THE CARD TO OUTPUT LISTING */
L40:
    io___677.ciunit = status_1.iofile;
    s_wsfe(&io___677);
    i__1 = nofld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&line_1.afield[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

/*  INITIALIZATION FOR NEW CARD */

/* L45: */
    line_1.kntrc = 0;
/* Computing MIN */
    i__1 = nofld << 3;
    line_1.kntlim = min(i__1,miscel_1.iwidth);

/*  FETCH FIRST NON-DELIMITER (SEE ROUTINE *NXTCHR* FOR LIST) */

L50:
    if ((i__1 = nxtchr_(&c__0)) < 0) {
	goto L600;
    } else if (i__1 == 0) {
	goto L50;
    } else {
	goto L60;
    }
/* ...  CHECK FOR COMMENT (LEADING ASTERISK) */
L60:
    if (line_1.achar == astk) {
	goto L10;
    }
    goto L100;

/*  FETCH NEXT CHARACTER */

L70:
    if ((i__1 = nxtchr_(&c__0)) < 0) {
	goto L600;
    } else if (i__1 == 0) {
	goto L80;
    } else {
	goto L100;
    }

/*  TWO CONSECUTIVE DELIMITERS IMPLY NUMERIC ZERO UNLESS THE DELIMITER */
/*  IS A BLANK OR PARENTHESIS. */

L80:
    if (line_1.achar == ablnk) {
	goto L70;
    }
    if (line_1.achar == alprn) {
	goto L70;
    }
    if (line_1.achar == arprn) {
	goto L70;
    }
    if (line_1.achar == aequal) {
	goto L70;
    }
/* ...  CHECK FOR SUFFICIENT SPACE IN STORAGE ARRAYS */
    if (numfld < tabinf_1.insize - 1) {
	goto L90;
    }
    extmem_(&tabinf_1.ifield, &c__50);
    extmem_(&tabinf_1.icode, &c__50);
    extmem_(&tabinf_1.idelim, &c__50);
    extmem_(&tabinf_1.icolum, &c__50);
    tabinf_1.insize += 50;
L90:
    ++numfld;
    blank_1.value[tabinf_1.ifield + numfld - 1] = 0.;
    nodplc[tabinf_1.icode + numfld - 1] = 0;
    blank_1.value[tabinf_1.idelim + numfld - 1] = line_1.achar;
    nodplc[tabinf_1.icolum + numfld - 1] = line_1.kntrc;
    goto L70;

/*  CHECK FOR SUFFICIENT SPACE IN STORAGE ARRAYS */

L100:
    if (numfld < tabinf_1.insize - 1) {
	goto L110;
    }
    extmem_(&tabinf_1.ifield, &c__50);
    extmem_(&tabinf_1.icode, &c__50);
    extmem_(&tabinf_1.idelim, &c__50);
    extmem_(&tabinf_1.icolum, &c__50);
    tabinf_1.insize += 50;

/*  BEGIN SCAN OF NEXT FIELD */

/* ...  INITIALIZATION */
L110:
    jdelim = 0;
    xsign = 1.;
    xmant = 0.;
    idec = 0;
    iexp = 0;
/* ...  CHECK FOR LEADING PLUS OR MINUS SIGN */
    if (line_1.achar == aplus) {
	goto L210;
    }
    if (line_1.achar == aminus) {
	goto L200;
    }
/* ...  FINISH INITIALIZATION */
    anam = ablnk;
    kchr = 1;
/* ...  AN ISOLATED PERIOD INDICATES THAT A CONTINUATION CARD FOLLOWS */
    if (line_1.achar != aper) {
	goto L120;
    }
/* ...  ALTER INITIALIZATION SLIGHTLY IF LEADING PERIOD FOUND */
    idec = 1;
    iexp = -1;
    anam = aper;
    kchr = 2;
/* ...  NOW TAKE A LOOK AT THE NEXT CHARACTER */
    if (nxtchr_(&c__0) <= 0) {
	goto L10;
    } else {
	goto L120;
    }

/*  TEST FOR NUMBER (ANY DIGIT) */

L120:
    for (i__ = 1; i__ <= 10; ++i__) {
	if (line_1.achar != adigit[i__ - 1]) {
	    goto L130;
	}
	xmant = (doublereal) (i__ - 1);
	goto L210;
L130:
	;
    }

/*  ASSEMBLE NAME */

    ++numfld;
    move_(&anam, &kchr, &line_1.achar, &c__1, &c__1);
    ++kchr;
    for (i__ = kchr; i__ <= 8; ++i__) {
	if (nxtchr_(&c__0) <= 0) {
	    goto L160;
	} else {
	    goto L140;
	}
L140:
	move_(&anam, &i__, &line_1.achar, &c__1, &c__1);
/* L150: */
    }
    goto L170;
L160:
    jdelim = 1;
L170:
    blank_1.value[tabinf_1.ifield + numfld - 1] = anam;
    nodplc[tabinf_1.icode + numfld - 1] = 1;
    nodplc[tabinf_1.icolum + numfld - 1] = line_1.kntrc;
/* ...  NO '+' FORMAT CONTINUATION POSSIBLE FOR .END CARD */
    if (numfld >= 2) {
	goto L400;
    }
    if (anam != aend) {
	goto L400;
    }
    nodplc[tabinf_1.icode + numfld] = -1;
    goto L1000;

/*  PROCESS NUMBER */

/* ...  TAKE NOTE OF LEADING MINUS SIGN */
L200:
    xsign = -1.;
/* ...  TAKE A LOOK AT THE NEXT CHARACTER */
L210:
    if (nxtchr_(&c__0) <= 0) {
	goto L335;
    } else {
	goto L220;
    }
/* ...  TEST FOR DIGIT */
L220:
    for (i__ = 1; i__ <= 10; ++i__) {
	if (line_1.achar != adigit[i__ - 1]) {
	    goto L230;
	}
	xmant = xmant * 10. + (doublereal) (i__ - 1);
	if (idec == 0) {
	    goto L210;
	}
	--iexp;
	goto L210;
L230:
	;
    }

/*  CHECK FOR DECIMAL POINT */

    if (line_1.achar != aper) {
	goto L240;
    }
/* ...  MAKE CERTAIN THAT THIS IS THE FIRST ONE FOUND */
    if (idec != 0) {
	goto L500;
    }
    idec = 1;
    goto L210;

/*  TEST FOR EXPONENT */

L240:
    if (line_1.achar != ae) {
	goto L300;
    }
    if (nxtchr_(&c__0) <= 0) {
	goto L335;
    } else {
	goto L250;
    }
L250:
    itemp = 0;
    isign = 1;
/* ...  CHECK FOR POSSIBLE LEADING SIGN ON EXPONENT */
    if (line_1.achar == aplus) {
	goto L260;
    }
    if (line_1.achar != aminus) {
	goto L270;
    }
    isign = -1;
L260:
    if (nxtchr_(&c__0) <= 0) {
	goto L285;
    } else {
	goto L270;
    }
/* ...  TEST FOR DIGIT */
L270:
    for (i__ = 1; i__ <= 10; ++i__) {
	if (line_1.achar != adigit[i__ - 1]) {
	    goto L280;
	}
	itemp = itemp * 10 + i__ - 1;
	goto L260;
L280:
	;
    }
    goto L290;
L285:
    jdelim = 1;
/* ...  CORRECT INTERNAL EXPONENT */
L290:
    iexp += isign * itemp;
    goto L340;

/*  TEST FOR SCALE FACTOR */

L300:
    if (line_1.achar != am) {
	goto L330;
    }
/* ...  SPECIAL CHECK FOR *ME* (AS DISTINGUISHED FROM *M*) */
    if (nxtchr_(&c__0) <= 0) {
	goto L320;
    } else {
	goto L310;
    }
L310:
    if (line_1.achar != ae) {
	goto L315;
    }
    iexp += 6;
    goto L340;
L315:
    if (line_1.achar != ai) {
	goto L325;
    }
    xmant *= 2.54e-5;
    goto L340;
L320:
    jdelim = 1;
L325:
    iexp += -3;
    goto L340;
L330:
    if (line_1.achar == at) {
	iexp += 12;
    }
    if (line_1.achar == bg) {
	iexp += 9;
    }
    if (line_1.achar == ak) {
	iexp += 3;
    }
    if (line_1.achar == au) {
	iexp += -6;
    }
    if (line_1.achar == an) {
	iexp += -9;
    }
    if (line_1.achar == ap) {
	iexp += -12;
    }
    if (line_1.achar == af) {
	iexp += -15;
    }
    goto L340;
L335:
    jdelim = 1;

/*  ASSEMBLE THE FINAL NUMBER */

L340:
    if (xmant == 0.) {
	goto L350;
    }
    if (iexp == 0) {
	goto L350;
    }
    if (abs(iexp) >= 201) {
	goto L500;
    }
    xmant *= exp((doublereal) iexp * knstnt_1.xlog10);
    if (xmant > 1e35) {
	goto L500;
    }
    if (xmant < 1e-35) {
	goto L500;
    }
L350:
    ++numfld;
    blank_1.value[tabinf_1.ifield + numfld - 1] = d_sign(&xmant, &xsign);
    nodplc[tabinf_1.icode + numfld - 1] = 0;
    nodplc[tabinf_1.icolum + numfld - 1] = line_1.kntrc;

/*  SKIP TO NON-BLANK DELIMITER (IF NECESSARY) */

L400:
    if (jdelim == 0) {
	goto L440;
    }
L410:
    blank_1.value[tabinf_1.idelim + numfld - 1] = line_1.achar;
    if (line_1.achar != ablnk) {
	goto L70;
    }
    if ((i__1 = nxtchr_(&c__0)) < 0) {
	goto L450;
    } else if (i__1 == 0) {
	goto L410;
    } else {
	goto L420;
    }
L420:
    --line_1.kntrc;
    goto L70;
L440:
    if ((i__1 = nxtchr_(&c__0)) < 0) {
	goto L450;
    } else if (i__1 == 0) {
	goto L410;
    } else {
	goto L440;
    }
L450:
    blank_1.value[tabinf_1.idelim + numfld - 1] = line_1.achar;
    goto L600;

/*  ERRORS */

L500:
    io___688.ciunit = status_1.iofile;
    s_wsfe(&io___688);
    do_fio(&c__1, (char *)&line_1.kntrc, (ftnlen)sizeof(integer));
    e_wsfe();
    flags_1.igoof = 1;
    ++numfld;
    blank_1.value[tabinf_1.ifield + numfld - 1] = 0.;
    nodplc[tabinf_1.icode + numfld - 1] = 0;
    blank_1.value[tabinf_1.idelim + numfld - 1] = line_1.achar;
    nodplc[tabinf_1.icolum + numfld - 1] = line_1.kntrc;

/*  FINISHED */

L600:
    nodplc[tabinf_1.icode + numfld] = -1;

/*  CHECK NEXT LINE FOR POSSIBLE CONTINUATION */

L610:
    getlin_();
    if (flags_1.keof == 1) {
	goto L15;
    }
    nofld = 10;
L620:
    if (line_1.afield[nofld - 1] != ablnk) {
	goto L630;
    }
    if (nofld == 1) {
	goto L650;
    }
    --nofld;
    goto L620;
L630:
    line_1.kntrc = 0;
/* Computing MIN */
    i__1 = nofld << 3;
    line_1.kntlim = min(i__1,miscel_1.iwidth);
/* ...  CONTINUATION LINE HAS A '+' AS FIRST NON-DELIMITER ON CARD */
L632:
    if ((i__1 = nxtchr_(&c__0)) < 0) {
	goto L650;
    } else if (i__1 == 0) {
	goto L632;
    } else {
	goto L634;
    }
L634:
    if (line_1.achar != aplus) {
	goto L640;
    }
    io___689.ciunit = status_1.iofile;
    s_wsfe(&io___689);
    i__1 = nofld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&line_1.afield[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L70;
L640:
    if (line_1.achar != astk) {
	goto L1000;
    }
L650:
    io___690.ciunit = status_1.iofile;
    s_wsfe(&io___690);
    i__1 = nofld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&line_1.afield[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L610;
L1000:
    return 0;
} /* card_ */

#undef cvalue
#undef nodplc
#undef aend
#undef aequal
#undef arprn
#undef alprn
#undef ai
#undef at
#undef af
#undef am
#undef ae
#undef ap
#undef an
#undef au
#undef ak
#undef bg
#undef astk
#undef aminus
#undef aplus
#undef aper
#undef ablnk
#undef adigit


/* Subroutine */ int getlin_(void)
{
    /* Format strings */
    static char fmt_6[] = "(10a8)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *),
	     ushift_(doublereal *);

    /* Fortran I/O blocks */
    static cilist io___711 = { 0, 5, 1, fmt_6, 0 };



/*     THIS ROUTINE READS THE NEXT LINE OF INPUT INTO THE ARRAY AFIELD. */
/* IF END-OF-FILE IS FOUND, THE VARIABLE KEOF IS SET TO 1. */

/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */


    copy8_(line_1.afield, line_1.oldlin, &c__15);
    i__1 = s_rsfe(&io___711);
    if (i__1 != 0) {
	goto L10;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	i__1 = do_fio(&c__1, (char *)&line_1.afield[i__ - 1], (ftnlen)sizeof(
		doublereal));
	if (i__1 != 0) {
	    goto L10;
	}
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L10;
    }
    goto L100;
L10:
    flags_1.keof = 1;
L100:
    ushift_(line_1.afield);
    return 0;
} /* getlin_ */

/* Subroutine */ int ushift_(shortint *line)
{
    static integer i__;
    static shortint ichar1, ichar2;


/* ..   THIS ROUTINE UPSHIFTS AN INPUT LINE */

    /* Parameter adjustments */
    --line;

    /* Function Body */
    for (i__ = 1; i__ <= 40; ++i__) {
	ichar1 = (shortint) (line[i__] / 256);
/* ..   IF THE TOP BYTE IS BETWEEN 'a' AND 'z', UPSHIFTS IT ... */
	if (! (ichar1 >= 97 && ichar1 <= 122)) {
	    goto L1;
	}
	ichar1 = (shortint) (ichar1 - 32);
L1:
	ichar2 = (shortint) (line[i__] - (line[i__] / 256 << 8));
/* ..   IF THE BOTTOM BYTE IS BETWEEN 'a' AND 'z', UPSHIFTS IT ... */
	if (! (ichar2 >= 97 && ichar2 <= 122)) {
	    goto L2;
	}
	ichar2 = (shortint) (ichar2 - 32);
L2:
	line[i__] = (shortint) ((ichar1 << 8) + ichar2);
/* L3: */
    }
    return 0;
} /* ushift_ */

integer nxtchr_(integer *int__)
{
    /* Initialized data */

    static struct {
	char e_1[40];
	doublereal e_2;
	} equiv_720 = { "        ,       =       (       )       ", 0. };

#define adelim ((doublereal *)&equiv_720)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_721 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_721)


    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);


/*     THIS ROUTINE ADVANCES THE CURRENT LINE SCAN POINTER ONE COLUMN */
/*     AND CHECKS WHETHER OR NOT THE NEXT CHARACTER IS A DELIMITER */

/* SPICE VERSION 2G.6  SCCSID=LINE 3/15/83 */


/*  ADVANCE SCAN POINTER (KNTRC) */

    ++line_1.kntrc;
    if (line_1.kntrc > line_1.kntlim) {
	goto L30;
    }
    move_(&line_1.achar, &c__1, line_1.afield, &line_1.kntrc, &c__1);
/* L5: */
    for (i__ = 1; i__ <= 5; ++i__) {
	if (line_1.achar == adelim[i__ - 1]) {
	    goto L20;
	}
/* L10: */
    }

/*  NON-DELIMITER */

    ret_val = 1;
    return ret_val;

/*  DELIMITER */

L20:
    ret_val = 0;
    return ret_val;

/*  END-OF-LINE */

L30:
    ret_val = -1;
    line_1.achar = ablnk;
    return ret_val;
} /* nxtchr_ */

#undef ablnk
#undef adelim


/* SPICE VERSION 2G.6  SCCSID=errchk.ma 3/15/83 */
/* Subroutine */ int errchk_(void)
{
    /* Initialized data */

    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_783 = { "TRAP    GEAR    ", 0. };

#define aname ((doublereal *)&equiv_783)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_784 = { "OPTION SUMMARY                  ", 0. };

#define titlop ((doublereal *)&equiv_784)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_785 = { ".U  ", 0 };

#define ndefin (*(integer *)&equiv_785)

    static integer nnods[50] = { 2,2,2,0,2,2,2,2,2,2,2,4,3,4,0,0,4,0,1,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0 };
    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_786 = { "ELEMENT ", 0. };

#define aelmt (*(doublereal *)&equiv_786)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_787 = { "MODEL   ", 0. };

#define amodel (*(doublereal *)&equiv_787)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_788 = { "OUTPUT  ", 0. };

#define aoutpt (*(doublereal *)&equiv_788)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_789 = { "DC      ", 0. };

#define alsdc (*(doublereal *)&equiv_789)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_790 = { "TRAN    ", 0. };

#define alstr (*(doublereal *)&equiv_790)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_791 = { "AC      ", 0. };

#define alsac (*(doublereal *)&equiv_791)


    /* Format strings */
    static char fmt_41[] = "(\0020*ERROR*:  \002,2a8,\002 HAS BEEN REFERENCE"
	    "D BUT NOT DEFINED\002/)";
    static char fmt_321[] = "(\0020*ERROR*:  CIRCUIT HAS NO NODES\002/)";
    static char fmt_661[] = "(\0020*ERROR*:  ELEMENT \002,a8,\002 PIECEWISE "
	    "LINEAR SOURCE TABLE NOT INCREASING IN TIME\002)";
    static char fmt_1601[] = "(\0020DC ANALYSIS -\002,/,\0020    GMIN   ="
	    " \002,1pd10.3,/,\002     RELTOL = \002,d10.3,/,\002     ABSTOL = "
	    "\002,d10.3,/,\002     VNTOL  = \002,d10.3,/,\002     LVLCOD ="
	    " \002,i6,/,\002     ITL1   = \002,i6,/,\002     ITL2   = \002,i6"
	    ",/)";
    static char fmt_1605[] = "(\002     PIVTOL = \002,1pd10.3,/,\002     PIV"
	    "REL = \002,d10.3)";
    static char fmt_1611[] = "(\0020TRANSIENT ANALYSIS -\002,/,\0020    METH"
	    "OD =  \002,a8,/,\002     MAXORD = \002,i6,/,\002     CHGTOL ="
	    " \002,1pd10.3,/,\002     TRTOL  = \002,d10.3,/,\002     LVLTIM = "
	    "\002,i6,/,\002     MU     = \002,0pf10.3,/,\002     ITL3   = "
	    "\002,i6,/,\002     ITL4   = \002,i6,/,\002     ITL5   = \002,i6,"
	    "/)";
    static char fmt_1621[] = "(\0020MISCELLANEOUS -\002,/,\0020    LIMPTS ="
	    " \002,i6,/,\002     LIMTIM = \002,i6,/,\002     CPTIME = \002,i9"
	    ",/,\002     NUMDGT = \002,i6,/,\002     TNOM   = \002,0pf10.3,/"
	    ",\002     DEFL   = \002,1pd10.3,/,\002     DEFW   = \002,d10.3,/,"
	    "\002     DEFAD  = \002,d10.3,/,\002     DEFAS  = \002,d10.3)";
    static char fmt_1701[] = "(\0020WARNING:  MORE THAN \002,i5,\002 POINTS "
	    "FOR \002,a4,\002 ANALYSIS,\002,/1x,\002ANALYSIS OMITTED.  THIS L"
	    "IMIT MAY BE OVERRIDDEN USING THE \002,/1x,\002LIMPTS PARAMETER O"
	    "N THE .OPTION CARD\002/)";
    static char fmt_1711[] = "(\0020WARNING:  NO \002,a4,\002 OUTPUTS SPECIF"
	    "IED .\002,\002.. ANALYSIS OMITTED\002/)";
    static char fmt_1736[] = "(\0020WARNING:  FOURIER ANALYSIS FUNDAMENTAL F"
	    "REQUENCY IS INCOMPATIBLE WITH\002/11x,\002TRANSIENT ANALYSIS PRI"
	    "NT INTERVAL ... FOURIER ANALYSIS OMITTED\002/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal t1, t2;
    static integer id;
    static doublereal td;
    static integer nl1, nl2, nic, loc;
    static doublereal tol, anam;
    extern /* Subroutine */ int find_(doublereal *, integer *, integer *, 
	    integer *);
    static integer node, ibkp, locp, locv;
    static doublereal temp;
    static integer iknt, nump, node1, node2, node3, node4;
    extern /* Subroutine */ int getm4_(integer *, integer *), getm8_(integer *
	    , integer *), copy4_(integer *, integer *, integer *);
    static integer lptr1, lptr2;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static integer nbkpt, jstop, jtype, ntemp;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *), modchk_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int second_(doublereal *), putnod_(integer *);
    static integer nssnod;
    extern /* Subroutine */ int sizmem_(integer *, integer *), getnod_(
	    integer *), subckt_(void), lnkref_(void), subnam_(integer *), 
	    clrmem_(integer *), relmem_(integer *, integer *), elprnt_(void), 
	    topchk_(void), extmem_(integer *, integer *), shlsrt_(doublereal *
	    , integer *);
    static doublereal forprd;
    static integer ifwdth, noprln, noprex, locnew;

    /* Fortran I/O blocks */
    static cilist io___739 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___746 = { 0, 0, 0, fmt_321, 0 };
    static cilist io___756 = { 0, 0, 0, fmt_661, 0 };
    static cilist io___766 = { 0, 0, 0, fmt_1601, 0 };
    static cilist io___767 = { 0, 0, 0, fmt_1605, 0 };
    static cilist io___768 = { 0, 0, 0, fmt_1611, 0 };
    static cilist io___769 = { 0, 0, 0, fmt_1621, 0 };
    static cilist io___770 = { 0, 0, 0, fmt_1701, 0 };
    static cilist io___771 = { 0, 0, 0, fmt_1711, 0 };
    static cilist io___772 = { 0, 0, 0, fmt_1701, 0 };
    static cilist io___773 = { 0, 0, 0, fmt_1711, 0 };
    static cilist io___775 = { 0, 0, 0, fmt_1736, 0 };
    static cilist io___776 = { 0, 0, 0, fmt_1701, 0 };
    static cilist io___777 = { 0, 0, 0, fmt_1711, 0 };




/*     THIS ROUTINE DRIVES THE PRE-PROCESSING AND GENERAL ERROR-CHECKING */
/* OF INPUT PERFORMED BY SPICE. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    second_(&t1);
    for (id = 1; id <= 50; ++id) {
	loc = cirdat_1.locate[id - 1];
L10:
	if (loc == 0) {
	    goto L60;
	}
	if (nodplc[loc + 1] != ndefin) {
	    goto L50;
	}
	flags_1.nogo = 1;
	locv = nodplc[loc];
	if (id >= 21) {
	    goto L20;
	}
	anam = aelmt;
	goto L40;
L20:
	if (id >= 31) {
	    goto L30;
	}
	anam = amodel;
	goto L40;
L30:
	anam = aoutpt;
L40:
	io___739.ciunit = status_1.iofile;
	s_wsfe(&io___739);
	do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
L50:
	loc = nodplc[loc - 1];
	goto L10;
L60:
	;
    }
    if (flags_1.nogo != 0) {
	goto L2000;
    }

/*  CONSTRUCT ORDERED LIST OF USER SPECIFIED NODES */

    getm4_(&tabinf_1.junode, &c__1);
    nodplc[tabinf_1.junode] = 0;
    cirdat_1.nunods = 1;
    for (id = 1; id <= 50; ++id) {
	if (nnods[id - 1] == 0) {
	    goto L180;
	}
	loc = cirdat_1.locate[id - 1];
L110:
	if (loc == 0) {
	    goto L180;
	}
	if (id <= 4) {
	    goto L120;
	}
	if (id <= 8) {
	    goto L150;
	}
	if (id == 19) {
	    goto L165;
	}
	if (id <= 40) {
	    goto L120;
	}
	if (id <= 43) {
	    goto L170;
	}
L120:
	jstop = loc + nnods[id - 1] - 1;
	i__1 = jstop;
	for (j = loc; j <= i__1; ++j) {
	    putnod_(&nodplc[j + 1]);
/* L130: */
	}
	goto L170;
L150:
	putnod_(&nodplc[loc + 1]);
	putnod_(&nodplc[loc + 2]);
	if (id >= 7) {
	    goto L170;
	}
	locp = nodplc[loc + id];
	nssnod = nodplc[loc + 3] << 1;
L155:
	i__1 = nssnod;
	for (j = 1; j <= i__1; ++j) {
	    putnod_(&nodplc[locp + j - 1]);
/* L160: */
	}
	goto L170;
L165:
	locp = nodplc[loc + 1];
	sizmem_(&nodplc[loc + 1], &nssnod);
	goto L155;
L170:
	loc = nodplc[loc - 1];
	goto L110;
L180:
	;
    }
    if (flags_1.nogo != 0) {
	goto L2000;
    }
    cirdat_1.ncnods = cirdat_1.nunods;

/*  ASSIGN PROGRAM NODES */

/* L200: */
    for (id = 1; id <= 50; ++id) {
	if (nnods[id - 1] == 0) {
	    goto L280;
	}
	loc = cirdat_1.locate[id - 1];
L210:
	if (loc == 0) {
	    goto L280;
	}
	if (id <= 4) {
	    goto L220;
	}
	if (id <= 8) {
	    goto L250;
	}
	if (id == 19) {
	    goto L265;
	}
	if (id <= 40) {
	    goto L220;
	}
	if (id <= 43) {
	    goto L240;
	}
L220:
	jstop = loc + nnods[id - 1] - 1;
	i__1 = jstop;
	for (j = loc; j <= i__1; ++j) {
	    getnod_(&nodplc[j + 1]);
/* L230: */
	}
	goto L270;
L240:
	if (nodplc[loc + 4] == 0) {
	    goto L220;
	}
	goto L270;
L250:
	getnod_(&nodplc[loc + 1]);
	getnod_(&nodplc[loc + 2]);
	if (id >= 7) {
	    goto L270;
	}
	locp = nodplc[loc + id];
	nssnod = nodplc[loc + 3] << 1;
L255:
	i__1 = nssnod;
	for (j = 1; j <= i__1; ++j) {
	    getnod_(&nodplc[locp + j - 1]);
/* L260: */
	}
	goto L270;
L265:
	locp = nodplc[loc + 1];
	sizmem_(&nodplc[loc + 1], &nssnod);
	goto L255;
L270:
	loc = nodplc[loc - 1];
	goto L210;
L280:
	;
    }

/*  CHECK AND SET .NODESET NODES TO THEIR INTERNAL VALUES */

    sizmem_(&tabinf_1.nsnod, &nic);
    if (nic == 0) {
	goto L300;
    }
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	getnod_(&nodplc[tabinf_1.nsnod + i__ - 1]);
/* L290: */
    }

/*   CHECK AND SET .IC NODES TO THEIR INTERNAL VALUES */

L300:
    sizmem_(&tabinf_1.icnod, &nic);
    if (nic == 0) {
	goto L320;
    }
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	getnod_(&nodplc[tabinf_1.icnod + i__ - 1]);
/* L310: */
    }
L320:
    if (flags_1.nogo != 0) {
	goto L2000;
    }

/*  EXPAND SUBCIRCUIT CALLS */

    subckt_();
    if (flags_1.nogo != 0) {
	goto L2000;
    }
    if (cirdat_1.ncnods >= 2) {
	goto L400;
    }
    io___746.ciunit = status_1.iofile;
    s_wsfe(&io___746);
    e_wsfe();
    flags_1.nogo = 1;
    goto L2000;
L400:
    cirdat_1.numnod = cirdat_1.ncnods;

/*  LINK UNSATISFIED REFERENCES */

    lnkref_();
    if (flags_1.nogo != 0) {
	goto L2000;
    }

/*  GENERATE SUBCIRCUIT ELEMENT NAMES */

    if (cirdat_1.jelcnt[18] == 0) {
	goto L530;
    }
    for (id = 1; id <= 24; ++id) {
	loc = cirdat_1.locate[id - 1];
L510:
	if (loc == 0) {
	    goto L520;
	}
	subnam_(&loc);
	loc = nodplc[loc - 1];
	goto L510;
L520:
	;
    }

/*  TRANSLATE NODE INITIAL CONDITIONS TO DEVICE INITIAL CONDITIONS */
/*  (CAPACITANCE, DIODE, BJT, JFET AND MOSFET ONLY) WHEN UIC IS */
/*  SPECIFIED ON THE .TRAN CARD */

L530:
    if (status_1.nosolv <= 0) {
	goto L600;
    }
    sizmem_(&tabinf_1.icnod, &nic);
    if (nic == 0) {
	goto L600;
    }
    getm8_(&tabinf_1.lvnim1, &cirdat_1.numnod);
    zero8_(&blank_1.value[tabinf_1.lvnim1], &cirdat_1.numnod);
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = nodplc[tabinf_1.icnod + i__ - 1];
/* L535: */
	blank_1.value[tabinf_1.lvnim1 + node - 1] = blank_1.value[
		tabinf_1.icval + i__ - 1];
    }
    loc = cirdat_1.locate[1];
L540:
    if (loc == 0) {
	goto L550;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv + 1] != 0.) {
	goto L545;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    blank_1.value[locv + 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node2 - 1];
L545:
    loc = nodplc[loc - 1];
    goto L540;
L550:
    loc = cirdat_1.locate[10];
L555:
    if (loc == 0) {
	goto L565;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv + 1] != 0.) {
	goto L560;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    blank_1.value[locv + 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node2 - 1];
L560:
    loc = nodplc[loc - 1];
    goto L555;
L565:
    loc = cirdat_1.locate[11];
L570:
    if (loc == 0) {
	goto L580;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    if (blank_1.value[locv + 1] == 0.) {
	blank_1.value[locv + 1] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    if (blank_1.value[locv + 2] == 0.) {
	blank_1.value[locv + 2] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    loc = nodplc[loc - 1];
    goto L570;
L580:
    loc = cirdat_1.locate[12];
L585:
    if (loc == 0) {
	goto L590;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    if (blank_1.value[locv + 1] == 0.) {
	blank_1.value[locv + 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    if (blank_1.value[locv + 2] == 0.) {
	blank_1.value[locv + 2] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    loc = nodplc[loc - 1];
    goto L585;
L590:
    loc = cirdat_1.locate[13];
L595:
    if (loc == 0) {
	goto L598;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    if (blank_1.value[locv + 4] == 0.) {
	blank_1.value[locv + 4] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    if (blank_1.value[locv + 5] == 0.) {
	blank_1.value[locv + 5] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    if (blank_1.value[locv + 6] == 0.) {
	blank_1.value[locv + 6] = blank_1.value[tabinf_1.lvnim1 + node4 - 1] 
		- blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    }
    loc = nodplc[loc - 1];
    goto L595;
L598:
    clrmem_(&tabinf_1.lvnim1);

/*  PROCESS SOURCES */

L600:
    if (tran_1.jtrflg == 0) {
	goto L700;
    }
    for (id = 9; id <= 10; ++id) {
	loc = cirdat_1.locate[id - 1];
L610:
	if (loc == 0) {
	    goto L690;
	}
	locv = nodplc[loc];
	locp = nodplc[loc + 4];
	jtype = nodplc[loc + 3] + 1;
	switch (jtype) {
	    case 1:  goto L680;
	    case 2:  goto L620;
	    case 3:  goto L630;
	    case 4:  goto L640;
	    case 5:  goto L650;
	    case 6:  goto L675;
	}
L620:
/* Computing MAX */
	d__1 = blank_1.value[locp + 2];
	blank_1.value[locp + 2] = max(d__1,0.);
	if (blank_1.value[locp + 3] <= 0.) {
	    blank_1.value[locp + 3] = tran_1.tstep;
	}
	if (blank_1.value[locp + 4] <= 0.) {
	    blank_1.value[locp + 4] = tran_1.tstep;
	}
	if (blank_1.value[locp + 5] <= 0.) {
	    blank_1.value[locp + 5] = tran_1.tstop;
	}
	if (blank_1.value[locp + 6] <= 0.) {
	    blank_1.value[locp + 6] = tran_1.tstop;
	}
	temp = blank_1.value[locp + 3] + blank_1.value[locp + 4] + 
		blank_1.value[locp + 5];
/* Computing MAX */
	d__1 = blank_1.value[locp + 6];
	blank_1.value[locp + 6] = max(d__1,temp);
	blank_1.value[locv] = blank_1.value[locp];
	goto L680;
L630:
	if (blank_1.value[locp + 2] <= 0.) {
	    blank_1.value[locp + 2] = 1. / tran_1.tstop;
	}
/* Computing MAX */
	d__1 = blank_1.value[locp + 3];
	blank_1.value[locp + 3] = max(d__1,0.);
	blank_1.value[locv] = blank_1.value[locp];
	goto L680;
L640:
/* Computing MAX */
	d__1 = blank_1.value[locp + 2];
	blank_1.value[locp + 2] = max(d__1,0.);
	if (blank_1.value[locp + 3] <= 0.) {
	    blank_1.value[locp + 3] = tran_1.tstep;
	}
	if (blank_1.value[locp + 4] <= blank_1.value[locp + 2]) {
	    blank_1.value[locp + 4] = blank_1.value[locp + 2] + tran_1.tstep;
	}
	if (blank_1.value[locp + 5] <= 0.) {
	    blank_1.value[locp + 5] = tran_1.tstep;
	}
	blank_1.value[locv] = blank_1.value[locp];
	goto L680;
L650:
/* Computing MIN */
/* Computing MAX */
	d__2 = blank_1.value[locp];
	d__1 = max(d__2,0.);
	blank_1.value[locp] = min(d__1,tran_1.tstop);
	iknt = 1;
	sizmem_(&nodplc[loc + 4], &nump);
L660:
	temp = blank_1.value[locp + iknt - 1];
	if (blank_1.value[locp + iknt + 1] == 0.) {
	    goto L670;
	}
	if (blank_1.value[locp + iknt + 1] >= tran_1.tstop) {
	    goto L670;
	}
/* Computing MAX */
	d__1 = blank_1.value[locp + iknt + 1];
	blank_1.value[locp + iknt + 1] = max(d__1,temp);
	if (temp != blank_1.value[locp + iknt + 1]) {
	    goto L665;
	}
	io___756.ciunit = status_1.iofile;
	s_wsfe(&io___756);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	flags_1.nogo = 1;
L665:
	iknt += 2;
	if (iknt < nump) {
	    goto L660;
	}
L670:
	blank_1.value[locp + iknt + 1] = tran_1.tstop;
	blank_1.value[locv] = blank_1.value[locp + 1];
	i__1 = nump - iknt - 3;
	relmem_(&nodplc[loc + 4], &i__1);
	goto L680;
L675:
	if (blank_1.value[locp + 2] <= 0.) {
	    blank_1.value[locp + 2] = 1. / tran_1.tstop;
	}
	if (blank_1.value[locp + 4] <= 0.) {
	    blank_1.value[locp + 4] = 1. / tran_1.tstop;
	}
	blank_1.value[locv] = blank_1.value[locp];
L680:
	loc = nodplc[loc - 1];
	goto L610;
L690:
	;
    }

/*  USE DEFAULT VALUES FOR MOS DEVICE GEOMETRIES IF NOT SPECIFIED */

L700:
    loc = cirdat_1.locate[13];
L710:
    if (loc == 0) {
	goto L720;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv] <= 0.) {
	blank_1.value[locv] = miscel_1.defl;
    }
    if (blank_1.value[locv + 1] <= 0.) {
	blank_1.value[locv + 1] = miscel_1.defw;
    }
    if (blank_1.value[locv + 2] <= 0.) {
	blank_1.value[locv + 2] = miscel_1.defad;
    }
    if (blank_1.value[locv + 3] <= 0.) {
	blank_1.value[locv + 3] = miscel_1.defas;
    }
    loc = nodplc[loc - 1];
    goto L710;

/*  PRINT LISTING OF ELEMENTS, PROCESS DEVICE MODELS, */
/*  AND CHECK TOPOLOGY */

L720:
    if (flags_1.iprntl == 0) {
	goto L730;
    }
    elprnt_();
L730:
    topchk_();
    modchk_();
    if (flags_1.nogo != 0) {
	goto L2000;
    }

/*  INVERT RESISTANCE VALUES */

/* L800: */
    loc = cirdat_1.locate[0];
L810:
    if (loc == 0) {
	goto L900;
    }
    locv = nodplc[loc];
    blank_1.value[locv] = 1. / blank_1.value[locv + 1];
    loc = nodplc[loc - 1];
    goto L810;

/*  PROCESS MUTUAL INDUCTORS */

L900:
    loc = cirdat_1.locate[3];
L910:
    if (loc == 0) {
	goto L1000;
    }
    locv = nodplc[loc];
    nl1 = nodplc[loc + 1];
    lptr1 = nodplc[nl1];
    nl2 = nodplc[loc + 2];
    lptr2 = nodplc[nl2];
    blank_1.value[locv] *= sqrt(blank_1.value[lptr1] * blank_1.value[lptr2]);
    loc = nodplc[loc - 1];
    goto L910;

/*  LIMIT DELMAX  IF TRANSMISSION LINES IN CIRCUIT */

L1000:
    if (tran_1.jtrflg == 0) {
	goto L1200;
    }
    tran_1.tdmax = 0.;
    loc = cirdat_1.locate[16];
L1010:
    if (loc == 0) {
	goto L1200;
    }
    locv = nodplc[loc];
/* Computing MIN */
    d__1 = tran_1.delmax, d__2 = blank_1.value[locv + 1] / 2.;
    tran_1.delmax = min(d__1,d__2);
/* Computing MAX */
    d__1 = tran_1.tdmax, d__2 = blank_1.value[locv + 1];
    tran_1.tdmax = max(d__1,d__2);
    loc = nodplc[loc - 1];
    goto L1010;

/*  PROCESS SOURCE PARAMETERS */

L1200:
    tabinf_1.numbkp = 0;
    if (tran_1.jtrflg == 0) {
	goto L1205;
    }
    tol = tran_1.delmax * .01;
    tabinf_1.numbkp = 2;
    getm8_(&tabinf_1.lsbkpt, &tabinf_1.numbkp);
    blank_1.value[tabinf_1.lsbkpt] = 0.;
    blank_1.value[tabinf_1.lsbkpt + 1] = tran_1.tstop;
L1205:
    for (id = 9; id <= 10; ++id) {
	loc = cirdat_1.locate[id - 1];
L1210:
	if (loc == 0) {
	    goto L1290;
	}
	locv = nodplc[loc];
	locp = nodplc[loc + 4];
	temp = blank_1.value[locv + 2] / knstnt_1.rad;
	blank_1.value[locv + 2] = blank_1.value[locv + 1] * sin(temp);
	blank_1.value[locv + 1] *= cos(temp);
	if (tran_1.jtrflg == 0) {
	    goto L1280;
	}
	jtype = nodplc[loc + 3] + 1;
	switch (jtype) {
	    case 1:  goto L1280;
	    case 2:  goto L1220;
	    case 3:  goto L1230;
	    case 4:  goto L1235;
	    case 5:  goto L1240;
	    case 6:  goto L1260;
	}
L1220:
	blank_1.value[locp + 3] += blank_1.value[locp + 2];
	temp = blank_1.value[locp + 4];
	blank_1.value[locp + 4] = blank_1.value[locp + 3] + blank_1.value[
		locp + 5];
	blank_1.value[locp + 5] = blank_1.value[locp + 4] + temp;
	status_1.time = 0.;
L1225:
	extmem_(&tabinf_1.lsbkpt, &c__4);
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = blank_1.value[locp 
		+ 2] + status_1.time;
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp + 1] = blank_1.value[
		locp + 3] + status_1.time;
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp + 2] = blank_1.value[
		locp + 4] + status_1.time;
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp + 3] = blank_1.value[
		locp + 5] + status_1.time;
	tabinf_1.numbkp += 4;
	status_1.time += blank_1.value[locp + 6];
	if (status_1.time >= tran_1.tstop) {
	    goto L1280;
	}
	goto L1225;
L1230:
	blank_1.value[locp + 2] *= knstnt_1.twopi;
	extmem_(&tabinf_1.lsbkpt, &c__1);
/* L1231: */
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = blank_1.value[locp 
		+ 3];
	++tabinf_1.numbkp;
	goto L1280;
L1235:
	extmem_(&tabinf_1.lsbkpt, &c__2);
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = blank_1.value[locp 
		+ 2];
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp + 1] = blank_1.value[
		locp + 4];
	tabinf_1.numbkp += 2;
	goto L1280;
L1240:
	iknt = 1;
	sizmem_(&nodplc[loc + 4], &nump);
L1250:
	extmem_(&tabinf_1.lsbkpt, &c__1);
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = blank_1.value[locp 
		+ iknt - 1];
	++tabinf_1.numbkp;
	iknt += 2;
	if (iknt <= nump) {
	    goto L1250;
	}
	goto L1280;
L1260:
	blank_1.value[locp + 2] *= knstnt_1.twopi;
	blank_1.value[locp + 4] *= knstnt_1.twopi;
L1280:
	loc = nodplc[loc - 1];
	goto L1210;
L1290:
	;
    }

/*  AUGMENT BREAKPOINT TABLE FOR TRANSMISSION LINE DELAYS */

    if (tran_1.jtrflg == 0) {
	goto L1300;
    }
    loc = cirdat_1.locate[16];
L1292:
    if (loc == 0) {
	goto L1300;
    }
    locv = nodplc[loc];
    td = blank_1.value[locv + 1];
    ntemp = tabinf_1.numbkp;
    i__1 = ntemp;
    for (ibkp = 1; ibkp <= i__1; ++ibkp) {
	status_1.time = blank_1.value[tabinf_1.lsbkpt + ibkp - 1];
L1294:
	status_1.time += td;
	if (status_1.time >= tran_1.tstop) {
	    goto L1296;
	}
	extmem_(&tabinf_1.lsbkpt, &c__1);
	blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = status_1.time;
	++tabinf_1.numbkp;
	goto L1294;
L1296:
	;
    }
    shlsrt_(&blank_1.value[tabinf_1.lsbkpt], &tabinf_1.numbkp);
    nbkpt = 1;
    i__1 = tabinf_1.numbkp;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (blank_1.value[tabinf_1.lsbkpt + i__ - 1] - blank_1.value[
		tabinf_1.lsbkpt + nbkpt - 1] < tol) {
	    goto L1298;
	}
	++nbkpt;
	blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] = blank_1.value[
		tabinf_1.lsbkpt + i__ - 1];
	if (blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] >= tran_1.tstop) {
	    goto L1299;
	}
L1298:
	;
    }
L1299:
    i__1 = tabinf_1.numbkp - nbkpt;
    relmem_(&tabinf_1.lsbkpt, &i__1);
    tabinf_1.numbkp = nbkpt;
/* Computing MAX */
    d__1 = blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp - 1];
    blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp - 1] = max(d__1,
	    tran_1.tstop);
    loc = nodplc[loc - 1];
    goto L1292;

/*  FINISH BREAKPOINT TABLE */

L1300:
    if (tran_1.jtrflg == 0) {
	goto L1600;
    }
    extmem_(&tabinf_1.lsbkpt, &c__1);
    blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp] = tran_1.tstop;
    ++tabinf_1.numbkp;
    shlsrt_(&blank_1.value[tabinf_1.lsbkpt], &tabinf_1.numbkp);
    nbkpt = 1;
    i__1 = tabinf_1.numbkp;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (blank_1.value[tabinf_1.lsbkpt + i__ - 1] - blank_1.value[
		tabinf_1.lsbkpt + nbkpt - 1] < tol) {
	    goto L1310;
	}
	++nbkpt;
	blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] = blank_1.value[
		tabinf_1.lsbkpt + i__ - 1];
	if (blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] >= tran_1.tstop) {
	    goto L1320;
	}
L1310:
	;
    }
L1320:
    i__1 = tabinf_1.numbkp - nbkpt;
    relmem_(&tabinf_1.lsbkpt, &i__1);
    tabinf_1.numbkp = nbkpt;
/* Computing MAX */
    d__1 = blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp - 1];
    blank_1.value[tabinf_1.lsbkpt + tabinf_1.numbkp - 1] = max(d__1,
	    tran_1.tstop);

/*  PRINT OPTION SUMMARY */

L1600:
    if (flags_1.iprnto == 0) {
	goto L1700;
    }
    title_(&c__0, &miscel_1.lwidth, &c__1, titlop);
    io___766.ciunit = status_1.iofile;
    s_wsfe(&io___766);
    do_fio(&c__1, (char *)&knstnt_1.gmin, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&knstnt_1.reltol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&knstnt_1.abstol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&knstnt_1.vntol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&flags_1.lvlcod, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.itl1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.itl2, (ftnlen)sizeof(integer));
    e_wsfe();
    io___767.ciunit = status_1.iofile;
    s_wsfe(&io___767);
    do_fio(&c__1, (char *)&knstnt_1.pivtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&knstnt_1.pivrel, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___768.ciunit = status_1.iofile;
    s_wsfe(&io___768);
    do_fio(&c__1, (char *)&aname[status_1.method - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&status_1.maxord, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&knstnt_1.chgtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&knstnt_1.trtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&flags_1.lvltim, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&status_1.xmu, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&flags_1.itl3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.itl4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.itl5, (ftnlen)sizeof(integer));
    e_wsfe();
    io___769.ciunit = status_1.iofile;
    s_wsfe(&io___769);
    do_fio(&c__1, (char *)&flags_1.limpts, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&flags_1.limtim, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&cje_1.maxtim, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&outinf_1.numdgt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[tabinf_1.itemps], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&miscel_1.defl, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.defw, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.defad, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&miscel_1.defas, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  MISCELLANEOUS ERROR CHECKING */

L1700:
    if (dc_1.icvflg == 0) {
	goto L1720;
    }
    if (dc_1.icvflg <= flags_1.limpts) {
	goto L1710;
    }
    dc_1.icvflg = 0;
    io___770.ciunit = status_1.iofile;
    s_wsfe(&io___770);
    do_fio(&c__1, (char *)&flags_1.limpts, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&alsdc, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1720;
L1710:
    if (cirdat_1.jelcnt[30] + cirdat_1.jelcnt[35] > 0) {
	goto L1720;
    }
    if (status_1.ipostp != 0) {
	goto L1720;
    }
    dc_1.icvflg = 0;
    io___771.ciunit = status_1.iofile;
    s_wsfe(&io___771);
    do_fio(&c__1, (char *)&alsdc, (ftnlen)sizeof(doublereal));
    e_wsfe();
L1720:
    if (tran_1.jtrflg == 0) {
	goto L1740;
    }
    if (status_1.method == 1) {
	status_1.maxord = 2;
    }
    if (status_1.method == 2 && status_1.maxord >= 3) {
	flags_1.lvltim = 2;
    }
    if (tran_1.jtrflg <= flags_1.limpts) {
	goto L1730;
    }
    tran_1.jtrflg = 0;
    io___772.ciunit = status_1.iofile;
    s_wsfe(&io___772);
    do_fio(&c__1, (char *)&flags_1.limpts, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&alstr, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1740;
L1730:
    if (cirdat_1.jelcnt[31] + cirdat_1.jelcnt[36] + tabinf_1.nfour > 0) {
	goto L1735;
    }
    if (status_1.ipostp != 0) {
	goto L1735;
    }
    tran_1.jtrflg = 0;
    io___773.ciunit = status_1.iofile;
    s_wsfe(&io___773);
    do_fio(&c__1, (char *)&alstr, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1740;
L1735:
    if (tabinf_1.nfour == 0) {
	goto L1740;
    }
    forprd = 1. / tran_1.forfre;
    if (tran_1.tstop - forprd >= tran_1.tstart - 1e-12) {
	goto L1740;
    }
    tabinf_1.nfour = 0;
    clrmem_(&tabinf_1.ifour);
    io___775.ciunit = status_1.iofile;
    s_wsfe(&io___775);
    e_wsfe();
L1740:
    if (ac_1.jacflg == 0) {
	goto L1800;
    }
    if (ac_1.jacflg <= flags_1.limpts) {
	goto L1750;
    }
    ac_1.jacflg = 0;
    io___776.ciunit = status_1.iofile;
    s_wsfe(&io___776);
    do_fio(&c__1, (char *)&flags_1.limpts, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&alsac, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1800;
L1750:
    if (cirdat_1.jelcnt[32] + cirdat_1.jelcnt[33] + cirdat_1.jelcnt[34] + 
	    cirdat_1.jelcnt[37] + cirdat_1.jelcnt[38] + cirdat_1.jelcnt[39] + 
	    ac_1.idist + ac_1.inoise > 0) {
	goto L1800;
    }
    if (status_1.ipostp != 0) {
	goto L1800;
    }
    ac_1.jacflg = 0;
    io___777.ciunit = status_1.iofile;
    s_wsfe(&io___777);
    do_fio(&c__1, (char *)&alsac, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  SEQUENCE THROUGH THE OUTPUT LISTS */

L1800:
    for (id = 41; id <= 45; ++id) {
	if (id <= 43) {
	    outinf_1.numout = 1;
	}
	loc = cirdat_1.locate[id - 1];
L1810:
	if (loc == 0) {
	    goto L1820;
	}
	++outinf_1.numout;
	nodplc[loc + 3] = outinf_1.numout;
	loc = nodplc[loc - 1];
	goto L1810;
L1820:
	;
    }

/*   INCREASE NUMBER OF .PRINTS IF TOO MANY OUTPUTS FOR OUTPUT LINE-WIDTH */

/* Computing MAX */
    i__1 = outinf_1.numdgt - 1;
    ifwdth = max(i__1,0) + 9;
/* Computing MIN */
    i__1 = 8, i__2 = (miscel_1.lwidth - 12) / ifwdth;
    noprln = min(i__1,i__2);
    for (id = 31; id <= 35; ++id) {
	loc = cirdat_1.locate[id - 1];
L1830:
	if (loc == 0) {
	    goto L1860;
	}
	noprex = nodplc[loc + 2] - noprln;
	if (noprex <= 0) {
	    goto L1850;
	}
	nodplc[loc + 2] = noprln;
	d__1 = (doublereal) cirdat_1.jelcnt[id - 1];
	find_(&d__1, &id, &locnew, &c__1);
	nodplc[locnew + 1] = nodplc[loc + 1];
	nodplc[locnew + 2] = noprex;
	i__1 = noprex << 1;
	copy4_(&nodplc[loc + (noprln << 1) + 3], &nodplc[locnew + 3], &i__1);
L1850:
	loc = nodplc[loc - 1];
	goto L1830;
L1860:
	;
    }

/*  EXIT */

L2000:
    second_(&t2);
    miscel_1.rstats[0] = miscel_1.rstats[0] + t2 - t1;
    return 0;
} /* errchk_ */

#undef cvalue
#undef nodplc
#undef alsac
#undef alstr
#undef alsdc
#undef aoutpt
#undef amodel
#undef aelmt
#undef ndefin
#undef titlop
#undef aname


/* Subroutine */ int shlsrt_(doublereal *a, integer *n)
{
    static integer h__, i__, j;
    static doublereal ak, ar;


/*     THIS ROUTINE SORTS THE ARRAY A USING A SHELL SORT ALGORITHM. */



/* ...  COMPUTE BEST STARTING STEP SIZE */
    /* Parameter adjustments */
    --a;

    /* Function Body */
    h__ = 1;
L10:
    h__ = h__ * 3 + 1;
    if (h__ < *n) {
	goto L10;
    }
/* ...  BACK OFF TWO TIMES */
    h__ = (h__ - 1) / 3;
    h__ = (h__ - 1) / 3;
    h__ = max(h__,1);

/*  SHELL SORT */

L20:
    j = h__ + 1;
    goto L60;
L30:
    i__ = j - h__;
/* ...  AK = RECORD KEY;  AR = RECORD */
    ak = a[j];
    ar = ak;
L40:
    if (ak >= a[i__]) {
	goto L50;
    }
    a[i__ + h__] = a[i__];
    i__ -= h__;
    if (i__ >= 1) {
	goto L40;
    }
L50:
    a[i__ + h__] = ar;
    ++j;
L60:
    if (j <= *n) {
	goto L30;
    }
    h__ = (h__ - 1) / 3;
    if (h__ != 0) {
	goto L20;
    }
    return 0;
} /* shlsrt_ */

/* Subroutine */ int putnod_(integer *node)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k, jknt;
    extern /* Subroutine */ int copy4_(integer *, integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int extmem_(integer *, integer *);


/*     THIS ROUTINE ADDS 'NODE' TO THE LIST OF USER INPUT NODES IN TABLE */
/* JUNODE. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    jknt = 0;
L10:
    ++jknt;
    if (jknt > cirdat_1.nunods) {
	goto L20;
    }
    if ((i__1 = *node - nodplc[tabinf_1.junode + jknt - 1]) < 0) {
	goto L20;
    } else if (i__1 == 0) {
	goto L100;
    } else {
	goto L10;
    }
L20:
    k = cirdat_1.nunods + 1;
    extmem_(&tabinf_1.junode, &c__1);
    if (k <= jknt) {
	goto L30;
    }
    i__1 = k - jknt;
    copy4_(&nodplc[tabinf_1.junode + jknt - 1], &nodplc[tabinf_1.junode + 
	    jknt], &i__1);
    k = jknt;
L30:
    nodplc[tabinf_1.junode + k - 1] = *node;
    ++cirdat_1.nunods;

/*  FINISHED */

L100:
    return 0;
} /* putnod_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int getnod_(integer *node)
{
    /* Format strings */
    static char fmt_21[] = "(\0020WARNING:  ATTEMPT TO REFERENCE UNDEFINED N"
	    "ODE \002,i5,\002 -- NODE RESET TO 0\002/)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer jknt;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

    /* Fortran I/O blocks */
    static cilist io___804 = { 0, 0, 0, fmt_21, 0 };



/*     THIS ROUTINE CONVERTS FROM THE USER NODE NUMBER TO THE INTERNAL */
/* (COMPACT) NODE NUMBER. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */


    if (flags_1.nogo != 0) {
	goto L100;
    }
    jknt = 0;
L10:
    ++jknt;
    if (jknt > cirdat_1.nunods) {
	goto L20;
    }
    if (nodplc[tabinf_1.junode + jknt - 1] != *node) {
	goto L10;
    }
    *node = jknt;
    goto L100;

/*  UNKNOWN NODE -- MUST BE IMPLIED BY .PRINT AND/OR .PLOT */

L20:
    if (*node == 0) {
	goto L30;
    }
    io___804.ciunit = status_1.iofile;
    s_wsfe(&io___804);
    do_fio(&c__1, (char *)&(*node), (ftnlen)sizeof(integer));
    e_wsfe();
L30:
    *node = 1;

/*  FINISHED */

L100:
    return 0;
} /* getnod_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int subckt_(void)
{
    /* Format strings */
    static char fmt_251[] = "(\0020*ERROR*:  \002,a8,\002 HAS DIFFERENT NUMB"
	    "ER OF NODES THAN \002,a8/)";
    static char fmt_261[] = "(\0020*ERROR*:  SUBCIRCUIT \002,a8,\002 IS DEFI"
	    "NED RECURSIVELY\002/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer id, loc;
    extern /* Subroutine */ int find_(doublereal *, integer *, integer *, 
	    integer *);
    static integer loce, locx, locs, locv;
    extern /* Subroutine */ int getm4_(integer *, integer *), copy4_(integer *
	    , integer *, integer *);
    static doublereal asnam;
    static integer inodi;
    static doublereal axnam;
    static integer itemp, nxnod, inodx, locsv;
    extern /* Subroutine */ int addelt_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), fndnam_(doublereal *, integer *,
	     integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer isbptr;
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    static integer nssnod;
    extern /* Subroutine */ int clrmem_(integer *);

    /* Fortran I/O blocks */
    static cilist io___821 = { 0, 0, 0, fmt_251, 0 };
    static cilist io___823 = { 0, 0, 0, fmt_261, 0 };



/*     THIS ROUTINE DRIVES THE EXPANSION OF SUBCIRCUIT CALLS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */


/* ... AVOID 'CALL BY VALUE' PROBLEMS, MAKE INODI, INODX ARRAYS */
/* ... IN ROUTINES WHICH RECEIVE THEM AS PARAMETERS ]]] */
    locx = cirdat_1.locate[18];
L10:
    if (locx == 0) {
	goto L300;
    }
    locs = nodplc[locx + 2];
    asnam = blank_1.value[tabinf_1.iunsat + locs - 1];
    i__1 = locx - 1;
    i__2 = locx + 3;
    fndnam_(&asnam, &i__1, &i__2, &c__20);
    if (flags_1.nogo != 0) {
	goto L300;
    }
    locs = nodplc[locx + 2];

/*  CHECK FOR RECURSION */

    isbptr = nodplc[locx - 2];
L20:
    if (isbptr == 0) {
	goto L30;
    }
    if (locs == nodplc[isbptr + 2]) {
	goto L260;
    }
    isbptr = nodplc[isbptr - 2];
    goto L20;


L30:
    sizmem_(&nodplc[locx + 1], &nxnod);
    sizmem_(&nodplc[locs + 1], &nssnod);
    if (nxnod != nssnod) {
	goto L250;
    }
    getm4_(&inodx, &nssnod);
    getm4_(&inodi, &nssnod);
    itemp = nodplc[locs + 1];
    copy4_(&nodplc[itemp], &nodplc[inodx], &nssnod);
    itemp = nodplc[locx + 1];
    copy4_(&nodplc[itemp], &nodplc[inodi], &nxnod);

/*  ADD ELEMENTS OF SUBCIRCUIT TO NOMINAL CIRCUIT */

    loc = nodplc[locs + 2];
L100:
    if (loc == 0) {
	goto L200;
    }
    id = nodplc[loc - 2];
    if (id == 20) {
	goto L110;
    }
    d__1 = (doublereal) cirdat_1.jelcnt[id - 1];
    find_(&d__1, &id, &loce, &c__1);
    nodplc[loce - 2] = locx;
    addelt_(&loce, &loc, &id, &inodx, &inodi, &nxnod);
L110:
    loc = nodplc[loc - 1];
    goto L100;


L200:
    clrmem_(&inodx);
    clrmem_(&inodi);
    locx = nodplc[locx - 1];
    goto L10;

/*  ERRORS */

L250:
    locv = nodplc[locx];
    axnam = blank_1.value[locv - 1];
    locv = nodplc[locs];
    asnam = blank_1.value[locv - 1];
    io___821.ciunit = status_1.iofile;
    s_wsfe(&io___821);
    do_fio(&c__1, (char *)&axnam, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&asnam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.nogo = 1;
    goto L300;
L260:
    locsv = nodplc[locs];
    asnam = blank_1.value[locsv - 1];
    io___823.ciunit = status_1.iofile;
    s_wsfe(&io___823);
    do_fio(&c__1, (char *)&asnam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.nogo = 1;

/*  FINISHED */

L300:
    return 0;
} /* subckt_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int fndnam_(doublereal *anam, integer *jsbptr, integer *
	ispot, integer *id)
{
    /* Format strings */
    static char fmt_91[] = "(\0020*ERROR*:  UNABLE TO FIND \002,a8/)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer loc, isub, locv;
    extern integer xxor_(doublereal *, doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer isbptr;

    /* Fortran I/O blocks */
    static cilist io___830 = { 0, 0, 0, fmt_91, 0 };



/*     THIS ROUTINE SEARCHES FOR AN ELEMENT WITH ID 'ID' BY TRACING BACK */
/* UP THE SUBCIRCUIT DEFINITION LIST.  IF THE ELEMENT IS NOT FOUND, THE */
/* NOMINAL ELEMENT LIST IS SEARCHED. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */


    isbptr = nodplc[*jsbptr - 1];
L10:
    if (isbptr == 0) {
	goto L50;
    }
    isub = nodplc[isbptr + 2];
    loc = nodplc[isub + 2];
L20:
    if (loc == 0) {
	goto L40;
    }
    if (*id != nodplc[loc - 2]) {
	goto L30;
    }
    locv = nodplc[loc];
    if (xxor_(anam, &blank_1.value[locv - 1]) != 0) {
	goto L30;
    }
    if (*id != 20) {
	goto L50;
    }
    goto L65;
L30:
    loc = nodplc[loc - 1];
    goto L20;
L40:
    isbptr = nodplc[isbptr - 2];
    goto L10;

L50:
    loc = cirdat_1.locate[*id - 1];
L60:
    if (loc == 0) {
	goto L90;
    }
    if (nodplc[loc - 2] != isbptr) {
	goto L70;
    }
    locv = nodplc[loc];
    if (xxor_(anam, &blank_1.value[locv - 1]) != 0) {
	goto L70;
    }
L65:
    nodplc[*ispot - 1] = loc;
    goto L100;
L70:
    loc = nodplc[loc - 1];
    goto L60;
L90:
    io___830.ciunit = status_1.iofile;
    s_wsfe(&io___830);
    do_fio(&c__1, (char *)&(*anam), (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.nogo = 1;
L100:
    return 0;
} /* fndnam_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int newnod_(integer *nodold, integer *nodnew, integer *inodx,
	 integer *inodi, integer *nnodi)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, jnodi, jnodx;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int extmem_(integer *, integer *);


/*     THIS ROUTINE MAKES A NEW NODE NUMBER FOR AN ELEMENT WHICH IS ABOUT */
/* TO BE ADDED TO THE CIRCUIT AS A RESULT OF A SUBCIRCUIT CALL. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/* ... INODX, INODI ARE ARRAYS (SEE SUBCKT) */

    /* Parameter adjustments */
    --inodi;
    --inodx;

    /* Function Body */
    if (*nodold != 0) {
	goto L5;
    }
    *nodnew = 1;
    goto L20;
L5:
    i__1 = *nnodi;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jnodx = inodx[1];
	if (*nodold != nodplc[jnodx + i__ - 1]) {
	    goto L10;
	}
	jnodi = inodi[1];
	*nodnew = nodplc[jnodi + i__ - 1];
	goto L20;
L10:
	;
    }

    extmem_(&inodx[1], &c__1);
    extmem_(&inodi[1], &c__1);
    extmem_(&tabinf_1.junode, &c__1);
    ++(*nnodi);
    ++cirdat_1.ncnods;
    jnodx = inodx[1];
    nodplc[jnodx + *nnodi - 1] = *nodold;
    jnodi = inodi[1];
    nodplc[jnodi + *nnodi - 1] = cirdat_1.ncnods;
    nodplc[tabinf_1.junode + cirdat_1.ncnods - 1] = nodplc[tabinf_1.junode + 
	    cirdat_1.ncnods - 2] + 1;
    *nodnew = cirdat_1.ncnods;
L20:
    return 0;
} /* newnod_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int addelt_(integer *loce, integer *loc, integer *id, 
	integer *inodx, integer *inodi, integer *nnodi)
{
    /* Initialized data */

    static integer lnod[50] = { 10,14,16,8,15,16,15,16,13,8,18,38,27,35,8,8,
	    35,5,5,5,5,5,5,5,0,0,0,0,0,0,21,21,21,21,21,21,21,21,21,21,8,8,8,
	    8,8,0,0,0,0,0 };
    static integer lval[50] = { 5,4,4,2,1,1,1,1,4,4,3,4,4,16,1,1,9,2,1,1,19,
	    55,17,46,0,0,0,0,0,0,1,1,1,1,1,17,17,17,17,17,1,1,1,1,1,0,0,0,0,0 
	    };
    static integer nnods[50] = { 2,2,2,0,2,2,2,2,2,2,2,4,3,4,4,4,4,0,1,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, itab, locp, locv;
    extern /* Subroutine */ int getm4_(integer *, integer *), copy4_(integer *
	    , integer *, integer *), copy8_(doublereal *, doublereal *, 
	    integer *);
    static integer locpe, locve, nlocp, nword, jstop;
    extern /* Subroutine */ int cpytb4_(integer *, integer *), cpytb8_(
	    integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int newnod_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer nssnod, nlocpe, nodold, nodnew;
    extern /* Subroutine */ int sizmem_(integer *, integer *);


/*     THIS ROUTINE ADDS AN ELEMENT TO THE NOMINAL CIRCUIT DEFINITION */
/* LISTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/* ... INODX(1), INODI(1) ARE ARRAYS (SEE SUBCKT) */

    /* Parameter adjustments */
    --inodi;
    --inodx;

    /* Function Body */

/*  COPY INTEGER PART */

    nword = lnod[(0 + (0 + (*id - 1 << 2))) / 4] - 3;
    if (nword <= 0) {
	goto L10;
    }
    copy4_(&nodplc[*loc + 1], &nodplc[*loce + 1], &nword);

/*  SET NODES */

L10:
    if (*id >= 21) {
	goto L100;
    }
    if (nnods[*id - 1] == 0) {
	goto L100;
    }
    if (*id <= 4) {
	goto L20;
    }
    if (*id <= 8) {
	goto L40;
    }
    if (*id == 19) {
	goto L70;
    }
L20:
    jstop = nnods[*id - 1];
    i__1 = jstop;
    for (j = 1; j <= i__1; ++j) {
	newnod_(&nodplc[*loc + j], &nodplc[*loce + j], &inodx[1], &inodi[1], 
		nnodi);
/* L30: */
    }
    goto L100;
L40:
    newnod_(&nodplc[*loc + 1], &nodplc[*loce + 1], &inodx[1], &inodi[1], 
	    nnodi);
    newnod_(&nodplc[*loc + 2], &nodplc[*loce + 2], &inodx[1], &inodi[1], 
	    nnodi);
    if (*id >= 7) {
	goto L100;
    }
    nlocp = *loc + *id + 1;
    nssnod = nodplc[*loc + 3] << 1;
    getm4_(&nodplc[*loce + *id], &nssnod);
    nlocpe = *loce + *id + 1;
L50:
    i__1 = nssnod;
    for (j = 1; j <= i__1; ++j) {
	locp = nodplc[nlocp - 1];
	nodold = nodplc[locp + j - 1];
	newnod_(&nodold, &nodnew, &inodx[1], &inodi[1], nnodi);
	locpe = nodplc[nlocpe - 1];
	nodplc[locpe + j - 1] = nodnew;
/* L60: */
    }
    goto L100;
L70:
    nlocp = *loc + 2;
    sizmem_(&nodplc[*loc + 1], &nssnod);
    getm4_(&nodplc[*loce + 1], &nssnod);
    nlocpe = *loce + 2;
    goto L50;

/*  COPY REAL PART */

L100:
    if (flags_1.nogo != 0) {
	goto L300;
    }
    locv = nodplc[*loc];
    locve = nodplc[*loce];
    copy8_(&blank_1.value[locv - 1], &blank_1.value[locve - 1], &lval[*id - 1]
	    );

/*  TREAT NON-NODE TABLES SPECIALLY */

/* L200: */
    if (*id >= 11) {
	goto L300;
    }
    switch (*id) {
	case 1:  goto L300;
	case 2:  goto L210;
	case 3:  goto L220;
	case 4:  goto L300;
	case 5:  goto L230;
	case 6:  goto L240;
	case 7:  goto L230;
	case 8:  goto L240;
	case 9:  goto L260;
	case 10:  goto L260;
    }
L210:
    if (nodplc[*loc + 3] == 1) {
	goto L300;
    }
    i__1 = *loc + 7;
    i__2 = *loce + 7;
    cpytb8_(&i__1, &i__2);
    goto L300;
L220:
    if (nodplc[*loc + 3] == 1) {
	goto L300;
    }
    i__1 = *loc + 10;
    i__2 = *loce + 10;
    cpytb8_(&i__1, &i__2);
    goto L300;
L230:
    itab = 5;
    goto L250;
L240:
    itab = 6;
L250:
    if (*id <= 6) {
	goto L255;
    }
    i__1 = *loc + itab + 1;
    i__2 = *loce + itab + 1;
    cpytb4_(&i__1, &i__2);
L255:
    i__1 = *loc + itab + 2;
    i__2 = *loce + itab + 2;
    cpytb4_(&i__1, &i__2);
    i__1 = *loc + itab + 3;
    i__2 = *loce + itab + 3;
    cpytb8_(&i__1, &i__2);
    i__1 = *loc + itab + 4;
    i__2 = *loce + itab + 4;
    cpytb8_(&i__1, &i__2);
    i__1 = *loc + itab + 5;
    i__2 = *loce + itab + 5;
    cpytb4_(&i__1, &i__2);
    i__1 = *loc + itab + 6;
    i__2 = *loce + itab + 6;
    cpytb8_(&i__1, &i__2);
    goto L300;
L260:
    i__1 = *loc + 5;
    i__2 = *loce + 5;
    cpytb8_(&i__1, &i__2);


L300:
    return 0;
} /* addelt_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int lnkref_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, loc, iref, locp, nump;
    extern /* Subroutine */ int fndnam_(doublereal *, integer *, integer *, 
	    integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int clrmem_(integer *);


/*     THIS ROUTINE RESOLVES ALL UNSATISFIED NAME REFERENCES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  MUTUAL INDUCTORS */

    loc = cirdat_1.locate[3];
L100:
    if (loc == 0) {
	goto L200;
    }
    iref = nodplc[loc + 1];
    i__1 = loc - 1;
    i__2 = loc + 2;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__3);
    iref = nodplc[loc + 2];
    i__1 = loc - 1;
    i__2 = loc + 3;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__3);
    loc = nodplc[loc - 1];
    goto L100;

/*  CURRENT-CONTROLLED CURRENT SOURCE */

L200:
    loc = cirdat_1.locate[6];
L210:
    if (loc == 0) {
	goto L300;
    }
    nump = nodplc[loc + 3];
    locp = nodplc[loc + 5];
    i__1 = nump;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iref = nodplc[locp + i__ - 1];
	i__2 = loc - 1;
	i__3 = locp + i__;
	fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__2, &i__3, &
		c__9);
/* L220: */
    }
    loc = nodplc[loc - 1];
    goto L210;

/*  CURRENT-CONTROLLED VOLTAGE SOURCES */

L300:
    loc = cirdat_1.locate[7];
L310:
    if (loc == 0) {
	goto L400;
    }
    nump = nodplc[loc + 3];
    locp = nodplc[loc + 6];
    i__1 = nump;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iref = nodplc[locp + i__ - 1];
	i__2 = loc - 1;
	i__3 = locp + i__;
	fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__2, &i__3, &
		c__9);
/* L320: */
    }
    loc = nodplc[loc - 1];
    goto L310;

/*  DIODES */

L400:
    loc = cirdat_1.locate[10];
L410:
    if (loc == 0) {
	goto L500;
    }
    iref = nodplc[loc + 4];
    i__1 = loc - 1;
    i__2 = loc + 5;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__21);
    loc = nodplc[loc - 1];
    goto L410;

/*  BJTS */

L500:
    loc = cirdat_1.locate[11];
L510:
    if (loc == 0) {
	goto L600;
    }
    iref = nodplc[loc + 7];
    i__1 = loc - 1;
    i__2 = loc + 8;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__22);
    loc = nodplc[loc - 1];
    goto L510;

/*  JFETS */

L600:
    loc = cirdat_1.locate[12];
L610:
    if (loc == 0) {
	goto L700;
    }
    iref = nodplc[loc + 6];
    i__1 = loc - 1;
    i__2 = loc + 7;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__23);
    loc = nodplc[loc - 1];
    goto L610;

/*  MOSFETS */

L700:
    loc = cirdat_1.locate[13];
L710:
    if (loc == 0) {
	goto L1000;
    }
    iref = nodplc[loc + 7];
    i__1 = loc - 1;
    i__2 = loc + 8;
    fndnam_(&blank_1.value[tabinf_1.iunsat + iref - 1], &i__1, &i__2, &c__24);
    loc = nodplc[loc - 1];
    goto L710;

/*  FINISHED */

L1000:
    clrmem_(&tabinf_1.iunsat);
    return 0;
} /* lnkref_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int subnam_(integer *loce)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_874 = { "        ", 0. };

#define ablank (*(doublereal *)&equiv_874)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_875 = { ".       ", 0. };

#define aper (*(doublereal *)&equiv_875)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_876 = { "*       ", 0. };

#define astk (*(doublereal *)&equiv_876)


    /* Local variables */
    static integer loc, locv;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static doublereal achar;
    static integer ichar, nchar;
    static doublereal sname;
    static integer locve;
    static doublereal elname;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE CONSTRUCTS THE NAMES OF ELEMENTS ADDED AS A RESULT OF */
/* SUBCIRCUIT EXPANSION.  THE FULL ELEMENT NAMES ARE OF THE FORM */
/*                  NAME.XN. --- XD.XC.XB.XA */
/* WHERE 'NAME' IS THE NOMINAL ELEMENT NAME, AND THE 'X'*S DENOTE THE */
/* SEQUENCE OF SUBCIRCUIT CALLS (FROM TOP OR CIRCUIT LEVEL DOWN THROUGH */
/* NESTED SUBCIRCUIT CALLS) WHICH CAUSED THE PARTICULAR ELEMENT TO BE */
/* ADDED.  AT PRESENT, SPICE RESTRICTS ALL ELEMENT NAMES TO BE 8 CHARAC- */
/* TERS OR LESS.  THEREFORE, THE NAME USED CONSISTS OF THE LEFTMOST 8 */
/* CHARACTERS OF THE FULL ELEMENT NAME, WITH THE RIGHTMOST CHARACTER */
/* REPLACED BY AN ASTERISK ('*') IF THE FULL ELEMENT NAME IS LONGER THAN */
/* 8 CHARACTERS. */

/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



/*  CONSTRUCT SUBCIRCUIT ELEMENT NAME */

    if (nodplc[(0 + (0 + (*loce - 1 - 1 << 2))) / 4] == 0) {
	goto L100;
    }
    locve = nodplc[*loce];
    loc = *loce;
    nchar = 0;
    sname = ablank;
    achar = ablank;
L10:
    locv = nodplc[loc];
    elname = blank_1.value[locv - 1];
    for (ichar = 1; ichar <= 8; ++ichar) {
	move_(&achar, &c__1, &elname, &ichar, &c__1);
	if (achar == ablank) {
	    goto L30;
	}
	if (nchar == 8) {
	    goto L40;
	}
	++nchar;
	move_(&sname, &nchar, &achar, &c__1, &c__1);
/* L20: */
    }
L30:
    loc = nodplc[loc - 2];
    if (loc == 0) {
	goto L60;
    }
    if (nchar == 8) {
	goto L40;
    }
    ++nchar;
    move_(&sname, &nchar, &aper, &c__1, &c__1);
    goto L10;

/*  NAME IS LONGER THAN 8 CHARACTERS:  FLAG WITH ASTERISK */

L40:
    move_(&sname, &c__8, &astk, &c__1, &c__1);
L60:
    blank_1.value[locve - 1] = sname;

/*  FINISHED */

L100:
    return 0;
} /* subnam_ */

#undef cvalue
#undef nodplc
#undef astk
#undef aper
#undef ablank


/* Subroutine */ int elprnt_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_948 = { "CIRCUIT ELEMENT SUMMARY         ", 0. };

#define eltitl ((doublereal *)&equiv_948)

    static struct {
	char e_1[48];
	doublereal e_2;
	} equiv_949 = { "        PULSE   SIN     EXP     PWL     SFFM    ", 
		0. };

#define astyp ((doublereal *)&equiv_949)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_950 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_950)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_951 = { "OFF     ", 0. };

#define aoff (*(doublereal *)&equiv_951)


    /* Format strings */
    static char fmt_21[] = "(//\0020**** RESISTORS\002/\0020     NAME       "
	    " NODES     VALUE       TC1        TC2\002//)";
    static char fmt_31[] = "(6x,a8,2i5,1p3d11.2)";
    static char fmt_51[] = "(//\0020**** CAPACITORS AND INDUCTORS\002/\0020 "
	    "    NAME        NODES    IN COND     VALUE\002//)";
    static char fmt_63[] = "(6x,a8,2i5,1pd11.2,\002   VARIABLE\002)";
    static char fmt_81[] = "(//\0020**** MUTUAL INDUCTORS\002/\0020     NAME"
	    "        COUPLED INDUCTORS   VALUE\002//)";
    static char fmt_91[] = "(6x,a8,4x,a8,2x,a8,1pd10.2)";
    static char fmt_101[] = "(//\0020**** VOLTAGE-CONTROLLED CURRENT SOURCE"
	    "S\002/\0020     NAME        +    -   DIMENSION   FUNCTION\002)";
    static char fmt_111[] = "(6x,a8,2i5,i8,9x,\002POLY\002)";
    static char fmt_121[] = "(//\0020**** VOLTAGE-CONTROLLED VOLTAGE SOURCE"
	    "S\002/\0020     NAME        +    -   DIMENSION   FUNCTION\002)";
    static char fmt_141[] = "(//\0020**** CURRENT-CONTROLLED CURRENT SOURCE"
	    "S\002/\0020     NAME        +    -   DIMENSION   FUNCTION\002)";
    static char fmt_161[] = "(//\0020**** CURRENT-CONTROLLED VOLTAGE SOURCE"
	    "S\002/\0020     NAME        +    -   DIMENSION   FUNCTION\002)";
    static char fmt_171[] = "(//\0020**** INDEPENDENT SOURCES\002/\0020     "
	    "NAME        NODES   DC VALUE   AC VALUE   AC PHASE   TRANSIEN"
	    "T\002//)";
    static char fmt_181[] = "(6x,a8,2i5,1p3d11.2,2x,a8)";
    static char fmt_191[] = "(\0020\002,42x,\002INITIAL VALUE\002,1pd11.2,/,"
	    "43x,\002PULSED VALUE.\002,d11.2,/,43x,\002DELAY TIME...\002,d11."
	    "2,/,43x,\002RISETIME.....\002,d11.2,/,43x,\002FALLTIME.....\002,"
	    "d11.2,/,43x,\002WIDTH........\002,d11.2,/,43x,\002PERIOD......"
	    ".\002,d11.2,/)";
    static char fmt_201[] = "(\0020\002,42x,\002OFFSET.......\002,1pd11.2,/,"
	    "43x,\002AMPLITUDE....\002,d11.2,/,43x,\002FREQUENCY....\002,d11."
	    "2,/,43x,\002DELAY........\002,d11.2,/,43x,\002THETA........\002,"
	    "d11.2,/)";
    static char fmt_211[] = "(\0020\002,42x,\002INITIAL VALUE\002,1pd11.2,/,"
	    "43x,\002PULSED VALUE.\002,d11.2,/,43x,\002RISE DELAY...\002,d11."
	    "2,/,43x,\002RISE TAU.....\002,d11.2,/,43x,\002FALL DELAY...\002,"
	    "d11.2,/,43x,\002FALL TAU.....\002,d11.2,/)";
    static char fmt_221[] = "(\0020\002,49x,\002TIME       VALUE\002//,(46x,"
	    "1p2d11.2))";
    static char fmt_226[] = "(1x)";
    static char fmt_231[] = "(\0020\002,42x,\002OFFSET.......\002,1pd11.2,/,"
	    "43x,\002AMPLITUDE....\002,d11.2,/,43x,\002CARRIER FREQ.\002,d11."
	    "2,/,43x,\002MODN INDEX...\002,d11.2,/,43x,\002SIGNAL FREQ..\002,"
	    "d11.2,/)";
    static char fmt_251[] = "(//\0020**** TRANSMISSION LINES\002/\0020     N"
	    "AME             NODES            Z0         TD\002//)";
    static char fmt_256[] = "(6x,a8,4i5,1p2d11.2)";
    static char fmt_261[] = "(//\0020**** DIODES\002/\0020     NAME        +"
	    "    -  MODEL       AREA\002//)";
    static char fmt_271[] = "(6x,a8,2i5,2x,a8,f8.3,2x,a8)";
    static char fmt_291[] = "(//\0020**** BIPOLAR JUNCTION TRANSISTORS\002"
	    "/\0020     NAME        C    B    E    S  MODEL       AREA\002//)";
    static char fmt_301[] = "(6x,a8,4i5,2x,a8,f8.3,2x,a8)";
    static char fmt_321[] = "(//\0020**** JFETS\002/\0020     NAME        D "
	    "   G    S  MODEL       AREA\002//)";
    static char fmt_331[] = "(6x,a8,3i5,2x,a8,f8.3,2x,a8)";
    static char fmt_351[] = "(//\0020**** MOSFETS\002,/,\0020NAME\002,6x,"
	    "\002D   G   S   B  MODEL\002,6x,\002W       AD       PD      RD"
	    "S\002/37x,\002L       AS       PS      RSS\002,//)";
    static char fmt_361[] = "(1x,a8,4i4,1x,a8,1p4d8.1,/34x,1p4d8.1,1x,a8)";
    static char fmt_401[] = "(//\0020**** SUBCIRCUIT CALLS\002/\0020     NAM"
	    "E     SUBCIRCUIT   EXTERNAL NODES\002//)";
    static char fmt_416[] = "(6x,a8,2x,a8,4x,20i5)";
    static char fmt_418[] = "(28x,20i5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer j, id, nl1, nl2;
    static doublereal aic;
    static integer loc;
    static doublereal anam;
    static integer itab[25], ltab, node, locm, locn, locp, locv, locs, node1, 
	    node2, node3, node4;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer ispot, itype, jstop, nnodx, locsv;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer ititle;
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    static integer nparam, jstart, ndprln;

    /* Fortran I/O blocks */
    static cilist io___885 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___889 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___891 = { 0, 0, 0, fmt_51, 0 };
    static cilist io___892 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___896 = { 0, 0, 0, fmt_63, 0 };
    static cilist io___897 = { 0, 0, 0, fmt_81, 0 };
    static cilist io___900 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___901 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___902 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___903 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___904 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___905 = { 0, 0, 0, fmt_141, 0 };
    static cilist io___906 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___907 = { 0, 0, 0, fmt_161, 0 };
    static cilist io___908 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___909 = { 0, 0, 0, fmt_171, 0 };
    static cilist io___913 = { 0, 0, 0, fmt_181, 0 };
    static cilist io___916 = { 0, 0, 0, fmt_191, 0 };
    static cilist io___918 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___919 = { 0, 0, 0, fmt_211, 0 };
    static cilist io___920 = { 0, 0, 0, fmt_221, 0 };
    static cilist io___921 = { 0, 0, 0, fmt_226, 0 };
    static cilist io___922 = { 0, 0, 0, fmt_231, 0 };
    static cilist io___923 = { 0, 0, 0, fmt_251, 0 };
    static cilist io___926 = { 0, 0, 0, fmt_256, 0 };
    static cilist io___927 = { 0, 0, 0, fmt_261, 0 };
    static cilist io___930 = { 0, 0, 0, fmt_271, 0 };
    static cilist io___931 = { 0, 0, 0, fmt_291, 0 };
    static cilist io___932 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___933 = { 0, 0, 0, fmt_321, 0 };
    static cilist io___934 = { 0, 0, 0, fmt_331, 0 };
    static cilist io___935 = { 0, 0, 0, fmt_351, 0 };
    static cilist io___936 = { 0, 0, 0, fmt_361, 0 };
    static cilist io___937 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___945 = { 0, 0, 0, fmt_416, 0 };
    static cilist io___946 = { 0, 0, 0, fmt_418, 0 };
    static cilist io___947 = { 0, 0, 0, fmt_226, 0 };



/*     THIS ROUTINE PRINTS A CIRCUIT ELEMENT SUMMARY. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */



/*  PRINT LISTING OF ELEMENTS */

    title_(&c__0, &miscel_1.lwidth, &c__1, eltitl);

/*  PRINT RESISTORS */

    if (cirdat_1.jelcnt[0] == 0) {
	goto L50;
    }
    ititle = 0;
/* L21: */
    loc = cirdat_1.locate[0];
L30:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L50;
    }
    if (ititle == 0) {
	io___885.ciunit = status_1.iofile;
	s_wsfe(&io___885);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    io___889.ciunit = status_1.iofile;
    s_wsfe(&io___889);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 2], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 3], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
/* L40: */
    loc = nodplc[loc - 1];
    goto L30;

/*  PRINT CAPACITORS AND INDUCTORS */

L50:
    if (cirdat_1.jelcnt[1] + cirdat_1.jelcnt[2] == 0) {
	goto L80;
    }
    ititle = 0;
/* L51: */
    for (id = 2; id <= 3; ++id) {
	loc = cirdat_1.locate[id - 1];
L60:
	if (loc == 0) {
	    goto L70;
	}
	if (id == 2 && nodplc[loc + 11] != 0) {
	    goto L70;
	}
	if (id == 3 && nodplc[loc + 13] != 0) {
	    goto L70;
	}
	if (ititle == 0) {
	    io___891.ciunit = status_1.iofile;
	    s_wsfe(&io___891);
	    e_wsfe();
	}
	ititle = 1;
	locv = nodplc[loc];
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	if (nodplc[loc + 3] != 1) {
	    goto L62;
	}
	io___892.ciunit = status_1.iofile;
	s_wsfe(&io___892);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal)
		);
	e_wsfe();
	goto L65;
L62:
	ltab = 7;
	if (id == 3) {
	    ltab = 10;
	}
	sizmem_(&nodplc[loc + ltab - 1], &nparam);
	ispot = nodplc[loc + ltab - 1] + 1;
	io___896.ciunit = status_1.iofile;
	s_wsfe(&io___896);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
L65:
	loc = nodplc[loc - 1];
	goto L60;
L70:
	;
    }

/*  PRINT MUTUAL INDUCTORS */

L80:
    if (cirdat_1.jelcnt[3] == 0) {
	goto L100;
    }
    ititle = 0;
/* L81: */
    loc = cirdat_1.locate[3];
L90:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L110;
    }
    if (ititle == 0) {
	io___897.ciunit = status_1.iofile;
	s_wsfe(&io___897);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    nl1 = nodplc[loc + 1];
    nl1 = nodplc[nl1];
    nl2 = nodplc[loc + 2];
    nl2 = nodplc[nl2];
    io___900.ciunit = status_1.iofile;
    s_wsfe(&io___900);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[nl1 - 1], (ftnlen)sizeof(doublereal))
	    ;
    do_fio(&c__1, (char *)&blank_1.value[nl2 - 1], (ftnlen)sizeof(doublereal))
	    ;
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L95: */
    loc = nodplc[loc - 1];
    goto L90;

/*  PRINT NONLINEAR VOLTAGE CONTROLLED SOURCES */

L100:
    if (cirdat_1.jelcnt[4] == 0) {
	goto L120;
    }
    ititle = 0;
/* L101: */
    loc = cirdat_1.locate[4];
L110:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L120;
    }
    if (ititle == 0) {
	io___901.ciunit = status_1.iofile;
	s_wsfe(&io___901);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    io___902.ciunit = status_1.iofile;
    s_wsfe(&io___902);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[loc + 3], (ftnlen)sizeof(integer));
    e_wsfe();
/* L115: */
    loc = nodplc[loc - 1];
    goto L110;

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L120:
    if (cirdat_1.jelcnt[5] == 0) {
	goto L140;
    }
    ititle = 0;
/* L121: */
    loc = cirdat_1.locate[5];
L130:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L140;
    }
    if (ititle == 0) {
	io___903.ciunit = status_1.iofile;
	s_wsfe(&io___903);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    io___904.ciunit = status_1.iofile;
    s_wsfe(&io___904);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[loc + 3], (ftnlen)sizeof(integer));
    e_wsfe();
/* L135: */
    loc = nodplc[loc - 1];
    goto L130;

/*  NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */

L140:
    if (cirdat_1.jelcnt[6] == 0) {
	goto L160;
    }
    ititle = 0;
/* L141: */
    loc = cirdat_1.locate[6];
L150:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L160;
    }
    if (ititle == 0) {
	io___905.ciunit = status_1.iofile;
	s_wsfe(&io___905);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    io___906.ciunit = status_1.iofile;
    s_wsfe(&io___906);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[loc + 3], (ftnlen)sizeof(integer));
    e_wsfe();
/* L155: */
    loc = nodplc[loc - 1];
    goto L150;

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L160:
    if (cirdat_1.jelcnt[7] == 0) {
	goto L170;
    }
    ititle = 0;
/* L161: */
    loc = cirdat_1.locate[7];
L165:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L170;
    }
    if (ititle == 0) {
	io___907.ciunit = status_1.iofile;
	s_wsfe(&io___907);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    io___908.ciunit = status_1.iofile;
    s_wsfe(&io___908);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[loc + 3], (ftnlen)sizeof(integer));
    e_wsfe();
/* L167: */
    loc = nodplc[loc - 1];
    goto L165;

/*  PRINT INDEPENDENT SOURCES */

L170:
    if (cirdat_1.jelcnt[8] + cirdat_1.jelcnt[9] == 0) {
	goto L250;
    }
    ititle = 0;
/* L171: */
    for (id = 9; id <= 10; ++id) {
	loc = cirdat_1.locate[id - 1];
L180:
	if (loc == 0) {
	    goto L245;
	}
	if (id == 9 && nodplc[loc + 10] != 0) {
	    goto L245;
	}
	if (id == 10 && nodplc[loc + 5] != 0) {
	    goto L245;
	}
	if (ititle == 0) {
	    io___909.ciunit = status_1.iofile;
	    s_wsfe(&io___909);
	    e_wsfe();
	}
	ititle = 1;
	locv = nodplc[loc];
	locp = nodplc[loc + 4];
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	itype = nodplc[loc + 3] + 1;
	anam = astyp[itype - 1];
	io___913.ciunit = status_1.iofile;
	s_wsfe(&io___913);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&blank_1.value[locv + 2], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (tran_1.jtrflg == 0) {
	    goto L240;
	}
	jstart = locp + 1;
	switch (itype) {
	    case 1:  goto L240;
	    case 2:  goto L190;
	    case 3:  goto L200;
	    case 4:  goto L210;
	    case 5:  goto L220;
	    case 6:  goto L230;
	}
L190:
	jstop = locp + 7;
	io___916.ciunit = status_1.iofile;
	s_wsfe(&io___916);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&blank_1.value[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	goto L240;
L200:
	jstop = locp + 5;
	io___918.ciunit = status_1.iofile;
	s_wsfe(&io___918);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&blank_1.value[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	goto L240;
L210:
	jstop = locp + 6;
	io___919.ciunit = status_1.iofile;
	s_wsfe(&io___919);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&blank_1.value[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	goto L240;
L220:
	sizmem_(&nodplc[loc + 4], &jstop);
	jstop = locp + jstop;
	io___920.ciunit = status_1.iofile;
	s_wsfe(&io___920);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&blank_1.value[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	io___921.ciunit = status_1.iofile;
	s_wsfe(&io___921);
	e_wsfe();
	goto L240;
L230:
	jstop = locp + 5;
	io___922.ciunit = status_1.iofile;
	s_wsfe(&io___922);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&blank_1.value[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
L240:
	loc = nodplc[loc - 1];
	goto L180;
L245:
	;
    }

/*  PRINT TRANSMISSION LINES */

L250:
    if (cirdat_1.jelcnt[16] == 0) {
	goto L260;
    }
    ititle = 0;
/* L251: */
    loc = cirdat_1.locate[16];
L253:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L260;
    }
    if (ititle == 0) {
	io___923.ciunit = status_1.iofile;
	s_wsfe(&io___923);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    io___926.ciunit = status_1.iofile;
    s_wsfe(&io___926);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node3 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node4 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
/* L258: */
    loc = nodplc[loc - 1];
    goto L253;

/*  PRINT DIODES */

L260:
    if (cirdat_1.jelcnt[10] == 0) {
	goto L290;
    }
    ititle = 0;
/* L261: */
    loc = cirdat_1.locate[10];
L270:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L290;
    }
    if (ititle == 0) {
	io___927.ciunit = status_1.iofile;
	s_wsfe(&io___927);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    aic = ablnk;
    if (nodplc[loc + 5] == 1) {
	aic = aoff;
    }
    io___930.ciunit = status_1.iofile;
    s_wsfe(&io___930);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locm - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aic, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L280: */
    loc = nodplc[loc - 1];
    goto L270;

/*  PRINT TRANSISTORS */

L290:
    if (cirdat_1.jelcnt[11] == 0) {
	goto L320;
    }
    ititle = 0;
/* L291: */
    loc = cirdat_1.locate[11];
L300:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L320;
    }
    if (ititle == 0) {
	io___931.ciunit = status_1.iofile;
	s_wsfe(&io___931);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    aic = ablnk;
    if (nodplc[loc + 8] == 1) {
	aic = aoff;
    }
    io___932.ciunit = status_1.iofile;
    s_wsfe(&io___932);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node3 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node4 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locm - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aic, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L310: */
    loc = nodplc[loc - 1];
    goto L300;

/*  PRINT JFETS */

L320:
    if (cirdat_1.jelcnt[12] == 0) {
	goto L350;
    }
    ititle = 0;
/* L321: */
    loc = cirdat_1.locate[12];
L330:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L350;
    }
    if (ititle == 0) {
	io___933.ciunit = status_1.iofile;
	s_wsfe(&io___933);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    locm = nodplc[loc + 6];
    locm = nodplc[locm];
    aic = ablnk;
    if (nodplc[loc + 7] == 1) {
	aic = aoff;
    }
    io___934.ciunit = status_1.iofile;
    s_wsfe(&io___934);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node3 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locm - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aic, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L340: */
    loc = nodplc[loc - 1];
    goto L330;

/*  PRINT MOSFETS */

L350:
    if (cirdat_1.jelcnt[13] == 0) {
	goto L400;
    }
    ititle = 0;
/* L351: */
    loc = cirdat_1.locate[13];
L360:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L400;
    }
    if (ititle == 0) {
	io___935.ciunit = status_1.iofile;
	s_wsfe(&io___935);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    aic = ablnk;
    if (nodplc[loc + 8] == 1) {
	aic = aoff;
    }
    io___936.ciunit = status_1.iofile;
    s_wsfe(&io___936);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node1 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node2 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node3 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + node4 - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&blank_1.value[locm - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 2], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 10], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 12], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 3], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locv + 11], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&blank_1.value[locv + 13], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&aic, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L370: */
    loc = nodplc[loc - 1];
    goto L360;

/*  SUBCIRCUIT CALLS */

L400:
    if (cirdat_1.jelcnt[18] == 0) {
	goto L500;
    }
    ititle = 0;
/* L401: */
    loc = cirdat_1.locate[18];
L410:
    if (loc == 0) {
	goto L500;
    }
    if (ititle == 0) {
	io___937.ciunit = status_1.iofile;
	s_wsfe(&io___937);
	e_wsfe();
    }
    ititle = 1;
    locv = nodplc[loc];
    locn = nodplc[loc + 1];
    sizmem_(&nodplc[loc + 1], &nnodx);
    locs = nodplc[loc + 2];
    locsv = nodplc[locs];
    jstart = 1;
    ndprln = (miscel_1.lwidth - 28) / 5;
L412:
/* Computing MIN */
    i__1 = nnodx, i__2 = jstart + ndprln - 1;
    jstop = min(i__1,i__2);
    i__1 = jstop;
    for (j = jstart; j <= i__1; ++j) {
	node = nodplc[locn + j - 1];
	itab[j - jstart] = nodplc[tabinf_1.junode + node - 1];
/* L414: */
    }
    if (jstart == 1) {
	io___945.ciunit = status_1.iofile;
	s_wsfe(&io___945);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&blank_1.value[locsv - 1], (ftnlen)sizeof(
		doublereal));
	i__1 = jstop;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&itab[j - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    }
    if (jstart != 1) {
	io___946.ciunit = status_1.iofile;
	s_wsfe(&io___946);
	i__1 = jstop;
	for (j = jstart; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&itab[j - jstart], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    }
    jstart = jstop + 1;
    if (jstart <= nnodx) {
	goto L412;
    }
    if (nnodx <= ndprln) {
	goto L420;
    }
    io___947.ciunit = status_1.iofile;
    s_wsfe(&io___947);
    e_wsfe();
L420:
    loc = nodplc[loc - 1];
    goto L410;

/*  FINISHED */

L500:
    return 0;
} /* elprnt_ */

#undef cvalue
#undef nodplc
#undef aoff
#undef ablnk
#undef astyp
#undef eltitl


/* Subroutine */ int modchk_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1024 = { "DIODE MODEL PARAMETERS          ", 0. };

#define titled ((doublereal *)&equiv_1024)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1025 = { "BJT MODEL PARAMETERS            ", 0. };

#define titleb ((doublereal *)&equiv_1025)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1026 = { "JFET MODEL PARAMETERS           ", 0. };

#define titlej ((doublereal *)&equiv_1026)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1027 = { "MOSFET MODEL PARAMETERS         ", 0. };

#define titlem ((doublereal *)&equiv_1027)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1028 = { "        NPN     NJF     NMOS    ", 0. };

#define antype ((doublereal *)&equiv_1028)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1029 = { "        PNP     PJF     PMOS    ", 0. };

#define aptype ((doublereal *)&equiv_1029)

    static integer ipar[5] = { 0,14,60,72,114 };
    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_1030 = { "C2      C4      ", 0. };

#define cpar ((doublereal *)&equiv_1030)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1031 = { ".U      ", 0. };

#define aundef (*(doublereal *)&equiv_1031)

    static struct {
	char e_1[912];
	doublereal e_2;
	} equiv_1032 = { "IS      RS      N       TT      CJO     VJ      M "
		"      EG      XTI     KF      AF      FC      BV      IBV   "
		"  IS      BF      NF      VAF     IKF     ISE     NE      BR"
		"      NR      VAR     IKR     ISC     NC      0       0     "
		"  RB      IRB     RBM     RE      RC      CJE     VJE     MJ"
		"E     TF      XTF     VTF     ITF     PTF     CJC     VJC   "
		"  MJC     XCJC    TR      0       0       0       0       CJ"
		"S     VJS     MJS     XTB     EG      XTI     KF      AF    "
		"  FC      VTO     BETA    LAMBDA  RD      RS      CGS     CG"
		"D     PB      IS      KF      AF      FC      LEVEL   VTO   "
		"  KP      GAMMA   PHI     LAMBDA  RD      RS      CBD     CB"
		"S     IS      PB      CGSO    CGDO    CGBO    RSH     CJ    "
		"  MJ      CJSW    MJSW    JS      TOX     NSUB    NSS     NF"
		"S     TPG     XJ      LD      UO      UCRIT   UEXP    UTRA  "
		"  VMAX    NEFF    XQC     KF      AF      FC      DELTA   TH"
		"ETA   ETA     KAPPA   ", 0. };

#define ampar ((doublereal *)&equiv_1032)

    static doublereal defval[115] = { 1e-14,0.,1.,0.,0.,1.,.5,1.11,3.,0.,1.,
	    .5,0.,.001,1e-16,100.,1.,0.,0.,0.,1.5,1.,1.,0.,0.,0.,2.,0.,1.,0.,
	    0.,0.,0.,0.,0.,.75,.33,0.,0.,0.,0.,0.,0.,.75,.33,1.,0.,0.,0.,0.,
	    0.,0.,.75,0.,0.,1.11,3.,0.,1.,.5,-2.,1e-4,0.,0.,0.,0.,0.,1.,1e-14,
	    0.,1.,.5,1.,0.,2e-5,0.,.6,0.,0.,0.,0.,0.,1e-14,.8,0.,0.,0.,0.,0.,
	    .5,0.,.33,0.,0.,0.,0.,0.,1.,0.,0.,600.,1e4,0.,0.,0.,1.,1.,0.,1.,
	    .5,0.,0.,0.,.2,0. };
    static integer ifmt[115] = { 4,1,1,2,2,1,1,1,1,2,1,1,2,2,4,3,3,2,2,2,1,3,
	    3,2,2,2,1,0,0,1,2,1,1,1,2,1,1,2,2,2,2,1,2,1,1,1,2,0,0,0,0,2,1,1,2,
	    1,1,2,2,2,3,4,1,1,1,2,2,1,2,2,1,1,3,3,4,1,1,2,1,1,2,2,2,1,2,2,2,1,
	    2,1,2,1,2,2,2,2,2,1,2,2,1,2,1,1,2,1,1,2,1,1,1,1,1,1,0 };
    static integer ivchk[115] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,-1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* Format strings */
    static char fmt_31[] = "(\0020*ERROR*:  NSUB <= NI IN MOSFET MODEL \002,"
	    "a8,/)";
    static char fmt_89[] = "(\0020WARNING:  MINIMUM BASE RESISTANCE (RBM) IS"
	    " LESS THAN \002,\002TOTAL (RB) FOR MODEL \002,a8,/10x,\002 RBM S"
	    "ET EQUAL TO RB\002,/)";
    static char fmt_121[] = "(\0020WARNING:  THE VALUE OF LAMBDA FOR MOSFET "
	    "MODEL \002,a8,/,\002 IS UNUSUALLY LARGE AND MIGHT CAUSE NONCONVE"
	    "RGENCE\002,/)";
    static char fmt_241[] = "(//11x,12(2x,a8))";
    static char fmt_261[] = "(\0020TYPE\002,4x,12(4x,a6))";
    static char fmt_321[] = "(\0020\002,a8,12f10.3)";
    static char fmt_331[] = "(\0020\002,a8,1p12d10.2)";
    static char fmt_411[] = "(\0020WARNING:  IN DIODE MODEL \002,a8,\002 IBV"
	    " INCREASED TO \002,1pe10.3,11x,\002TO RESOLVE INCOMPATIBILITY WI"
	    "TH SPECIFIED IS\002/)";
    static char fmt_415[] = "(\0020WARNING:  UNABLE TO MATCH FORWARD AND REV"
	    "ERSE DIODE REGIONS\002,/,11x,\002BV = \002,1pd10.3,\002 AND IBV "
	    "= \002,d10.3,/)";
    static char fmt_911[] = "(\0020*ERROR*:  EFFECTIVE CHANNEL LENGTH OF "
	    "\002,a8,\002 LESS THAN \002,\002ZERO.\002,/\002 CHECK VALUE OF L"
	    "D FOR MODEL \002,a8)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double log(doublereal), sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double exp(doublereal);

    /* Local variables */
    static integer i__, k;
    static doublereal ad, fc;
    static integer id;
    static doublereal cj, pb, pc, as, pe, bv, xm, cbv;
    static integer loc;
    static doublereal xfc;
    static integer lev;
    static doublereal xmc, cox, xme, vte, xbv, tol, xkt;
    static integer itab[50], locm, locv, locs, locn;
    static doublereal tnom;
    static integer kntr;
    static doublereal type__, csat;
    static integer iter;
    static doublereal xcbv, xleff, wkfng;
    static integer nopar;
    static doublereal xnsub;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer iccflg;
    static doublereal atable[12], btable[12], fermig;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer nummod;
    static doublereal fermis, wkfngs;
    static integer kntlim;

    /* Fortran I/O blocks */
    static cilist io___980 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___987 = { 0, 0, 0, fmt_89, 0 };
    static cilist io___989 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___994 = { 0, 0, 0, fmt_241, 0 };
    static cilist io___996 = { 0, 0, 0, fmt_261, 0 };
    static cilist io___999 = { 0, 0, 0, fmt_321, 0 };
    static cilist io___1000 = { 0, 0, 0, fmt_331, 0 };
    static cilist io___1001 = { 0, 0, 0, fmt_321, 0 };
    static cilist io___1010 = { 0, 0, 0, fmt_411, 0 };
    static cilist io___1015 = { 0, 0, 0, fmt_415, 0 };
    static cilist io___1021 = { 0, 0, 0, fmt_911, 0 };



/*     THIS ROUTINE PERFORMS ONE-TIME PROCESSING OF DEVICE MODEL PARA- */
/* METERS AND PRINTS OUT A DEVICE MODEL SUMMARY.  IT ALSO RESERVES THE */
/* ADDITIONAL NODES REQUIRED BY NONZERO DEVICE EXTRINSIC RESISTANCES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    tnom = blank_1.value[(0 + (0 + (tabinf_1.itemps + 1 - 1 << 3))) / 8] + 
	    knstnt_1.ctok;
    xkt = knstnt_1.boltz * tnom;
    status_1.vt = xkt / knstnt_1.charge;
    status_1.xni = 1.45e16;
    status_1.egfet = 1.16 - tnom * 7.02e-4 * tnom / (tnom + 1108.);
    nummod = cirdat_1.jelcnt[20] + cirdat_1.jelcnt[21] + cirdat_1.jelcnt[22] 
	    + cirdat_1.jelcnt[23];
    if (nummod == 0) {
	goto L1000;
    }

/*  SPECIAL PREPROCESSING FOR MOSFET MODELS */

    loc = cirdat_1.locate[23];
L5:
    if (loc == 0) {
	goto L35;
    }
    locv = nodplc[loc];
    type__ = (doublereal) nodplc[loc + 1];

/*     DEFAULT PARAMETERS FOR HIGHER LEVEL MOS MODELS */

    lev = (integer) blank_1.value[locv];
    if (blank_1.value[locv] == aundef) {
	lev = 1;
    }
    if (blank_1.value[locv + 22] != aundef) {
	xnsub = blank_1.value[locv + 22] * 1e6;
    }
    if (blank_1.value[locv + 21] == aundef && lev > 1) {
	blank_1.value[locv + 21] = 1e-7;
    }
    if (blank_1.value[locv + 21] == aundef) {
	goto L33;
    }
    cox = knstnt_1.epsox / blank_1.value[locv + 21];

/*     COMPUTE KP, IF NOT INPUT, USING DEFAULT MOBILITY 600 CM**2/V*SEC */

    if (blank_1.value[locv + 2] != aundef) {
	goto L10;
    }
    if (blank_1.value[locv + 28] == aundef) {
	blank_1.value[locv + 28] = 600.;
    }
    blank_1.value[locv + 2] = blank_1.value[locv + 28] * cox * 1e-4;
L10:
    if (blank_1.value[locv + 22] == aundef) {
	goto L33;
    }
    if (xnsub <= status_1.xni) {
	goto L30;
    }

/*     NSUB NONZERO => PROCESS ORIENTED MODEL */

    if (blank_1.value[locv + 4] == aundef) {
/* Computing MAX */
	d__1 = status_1.vt * 2. * log(xnsub / status_1.xni);
	blank_1.value[locv + 4] = max(d__1,.1);
    }
    fermis = type__ * .5 * blank_1.value[locv + 4];
    wkfng = 3.2;
    if (blank_1.value[locv + 25] == aundef) {
	blank_1.value[locv + 25] = 1.;
    }
    if (blank_1.value[locv + 25] == 0.) {
	goto L15;
    }

/*  POLYSILICON GATE */

    fermig = type__ * blank_1.value[locv + 25] * .5 * status_1.egfet;
    wkfng = status_1.egfet * .5 + 3.25 - fermig;
L15:
    wkfngs = wkfng - (status_1.egfet * .5 + 3.25 + fermis);
    if (blank_1.value[locv + 3] == aundef) {
	blank_1.value[locv + 3] = sqrt(knstnt_1.epssil * 2. * knstnt_1.charge 
		* xnsub) / cox;
    }

/*     COMPUTED VTO */

    if (blank_1.value[locv + 1] != aundef) {
	goto L20;
    }
    if (blank_1.value[locv + 23] == aundef) {
	blank_1.value[locv + 23] = 0.;
    }
    blank_1.value[locv + 43] = wkfngs - blank_1.value[locv + 23] * 1e4 * 
	    knstnt_1.charge / cox;
    blank_1.value[locv + 1] = blank_1.value[locv + 43] + type__ * (
	    blank_1.value[locv + 3] * sqrt(blank_1.value[locv + 4]) + 
	    blank_1.value[locv + 4]);
    goto L25;

/*     MEASURED VTO HAS BEEN INPUT */

L20:
    blank_1.value[locv + 43] = blank_1.value[locv + 1] - type__ * (
	    blank_1.value[locv + 3] * sqrt(blank_1.value[locv + 4]) + 
	    blank_1.value[locv + 4]);
L25:
    blank_1.value[locv + 44] = sqrt((knstnt_1.epssil + knstnt_1.epssil) / (
	    knstnt_1.charge * xnsub));
    goto L33;
L30:
    blank_1.value[locv + 22] = 0.;
    io___980.ciunit = status_1.iofile;
    s_wsfe(&io___980);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
    flags_1.nogo = 1;

/*   SPECIAL PROCESSING FOR MOS3: LIMIT KAPPA>0, */
/*   SET TO ZERO LAMBDA,UCRIT,UEXP AND UTAR */

L33:
    if (lev != 3) {
	goto L34;
    }
    if (blank_1.value[locv + 41] == aundef) {
	blank_1.value[locv + 41] = .2;
    }
    blank_1.value[locv + 5] = 0.;
    blank_1.value[locv + 29] = 0.;
    blank_1.value[locv + 30] = 0.;
    blank_1.value[locv + 31] = 0.;
L34:
    loc = nodplc[loc - 1];
    goto L5;

/*     CYCLE THRU DEVICES */

L35:
    kntlim = miscel_1.lwidth / 11;
    for (id = 1; id <= 4; ++id) {
	if (cirdat_1.jelcnt[id + 19] == 0) {
	    goto L390;
	}
	locm = ipar[id - 1];
	nopar = ipar[id] - locm;
	i__1 = nopar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (ifmt[locm + i__ - 1] >= 3) {
		goto L40;
	    }
	    itab[i__ - 1] = 0;
	    goto L45;
L40:
	    itab[i__ - 1] = ifmt[locm + i__ - 1] - 2;
L45:
	    ;
	}

/*  ASSIGN DEFAULT VALUES */

	loc = cirdat_1.locate[id + 19];
L50:
	if (loc == 0) {
	    goto L70;
	}
	locv = nodplc[loc];
	i__1 = nopar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (blank_1.value[locv + i__ - 1] == aundef) {
		goto L62;
	    }
	    if (ivchk[locm + i__ - 1] < 0) {
		goto L55;
	    }
	    if (blank_1.value[locv + i__ - 1] < 0.) {
		goto L62;
	    }
L55:
	    if (itab[i__ - 1] != 0) {
		goto L65;
	    }
	    itab[i__ - 1] = ifmt[locm + i__ - 1];
	    goto L65;
L62:
	    blank_1.value[locv + i__ - 1] = defval[locm + i__ - 1];
L65:
	    ;
	}
	loc = nodplc[loc - 1];
	goto L50;

/*     LIMIT MODEL VALUES */

L70:
	switch (id) {
	    case 1:  goto L80;
	    case 2:  goto L85;
	    case 3:  goto L90;
	    case 4:  goto L95;
	}
/* ...  DIODES */
L80:
	loc = cirdat_1.locate[20];
L82:
	if (loc == 0) {
	    goto L130;
	}
	locv = nodplc[loc];
/* Computing MIN */
	d__1 = blank_1.value[locv + 6];
	blank_1.value[locv + 6] = min(d__1,.9);
/* Computing MAX */
	d__1 = blank_1.value[locv + 7];
	blank_1.value[locv + 7] = max(d__1,.1);
/* Computing MAX */
	d__1 = blank_1.value[locv + 10];
	blank_1.value[locv + 10] = max(d__1,.1);
/* Computing MIN */
	d__1 = blank_1.value[locv + 11];
	blank_1.value[locv + 11] = min(d__1,.95);
	loc = nodplc[loc - 1];
	goto L82;
/* ...  BIPOLAR TRANSISTORS */
L85:
	loc = cirdat_1.locate[21];
L87:
	if (loc == 0) {
	    goto L130;
	}
	locv = nodplc[loc];
/* Computing MIN */
	d__1 = blank_1.value[locv + 22];
	blank_1.value[locv + 22] = min(d__1,.9);
	if (blank_1.value[locv + 23] == 0.) {
	    blank_1.value[locv + 27] = 0.;
	}
/* Computing MIN */
	d__1 = blank_1.value[locv + 30];
	blank_1.value[locv + 30] = min(d__1,.9);
/* Computing MIN */
	d__1 = blank_1.value[locv + 31];
	blank_1.value[locv + 31] = min(d__1,1.);
/* Computing MIN */
	d__1 = blank_1.value[locv + 39];
	blank_1.value[locv + 39] = min(d__1,.9);
/* Computing MAX */
	d__1 = blank_1.value[locv + 41];
	blank_1.value[locv + 41] = max(d__1,.1);
/* Computing MAX */
	d__1 = blank_1.value[locv + 44];
	blank_1.value[locv + 44] = max(d__1,.1);
/* Computing MIN */
	d__1 = blank_1.value[locv + 45];
	blank_1.value[locv + 45] = min(d__1,.9999);
	loc = nodplc[loc - 1];
	if (blank_1.value[locv + 17] == 0.) {
	    blank_1.value[locv + 17] = blank_1.value[locv + 15];
	}
	if (blank_1.value[locv + 15] >= blank_1.value[locv + 17]) {
	    goto L87;
	}
	io___987.ciunit = status_1.iofile;
	s_wsfe(&io___987);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	blank_1.value[locv + 17] = blank_1.value[locv + 15];
	goto L87;
/* ...  JFETS */
L90:
	loc = cirdat_1.locate[22];
L92:
	if (loc == 0) {
	    goto L130;
	}
	locv = nodplc[loc];
/* Computing MAX */
	d__1 = blank_1.value[locv + 10];
	blank_1.value[locv + 10] = max(d__1,.1);
/* Computing MIN */
	d__1 = blank_1.value[locv + 11];
	blank_1.value[locv + 11] = min(d__1,.95);
	loc = nodplc[loc - 1];
	goto L92;
/* ...  MOSFETS */
L95:
	loc = cirdat_1.locate[23];
L97:
	if (loc == 0) {
	    goto L130;
	}
	locv = nodplc[loc];

/* L100: */
/* Computing MAX */
	d__1 = blank_1.value[locv + 36];
	blank_1.value[locv + 36] = max(d__1,.1);
/* Computing MIN */
	d__1 = blank_1.value[locv + 37];
	blank_1.value[locv + 37] = min(d__1,.95);
	if (blank_1.value[locv + 22] <= 0.) {
	    goto L120;
	}
	cj = sqrt(knstnt_1.epssil * knstnt_1.charge * blank_1.value[locv + 22]
		 * 1e6 / (blank_1.value[locv + 11] * 2.));
	if (blank_1.value[locv + 8] <= 0.) {
	    goto L105;
	}
	itab[8] = 2;
L105:
	if (blank_1.value[locv + 9] <= 0.) {
	    goto L110;
	}
	itab[9] = 2;
	goto L115;
L110:
	if (blank_1.value[locv + 16] <= 0.) {
	    blank_1.value[locv + 16] = cj;
	}
	itab[16] = 2;
L115:
	if (blank_1.value[locv + 6] <= 0. && blank_1.value[locv + 7] <= 0.) {
	    goto L120;
	}
	itab[6] = 2;
	itab[7] = 2;
L120:
	if (blank_1.value[locv + 5] >= .2) {
	    io___989.ciunit = status_1.iofile;
	    s_wsfe(&io___989);
	    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (lev != 2) {
	    blank_1.value[locv + 34] = 1.;
	}
	if (lev != 3) {
	    goto L125;
	}
	itab[39] = 1;
	itab[40] = 1;
	itab[41] = 1;
	itab[42] = 1;
L125:
	loc = nodplc[loc - 1];
	goto L97;

/*     PRINT MODEL PARAMETERS */

L130:
	if (flags_1.iprntm == 0) {
	    goto L360;
	}
	locs = cirdat_1.locate[id + 19];
L140:
	kntr = 0;
	loc = locs;
	switch (id) {
	    case 1:  goto L150;
	    case 2:  goto L160;
	    case 3:  goto L170;
	    case 4:  goto L180;
	}
L150:
	title_(&c__0, &miscel_1.lwidth, &c__1, titled);
	goto L200;
L160:
	title_(&c__0, &miscel_1.lwidth, &c__1, titleb);
	goto L200;
L170:
	title_(&c__0, &miscel_1.lwidth, &c__1, titlej);
	goto L200;
L180:
	title_(&c__0, &miscel_1.lwidth, &c__1, titlem);
L200:
	if (loc == 0) {
	    goto L210;
	}
	if (kntr < kntlim) {
	    goto L220;
	}
L210:
	locn = loc;
	goto L240;
L220:
	++kntr;
	locv = nodplc[loc];
	atable[kntr - 1] = blank_1.value[locv - 1];
/* L230: */
	loc = nodplc[loc - 1];
	goto L200;
L240:
	io___994.ciunit = status_1.iofile;
	s_wsfe(&io___994);
	i__1 = kntr;
	for (k = 1; k <= i__1; ++k) {
	    do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	if (id == 1) {
	    goto L300;
	}
	kntr = 0;
	loc = locs;
L250:
	if (loc == 0) {
	    goto L260;
	}
	if (kntr >= kntlim) {
	    goto L260;
	}
	++kntr;
	atable[kntr - 1] = antype[id - 1];
	if (nodplc[loc + 1] == -1) {
	    atable[kntr - 1] = aptype[id - 1];
	}
	loc = nodplc[loc - 1];
	goto L250;
L260:
	io___996.ciunit = status_1.iofile;
	s_wsfe(&io___996);
	i__1 = kntr;
	for (k = 1; k <= i__1; ++k) {
	    do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
L300:
	i__1 = nopar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (itab[i__ - 1] == 0) {
		goto L340;
	    }
	    kntr = 0;
	    iccflg = 0;
	    loc = locs;
L310:
	    if (loc == 0) {
		goto L320;
	    }
	    if (kntr >= kntlim) {
		goto L320;
	    }
	    locv = nodplc[loc];
	    ++kntr;
	    if (iccflg != 0) {
		goto L313;
	    }
	    if (id != 2) {
		goto L315;
	    }
	    if (i__ != 6 && i__ != 12) {
		goto L315;
	    }
	    if (blank_1.value[locv + i__ - 1] <= 1.) {
		goto L315;
	    }
	    iccflg = i__ / 6;
L313:
	    btable[kntr - 1] = blank_1.value[locv + i__ - 1];
	    blank_1.value[locv + i__ - 1] *= blank_1.value[locv];
L315:
	    atable[kntr - 1] = blank_1.value[locv + i__ - 1];
	    loc = nodplc[loc - 1];
	    goto L310;
L320:
	    if (itab[i__ - 1] == 2) {
		goto L330;
	    }
	    io___999.ciunit = status_1.iofile;
	    s_wsfe(&io___999);
	    do_fio(&c__1, (char *)&ampar[locm + i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    i__2 = kntr;
	    for (k = 1; k <= i__2; ++k) {
		do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    goto L340;
L330:
	    io___1000.ciunit = status_1.iofile;
	    s_wsfe(&io___1000);
	    do_fio(&c__1, (char *)&ampar[locm + i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    i__2 = kntr;
	    for (k = 1; k <= i__2; ++k) {
		do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    if (iccflg == 0) {
		goto L340;
	    }
	    io___1001.ciunit = status_1.iofile;
	    s_wsfe(&io___1001);
	    do_fio(&c__1, (char *)&cpar[iccflg - 1], (ftnlen)sizeof(
		    doublereal));
	    i__2 = kntr;
	    for (k = 1; k <= i__2; ++k) {
		do_fio(&c__1, (char *)&btable[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
L340:
	    ;
	}
	if (locn == 0) {
	    goto L390;
	}
	locs = locn;
	goto L140;

/*  SPECIAL  TREATMENT FOR C2 & C4 IN THE BJT MODEL */
/*  WHEN NO MODEL PARAMETER PRINT */

L360:
	if (id != 2) {
	    goto L390;
	}
	loc = cirdat_1.locate[id + 19];
L370:
	if (loc == 0) {
	    goto L390;
	}
	locv = nodplc[loc];
	if (blank_1.value[locv + 5] >= 1.) {
	    blank_1.value[locv + 5] *= blank_1.value[locv];
	}
	if (blank_1.value[locv + 11] >= 1.) {
	    blank_1.value[locv + 11] *= blank_1.value[locv];
	}
	loc = nodplc[loc - 1];
	goto L370;
L390:
	;
    }

/*  PROCESS MODEL PARAMETERS */

/*  DIODES */

/* L400: */
    loc = cirdat_1.locate[20];
L410:
    if (loc == 0) {
	goto L420;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv + 1] != 0.) {
	blank_1.value[locv + 1] = 1. / blank_1.value[locv + 1];
    }
    pb = blank_1.value[locv + 5];
    xm = blank_1.value[locv + 6];
    fc = blank_1.value[locv + 11];
    blank_1.value[locv + 11] = fc * pb;
    xfc = log(1. - fc);
    blank_1.value[locv + 14] = pb * (1. - exp((1. - xm) * xfc)) / (1. - xm);
    blank_1.value[locv + 15] = exp((xm + 1.) * xfc);
    blank_1.value[locv + 16] = 1. - fc * (xm + 1.);
    csat = blank_1.value[locv];
    vte = blank_1.value[locv + 2] * status_1.vt;
    blank_1.value[locv + 17] = vte * log(vte / (knstnt_1.root2 * csat));
    bv = blank_1.value[locv + 12];
    if (bv == 0.) {
	goto L418;
    }
    cbv = blank_1.value[locv + 13];
    if (cbv >= csat * bv / status_1.vt) {
	goto L412;
    }
    cbv = csat * bv / status_1.vt;
    io___1010.ciunit = status_1.iofile;
    s_wsfe(&io___1010);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&cbv, (ftnlen)sizeof(doublereal));
    e_wsfe();
    xbv = bv;
    goto L416;
L412:
    tol = knstnt_1.reltol * cbv;
    xbv = bv - status_1.vt * log(cbv / csat + 1.);
    iter = 0;
L413:
    xbv = bv - status_1.vt * log(cbv / csat + 1. - xbv / status_1.vt);
    xcbv = csat * (exp((bv - xbv) / status_1.vt) - 1. + xbv / status_1.vt);
    if ((d__1 = xcbv - cbv, abs(d__1)) <= tol) {
	goto L416;
    }
    ++iter;
    if (iter < 25) {
	goto L413;
    }
    io___1015.ciunit = status_1.iofile;
    s_wsfe(&io___1015);
    do_fio(&c__1, (char *)&xbv, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xcbv, (ftnlen)sizeof(doublereal));
    e_wsfe();
L416:
    blank_1.value[locv + 12] = xbv;
L418:
    loc = nodplc[loc - 1];
    goto L410;

/*  BIPOLAR TRANSISTOR MODELS */

L420:
    loc = cirdat_1.locate[21];
L430:
    if (loc == 0) {
	goto L440;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv + 3] != 0.) {
	blank_1.value[locv + 3] = 1. / blank_1.value[locv + 3];
    }
    if (blank_1.value[locv + 4] != 0.) {
	blank_1.value[locv + 4] = 1. / blank_1.value[locv + 4];
    }
    if (blank_1.value[locv + 9] != 0.) {
	blank_1.value[locv + 9] = 1. / blank_1.value[locv + 9];
    }
    if (blank_1.value[locv + 10] != 0.) {
	blank_1.value[locv + 10] = 1. / blank_1.value[locv + 10];
    }
    if (blank_1.value[locv + 18] != 0.) {
	blank_1.value[locv + 18] = 1. / blank_1.value[locv + 18];
    }
    if (blank_1.value[locv + 19] != 0.) {
	blank_1.value[locv + 19] = 1. / blank_1.value[locv + 19];
    }
    if (blank_1.value[locv + 25] != 0.) {
	blank_1.value[locv + 25] = 1. / blank_1.value[locv + 25] / 1.44;
    }
    blank_1.value[locv + 27] = blank_1.value[locv + 27] / knstnt_1.rad * 
	    blank_1.value[locv + 23];
    if (blank_1.value[locv + 34] != 0.) {
	blank_1.value[locv + 34] = 1. / blank_1.value[locv + 34] / 1.44;
    }
    pe = blank_1.value[locv + 21];
    xme = blank_1.value[locv + 22];
    pc = blank_1.value[locv + 29];
    xmc = blank_1.value[locv + 30];
    fc = blank_1.value[locv + 45];
    blank_1.value[locv + 45] = fc * pe;
    xfc = log(1. - fc);
    blank_1.value[locv + 46] = pe * (1. - exp((1. - xme) * xfc)) / (1. - xme);
    blank_1.value[locv + 47] = exp((xme + 1.) * xfc);
    blank_1.value[locv + 48] = 1. - fc * (xme + 1.);
    blank_1.value[locv + 49] = fc * pc;
    blank_1.value[locv + 50] = pc * (1. - exp((1. - xmc) * xfc)) / (1. - xmc);
    blank_1.value[locv + 51] = exp((xmc + 1.) * xfc);
    blank_1.value[locv + 52] = 1. - fc * (xmc + 1.);
    csat = blank_1.value[locv];
    blank_1.value[locv + 53] = status_1.vt * log(status_1.vt / (
	    knstnt_1.root2 * csat));
    loc = nodplc[loc - 1];
    goto L430;

/*  JFET MODELS */

L440:
    loc = cirdat_1.locate[22];
L450:
    if (loc == 0) {
	goto L460;
    }
    locv = nodplc[loc];
    if (blank_1.value[locv + 3] != 0.) {
	blank_1.value[locv + 3] = 1. / blank_1.value[locv + 3];
    }
    if (blank_1.value[locv + 4] != 0.) {
	blank_1.value[locv + 4] = 1. / blank_1.value[locv + 4];
    }
    pb = blank_1.value[locv + 7];
    xm = .5;
    fc = blank_1.value[locv + 11];
    blank_1.value[locv + 11] = fc * pb;
    xfc = log(1. - fc);
    blank_1.value[locv + 12] = pb * (1. - exp((1. - xm) * xfc)) / (1. - xm);
    blank_1.value[locv + 13] = exp((xm + 1.) * xfc);
    blank_1.value[locv + 14] = 1. - fc * (xm + 1.);
    csat = blank_1.value[locv + 8];
    blank_1.value[locv + 15] = status_1.vt * log(status_1.vt / (
	    knstnt_1.root2 * csat));
    loc = nodplc[loc - 1];
    goto L450;

/*  MOSFET MODELS */

L460:
    loc = cirdat_1.locate[23];
L470:
    if (loc == 0) {
	goto L600;
    }
    locv = nodplc[loc];
    type__ = (doublereal) nodplc[loc + 1];
    if (blank_1.value[locv + 6] != 0.) {
	blank_1.value[locv + 6] = 1. / blank_1.value[locv + 6];
    }
    if (blank_1.value[locv + 7] != 0.) {
	blank_1.value[locv + 7] = 1. / blank_1.value[locv + 7];
    }
    if (blank_1.value[locv + 15] != 0.) {
	blank_1.value[locv + 15] = 1. / blank_1.value[locv + 15];
    }
    blank_1.value[locv + 22] *= 1e6;
    blank_1.value[locv + 23] *= 1e4;
    blank_1.value[locv + 24] *= 1e4;
    if (blank_1.value[locv + 21] != 0.) {
	blank_1.value[locv + 21] = knstnt_1.epsox / blank_1.value[locv + 21];
    }
    blank_1.value[locv + 28] *= 1e-4;
    if (lev == 3) {
	goto L472;
    }
    blank_1.value[locv + 29] *= 100.;
    goto L473;

/*   MOVE MOS3 PARAMETERS : THETA FROM LOCATIONS LOCV+40 TO LOCV+30 */
/*                          ETA                       41         31 */
/*                          KAPPA                     42         32 */
/*   AND REPLACE LOCV+6 BY (XD)**2 */

L472:
    blank_1.value[locv + 38] = blank_1.value[locv + 38] * .25 * 
	    knstnt_1.twopi * knstnt_1.epssil / blank_1.value[locv + 21];
    blank_1.value[locv + 29] = blank_1.value[locv + 39];
    blank_1.value[locv + 30] = blank_1.value[locv + 40] * 8.15e-22 / 
	    blank_1.value[locv + 21];
    blank_1.value[locv + 31] = blank_1.value[locv + 41];
    if (blank_1.value[locv + 22] > 0.) {
	blank_1.value[locv + 5] = (knstnt_1.epssil + knstnt_1.epssil) / (
		knstnt_1.charge * blank_1.value[locv + 22]);
    }

/*   NOISE PARAMETERS */

L473:
    pb = blank_1.value[locv + 11];
    xm = .5;
    fc = blank_1.value[locv + 37];
    blank_1.value[locv + 37] = fc * pb;
    xfc = log(1. - fc);
    blank_1.value[locv + 39] = pb * (1. - exp((1. - xm) * xfc)) / (1. - xm);
    blank_1.value[locv + 40] = exp((xm + 1.) * xfc);
    blank_1.value[locv + 41] = 1. - fc * (xm + 1.);
    blank_1.value[locv + 42] = -1.;
    blank_1.value[locv + 43] = blank_1.value[locv + 1] - type__ * 
	    blank_1.value[locv + 3] * sqrt(blank_1.value[locv + 4]);
/* L475: */
    if (blank_1.value[locv + 21] != 0. && lev != 3) {
	blank_1.value[locv + 29] = blank_1.value[locv + 29] * knstnt_1.epssil 
		/ blank_1.value[locv + 21];
    }
    loc = nodplc[loc - 1];
    goto L470;

/*  RESERVE ADDITIONAL NODES */

/*  DIODES */

L600:
    loc = cirdat_1.locate[10];
L610:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L700;
    }
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    if (blank_1.value[locm + 1] == 0.) {
	goto L620;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 3] = cirdat_1.numnod;
    goto L630;
L620:
    nodplc[loc + 3] = nodplc[loc + 1];
L630:
    loc = nodplc[loc - 1];
    goto L610;

/*  TRANSISTORS */

L700:
    loc = cirdat_1.locate[11];
L710:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L800;
    }
    nodplc[loc + 29] = nodplc[loc + 4];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    if (blank_1.value[locm + 15] == 0.) {
	goto L720;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 5] = cirdat_1.numnod;
    goto L730;
L720:
    nodplc[loc + 5] = nodplc[loc + 2];
L730:
    if (blank_1.value[locm + 19] == 0.) {
	goto L740;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 4] = cirdat_1.numnod;
    goto L750;
L740:
    nodplc[loc + 4] = nodplc[loc + 1];
L750:
    if (blank_1.value[locm + 18] == 0.) {
	goto L760;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 6] = cirdat_1.numnod;
    goto L770;
L760:
    nodplc[loc + 6] = nodplc[loc + 3];
L770:
    loc = nodplc[loc - 1];
    goto L710;

/*  JFETS */

L800:
    loc = cirdat_1.locate[12];
L810:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L900;
    }
    locm = nodplc[loc + 6];
    locm = nodplc[locm];
    if (blank_1.value[locm + 3] == 0.) {
	goto L820;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 4] = cirdat_1.numnod;
    goto L830;
L820:
    nodplc[loc + 4] = nodplc[loc + 1];
L830:
    if (blank_1.value[locm + 4] == 0.) {
	goto L840;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 5] = cirdat_1.numnod;
    goto L850;
L840:
    nodplc[loc + 5] = nodplc[loc + 3];
L850:
    loc = nodplc[loc - 1];
    goto L810;

/*  MOSFETS */

L900:
    loc = cirdat_1.locate[13];
L910:
    if (loc == 0) {
	goto L1000;
    }
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    locv = nodplc[loc];
    xleff = blank_1.value[locv] - blank_1.value[locm + 27] * 2.;
    if (xleff > 0.) {
	goto L915;
    }
    io___1021.ciunit = status_1.iofile;
    s_wsfe(&io___1021);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locm - 1], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
    if (nodplc[loc + 32] != 0) {
	goto L960;
    }
L915:
    if (blank_1.value[locm + 6] == 0. && blank_1.value[locm + 15] == 0.) {
	goto L920;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 5] = cirdat_1.numnod;
    goto L930;
L920:
    nodplc[loc + 5] = nodplc[loc + 1];
L930:
    if (blank_1.value[locm + 7] == 0. && blank_1.value[locm + 15] == 0.) {
	goto L940;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 6] = cirdat_1.numnod;
    goto L950;
L940:
    nodplc[loc + 6] = nodplc[loc + 3];
L950:
    ad = blank_1.value[locv + 2];
    as = blank_1.value[locv + 3];
    if (ad <= 0. || as <= 0. && blank_1.value[locm + 10] <= 0.) {
	blank_1.value[locm + 10] = 1e-14;
    }
L960:
    loc = nodplc[loc - 1];
    goto L910;

/*  TRANSMISSION LINES */

L1000:
    loc = cirdat_1.locate[16];
L1010:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L2000;
    }
    ++cirdat_1.numnod;
    nodplc[loc + 5] = cirdat_1.numnod;
    ++cirdat_1.numnod;
    nodplc[loc + 6] = cirdat_1.numnod;
    loc = nodplc[loc - 1];
    goto L1010;

/*  FINISHED */

L2000:
    return 0;
} /* modchk_ */

#undef cvalue
#undef nodplc
#undef ampar
#undef aundef
#undef cpar
#undef aptype
#undef antype
#undef titlem
#undef titlej
#undef titleb
#undef titled


/* Subroutine */ int topchk_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1073 = { "ELEMENT NODE TABLE              ", 0. };

#define toptit ((doublereal *)&equiv_1073)

    static integer idlist[4] = { 3,6,8,9 };
    static integer idlis2[4] = { 14,14,14,11 };
    static struct {
	char e_1[8];
	doublereal e_2;
	char e_3[8];
	doublereal e_4[2];
	char e_5[8];
	doublereal e_6;
	char e_7[16];
	doublereal e_8;
	char e_9[32];
	doublereal e_10[2];
	char e_11[8];
	doublereal e_12[3];
	} equiv_1074 = { "R       ", 0., "L       ", 0., 0., "E       ", 0., 
		"H       V       ", 0., "D       Q       J       M       ", 
		0., 0., "T       ", 0., 0., 0. };

#define aide ((doublereal *)&equiv_1074)

    static integer nnods[20] = { 2,2,2,0,2,2,2,2,2,2,2,4,3,4,4,4,4,0,0,0 };

    /* Format strings */
    static char fmt_1511[] = "(\0020\002,i7)";
    static char fmt_1521[] = "(\0020\002,i7,3x,12(1x,a8))";
    static char fmt_1526[] = "(11x,12(1x,a8))";
    static char fmt_1557[] = "(\0020*ERROR*:  LESS THAN 2 CONNECTIONS AT NOD"
	    "E \002,i6/)";
    static char fmt_1561[] = "(\0020*ERROR*:  NO DC PATH TO GROUND FROM NO"
	    "DE \002,i6/)";
    static char fmt_1711[] = "(\0020*ERROR*:  INDUCTOR/VOLTAGE SOURCE LOOP F"
	    "OUND, CONTAINING \002,a8/)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, id, loc, node, nloc, locv, kntr, node1, node2;
    extern /* Subroutine */ int getm4_(integer *, integer *), copy4_(integer *
	    , integer *, integer *), zero4_(integer *, integer *);
    static integer iflag, jflag, istop, jstop, ispot, kstop;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer change;
    static doublereal atable[12];
    static integer itabid, itable;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer kntlim;
    extern /* Subroutine */ int extmem_(integer *, integer *);
    static integer jstart, idcntr;
    extern /* Subroutine */ int clrmem_(integer *);

    /* Fortran I/O blocks */
    static cilist io___1057 = { 0, 0, 0, fmt_1511, 0 };
    static cilist io___1062 = { 0, 0, 0, fmt_1521, 0 };
    static cilist io___1063 = { 0, 0, 0, fmt_1526, 0 };
    static cilist io___1064 = { 0, 0, 0, fmt_1521, 0 };
    static cilist io___1065 = { 0, 0, 0, fmt_1526, 0 };
    static cilist io___1066 = { 0, 0, 0, fmt_1557, 0 };
    static cilist io___1067 = { 0, 0, 0, fmt_1561, 0 };
    static cilist io___1072 = { 0, 0, 0, fmt_1711, 0 };



/*     THIS ROUTINE CONSTRUCTS THE ELEMENT NODE TABLE.  IT ALSO CHECKS */
/* FOR VOLTAGE SOURCE/INDUCTOR LOOPS, CURRENT SOURCE/CAPACITOR CUTSETS, */
/* AND THAT EVERY NODE HAS A DC (CONDUCTIVE) PATH TO GROUND */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */



/*  ALLOCATE STORAGE */

    getm4_(&tabinf_1.iorder, &cirdat_1.ncnods);
    i__1 = cirdat_1.ncnods + 1;
    getm4_(&tabinf_1.iur, &i__1);

/*  CONSTRUCT NODE TABLE */

    kntlim = miscel_1.lwidth / 11;
/* L1300: */
    getm4_(&itable, &c__0);
    getm4_(&itabid, &c__0);
    istop = cirdat_1.ncnods + 1;
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1310: */
	nodplc[tabinf_1.iur + i__ - 1] = 1;
    }
    for (id = 1; id <= 18; ++id) {
	if (nnods[id - 1] == 0) {
	    goto L1370;
	}
	loc = cirdat_1.locate[id - 1];
L1320:
	if (loc == 0) {
	    goto L1370;
	}
	nloc = loc + 1;
	jstop = nnods[id - 1];
/* L1330: */
	i__1 = jstop;
	for (j = 1; j <= i__1; ++j) {
	    node = nodplc[nloc + j - 1];
	    ispot = nodplc[tabinf_1.iur + node];
	    k = nodplc[tabinf_1.iur + cirdat_1.ncnods];
	    extmem_(&itable, &c__1);
	    extmem_(&itabid, &c__1);
	    if (k <= ispot) {
		goto L1340;
	    }
	    i__2 = k - ispot;
	    copy4_(&nodplc[itable + ispot - 1], &nodplc[itable + ispot], &
		    i__2);
	    i__2 = k - ispot;
	    copy4_(&nodplc[itabid + ispot - 1], &nodplc[itabid + ispot], &
		    i__2);
L1340:
	    nodplc[itable + ispot - 1] = loc;
	    nodplc[itabid + ispot - 1] = id;
/* ...  TREAT THE SUBSTRATE NODE OF A MOSFET AS IF IT WERE A TRANSMISSION */
/* ...  LINE NODE, I.E. LET IT DANGLE IF DESIRED */
	    if (id == 14 && j == 4) {
		nodplc[itabid + ispot - 1] = 17;
	    }
	    k = node;
	    kstop = cirdat_1.ncnods + 1;
L1350:
	    ++k;
	    if (k > kstop) {
		goto L1360;
	    }
	    ++nodplc[tabinf_1.iur + k - 1];
	    goto L1350;
L1360:
	    ;
	}
	loc = nodplc[loc - 1];
	goto L1320;
L1370:
	;
    }

/*  CHECK THAT EVERY NODE HAS A DC PATH TO GROUND */

    zero4_(&nodplc[tabinf_1.iorder], &cirdat_1.ncnods);
    nodplc[tabinf_1.iorder] = 1;
L1420:
    iflag = 0;
    i__1 = cirdat_1.ncnods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (nodplc[tabinf_1.iorder + i__ - 1] == 1) {
	    goto L1470;
	}
	jstart = nodplc[tabinf_1.iur + i__ - 1];
	jstop = nodplc[tabinf_1.iur + i__] - 1;
	if (jstart > jstop) {
	    goto L1470;
	}
	i__2 = jstop;
	for (j = jstart; j <= i__2; ++j) {
	    loc = nodplc[itable + j - 1];
	    id = nodplc[itabid + j - 1];
	    if (aide[id - 1] == 0.) {
		goto L1450;
	    }
	    if (id == 17) {
		goto L1445;
	    }
	    kstop = loc + nnods[id - 1] - 1;
	    i__3 = kstop;
	    for (k = loc; k <= i__3; ++k) {
		node = nodplc[k + 1];
		if (nodplc[tabinf_1.iorder + node - 1] == 1) {
		    goto L1460;
		}
/* L1440: */
	    }
	    goto L1450;
L1445:
	    if (nodplc[loc + 1] == i__) {
		node = nodplc[loc + 2];
	    }
	    if (nodplc[loc + 2] == i__) {
		node = nodplc[loc + 1];
	    }
	    if (nodplc[loc + 3] == i__) {
		node = nodplc[loc + 4];
	    }
	    if (nodplc[loc + 4] == i__) {
		node = nodplc[loc + 3];
	    }
	    if (nodplc[tabinf_1.iorder + node - 1] == 1) {
		goto L1460;
	    }
L1450:
	    ;
	}
	goto L1470;
L1460:
	nodplc[tabinf_1.iorder + i__ - 1] = 1;
	iflag = 1;
L1470:
	;
    }
    if (iflag == 1) {
	goto L1420;
    }

/*  PRINT NODE TABLE AND TOPOLOGY ERROR MESSAGES */

    if (flags_1.iprntn == 0) {
	goto L1510;
    }
    title_(&c__0, &miscel_1.lwidth, &c__1, toptit);
L1510:
    i__1 = cirdat_1.ncnods;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jstart = nodplc[tabinf_1.iur + i__ - 1];
	jstop = nodplc[tabinf_1.iur + i__] - 1;
	if (flags_1.iprntn == 0) {
	    goto L1550;
	}
	if (jstart <= jstop) {
	    goto L1520;
	}
	io___1057.ciunit = status_1.iofile;
	s_wsfe(&io___1057);
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	e_wsfe();
	goto L1550;
L1520:
	kntr = 0;
	jflag = 1;
	i__2 = jstop;
	for (j = jstart; j <= i__2; ++j) {
	    loc = nodplc[itable + j - 1];
	    locv = nodplc[loc];
	    ++kntr;
	    atable[kntr - 1] = blank_1.value[locv - 1];
	    if (kntr < kntlim) {
		goto L1540;
	    }
	    if (jflag == 0) {
		goto L1525;
	    }
	    jflag = 0;
	    io___1062.ciunit = status_1.iofile;
	    s_wsfe(&io___1062);
	    do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		    sizeof(integer));
	    i__3 = kntr;
	    for (k = 1; k <= i__3; ++k) {
		do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    goto L1530;
L1525:
	    io___1063.ciunit = status_1.iofile;
	    s_wsfe(&io___1063);
	    i__3 = kntr;
	    for (k = 1; k <= i__3; ++k) {
		do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
L1530:
	    kntr = 0;
L1540:
	    ;
	}
	if (kntr == 0) {
	    goto L1550;
	}
	if (jflag == 0) {
	    goto L1545;
	}
	io___1064.ciunit = status_1.iofile;
	s_wsfe(&io___1064);
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	i__2 = kntr;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	goto L1550;
L1545:
	io___1065.ciunit = status_1.iofile;
	s_wsfe(&io___1065);
	i__2 = kntr;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__1, (char *)&atable[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
L1550:
	if ((i__2 = jstart - jstop) < 0) {
	    goto L1560;
	} else if (i__2 == 0) {
	    goto L1552;
	} else {
	    goto L1556;
	}

/*  ALLOW NODE WITH ONLY ONE CONNECTION IFF ELEMENT IS A T-LINE */

L1552:
	if (nodplc[itabid + jstart - 1] == 17) {
	    goto L1560;
	}
L1556:
	flags_1.nogo = 1;
	io___1066.ciunit = status_1.iofile;
	s_wsfe(&io___1066);
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	e_wsfe();
	goto L1590;
L1560:
	if (nodplc[tabinf_1.iorder + i__ - 1] == 1) {
	    goto L1590;
	}
	flags_1.nogo = 1;
	io___1067.ciunit = status_1.iofile;
	s_wsfe(&io___1067);
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	e_wsfe();
L1590:
	;
    }

/*  CHECK FOR INDUCTOR/VOLTAGE SOURCE LOOPS */

    i__1 = cirdat_1.ncnods;
    for (i__ = 1; i__ <= i__1; ++i__) {
	zero4_(&nodplc[tabinf_1.iorder], &cirdat_1.ncnods);
	nodplc[tabinf_1.iorder + i__ - 1] = -1;
L1605:
	change = 0;
	for (idcntr = 1; idcntr <= 4; ++idcntr) {
	    id = idlist[idcntr - 1];
	    loc = cirdat_1.locate[id - 1];
L1610:
	    if (loc == 0 || nodplc[loc + idlis2[idcntr - 1] - 1] != 0) {
		goto L1690;
	    }
	    node1 = nodplc[loc + 1];
	    node2 = nodplc[loc + 2];
	    if (nodplc[tabinf_1.iorder + node1 - 1] == loc || nodplc[
		    tabinf_1.iorder + node2 - 1] == loc) {
		goto L1680;
	    }
	    if ((i__2 = nodplc[tabinf_1.iorder + node1 - 1]) < 0) {
		goto L1620;
	    } else if (i__2 == 0) {
		goto L1640;
	    } else {
		goto L1630;
	    }
L1620:
	    nodplc[tabinf_1.iorder + node1 - 1] = loc;
	    change = 1;
L1630:
	    node = node2;
	    goto L1670;
L1640:
	    if ((i__2 = nodplc[tabinf_1.iorder + node2 - 1]) < 0) {
		goto L1650;
	    } else if (i__2 == 0) {
		goto L1680;
	    } else {
		goto L1660;
	    }
L1650:
	    nodplc[tabinf_1.iorder + node2 - 1] = loc;
	    change = 1;
L1660:
	    node = node1;
L1670:
	    if (nodplc[tabinf_1.iorder + node - 1] != 0) {
		goto L1710;
	    }
	    nodplc[tabinf_1.iorder + node - 1] = loc;
	    change = 1;
L1680:
	    loc = nodplc[loc - 1];
	    goto L1610;
L1690:
	    ;
	}
	if (change == 1) {
	    goto L1605;
	}
/* L1700: */
    }
    goto L1900;
/* ... LOOP FOUND */
L1710:
    locv = nodplc[loc];
    io___1072.ciunit = status_1.iofile;
    s_wsfe(&io___1072);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    e_wsfe();
    flags_1.nogo = 1;


L1900:
    clrmem_(&tabinf_1.iorder);
    clrmem_(&tabinf_1.iur);
    clrmem_(&itable);
    clrmem_(&itabid);
/* L2000: */
    return 0;
} /* topchk_ */

#undef cvalue
#undef nodplc
#undef aide
#undef toptit


/* SPICE VERSION 2G.6  SCCSID=setup.ma 3/15/83 */
/* Subroutine */ int setup_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal t1, t2;
    static integer nic, loc, node;
    extern /* Subroutine */ int getm4_(integer *, integer *);
    extern integer indxx_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern logical memptr_(integer *);
    extern /* Subroutine */ int second_(doublereal *), clrmem_(integer *), 
	    matptr_(void), reordr_(void), matloc_(void), sizmem_(integer *, 
	    integer *);


/*     THIS ROUTINE DRIVES THE SPARSE MATRIX SETUP USED BY SPICE. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    second_(&t1);
    cirdat_1.nstop = cirdat_1.numnod + cirdat_1.jelcnt[2] + cirdat_1.jelcnt[5]
	     + cirdat_1.jelcnt[7] + cirdat_1.jelcnt[8] + (cirdat_1.jelcnt[16] 
	    << 1);

/*     CLEAR OLD TABLES */

    if (memptr_(&tabinf_1.irpt)) {
	clrmem_(&tabinf_1.irpt);
    }
    if (memptr_(&tabinf_1.jcpt)) {
	clrmem_(&tabinf_1.jcpt);
    }
    if (memptr_(&tabinf_1.irowno)) {
	clrmem_(&tabinf_1.irowno);
    }
    if (memptr_(&tabinf_1.jcolno)) {
	clrmem_(&tabinf_1.jcolno);
    }

/*  RESERVE MATRIX LOCATIONS FOR EACH ELEMENT */

    matptr_();
    if (flags_1.nogo != 0) {
	goto L1000;
    }

/*  REORDER MATRIX POINTERS */

    tabinf_1.nttbr = 0;
    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	loc = i__;
L110:
	if (nodplc[tabinf_1.jcpt + loc - 1] == 0) {
	    goto L120;
	}
	loc = nodplc[tabinf_1.jcpt + loc - 1];
	++tabinf_1.nttbr;
	goto L110;
L120:
	;
    }
/* ...  ADD GROUND */
    tabinf_1.nttar = tabinf_1.nttbr;
    reordr_();
    if (flags_1.nogo != 0) {
	goto L1000;
    }

/*  STORE MATRIX LOCATIONS */

    matloc_();

/*  .NODESET */

/* L200: */
    sizmem_(&tabinf_1.nsnod, &nic);
    if (nic == 0) {
	goto L220;
    }
    getm4_(&tabinf_1.nsmat, &nic);
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = nodplc[tabinf_1.nsnod + i__ - 1];
	nodplc[tabinf_1.nsmat + i__ - 1] = indxx_(&node, &node);
/* L210: */
    }

/*  TRANSIENT INITIAL CONDITIONS */

L220:
    sizmem_(&tabinf_1.icnod, &nic);
    if (nic == 0) {
	goto L300;
    }
    getm4_(&tabinf_1.icmat, &nic);
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = nodplc[tabinf_1.icnod + i__ - 1];
	nodplc[tabinf_1.icmat + i__ - 1] = indxx_(&node, &node);
/* L230: */
    }

L300:
    clrmem_(&tabinf_1.iseq);
    clrmem_(&tabinf_1.iseq1);
    clrmem_(&tabinf_1.neqn);
    clrmem_(&tabinf_1.nodevs);
    clrmem_(&tabinf_1.ndiag);

/*  FINISHED */

L1000:
    second_(&t2);
    miscel_1.rstats[1] = miscel_1.rstats[1] + t2 - t1;
    return 0;
} /* setup_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int matptr_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ni1, ni2, nl1, nl2, loc, kbr, ibr1, ibr2;
    static doublereal cdis;
    static integer node, ndim, locm, locn, node1, node2, node3, ndim2, node4, 
	    node5, node6, node7;
    extern /* Subroutine */ int getm4_(integer *, integer *), zero4_(integer *
	    , integer *);
    static integer ntemp, locvs;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int crunch_(void), slpmem_(integer *, integer *), 
	    reserv_(integer *, integer *);
    static integer locvst;


/*     THIS ROUTINE (BY CALLS TO THE ROUTINE RESERVE) ESTABLISHES THE */
/* NONZERO-ELEMENT STRUCTURE OF THE CIRCUIT EQUATION COEFFICIENT MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  ALLOCATE AND INITIALIZE STORAGE */

    i__1 = cirdat_1.nstop + 1;
    getm4_(&tabinf_1.isr, &i__1);
    cirdat_1.numvs = cirdat_1.jelcnt[2] + cirdat_1.jelcnt[5] + 
	    cirdat_1.jelcnt[7] + cirdat_1.jelcnt[8] + (cirdat_1.jelcnt[16] << 
	    1);
    getm4_(&tabinf_1.iseq, &cirdat_1.numvs);
    getm4_(&tabinf_1.iseq1, &cirdat_1.numvs);
    getm4_(&tabinf_1.neqn, &cirdat_1.numvs);
    getm4_(&tabinf_1.nodevs, &cirdat_1.numnod);
    getm4_(&tabinf_1.ndiag, &cirdat_1.nstop);
    getm4_(&tabinf_1.nmoffc, &cirdat_1.nstop);
    getm4_(&tabinf_1.numoff, &cirdat_1.nstop);
    getm4_(&tabinf_1.irpt, &cirdat_1.nstop);
    getm4_(&tabinf_1.jcpt, &cirdat_1.nstop);
    getm4_(&tabinf_1.irowno, &cirdat_1.nstop);
    getm4_(&tabinf_1.jcolno, &cirdat_1.nstop);
    slpmem_(&tabinf_1.irpt, &cirdat_1.nstop);
    slpmem_(&tabinf_1.jcpt, &cirdat_1.nstop);
    slpmem_(&tabinf_1.irowno, &cirdat_1.nstop);
    slpmem_(&tabinf_1.jcolno, &cirdat_1.nstop);
    crunch_();

    zero4_(&nodplc[tabinf_1.irpt], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.jcpt], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.irowno], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.jcolno], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.iseq1], &cirdat_1.numvs);
    zero4_(&nodplc[tabinf_1.nodevs], &cirdat_1.numnod);
    zero4_(&nodplc[tabinf_1.ndiag], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.nmoffc], &cirdat_1.nstop);
    zero4_(&nodplc[tabinf_1.numoff], &cirdat_1.nstop);

    cirdat_1.numvs = 0;
    cirdat_1.nxtrm = 0;
    cirdat_1.ndist = 0;
    cirdat_1.ntlin = 1;
    cirdat_1.ibr = cirdat_1.numnod;

/*  RESISTORS */

    loc = cirdat_1.locate[0];
L110:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L120;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    reserv_(&node1, &node1);
    reserv_(&node1, &node2);
    reserv_(&node2, &node1);
    reserv_(&node2, &node2);
    loc = nodplc[loc - 1];
    goto L110;

/*  CAPACITORS */

L120:
    loc = cirdat_1.locate[1];
L130:
    if (loc == 0 || nodplc[loc + 11] != 0) {
	goto L400;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    reserv_(&node1, &node2);
    reserv_(&node2, &node1);
    ntemp = nodplc[tabinf_1.ndiag + node1 - 1];
    reserv_(&node1, &node1);
    nodplc[tabinf_1.ndiag + node1 - 1] = ntemp;
    ntemp = nodplc[tabinf_1.ndiag + node2 - 1];
    reserv_(&node2, &node2);
    nodplc[tabinf_1.ndiag + node2 - 1] = ntemp;
    nodplc[loc + 7] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 2;
    loc = nodplc[loc - 1];
    goto L130;

/*  INDUCTORS */

L400:
    loc = cirdat_1.locate[2];
L430:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L440;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ++cirdat_1.ibr;
    nodplc[loc + 4] = cirdat_1.ibr;
    reserv_(&node1, &cirdat_1.ibr);
    reserv_(&node2, &cirdat_1.ibr);
    reserv_(&cirdat_1.ibr, &node1);
    reserv_(&cirdat_1.ibr, &node2);
    ntemp = nodplc[tabinf_1.ndiag + cirdat_1.ibr - 1];
    reserv_(&cirdat_1.ibr, &cirdat_1.ibr);
    nodplc[tabinf_1.ndiag + cirdat_1.ibr - 1] = ntemp;
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = cirdat_1.ibr;
    ++nodplc[tabinf_1.nodevs + node1 - 1];
    ++nodplc[tabinf_1.nodevs + node2 - 1];
    nodplc[loc + 10] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 2;
    loc = nodplc[loc - 1];
    goto L430;

/*  MUTUAL INDUCTORS */

L440:
    loc = cirdat_1.locate[3];
L450:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L460;
    }
    nl1 = nodplc[loc + 1];
    nl2 = nodplc[loc + 2];
    nl1 = nodplc[nl1 + 4];
    nl2 = nodplc[nl2 + 4];
    reserv_(&nl1, &nl2);
    reserv_(&nl2, &nl1);
    loc = nodplc[loc - 1];
    goto L450;

/*  NONLINEAR VOLTAGE-CONTROLLED CURRENT SOURCES */

L460:
    loc = cirdat_1.locate[4];
L462:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L464;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    ndim2 = ndim + ndim;
    locn = nodplc[loc + 5];
    i__1 = ndim2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = nodplc[locn + i__ - 1];
	reserv_(&node1, &node);
	reserv_(&node2, &node);
/* L463: */
    }
    nodplc[loc + 11] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm = cirdat_1.nxtrm + 1 + ndim2;
    loc = nodplc[loc - 1];
    goto L462;

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L464:
    loc = cirdat_1.locate[5];
L466:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L468;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ++cirdat_1.ibr;
    nodplc[loc + 5] = cirdat_1.ibr;
    reserv_(&node1, &cirdat_1.ibr);
    reserv_(&node2, &cirdat_1.ibr);
    reserv_(&cirdat_1.ibr, &node1);
    reserv_(&cirdat_1.ibr, &node2);
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = cirdat_1.ibr;
    ++nodplc[tabinf_1.nodevs + node1 - 1];
    ++nodplc[tabinf_1.nodevs + node2 - 1];
    ndim = nodplc[loc + 3];
    ndim2 = ndim + ndim;
    locn = nodplc[loc + 6];
    i__1 = ndim2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = nodplc[locn + i__ - 1];
	reserv_(&cirdat_1.ibr, &node);
/* L467: */
    }
    nodplc[loc + 12] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm = cirdat_1.nxtrm + 2 + ndim2;
    loc = nodplc[loc - 1];
    goto L466;

/*  VOLTAGE SOURCES */

L468:
    loc = cirdat_1.locate[8];
L470:
    if (loc == 0 || nodplc[loc + 10] != 0) {
	goto L472;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ++cirdat_1.ibr;
    nodplc[loc + 5] = cirdat_1.ibr;
    reserv_(&node1, &cirdat_1.ibr);
    reserv_(&node2, &cirdat_1.ibr);
    reserv_(&cirdat_1.ibr, &node1);
    reserv_(&cirdat_1.ibr, &node2);
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = cirdat_1.ibr;
    ++nodplc[tabinf_1.nodevs + node1 - 1];
    ++nodplc[tabinf_1.nodevs + node2 - 1];
    loc = nodplc[loc - 1];
    goto L470;

/*  NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */

L472:
    loc = cirdat_1.locate[6];
L474:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L476;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    locvs = nodplc[loc + 5];
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locvst = nodplc[locvs + i__ - 1];
	kbr = nodplc[locvst + 5];
	reserv_(&node1, &kbr);
	reserv_(&node2, &kbr);
/* L475: */
    }
    nodplc[loc + 11] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm = cirdat_1.nxtrm + 1 + ndim + ndim;
    loc = nodplc[loc - 1];
    goto L474;

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L476:
    loc = cirdat_1.locate[7];
L478:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L500;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ++cirdat_1.ibr;
    nodplc[loc + 5] = cirdat_1.ibr;
    reserv_(&node1, &cirdat_1.ibr);
    reserv_(&node2, &cirdat_1.ibr);
    reserv_(&cirdat_1.ibr, &node1);
    reserv_(&cirdat_1.ibr, &node2);
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = cirdat_1.ibr;
    ++nodplc[tabinf_1.nodevs + node1 - 1];
    ++nodplc[tabinf_1.nodevs + node2 - 1];
    ndim = nodplc[loc + 3];
    locvs = nodplc[loc + 6];
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locvst = nodplc[locvs + i__ - 1];
	kbr = nodplc[locvst + 5];
	reserv_(&cirdat_1.ibr, &kbr);
/* L479: */
    }
    nodplc[loc + 12] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm = cirdat_1.nxtrm + 2 + ndim + ndim;
    loc = nodplc[loc - 1];
    goto L478;

/*  DIODES */

L500:
    loc = cirdat_1.locate[10];
L510:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L520;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    reserv_(&node1, &node1);
    reserv_(&node2, &node2);
    reserv_(&node3, &node3);
    reserv_(&node1, &node3);
    reserv_(&node2, &node3);
    reserv_(&node3, &node1);
    reserv_(&node3, &node2);
    nodplc[loc + 10] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 5;
    nodplc[loc + 11] = cirdat_1.ndist + 1;
    cirdat_1.ndist += 7;
    loc = nodplc[loc - 1];
    goto L510;

/*  TRANSISTORS */

L520:
    loc = cirdat_1.locate[11];
L530:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L540;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    node7 = nodplc[loc + 29];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    cdis = blank_1.value[locm + 31];
    reserv_(&node1, &node1);
    reserv_(&node2, &node2);
    reserv_(&node3, &node3);
    reserv_(&node4, &node4);
    reserv_(&node5, &node5);
    reserv_(&node6, &node6);
    reserv_(&node1, &node4);
    reserv_(&node2, &node5);
    reserv_(&node3, &node6);
    reserv_(&node4, &node5);
    reserv_(&node4, &node6);
    reserv_(&node5, &node6);
    reserv_(&node4, &node1);
    reserv_(&node5, &node2);
    reserv_(&node6, &node3);
    reserv_(&node5, &node4);
    reserv_(&node6, &node4);
    reserv_(&node6, &node5);
    reserv_(&node7, &node7);
    reserv_(&node4, &node7);
    reserv_(&node7, &node4);
    if (cdis < 1.) {
	reserv_(&node2, &node4);
    }
    if (cdis < 1.) {
	reserv_(&node4, &node2);
    }
    nodplc[loc + 21] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 19;
    nodplc[loc + 22] = cirdat_1.ndist + 1;
    cirdat_1.ndist += 21;
    loc = nodplc[loc - 1];
    goto L530;

/*  JFETS */

L540:
    loc = cirdat_1.locate[12];
L550:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L560;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    reserv_(&node1, &node1);
    reserv_(&node2, &node2);
    reserv_(&node3, &node3);
    reserv_(&node4, &node4);
    reserv_(&node5, &node5);
    reserv_(&node1, &node4);
    reserv_(&node2, &node4);
    reserv_(&node2, &node5);
    reserv_(&node3, &node5);
    reserv_(&node4, &node5);
    reserv_(&node4, &node1);
    reserv_(&node4, &node2);
    reserv_(&node5, &node2);
    reserv_(&node5, &node3);
    reserv_(&node5, &node4);
    nodplc[loc + 18] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 13;
    loc = nodplc[loc - 1];
    goto L550;

/*  MOSFETS */

L560:
    loc = cirdat_1.locate[13];
L570:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L600;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    reserv_(&node1, &node1);
    reserv_(&node2, &node2);
    reserv_(&node3, &node3);
    reserv_(&node4, &node4);
    reserv_(&node5, &node5);
    reserv_(&node6, &node6);
    reserv_(&node1, &node5);
    reserv_(&node2, &node4);
    reserv_(&node2, &node5);
    reserv_(&node2, &node6);
    reserv_(&node3, &node6);
    reserv_(&node4, &node5);
    reserv_(&node4, &node6);
    reserv_(&node5, &node6);
    reserv_(&node5, &node1);
    reserv_(&node4, &node2);
    reserv_(&node5, &node2);
    reserv_(&node6, &node2);
    reserv_(&node6, &node3);
    reserv_(&node5, &node4);
    reserv_(&node6, &node4);
    reserv_(&node6, &node5);
    nodplc[loc + 25] = cirdat_1.nxtrm + 1;
    cirdat_1.nxtrm += 28;
    loc = nodplc[loc - 1];
    goto L570;

/*  TRANSMISSION LINES */

L600:
    loc = cirdat_1.locate[16];
L610:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L1000;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    ni1 = nodplc[loc + 5];
    ni2 = nodplc[loc + 6];
    ibr1 = cirdat_1.ibr + 1;
    ibr2 = cirdat_1.ibr + 2;
    cirdat_1.ibr += 2;
    nodplc[loc + 7] = ibr1;
    nodplc[loc + 8] = ibr2;
    reserv_(&node1, &node1);
    reserv_(&node1, &ni1);
    reserv_(&node2, &ibr1);
    reserv_(&node3, &node3);
    reserv_(&node4, &ibr2);
    reserv_(&ni1, &node1);
    reserv_(&ni1, &ni1);
    reserv_(&ni1, &ibr1);
    reserv_(&ni2, &ni2);
    reserv_(&ni2, &ibr2);
    reserv_(&ibr1, &node2);
    reserv_(&ibr1, &node3);
    reserv_(&ibr1, &node4);
    reserv_(&ibr1, &ni1);
    reserv_(&ibr1, &ibr2);
    reserv_(&ibr2, &node1);
    reserv_(&ibr2, &node2);
    reserv_(&ibr2, &node4);
    reserv_(&ibr2, &ni2);
    reserv_(&ibr2, &ibr1);
    reserv_(&node3, &ni2);
    reserv_(&ni2, &node3);
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.iseq1 + cirdat_1.numvs - 1] = 1;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = ibr1;
    ++nodplc[tabinf_1.nodevs + ni1 - 1];
    ++nodplc[tabinf_1.nodevs + node2 - 1];
    ++cirdat_1.numvs;
    nodplc[tabinf_1.iseq + cirdat_1.numvs - 1] = loc;
    nodplc[tabinf_1.iseq1 + cirdat_1.numvs - 1] = 2;
    nodplc[tabinf_1.neqn + cirdat_1.numvs - 1] = ibr2;
    ++nodplc[tabinf_1.nodevs + ni2 - 1];
    ++nodplc[tabinf_1.nodevs + node4 - 1];
    nodplc[loc + 29] = cirdat_1.ntlin + 1;
    cirdat_1.ntlin += 2;
    loc = nodplc[loc - 1];
    goto L610;

/*  FINISHED */

L1000:
    return 0;
} /* matptr_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int reordr_(void)
{
    /* Format strings */
    static char fmt_591[] = "(\0020*ABORT*:  SPICE INTERNAL ERROR IN REORD"
	    "R\002/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, j, l, ix, loc, node, locx, node1, node2;
    extern /* Subroutine */ int getm4_(integer *, integer *), copy4_(integer *
	    , integer *, integer *);
    static integer nflag, nodex, ltemp, nextv;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int swapij_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___1125 = { 0, 0, 0, fmt_591, 0 };



/*     THIS ROUTINE SWAPS ROWS IN THE COEFFICIENT MATRIX TO ELIMINATE */
/* SINGULARITY PROBLEMS WHICH CAN BE RECOGNIZED BY EXAMINING THE CIRCUIT */
/* TOPOLOGY. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */

/*  ALLOCATE AND INITIALIZE STORAGE */

    getm4_(&tabinf_1.irswpf, &cirdat_1.nstop);
    getm4_(&tabinf_1.irswpr, &cirdat_1.nstop);
    getm4_(&tabinf_1.icswpf, &cirdat_1.nstop);
    getm4_(&tabinf_1.icswpr, &cirdat_1.nstop);

    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nodplc[tabinf_1.irswpf + i__ - 1] = i__;
/* L10: */
    }
    copy4_(&nodplc[tabinf_1.irswpf], &nodplc[tabinf_1.irswpr], &
	    cirdat_1.nstop);
    copy4_(&nodplc[tabinf_1.irswpf], &nodplc[tabinf_1.icswpf], &
	    cirdat_1.nstop);
    copy4_(&nodplc[tabinf_1.irswpf], &nodplc[tabinf_1.icswpr], &
	    cirdat_1.nstop);

/*  SWAP CURRENT EQUATIONS INTO ADMITTANCE PART OF EQUATION MATRIX */

    nextv = 1;

/*  FIND SUITABLE VOLTAGE SOURCE */

L100:
    if (nextv > cirdat_1.numvs) {
	goto L600;
    }
    ix = 0;
    i__1 = cirdat_1.numvs;
    for (i__ = nextv; i__ <= i__1; ++i__) {
	loc = nodplc[tabinf_1.iseq + i__ - 1];
	node = nodplc[loc + 1];
	nflag = nodplc[tabinf_1.iseq1 + i__ - 1];
	if (nflag == 1) {
	    node = nodplc[loc + 5];
	}
	if (nflag == 2) {
	    node = nodplc[loc + 6];
	}
	if (node == 1) {
	    goto L110;
	}
	if (nodplc[tabinf_1.nodevs + node - 1] >= 2) {
	    goto L110;
	}
	if (nodplc[tabinf_1.ndiag + node - 1] == 0) {
	    goto L145;
	}
	ix = i__;
	locx = loc;
	nodex = node;
L110:
	node = nodplc[loc + 2];
	if (nflag == 2) {
	    node = nodplc[loc + 4];
	}
	if (node == 1) {
	    goto L130;
	}
	if (nodplc[tabinf_1.nodevs + node - 1] >= 2) {
	    goto L130;
	}
/* L120: */
	if (nodplc[tabinf_1.ndiag + node - 1] == 0) {
	    goto L145;
	}
	ix = i__;
	locx = loc;
	nodex = node;
L130:
	;
    }
    if (ix == 0) {
	goto L590;
    }
    i__ = ix;
    loc = locx;
    node = nodex;

/*  RESEQUENCE VOLTAGE SOURCES */

L145:
    nodplc[tabinf_1.iseq + i__ - 1] = nodplc[tabinf_1.iseq + nextv - 1];
    nodplc[tabinf_1.iseq + nextv - 1] = loc;
    ltemp = nodplc[tabinf_1.iseq1 + i__ - 1];
    nodplc[tabinf_1.iseq1 + i__ - 1] = nodplc[tabinf_1.iseq1 + nextv - 1];
    nodplc[tabinf_1.iseq1 + nextv - 1] = ltemp;
    cirdat_1.ibr = nodplc[tabinf_1.neqn + i__ - 1];
    nodplc[tabinf_1.neqn + i__ - 1] = nodplc[tabinf_1.neqn + nextv - 1];
    nodplc[tabinf_1.neqn + nextv - 1] = cirdat_1.ibr;
    node1 = nodplc[loc + 1];
    if (ltemp == 1) {
	node1 = nodplc[loc + 5];
    }
    if (ltemp == 2) {
	node1 = nodplc[loc + 6];
    }
    node2 = nodplc[loc + 2];
    if (ltemp == 1) {
	node2 = nodplc[loc + 2];
    }
    if (ltemp == 2) {
	node2 = nodplc[loc + 4];
    }
    --nodplc[tabinf_1.nodevs + node1 - 1];
    --nodplc[tabinf_1.nodevs + node2 - 1];

/*  SET ROW SWAP INDICATORS */

    l = nodplc[tabinf_1.irswpf + cirdat_1.ibr - 1];
    j = nodplc[tabinf_1.irswpr + node - 1];
    nodplc[tabinf_1.irswpf + j - 1] = l;
    nodplc[tabinf_1.irswpr + l - 1] = j;
    nodplc[tabinf_1.irswpf + cirdat_1.ibr - 1] = node;
    nodplc[tabinf_1.irswpr + node - 1] = cirdat_1.ibr;
    swapij_(&cirdat_1.ibr, &j, &c__1, &c__1);
    ++nextv;
    goto L100;


/*  ERROR - VOLTAGE-SOURCE/INDUCTOR/TRANSMISSION-LINE LOOP DETECTED ... */

L590:
    flags_1.nogo = 1;
    io___1125.ciunit = status_1.iofile;
    s_wsfe(&io___1125);
    e_wsfe();
/* ...  LOOP SHOULD HAVE BEEN DETECTED IN TOPCHK */

/*  FINISHED */

L600:
    return 0;
} /* reordr_ */

#undef cvalue
#undef nodplc


/* SPICE VERSION 2G.6  SCCSID=dctran.ma 3/15/83 */
/* Subroutine */ int dctran_(void)
{
    /* Initialized data */

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_1218 = { "( (2X,A4,3X,A7,3X)//)   ", 0. };

#define avhdr ((doublereal *)&equiv_1218)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_1219 = { "( (1H ,A1,I3,1H),F10.4,3X)/)    ", 0. };

#define avfrm ((doublereal *)&equiv_1219)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1220 = { "NODE    ", 0. };

#define anode (*(doublereal *)&equiv_1220)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1221 = { "VOLTAGE ", 0. };

#define avltg (*(doublereal *)&equiv_1221)

    static struct {
	char e_1[64];
	doublereal e_2;
	} equiv_1222 = { "SMALL SIGNAL BIAS SOLUTION      INITIAL TRANSIENT "
		"SOLUTION      ", 0. };

#define subtit ((doublereal *)&equiv_1222)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_1223 = { "(   ", 0 };

#define lprn (*(integer *)&equiv_1223)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1224 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_1224)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1225 = { "R       ", 0. };

#define aletr (*(doublereal *)&equiv_1225)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1226 = { "T       ", 0. };

#define alett (*(doublereal *)&equiv_1226)


    /* Format strings */
    static char fmt_26[] = "(\0020INSUFFICIENT MEMORY AVAILABLE FOR DC ANALY"
	    "SIS.\002,/\002 MEMORY REQUIRED \002,i6,\002, MEMORY AVAILABLE"
	    " \002,i6,\002.\002)";
    static char fmt_151[] = "(\0021*ERROR*:  NO CONVERGENCE IN DC ANALYSI"
	    "S\002/\0020LAST NODE VOL\002,\002TAGES:\002/)";
    static char fmt_451[] = "(\0021*ERROR*:  NO CONVERGENCE IN DC TRANSFER C"
	    "URVES AT \002,a8,\002 = \002,1pd10.3/\0020LAST NODE VOLTAGES:"
	    "\002/)";
    static char fmt_461[] = "(\0020*ERROR*:  CPU TIME LIMIT EXCEEDED ... ANA"
	    "LYSIS STOPPED\002/)";
    static char fmt_463[] = "(\0020*ERROR*:   TEMPERATURE SWEEP SHOULD BE TH"
	    "E SECOND SWEEP  SOURCE, CHANGE THE ORDER AND RE-EXECUTE\002/)";
    static char fmt_492[] = "(/,\0020*****0 RETURN TO ORIGINAL TEMPERATURE 0"
	    "*****0\002,/)";
    static char fmt_901[] = "(\0021*ERROR*:  INTERNAL TIMESTEP TOO SMALL IN "
	    "TRANSIENT ANALYSIS\002/)";
    static char fmt_906[] = "(\0021*ERROR*:  TRANSIENT ANALYSIS ITERATIONS E"
	    "XCEED LIMIT OF \002,i5,/\0020THIS LIMIT MAY BE OVERRIDDEN USING "
	    "THE ITL5 PARAMETER ON THE .OPTION CARD\002)";
    static char fmt_911[] = "(\0020\002,10x,\002TIME = \002,1pd12.5,\002;  D"
	    "ELTA = \002,d12.5,\002;  NUMNIT = \002,i6/)";
    static char fmt_916[] = "(\0020\002/\0020LAST NODE VOLTAGES:\002/)";
    static char fmt_921[] = "(\0020*ERROR*:  CPU TIME LIMIT EXCEEDED IN TRAN"
	    "SIENT ANALYSIS \002,\002AT TIME = \002,1pd13.6/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    static doublereal t1, t2, z0;
    static integer loc;
    extern /* Subroutine */ int bjt_(void);
    static doublereal del1;
    static integer ibr1, ibr2, need;
    static doublereal anam;
    static integer loce;
    extern /* Subroutine */ int jfet_(void);
    static integer loco, jord, navl, locs, ipos;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static doublereal temp;
    static integer iptr, locv, ical2, node1, node2, node3, node4, locs2;
    extern /* Subroutine */ int getm8_(integer *, integer *), avlm8_(integer *
	    ), iter8_(integer *);
    static doublereal temv2;
    static integer nolx2, nolx3;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *);
    static integer ibuff;
    extern /* Subroutine */ int diode_(void);
    static integer itemp;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer numtp, nbkpt;
    extern /* Subroutine */ int trunc_(doublereal *);
    static integer numtd, lcntr, ltemp, lspot, icvfl1, icvfl2, irdct2, itdct2,
	     ibkflg;
    extern /* Subroutine */ int getcje_(void);
    static doublereal delbkp;
    extern /* Subroutine */ int pheadr_(doublereal *), comcof_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern logical memptr_(integer *);
    extern /* Subroutine */ int second_(doublereal *);
    static integer loctim, numcur, numpos, loccur, nvprln;
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *), 
	    slpmem_(integer *, integer *), crunch_(void), sorupd_(void), 
	    sorstp_(integer *), mosfet_(void);
    static integer numout, irdctc, itdctc;
    static doublereal temval;
    extern /* Subroutine */ int tmpupd_(void), extmem_(integer *, integer *), 
	    fwrite_(doublereal *, integer *), ptrmem_(integer *, integer *), 
	    relmem_(integer *, integer *);
    static integer numese, numrtp, numnit;
    static doublereal delnew, delmin;
    static integer itrlim;
    extern /* Subroutine */ int clrmem_(integer *);
    static doublereal ordrat;
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    static integer ltdsiz;
    static doublereal baktim;
    static integer nwords, ltdptr;
    extern /* Subroutine */ int clsraw_(void);

    /* Fortran I/O blocks */
    static cilist io___1150 = { 0, 0, 0, fmt_26, 0 };
    static cilist io___1151 = { 0, 0, 0, (char *)avhdr, 0 };
    static cilist io___1153 = { 0, 0, 0, (char *)avfrm, 0 };
    static cilist io___1154 = { 0, 0, 0, fmt_151, 0 };
    static cilist io___1155 = { 0, 0, 0, (char *)avhdr, 0 };
    static cilist io___1156 = { 0, 0, 0, (char *)avfrm, 0 };
    static cilist io___1177 = { 0, 0, 0, fmt_451, 0 };
    static cilist io___1178 = { 0, 0, 0, (char *)avhdr, 0 };
    static cilist io___1179 = { 0, 0, 0, (char *)avfrm, 0 };
    static cilist io___1180 = { 0, 0, 0, fmt_461, 0 };
    static cilist io___1181 = { 0, 0, 0, fmt_463, 0 };
    static cilist io___1182 = { 0, 0, 0, fmt_492, 0 };
    static cilist io___1210 = { 0, 0, 0, fmt_901, 0 };
    static cilist io___1211 = { 0, 0, 0, fmt_906, 0 };
    static cilist io___1212 = { 0, 0, 0, fmt_911, 0 };
    static cilist io___1213 = { 0, 0, 0, fmt_916, 0 };
    static cilist io___1214 = { 0, 0, 0, (char *)avhdr, 0 };
    static cilist io___1215 = { 0, 0, 0, (char *)avfrm, 0 };
    static cilist io___1216 = { 0, 0, 0, fmt_921, 0 };




/*     THIS ROUTINE CONTROLS THE DC TRANSFER CURVE, DC OPERATING POINT, */
/* AND TRANSIENT ANALYSES.  THE VARIABLES MODE AND MODEDC (DEFINED BELOW) */
/* DETERMINE EXACTLY WHICH ANALYSIS IS PERFORMED. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



/*      THE VARIABLES *MODE*, *MODEDC*, AND *INITF* ARE USED BY SPICE TO */
/* KEEP TRACK OF THE STATE OF THE ANALYSIS.  THE VALUES OF THESE FLAGS */
/* (AND THE CORRESPONDING MEANINGS) ARE AS FOLLOWS: */

/*        FLAG    VALUE    MEANING */
/*        ----    -----    ------- */

/*        MODE      1      DC ANALYSIS (SUBTYPE DEFINED BY *MODEDC*) */
/*                  2      TRANSIENT ANALYSIS */
/*                  3      AC ANALYSIS (SMALL SIGNAL) */

/*        MODEDC    1      DC OPERATING POINT */
/*                  2      INITIAL OPERATING POINT FOR TRANSIENT ANALYSIS */
/*                  3      DC TRANSFER CURVE COMPUTATION */

/*        INITF     1      CONVERGE WITH 'OFF' DEVICES ALLOWED TO FLOAT */
/*                  2      INITIALIZE JUNCTION VOLTAGES */
/*                  3      CONVERGE WITH 'OFF' DEVICES HELD 'OFF' */
/*                  4      STORE SMALL-SIGNAL PARAMETERS AWAY */
/*                  5      FIRST TIMEPOINT IN TRANSIENT ANALYSIS */
/*                  6      PREDICTION STEP */

/* NOTE:  *MODEDC* IS ONLY SIGNIFICANT IF *MODE* = 1. */


/*  INITIALIZE */

    second_(&t1);
    status_1.sfactr = 1.;
/* .. DON'T TAKE ANY CHANCES WITH LX3, SET TO LARGE NUMBER */
    tabinf_1.lx3 = 20000000;
    tabinf_1.lx2 = 20000000;
/* .. SEE IF LX3 AND LX2 TABLES ARE NEEDED */
    nolx2 = 0;
    nolx3 = 0;
/* L20: */
    loctim = 5;

/* .. POST-PROCESSING INITIALIZATION */

    if (status_1.ipostp == 0) {
	goto L25;
    }
    numcur = cirdat_1.jelcnt[8];
    numpos = cirdat_1.nunods + numcur;
    getm8_(&ibuff, &numpos);
    numpos <<= 2;
    if (numcur == 0) {
	goto L25;
    }
    loc = cirdat_1.locate[8];
    loccur = nodplc[loc + 5] - 1;

/* ...  SET UP FORMAT */

L25:
    nvprln = (miscel_1.lwidth - 72) / 19 + 4;
/* Computing MIN */
    i__1 = nvprln, i__2 = cirdat_1.ncnods - 1;
    nvprln = min(i__1,i__2);
    ipos = 2;
    alfnum_(&nvprln, avfrm, &ipos);
    ipos = 2;
    alfnum_(&nvprln, avhdr, &ipos);
/* ...  ALLOCATE STORAGE */
    if (status_1.mode == 2) {
	goto L35;
    }
    need = (cirdat_1.nstop << 2) + tabinf_1.nttbr + cirdat_1.nxtrm;
    avlm8_(&navl);
    if (need <= navl) {
	goto L30;
    }
/* ...  NOT ENOUGH MEMORY FOR DC OPERATING POINT ANALYSIS */
    io___1150.ciunit = status_1.iofile;
    s_wsfe(&io___1150);
    do_fio(&c__1, (char *)&need, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&navl, (ftnlen)sizeof(integer));
    e_wsfe();
    flags_1.nogo = 1;
    goto L1100;
L30:
    getm8_(&tabinf_1.lvnim1, &cirdat_1.nstop);
    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    getm8_(&tabinf_1.lvn, &i__1);
    slpmem_(&tabinf_1.lvn, &cirdat_1.nstop);
    getm8_(&tabinf_1.lx0, &cirdat_1.nxtrm);
    getm8_(&tabinf_1.lvntmp, &cirdat_1.nstop);
    if (status_1.modedc != 3) {
	goto L45;
    }
L35:
    getm8_(&tabinf_1.lx1, &cirdat_1.nxtrm);
    if (nolx2 == 0) {
	getm8_(&tabinf_1.lx2, &cirdat_1.nxtrm);
    }
    if (status_1.mode != 2) {
	goto L40;
    }
    if (nolx3 == 0) {
	getm8_(&tabinf_1.lx3, &cirdat_1.nxtrm);
    }
    getm8_(&tabinf_1.ltd, &c__0);
L40:
    getm8_(&tabinf_1.loutpt, &c__0);
L45:
    crunch_();
/* L50: */
    if (status_1.mode == 2) {
	goto L500;
    }
    status_1.time = 0.;
    status_1.ag[0] = 0.;
    sorupd_();
    if (status_1.modedc == 3) {
	goto L300;
    }


/*  ....  SINGLE POINT DC ANALYSIS */


/*  COMPUTE DC OPERATING POINT */

/* L100: */
    if (flags_1.itl6 > 0) {
	goto L105;
    }
    status_1.initf = 2;
    iter8_(&flags_1.itl1);
    miscel_1.rstats[5] += status_1.iterno;
    if (flags_1.igoof != 0) {
	goto L150;
    }
    goto L110;
L105:
    sorstp_(&flags_1.itl6);
    miscel_1.rstats[5] += status_1.iterno;
    if (flags_1.igoof != 0) {
	goto L150;
    }
L110:
    if (status_1.modedc != 1) {
	goto L120;
    }
    status_1.initf = 4;
    diode_();
    bjt_();
    jfet_();
    mosfet_();

/*  PRINT OPERATING POINT */

L120:
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L1000;
    }
    title_(&c_n1, &miscel_1.lwidth, &c__1, &subtit[(status_1.modedc << 2) - 4]
	    );
    io___1151.ciunit = status_1.iofile;
    s_wsfe(&io___1151);
    i__1 = nvprln;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anode, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avltg, (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___1153.ciunit = status_1.iofile;
    s_wsfe(&io___1153);
    i__1 = cirdat_1.ncnods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&lprn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvnim1 + i__ - 1], (
		ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L1000;

/*  NO CONVERGENCE */

L150:
    flags_1.nogo = 1;
    io___1154.ciunit = status_1.iofile;
    s_wsfe(&io___1154);
    e_wsfe();
    io___1155.ciunit = status_1.iofile;
    s_wsfe(&io___1155);
    i__1 = nvprln;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anode, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avltg, (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___1156.ciunit = status_1.iofile;
    s_wsfe(&io___1156);
    i__1 = cirdat_1.ncnods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&lprn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvnim1 + i__ - 1], (
		ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L1000;

/*  ....  DC TRANSFER CURVES */

L300:
    numout = cirdat_1.jelcnt[40] + 1;
    if (status_1.ipostp != 0) {
	pheadr_(miscel_1.atitle);
    }
    itemp = dc_1.itcelm[0];
    locs = nodplc[itemp];
    anam = blank_1.value[locs - 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    irdctc = 0;
    irdct2 = 0;
    itdctc = 0;
    itdct2 = 0;
    if (anam == aletr) {
	irdctc = 1;
    }
    if (anam == alett) {
	itdctc = 1;
    }
    temval = blank_1.value[locs];
    icvfl2 = 1;
    if (dc_1.itcelm[1] == 0) {
	goto L310;
    }
    itemp = dc_1.itcelm[1];
    locs2 = nodplc[itemp];
    anam = blank_1.value[locs2 - 1];
    move_(&anam, &c__2, &ablnk, &c__1, &c__7);
    if (anam == aletr) {
	irdct2 = 1;
    }
    if (anam == alett) {
	itdct2 = 1;
    }
    temv2 = blank_1.value[locs2];
    blank_1.value[locs2] = dc_1.tcstar[1];
    temp = (d__1 = (dc_1.tcstop[1] - dc_1.tcstar[1]) / dc_1.tcincr[1], abs(
	    d__1)) + .5;
    icvfl2 = (integer) temp + 1;
    icvfl2 = max(icvfl2,1);
L310:
    status_1.delta = dc_1.tcincr[0];
    for (i__ = 1; i__ <= 7; ++i__) {
	status_1.delold[i__ - 1] = status_1.delta;
/* L320: */
    }
    icvfl1 = dc_1.icvflg / icvfl2;
    blank_1.value[locs] = dc_1.tcstar[0];
    if (itdctc != 1 && itdct2 != 1) {
	goto L325;
    }
    status_1.itemno = 3;
    if (itdctc == 1) {
	blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = blank_1.value[
		locs];
    }
    if (itdct2 == 1) {
	blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = blank_1.value[
		locs2];
    }
    tmpupd_();
L325:
    if (irdctc == 1) {
	blank_1.value[locs] = 1. / blank_1.value[locs];
    }
    if (irdct2 == 1) {
	blank_1.value[locs2] = 1. / blank_1.value[locs2];
    }
    status_1.icalc = 0;
    ical2 = 0;
    loctim = 3;
L340:
    status_1.initf = 2;
    iter8_(&flags_1.itl1);
    miscel_1.rstats[3] += status_1.iterno;
    copy8_(&blank_1.value[tabinf_1.lx0], &blank_1.value[tabinf_1.lx1], &
	    cirdat_1.nxtrm);
    if (nolx2 == 0) {
	copy8_(&blank_1.value[tabinf_1.lx0], &blank_1.value[tabinf_1.lx2], &
		cirdat_1.nxtrm);
    }
    if (flags_1.igoof != 0) {
	goto L450;
    }
    goto L360;
L350:
    getcje_();
    if (cje_1.maxtim - cje_1.itime <= flags_1.limtim) {
	goto L460;
    }
    status_1.initf = 6;
    iter8_(&flags_1.itl2);
    miscel_1.rstats[3] += status_1.iterno;
    if (flags_1.igoof != 0) {
	goto L340;
    }

/*  STORE OUTPUTS */

L360:
    extmem_(&tabinf_1.loutpt, &numout);
    loco = tabinf_1.loutpt + status_1.icalc * numout;
    ++status_1.icalc;
    ++ical2;
    blank_1.value[loco] = blank_1.value[locs];
    if (irdctc == 1) {
	blank_1.value[loco] = 1. / blank_1.value[loco];
    }
    loc = cirdat_1.locate[40];
L370:
    if (loc == 0) {
	goto L400;
    }
    if (nodplc[loc + 4] != 0) {
	goto L380;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    tabinf_1.iseq = nodplc[loc + 3];
    blank_1.value[loco + tabinf_1.iseq - 1] = blank_1.value[tabinf_1.lvnim1 + 
	    node1 - 1] - blank_1.value[tabinf_1.lvnim1 + node2 - 1];
    loc = nodplc[loc - 1];
    goto L370;
L380:
    iptr = nodplc[loc + 1];
    iptr = nodplc[iptr + 5];
    tabinf_1.iseq = nodplc[loc + 3];
    blank_1.value[loco + tabinf_1.iseq - 1] = blank_1.value[tabinf_1.lvnim1 + 
	    iptr - 1];
    loc = nodplc[loc - 1];
    goto L370;

/*  INCREMENT SOURCE VALUE */

L400:
    if (status_1.ipostp == 0) {
	goto L410;
    }
    blank_1.value[ibuff] = blank_1.value[locs];
    i__1 = cirdat_1.nunods - 1;
    copy8_(&blank_1.value[tabinf_1.lvnim1 + 1], &blank_1.value[ibuff + 1], &
	    i__1);
    if (numcur != 0) {
	copy8_(&blank_1.value[tabinf_1.lvnim1 + loccur], &blank_1.value[ibuff 
		+ cirdat_1.nunods], &numcur);
    }
    fwrite_(&blank_1.value[ibuff], &numpos);
L410:
    if (status_1.icalc >= dc_1.icvflg) {
	goto L490;
    }
    if (ical2 >= icvfl1) {
	goto L480;
    }
    if (nolx2 != 0) {
	goto L420;
    }
    ptrmem_(&tabinf_1.lx2, &itemp);
    ptrmem_(&tabinf_1.lx1, &tabinf_1.lx2);
    goto L430;
L420:
    ptrmem_(&tabinf_1.lx1, &itemp);
L430:
    ptrmem_(&tabinf_1.lx0, &tabinf_1.lx1);
    ptrmem_(&itemp, &tabinf_1.lx0);
    blank_1.value[locs] = dc_1.tcstar[0] + (doublereal) ical2 * 
	    status_1.delta;
    if (itdctc != 1) {
	goto L440;
    }
    blank_1.value[tabinf_1.itemps + status_1.itemno - 2] = blank_1.value[
	    tabinf_1.itemps + status_1.itemno - 1];
    blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = blank_1.value[locs]
	    ;
    tmpupd_();
L440:
    if (irdctc == 1) {
	blank_1.value[locs] = 1. / blank_1.value[locs];
    }
    goto L350;

/*  NO CONVERGENCE */

L450:
    itemp = dc_1.itcelm[0];
    loce = nodplc[itemp];
    io___1177.ciunit = status_1.iofile;
    s_wsfe(&io___1177);
    do_fio(&c__1, (char *)&blank_1.value[loce - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&blank_1.value[locs], (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___1178.ciunit = status_1.iofile;
    s_wsfe(&io___1178);
    i__1 = nvprln;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anode, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avltg, (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___1179.ciunit = status_1.iofile;
    s_wsfe(&io___1179);
    i__1 = cirdat_1.ncnods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&lprn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvnim1 + i__ - 1], (
		ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L470;
L460:
    io___1180.ciunit = status_1.iofile;
    s_wsfe(&io___1180);
    e_wsfe();
    goto L470;
L462:
    io___1181.ciunit = status_1.iofile;
    s_wsfe(&io___1181);
    e_wsfe();
L470:
    flags_1.nogo = 1;
    goto L490;
/* ... RESET FIRST SWEEP VARIABLE ... STEP SECOND */
L480:
    ical2 = 0;
    blank_1.value[locs] = dc_1.tcstar[0];
    if (irdctc == 1) {
	blank_1.value[locs] = 1. / blank_1.value[locs];
    }
    if (itdctc == 1) {
	goto L462;
    }
    blank_1.value[locs2] += dc_1.tcincr[1];
    if (irdct2 == 1) {
	blank_1.value[locs2] = 1. / blank_1.value[locs2];
    }
    if (itdct2 != 1) {
	goto L340;
    }
    blank_1.value[tabinf_1.itemps + status_1.itemno - 2] = blank_1.value[
	    tabinf_1.itemps + status_1.itemno - 1];
    blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = blank_1.value[
	    locs2];
    tmpupd_();
    goto L340;

/*  FINISHED WITH DC TRANSFER CURVES */

L490:
    blank_1.value[locs] = temval;
    if (dc_1.itcelm[1] != 0) {
	blank_1.value[locs2] = temv2;
    }
    if (itdctc == 0 && itdct2 == 0) {
	goto L1000;
    }
    blank_1.value[tabinf_1.itemps + status_1.itemno - 2] = blank_1.value[
	    tabinf_1.itemps + status_1.itemno - 1];
    if (itdctc == 1) {
	blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = temval;
    }
    if (itdct2 == 1) {
	blank_1.value[tabinf_1.itemps + status_1.itemno - 1] = temv2;
    }
    io___1182.ciunit = status_1.iofile;
    s_wsfe(&io___1182);
    e_wsfe();
    tmpupd_();
    status_1.itemno = 1;
    relmem_(&tabinf_1.itemps, &c__2);
    if (status_1.ipostp == 0) {
	goto L1000;
    }
    fwrite_(&blank_1.value[ibuff], &numpos);
    goto L1000;

/*  ....  TRANSIENT ANALYSIS */

L500:
    numout = cirdat_1.jelcnt[41] + 1;
    if (status_1.ipostp != 0) {
	pheadr_(miscel_1.atitle);
    }
/* ...  LIMIT DELMAX IF NO ENERGY-STORAGE ELEMENTS */
    numese = cirdat_1.jelcnt[1] + cirdat_1.jelcnt[2] + cirdat_1.jelcnt[10] + 
	    cirdat_1.jelcnt[11] + cirdat_1.jelcnt[12] + cirdat_1.jelcnt[13];
    if (numese == 0) {
	tran_1.delmax = min(tran_1.delmax,tran_1.tstep);
    }
    status_1.initf = 5;
    status_1.iord = 1;
    loctim = 9;
    status_1.icalc = 0;
    numtp = 0;
    numrtp = 0;
    numnit = 0;
    status_1.time = 0.;
    ibkflg = 1;
    delbkp = tran_1.delmax;
    nbkpt = 1;
    status_1.delta = tran_1.delmax;
    for (i__ = 1; i__ <= 7; ++i__) {
	status_1.delold[i__ - 1] = status_1.delta;
/* L510: */
    }
    delnew = status_1.delta;
    delmin = tran_1.delmax * 1e-9;
    goto L650;

/*  INCREMENT TIME, UPDATE SOURCES, AND SOLVE NEXT TIMEPOINT */

L600:
    status_1.time += status_1.delta;
    sorupd_();
    if (flags_1.nogo != 0) {
	goto L950;
    }
    getcje_();
    if (cje_1.maxtim - cje_1.itime <= flags_1.limtim) {
	goto L920;
    }
    if (flags_1.itl5 != 0 && numnit >= flags_1.itl5) {
	goto L905;
    }
    comcof_();
    if (status_1.initf != 5) {
	status_1.initf = 6;
    }
    itrlim = flags_1.itl4;
    if (numtp == 0 && status_1.nosolv != 0) {
	itrlim = flags_1.itl1;
    }
    iter8_(&itrlim);
    numnit += status_1.iterno;
    ++numtp;
    if (numtp != 1) {
	goto L605;
    }
    if (nolx2 == 0) {
	copy8_(&blank_1.value[tabinf_1.lx1], &blank_1.value[tabinf_1.lx2], &
		cirdat_1.nxtrm);
    }
    if (nolx3 == 0) {
	copy8_(&blank_1.value[tabinf_1.lx1], &blank_1.value[tabinf_1.lx3], &
		cirdat_1.nxtrm);
    }
/* .. NOTE THAT TIME-POINT IS CUT WHEN ITRLIM EXCEEDED REGARDLESS */
/* .. OF WHICH TIME-STEP CONTOL IS SPECIFIED THRU 'LVLTIM'. */
L605:
    if (flags_1.igoof == 0) {
	goto L610;
    }
    jord = status_1.iord;
    status_1.iord = 1;
    if (jord >= 5) {
	clrmem_(&tabinf_1.lx7);
    }
    if (jord >= 4) {
	clrmem_(&tabinf_1.lx6);
    }
    if (jord >= 3) {
	clrmem_(&tabinf_1.lx5);
    }
    if (jord >= 2 && status_1.method != 1) {
	clrmem_(&tabinf_1.lx4);
    }
    flags_1.igoof = 0;
    status_1.time -= status_1.delta;
    status_1.delta /= 8.;
    goto L620;
L610:
    delnew = status_1.delta;
    if (numtp == 1) {
	goto L630;
    }
    trunc_(&delnew);
    if (delnew >= status_1.delta * .9) {
	goto L630;
    }
    status_1.time -= status_1.delta;
    status_1.delta = delnew;
L620:
    ++numrtp;
    ibkflg = 0;
    status_1.delold[0] = status_1.delta;
    if (status_1.delta >= delmin) {
	goto L600;
    }
    status_1.time += status_1.delta;
    goto L900;

/*  DETERMINE ORDER OF INTEGRATION METHOD */

/* ...  SKIP IF TRAPEZOIDAL ALGORITHM USED */
L630:
    if (status_1.method == 1 && status_1.iord == 2) {
	goto L650;
    }
    if (numtp == 1) {
	goto L650;
    }
    ordrat = 1.05;
    if (status_1.iord > 1) {
	goto L635;
    }
    status_1.iord = 2;
    trunc_(&delnew);
    status_1.iord = 1;
    if (delnew / status_1.delta <= ordrat) {
	goto L650;
    }
    if (status_1.maxord <= 1) {
	goto L650;
    }
    status_1.iord = 2;
    if (status_1.method == 1) {
	goto L650;
    }
    getm8_(&tabinf_1.lx4, &cirdat_1.nxtrm);
    goto L650;
L635:
    if (status_1.iord < status_1.maxord) {
	goto L640;
    }
    --status_1.iord;
    trunc_(&delnew);
    ++status_1.iord;
    if (delnew / status_1.delta <= ordrat) {
	goto L650;
    }
    goto L642;
L640:
    --status_1.iord;
    trunc_(&delnew);
    ++status_1.iord;
    if (delnew / status_1.delta <= ordrat) {
	goto L645;
    }
L642:
    --status_1.iord;
    if (status_1.iord == 1) {
	clrmem_(&tabinf_1.lx4);
    }
    if (status_1.iord == 2) {
	clrmem_(&tabinf_1.lx5);
    }
    if (status_1.iord == 3) {
	clrmem_(&tabinf_1.lx6);
    }
    if (status_1.iord == 4) {
	clrmem_(&tabinf_1.lx7);
    }
    goto L650;
L645:
    ++status_1.iord;
    trunc_(&delnew);
    --status_1.iord;
    if (delnew / status_1.delta <= ordrat) {
	goto L650;
    }
    ++status_1.iord;
    if (status_1.iord == 2) {
	getm8_(&tabinf_1.lx4, &cirdat_1.nxtrm);
    }
    if (status_1.iord == 3) {
	getm8_(&tabinf_1.lx5, &cirdat_1.nxtrm);
    }
    if (status_1.iord == 4) {
	getm8_(&tabinf_1.lx6, &cirdat_1.nxtrm);
    }
    if (status_1.iord == 5) {
	getm8_(&tabinf_1.lx7, &cirdat_1.nxtrm);
    }

/*  STORE OUTPUTS */

L650:
    if (status_1.time + status_1.delta <= tran_1.tstart) {
	goto L685;
    }
    if (numtp == 0 && status_1.nosolv != 0) {
	goto L685;
    }
    extmem_(&tabinf_1.loutpt, &numout);
    loco = tabinf_1.loutpt + status_1.icalc * numout;
    ++status_1.icalc;
    blank_1.value[loco] = status_1.time;
    loc = cirdat_1.locate[41];
L670:
    if (loc == 0) {
	goto L682;
    }
    if (nodplc[loc + 4] != 0) {
	goto L680;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    tabinf_1.iseq = nodplc[loc + 3];
    blank_1.value[loco + tabinf_1.iseq - 1] = blank_1.value[tabinf_1.lvnim1 + 
	    node1 - 1] - blank_1.value[tabinf_1.lvnim1 + node2 - 1];
    loc = nodplc[loc - 1];
    goto L670;
L680:
    iptr = nodplc[loc + 1];
    iptr = nodplc[iptr + 5];
    tabinf_1.iseq = nodplc[loc + 3];
    blank_1.value[loco + tabinf_1.iseq - 1] = blank_1.value[tabinf_1.lvnim1 + 
	    iptr - 1];
    loc = nodplc[loc - 1];
    goto L670;
L682:
    if (status_1.ipostp == 0) {
	goto L684;
    }
    blank_1.value[ibuff] = status_1.time;
    i__1 = cirdat_1.nunods - 1;
    copy8_(&blank_1.value[tabinf_1.lvnim1 + 1], &blank_1.value[ibuff + 1], &
	    i__1);
    if (numcur != 0) {
	copy8_(&blank_1.value[tabinf_1.lvnim1 + loccur], &blank_1.value[ibuff 
		+ cirdat_1.nunods], &numcur);
    }
    fwrite_(&blank_1.value[ibuff], &numpos);
L684:

/*  UPDATE TRANSMISSION LINE DELAY TABLE */

L685:
    if (cirdat_1.jelcnt[16] == 0) {
	goto L694;
    }
    sizmem_(&tabinf_1.ltd, &ltdsiz);
    numtd = ltdsiz / cirdat_1.ntlin;
    if (numtd <= 3) {
	goto L689;
    }
    baktim = status_1.time - tran_1.tdmax;
    if (baktim < 0.) {
	goto L689;
    }
    lcntr = 0;
    ltemp = tabinf_1.ltd;
    i__1 = numtd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (blank_1.value[ltemp] >= baktim) {
	    goto L687;
	}
	ltemp += cirdat_1.ntlin;
	++lcntr;
/* L686: */
    }
    goto L689;
L687:
    if (lcntr <= 2) {
	goto L689;
    }
    lcntr += -2;
    nwords = lcntr * cirdat_1.ntlin;
    ltemp = ltemp - cirdat_1.ntlin - cirdat_1.ntlin;
    i__1 = ltdsiz - nwords;
    copy8_(&blank_1.value[ltemp], &blank_1.value[tabinf_1.ltd], &i__1);
    relmem_(&tabinf_1.ltd, &nwords);
    sizmem_(&tabinf_1.ltd, &ltdsiz);
L689:
    extmem_(&tabinf_1.ltd, &cirdat_1.ntlin);
    ltdptr = tabinf_1.ltd + ltdsiz;
    blank_1.value[ltdptr] = status_1.time;
    loc = cirdat_1.locate[16];
L690:
    if (loc == 0) {
	goto L693;
    }
    locv = nodplc[loc];
    z0 = blank_1.value[locv];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    ibr1 = nodplc[loc + 7];
    ibr2 = nodplc[loc + 8];
    lspot = nodplc[loc + 29] + ltdptr;
    if (status_1.initf == 5 && status_1.nosolv != 0) {
	goto L691;
    }
    blank_1.value[lspot - 1] = blank_1.value[tabinf_1.lvnim1 + node3 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1] + blank_1.value[
	    tabinf_1.lvnim1 + ibr2 - 1] * z0;
    blank_1.value[lspot] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node2 - 1] + blank_1.value[
	    tabinf_1.lvnim1 + ibr1 - 1] * z0;
    goto L692;
L691:
    blank_1.value[lspot - 1] = blank_1.value[locv + 6] + blank_1.value[locv + 
	    7] * z0;
    blank_1.value[lspot] = blank_1.value[locv + 4] + blank_1.value[locv + 5] *
	     z0;
L692:
    loc = nodplc[loc - 1];
    goto L690;

/*  ADD TWO *FAKE* BACKPOINTS TO LTD FOR INTERPOLATION NEAR TIME=0.0D0 */

L693:
    if (numtd != 0) {
	goto L694;
    }
    i__1 = cirdat_1.ntlin + cirdat_1.ntlin;
    extmem_(&tabinf_1.ltd, &i__1);
    copy8_(&blank_1.value[tabinf_1.ltd], &blank_1.value[tabinf_1.ltd + 
	    cirdat_1.ntlin], &cirdat_1.ntlin);
    copy8_(&blank_1.value[tabinf_1.ltd], &blank_1.value[tabinf_1.ltd + (
	    cirdat_1.ntlin << 1)], &cirdat_1.ntlin);
    blank_1.value[tabinf_1.ltd + (cirdat_1.ntlin << 1)] = status_1.time;
    blank_1.value[tabinf_1.ltd + cirdat_1.ntlin] = status_1.time - 
	    status_1.delta;
    blank_1.value[tabinf_1.ltd] = status_1.time - status_1.delta - 
	    status_1.delta;

/*  ROTATE STATE VECTOR STORAGE */

/* .. TIME-POINT ACCEPTED */
L694:
    copy8_(status_1.delold, &status_1.delold[1], &c__6);
    status_1.delta = delnew;
    status_1.delold[0] = status_1.delta;
    switch (status_1.iord) {
	case 1:  goto L710;
	case 2:  goto L706;
	case 3:  goto L702;
	case 4:  goto L698;
	case 5:  goto L696;
	case 6:  goto L696;
    }
L696:
    ptrmem_(&tabinf_1.lx7, &itemp);
    ptrmem_(&tabinf_1.lx6, &tabinf_1.lx7);
    goto L700;
L698:
    ptrmem_(&tabinf_1.lx6, &itemp);
L700:
    ptrmem_(&tabinf_1.lx5, &tabinf_1.lx6);
    goto L704;
L702:
    ptrmem_(&tabinf_1.lx5, &itemp);
L704:
    ptrmem_(&tabinf_1.lx4, &tabinf_1.lx5);
    goto L708;
L706:
    if (status_1.method == 1) {
	goto L710;
    }
    ptrmem_(&tabinf_1.lx4, &itemp);
L708:
    ptrmem_(&tabinf_1.lx3, &tabinf_1.lx4);
    goto L713;
L710:
    if (nolx3 == 0) {
	goto L712;
    }
    if (nolx2 == 0) {
	goto L711;
    }
    ptrmem_(&tabinf_1.lx1, &itemp);
    goto L714;
L711:
    ptrmem_(&tabinf_1.lx2, &itemp);
    ptrmem_(&tabinf_1.lx1, &tabinf_1.lx2);
    goto L714;
L712:
    ptrmem_(&tabinf_1.lx3, &itemp);
L713:
    ptrmem_(&tabinf_1.lx2, &tabinf_1.lx3);
    ptrmem_(&tabinf_1.lx1, &tabinf_1.lx2);
L714:
    ptrmem_(&tabinf_1.lx0, &tabinf_1.lx1);
    ptrmem_(&itemp, &tabinf_1.lx0);

/*  CHECK BREAKPOINTS */

/* L750: */
    if (ibkflg == 0) {
	goto L760;
    }
/* .. JUST ACCEPTED ANALYSIS AT BREAKPOINT */
    jord = status_1.iord;
    status_1.iord = 1;
    if (jord >= 5) {
	clrmem_(&tabinf_1.lx7);
    }
    if (jord >= 4) {
	clrmem_(&tabinf_1.lx6);
    }
    if (jord >= 3) {
	clrmem_(&tabinf_1.lx5);
    }
    if (jord >= 2 && status_1.method != 1) {
	clrmem_(&tabinf_1.lx4);
    }
    ibkflg = 0;
    ++nbkpt;
    if (nbkpt > tabinf_1.numbkp) {
	goto L950;
    }
/* Computing MIN */
    d__1 = delbkp, d__2 = blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] - 
	    status_1.time;
    temp = min(d__1,d__2);
/* Computing MIN */
    d__1 = status_1.delta, d__2 = temp * .1, d__1 = min(d__1,d__2);
    status_1.delta = min(d__1,tran_1.delmax);
    if (numtp == 0) {
	status_1.delta /= 10.;
    }
    status_1.delold[0] = status_1.delta;
    goto L600;
L760:
    del1 = blank_1.value[tabinf_1.lsbkpt + nbkpt - 1] - status_1.time;
    if (status_1.delta * 1.01 <= del1) {
	goto L600;
    }
    ibkflg = 1;
    delbkp = status_1.delta;
    status_1.delta = del1;
    status_1.delold[0] = status_1.delta;
    goto L600;

/*  TRANSIENT ANALYSIS FAILED */

L900:
    io___1210.ciunit = status_1.iofile;
    s_wsfe(&io___1210);
    e_wsfe();
    goto L910;
L905:
    io___1211.ciunit = status_1.iofile;
    s_wsfe(&io___1211);
    do_fio(&c__1, (char *)&flags_1.itl5, (ftnlen)sizeof(integer));
    e_wsfe();
L910:
    io___1212.ciunit = status_1.iofile;
    s_wsfe(&io___1212);
    do_fio(&c__1, (char *)&status_1.time, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&status_1.delta, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&numnit, (ftnlen)sizeof(integer));
    e_wsfe();
    io___1213.ciunit = status_1.iofile;
    s_wsfe(&io___1213);
    e_wsfe();
    io___1214.ciunit = status_1.iofile;
    s_wsfe(&io___1214);
    i__1 = nvprln;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anode, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avltg, (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___1215.ciunit = status_1.iofile;
    s_wsfe(&io___1215);
    i__1 = cirdat_1.ncnods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&lprn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nodplc[tabinf_1.junode + i__ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&blank_1.value[tabinf_1.lvnim1 + i__ - 1], (
		ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L930;
L920:
    io___1216.ciunit = status_1.iofile;
    s_wsfe(&io___1216);
    do_fio(&c__1, (char *)&status_1.time, (ftnlen)sizeof(doublereal));
    e_wsfe();
L930:
    flags_1.nogo = 1;

/*  FINISHED WITH TRANSIENT ANALYSIS */

L950:
    miscel_1.rstats[9] += numnit;
    miscel_1.rstats[29] += numtp;
    miscel_1.rstats[30] += numrtp;
    miscel_1.rstats[31] += numnit;
    if (status_1.ipostp == 0) {
	goto L1000;
    }
    if (status_1.ipostp != 0) {
	clsraw_();
    }

/*  RETURN UNNEEDED MEMORY */

L1000:
    if (status_1.mode == 2) {
	goto L1010;
    }
    if (status_1.modedc != 3) {
	goto L1100;
    }
L1010:
    clrmem_(&tabinf_1.lvnim1);
    clrmem_(&tabinf_1.lx0);
    clrmem_(&tabinf_1.lvn);
    clrmem_(&tabinf_1.lx1);
    if (memptr_(&tabinf_1.macins)) {
	clrmem_(&tabinf_1.macins);
    }
    if (nolx2 == 0) {
	clrmem_(&tabinf_1.lx2);
    }
    clrmem_(&tabinf_1.lvntmp);
    if (status_1.mode == 1 && status_1.modedc == 3) {
	goto L1020;
    }
    if (nolx3 == 0) {
	clrmem_(&tabinf_1.lx3);
    }
    if (status_1.mode == 1) {
	goto L1020;
    }
    clrmem_(&tabinf_1.ltd);
    if (status_1.iord == 1) {
	goto L1020;
    }
    if (status_1.method == 1) {
	goto L1020;
    }
    clrmem_(&tabinf_1.lx4);
    if (status_1.iord == 2) {
	goto L1020;
    }
    clrmem_(&tabinf_1.lx5);
    if (status_1.iord == 3) {
	goto L1020;
    }
    clrmem_(&tabinf_1.lx6);
    if (status_1.iord == 4) {
	goto L1020;
    }
    clrmem_(&tabinf_1.lx7);
L1020:
    i__1 = numout << 1;
    extmem_(&tabinf_1.loutpt, &i__1);
L1100:
    if (status_1.ipostp != 0) {
	clrmem_(&ibuff);
    }
    second_(&t2);
    miscel_1.rstats[loctim - 1] = miscel_1.rstats[loctim - 1] + t2 - t1;
    return 0;
} /* dctran_ */

#undef cvalue
#undef nodplc
#undef alett
#undef aletr
#undef ablnk
#undef lprn
#undef subtit
#undef avltg
#undef anode
#undef avfrm
#undef avhdr


/* Subroutine */ int pheadr_(doublereal *aheadr)
{
    /* Initialized data */

    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_1252 = { "TIME    FREQ    ", 0. };

#define xtype ((doublereal *)&equiv_1252)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1253 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_1253)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1254 = { "V       ", 0. };

#define aletv (*(doublereal *)&equiv_1254)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_1255 = { "I       ", 0. };

#define aleti (*(doublereal *)&equiv_1255)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, loc;
    static shortint int2, int3;
    static doublereal anam;
    static integer info, locv, iknt;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer ipos, nwds, ityp;
    extern /* Subroutine */ int getm4_(integer *, integer *);
    static integer iseq2;
    extern /* Subroutine */ int getm8_(integer *, integer *), copy8_(
	    doublereal *, doublereal *, integer *);
    static integer ibuff, iseqs;
#define nodpl2 ((shortint *)&blank_1)
    static integer itype2;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int fwrite_();
    static integer numout, inames, itypes;
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *), 
	    clrmem_(integer *);

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* int3 (not used) is strictly for alignment.  f77 on Unix craps out. */

/*  PUT OUT THE HEADER RECORDS ONTO THE POST-PROCESSING FILE */
/*  ROUTINE IS USED FOR ALL ANALYSIS MODES (MODE=1,2,3) */

    /* Parameter adjustments */
    --aheadr;

    /* Function Body */

/* File structure for post-processor */

/* Record 1  Title card (80 bytes), date (8 bytes), time (8 bytes) TOTAL-96 BYTES */
/* Record 2  Number of output variables (including "sweep" variable) */
/* Record 3  Integer '4' (2 bytes) */
/* Record 4  Names of each output variable (8 bytes ea.) */
/* Record 5  Type of each output       0-no type */
/*                                     1-time */
/*                                     2-frequency */
/*                                     3-voltage */
/*                                     4-current */
/*                                     5-output noise */
/*                                     6-input noise */
/*                                     7-HD2    | */
/*                                     8-HD3    | */
/*                                     9-DIM2   }   distortion outputs */
/*                                    10-SIM2   | */
/*                                    11-DIM3   | */
/* Record 6  The location of each variable within each sweep point. */
/*           (Normally just 1,2,3,4,... but needed if outputs are mixed up) */
/* Record 6a 24 characters that are the plot title if Record 3 is a '4'. */
/* Record 7  Output at first sweep point */
/* Record 8  Output at second sweep point */
/* Record 9  . */
/*           . */
/*           . */
/* last record */


    getm8_(&ibuff, &c__12);
    copy8_(&aheadr[1], &blank_1.value[ibuff], &c__10);
    blank_1.value[ibuff + 10] = miscel_1.adate;
    blank_1.value[ibuff + 11] = miscel_1.atime;
    fwrite_(&blank_1.value[ibuff], &c__48);
    numout = cirdat_1.nunods + cirdat_1.jelcnt[8];
/* Force nused to be allocated by useless usage. */
    int2 = (shortint) numout;
    int3 = (shortint) numout;
    info = 4;
    getm8_(&inames, &numout);
    getm4_(&itypes, &numout);
    getm4_(&iseqs, &numout);
    itype2 = itypes << 1;
    iseq2 = iseqs << 1;
    iknt = 1;
    nodpl2[iseq2] = 1;

/* DC Transfer curve (mode = 1): */

    if (status_1.mode != 1) {
	goto L10;
    }
    loc = dc_1.itcelm[0];
    locv = nodplc[loc];
    blank_1.value[inames] = blank_1.value[locv - 1];
    anam = ablnk;
    move_(&anam, &c__1, &blank_1.value[locv - 1], &c__1, &c__1);
    ityp = 0;
/* Voltage transfer becomes type 3 and Current transfer becomes 4. */
    if (anam == aletv) {
	ityp = 3;
    }
    if (anam == aleti) {
	ityp = 4;
    }
    nodpl2[itype2] = (shortint) ityp;
    goto L20;
L10:
    blank_1.value[inames] = xtype[status_1.mode - 2];
    nodpl2[itype2] = (shortint) (status_1.mode - 1);
L20:
    i__1 = cirdat_1.nunods;
    for (i__ = 2; i__ <= i__1; ++i__) {
	nodpl2[itype2 + i__ - 1] = 3;
	nodpl2[iseq2 + i__ - 1] = (shortint) i__;
	blank_1.value[inames + i__ - 1] = ablnk;
	ipos = 1;
	alfnum_(&nodplc[tabinf_1.junode + i__ - 1], &blank_1.value[inames + 
		i__ - 1], &ipos);
/* L30: */
    }
    loc = cirdat_1.locate[8];
    iknt = cirdat_1.nunods;
L40:
    if (loc == 0) {
	goto L50;
    }
    ++iknt;
    nodpl2[itype2 + iknt - 1] = 4;
    nodpl2[iseq2 + iknt - 1] = (shortint) iknt;
    locv = nodplc[loc];
    blank_1.value[inames + iknt - 1] = blank_1.value[locv - 1];
    loc = nodplc[loc - 1];
    goto L40;
L50:
    int2 = (shortint) numout;
    fwrite_(&int2, &c__1);
    int2 = (shortint) info;
    fwrite_(&int2, &c__1);
    nwds = numout << 2;
    fwrite_(&blank_1.value[inames], &nwds);
    fwrite_(&nodpl2[itype2], &numout);
    fwrite_(&nodpl2[iseq2], &numout);
    fwrite_(miscel_1.aprog, &c__12);
    clrmem_(&ibuff);
    clrmem_(&inames);
    clrmem_(&itypes);
    clrmem_(&iseqs);
    return 0;
} /* pheadr_ */

#undef cvalue
#undef nodplc
#undef nodpl2
#undef aleti
#undef aletv
#undef ablnk
#undef xtype


/* Subroutine */ int comcof_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, ir;
    static doublereal arg, arg1, gmat[49]	/* was [7][7] */;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static integer istop;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer jstart;


/*     THIS ROUTINE CALCULATES THE TIMESTEP-DEPENDENT TERMS USED IN THE */
/* NUMERICAL INTEGRATION. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  COMPUTE COEFFICIENTS FOR PARTICULAR INTEGRATION METHOD */

    if (status_1.method != 1) {
	goto L5;
    }
    if (status_1.iord == 1) {
	goto L5;
    }
/* ...  TRAPEZOIDAL METHOD */
    status_1.ag[0] = 1. / status_1.delta / (1. - status_1.xmu);
    status_1.ag[1] = status_1.xmu / (1. - status_1.xmu);
    goto L200;

/*  CONSTRUCT GEAR COEFFICIENT MATRIX */

L5:
    istop = status_1.iord + 1;
    zero8_(status_1.ag, &istop);
    status_1.ag[1] = -1.;
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	gmat[i__ * 7 - 7] = 1.;
/* L10: */
    }
    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	gmat[i__ - 1] = 0.;
/* L20: */
    }
    arg = 0.;
    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	arg += status_1.delold[i__ - 2];
	arg1 = 1.;
	i__2 = istop;
	for (j = 2; j <= i__2; ++j) {
	    arg1 *= arg;
	    gmat[j + i__ * 7 - 8] = arg1;
/* L30: */
	}
/* L40: */
    }

/*  SOLVE FOR GEAR COEFFICIENTS AG(*) */


/*  LU DECOMPOSITION */

    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	jstart = i__ + 1;
	if (jstart > istop) {
	    goto L70;
	}
	i__2 = istop;
	for (j = jstart; j <= i__2; ++j) {
	    gmat[j + i__ * 7 - 8] /= gmat[i__ + i__ * 7 - 8];
	    i__3 = istop;
	    for (k = jstart; k <= i__3; ++k) {
		gmat[j + k * 7 - 8] -= gmat[j + i__ * 7 - 8] * gmat[i__ + k * 
			7 - 8];
/* L50: */
	    }
/* L60: */
	}
L70:
	;
    }

/*  FORWARD SUBSTITUTION */

    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	jstart = i__ + 1;
	if (jstart > istop) {
	    goto L90;
	}
	i__2 = istop;
	for (j = jstart; j <= i__2; ++j) {
	    status_1.ag[j - 1] -= gmat[j + i__ * 7 - 8] * status_1.ag[i__ - 1]
		    ;
/* L80: */
	}
L90:
	;
    }

/*  BACKWARD SUBSTITUTION */

    status_1.ag[istop - 1] /= gmat[istop + istop * 7 - 8];
    ir = istop;
    i__1 = istop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	jstart = ir;
	--ir;
	i__2 = istop;
	for (j = jstart; j <= i__2; ++j) {
	    status_1.ag[ir - 1] -= gmat[ir + j * 7 - 8] * status_1.ag[j - 1];
/* L100: */
	}
	status_1.ag[ir - 1] /= gmat[ir + ir * 7 - 8];
/* L110: */
    }

/*  FINISHED */

L200:
    return 0;
} /* comcof_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int trunc_(doublereal *delnew)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer loc, loct;
    extern /* Subroutine */ int terr_(integer *, doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE DETERMINES THE NEW TRANSIENT STEPSIZE BY EITHER */
/* CALLING TERR TO ESTIMATE THE LOCAL TRUNCATION ERROR, OR BY CHECKING */
/* ON THE NUMBER OF ITERATIONS NEEDED TO CONVERGE AT THE LAST TIMEPOINT. */

/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    if (flags_1.lvltim != 0) {
	goto L5;
    }
    *delnew = min(tran_1.tstep,tran_1.delmax);
    return 0;
L5:
    if (flags_1.lvltim != 1) {
	goto L10;
    }
    *delnew = status_1.delta;
    if (status_1.iterno > flags_1.itl3) {
	return 0;
    }
/* Computing MIN */
    d__1 = status_1.delta * 2., d__1 = min(d__1,tran_1.tstep);
    *delnew = min(d__1,tran_1.delmax);
    return 0;

/*  CAPACITORS */

L10:
    *delnew = 1e20;
    loc = cirdat_1.locate[1];
L20:
    if (loc == 0 || nodplc[loc + 11] != 0) {
	goto L30;
    }
    loct = nodplc[loc + 7];
    terr_(&loct, delnew);
    loc = nodplc[loc - 1];
    goto L20;

/*  INDUCTORS */

L30:
    loc = cirdat_1.locate[2];
L40:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L50;
    }
    loct = nodplc[loc + 10];
    terr_(&loct, delnew);
    loc = nodplc[loc - 1];
    goto L40;

/*  DIODES */

L50:
    loc = cirdat_1.locate[10];
L60:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L70;
    }
    loct = nodplc[loc + 10];
    i__1 = loct + 3;
    terr_(&i__1, delnew);
    loc = nodplc[loc - 1];
    goto L60;

/*  BJTS */

L70:
    loc = cirdat_1.locate[11];
L80:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L90;
    }
    loct = nodplc[loc + 21];
    i__1 = loct + 8;
    terr_(&i__1, delnew);
    i__1 = loct + 10;
    terr_(&i__1, delnew);
    i__1 = loct + 12;
    terr_(&i__1, delnew);
    loc = nodplc[loc - 1];
    goto L80;

/*  JFETS */

L90:
    loc = cirdat_1.locate[12];
L100:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L110;
    }
    loct = nodplc[loc + 18];
    i__1 = loct + 9;
    terr_(&i__1, delnew);
    i__1 = loct + 11;
    terr_(&i__1, delnew);
    loc = nodplc[loc - 1];
    goto L100;

/*  MOSFETS */

L110:
    loc = cirdat_1.locate[13];
L120:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L200;
    }
    loct = nodplc[loc + 25];
    i__1 = loct + 12;
    terr_(&i__1, delnew);
    i__1 = loct + 14;
    terr_(&i__1, delnew);
    i__1 = loct + 16;
    terr_(&i__1, delnew);
    loc = nodplc[loc - 1];
    goto L120;

/*  DELTA IS ALLOWED ONLY TO DOUBLE AT EACH TIMEPOINT */

L200:
/* Computing MIN */
    d__1 = status_1.delta * 2., d__1 = min(d__1,*delnew);
    *delnew = min(d__1,tran_1.delmax);
    return 0;
} /* trunc_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int terr_(integer *loct, doublereal *delnew)
{
    /* Initialized data */

    static doublereal coef[6] = { .5,.2222222222,.1363636364,.096,
	    .07299270073,.0583090379 };
    static doublereal xtwelv = .08333333333;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal), log(doublereal), exp(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal del, tol;
#define ccap ((doublereal *)&blank_1 + 1)
    static doublereal diff[8];
#define qcap ((doublereal *)&blank_1)
    static doublereal ctol, const__;
    static integer istop;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal deltmp[7];


/*     THIS ROUTINE ESTIMATES THE LOCAL TRUNCATION ERROR FOR A PARTICULAR */
/* CIRCUIT ELEMENT.  IT THEN COMPUTES THE APPROPRIATE STEPSIZE WHICH */
/* SHOULD BE USED. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




/* Computing MAX */
    d__3 = (d__1 = ccap[(8 + (0 + (tabinf_1.lx0 + *loct - 1 << 3)) - 8) / 8], 
	    abs(d__1)), d__4 = (d__2 = ccap[(8 + (0 + (tabinf_1.lx1 + *loct - 
	    1 << 3)) - 8) / 8], abs(d__2));
    tol = knstnt_1.reltol * max(d__3,d__4) + knstnt_1.abstol;
/* Computing MAX */
    d__3 = (d__1 = qcap[tabinf_1.lx0 + *loct - 1], abs(d__1)), d__4 = (d__2 = 
	    qcap[tabinf_1.lx1 + *loct - 1], abs(d__2)), d__3 = max(d__3,d__4);
    ctol = knstnt_1.reltol * max(d__3,knstnt_1.chgtol) / status_1.delta;
    tol = max(tol,ctol);

/*  DETERMINE DIVIDED DIFFERENCES */

    switch (status_1.iord) {
	case 1:  goto L6;
	case 2:  goto L5;
	case 3:  goto L4;
	case 4:  goto L3;
	case 5:  goto L2;
	case 6:  goto L1;
    }
L1:
    diff[7] = qcap[tabinf_1.lx7 + *loct - 1];
L2:
    diff[6] = qcap[tabinf_1.lx6 + *loct - 1];
L3:
    diff[5] = qcap[tabinf_1.lx5 + *loct - 1];
L4:
    diff[4] = qcap[tabinf_1.lx4 + *loct - 1];
L5:
    diff[3] = qcap[tabinf_1.lx3 + *loct - 1];
L6:
    diff[2] = qcap[tabinf_1.lx2 + *loct - 1];
    diff[1] = qcap[tabinf_1.lx1 + *loct - 1];
    diff[0] = qcap[tabinf_1.lx0 + *loct - 1];
    istop = status_1.iord + 1;
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	deltmp[i__ - 1] = status_1.delold[i__ - 1];
/* L10: */
    }
L20:
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	diff[i__ - 1] = (diff[i__ - 1] - diff[i__]) / deltmp[i__ - 1];
/* L30: */
    }
    --istop;
    if (istop == 0) {
	goto L100;
    }
    i__1 = istop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	deltmp[i__ - 1] = deltmp[i__] + status_1.delold[i__ - 1];
/* L40: */
    }
    goto L20;

/*  DIFF(1) CONTAINS DIVIDED DIFFERENCE */

L100:
    const__ = coef[status_1.iord - 1];
    if (status_1.method == 1 && status_1.iord == 2) {
	const__ = xtwelv;
    }
/* Computing MAX */
    d__1 = knstnt_1.abstol, d__2 = const__ * abs(diff[0]);
    del = knstnt_1.trtol * tol / max(d__1,d__2);
    if (status_1.iord == 1) {
	goto L200;
    }
    if (status_1.iord >= 3) {
	goto L150;
    }
    del = sqrt(del);
    goto L200;
L150:
    del = exp(log(del) / (doublereal) status_1.iord);
L200:
    *delnew = min(*delnew,del);
    return 0;
} /* terr_ */

#undef cvalue
#undef nodplc
#undef qcap
#undef ccap


/* Subroutine */ int sorupd_(void)
{
    /* Format strings */
    static char fmt_901[] = "(\0020*ABORT*:  INTERNAL SPICE ERROR:  SORUPD"
	    ":  \002,2i5/)";

    /* Builtin functions */
    double sin(doublereal), exp(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer l1, l2, l3;
    static doublereal t1, t2, v1, v2, t3, t4;
    static integer id;
    static doublereal td;
    static integer loc;
    static doublereal tau1, tau2, dtt1, dtt2, dtt3, omeg;
    static integer locp, locv, iknt;
    static doublereal xmod, dt1t2, dt1t3, dt2t3, time1, omegc, theta, omegs;
    static integer icntr, itype, numtd;
    static doublereal tfact1, tfact2, tfact3, tdnom1, tdnom2, tdnom3, baktim;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal period;
    extern /* Subroutine */ int sizmem_(integer *, integer *);
    static integer ltdsiz, ltdptr;

    /* Fortran I/O blocks */
    static cilist io___1329 = { 0, 0, 0, fmt_901, 0 };



/*     THIS ROUTINE UPDATES THE INDEPENDENT VOLTAGE AND CURRENT SOURCES */
/* USED IN THE CIRCUIT.  IT ALSO UPDATES THE LTD TABLE (WHICH CONTAINS */
/* PREVIOUS (DELAYED) VALUES OF THE SOURCES USED TO MODEL TRANSMISSION */
/* LINES). */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    for (id = 9; id <= 10; ++id) {
	loc = cirdat_1.locate[id - 1];
L10:
	if (loc == 0) {
	    goto L500;
	}
	if (id == 9 && nodplc[loc + 10] != 0) {
	    goto L500;
	}
	if (id == 10 && nodplc[loc + 5] != 0) {
	    goto L500;
	}
	locv = nodplc[loc];
	locp = nodplc[loc + 4];
	itype = nodplc[loc + 3] + 1;
	switch (itype) {
	    case 1:  goto L490;
	    case 2:  goto L100;
	    case 3:  goto L200;
	    case 4:  goto L300;
	    case 5:  goto L400;
	    case 6:  goto L450;
	}

/*  PULSE SOURCE */

L100:
	v1 = blank_1.value[locp];
	v2 = blank_1.value[locp + 1];
	t1 = blank_1.value[locp + 2];
	t2 = blank_1.value[locp + 3];
	t3 = blank_1.value[locp + 4];
	t4 = blank_1.value[locp + 5];
	period = blank_1.value[locp + 6];
	time1 = status_1.time;
	if (time1 <= 0.) {
	    goto L160;
	}
L110:
	if (time1 < t1 + period) {
	    goto L120;
	}
	time1 -= period;
	goto L110;
L120:
	if (time1 < t4) {
	    goto L130;
	}
	blank_1.value[locv] = v1;
	goto L490;
L130:
	if (time1 < t3) {
	    goto L140;
	}
	blank_1.value[locv] = v2 + (time1 - t3) * (v1 - v2) / (t4 - t3);
	goto L490;
L140:
	if (time1 < t2) {
	    goto L150;
	}
	blank_1.value[locv] = v2;
	goto L490;
L150:
	if (time1 < t1) {
	    goto L160;
	}
	blank_1.value[locv] = v1 + (time1 - t1) * (v2 - v1) / (t2 - t1);
	goto L490;
L160:
	blank_1.value[locv] = v1;
	goto L490;

/*  SINUSOIDAL SOURCE */

L200:
	v1 = blank_1.value[locp];
	v2 = blank_1.value[locp + 1];
	omeg = blank_1.value[locp + 2];
	t1 = blank_1.value[locp + 3];
	theta = blank_1.value[locp + 4];
	time1 = status_1.time - t1;
	if (time1 > 0.) {
	    goto L210;
	}
	blank_1.value[locv] = v1;
	goto L490;
L210:
	if (theta != 0.) {
	    goto L220;
	}
	blank_1.value[locv] = v1 + v2 * sin(omeg * time1);
	goto L490;
L220:
	blank_1.value[locv] = v1 + v2 * sin(omeg * time1) * exp(-time1 * 
		theta);
	goto L490;

/*  EXPONENTIAL SOURCE */

L300:
	v1 = blank_1.value[locp];
	v2 = blank_1.value[locp + 1];
	t1 = blank_1.value[locp + 2];
	tau1 = blank_1.value[locp + 3];
	t2 = blank_1.value[locp + 4];
	tau2 = blank_1.value[locp + 5];
	time1 = status_1.time;
	if (time1 > t1) {
	    goto L310;
	}
	blank_1.value[locv] = v1;
	goto L490;
L310:
	if (time1 > t2) {
	    goto L320;
	}
	blank_1.value[locv] = v1 + (v2 - v1) * (1. - exp((t1 - time1) / tau1))
		;
	goto L490;
L320:
	blank_1.value[locv] = v1 + (v2 - v1) * (1. - exp((t1 - time1) / tau1))
		 + (v1 - v2) * (1. - exp((t2 - time1) / tau2));
	goto L490;

/*  PIECEWISE-LINEAR SOURCE */

L400:
	t1 = blank_1.value[locp];
	v1 = blank_1.value[locp + 1];
	t2 = blank_1.value[locp + 2];
	v2 = blank_1.value[locp + 3];
	iknt = 4;
L410:
	if (status_1.time <= t2) {
	    goto L420;
	}
	t1 = t2;
	v1 = v2;
	t2 = blank_1.value[locp + iknt];
	v2 = blank_1.value[locp + iknt + 1];
	iknt += 2;
	goto L410;
L420:
	blank_1.value[locv] = v1 + (status_1.time - t1) / (t2 - t1) * (v2 - 
		v1);
	goto L490;

/*  SINGLE-FREQUENCY FM */

L450:
	v1 = blank_1.value[locp];
	v2 = blank_1.value[locp + 1];
	omegc = blank_1.value[locp + 2];
	xmod = blank_1.value[locp + 3];
	omegs = blank_1.value[locp + 4];
	blank_1.value[locv] = v1 + v2 * sin(omegc * status_1.time + xmod * 
		sin(omegs * status_1.time));
L490:
	loc = nodplc[loc - 1];
	goto L10;
L500:
	;
    }

/*  UPDATE TRANSMISSION LINE SOURCES */

    if (cirdat_1.jelcnt[16] == 0) {
	goto L1000;
    }
    if (status_1.mode != 2) {
	goto L1000;
    }
    sizmem_(&tabinf_1.ltd, &ltdsiz);
    numtd = ltdsiz / cirdat_1.ntlin;
    if (numtd < 3) {
	goto L900;
    }
    loc = cirdat_1.locate[16];
L610:
    if (loc == 0) {
	goto L1000;
    }
    locv = nodplc[loc];
    td = blank_1.value[locv + 1];
    baktim = status_1.time - td;
    if (baktim < 0.) {
	goto L640;
    }
    ltdptr = nodplc[loc + 29];
    icntr = 2;
    l1 = tabinf_1.ltd;
    l2 = l1 + cirdat_1.ntlin;
    l3 = l2 + cirdat_1.ntlin;
    t1 = blank_1.value[l1];
    t2 = blank_1.value[l2];
L620:
    t3 = blank_1.value[l3];
    ++icntr;
    if (baktim <= t3) {
	goto L630;
    }
    if (icntr == numtd) {
	goto L900;
    }
    l1 = l2;
    l2 = l3;
    l3 = l2 + cirdat_1.ntlin;
    t1 = t2;
    t2 = t3;
    goto L620;
L630:
    dt1t2 = t1 - t2;
    dt1t3 = t1 - t3;
    dt2t3 = t2 - t3;
    tdnom1 = 1. / (dt1t2 * dt1t3);
    tdnom2 = -1. / (dt1t2 * dt2t3);
    tdnom3 = 1. / (dt2t3 * dt1t3);
    dtt1 = baktim - t1;
    dtt2 = baktim - t2;
    dtt3 = baktim - t3;
    tfact1 = dtt2 * dtt3 * tdnom1;
    tfact2 = dtt1 * dtt3 * tdnom2;
    tfact3 = dtt1 * dtt2 * tdnom3;
    blank_1.value[locv + 2] = blank_1.value[l1 + ltdptr - 1] * tfact1 + 
	    blank_1.value[l2 + ltdptr - 1] * tfact2 + blank_1.value[l3 + 
	    ltdptr - 1] * tfact3;
    blank_1.value[locv + 3] = blank_1.value[l1 + ltdptr] * tfact1 + 
	    blank_1.value[l2 + ltdptr] * tfact2 + blank_1.value[l3 + ltdptr] *
	     tfact3;
L640:
    loc = nodplc[loc - 1];
    goto L610;

/*  INTERNAL LOGIC ERROR:  LESS THAN 3 ENTRIES IN LTD */

L900:
    flags_1.nogo = 1;
    io___1329.ciunit = status_1.iofile;
    s_wsfe(&io___1329);
    do_fio(&c__1, (char *)&numtd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&icntr, (ftnlen)sizeof(integer));
    e_wsfe();

/*  FINISHED */

L1000:
    return 0;
} /* sorupd_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int sorstp_(integer *itlim)
{
    /* Format strings */
    static char fmt_110[] = "(\0020 SOURCE STEPPING METHOD FAILED\002)";

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    extern /* Subroutine */ int iter8_(integer *);
    static doublereal bound, fractn;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

    /* Fortran I/O blocks */
    static cilist io___1334 = { 0, 0, 0, fmt_110, 0 };



/*     THIS ROUTINE USES THE SOURCE STEPPING METHOD TO SOLVE THE DC */
/*     OPERATING POINT */

/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

    bound = .015625;
    fractn = .0625;

/*  STEP DOWN SOURCES */

L10:
    fractn *= 2.;
    status_1.sfactr *= fractn;
    if (status_1.sfactr < bound) {
	goto L100;
    }
    status_1.initf = 2;
    iter8_(itlim);
    miscel_1.rstats[5] += status_1.iterno;
    if (flags_1.igoof != 0) {
	goto L10;
    }
    fractn = 2.;

/*  STEP UP SOURCES */

L20:
    status_1.sfactr *= fractn;
    if (status_1.sfactr <= 1.) {
	goto L30;
    }
    status_1.sfactr = 1.;
L30:
    status_1.initf = 3;
    iter8_(itlim);
    miscel_1.rstats[5] += status_1.iterno;
    if (flags_1.igoof == 0 && status_1.sfactr == 1.) {
	goto L200;
    }
    if (flags_1.igoof == 0) {
	goto L20;
    }

/*  STEP DOWN IF STEP UP FAILED */

L40:
    fractn = sqrt(fractn);
    if (fractn < 1.0001) {
	goto L100;
    }
    status_1.sfactr /= fractn;
    status_1.initf = 3;
    iter8_(itlim);
    miscel_1.rstats[5] += status_1.iterno;
    if (flags_1.igoof != 0) {
	goto L40;
    }
    goto L20;

/*   FINISH WITH SOURCE STEPPING METHOD */

L100:
    flags_1.igoof = 1;
    io___1334.ciunit = status_1.iofile;
    s_wsfe(&io___1334);
    e_wsfe();
L200:
    status_1.initf = 2;
    return 0;
} /* sorstp_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int iter8_(integer *itlim)
{
    /* Format strings */
    static char fmt_301[] = "(\0020WARNING:  UNDERFLOW OCCURRED \002,i4,\002"
	    " TIME(S)\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, nic;
    static doublereal tol;
    extern /* Subroutine */ int load_(void);
    static doublereal vold, vnew;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *),
	     dcsol_(void);
    static integer ipass, ntemp;
    extern /* Subroutine */ int dcdcmp_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static integer ndrflo;
    extern /* Subroutine */ int sizmem_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1347 = { 0, 0, 0, fmt_301, 0 };



/*     THIS ROUTINE DRIVES THE NEWTON-RAPHSON ITERATION TECHNIQUE USED TO */
/* SOLVE THE SET OF NONLINEAR CIRCUIT EQUATIONS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    flags_1.igoof = 0;
    status_1.iterno = 0;
    ndrflo = 0;
    status_1.noncon = 0;
    ipass = 0;

/*  CONSTRUCT LINEAR EQUATIONS AND CHECK CONVERGENCE */

L10:
    status_1.ivmflg = 0;
    load_();
/* L15: */
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L300;
    }
    ++status_1.iterno;
    switch (status_1.initf) {
	case 1:  goto L20;
	case 2:  goto L30;
	case 3:  goto L40;
	case 4:  goto L60;
	case 5:  goto L50;
	case 6:  goto L60;
    }
L20:
    if (status_1.mode != 1) {
	goto L22;
    }
    sizmem_(&tabinf_1.nsnod, &nic);
    if (nic == 0) {
	goto L22;
    }
    if (ipass != 0) {
	status_1.noncon = ipass;
    }
    ipass = 0;
L22:
    if (status_1.noncon == 0) {
	goto L300;
    }
    goto L100;
L30:
    status_1.initf = 3;
    if (flags_1.lvlcod == 3) {
	flags_1.lvlcod = 2;
    }
    status_1.ipiv = 1;
L40:
    if (status_1.noncon == 0) {
	status_1.initf = 1;
    }
    ipass = 1;
    goto L100;
L50:
    if (status_1.iterno > 1) {
	goto L60;
    }
    status_1.ipiv = 1;
    if (flags_1.lvlcod == 3) {
	flags_1.lvlcod = 2;
    }
L60:
    status_1.initf = 1;

/*  SOLVE EQUATIONS FOR NEXT ITERATION */

L100:
    if (status_1.iterno >= *itlim) {
	goto L200;
    }
L102:
    dcdcmp_();
    if (flags_1.igoof != 0) {
	goto L400;
    }
    if (flags_1.lvlcod == 1) {
	goto L105;
    }
L105:
    dcsol_();
    goto L120;
L120:
    if (flags_1.igoof == 0) {
	goto L130;
    }
    flags_1.igoof = 0;
    if (flags_1.lvlcod != 1) {
	flags_1.lvlcod = 2;
    }
    status_1.ipiv = 1;
    load_();
    goto L102;
L130:
    blank_1.value[tabinf_1.lvn] = 0.;
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.icswpr + i__ - 1];
	k = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.lvntmp + k - 1] = blank_1.value[
		tabinf_1.lvnim1 + i__ - 1];
/* L135: */
    }
    copy8_(&blank_1.value[tabinf_1.lvntmp], &blank_1.value[tabinf_1.lvnim1], &
	    cirdat_1.nstop);
    ntemp = status_1.noncon;
    status_1.noncon = 0;
    if (ntemp > 0) {
	goto L150;
    }
    if (status_1.iterno == 1) {
	goto L150;
    }
    i__1 = cirdat_1.numnod;
    for (i__ = 2; i__ <= i__1; ++i__) {
	vold = blank_1.value[tabinf_1.lvnim1 + i__ - 1];
	vnew = blank_1.value[tabinf_1.lvn + i__ - 1];
/* Computing MAX */
	d__1 = abs(vold), d__2 = abs(vnew);
	tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.vntol;
	if ((d__1 = vold - vnew, abs(d__1)) <= tol) {
	    goto L140;
	}
	++status_1.noncon;
L140:
	;
    }
L150:
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.icswpr + i__ - 1];
	k = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.lvnim1 + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
/* L160: */
    }
/*     WRITE(IOFILE,151) (VALUE(LVN+K),K=1,NSTOP) */
/* 151 FORMAT(' SOLUTION: '/1P12D10.3) */
    goto L10;

/*  NO CONVERGENCE */

L200:
    flags_1.igoof = 1;
L300:
    if (ndrflo == 0) {
	goto L400;
    }
    io___1347.ciunit = status_1.iofile;
    s_wsfe(&io___1347);
    do_fio(&c__1, (char *)&ndrflo, (ftnlen)sizeof(integer));
    e_wsfe();

/*  FINISHED */

L400:
    return 0;
} /* iter8_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int load_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal g;
    static integer i__;
    static doublereal t1, t2, y0, z0;
    static integer nl1, nl2;
    static doublereal ceq;
    static integer nic, loc;
    static doublereal geq;
    extern /* Subroutine */ int bjt_(void);
    static doublereal val, req, veq;
    static integer ibr1, ibr2;
#define ccap ((doublereal *)&blank_1 + 1)
    static doublereal cind;
#define find ((doublereal *)&blank_1)
#define qcap ((doublereal *)&blank_1)
    extern /* Subroutine */ int jfet_(void);
    static doublereal vcap;
    static integer node;
#define vind ((doublereal *)&blank_1 + 1)
    static integer locv, locy, loct, iptr, node1, node2, node3, node4, loct1, 
	    loct2, iptr1, iptr2;
    extern /* Subroutine */ int zero8_(doublereal *, integer *), diode_(void);
    static integer lcoef, ncoef, ipoly, ntest;
    extern /* Subroutine */ int intgr8_(doublereal *, doublereal *, 
	    doublereal *, integer *), second_(doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int sizmem_(integer *, integer *), evpoly_(
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *), nlcsrc_(void), mosfet_(void);


/*     THIS ROUTINE ZEROES-OUT AND THEN LOADS THE COEFFICIENT MATRIX. */
/* THE ACTIVE DEVICES AND THE CONTROLLED SOURCES ARE LOADED BY SEPARATE */
/* SUBROUTINES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



    second_(&t1);

/*  ZERO Y MATRIX AND CURRENT VECTOR */

    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    zero8_(&blank_1.value[tabinf_1.lvn], &i__1);

/*  RESISTORS */

    loc = cirdat_1.locate[0];
L20:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L30;
    }
    locv = nodplc[loc];
    val = blank_1.value[locv];
    locy = tabinf_1.lvn + nodplc[loc + 5];
    blank_1.value[locy - 1] += val;
    locy = tabinf_1.lvn + nodplc[loc + 6];
    blank_1.value[locy - 1] += val;
    locy = tabinf_1.lvn + nodplc[loc + 3];
    blank_1.value[locy - 1] -= val;
    locy = tabinf_1.lvn + nodplc[loc + 4];
    blank_1.value[locy - 1] -= val;
    loc = nodplc[loc - 1];
    goto L20;

/*  CAPACITORS */

L30:
    loc = cirdat_1.locate[1];
    if (status_1.mode == 1 && status_1.modedc != 2) {
	goto L100;
    }
L40:
    if (loc == 0 || nodplc[loc + 11] != 0) {
	goto L100;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    loct = nodplc[loc + 7];
    ipoly = nodplc[loc + 3];
    if (ipoly == 1) {
	goto L43;
    }
    lcoef = nodplc[loc + 6];
    sizmem_(&nodplc[loc + 6], &ncoef);
L43:
    vcap = blank_1.value[locv + 1];
    if (status_1.mode == 1 && status_1.initf == 2) {
	goto L45;
    }
    if (status_1.nosolv != 0 && status_1.initf == 5) {
	goto L45;
    }
    vcap = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - blank_1.value[
	    tabinf_1.lvnim1 + node2 - 1];
L45:
    blank_1.value[locv + 2] = vcap;
    if (status_1.mode == 1) {
	goto L60;
    }
/* L47: */
    if (status_1.initf != 6) {
	goto L50;
    }
    qcap[tabinf_1.lx0 + loct - 1] = qcap[tabinf_1.lx1 + loct - 1];
    goto L60;
L50:
    if (ipoly == 0) {
	goto L53;
    }
    qcap[tabinf_1.lx0 + loct - 1] = blank_1.value[locv] * vcap;
    if (status_1.initf != 5) {
	goto L60;
    }
    if (status_1.nosolv != 0) {
	qcap[tabinf_1.lx0 + loct - 1] = blank_1.value[locv] * blank_1.value[
		locv + 1];
    }
    qcap[tabinf_1.lx1 + loct - 1] = qcap[tabinf_1.lx0 + loct - 1];
    goto L60;
L53:
    i__1 = locv + 2;
    i__2 = loc + 8;
    evpoly_(&qcap[tabinf_1.lx0 + loct - 1], &c_n1, &lcoef, &ncoef, &i__1, &
	    c__1, &i__2);
    if (status_1.initf != 5) {
	goto L60;
    }
    if (status_1.nosolv == 0) {
	goto L55;
    }
    vcap = blank_1.value[locv + 1];
    blank_1.value[locv + 2] = vcap;
    i__1 = locv + 2;
    i__2 = loc + 8;
    evpoly_(&qcap[tabinf_1.lx0 + loct - 1], &c_n1, &lcoef, &ncoef, &i__1, &
	    c__1, &i__2);
L55:
    qcap[tabinf_1.lx1 + loct - 1] = qcap[tabinf_1.lx0 + loct - 1];
L60:
    if (ipoly == 1) {
	goto L62;
    }
    i__1 = locv + 2;
    i__2 = loc + 8;
    evpoly_(&blank_1.value[locv], &c__0, &lcoef, &ncoef, &i__1, &c__1, &i__2);
L62:
    if (status_1.mode == 1) {
	goto L90;
    }
    intgr8_(&geq, &ceq, &blank_1.value[locv], &loct);
    if (ipoly == 1) {
	goto L65;
    }
    ceq = ceq - geq * vcap + status_1.ag[0] * qcap[tabinf_1.lx0 + loct - 1];
L65:
    if (status_1.initf != 5) {
	goto L70;
    }
    ccap[tabinf_1.lx1 + loct - 1] = ccap[tabinf_1.lx0 + loct - 1];
L70:
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] += geq;
    locy = tabinf_1.lvn + nodplc[loc + 10];
    blank_1.value[locy - 1] += geq;
    locy = tabinf_1.lvn + nodplc[loc + 4];
    blank_1.value[locy - 1] -= geq;
    locy = tabinf_1.lvn + nodplc[loc + 5];
    blank_1.value[locy - 1] -= geq;
    blank_1.value[tabinf_1.lvn + node1 - 1] -= ceq;
    blank_1.value[tabinf_1.lvn + node2 - 1] += ceq;
L90:
    loc = nodplc[loc - 1];
    goto L40;

/*  INDUCTORS */

L100:
    if (cirdat_1.jelcnt[2] == 0) {
	goto L400;
    }
    if (status_1.mode == 1) {
	goto L150;
    }
    if (status_1.initf == 6) {
	goto L150;
    }
    loc = cirdat_1.locate[2];
L110:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L120;
    }
    locv = nodplc[loc];
    iptr = nodplc[loc + 4];
    loct = nodplc[loc + 10];
    ipoly = nodplc[loc + 3];
    if (ipoly == 0) {
	goto L115;
    }
    find[tabinf_1.lx0 + loct - 1] = blank_1.value[locv] * blank_1.value[
	    tabinf_1.lvnim1 + iptr - 1];
    if (status_1.initf == 5 && status_1.nosolv != 0) {
	find[tabinf_1.lx0 + loct - 1] = blank_1.value[locv] * blank_1.value[
		locv + 1];
    }
    goto L118;
L115:
    lcoef = nodplc[loc + 9];
    sizmem_(&nodplc[loc + 9], &ncoef);
    cind = blank_1.value[tabinf_1.lvnim1 + iptr - 1];
    if (status_1.initf == 5 && status_1.nosolv != 0) {
	cind = blank_1.value[locv + 1];
    }
    blank_1.value[locv + 2] = cind;
    i__1 = locv + 2;
    i__2 = loc + 11;
    evpoly_(&find[tabinf_1.lx0 + loct - 1], &c_n1, &lcoef, &ncoef, &i__1, &
	    c__1, &i__2);
L118:
    loc = nodplc[loc - 1];
    goto L110;
L120:
    loc = cirdat_1.locate[3];
L130:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L150;
    }
    locv = nodplc[loc];
    nl1 = nodplc[loc + 1];
    nl2 = nodplc[loc + 2];
    iptr1 = nodplc[nl1 + 4];
    iptr2 = nodplc[nl2 + 4];
    loct1 = nodplc[nl1 + 10];
    loct2 = nodplc[nl2 + 10];
    find[tabinf_1.lx0 + loct1 - 1] += blank_1.value[locv] * blank_1.value[
	    tabinf_1.lvnim1 + iptr2 - 1];
    find[tabinf_1.lx0 + loct2 - 1] += blank_1.value[locv] * blank_1.value[
	    tabinf_1.lvnim1 + iptr1 - 1];
    loc = nodplc[loc - 1];
    goto L130;
L150:
    loc = cirdat_1.locate[2];
L160:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L300;
    }
    locv = nodplc[loc];
    iptr = nodplc[loc + 4];
    loct = nodplc[loc + 10];
    ipoly = nodplc[loc + 3];
    if (ipoly == 1) {
	goto L170;
    }
    lcoef = nodplc[loc + 9];
    sizmem_(&nodplc[loc + 9], &ncoef);
L170:
    cind = blank_1.value[tabinf_1.lvnim1 + iptr - 1];
    if (status_1.nosolv != 0 && status_1.initf == 5) {
	cind = blank_1.value[locv + 1];
    }
    blank_1.value[locv + 2] = cind;
/* L180: */
    if (status_1.mode != 1) {
	goto L200;
    }
    veq = 0.;
    req = 0.;
    goto L210;
L200:
    if (status_1.initf != 6) {
	goto L205;
    }
    find[tabinf_1.lx0 + loct - 1] = find[tabinf_1.lx1 + loct - 1];
    goto L210;
L205:
    if (status_1.initf != 5) {
	goto L210;
    }
    find[tabinf_1.lx1 + loct - 1] = find[tabinf_1.lx0 + loct - 1];
L210:
    if (ipoly == 1) {
	goto L220;
    }
    i__1 = locv + 2;
    i__2 = loc + 11;
    evpoly_(&blank_1.value[locv], &c__0, &lcoef, &ncoef, &i__1, &c__1, &i__2);
L220:
    if (status_1.mode == 1) {
	goto L250;
    }
    intgr8_(&req, &veq, &blank_1.value[locv], &loct);
    if (ipoly == 1) {
	goto L250;
    }
    veq = veq - req * cind + status_1.ag[0] * find[tabinf_1.lx0 + loct - 1];
L250:
    blank_1.value[tabinf_1.lvn + iptr - 1] = veq;
    if (status_1.initf != 5) {
	goto L260;
    }
    vind[tabinf_1.lx1 + loct - 1] = vind[tabinf_1.lx0 + loct - 1];
L260:
    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] = -req;
    locy = tabinf_1.lvn + nodplc[loc + 5];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 6];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 7];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 8];
    blank_1.value[locy - 1] = -1.;
    loc = nodplc[loc - 1];
    goto L160;

/*  MUTUAL INDUCTANCES */

L300:
    loc = cirdat_1.locate[3];
L310:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L400;
    }
    locv = nodplc[loc];
    req = status_1.ag[0] * blank_1.value[locv];
    locy = tabinf_1.lvn + nodplc[loc + 3];
    blank_1.value[locy - 1] = -req;
    locy = tabinf_1.lvn + nodplc[loc + 4];
    blank_1.value[locy - 1] = -req;
    loc = nodplc[loc - 1];
    goto L310;

/*  NONLINEAR CONTROLLED SOURCES */

L400:
    nlcsrc_();

/*  VOLTAGE SOURCES */

    loc = cirdat_1.locate[8];
L610:
    if (loc == 0 || nodplc[loc + 10] != 0) {
	goto L700;
    }
    locv = nodplc[loc];
    iptr = nodplc[loc + 5];
    blank_1.value[tabinf_1.lvn + iptr - 1] = blank_1.value[locv] * 
	    status_1.sfactr;
    locy = tabinf_1.lvn + nodplc[loc + 6];
    blank_1.value[locy - 1] += 1.;
    locy = tabinf_1.lvn + nodplc[loc + 7];
    blank_1.value[locy - 1] += -1.;
    locy = tabinf_1.lvn + nodplc[loc + 8];
    blank_1.value[locy - 1] += 1.;
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] += -1.;
    loc = nodplc[loc - 1];
    goto L610;

/*  CURRENT SOURCES */

L700:
    loc = cirdat_1.locate[9];
L710:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L800;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    val = blank_1.value[locv] * status_1.sfactr;
    blank_1.value[tabinf_1.lvn + node1 - 1] -= val;
    blank_1.value[tabinf_1.lvn + node2 - 1] += val;
    loc = nodplc[loc - 1];
    goto L710;

/*  CALL DEVICE MODEL ROUTINES */

L800:
    diode_();
    bjt_();
    jfet_();
    mosfet_();

/*  TRANSMISSION LINES */

    loc = cirdat_1.locate[16];
L910:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L980;
    }
    locv = nodplc[loc];
    z0 = blank_1.value[locv];
    y0 = 1. / z0;
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    ibr1 = nodplc[loc + 7];
    ibr2 = nodplc[loc + 8];
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] += y0;
    locy = tabinf_1.lvn + nodplc[loc + 10];
    blank_1.value[locy - 1] = -y0;
    locy = tabinf_1.lvn + nodplc[loc + 11];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] += y0;
    locy = tabinf_1.lvn + nodplc[loc + 13];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 14];
    blank_1.value[locy - 1] = -y0;
    locy = tabinf_1.lvn + nodplc[loc + 15];
    blank_1.value[locy - 1] = y0;
    locy = tabinf_1.lvn + nodplc[loc + 16];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 17];
    blank_1.value[locy - 1] = y0;
    locy = tabinf_1.lvn + nodplc[loc + 18];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 19];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 22];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 26];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 27];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 30];
    blank_1.value[locy - 1] = -y0;
    locy = tabinf_1.lvn + nodplc[loc + 31];
    blank_1.value[locy - 1] = -y0;
    if (status_1.mode != 1) {
	goto L920;
    }
    locy = tabinf_1.lvn + nodplc[loc + 20];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 21];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 23];
    blank_1.value[locy - 1] = -(1. - knstnt_1.gmin) * z0;
    locy = tabinf_1.lvn + nodplc[loc + 24];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[loc + 25];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[loc + 28];
    blank_1.value[locy - 1] = -(1. - knstnt_1.gmin) * z0;
    goto L950;
L920:
    if (status_1.initf != 5) {
	goto L930;
    }
    if (status_1.nosolv != 0) {
	goto L925;
    }
    blank_1.value[locv + 2] = blank_1.value[tabinf_1.lvnim1 + node3 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1] + blank_1.value[
	    tabinf_1.lvnim1 + ibr2 - 1] * z0;
    blank_1.value[locv + 3] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node2 - 1] + blank_1.value[
	    tabinf_1.lvnim1 + ibr1 - 1] * z0;
    goto L930;
L925:
    blank_1.value[locv + 2] = blank_1.value[locv + 6] + blank_1.value[locv + 
	    7] * z0;
    blank_1.value[locv + 3] = blank_1.value[locv + 4] + blank_1.value[locv + 
	    5] * z0;
L930:
    blank_1.value[tabinf_1.lvn + ibr1 - 1] = blank_1.value[locv + 2];
    blank_1.value[tabinf_1.lvn + ibr2 - 1] = blank_1.value[locv + 3];
L950:
    loc = nodplc[loc - 1];
    goto L910;

/*  INITIALIZE NODES */

L980:
    if (status_1.mode != 1) {
	goto L995;
    }
    if (status_1.initf != 3 && status_1.initf != 2) {
	goto L995;
    }
    sizmem_(&tabinf_1.nsnod, &nic);
    if (nic == 0) {
	goto L995;
    }
    sizmem_(&tabinf_1.icnod, &ntest);
    if (status_1.modedc == 2 && ntest != 0) {
	goto L995;
    }
    g = 1.;
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locy = tabinf_1.lvn + nodplc[tabinf_1.nsmat + i__ - 1];
	blank_1.value[locy - 1] += g;
	node = nodplc[tabinf_1.nsnod + i__ - 1];
	blank_1.value[tabinf_1.lvn + node - 1] += blank_1.value[
		tabinf_1.nsval + i__ - 1] * g;
/* L990: */
    }

/*  TRANSIENT INITIAL CONDITIONS (UIC NOT SPECIFIED) */

L995:
    if (status_1.mode != 1) {
	goto L1000;
    }
    if (status_1.modedc != 2) {
	goto L1000;
    }
    if (status_1.nosolv != 0) {
	goto L1000;
    }
    sizmem_(&tabinf_1.icnod, &nic);
    if (nic == 0) {
	goto L1000;
    }
    g = 1.;
    i__1 = nic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locy = tabinf_1.lvn + nodplc[tabinf_1.icmat + i__ - 1];
	blank_1.value[locy - 1] += g;
	node = nodplc[tabinf_1.icnod + i__ - 1];
	blank_1.value[tabinf_1.lvn + node - 1] += blank_1.value[
		tabinf_1.icval + i__ - 1] * g;
/* L996: */
    }

/*  FINISHED */

L1000:
    second_(&t2);
    miscel_1.rstats[44] = miscel_1.rstats[44] + t2 - t1;
    return 0;
} /* load_ */

#undef cvalue
#undef nodplc
#undef vind
#undef qcap
#undef find
#undef ccap


/* Subroutine */ int nlcsrc_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__, lic;
    static doublereal ceq;
    static integer loc;
    static doublereal geq, veq, tol;
    static integer lvs;
    static doublereal cold;
    static integer larg, ndim;
    static doublereal csrc;
    static integer lnod, lmat, lexp, loct, locy, iptr;
    static doublereal volt;
    static integer node1, node2;
    static doublereal cgain;
    static integer lcoef, ncoef;
    static doublereal vgain;
    static integer icheck;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int sizmem_(integer *, integer *), update_(
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *), evpoly_(doublereal *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    static doublereal transr;


/*     THIS ROUTINE LOADS THE NONLINEAR CONTROLLED SOURCES INTO THE */
/* COEFFICIENT MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  NONLINEAR VOLTAGE-CONTROLLED CURRENT SOURCES */

    loc = cirdat_1.locate[4];
L10:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L100;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    lnod = nodplc[loc + 5];
    lmat = nodplc[loc + 6];
    lcoef = nodplc[loc + 7];
    sizmem_(&nodplc[loc + 7], &ncoef);
    larg = nodplc[loc + 8];
    lexp = nodplc[loc + 9];
    lic = nodplc[loc + 10];
    loct = nodplc[loc + 11] + 1;
    icheck = 0;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	update_(&blank_1.value[lic + i__ - 1], &loct, &nodplc[lnod], &nodplc[
		lnod + 1], &c__2, &icheck);
	blank_1.value[larg + i__ - 1] = blank_1.value[tabinf_1.lx0 + loct - 1]
		;
	loct += 2;
	lnod += 2;
/* L20: */
    }
    evpoly_(&cold, &c__0, &lcoef, &ncoef, &larg, &ndim, &lexp);
    loct = nodplc[loc + 11];
    if (icheck == 1) {
	goto L30;
    }
    if (status_1.initf == 6) {
	goto L30;
    }
/* Computing MAX */
    d__2 = abs(cold), d__3 = (d__1 = blank_1.value[tabinf_1.lx0 + loct - 1], 
	    abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cold - blank_1.value[tabinf_1.lx0 + loct - 1], abs(d__1)) < 
	    tol) {
	goto L40;
    }
L30:
    ++status_1.noncon;
L40:
    blank_1.value[tabinf_1.lx0 + loct - 1] = cold;
    ceq = cold;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	evpoly_(&geq, &i__, &lcoef, &ncoef, &larg, &ndim, &lexp);
	loct += 2;
	blank_1.value[tabinf_1.lx0 + loct - 1] = geq;
	ceq -= geq * blank_1.value[larg + i__ - 1];
	locy = tabinf_1.lvn + nodplc[lmat];
	blank_1.value[locy - 1] += geq;
	locy = tabinf_1.lvn + nodplc[lmat + 1];
	blank_1.value[locy - 1] -= geq;
	locy = tabinf_1.lvn + nodplc[lmat + 2];
	blank_1.value[locy - 1] -= geq;
	locy = tabinf_1.lvn + nodplc[lmat + 3];
	blank_1.value[locy - 1] += geq;
	lmat += 4;
/* L50: */
    }
    blank_1.value[tabinf_1.lvn + node1 - 1] -= ceq;
    blank_1.value[tabinf_1.lvn + node2 - 1] += ceq;
    loc = nodplc[loc - 1];
    goto L10;

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L100:
    loc = cirdat_1.locate[5];
L110:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L200;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    iptr = nodplc[loc + 5];
    lnod = nodplc[loc + 6];
    lmat = nodplc[loc + 7];
    lcoef = nodplc[loc + 8];
    sizmem_(&nodplc[loc + 8], &ncoef);
    larg = nodplc[loc + 9];
    lexp = nodplc[loc + 10];
    lic = nodplc[loc + 11];
    loct = nodplc[loc + 12] + 2;
    icheck = 0;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	update_(&blank_1.value[lic + i__ - 1], &loct, &nodplc[lnod], &nodplc[
		lnod + 1], &c__2, &icheck);
	blank_1.value[larg + i__ - 1] = blank_1.value[tabinf_1.lx0 + loct - 1]
		;
	loct += 2;
	lnod += 2;
/* L120: */
    }
    evpoly_(&volt, &c__0, &lcoef, &ncoef, &larg, &ndim, &lexp);
    loct = nodplc[loc + 12];
    if (icheck == 1) {
	goto L130;
    }
    if (status_1.initf == 6) {
	goto L130;
    }
/* Computing MAX */
    d__2 = abs(volt), d__3 = (d__1 = blank_1.value[tabinf_1.lx0 + loct - 1], 
	    abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if ((d__1 = volt - blank_1.value[tabinf_1.lx0 + loct - 1], abs(d__1)) < 
	    tol) {
	goto L140;
    }
L130:
    ++status_1.noncon;
L140:
    blank_1.value[tabinf_1.lx0 + loct - 1] = volt;
    blank_1.value[tabinf_1.lx0 + loct] = blank_1.value[tabinf_1.lvnim1 + iptr 
	    - 1];
    veq = volt;
    locy = tabinf_1.lvn + nodplc[lmat];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[lmat + 1];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[lmat + 2];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[lmat + 3];
    blank_1.value[locy - 1] = -1.;
    lmat += 4;
    ++loct;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	evpoly_(&vgain, &i__, &lcoef, &ncoef, &larg, &ndim, &lexp);
	loct += 2;
	blank_1.value[tabinf_1.lx0 + loct - 1] = vgain;
	veq -= vgain * blank_1.value[larg + i__ - 1];
	locy = tabinf_1.lvn + nodplc[lmat];
	blank_1.value[locy - 1] -= vgain;
	locy = tabinf_1.lvn + nodplc[lmat + 1];
	blank_1.value[locy - 1] += vgain;
	lmat += 2;
/* L150: */
    }
    blank_1.value[tabinf_1.lvn + iptr - 1] = veq;
    loc = nodplc[loc - 1];
    goto L110;

/*  NONLINEAR CURRENT-CONTROLLED CURRENT SOURCES */

L200:
    loc = cirdat_1.locate[6];
L210:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L300;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    lvs = nodplc[loc + 5];
    lmat = nodplc[loc + 6];
    lcoef = nodplc[loc + 7];
    sizmem_(&nodplc[loc + 7], &ncoef);
    larg = nodplc[loc + 8];
    lexp = nodplc[loc + 9];
    lic = nodplc[loc + 10];
    loct = nodplc[loc + 11] + 1;
    icheck = 0;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iptr = nodplc[lvs + i__ - 1];
	iptr = nodplc[iptr + 5];
	update_(&blank_1.value[lic + i__ - 1], &loct, &iptr, &c__1, &c__2, &
		icheck);
	blank_1.value[larg + i__ - 1] = blank_1.value[tabinf_1.lx0 + loct - 1]
		;
	loct += 2;
/* L220: */
    }
    evpoly_(&csrc, &c__0, &lcoef, &ncoef, &larg, &ndim, &lexp);
    loct = nodplc[loc + 11];
    if (icheck == 1) {
	goto L230;
    }
    if (status_1.initf == 6) {
	goto L230;
    }
/* Computing MAX */
    d__2 = abs(csrc), d__3 = (d__1 = blank_1.value[tabinf_1.lx0 + loct - 1], 
	    abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = csrc - blank_1.value[tabinf_1.lx0 + loct - 1], abs(d__1)) < 
	    tol) {
	goto L240;
    }
L230:
    ++status_1.noncon;
L240:
    blank_1.value[tabinf_1.lx0 + loct - 1] = csrc;
    ceq = csrc;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	evpoly_(&cgain, &i__, &lcoef, &ncoef, &larg, &ndim, &lexp);
	loct += 2;
	blank_1.value[tabinf_1.lx0 + loct - 1] = cgain;
	ceq -= cgain * blank_1.value[larg + i__ - 1];
	locy = tabinf_1.lvn + nodplc[lmat];
	blank_1.value[locy - 1] += cgain;
	locy = tabinf_1.lvn + nodplc[lmat + 1];
	blank_1.value[locy - 1] -= cgain;
	lmat += 2;
/* L250: */
    }
    blank_1.value[tabinf_1.lvn + node1 - 1] -= ceq;
    blank_1.value[tabinf_1.lvn + node2 - 1] += ceq;
    loc = nodplc[loc - 1];
    goto L210;

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L300:
    loc = cirdat_1.locate[7];
L310:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L1000;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    ndim = nodplc[loc + 3];
    cirdat_1.ibr = nodplc[loc + 5];
    lvs = nodplc[loc + 6];
    lmat = nodplc[loc + 7];
    lcoef = nodplc[loc + 8];
    sizmem_(&nodplc[loc + 8], &ncoef);
    larg = nodplc[loc + 9];
    lexp = nodplc[loc + 10];
    lic = nodplc[loc + 11];
    loct = nodplc[loc + 12] + 2;
    icheck = 0;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iptr = nodplc[lvs + i__ - 1];
	iptr = nodplc[iptr + 5];
	update_(&blank_1.value[lic + i__ - 1], &loct, &iptr, &c__1, &c__2, &
		icheck);
	blank_1.value[larg + i__ - 1] = blank_1.value[tabinf_1.lx0 + loct - 1]
		;
	loct += 2;
/* L320: */
    }
    evpoly_(&volt, &c__0, &lcoef, &ncoef, &larg, &ndim, &lexp);
    loct = nodplc[loc + 12];
    if (icheck == 1) {
	goto L330;
    }
    if (status_1.initf == 6) {
	goto L330;
    }
/* Computing MAX */
    d__2 = abs(volt), d__3 = (d__1 = blank_1.value[tabinf_1.lx0 + loct - 1], 
	    abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if ((d__1 = volt - blank_1.value[tabinf_1.lx0 + loct - 1], abs(d__1)) < 
	    tol) {
	goto L340;
    }
L330:
    ++status_1.noncon;
L340:
    blank_1.value[tabinf_1.lx0 + loct - 1] = volt;
    blank_1.value[tabinf_1.lx0 + loct] = blank_1.value[tabinf_1.lvnim1 + 
	    cirdat_1.ibr - 1];
    veq = volt;
    locy = tabinf_1.lvn + nodplc[lmat];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[lmat + 1];
    blank_1.value[locy - 1] = -1.;
    locy = tabinf_1.lvn + nodplc[lmat + 2];
    blank_1.value[locy - 1] = 1.;
    locy = tabinf_1.lvn + nodplc[lmat + 3];
    blank_1.value[locy - 1] = -1.;
    lmat += 4;
    ++loct;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	evpoly_(&transr, &i__, &lcoef, &ncoef, &larg, &ndim, &lexp);
	loct += 2;
	blank_1.value[tabinf_1.lx0 + loct - 1] = transr;
	veq -= transr * blank_1.value[larg + i__ - 1];
	locy = tabinf_1.lvn + nodplc[lmat + i__ - 1];
	blank_1.value[locy - 1] -= transr;
/* L350: */
    }
    blank_1.value[tabinf_1.lvn + cirdat_1.ibr - 1] = veq;
    loc = nodplc[loc - 1];
    goto L310;

/*  FINISHED */

L1000:
    return 0;
} /* nlcsrc_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int update_(doublereal *vinit, integer *loct, integer *node1,
	 integer *node2, integer *nupda, integer *icheck)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal delv, vlim, vnew;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *);
    static doublereal xfact;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE UPDATES AND LIMITS THE CONTROLLING VARIABLES FOR THE */
/* NONLINEAR CONTROLLED SOURCES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    switch (status_1.initf) {
	case 1:  goto L40;
	case 2:  goto L10;
	case 3:  goto L40;
	case 4:  goto L20;
	case 5:  goto L30;
	case 6:  goto L50;
    }
L10:
    vnew = *vinit;
    goto L70;
L20:
    vnew = blank_1.value[tabinf_1.lx0 + *loct - 1];
    goto L70;
L30:
    vnew = blank_1.value[tabinf_1.lx1 + *loct - 1];
    goto L70;
L40:
    vnew = blank_1.value[tabinf_1.lvnim1 + *node1 - 1] - blank_1.value[
	    tabinf_1.lvnim1 + *node2 - 1];
    goto L60;
L50:
    copy8_(&blank_1.value[tabinf_1.lx1 + *loct - 1], &blank_1.value[
	    tabinf_1.lx0 + *loct - 1], nupda);
    xfact = status_1.delta / status_1.delold[1];
    vnew = (xfact + 1.) * blank_1.value[tabinf_1.lx1 + *loct - 1] - xfact * 
	    blank_1.value[tabinf_1.lx2 + *loct - 1];
L60:
    if (abs(vnew) <= 1.) {
	goto L80;
    }
    delv = vnew - blank_1.value[tabinf_1.lx0 + *loct - 1];
    if (abs(delv) <= .1) {
	goto L80;
    }
/* Computing MAX */
    d__2 = (d__1 = blank_1.value[tabinf_1.lx0 + *loct - 1] * .1, abs(d__1));
    vlim = max(d__2,.1);
/* Computing MIN */
    d__2 = abs(delv);
    d__1 = min(d__2,vlim);
    vnew = blank_1.value[tabinf_1.lx0 + *loct - 1] + d_sign(&d__1, &delv);
    goto L70;
L70:
    *icheck = 1;
L80:
    blank_1.value[tabinf_1.lx0 + *loct - 1] = vnew;
    return 0;
} /* update_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int evpoly_(doublereal *result, integer *itype, integer *
	lcoef, integer *ncoef, integer *larg, integer *narg, integer *lexp)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j;
    static doublereal arg, val, arg1;
    extern /* Subroutine */ int zero4_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int evterm_(doublereal *, doublereal *, integer *)
	    , nxtpwr_(integer *, integer *);


/*     THIS ROUTINE EVALUATES A POLYNOMIAL.  LCOEF POINTS TO THE COEF- */
/* FICIENTS, AND LARG POINTS TO THE VALUES OF THE POLYNOMIAL ARGUMENT(S). */

/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    if (*itype < 0) {
	goto L100;
    } else if (*itype == 0) {
	goto L200;
    } else {
	goto L300;
    }

/*  INTEGRATION (POLYNOMIAL *MUST* BE ONE-DIMENSIONAL) */

L100:
    *result = 0.;
    arg = 1.;
    arg1 = blank_1.value[*larg];
    i__1 = *ncoef;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arg *= arg1;
	*result += blank_1.value[*lcoef + i__ - 1] * arg / (doublereal) i__;
/* L110: */
    }
    goto L1000;

/*  EVALUATION OF THE POLYNOMIAL */

L200:
    *result = blank_1.value[*lcoef];
    if (*ncoef == 1) {
	goto L1000;
    }
    zero4_(&nodplc[*lexp], narg);
    i__1 = *ncoef;
    for (i__ = 2; i__ <= i__1; ++i__) {
	nxtpwr_(&nodplc[*lexp], narg);
	if (blank_1.value[*lcoef + i__ - 1] == 0.) {
	    goto L220;
	}
	arg = 1.;
	i__2 = *narg;
	for (j = 1; j <= i__2; ++j) {
	    evterm_(&val, &blank_1.value[*larg + j - 1], &nodplc[*lexp + j - 
		    1]);
	    arg *= val;
/* L210: */
	}
	*result += blank_1.value[*lcoef + i__ - 1] * arg;
L220:
	;
    }
    goto L1000;

/*  PARTIAL DERIVATIVE WITH RESPECT TO THE ITYPE*TH VARIABLE */

L300:
    *result = 0.;
    if (*ncoef == 1) {
	goto L1000;
    }
    zero4_(&nodplc[*lexp], narg);
    i__1 = *ncoef;
    for (i__ = 2; i__ <= i__1; ++i__) {
	nxtpwr_(&nodplc[*lexp], narg);
	if (nodplc[*lexp + *itype - 1] == 0) {
	    goto L330;
	}
	if (blank_1.value[*lcoef + i__ - 1] == 0.) {
	    goto L330;
	}
	arg = 1.;
	i__2 = *narg;
	for (j = 1; j <= i__2; ++j) {
	    if (j == *itype) {
		goto L310;
	    }
	    evterm_(&val, &blank_1.value[*larg + j - 1], &nodplc[*lexp + j - 
		    1]);
	    arg *= val;
	    goto L320;
L310:
	    i__3 = nodplc[*lexp + j - 1] - 1;
	    evterm_(&val, &blank_1.value[*larg + j - 1], &i__3);
	    arg = arg * (doublereal) nodplc[*lexp + j - 1] * val;
L320:
	    ;
	}
	*result += blank_1.value[*lcoef + i__ - 1] * arg;
L330:
	;
    }

/*  FINISHED */

L1000:
    return 0;
} /* evpoly_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int evterm_(doublereal *val, doublereal *arg, integer *iexp)
{
    /* Builtin functions */
    double log(doublereal), exp(doublereal), d_sign(doublereal *, doublereal *
	    );

    /* Local variables */
    static integer jexp;
    static doublereal argexp;


/*     THIS ROUTINE EVALUATES ONE TERM OF A POLYNOMIAL. */

    jexp = *iexp + 1;
    if (jexp >= 6) {
	goto L60;
    }
    switch (jexp) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
    }
L10:
    *val = 1.;
    goto L100;
L20:
    *val = *arg;
    goto L100;
L30:
    *val = *arg * *arg;
    goto L100;
L40:
    *val = *arg * *arg * *arg;
    goto L100;
L50:
    *val = *arg * *arg;
    *val *= *val;
    goto L100;
L60:
    if (*arg == 0.) {
	goto L70;
    }
    argexp = (doublereal) (*iexp) * log((abs(*arg)));
    if (argexp < -200.) {
	goto L70;
    }
    *val = exp(argexp);
    if (*iexp / 2 << 1 == *iexp) {
	goto L100;
    }
    *val = d_sign(val, arg);
    goto L100;
L70:
    *val = 0.;

/*  FINISHED */

L100:
    return 0;
} /* evterm_ */

/* Subroutine */ int nxtpwr_(integer *pwrseq, integer *pdim)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, km1, psum;


/*     THIS ROUTINE DETERMINES THE 'NEXT' SET OF EXPONENTS FOR THE */
/* DIFFERENT DIMENSIONS OF A POLYNOMIAL. */



    /* Parameter adjustments */
    --pwrseq;

    /* Function Body */
    if (*pdim == 1) {
	goto L80;
    }
    k = *pdim;
L10:
    if (pwrseq[k] != 0) {
	goto L20;
    }
    --k;
    if (k != 0) {
	goto L10;
    }
    goto L80;
L20:
    if (k == *pdim) {
	goto L30;
    }
    --pwrseq[k];
    ++pwrseq[k + 1];
    goto L100;
L30:
    km1 = k - 1;
    i__1 = km1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (pwrseq[i__] != 0) {
	    goto L50;
	}
/* L40: */
    }
    pwrseq[1] = pwrseq[*pdim] + 1;
    pwrseq[*pdim] = 0;
    goto L100;
L50:
    psum = 1;
    k = *pdim;
L60:
    if (pwrseq[k - 1] >= 1) {
	goto L70;
    }
    psum += pwrseq[k];
    pwrseq[k] = 0;
    --k;
    goto L60;
L70:
    pwrseq[k] += psum;
    --pwrseq[k - 1];
    goto L100;
L80:
    ++pwrseq[1];

/*  FINISHED */

L100:
    return 0;
} /* nxtpwr_ */

/* Subroutine */ int intgr8_(doublereal *geq, doublereal *ceq, doublereal *
	capval, integer *loct)
{
    /* Local variables */
#define ccap ((doublereal *)&blank_1 + 1)
#define qcap ((doublereal *)&blank_1)
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE PERFORMS THE ACTUAL NUMERICAL INTEGRATION FOR EACH */
/* CIRCUIT ELEMENT. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    if (status_1.method == 2) {
	goto L100;
    }

/*  TRAPEZOIDAL ALGORITHM */

    if (status_1.iord == 1) {
	goto L100;
    }
    ccap[tabinf_1.lx0 + *loct - 1] = -ccap[tabinf_1.lx1 + *loct - 1] * 
	    status_1.ag[1] + status_1.ag[0] * (qcap[tabinf_1.lx0 + *loct - 1] 
	    - qcap[tabinf_1.lx1 + *loct - 1]);
    goto L190;

/*  GEARS ALGORITHM */

L100:
    switch (status_1.iord) {
	case 1:  goto L110;
	case 2:  goto L120;
	case 3:  goto L130;
	case 4:  goto L140;
	case 5:  goto L150;
	case 6:  goto L160;
    }
L110:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1];
    goto L190;
L120:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1] + 
	    status_1.ag[2] * qcap[tabinf_1.lx2 + *loct - 1];
    goto L190;
L130:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1] + 
	    status_1.ag[2] * qcap[tabinf_1.lx2 + *loct - 1] + status_1.ag[3] *
	     qcap[tabinf_1.lx3 + *loct - 1];
    goto L190;
L140:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1] + 
	    status_1.ag[2] * qcap[tabinf_1.lx2 + *loct - 1] + status_1.ag[3] *
	     qcap[tabinf_1.lx3 + *loct - 1] + status_1.ag[4] * qcap[
	    tabinf_1.lx4 + *loct - 1];
    goto L190;
L150:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1] + 
	    status_1.ag[2] * qcap[tabinf_1.lx2 + *loct - 1] + status_1.ag[3] *
	     qcap[tabinf_1.lx3 + *loct - 1] + status_1.ag[4] * qcap[
	    tabinf_1.lx4 + *loct - 1] + status_1.ag[5] * qcap[tabinf_1.lx5 + *
	    loct - 1];
    goto L190;
L160:
    ccap[tabinf_1.lx0 + *loct - 1] = status_1.ag[0] * qcap[tabinf_1.lx0 + *
	    loct - 1] + status_1.ag[1] * qcap[tabinf_1.lx1 + *loct - 1] + 
	    status_1.ag[2] * qcap[tabinf_1.lx2 + *loct - 1] + status_1.ag[3] *
	     qcap[tabinf_1.lx3 + *loct - 1] + status_1.ag[4] * qcap[
	    tabinf_1.lx4 + *loct - 1] + status_1.ag[5] * qcap[tabinf_1.lx5 + *
	    loct - 1] + status_1.ag[6] * qcap[tabinf_1.lx6 + *loct - 1];
/* ... CEQ IS THE EQUIVALENT CURRENT APPLICABLE TO LINEAR CAPACITANCE */
/*    (INDUCTANCE) ONLY, I.E. Q=C*V */
L190:
    *ceq = ccap[tabinf_1.lx0 + *loct - 1] - status_1.ag[0] * qcap[
	    tabinf_1.lx0 + *loct - 1];
    *geq = status_1.ag[0] * *capval;
    return 0;
} /* intgr8_ */

#undef cvalue
#undef nodplc
#undef qcap
#undef ccap


/* Subroutine */ int pnjlim_(doublereal *vnew, doublereal *vold, doublereal *
	vt, doublereal *vcrit, integer *icheck)
{
    /* Builtin functions */
    double log(doublereal);

    /* Local variables */
    static doublereal arg, delv, vlim;


/*     THIS ROUTINE LIMITS THE CHANGE-PER-ITERATION OF DEVICE PN-JUNCTION */
/* VOLTAGES. */

    if (*vnew <= *vcrit) {
	goto L30;
    }
    vlim = *vt + *vt;
    delv = *vnew - *vold;
    if (abs(delv) <= vlim) {
	goto L30;
    }
    if (*vold <= 0.) {
	goto L20;
    }
    arg = delv / *vt + 1.;
    if (arg <= 0.) {
	goto L10;
    }
    *vnew = *vold + *vt * log(arg);
    goto L100;
L10:
    *vnew = *vcrit;
    goto L100;
L20:
    *vnew = *vt * log(*vnew / *vt);
    goto L100;
L30:
    *icheck = 0;

/*  FINISHED */

L100:
    return 0;
} /* pnjlim_ */

/* Subroutine */ int diode_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double exp(doublereal), log(doublereal);

    /* Local variables */
    static doublereal f1, f2, f3, cd, gd, pb;
#define qd ((doublereal *)&blank_1 + 3)
    static doublereal bv, vd, xm;
#define cdo ((doublereal *)&blank_1 + 1)
#define cqd ((doublereal *)&blank_1 + 4)
#define gdo ((doublereal *)&blank_1 + 2)
    static doublereal arg, ceq;
    static integer loc;
    static doublereal evd, geq;
#define vdo ((doublereal *)&blank_1)
    static doublereal tau, vte, tol, capd, area, fcpb, cdeq;
    static integer ioff, locm;
    static doublereal csat, sarg;
    static integer locv, loct;
    static doublereal vlim, gspr;
    static integer locy, node1, node2, node3;
    static doublereal czof2, cdhat, delvd, xfact, vcrit, evrev, czero;
    extern /* Subroutine */ int intgr8_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer icheck;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int pnjlim_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal vdtemp;


/*     THIS ROUTINE PROCESSES DIODES FOR DC AND TRANSIENT ANALYSES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    loc = cirdat_1.locate[10];
L10:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	return 0;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    locm = nodplc[loc + 4];
    ioff = nodplc[loc + 5];
    locm = nodplc[locm];
    loct = nodplc[loc + 10];

/*  DC MODEL PARAMETERS */

    area = blank_1.value[locv];
    csat = blank_1.value[locm] * area;
    gspr = blank_1.value[locm + 1] * area;
    vte = blank_1.value[locm + 2] * status_1.vt;
    bv = blank_1.value[locm + 12];
    vcrit = blank_1.value[locm + 17];

/*  INITIALIZATION */

    icheck = 1;
    switch (status_1.initf) {
	case 1:  goto L100;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L50;
	case 5:  goto L60;
	case 6:  goto L70;
    }
L20:
    if (status_1.mode != 1 || status_1.modedc != 2 || status_1.nosolv == 0) {
	goto L25;
    }
    vd = blank_1.value[locv + 1];
    goto L300;
L25:
    if (ioff != 0) {
	goto L40;
    }
    vd = vcrit;
    goto L300;
L30:
    if (ioff == 0) {
	goto L100;
    }
L40:
    vd = 0.;
    goto L300;
L50:
    vd = vdo[tabinf_1.lx0 + loct - 1];
    goto L300;
L60:
    vd = vdo[tabinf_1.lx1 + loct - 1];
    goto L300;
L70:
    xfact = status_1.delta / status_1.delold[1];
    vdo[tabinf_1.lx0 + loct - 1] = vdo[tabinf_1.lx1 + loct - 1];
    vd = (xfact + 1.) * vdo[tabinf_1.lx1 + loct - 1] - xfact * vdo[
	    tabinf_1.lx2 + loct - 1];
    cdo[tabinf_1.lx0 + loct - 1] = cdo[tabinf_1.lx1 + loct - 1];
    gdo[tabinf_1.lx0 + loct - 1] = gdo[tabinf_1.lx1 + loct - 1];
    goto L110;

/*  COMPUTE NEW NONLINEAR BRANCH VOLTAGE */

L100:
    vd = blank_1.value[tabinf_1.lvnim1 + node3 - 1] - blank_1.value[
	    tabinf_1.lvnim1 + node2 - 1];
L110:
    delvd = vd - vdo[tabinf_1.lx0 + loct - 1];
    cdhat = cdo[tabinf_1.lx0 + loct - 1] + gdo[tabinf_1.lx0 + loct - 1] * 
	    delvd;

/*  BYPASS IF SOLUTION HAS NOT CHANGED */

    if (status_1.initf == 6) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vd), d__3 = (d__1 = vdo[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvd) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cdhat), d__3 = (d__1 = cdo[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cdhat - cdo[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
    vd = vdo[tabinf_1.lx0 + loct - 1];
    cd = cdo[tabinf_1.lx0 + loct - 1];
    gd = gdo[tabinf_1.lx0 + loct - 1];
    goto L800;

/*  LIMIT NEW JUNCTION VOLTAGE */

L200:
    vlim = vte + vte;
    if (bv == 0.) {
	goto L205;
    }
/* Computing MIN */
    d__1 = 0., d__2 = -bv + vte * 10.;
    if (vd < min(d__1,d__2)) {
	goto L210;
    }
L205:
    pnjlim_(&vd, &vdo[tabinf_1.lx0 + loct - 1], &vte, &vcrit, &icheck);
    goto L300;
L210:
    vdtemp = -(vd + bv);
    d__1 = -(vdo[tabinf_1.lx0 + loct - 1] + bv);
    pnjlim_(&vdtemp, &d__1, &vte, &vcrit, &icheck);
    vd = -(vdtemp + bv);

/*  COMPUTE DC CURRENT AND DERIVITIVES */

L300:
    if (vd < vte * -5.) {
	goto L310;
    }
    evd = exp(vd / vte);
    cd = csat * (evd - 1.) + knstnt_1.gmin * vd;
    gd = csat * evd / vte + knstnt_1.gmin;
    goto L330;
L310:
    if (bv == 0.) {
	goto L315;
    }
    if (vd < -bv) {
	goto L320;
    }
L315:
    gd = -csat / vd + knstnt_1.gmin;
    cd = gd * vd;
    goto L330;
L320:
    evrev = exp(-(bv + vd) / status_1.vt);
    cd = -csat * (evrev - 1. + bv / status_1.vt);
    gd = csat * evrev / status_1.vt;
L330:
    if (status_1.mode != 1) {
	goto L500;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L500;
    }
    if (status_1.initf == 4) {
	goto L500;
    }
    goto L700;

/*  CHARGE STORAGE ELEMENTS */

L500:
    tau = blank_1.value[locm + 3];
    czero = blank_1.value[locm + 4] * area;
    pb = blank_1.value[locm + 5];
    xm = blank_1.value[locm + 6];
    fcpb = blank_1.value[locm + 11];
    if (vd >= fcpb) {
	goto L510;
    }
    arg = 1. - vd / pb;
    sarg = exp(-xm * log(arg));
    qd[tabinf_1.lx0 + loct - 1] = tau * cd + pb * czero * (1. - arg * sarg) / 
	    (1. - xm);
    capd = tau * gd + czero * sarg;
    goto L520;
L510:
    f1 = blank_1.value[locm + 14];
    f2 = blank_1.value[locm + 15];
    f3 = blank_1.value[locm + 16];
    czof2 = czero / f2;
    qd[tabinf_1.lx0 + loct - 1] = tau * cd + czero * f1 + czof2 * (f3 * (vd - 
	    fcpb) + xm / (pb + pb) * (vd * vd - fcpb * fcpb));
    capd = tau * gd + czof2 * (f3 + xm * vd / pb);

/*  STORE SMALL-SIGNAL PARAMETERS */

L520:
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L700;
    }
    if (status_1.initf != 4) {
	goto L600;
    }
    blank_1.value[tabinf_1.lx0 + loct + 3] = capd;
    goto L1000;

/*  TRANSIENT ANALYSIS */

L600:
    if (status_1.initf != 5) {
	goto L610;
    }
    qd[tabinf_1.lx1 + loct - 1] = qd[tabinf_1.lx0 + loct - 1];
L610:
    i__1 = loct + 3;
    intgr8_(&geq, &ceq, &capd, &i__1);
    gd += geq;
    cd += cqd[tabinf_1.lx0 + loct - 1];
    if (status_1.initf != 5) {
	goto L700;
    }
    cqd[tabinf_1.lx1 + loct - 1] = cqd[tabinf_1.lx0 + loct - 1];

/*  CHECK CONVERGENCE */

L700:
    if (status_1.initf != 3) {
	goto L710;
    }
    if (ioff == 0) {
	goto L710;
    }
    goto L750;
L710:
    if (icheck == 1) {
	goto L720;
    }
/* Computing MAX */
    d__1 = abs(cdhat), d__2 = abs(cd);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cdhat - cd, abs(d__1)) <= tol) {
	goto L750;
    }
L720:
    ++status_1.noncon;
L750:
    vdo[tabinf_1.lx0 + loct - 1] = vd;
    cdo[tabinf_1.lx0 + loct - 1] = cd;
    gdo[tabinf_1.lx0 + loct - 1] = gd;

/*  LOAD CURRENT VECTOR */

L800:
    cdeq = cd - gd * vd;
    blank_1.value[tabinf_1.lvn + node2 - 1] += cdeq;
    blank_1.value[tabinf_1.lvn + node3 - 1] -= cdeq;

/*  LOAD MATRIX */

    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lvn + nodplc[loc + 13];
    blank_1.value[locy - 1] += gd;
    locy = tabinf_1.lvn + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gd + gspr;
    locy = tabinf_1.lvn + nodplc[loc + 6];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 7];
    blank_1.value[locy - 1] -= gd;
    locy = tabinf_1.lvn + nodplc[loc + 8];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] -= gd;
L1000:
    loc = nodplc[loc - 1];
    goto L10;
} /* diode_ */

#undef cvalue
#undef nodplc
#undef vdo
#undef gdo
#undef cqd
#undef cdo
#undef qd


/* Subroutine */ int bjt_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double exp(doublereal), sqrt(doublereal), tan(doublereal), log(doublereal)
	    ;

    /* Local variables */
    static doublereal c2, c4, f1, f2, f3, q1, q2, cb, cc, qb, gm, pe, go, pc, 
	    td, tf, gx, ps, tr, cbc, cbe, gbc, gbe;
#define cbo ((doublereal *)&blank_1 + 3)
#define cco ((doublereal *)&blank_1 + 2)
#define qbc ((doublereal *)&blank_1 + 10)
#define qbe ((doublereal *)&blank_1 + 8)
    static doublereal bfm, vbc, arg;
    static integer loc;
    static doublereal vbe, brm;
#define gmo ((doublereal *)&blank_1 + 6)
#define goo ((doublereal *)&blank_1 + 7)
    static doublereal ova;
#define qcs ((doublereal *)&blank_1 + 12)
    static doublereal ovb, oik;
#define qbx ((doublereal *)&blank_1 + 14)
    static doublereal vce, vtc;
#define gxo ((doublereal *)&blank_1 + 16)
    static doublereal vte, vbx, vcs, tol, gpi, gmu, vtn, cex, gex, xme, xmc, 
	    xms, xtf, geq, ceq, arg1, arg2, arg3, cbcn, cben;
#define cqbc ((doublereal *)&blank_1 + 11)
    static doublereal area;
#define cqbe ((doublereal *)&blank_1 + 9)
    static doublereal gben, gbcn, fcpe, gccs, evbc, evbe, cdis;
    static integer ioff;
    static doublereal czbe, czbc;
#define vbco ((doublereal *)&blank_1 + 1)
#define vbeo ((doublereal *)&blank_1)
#define cqcs ((doublereal *)&blank_1 + 13)
#define gpio ((doublereal *)&blank_1 + 4)
#define cqbx ((doublereal *)&blank_1 + 15)
#define gmuo ((doublereal *)&blank_1 + 5)
    static integer locv, locm, loct;
    static doublereal csat, type__, rbpr, rbpi, gcpr, gepr, oikr, xjrb, ctot, 
	    czbx, czcs, ovtf, xjtf, temp;
    static integer ichk1;
    static doublereal sarg, fcpc;
    static integer locy, node1, node2, node3, node4, node5, node6, node7;
    static doublereal capbc, capbe, ceqbc, ceqbe, geqcb;
#define cexbc ((doublereal *)&blank_1 + 17)
    static doublereal cchat, cbhat, capcs, ceqcs, evben, evbcn, ceqbx, denom, 
	    xfact, geqbx, argtf, capbx, sqarg, vcrit, czbcf2, czbef2, czbxf2;
    extern /* Subroutine */ int intgr8_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer icheck;
    static doublereal delvbc;
#define geqcbo ((doublereal *)&blank_1 + 18)
    static doublereal delvbe, dqbdve, dqbdvc;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int pnjlim_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);


/*     THIS ROUTINE PROCESSES BJTS FOR DC AND TRANSIENT ANALYSES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    loc = cirdat_1.locate[11];
L10:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	return 0;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    node7 = nodplc[loc + 29];
    locm = nodplc[loc + 7];
    ioff = nodplc[loc + 8];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = nodplc[loc + 21];
    gccs = 0.;
    ceqcs = 0.;
    geqbx = 0.;
    ceqbx = 0.;
    geqcb = 0.;

/*  DC MODEL PARAMTERS */

    area = blank_1.value[locv];
    bfm = blank_1.value[locm + 1];
    brm = blank_1.value[locm + 7];
    csat = blank_1.value[locm] * area;
    rbpr = blank_1.value[locm + 17] / area;
    rbpi = blank_1.value[locm + 15] / area - rbpr;
    gcpr = blank_1.value[locm + 19] * area;
    gepr = blank_1.value[locm + 18] * area;
    ova = blank_1.value[locm + 3];
    ovb = blank_1.value[locm + 9];
    oik = blank_1.value[locm + 4] / area;
    c2 = blank_1.value[locm + 5] * area;
    vte = blank_1.value[locm + 6] * status_1.vt;
    oikr = blank_1.value[locm + 10] / area;
    c4 = blank_1.value[locm + 11] * area;
    vtc = blank_1.value[locm + 12] * status_1.vt;
    vcrit = blank_1.value[locm + 53];
    td = blank_1.value[locm + 27];
    xjrb = blank_1.value[locm + 16] * area;

/*  INITIALIZATION */

    icheck = 1;
    switch (status_1.initf) {
	case 1:  goto L100;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L50;
	case 5:  goto L60;
	case 6:  goto L70;
    }
L20:
    if (status_1.mode != 1 || status_1.modedc != 2 || status_1.nosolv == 0) {
	goto L25;
    }
    vbe = type__ * blank_1.value[locv + 1];
    vce = type__ * blank_1.value[locv + 2];
    vbc = vbe - vce;
    vbx = vbc;
    vcs = 0.;
    goto L300;
L25:
    if (ioff != 0) {
	goto L40;
    }
    vbe = vcrit;
    vbc = 0.;
    goto L300;
L30:
    if (ioff == 0) {
	goto L100;
    }
L40:
    vbe = 0.;
    vbc = 0.;
    goto L300;
L50:
    vbe = vbeo[tabinf_1.lx0 + loct - 1];
    vbc = vbco[tabinf_1.lx0 + loct - 1];
    vbx = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    vcs = type__ * (blank_1.value[tabinf_1.lvnim1 + node7 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    goto L300;
L60:
    vbe = vbeo[tabinf_1.lx1 + loct - 1];
    vbc = vbco[tabinf_1.lx1 + loct - 1];
    vbx = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    vcs = type__ * (blank_1.value[tabinf_1.lvnim1 + node7 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    if (status_1.mode != 2 || status_1.nosolv == 0) {
	goto L300;
    }
    vbx = type__ * (blank_1.value[locv + 1] - blank_1.value[locv + 2]);
    vcs = 0.;
    goto L300;
L70:
    xfact = status_1.delta / status_1.delold[1];
    vbeo[tabinf_1.lx0 + loct - 1] = vbeo[tabinf_1.lx1 + loct - 1];
    vbe = (xfact + 1.) * vbeo[tabinf_1.lx1 + loct - 1] - xfact * vbeo[
	    tabinf_1.lx2 + loct - 1];
    vbco[tabinf_1.lx0 + loct - 1] = vbco[tabinf_1.lx1 + loct - 1];
    vbc = (xfact + 1.) * vbco[tabinf_1.lx1 + loct - 1] - xfact * vbco[
	    tabinf_1.lx2 + loct - 1];
    cco[tabinf_1.lx0 + loct - 1] = cco[tabinf_1.lx1 + loct - 1];
    cbo[tabinf_1.lx0 + loct - 1] = cbo[tabinf_1.lx1 + loct - 1];
    gpio[tabinf_1.lx0 + loct - 1] = gpio[tabinf_1.lx1 + loct - 1];
    gmuo[tabinf_1.lx0 + loct - 1] = gmuo[tabinf_1.lx1 + loct - 1];
    gmo[tabinf_1.lx0 + loct - 1] = gmo[tabinf_1.lx1 + loct - 1];
    goo[tabinf_1.lx0 + loct - 1] = goo[tabinf_1.lx1 + loct - 1];
    gxo[tabinf_1.lx0 + loct - 1] = gxo[tabinf_1.lx1 + loct - 1];
    goto L110;

/*  COMPUTE NEW NONLINEAR BRANCH VOLTAGES */

L100:
    vbe = type__ * (blank_1.value[tabinf_1.lvnim1 + node5 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node6 - 1]);
    vbc = type__ * (blank_1.value[tabinf_1.lvnim1 + node5 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
L110:
    delvbe = vbe - vbeo[tabinf_1.lx0 + loct - 1];
    delvbc = vbc - vbco[tabinf_1.lx0 + loct - 1];
    vbx = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    vcs = type__ * (blank_1.value[tabinf_1.lvnim1 + node7 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
    cchat = cco[tabinf_1.lx0 + loct - 1] + (gmo[tabinf_1.lx0 + loct - 1] + 
	    goo[tabinf_1.lx0 + loct - 1]) * delvbe - (goo[tabinf_1.lx0 + loct 
	    - 1] + gmuo[tabinf_1.lx0 + loct - 1]) * delvbc;
    cbhat = cbo[tabinf_1.lx0 + loct - 1] + gpio[tabinf_1.lx0 + loct - 1] * 
	    delvbe + gmuo[tabinf_1.lx0 + loct - 1] * delvbc;

/*   BYPASS IF SOLUTION HAS NOT CHANGED */

    if (status_1.initf == 6) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vbe), d__3 = (d__1 = vbeo[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvbe) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vbc), d__3 = (d__1 = vbco[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvbc) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cchat), d__3 = (d__1 = cco[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cchat - cco[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cbhat), d__3 = (d__1 = cbo[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cbhat - cbo[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
    vbe = vbeo[tabinf_1.lx0 + loct - 1];
    vbc = vbco[tabinf_1.lx0 + loct - 1];
    cc = cco[tabinf_1.lx0 + loct - 1];
    cb = cbo[tabinf_1.lx0 + loct - 1];
    gpi = gpio[tabinf_1.lx0 + loct - 1];
    gmu = gmuo[tabinf_1.lx0 + loct - 1];
    gm = gmo[tabinf_1.lx0 + loct - 1];
    go = goo[tabinf_1.lx0 + loct - 1];
    gx = gxo[tabinf_1.lx0 + loct - 1];
    geqcb = geqcbo[tabinf_1.lx0 + loct - 1];
    if (status_1.mode != 1) {
	goto L800;
    }
    goto L900;

/*  LIMIT NONLINEAR BRANCH VOLTAGES */

L200:
    ichk1 = 1;
    pnjlim_(&vbe, &vbeo[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    icheck);
    pnjlim_(&vbc, &vbco[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    ichk1);
    if (ichk1 == 1) {
	icheck = 1;
    }

/*  DETERMINE DC CURRENT AND DERIVITIVES */

L300:
    vtn = status_1.vt * blank_1.value[locm + 2];
    if (vbe <= vtn * -5.) {
	goto L320;
    }
    evbe = exp(vbe / vtn);
    cbe = csat * (evbe - 1.) + knstnt_1.gmin * vbe;
    gbe = csat * evbe / vtn + knstnt_1.gmin;
    if (c2 != 0.) {
	goto L310;
    }
    cben = 0.;
    gben = 0.;
    goto L350;
L310:
    evben = exp(vbe / vte);
    cben = c2 * (evben - 1.);
    gben = c2 * evben / vte;
    goto L350;
L320:
    gbe = -csat / vbe + knstnt_1.gmin;
    cbe = gbe * vbe;
    gben = -c2 / vbe;
    cben = gben * vbe;
L350:
    vtn = status_1.vt * blank_1.value[locm + 8];
    if (vbc <= vtn * -5.) {
	goto L370;
    }
    evbc = exp(vbc / vtn);
    cbc = csat * (evbc - 1.) + knstnt_1.gmin * vbc;
    gbc = csat * evbc / vtn + knstnt_1.gmin;
    if (c4 != 0.) {
	goto L360;
    }
    cbcn = 0.;
    gbcn = 0.;
    goto L400;
L360:
    evbcn = exp(vbc / vtc);
    cbcn = c4 * (evbcn - 1.);
    gbcn = c4 * evbcn / vtc;
    goto L400;
L370:
    gbc = -csat / vbc + knstnt_1.gmin;
    cbc = gbc * vbc;
    gbcn = -c4 / vbc;
    cbcn = gbcn * vbc;

/*  DETERMINE BASE CHARGE TERMS */

L400:
    q1 = 1. / (1. - ova * vbc - ovb * vbe);
    if (oik != 0.) {
	goto L405;
    }
    if (oikr != 0.) {
	goto L405;
    }
    qb = q1;
    dqbdve = q1 * qb * ovb;
    dqbdvc = q1 * qb * ova;
    goto L410;
L405:
    q2 = oik * cbe + oikr * cbc;
/* Computing MAX */
    d__1 = 0., d__2 = q2 * 4. + 1.;
    arg = max(d__1,d__2);
    sqarg = 1.;
    if (arg != 0.) {
	sqarg = sqrt(arg);
    }
    qb = q1 * (sqarg + 1.) / 2.;
    dqbdve = q1 * (qb * ovb + oik * gbe / sqarg);
    dqbdvc = q1 * (qb * ova + oikr * gbc / sqarg);

/*  WEIL'S APPROX. FOR EXCESS PHASE APPLIED WITH BACKWARD- */
/*  EULER INTEGRATION */

L410:
    cc = 0.;
    cex = cbe;
    gex = gbe;
    if (status_1.mode == 1) {
	goto L420;
    }
    if (td == 0.) {
	goto L420;
    }
    arg1 = status_1.delta / td;
    arg2 = arg1 * 3.;
    arg1 = arg2 * arg1;
    denom = arg1 + 1. + arg2;
    arg3 = arg1 / denom;
    if (status_1.initf != 5) {
	goto L411;
    }
    cexbc[tabinf_1.lx1 + loct - 1] = cbe / qb;
    cexbc[tabinf_1.lx2 + loct - 1] = cexbc[tabinf_1.lx1 + loct - 1];
L411:
    cc = (cexbc[tabinf_1.lx1 + loct - 1] * (status_1.delta / status_1.delold[
	    1] + 1. + arg2) - cexbc[tabinf_1.lx2 + loct - 1] * status_1.delta 
	    / status_1.delold[1]) / denom;
    cex = cbe * arg3;
    gex = gbe * arg3;
    cexbc[tabinf_1.lx0 + loct - 1] = cc + cex / qb;

/*  DETERMINE DC INCREMENTAL CONDUCTANCES */

L420:
    cc = cc + (cex - cbc) / qb - cbc / brm - cbcn;
    cb = cbe / bfm + cben + cbc / brm + cbcn;
    gx = rbpr + rbpi / qb;
    if (xjrb == 0.) {
	goto L430;
    }
/* Computing MAX */
    d__1 = cb / xjrb;
    arg1 = max(d__1,1e-9);
    arg2 = (sqrt(arg1 * 14.59025 + 1.) - 1.) / 2.4317 / sqrt(arg1);
    arg1 = tan(arg2);
    gx = rbpr + rbpi * 3. * (arg1 - arg2) / arg2 / arg1 / arg1;
L430:
    if (gx != 0.) {
	gx = 1. / gx;
    }
    gpi = gbe / bfm + gben;
    gmu = gbc / brm + gbcn;
    go = (gbc + (cex - cbc) * dqbdvc / qb) / qb;
    gm = (gex - (cex - cbc) * dqbdve / qb) / qb - go;
    if (status_1.mode != 1) {
	goto L500;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L500;
    }
    if (status_1.initf == 4) {
	goto L500;
    }
    goto L700;

/*  CHARGE STORAGE ELEMENTS */

L500:
    tf = blank_1.value[locm + 23];
    tr = blank_1.value[locm + 32];
    czbe = blank_1.value[locm + 20] * area;
    pe = blank_1.value[locm + 21];
    xme = blank_1.value[locm + 22];
    cdis = blank_1.value[locm + 31];
    ctot = blank_1.value[locm + 28] * area;
    czbc = ctot * cdis;
    czbx = ctot - czbc;
    pc = blank_1.value[locm + 29];
    xmc = blank_1.value[locm + 30];
    fcpe = blank_1.value[locm + 45];
    czcs = blank_1.value[locm + 37] * area;
    ps = blank_1.value[locm + 38];
    xms = blank_1.value[locm + 39];
    xtf = blank_1.value[locm + 24];
    ovtf = blank_1.value[locm + 25];
    xjtf = blank_1.value[locm + 26] * area;
    if (tf == 0.) {
	goto L505;
    }
    if (vbe <= 0.) {
	goto L505;
    }
    argtf = 0.;
    arg2 = 0.;
    arg3 = 0.;
    if (xtf == 0.) {
	goto L504;
    }
    argtf = xtf;
    if (ovtf != 0.) {
	argtf *= exp(vbc * ovtf);
    }
    arg2 = argtf;
    if (xjtf == 0.) {
	goto L503;
    }
    temp = cbe / (cbe + xjtf);
    argtf = argtf * temp * temp;
    arg2 = argtf * (3. - temp - temp);
L503:
    arg3 = cbe * argtf * ovtf;
L504:
    cbe = cbe * (argtf + 1.) / qb;
    gbe = (gbe * (arg2 + 1.) - cbe * dqbdve) / qb;
    geqcb = tf * (arg3 - cbe * dqbdvc) / qb;
L505:
    if (vbe >= fcpe) {
	goto L510;
    }
    arg = 1. - vbe / pe;
    sarg = exp(-xme * log(arg));
    qbe[tabinf_1.lx0 + loct - 1] = tf * cbe + pe * czbe * (1. - arg * sarg) / 
	    (1. - xme);
    capbe = tf * gbe + czbe * sarg;
    goto L520;
L510:
    f1 = blank_1.value[locm + 46];
    f2 = blank_1.value[locm + 47];
    f3 = blank_1.value[locm + 48];
    czbef2 = czbe / f2;
    qbe[tabinf_1.lx0 + loct - 1] = tf * cbe + czbe * f1 + czbef2 * (f3 * (vbe 
	    - fcpe) + xme / (pe + pe) * (vbe * vbe - fcpe * fcpe));
    capbe = tf * gbe + czbef2 * (f3 + xme * vbe / pe);
L520:
    fcpc = blank_1.value[locm + 49];
    f1 = blank_1.value[locm + 50];
    f2 = blank_1.value[locm + 51];
    f3 = blank_1.value[locm + 52];
    if (vbc >= fcpc) {
	goto L530;
    }
    arg = 1. - vbc / pc;
    sarg = exp(-xmc * log(arg));
    qbc[tabinf_1.lx0 + loct - 1] = tr * cbc + pc * czbc * (1. - arg * sarg) / 
	    (1. - xmc);
    capbc = tr * gbc + czbc * sarg;
    goto L540;
L530:
    czbcf2 = czbc / f2;
    qbc[tabinf_1.lx0 + loct - 1] = tr * cbc + czbc * f1 + czbcf2 * (f3 * (vbc 
	    - fcpc) + xmc / (pc + pc) * (vbc * vbc - fcpc * fcpc));
    capbc = tr * gbc + czbcf2 * (f3 + xmc * vbc / pc);
L540:
    if (vbx >= fcpc) {
	goto L550;
    }
    arg = 1. - vbx / pc;
    sarg = exp(-xmc * log(arg));
    qbx[tabinf_1.lx0 + loct - 1] = pc * czbx * (1. - arg * sarg) / (1. - xmc);
    capbx = czbx * sarg;
    goto L560;
L550:
    czbxf2 = czbx / f2;
    qbx[tabinf_1.lx0 + loct - 1] = czbx * f1 + czbxf2 * (f3 * (vbx - fcpc) + 
	    xmc / (pc + pc) * (vbx * vbx - fcpc * fcpc));
    capbx = czbxf2 * (f3 + xmc * vbx / pc);
L560:
    if (vcs >= 0.) {
	goto L570;
    }
    arg = 1. - vcs / ps;
    sarg = exp(-xms * log(arg));
    qcs[tabinf_1.lx0 + loct - 1] = ps * czcs * (1. - arg * sarg) / (1. - xms);
    capcs = czcs * sarg;
    goto L580;
L570:
    qcs[tabinf_1.lx0 + loct - 1] = vcs * czcs * (xms * vcs / (ps * 2.) + 1.);
    capcs = czcs * (xms * vcs / ps + 1.);

/*  STORE SMALL-SIGNAL PARAMETERS */

L580:
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L700;
    }
    if (status_1.initf != 4) {
	goto L600;
    }
    blank_1.value[tabinf_1.lx0 + loct + 8] = capbe;
    blank_1.value[tabinf_1.lx0 + loct + 10] = capbc;
    blank_1.value[tabinf_1.lx0 + loct + 12] = capcs;
    blank_1.value[tabinf_1.lx0 + loct + 14] = capbx;
    blank_1.value[tabinf_1.lx0 + loct + 16] = geqcb;
    goto L1000;

/*  TRANSIENT ANALYSIS */

L600:
    if (status_1.initf != 5) {
	goto L610;
    }
    qbe[tabinf_1.lx1 + loct - 1] = qbe[tabinf_1.lx0 + loct - 1];
    qbc[tabinf_1.lx1 + loct - 1] = qbc[tabinf_1.lx0 + loct - 1];
    qbx[tabinf_1.lx1 + loct - 1] = qbx[tabinf_1.lx0 + loct - 1];
    qcs[tabinf_1.lx1 + loct - 1] = qcs[tabinf_1.lx0 + loct - 1];
L610:
    i__1 = loct + 8;
    intgr8_(&geq, &ceq, &capbe, &i__1);
    geqcb *= status_1.ag[0];
    gpi += geq;
    cb += cqbe[tabinf_1.lx0 + loct - 1];
    i__1 = loct + 10;
    intgr8_(&geq, &ceq, &capbc, &i__1);
    gmu += geq;
    cb += cqbc[tabinf_1.lx0 + loct - 1];
    cc -= cqbc[tabinf_1.lx0 + loct - 1];
    if (status_1.initf != 5) {
	goto L700;
    }
    cqbe[tabinf_1.lx1 + loct - 1] = cqbe[tabinf_1.lx0 + loct - 1];
    cqbc[tabinf_1.lx1 + loct - 1] = cqbc[tabinf_1.lx0 + loct - 1];

/*  CHECK CONVERGENCE */

L700:
    if (status_1.initf != 3) {
	goto L710;
    }
    if (ioff == 0) {
	goto L710;
    }
    goto L750;
L710:
    if (icheck == 1) {
	goto L720;
    }
/* Computing MAX */
    d__1 = abs(cchat), d__2 = abs(cc);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cchat - cc, abs(d__1)) > tol) {
	goto L720;
    }
/* Computing MAX */
    d__1 = abs(cbhat), d__2 = abs(cb);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cbhat - cb, abs(d__1)) <= tol) {
	goto L750;
    }
L720:
    ++status_1.noncon;
L750:
    vbeo[tabinf_1.lx0 + loct - 1] = vbe;
    vbco[tabinf_1.lx0 + loct - 1] = vbc;
    cco[tabinf_1.lx0 + loct - 1] = cc;
    cbo[tabinf_1.lx0 + loct - 1] = cb;
    gpio[tabinf_1.lx0 + loct - 1] = gpi;
    gmuo[tabinf_1.lx0 + loct - 1] = gmu;
    gmo[tabinf_1.lx0 + loct - 1] = gm;
    goo[tabinf_1.lx0 + loct - 1] = go;
    gxo[tabinf_1.lx0 + loct - 1] = gx;
    geqcbo[tabinf_1.lx0 + loct - 1] = geqcb;
    if (status_1.mode == 1) {
	goto L900;
    }

/*     CHARGE STORAGE FOR C-S AND B-X JUNCTIONS */

L800:
    i__1 = loct + 12;
    intgr8_(&gccs, &ceq, &capcs, &i__1);
    ceqcs = type__ * (cqcs[tabinf_1.lx0 + loct - 1] - vcs * gccs);
    i__1 = loct + 14;
    intgr8_(&geqbx, &ceq, &capbx, &i__1);
    ceqbx = type__ * (cqbx[tabinf_1.lx0 + loct - 1] - vbx * geqbx);
    if (status_1.initf != 5) {
	goto L900;
    }
    cqbx[tabinf_1.lx1 + loct - 1] = cqbx[tabinf_1.lx0 + loct - 1];
    cqcs[tabinf_1.lx1 + loct - 1] = cqcs[tabinf_1.lx0 + loct - 1];

/*  LOAD CURRENT EXCITATION VECTOR */

L900:
    ceqbe = type__ * (cc + cb - vbe * (gm + go + gpi) + vbc * (go - geqcb));
    ceqbc = type__ * (-cc + vbe * (gm + go) - vbc * (gmu + go));
    blank_1.value[tabinf_1.lvn + node2 - 1] -= ceqbx;
    blank_1.value[tabinf_1.lvn + node4 - 1] = blank_1.value[tabinf_1.lvn + 
	    node4 - 1] + ceqcs + ceqbx + ceqbc;
    blank_1.value[tabinf_1.lvn + node5 - 1] = blank_1.value[tabinf_1.lvn + 
	    node5 - 1] - ceqbe - ceqbc;
    blank_1.value[tabinf_1.lvn + node6 - 1] += ceqbe;
    blank_1.value[tabinf_1.lvn + node7 - 1] -= ceqcs;

/*  LOAD Y MATRIX */

    locy = tabinf_1.lvn + nodplc[loc + 23];
    blank_1.value[locy - 1] += gcpr;
    locy = tabinf_1.lvn + nodplc[loc + 24];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gx + geqbx;
    locy = tabinf_1.lvn + nodplc[loc + 25];
    blank_1.value[locy - 1] += gepr;
    locy = tabinf_1.lvn + nodplc[loc + 26];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gmu + go + gcpr + 
	    gccs + geqbx;
    locy = tabinf_1.lvn + nodplc[loc + 27];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gx + gpi + gmu + 
	    geqcb;
    locy = tabinf_1.lvn + nodplc[loc + 28];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gpi + gepr + gm + go;
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] -= gcpr;
    locy = tabinf_1.lvn + nodplc[loc + 10];
    blank_1.value[locy - 1] -= gx;
    locy = tabinf_1.lvn + nodplc[loc + 11];
    blank_1.value[locy - 1] -= gepr;
    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] -= gcpr;
    locy = tabinf_1.lvn + nodplc[loc + 13];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gmu + gm;
    locy = tabinf_1.lvn + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gm - go;
    locy = tabinf_1.lvn + nodplc[loc + 15];
    blank_1.value[locy - 1] -= gx;
    locy = tabinf_1.lvn + nodplc[loc + 16];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gmu - geqcb;
    locy = tabinf_1.lvn + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gpi;
    locy = tabinf_1.lvn + nodplc[loc + 18];
    blank_1.value[locy - 1] -= gepr;
    locy = tabinf_1.lvn + nodplc[loc + 19];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - go + geqcb;
    locy = tabinf_1.lvn + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gpi - gm - geqcb;
    locy = tabinf_1.lvn + nodplc[loc + 30];
    blank_1.value[locy - 1] += gccs;
    locy = tabinf_1.lvn + nodplc[loc + 31];
    blank_1.value[locy - 1] -= gccs;
    locy = tabinf_1.lvn + nodplc[loc + 32];
    blank_1.value[locy - 1] -= gccs;
    locy = tabinf_1.lvn + nodplc[loc + 33];
    blank_1.value[locy - 1] -= geqbx;
    locy = tabinf_1.lvn + nodplc[loc + 34];
    blank_1.value[locy - 1] -= geqbx;
L1000:
    loc = nodplc[loc - 1];
    goto L10;
} /* bjt_ */

#undef cvalue
#undef nodplc
#undef geqcbo
#undef cexbc
#undef gmuo
#undef cqbx
#undef gpio
#undef cqcs
#undef vbeo
#undef vbco
#undef cqbe
#undef cqbc
#undef gxo
#undef qbx
#undef qcs
#undef goo
#undef gmo
#undef qbe
#undef qbc
#undef cco
#undef cbo


/* Subroutine */ int fetlim_(doublereal *vnew, doublereal *vold, doublereal *
	vto)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal delv, vtox, vtemp, vtsthi, vtstlo;


/*     THIS ROUTINE LIMITS THE PER-ITERATION CHANGE OF FET VOLTAGES. */


/*      THREE REGIONS OF OPERATION ARE IDENTIFIED: */

/*                  V < VTO        DEFINITELY OFF */
/*            VTO <= V <= VTO+3.5D0    OFF OR ON DEPENDING ON VBS */
/*        VTO+3.5D0 < V              DEFINITELY ON */

    vtsthi = (d__1 = (*vold - *vto) * 2., abs(d__1)) + 2.;
    vtstlo = vtsthi / 2. + 2.;
    vtox = *vto + 3.5;
    delv = *vnew - *vold;

    if (*vold < *vto) {
	goto L300;
    }
    if (*vold < vtox) {
	goto L200;
    }

/*  ON ... */

    if (delv > 0.) {
	goto L120;
    }
/* ...  GOING OFF */
    if (*vnew < vtox) {
	goto L110;
    }
    if (-delv <= vtstlo) {
	goto L500;
    }
    *vnew = *vold - vtstlo;
    goto L500;
L110:
/* Computing MAX */
    d__1 = *vnew, d__2 = *vto + 2.;
    *vnew = max(d__1,d__2);
    goto L500;
/* ...  STAYING ON */
L120:
    if (delv < vtsthi) {
	goto L500;
    }
    *vnew = *vold + vtsthi;
    goto L500;

/*  MIDDLE REGION ... */

L200:
    if (delv > 0.) {
	goto L210;
    }
/* ...  DECREASING */
/* Computing MAX */
    d__1 = *vnew, d__2 = *vto - .5;
    *vnew = max(d__1,d__2);
    goto L500;
/* ...  INCREASING */
L210:
/* Computing MIN */
    d__1 = *vnew, d__2 = *vto + 4.;
    *vnew = min(d__1,d__2);
    goto L500;

/*  OFF ... */

L300:
    if (delv > 0.) {
	goto L310;
    }
    if (-delv <= vtsthi) {
	goto L500;
    }
    *vnew = *vold - vtsthi;
    goto L500;
L310:
    vtemp = *vto + .5;
    if (*vnew > vtemp) {
	goto L320;
    }
    if (delv <= vtstlo) {
	goto L500;
    }
    *vnew = *vold + vtstlo;
    goto L500;
L320:
    *vnew = vtemp;

/*  FINISHED */

L500:
    return 0;
} /* fetlim_ */

/* Subroutine */ int limvds_(doublereal *vnew, doublereal *vold)
{
    /* System generated locals */
    doublereal d__1, d__2;


/*     THIS ROUTINE LIMITS THE PER-ITERATION CHANGE OF FET VDS. */

    if (*vold < 3.5) {
	goto L200;
    }

    if (*vnew <= *vold) {
	goto L100;
    }
/* Computing MIN */
    d__1 = *vnew, d__2 = *vold * 3. + 2.;
    *vnew = min(d__1,d__2);
    goto L500;
L100:
    if (*vnew < 3.5) {
	*vnew = max(*vnew,2.);
    }
    goto L500;

L200:
    if (*vnew <= *vold) {
	goto L300;
    }
    *vnew = min(*vnew,4.);
    goto L500;
L300:
    *vnew = max(*vnew,-.5);

L500:
    return 0;
} /* limvds_ */

/* Subroutine */ int jfet_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double exp(doublereal), sqrt(doublereal);

    /* Local variables */
    static doublereal f1, f2, f3, cd, cg, gm, cgd, ggd;
#define cdo ((doublereal *)&blank_1 + 3)
#define cgo ((doublereal *)&blank_1 + 2)
    static doublereal ceq;
#define qgd ((doublereal *)&blank_1 + 11)
    static integer loc;
    static doublereal gds, geq, vgd;
#define gmo ((doublereal *)&blank_1 + 5)
    static doublereal ggs;
#define qgs ((doublereal *)&blank_1 + 9)
    static doublereal vds, vgs, tol, vto, area, fcpb, beta;
#define cgdo ((doublereal *)&blank_1 + 4)
#define cqgd ((doublereal *)&blank_1 + 12)
#define ggdo ((doublereal *)&blank_1 + 8)
    static doublereal phib;
    static integer ioff;
    static doublereal evgd, czgd;
    static integer locm;
#define gdso ((doublereal *)&blank_1 + 6)
#define vgdo ((doublereal *)&blank_1 + 1)
#define ggso ((doublereal *)&blank_1 + 7)
#define cqgs ((doublereal *)&blank_1 + 10)
    static integer locv, loct;
    static doublereal gdpr;
#define vgso ((doublereal *)&blank_1)
    static doublereal type__, gspr, csat, evgs, vgst, twob, vgdt, czgs, twop, 
	    sarg, fcpb2;
    static integer locy, ichk1, node1, node2, node3, node4, node5;
    static doublereal capgd, cdhat, cghat, ceqgd, betap, capgs, cdreq, ceqgs, 
	    xlamb, xfact, vcrit, czgdf2, czgsf2;
    extern /* Subroutine */ int intgr8_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer icheck;
    static doublereal cdrain, delvgd;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal delvgs, delvds;
    extern /* Subroutine */ int pnjlim_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), fetlim_(doublereal *, 
	    doublereal *, doublereal *);


/*     THIS ROUTINE PROCESSES JFETS FOR DC AND TRANSIENT ANALYSES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    loc = cirdat_1.locate[12];
L10:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	return 0;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    locm = nodplc[loc + 6];
    ioff = nodplc[loc + 7];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = nodplc[loc + 18];

/*  DC MODEL PARAMETERS */

    area = blank_1.value[locv];
    vto = blank_1.value[locm];
    beta = blank_1.value[locm + 1] * area;
    xlamb = blank_1.value[locm + 2];
    gdpr = blank_1.value[locm + 3] * area;
    gspr = blank_1.value[locm + 4] * area;
    csat = blank_1.value[locm + 8] * area;
    vcrit = blank_1.value[locm + 15];

/*  INITIALIZATION */

    icheck = 1;
    switch (status_1.initf) {
	case 1:  goto L100;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L50;
	case 5:  goto L60;
	case 6:  goto L70;
    }
L20:
    if (status_1.mode != 1 || status_1.modedc != 2 || status_1.nosolv == 0) {
	goto L25;
    }
    vds = type__ * blank_1.value[locv + 1];
    vgs = type__ * blank_1.value[locv + 2];
    vgd = vgs - vds;
    goto L300;
L25:
    if (ioff != 0) {
	goto L40;
    }
    vgs = -1.;
    vgd = -1.;
    goto L300;
L30:
    if (ioff == 0) {
	goto L100;
    }
L40:
    vgs = 0.;
    vgd = 0.;
    goto L300;
L50:
    vgs = vgso[tabinf_1.lx0 + loct - 1];
    vgd = vgdo[tabinf_1.lx0 + loct - 1];
    goto L300;
L60:
    vgs = vgso[tabinf_1.lx1 + loct - 1];
    vgd = vgdo[tabinf_1.lx1 + loct - 1];
    goto L300;
L70:
    xfact = status_1.delta / status_1.delold[1];
    vgso[tabinf_1.lx0 + loct - 1] = vgso[tabinf_1.lx1 + loct - 1];
    vgs = (xfact + 1.) * vgso[tabinf_1.lx1 + loct - 1] - xfact * vgso[
	    tabinf_1.lx2 + loct - 1];
    vgdo[tabinf_1.lx0 + loct - 1] = vgdo[tabinf_1.lx1 + loct - 1];
    vgd = (xfact + 1.) * vgdo[tabinf_1.lx1 + loct - 1] - xfact * vgdo[
	    tabinf_1.lx2 + loct - 1];
    cgo[tabinf_1.lx0 + loct - 1] = cgo[tabinf_1.lx1 + loct - 1];
    cdo[tabinf_1.lx0 + loct - 1] = cdo[tabinf_1.lx1 + loct - 1];
    cgdo[tabinf_1.lx0 + loct - 1] = cgdo[tabinf_1.lx1 + loct - 1];
    gmo[tabinf_1.lx0 + loct - 1] = gmo[tabinf_1.lx1 + loct - 1];
    gdso[tabinf_1.lx0 + loct - 1] = gdso[tabinf_1.lx1 + loct - 1];
    ggso[tabinf_1.lx0 + loct - 1] = ggso[tabinf_1.lx1 + loct - 1];
    ggdo[tabinf_1.lx0 + loct - 1] = ggdo[tabinf_1.lx1 + loct - 1];
    goto L110;

/*  COMPUTE NEW NONLINEAR BRANCH VOLTAGES */

L100:
    vgs = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node5 - 1]);
    vgd = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
L110:
    delvgs = vgs - vgso[tabinf_1.lx0 + loct - 1];
    delvgd = vgd - vgdo[tabinf_1.lx0 + loct - 1];
    delvds = delvgs - delvgd;
    cghat = cgo[tabinf_1.lx0 + loct - 1] + ggdo[tabinf_1.lx0 + loct - 1] * 
	    delvgd + ggso[tabinf_1.lx0 + loct - 1] * delvgs;
    cdhat = cdo[tabinf_1.lx0 + loct - 1] + gmo[tabinf_1.lx0 + loct - 1] * 
	    delvgs + gdso[tabinf_1.lx0 + loct - 1] * delvds - ggdo[
	    tabinf_1.lx0 + loct - 1] * delvgd;

/*  BYPASS IF SOLUTION HAS NOT CHANGED */

    if (status_1.initf == 6) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vgs), d__3 = (d__1 = vgso[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvgs) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vgd), d__3 = (d__1 = vgdo[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvgd) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cghat), d__3 = (d__1 = cgo[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cghat - cgo[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cdhat), d__3 = (d__1 = cdo[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cdhat - cdo[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
    vgs = vgso[tabinf_1.lx0 + loct - 1];
    vgd = vgdo[tabinf_1.lx0 + loct - 1];
    vds = vgs - vgd;
    cg = cgo[tabinf_1.lx0 + loct - 1];
    cd = cdo[tabinf_1.lx0 + loct - 1];
    cgd = cgdo[tabinf_1.lx0 + loct - 1];
    gm = gmo[tabinf_1.lx0 + loct - 1];
    gds = gdso[tabinf_1.lx0 + loct - 1];
    ggs = ggso[tabinf_1.lx0 + loct - 1];
    ggd = ggdo[tabinf_1.lx0 + loct - 1];
    goto L900;

/*  LIMIT NONLINEAR BRANCH VOLTAGES */

L200:
    ichk1 = 1;
    pnjlim_(&vgs, &vgso[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    icheck);
    pnjlim_(&vgd, &vgdo[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    ichk1);
    if (ichk1 == 1) {
	icheck = 1;
    }
    fetlim_(&vgs, &vgso[tabinf_1.lx0 + loct - 1], &vto);
    fetlim_(&vgd, &vgdo[tabinf_1.lx0 + loct - 1], &vto);

/*  DETERMINE DC CURRENT AND DERIVATIVES */

L300:
    vds = vgs - vgd;
    if (vgs > status_1.vt * -5.) {
	goto L310;
    }
    ggs = -csat / vgs + knstnt_1.gmin;
    cg = ggs * vgs;
    goto L320;
L310:
    evgs = exp(vgs / status_1.vt);
    ggs = csat * evgs / status_1.vt + knstnt_1.gmin;
    cg = csat * (evgs - 1.) + knstnt_1.gmin * vgs;
L320:
    if (vgd > status_1.vt * -5.) {
	goto L330;
    }
    ggd = -csat / vgd + knstnt_1.gmin;
    cgd = ggd * vgd;
    goto L340;
L330:
    evgd = exp(vgd / status_1.vt);
    ggd = csat * evgd / status_1.vt + knstnt_1.gmin;
    cgd = csat * (evgd - 1.) + knstnt_1.gmin * vgd;
L340:
    cg += cgd;

/*  COMPUTE DRAIN CURRENT AND DERIVITIVES FOR NORMAL MODE */

/* L400: */
    if (vds < 0.) {
	goto L450;
    }
    vgst = vgs - vto;

/*  NORMAL MODE, CUTOFF REGION */

    if (vgst > 0.) {
	goto L410;
    }
    cdrain = 0.;
    gm = 0.;
    gds = 0.;
    goto L490;

/*  NORMAL MODE, SATURATION REGION */

L410:
    betap = beta * (xlamb * vds + 1.);
    twob = betap + betap;
    if (vgst > vds) {
	goto L420;
    }
    cdrain = betap * vgst * vgst;
    gm = twob * vgst;
    gds = xlamb * beta * vgst * vgst;
    goto L490;

/*  NORMAL MODE, LINEAR REGION */

L420:
    cdrain = betap * vds * (vgst + vgst - vds);
    gm = twob * vds;
    gds = twob * (vgst - vds) + xlamb * beta * vds * (vgst + vgst - vds);
    goto L490;

/*  COMPUTE DRAIN CURRENT AND DERIVITIVES FOR INVERSE MODE */

L450:
    vgdt = vgd - vto;

/*  INVERSE MODE, CUTOFF REGION */

    if (vgdt > 0.) {
	goto L460;
    }
    cdrain = 0.;
    gm = 0.;
    gds = 0.;
    goto L490;

/*  INVERSE MODE, SATURATION REGION */

L460:
    betap = beta * (1. - xlamb * vds);
    twob = betap + betap;
    if (vgdt > -vds) {
	goto L470;
    }
    cdrain = -betap * vgdt * vgdt;
    gm = -twob * vgdt;
    gds = xlamb * beta * vgdt * vgdt - gm;
    goto L490;

/*  INVERSE MODE, LINEAR REGION */

L470:
    cdrain = betap * vds * (vgdt + vgdt + vds);
    gm = twob * vds;
    gds = twob * vgdt - xlamb * beta * vds * (vgdt + vgdt + vds);

/*  COMPUTE EQUIVALENT DRAIN CURRENT SOURCE */

L490:
    cd = cdrain - cgd;
    if (status_1.mode != 1) {
	goto L500;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L500;
    }
    if (status_1.initf == 4) {
	goto L500;
    }
    goto L700;

/*  CHARGE STORAGE ELEMENTS */

L500:
    czgs = blank_1.value[locm + 5] * area;
    czgd = blank_1.value[locm + 6] * area;
    phib = blank_1.value[locm + 7];
    twop = phib + phib;
    fcpb = blank_1.value[locm + 11];
    fcpb2 = fcpb * fcpb;
    f1 = blank_1.value[locm + 12];
    f2 = blank_1.value[locm + 13];
    f3 = blank_1.value[locm + 14];
    czgsf2 = czgs / f2;
    czgdf2 = czgd / f2;
    if (vgs >= fcpb) {
	goto L510;
    }
    sarg = sqrt(1. - vgs / phib);
    qgs[tabinf_1.lx0 + loct - 1] = twop * czgs * (1. - sarg);
    capgs = czgs / sarg;
    goto L520;
L510:
    qgs[tabinf_1.lx0 + loct - 1] = czgs * f1 + czgsf2 * (f3 * (vgs - fcpb) + (
	    vgs * vgs - fcpb2) / (twop + twop));
    capgs = czgsf2 * (f3 + vgs / twop);
L520:
    if (vgd >= fcpb) {
	goto L530;
    }
    sarg = sqrt(1. - vgd / phib);
    qgd[tabinf_1.lx0 + loct - 1] = twop * czgd * (1. - sarg);
    capgd = czgd / sarg;
    goto L560;
L530:
    qgd[tabinf_1.lx0 + loct - 1] = czgd * f1 + czgdf2 * (f3 * (vgd - fcpb) + (
	    vgd * vgd - fcpb2) / (twop + twop));
    capgd = czgdf2 * (f3 + vgd / twop);

/*  STORE SMALL-SIGNAL PARAMETERS */

L560:
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L700;
    }
    if (status_1.initf != 4) {
	goto L600;
    }
    blank_1.value[tabinf_1.lx0 + loct + 8] = capgs;
    blank_1.value[tabinf_1.lx0 + loct + 10] = capgd;
    goto L1000;

/*  TRANSIENT ANALYSIS */

L600:
    if (status_1.initf != 5) {
	goto L610;
    }
    qgs[tabinf_1.lx1 + loct - 1] = qgs[tabinf_1.lx0 + loct - 1];
    qgd[tabinf_1.lx1 + loct - 1] = qgd[tabinf_1.lx0 + loct - 1];
L610:
    i__1 = loct + 9;
    intgr8_(&geq, &ceq, &capgs, &i__1);
    ggs += geq;
    cg += cqgs[tabinf_1.lx0 + loct - 1];
    i__1 = loct + 11;
    intgr8_(&geq, &ceq, &capgd, &i__1);
    ggd += geq;
    cg += cqgd[tabinf_1.lx0 + loct - 1];
    cd -= cqgd[tabinf_1.lx0 + loct - 1];
    cgd += cqgd[tabinf_1.lx0 + loct - 1];
    if (status_1.initf != 5) {
	goto L700;
    }
    cqgs[tabinf_1.lx1 + loct - 1] = cqgs[tabinf_1.lx0 + loct - 1];
    cqgd[tabinf_1.lx1 + loct - 1] = cqgd[tabinf_1.lx0 + loct - 1];

/*  CHECK CONVERGENCE */

L700:
    if (status_1.initf != 3) {
	goto L710;
    }
    if (ioff == 0) {
	goto L710;
    }
    goto L750;
L710:
    if (icheck == 1) {
	goto L720;
    }
/* Computing MAX */
    d__1 = abs(cghat), d__2 = abs(cg);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cghat - cg, abs(d__1)) >= tol) {
	goto L720;
    }
/* Computing MAX */
    d__1 = abs(cdhat), d__2 = abs(cd);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cdhat - cd, abs(d__1)) <= tol) {
	goto L750;
    }
L720:
    ++status_1.noncon;
L750:
    vgso[tabinf_1.lx0 + loct - 1] = vgs;
    vgdo[tabinf_1.lx0 + loct - 1] = vgd;
    cgo[tabinf_1.lx0 + loct - 1] = cg;
    cdo[tabinf_1.lx0 + loct - 1] = cd;
    cgdo[tabinf_1.lx0 + loct - 1] = cgd;
    gmo[tabinf_1.lx0 + loct - 1] = gm;
    gdso[tabinf_1.lx0 + loct - 1] = gds;
    ggso[tabinf_1.lx0 + loct - 1] = ggs;
    ggdo[tabinf_1.lx0 + loct - 1] = ggd;

/*  LOAD CURRENT VECTOR */

L900:
    ceqgd = type__ * (cgd - ggd * vgd);
    ceqgs = type__ * (cg - cgd - ggs * vgs);
    cdreq = type__ * (cd + cgd - gds * vds - gm * vgs);
    blank_1.value[tabinf_1.lvn + node2 - 1] = blank_1.value[tabinf_1.lvn + 
	    node2 - 1] - ceqgs - ceqgd;
    blank_1.value[tabinf_1.lvn + node4 - 1] = blank_1.value[tabinf_1.lvn + 
	    node4 - 1] - cdreq + ceqgd;
    blank_1.value[tabinf_1.lvn + node5 - 1] = blank_1.value[tabinf_1.lvn + 
	    node5 - 1] + cdreq + ceqgs;

/*  LOAD Y MATRIX */

    locy = tabinf_1.lvn + nodplc[loc + 19];
    blank_1.value[locy - 1] += gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + ggd + ggs;
    locy = tabinf_1.lvn + nodplc[loc + 21];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lvn + nodplc[loc + 22];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gdpr + gds + ggd;
    locy = tabinf_1.lvn + nodplc[loc + 23];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gspr + gds + gm + ggs;
    locy = tabinf_1.lvn + nodplc[loc + 8];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] -= ggd;
    locy = tabinf_1.lvn + nodplc[loc + 10];
    blank_1.value[locy - 1] -= ggs;
    locy = tabinf_1.lvn + nodplc[loc + 11];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 13];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gm - ggd;
    locy = tabinf_1.lvn + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - gm;
    locy = tabinf_1.lvn + nodplc[loc + 15];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - ggs - gm;
    locy = tabinf_1.lvn + nodplc[loc + 16];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gds;
L1000:
    loc = nodplc[loc - 1];
    goto L10;
} /* jfet_ */

#undef cvalue
#undef nodplc
#undef vgso
#undef cqgs
#undef ggso
#undef vgdo
#undef gdso
#undef ggdo
#undef cqgd
#undef cgdo
#undef qgs
#undef gmo
#undef qgd
#undef cgo
#undef cdo


/* Subroutine */ int mosfet_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double log(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal f1, f2, f3, ad, cd;
#define qb ((doublereal *)&blank_1 + 12)
    static doublereal as;
#define qd ((doublereal *)&blank_1 + 16)
    static doublereal pd, gm;
#define qg ((doublereal *)&blank_1 + 14)
    static doublereal ps, cbd, cgb, gbd, cgd;
#define cdo ((doublereal *)&blank_1 + 4)
#define cqb ((doublereal *)&blank_1 + 13)
#define cqd ((doublereal *)&blank_1 + 17)
#define cqg ((doublereal *)&blank_1 + 15)
#define qbd ((doublereal *)&blank_1 + 24)
#define qgd ((doublereal *)&blank_1 + 14)
#define qgb ((doublereal *)&blank_1 + 16)
    static integer loc;
#define gmo ((doublereal *)&blank_1 + 7)
#define qbs ((doublereal *)&blank_1 + 26)
#define qgs ((doublereal *)&blank_1 + 12)
    static doublereal vds, vgs, vbs, vbd, vgd, tol, vgb, cbs, gds, gbs, cgs, 
	    xmj, arg, geq, ceq, cgd1, cgb1, cgs1, vgb1, vgd1, vgs1, von1, 
	    cbdb, cbgb, cgdb, cggb, gcgb, gcgd;
#define cbdo ((doublereal *)&blank_1 + 6)
#define cqbd ((doublereal *)&blank_1 + 25)
#define cgbo ((doublereal *)&blank_1 + 18)
#define gbdo ((doublereal *)&blank_1 + 10)
#define cgdo ((doublereal *)&blank_1 + 19)
#define cqgd ((doublereal *)&blank_1 + 15)
#define cqgb ((doublereal *)&blank_1 + 17)
    static doublereal cgsb;
    static integer ioff;
    static doublereal cbsb;
#define cbso ((doublereal *)&blank_1 + 5)
#define cqbs ((doublereal *)&blank_1 + 27)
    static doublereal gmbs;
#define vbdo ((doublereal *)&blank_1)
#define gdso ((doublereal *)&blank_1 + 8)
#define gbso ((doublereal *)&blank_1 + 11)
#define cgso ((doublereal *)&blank_1 + 20)
#define cqgs ((doublereal *)&blank_1 + 13)
#define vbso ((doublereal *)&blank_1 + 1)
#define vgso ((doublereal *)&blank_1 + 2)
#define vdso ((doublereal *)&blank_1 + 3)
#define vono ((doublereal *)&blank_1 + 21)
    static integer locv, locm;
    static doublereal type__;
    static integer loct;
    static doublereal gdpr, gspr, vgdo, evbs, evbd, czbd, czbs, twop, fcpb;
    static integer node1, node2, node3, node4, node5, node6;
    static doublereal fcpb2, czdf2, sarg, gcgs, qdrn, qsrc, xnrm, xrev;
    static integer locy;
    static doublereal czsf2, gcbdb, gcddb, gcbgb, gcgdb, gcdgb;
#define cbdbo ((doublereal *)&blank_1 + 22)
    static doublereal capbd;
#define cbgbo ((doublereal *)&blank_1 + 21)
    static doublereal gcggb;
#define cgdbo ((doublereal *)&blank_1 + 19)
    static doublereal ceqbd, gcbsb;
#define cggbo ((doublereal *)&blank_1 + 18)
    static doublereal cdhat, cbhat;
#define cbsbo ((doublereal *)&blank_1 + 23)
#define cgsbo ((doublereal *)&blank_1 + 20)
    static doublereal cdsat, qgate, qchan, capbs, xfact;
#define gmbso ((doublereal *)&blank_1 + 9)
    static doublereal ceqgs, ceqgd, cssat, qbulk, ceqgb, gcgsb, vinit, vcrit, 
	    xmjsw, gcdsb, gcsgb, gcsdb, gcssb, ceqqg, ceqqb, ceqqd, cgate, 
	    cqdrn, ceqbs, cdreq, czdwf2, vdsat1;
    extern /* Subroutine */ int moseq1_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), moseq2_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), moseq3_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), intgr8_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal czswf2;
    static integer icheck;
    static doublereal delvbd, delvgd, covlgb, devmod;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
#define vdsato ((doublereal *)&blank_1 + 22)
    static doublereal covlgs, covlgd;
    static integer ibypas;
    static doublereal delvbs, delvgs, delvds;
    extern /* Subroutine */ int fetlim_(doublereal *, doublereal *, 
	    doublereal *), limvds_(doublereal *, doublereal *), pnjlim_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    static doublereal czbdsw, czbssw, sargsw;
    extern /* Subroutine */ int cmeyer_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), moscap_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    static doublereal cqbulk;


/*     THIS ROUTINE PROCESSES MOSFETS FOR DC AND TRANSIENT ANALYSES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DEBUG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    loc = cirdat_1.locate[13];
L10:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	return 0;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    locm = nodplc[loc + 7];
    ioff = nodplc[loc + 8];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = nodplc[loc + 25];

/*  DC MODEL PARAMETERS */

    mosarg_1.xj = blank_1.value[locm + 26];
    mosarg_1.xld = blank_1.value[locm + 27];
    mosarg_1.xl = blank_1.value[locv] - mosarg_1.xld * 2.;
    mosarg_1.xw = blank_1.value[locv + 1];
    devmod = blank_1.value[locv + 7];
    mosarg_1.vto = type__ * blank_1.value[locm + 1];
    mosarg_1.vdsat = type__ * blank_1.value[locv + 9];
    vinit = blank_1.value[locm + 42];
    ad = blank_1.value[locv + 2];
    as = blank_1.value[locv + 3];
    pd = blank_1.value[locv + 10];
    ps = blank_1.value[locv + 11];
    if (blank_1.value[locm + 20] == 0. || ad == 0. || as == 0.) {
	goto L12;
    }
    cdsat = blank_1.value[locm + 20] * ad;
    cssat = blank_1.value[locm + 20] * as;
    goto L15;
L12:
    cdsat = blank_1.value[locm + 10];
    cssat = blank_1.value[locm + 10];
L15:
    if (blank_1.value[locm + 6] <= 0. && blank_1.value[locm + 7] <= 0.) {
	goto L17;
    }
    gdpr = blank_1.value[locm + 6];
    gspr = blank_1.value[locm + 7];
    goto L19;
L17:
    gdpr = blank_1.value[locm + 15] / blank_1.value[locv + 12];
    gspr = blank_1.value[locm + 15] / blank_1.value[locv + 13];
L19:
    covlgs = blank_1.value[locm + 12] * mosarg_1.xw;
    covlgd = blank_1.value[locm + 13] * mosarg_1.xw;
    covlgb = blank_1.value[locm + 14] * mosarg_1.xl;
    mosarg_1.lev = (integer) blank_1.value[locm];

/*     MOS1, MOS2 AND MOS3 MODEL PARAMETERS */

    mosarg_1.beta = blank_1.value[locm + 2] * mosarg_1.xw / mosarg_1.xl;
    mosarg_1.gamma = blank_1.value[locm + 3];
    mosarg_1.phi = blank_1.value[locm + 4];
    mosarg_1.xlamda = blank_1.value[locm + 5];
    mosarg_1.phib = blank_1.value[locm + 11];
    mosarg_1.cox = blank_1.value[locm + 21] * mosarg_1.xw * mosarg_1.xl;
    mosarg_1.xnsub = blank_1.value[locm + 22];
    mosarg_1.xnfs = blank_1.value[locm + 24];
    mosarg_1.uo = blank_1.value[locm + 28];
    mosarg_1.vbp = blank_1.value[locm + 29];
    mosarg_1.uexp = blank_1.value[locm + 30];
    mosarg_1.utra = blank_1.value[locm + 31];
    mosarg_1.vbi = type__ * blank_1.value[locm + 43];
    mosarg_1.xd = blank_1.value[locm + 44];
    mosarg_1.vmax = blank_1.value[locm + 32];
    mosarg_1.xneff = blank_1.value[locm + 33];
    mosarg_1.xqco = blank_1.value[locm + 34];
    mosarg_1.fnarrw = blank_1.value[locm + 38];
    if (mosarg_1.lev == 3) {
	mosarg_1.fnarrw /= mosarg_1.xw;
    }

/*     INITIALIZATION */

    icheck = 1;
    ibypas = 0;
    switch (status_1.initf) {
	case 1:  goto L100;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L50;
	case 5:  goto L60;
	case 6:  goto L70;
    }
L20:
    if (ioff != 0) {
	goto L40;
    }
    vds = type__ * blank_1.value[locv + 4];
    vgs = type__ * blank_1.value[locv + 5];
    vbs = type__ * blank_1.value[locv + 6];
    if (vds != 0.) {
	goto L300;
    }
    if (vgs != 0.) {
	goto L300;
    }
    if (vbs != 0.) {
	goto L300;
    }
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L300;
    }
    vbs = vinit;
    vgs = mosarg_1.vto;
    vds = 0.;
    goto L300;
L30:
    if (ioff == 0) {
	goto L100;
    }
L40:
    vbs = 0.;
    vgs = 0.;
    vds = 0.;
    goto L300;
L50:
    vbs = vbso[tabinf_1.lx0 + loct - 1];
    vgs = vgso[tabinf_1.lx0 + loct - 1];
    vds = vdso[tabinf_1.lx0 + loct - 1];
    goto L300;
L60:
    vbs = vbso[tabinf_1.lx1 + loct - 1];
    vgs = vgso[tabinf_1.lx1 + loct - 1];
    vds = vdso[tabinf_1.lx1 + loct - 1];
    goto L300;
L70:
    xfact = status_1.delta / status_1.delold[1];
    vbso[tabinf_1.lx0 + loct - 1] = vbso[tabinf_1.lx1 + loct - 1];
    vbs = (xfact + 1.) * vbso[tabinf_1.lx1 + loct - 1] - xfact * vbso[
	    tabinf_1.lx2 + loct - 1];
    vgso[tabinf_1.lx0 + loct - 1] = vgso[tabinf_1.lx1 + loct - 1];
    vgs = (xfact + 1.) * vgso[tabinf_1.lx1 + loct - 1] - xfact * vgso[
	    tabinf_1.lx2 + loct - 1];
    vdso[tabinf_1.lx0 + loct - 1] = vdso[tabinf_1.lx1 + loct - 1];
    vds = (xfact + 1.) * vdso[tabinf_1.lx1 + loct - 1] - xfact * vdso[
	    tabinf_1.lx2 + loct - 1];
    vbdo[tabinf_1.lx0 + loct - 1] = vbso[tabinf_1.lx0 + loct - 1] - vdso[
	    tabinf_1.lx0 + loct - 1];
    cdo[tabinf_1.lx0 + loct - 1] = cdo[tabinf_1.lx1 + loct - 1];
    cbso[tabinf_1.lx0 + loct - 1] = cbso[tabinf_1.lx1 + loct - 1];
    cbdo[tabinf_1.lx0 + loct - 1] = cbdo[tabinf_1.lx1 + loct - 1];
    gmo[tabinf_1.lx0 + loct - 1] = gmo[tabinf_1.lx1 + loct - 1];
    gdso[tabinf_1.lx0 + loct - 1] = gdso[tabinf_1.lx1 + loct - 1];
    gmbso[tabinf_1.lx0 + loct - 1] = gmbso[tabinf_1.lx1 + loct - 1];
    gbdo[tabinf_1.lx0 + loct - 1] = gbdo[tabinf_1.lx1 + loct - 1];
    gbso[tabinf_1.lx0 + loct - 1] = gbso[tabinf_1.lx1 + loct - 1];
    cggbo[tabinf_1.lx0 + loct - 1] = cggbo[tabinf_1.lx1 + loct - 1];
    cgdbo[tabinf_1.lx0 + loct - 1] = cgdbo[tabinf_1.lx1 + loct - 1];
    cgsbo[tabinf_1.lx0 + loct - 1] = cgsbo[tabinf_1.lx1 + loct - 1];
    cbgbo[tabinf_1.lx0 + loct - 1] = cbgbo[tabinf_1.lx1 + loct - 1];
    cbdbo[tabinf_1.lx0 + loct - 1] = cbdbo[tabinf_1.lx1 + loct - 1];
    cbsbo[tabinf_1.lx0 + loct - 1] = cbsbo[tabinf_1.lx1 + loct - 1];
    goto L110;

/*  COMPUTE NEW NONLINEAR BRANCH VOLTAGES */

L100:
    vbs = type__ * (blank_1.value[tabinf_1.lvnim1 + node4 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node6 - 1]);
    vgs = type__ * (blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node6 - 1]);
    vds = type__ * (blank_1.value[tabinf_1.lvnim1 + node5 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node6 - 1]);
L110:
    vbd = vbs - vds;
    vgd = vgs - vds;
    vgdo = vgso[tabinf_1.lx0 + loct - 1] - vdso[tabinf_1.lx0 + loct - 1];
    delvbs = vbs - vbso[tabinf_1.lx0 + loct - 1];
    delvbd = vbd - vbdo[tabinf_1.lx0 + loct - 1];
    delvgs = vgs - vgso[tabinf_1.lx0 + loct - 1];
    delvds = vds - vdso[tabinf_1.lx0 + loct - 1];
    delvgd = vgd - vgdo;
    if (devmod < 0.) {
	goto L120;
    }
    cdhat = cdo[tabinf_1.lx0 + loct - 1] - gbdo[tabinf_1.lx0 + loct - 1] * 
	    delvbd + gmbso[tabinf_1.lx0 + loct - 1] * delvbs + gmo[
	    tabinf_1.lx0 + loct - 1] * delvgs + gdso[tabinf_1.lx0 + loct - 1] 
	    * delvds;
    goto L130;
L120:
    cdhat = cdo[tabinf_1.lx0 + loct - 1] - (gbdo[tabinf_1.lx0 + loct - 1] - 
	    gmbso[tabinf_1.lx0 + loct - 1]) * delvbd - gmo[tabinf_1.lx0 + 
	    loct - 1] * delvgd + gdso[tabinf_1.lx0 + loct - 1] * delvds;
L130:
    cbhat = cbso[tabinf_1.lx0 + loct - 1] + cbdo[tabinf_1.lx0 + loct - 1] + 
	    gbdo[tabinf_1.lx0 + loct - 1] * delvbd + gbso[tabinf_1.lx0 + loct 
	    - 1] * delvbs;

/*  BYPASS IF SOLUTION HAS NOT CHANGED */

    if (status_1.initf == 6) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vbs), d__3 = (d__1 = vbso[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvbs) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vbd), d__3 = (d__1 = vbdo[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvbd) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vgs), d__3 = (d__1 = vgso[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvgs) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(vds), d__3 = (d__1 = vdso[tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.vntol;
    if (abs(delvds) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cdhat), d__3 = (d__1 = cdo[tabinf_1.lx0 + loct - 1], abs(d__1))
	    ;
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cdhat - cdo[tabinf_1.lx0 + loct - 1], abs(d__1)) >= tol) {
	goto L200;
    }
/* Computing MAX */
    d__2 = abs(cbhat), d__3 = (d__1 = cbso[tabinf_1.lx0 + loct - 1] + cbdo[
	    tabinf_1.lx0 + loct - 1], abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cbhat - (cbso[tabinf_1.lx0 + loct - 1] + cbdo[tabinf_1.lx0 + 
	    loct - 1]), abs(d__1)) >= tol) {
	goto L200;
    }
    vbs = vbso[tabinf_1.lx0 + loct - 1];
    vbd = vbdo[tabinf_1.lx0 + loct - 1];
    vgs = vgso[tabinf_1.lx0 + loct - 1];
    vds = vdso[tabinf_1.lx0 + loct - 1];
    vgd = vgs - vds;
    vgb = vgs - vbs;
    cd = cdo[tabinf_1.lx0 + loct - 1];
    cbs = cbso[tabinf_1.lx0 + loct - 1];
    cbd = cbdo[tabinf_1.lx0 + loct - 1];
    mosarg_1.cdrain = devmod * (cd + cbd);
    gm = gmo[tabinf_1.lx0 + loct - 1];
    gds = gdso[tabinf_1.lx0 + loct - 1];
    gmbs = gmbso[tabinf_1.lx0 + loct - 1];
    gbd = gbdo[tabinf_1.lx0 + loct - 1];
    gbs = gbso[tabinf_1.lx0 + loct - 1];
    devmod = blank_1.value[locv + 7];
    if (status_1.mode != 1) {
	goto L135;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L135;
    }
    if (mosarg_1.xqco > .5) {
	goto L742;
    }
    goto L850;
L135:
    if (mosarg_1.xqco <= .5) {
	goto L140;
    }
    cgb = cgbo[tabinf_1.lx0 + loct - 1];
    cgd = cgdo[tabinf_1.lx0 + loct - 1];
    cgs = cgso[tabinf_1.lx0 + loct - 1];
    vgs1 = vgso[tabinf_1.lx1 + loct - 1];
    vgb1 = vgs1 - vbso[tabinf_1.lx1 + loct - 1];
    vgd1 = vgs1 - vdso[tabinf_1.lx1 + loct - 1];
    goto L735;
L140:
    cggb = cggbo[tabinf_1.lx0 + loct - 1];
    cgdb = cgdbo[tabinf_1.lx0 + loct - 1];
    cgsb = cgsbo[tabinf_1.lx0 + loct - 1];
    cbgb = cbgbo[tabinf_1.lx0 + loct - 1];
    cbdb = cbdbo[tabinf_1.lx0 + loct - 1];
    cbsb = cbsbo[tabinf_1.lx0 + loct - 1];
    mosarg_1.xqc = blank_1.value[locv + 14];
    ibypas = 1;
    goto L755;

/*  LIMIT NONLINEAR BRANCH VOLTAGES */

L200:
    mosarg_1.von = type__ * blank_1.value[locv + 8];
    if (vdso[tabinf_1.lx0 + loct - 1] < 0.) {
	goto L205;
    }
    fetlim_(&vgs, &vgso[tabinf_1.lx0 + loct - 1], &mosarg_1.von);
    vds = vgs - vgd;
    limvds_(&vds, &vdso[tabinf_1.lx0 + loct - 1]);
    vgd = vgs - vds;
    goto L210;
L205:
    fetlim_(&vgd, &vgdo, &mosarg_1.von);
    vds = vgs - vgd;
    d__1 = -vds;
    d__2 = -vdso[tabinf_1.lx0 + loct - 1];
    limvds_(&d__1, &d__2);
    vgs = vgd + vds;
L210:
    if (vds < 0.) {
	goto L220;
    }
    vcrit = status_1.vt * log(status_1.vt / (knstnt_1.root2 * cssat));
    pnjlim_(&vbs, &vbso[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    icheck);
    vbd = vbs - vds;
    goto L300;
L220:
    vcrit = status_1.vt * log(status_1.vt / (knstnt_1.root2 * cdsat));
    pnjlim_(&vbd, &vbdo[tabinf_1.lx0 + loct - 1], &status_1.vt, &vcrit, &
	    icheck);
    vbs = vbd + vds;

/*  DETERMINE DC CURRENT AND DERIVATIVES */

L300:
    vbd = vbs - vds;
    vgd = vgs - vds;
    vgb = vgs - vbs;
    if (vbs > 0.) {
	goto L310;
    }
    gbs = cssat / status_1.vt;
    cbs = gbs * vbs;
    gbs += knstnt_1.gmin;
    goto L320;
L310:
    evbs = exp(vbs / status_1.vt);
    gbs = cssat * evbs / status_1.vt + knstnt_1.gmin;
    cbs = cssat * (evbs - 1.);
L320:
    if (vbd > 0.) {
	goto L330;
    }
    gbd = cdsat / status_1.vt;
    cbd = gbd * vbd;
    gbd += knstnt_1.gmin;
    goto L400;
L330:
    evbd = exp(vbd / status_1.vt);
    gbd = cdsat * evbd / status_1.vt + knstnt_1.gmin;
    cbd = cdsat * (evbd - 1.);

/*  COMPUTE DRAIN CURRENT AND DERIVATIVES */

L400:
    if (vds < 0.) {
	goto L450;
    }

/*  NORMAL MODE */

    devmod = 1.;
    blank_1.value[locv + 7] = devmod;
    switch (mosarg_1.lev) {
	case 1:  goto L405;
	case 2:  goto L410;
	case 3:  goto L415;
    }
L405:
    moseq1_(&vds, &vbs, &vgs, &gm, &gds, &gmbs);
    goto L460;
L410:
    moseq2_(&vds, &vbs, &vgs, &gm, &gds, &gmbs, &qgate, &qchan, &qbulk, &cggb,
	     &cgdb, &cgsb, &cbgb, &cbdb, &cbsb);
    goto L460;
L415:
    moseq3_(&vds, &vbs, &vgs, &gm, &gds, &gmbs, &qgate, &qchan, &qbulk, &cggb,
	     &cgdb, &cgsb, &cbgb, &cbdb, &cbsb);
    goto L460;

/*  INVERSE MODE */

L450:
    devmod = -1.;
    blank_1.value[locv + 7] = devmod;
    switch (mosarg_1.lev) {
	case 1:  goto L452;
	case 2:  goto L453;
	case 3:  goto L454;
    }
L452:
    d__1 = -vds;
    moseq1_(&d__1, &vbd, &vgd, &gm, &gds, &gmbs);
    goto L460;
L453:
    d__1 = -vds;
    moseq2_(&d__1, &vbd, &vgd, &gm, &gds, &gmbs, &qgate, &qchan, &qbulk, &
	    cggb, &cgsb, &cgdb, &cbgb, &cbsb, &cbdb);
    goto L460;
L454:
    d__1 = -vds;
    moseq3_(&d__1, &vbd, &vgd, &gm, &gds, &gmbs, &qgate, &qchan, &qbulk, &
	    cggb, &cgsb, &cgdb, &cbgb, &cbsb, &cbdb);
L460:
    blank_1.value[locv + 8] = type__ * mosarg_1.von;
    blank_1.value[locv + 9] = type__ * mosarg_1.vdsat;
    if (mosarg_1.xqco <= .5) {
	blank_1.value[locv + 14] = mosarg_1.xqc;
    }

/*  COMPUTE EQUIVALENT DRAIN CURRENT SOURCE */

/* L490: */
    cd = devmod * mosarg_1.cdrain - cbd;
    if (status_1.mode != 1) {
	goto L500;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L500;
    }
    if (status_1.initf == 4) {
	goto L500;
    }
    goto L650;

/*  CHARGE STORAGE ELEMENTS */

/* .. BULK-DRAIN AND BULK-SOURCE DEPLETION CAPACITANCES */

L500:
    czbd = 0.;
    czbs = 0.;
    czbdsw = 0.;
    czbssw = 0.;
    if (blank_1.value[locm + 8] == 0. || blank_1.value[locm + 9] == 0.) {
	goto L505;
    }
    czbd = blank_1.value[locm + 8];
    czbs = blank_1.value[locm + 9];
    goto L510;
L505:
    if (blank_1.value[locm + 16] == 0.) {
	goto L510;
    }
    czbd = blank_1.value[locm + 16] * ad;
    czbs = blank_1.value[locm + 16] * as;
L510:
    if (blank_1.value[locm + 18] == 0.) {
	goto L515;
    }
    czbdsw = blank_1.value[locm + 18] * pd;
    czbssw = blank_1.value[locm + 18] * ps;
L515:
    mosarg_1.phib = blank_1.value[locm + 11];
    xmj = blank_1.value[locm + 17];
    xmjsw = blank_1.value[locm + 19];
    twop = mosarg_1.phib + mosarg_1.phib;
    fcpb = blank_1.value[locm + 37];
    fcpb2 = fcpb * fcpb;
    f1 = blank_1.value[locm + 39];
    f2 = blank_1.value[locm + 40];
    f3 = blank_1.value[locm + 41];
    czsf2 = czbs / f2;
    czswf2 = czbssw / f2;
    czdf2 = czbd / f2;
    czdwf2 = czbdsw / f2;
    if (vbs >= fcpb) {
	goto L520;
    }
    arg = 1. - vbs / mosarg_1.phib;
    sarg = exp(-xmj * log(arg));
    sargsw = exp(-xmjsw * log(arg));
    qbs[tabinf_1.lx0 + loct - 1] = mosarg_1.phib * (czbs * (1. - arg * sarg) /
	     (1. - xmj) + czbssw * (1. - arg * sargsw) / (1. - xmjsw));
    capbs = czbs * sarg + czbssw * sargsw;
    goto L525;
L520:
    qbs[tabinf_1.lx0 + loct - 1] = f1 * (czbs + czbssw) + f3 * (vbs - fcpb) * 
	    (czsf2 + czswf2) + (vbs * vbs - fcpb * fcpb) * (czsf2 * xmj + 
	    czswf2 * xmjsw);
    capbs = f3 * (czsf2 + czswf2) + vbs / mosarg_1.phib * (czsf2 * xmj + 
	    czswf2 * xmjsw);
L525:
    if (vbd >= fcpb) {
	goto L530;
    }
    arg = 1. - vbd / mosarg_1.phib;
    sarg = exp(-xmj * log(arg));
    sargsw = exp(-xmjsw * log(arg));
    qbd[tabinf_1.lx0 + loct - 1] = mosarg_1.phib * (czbd * (1. - arg * sarg) /
	     (1. - xmj) + czbdsw * (1. - arg * sargsw) / (1. - xmjsw));
    capbd = czbd * sarg + czbdsw * sargsw;
    goto L560;
L530:
    qbd[tabinf_1.lx0 + loct - 1] = f1 * (czbd + czbdsw) + f3 * (vbd - fcpb) * 
	    (czdf2 + czdwf2) + (vbd * vbd - fcpb * fcpb) * (czdf2 * xmj + 
	    czdwf2 * xmjsw);
    capbd = f3 * (czdf2 + czdwf2) + vbd / mosarg_1.phib * (czdf2 * xmj + 
	    czdwf2 * xmjsw);

L560:
    if (mosarg_1.xqco <= .5) {
	goto L650;
    }
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L650;
    }
    if (status_1.initf != 4) {
	goto L600;
    }
    goto L705;

/* C    CALCULATE EQUIVALENT CONDUCTANCES AND CURRENTS FOR */
/* C    DEPLETION CAPACITORS */

L600:
    if (status_1.initf != 5) {
	goto L610;
    }
    qbd[tabinf_1.lx1 + loct - 1] = qbd[tabinf_1.lx0 + loct - 1];
    qbs[tabinf_1.lx1 + loct - 1] = qbs[tabinf_1.lx0 + loct - 1];
L610:
    i__1 = loct + 24;
    intgr8_(&geq, &ceq, &capbd, &i__1);
    gbd += geq;
    cbd += cqbd[tabinf_1.lx0 + loct - 1];
    cd -= cqbd[tabinf_1.lx0 + loct - 1];
    i__1 = loct + 26;
    intgr8_(&geq, &ceq, &capbs, &i__1);
    gbs += geq;
    cbs += cqbs[tabinf_1.lx0 + loct - 1];
    if (status_1.initf != 5) {
	goto L650;
    }
    cqbd[tabinf_1.lx1 + loct - 1] = cqbd[tabinf_1.lx0 + loct - 1];
    cqbs[tabinf_1.lx1 + loct - 1] = cqbs[tabinf_1.lx0 + loct - 1];

/*  CHECK CONVERGENCE */

L650:
    if (status_1.initf != 3) {
	goto L660;
    }
    if (ioff != 0) {
	goto L680;
    }
L660:
    if (icheck == 1) {
	goto L670;
    }
/* Computing MAX */
    d__1 = abs(cdhat), d__2 = abs(cd);
    tol = knstnt_1.reltol * max(d__1,d__2) + knstnt_1.abstol;
    if ((d__1 = cdhat - cd, abs(d__1)) >= tol) {
	goto L670;
    }
/* Computing MAX */
    d__2 = abs(cbhat), d__3 = (d__1 = cbs + cbd, abs(d__1));
    tol = knstnt_1.reltol * max(d__2,d__3) + knstnt_1.abstol;
    if ((d__1 = cbhat - (cbs + cbd), abs(d__1)) <= tol) {
	goto L680;
    }
L670:
    ++status_1.noncon;
L680:
    vbso[tabinf_1.lx0 + loct - 1] = vbs;
    vbdo[tabinf_1.lx0 + loct - 1] = vbd;
    vgso[tabinf_1.lx0 + loct - 1] = vgs;
    vdso[tabinf_1.lx0 + loct - 1] = vds;
    cdo[tabinf_1.lx0 + loct - 1] = cd;
    cbso[tabinf_1.lx0 + loct - 1] = cbs;
    cbdo[tabinf_1.lx0 + loct - 1] = cbd;
    gmo[tabinf_1.lx0 + loct - 1] = gm;
    gdso[tabinf_1.lx0 + loct - 1] = gds;
    gmbso[tabinf_1.lx0 + loct - 1] = gmbs;
    gbdo[tabinf_1.lx0 + loct - 1] = gbd;
    gbso[tabinf_1.lx0 + loct - 1] = gbs;
    if (mosarg_1.xqco <= .5) {
	goto L690;
    }
    vono[tabinf_1.lx0 + loct - 1] = mosarg_1.von;
    vdsato[tabinf_1.lx0 + loct - 1] = mosarg_1.vdsat;
    goto L700;
L690:
    cggbo[tabinf_1.lx0 + loct - 1] = cggb;
    cgdbo[tabinf_1.lx0 + loct - 1] = cgdb;
    cgsbo[tabinf_1.lx0 + loct - 1] = cgsb;
    cbgbo[tabinf_1.lx0 + loct - 1] = cbgb;
    cbdbo[tabinf_1.lx0 + loct - 1] = cbdb;
    cbsbo[tabinf_1.lx0 + loct - 1] = cbsb;
    goto L750;

/*     XQCO > 0.5D0 USE MEYER"S CAPACITOR MODEL */

L700:
    if (status_1.mode != 1) {
	goto L705;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L705;
    }
    if (status_1.initf == 4) {
	goto L705;
    }
    goto L742;

/*     CALCULATE MEYER'S CAPACITORS */

L705:
    von1 = mosarg_1.von;
    vgs1 = vgs;
    vgd1 = vgd;
    vgb1 = vgs - vbs;
    vdsat1 = mosarg_1.vdsat;
    if (status_1.mode != 2 || status_1.initf == 5) {
	goto L710;
    }
    von1 = vono[tabinf_1.lx1 + loct - 1];
    vgs1 = vgso[tabinf_1.lx1 + loct - 1];
    vgd1 = vgs1 - vdso[tabinf_1.lx1 + loct - 1];
    vgb1 = vgs1 - vbso[tabinf_1.lx1 + loct - 1];
    vdsat1 = vdsato[tabinf_1.lx1 + loct - 1];
L710:
    if (devmod < 0.) {
	goto L715;
    }
    cmeyer_(&vgs1, &vgd1, &vgb1, &von1, &vdsat1, &vgs, &vgd, &vgb, &covlgs, &
	    covlgd, &covlgb, &cgs1, &cgd1, &cgb1, &cgs, &cgd, &cgb);
    goto L720;
L715:
    cmeyer_(&vgd1, &vgs1, &vgb1, &von1, &vdsat1, &vgd, &vgs, &vgb, &covlgd, &
	    covlgs, &covlgb, &cgd1, &cgs1, &cgb1, &cgd, &cgs, &cgb);
L720:
    cgs = (cgs + cgs1) * .5;
    cgd = (cgd + cgd1) * .5;
    cgb = (cgb + cgb1) * .5;

/*     STORE SMALL-SIGNAL PARAMETERS (FOR MEYER"S MODEL) */

    if (status_1.mode != 1) {
	goto L730;
    }
    if (status_1.initf != 4) {
	goto L730;
    }
    blank_1.value[tabinf_1.lx0 + loct + 23] = capbd;
    blank_1.value[tabinf_1.lx0 + loct + 25] = capbs;
    blank_1.value[tabinf_1.lx0 + loct + 11] = cgs - covlgs;
    blank_1.value[tabinf_1.lx0 + loct + 13] = cgd - covlgd;
    blank_1.value[tabinf_1.lx0 + loct + 15] = cgb - covlgb;
    goto L1000;
/* C */
L730:
    if (status_1.initf != 6) {
	goto L735;
    }
    qgs[tabinf_1.lx0 + loct - 1] = (xfact + 1.) * qgs[tabinf_1.lx1 + loct - 1]
	     - xfact * qgs[tabinf_1.lx2 + loct - 1];
    qgd[tabinf_1.lx0 + loct - 1] = (xfact + 1.) * qgd[tabinf_1.lx1 + loct - 1]
	     - xfact * qgd[tabinf_1.lx2 + loct - 1];
    qgb[tabinf_1.lx0 + loct - 1] = (xfact + 1.) * qgb[tabinf_1.lx1 + loct - 1]
	     - xfact * qgb[tabinf_1.lx2 + loct - 1];
    goto L745;
L735:
    qgs[tabinf_1.lx0 + loct - 1] = (vgs - vgs1) * cgs;
    qgd[tabinf_1.lx0 + loct - 1] = (vgd - vgd1) * cgd;
    qgb[tabinf_1.lx0 + loct - 1] = (vgb - vgb1) * cgb;
    if (status_1.mode != 2 || status_1.initf == 5) {
	goto L740;
    }
    qgs[tabinf_1.lx0 + loct - 1] += qgs[tabinf_1.lx1 + loct - 1];
    qgd[tabinf_1.lx0 + loct - 1] += qgd[tabinf_1.lx1 + loct - 1];
    qgb[tabinf_1.lx0 + loct - 1] += qgb[tabinf_1.lx1 + loct - 1];
L740:
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L742;
    }
    if (status_1.initf != 5) {
	goto L745;
    }
    qgs[tabinf_1.lx0 + loct - 1] = cgs * vgs;
    qgd[tabinf_1.lx0 + loct - 1] = cgd * vgd;
    qgb[tabinf_1.lx0 + loct - 1] = cgb * vgb;
    qgs[tabinf_1.lx1 + loct - 1] = qgs[tabinf_1.lx0 + loct - 1];
    qgd[tabinf_1.lx1 + loct - 1] = qgd[tabinf_1.lx0 + loct - 1];
    qgb[tabinf_1.lx1 + loct - 1] = qgb[tabinf_1.lx0 + loct - 1];

/*     INITIALIZE TO ZERO CHARGE CONDUCTANCES AND CURRENT */

L742:
    gcgs = 0.;
    ceqgs = 0.;
    gcgd = 0.;
    ceqgd = 0.;
    gcgb = 0.;
    ceqgb = 0.;
    goto L870;
/* C */
L745:
    if (cgs == 0.) {
	blank_1.value[tabinf_1.lx0 + loct + 12] = 0.;
    }
    if (cgd == 0.) {
	blank_1.value[tabinf_1.lx0 + loct + 14] = 0.;
    }
    if (cgb == 0.) {
	blank_1.value[tabinf_1.lx0 + loct + 16] = 0.;
    }
/* C */
/* C    CALCULATE EQUIVALENT CONDUCTANCES AND CURRENTS FOR */
/* C    MEYER"S CAPACITORS */
/* C */
    i__1 = loct + 12;
    intgr8_(&gcgs, &ceqgs, &cgs, &i__1);
    i__1 = loct + 14;
    intgr8_(&gcgd, &ceqgd, &cgd, &i__1);
    i__1 = loct + 16;
    intgr8_(&gcgb, &ceqgb, &cgb, &i__1);
    ceqgs = ceqgs - gcgs * vgs + status_1.ag[0] * qgs[tabinf_1.lx0 + loct - 1]
	    ;
    ceqgd = ceqgd - gcgd * vgd + status_1.ag[0] * qgd[tabinf_1.lx0 + loct - 1]
	    ;
    ceqgb = ceqgb - gcgb * vgb + status_1.ag[0] * qgb[tabinf_1.lx0 + loct - 1]
	    ;
    if (status_1.initf != 5) {
	goto L870;
    }
    cqgs[tabinf_1.lx1 + loct - 1] = cqgs[tabinf_1.lx0 + loct - 1];
    cqgd[tabinf_1.lx1 + loct - 1] = cqgd[tabinf_1.lx0 + loct - 1];
    cqgb[tabinf_1.lx1 + loct - 1] = cqgb[tabinf_1.lx0 + loct - 1];
    goto L870;

/* .. BULK AND CHANNEL CHARGE (PLUS OVERLAPS) */

L750:
    if (status_1.mode != 1) {
	goto L755;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L755;
    }
    if (status_1.initf == 4) {
	goto L755;
    }
    goto L850;
L755:
    if (devmod == -1.) {
	goto L760;
    }
    moscap_(&vgd, &vgs, &vgb, &covlgd, &covlgs, &covlgb, &capbd, &capbs, &
	    cggb, &cgdb, &cgsb, &cbgb, &cbdb, &cbsb, &gcggb, &gcgdb, &gcgsb, &
	    gcbgb, &gcbdb, &gcbsb, &gcdgb, &gcddb, &gcdsb, &gcsgb, &gcsdb, &
	    gcssb, &qgate, &qchan, &qbulk, &qdrn, &qsrc);
    goto L780;
L760:
    moscap_(&vgs, &vgd, &vgb, &covlgs, &covlgd, &covlgb, &capbs, &capbd, &
	    cggb, &cgsb, &cgdb, &cbgb, &cbsb, &cbdb, &gcggb, &gcgsb, &gcgdb, &
	    gcbgb, &gcbsb, &gcbdb, &gcsgb, &gcssb, &gcsdb, &gcdgb, &gcdsb, &
	    gcddb, &qgate, &qchan, &qbulk, &qsrc, &qdrn);
L780:
    if (ibypas == 1) {
	goto L860;
    }
    qg[tabinf_1.lx0 + loct - 1] = qgate;
    qd[tabinf_1.lx0 + loct - 1] = qdrn - qbd[tabinf_1.lx0 + loct - 1];
    qb[tabinf_1.lx0 + loct - 1] = qbulk + qbd[tabinf_1.lx0 + loct - 1] + qbs[
	    tabinf_1.lx0 + loct - 1];

/*  STORE SMALL-SIGNAL PARAMETERS */

/* L790: */
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L850;
    }
    if (status_1.initf != 4) {
	goto L800;
    }
    blank_1.value[tabinf_1.lx0 + loct + 17] = cggb;
    blank_1.value[tabinf_1.lx0 + loct + 18] = cgdb;
    blank_1.value[tabinf_1.lx0 + loct + 19] = cgsb;
    blank_1.value[tabinf_1.lx0 + loct + 20] = cbgb;
    blank_1.value[tabinf_1.lx0 + loct + 21] = cbdb;
    blank_1.value[tabinf_1.lx0 + loct + 22] = cbsb;
    blank_1.value[tabinf_1.lx0 + loct + 23] = capbd;
    blank_1.value[tabinf_1.lx0 + loct + 25] = capbs;
    goto L1000;

/*  TRANSIENT ANALYSIS */

L800:
    if (status_1.initf != 5) {
	goto L810;
    }
    qb[tabinf_1.lx1 + loct - 1] = qb[tabinf_1.lx0 + loct - 1];
    qg[tabinf_1.lx1 + loct - 1] = qg[tabinf_1.lx0 + loct - 1];
    qd[tabinf_1.lx1 + loct - 1] = qd[tabinf_1.lx0 + loct - 1];
/* .. INTEGRATE QB */
L810:
    i__1 = loct + 12;
    intgr8_(&geq, &ceq, &c_b2663, &i__1);
/* .. INTEGRATE QG */
    i__1 = loct + 14;
    intgr8_(&geq, &ceq, &c_b2663, &i__1);
/* .. INTEGRATE QD */
    i__1 = loct + 16;
    intgr8_(&geq, &ceq, &c_b2663, &i__1);
    goto L860;

/*     INITIALIZE TO ZERO CHARGE CONDUCTANCES AND CURRENT */

L850:
    ceqqg = 0.;
    ceqqb = 0.;
    ceqqd = 0.;
    gcdgb = 0.;
    gcddb = 0.;
    gcdsb = 0.;
    gcsgb = 0.;
    gcsdb = 0.;
    gcssb = 0.;
    gcggb = 0.;
    gcgdb = 0.;
    gcgsb = 0.;
    gcbgb = 0.;
    gcbdb = 0.;
    gcbsb = 0.;
    goto L900;

/*     EVALUATE EQUIVALENT CHARGE CURRENTS */

L860:
    cgate = cqg[tabinf_1.lx0 + loct - 1];
    cqbulk = cqb[tabinf_1.lx0 + loct - 1];
    cqdrn = cqd[tabinf_1.lx0 + loct - 1];
    ceqqg = cgate - gcggb * vgb + gcgdb * vbd + gcgsb * vbs;
    ceqqb = cqbulk - gcbgb * vgb + gcbdb * vbd + gcbsb * vbs;
    ceqqd = cqdrn - gcdgb * vgb + gcddb * vbd + gcdsb * vbs;
    if (status_1.initf != 5) {
	goto L900;
    }
    cqb[tabinf_1.lx1 + loct - 1] = cqb[tabinf_1.lx0 + loct - 1];
    cqg[tabinf_1.lx1 + loct - 1] = cqg[tabinf_1.lx0 + loct - 1];
    cqd[tabinf_1.lx1 + loct - 1] = cqd[tabinf_1.lx0 + loct - 1];
    goto L900;

/* C   DO THE MAPPING FROM MEYER"S CAPACITOR MODEL INTO THE CHARGE */
/* C   ORIENTED MODEL */
/* C */
L870:
    ceqqg = ceqgs + ceqgb + ceqgd;
    ceqqb = -ceqgb;
    ceqqd = -ceqgd;
    gcbdb = 0.;
    gcbsb = 0.;
    gcdsb = 0.;
    gcsdb = 0.;
    gcgdb = -gcgd;
    gcgsb = -gcgs;
    gcbgb = -gcgb;
    gcdgb = -gcgd;
    gcsgb = -gcgs;
    gcssb = gcgs;
    gcddb = gcgd;
    gcggb = gcgd + gcgs + gcgb;

/*     STORE CHARGE STORAGE INFO FOR MEYER'S CAP IN LX TABLE */

    cgbo[tabinf_1.lx0 + loct - 1] = cgb;
    cgso[tabinf_1.lx0 + loct - 1] = cgs;
    cgdo[tabinf_1.lx0 + loct - 1] = cgd;

/*  LOAD CURRENT VECTOR */

L900:
    ceqbs = type__ * (cbs - (gbs - knstnt_1.gmin) * vbs);
    ceqbd = type__ * (cbd - (gbd - knstnt_1.gmin) * vbd);
    ceqqg = type__ * ceqqg;
    ceqqb = type__ * ceqqb;
    ceqqd = type__ * ceqqd;
    xnrm = 1.;
    xrev = 0.;
    if (devmod < 0.) {
	goto L910;
    }
    cdreq = type__ * (mosarg_1.cdrain - gds * vds - gm * vgs - gmbs * vbs);
    goto L920;
L910:
    xnrm = 0.;
    xrev = 1.;
    cdreq = -type__ * (mosarg_1.cdrain - gds * (-vds) - gm * vgd - gmbs * vbd)
	    ;
L920:
    blank_1.value[tabinf_1.lvn + node2 - 1] -= ceqqg;
    blank_1.value[tabinf_1.lvn + node4 - 1] = blank_1.value[tabinf_1.lvn + 
	    node4 - 1] - ceqbs - ceqbd - ceqqb;
    blank_1.value[tabinf_1.lvn + node5 - 1] = blank_1.value[tabinf_1.lvn + 
	    node5 - 1] - cdreq + ceqbd - ceqqd;
    blank_1.value[tabinf_1.lvn + node6 - 1] = blank_1.value[tabinf_1.lvn + 
	    node6 - 1] + cdreq + ceqbs + ceqqg + ceqqb + ceqqd;

/*  LOAD Y MATRIX */

    locy = tabinf_1.lvn + nodplc[loc + 26];
    blank_1.value[locy - 1] += gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 27];
    blank_1.value[locy - 1] += gcggb;
    locy = tabinf_1.lvn + nodplc[loc + 28];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lvn + nodplc[loc + 29];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gbd + gbs - gcbgb - 
	    gcbdb - gcbsb;
    locy = tabinf_1.lvn + nodplc[loc + 30];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gdpr + gds + gbd + 
	    xrev * (gm + gmbs) + gcddb;
    locy = tabinf_1.lvn + nodplc[loc + 31];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gspr + gds + gbs + 
	    xnrm * (gm + gmbs) + gcssb;
    locy = tabinf_1.lvn + nodplc[loc + 9];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 10];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gcggb - gcgdb - gcgsb;
    locy = tabinf_1.lvn + nodplc[loc + 11];
    blank_1.value[locy - 1] += gcgdb;
    locy = tabinf_1.lvn + nodplc[loc + 12];
    blank_1.value[locy - 1] += gcgsb;
    locy = tabinf_1.lvn + nodplc[loc + 13];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 14];
    blank_1.value[locy - 1] += gcbgb;
    locy = tabinf_1.lvn + nodplc[loc + 15];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbd + gcbdb;
    locy = tabinf_1.lvn + nodplc[loc + 16];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbs + gcbsb;
    locy = tabinf_1.lvn + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lvn + nodplc[loc + 18];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + (xnrm - xrev) * gm + 
	    gcdgb;
    locy = tabinf_1.lvn + nodplc[loc + 19];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbd + (xnrm - xrev) * 
	    gmbs - gcdgb - gcddb - gcdsb;
    locy = tabinf_1.lvn + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - xnrm * (gm + 
	    gmbs) + gcdsb;
    locy = tabinf_1.lvn + nodplc[loc + 21];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - (xnrm - xrev) * gm + 
	    gcsgb;
    locy = tabinf_1.lvn + nodplc[loc + 22];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lvn + nodplc[loc + 23];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbs - (xnrm - xrev) * 
	    gmbs - gcsgb - gcsdb - gcssb;
    locy = tabinf_1.lvn + nodplc[loc + 24];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - xrev * (gm + 
	    gmbs) + gcsdb;
L1000:
    loc = nodplc[loc - 1];
    goto L10;
} /* mosfet_ */

#undef vdsato
#undef cvalue
#undef nodplc
#undef gmbso
#undef cgsbo
#undef cbsbo
#undef cggbo
#undef cgdbo
#undef cbgbo
#undef cbdbo
#undef vono
#undef vdso
#undef vgso
#undef vbso
#undef cqgs
#undef cgso
#undef gbso
#undef gdso
#undef vbdo
#undef cqbs
#undef cbso
#undef cqgb
#undef cqgd
#undef cgdo
#undef gbdo
#undef cgbo
#undef cqbd
#undef cbdo
#undef qgs
#undef qbs
#undef gmo
#undef qgb
#undef qgd
#undef qbd
#undef cqg
#undef cqd
#undef cqb
#undef cdo
#undef qg
#undef qd
#undef qb


/* Subroutine */ int moseq1_(doublereal *vds, doublereal *vbs, doublereal *
	vgs, doublereal *gm, doublereal *gds, doublereal *gmbs)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal arg, vbd, vgb, sarg, vgst, betap;


/*     THIS ROUTINE EVALUATES THE DRAIN CURRENT AND ITS DERIVATIVES */
/*     USING THE SHICHMAN-HODGES MODEL AND THE CHARGES ASSOCIATED */
/*     WITH THE GATE, CHANNEL AND BULK FOR MOSFETS */

/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
    vbd = *vbs - *vds;
    vgb = *vgs - *vbs;


    if (*vbs > 0.) {
	goto L102;
    }
    sarg = sqrt(mosarg_1.phi - *vbs);
    goto L104;
L102:
    sarg = sqrt(mosarg_1.phi);
    sarg -= *vbs / (sarg + sarg);
    sarg = max(0.,sarg);
L104:
    mosarg_1.von = mosarg_1.vbi + mosarg_1.gamma * sarg;
    vgst = *vgs - mosarg_1.von;
    mosarg_1.vdsat = max(vgst,0.);
    if (sarg > 0.) {
	goto L105;
    }
    arg = 0.;
    goto L108;
L105:
    arg = mosarg_1.gamma / (sarg + sarg);
L108:
    if (vgst > 0.) {
	goto L110;
    }

/*     CUTOFF REGION */

    mosarg_1.cdrain = 0.;
    *gm = 0.;
    *gds = 0.;
    *gmbs = 0.;
    goto L1000;

/*     SATURATION REGION */

L110:
    betap = mosarg_1.beta * (mosarg_1.xlamda * *vds + 1.);
    if (vgst > *vds) {
	goto L120;
    }
    mosarg_1.cdrain = betap * vgst * vgst * .5;
    *gm = betap * vgst;
    *gds = mosarg_1.xlamda * mosarg_1.beta * vgst * vgst * .5;
    *gmbs = *gm * arg;
    goto L1000;

/*     LINEAR REGION */

L120:
    mosarg_1.cdrain = betap * *vds * (vgst - *vds * .5);
    *gm = betap * *vds;
    *gds = betap * (vgst - *vds) + mosarg_1.xlamda * mosarg_1.beta * *vds * (
	    vgst - *vds * .5);
    *gmbs = *gm * arg;

/*     FINISHED */

L1000:
    return 0;
} /* moseq1_ */

/* Subroutine */ int moseq2_(doublereal *vds, doublereal *vbs, doublereal *
	vgs, doublereal *gm, doublereal *gds, doublereal *gmbs, doublereal *
	qg, doublereal *qc, doublereal *qb, doublereal *cggb, doublereal *
	cgdb, doublereal *cgsb, doublereal *cbgb, doublereal *cbdb, 
	doublereal *cbsb)
{
    /* Initialized data */

    static doublereal sig1[4] = { 1.,-1.,1.,-1. };
    static doublereal sig2[4] = { 1.,1.,-1.,-1. };

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), log(doublereal), exp(doublereal), atan(
	    doublereal), cos(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j;
    static doublereal p, r__, s, a1, b1, c1, a4[4], b4[4], d1, a3, b3, p0, p2,
	     p3, p4, r3, s2, v1, v2, x4[8], y3, fi, ro, vl, xn, xv, eta, arg, 
	    cfs, gmw, xwb, vth, xwd, xdv, xls, xlv, xws, arg1, arg2, barg, 
	    argd, argg, ueff, sarg, vbin, args, body, sphi, argv;
    static integer iknt, jknt;
    static doublereal expg, vpof, vgst, vgsx, sarg3, argv1, sphi3, d2bdb2;
    extern /* Subroutine */ int mosq2_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal poly4[8], d2sdb2, dfact, gdbdv, bsarg, argsd, ufact, 
	    xleff, argxd, cdson, dbxwd, ddxwd, gdson, argsq, gbson, argss, 
	    tsarg, daddb2, bodys, argxs, sargv, dgddb2, dbxws, vdson, dasdb2, 
	    gammd2, delta4, vdsat1, dbargd, dbrgdb, gammad, dgddvb, gamasd;
    static integer icharg;
    static doublereal clfact, dbsrdb, dbargs, dfundb, dsrgdb, cdonco, dgsdvb, 
	    sbiarg, dgdvds, gamass, factor, dgdvbs, dodvbs, dxndvb, dxndvd, 
	    dodvds, udenom, dudvgs, dudvds, dudvbs, dsdvgs, dsdvbs, xvalid, 
	    gdbdvs, xlfact, dldsat, vqchan, dqdsat, dfunds, dfundg, dldvgs, 
	    dldvds, dldvbs, deltal, didvds;
    extern /* Subroutine */ int mqspof_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);


/*     THIS ROUTINE EVALUATES THE DRAIN CURRENT, ITS DERIVATIVES AND */
/*     THE CHARGES ASSOCIATED WITH THE GATE, CHANNEL AND BULK */
/*     FOR MOSFETS */

/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */


/*     ICHARG=1 CAUSES CHARGES TO BE COMPUTED */
/*     ICHARG=0 BYPASSES THE COMPUTATION OF CHARGES */

    icharg = 1;
    if (status_1.mode != 1 && mosarg_1.xqco <= .5) {
	goto L100;
    }
    icharg = 0;
    if (mosarg_1.xqco > .5) {
	goto L100;
    }
    if (status_1.modedc == 2 && status_1.nosolv != 0) {
	icharg = 1;
    }
    if (status_1.initf == 4) {
	icharg = 1;
    }

/*  COMPUTE SOME USEFUL QUANTITIES */

L100:
    if (*vbs > 0.) {
	goto L110;
    }
    sarg = sqrt(mosarg_1.phi - *vbs);
    tsarg = sarg + sarg;
    dsrgdb = -.5 / sarg;
    d2sdb2 = dsrgdb * .5 / (mosarg_1.phi - *vbs);
    goto L120;
L110:
    sphi = sqrt(mosarg_1.phi);
    sphi3 = mosarg_1.phi * sphi;
    sarg = sphi / (*vbs * .5 / mosarg_1.phi + 1.);
    tsarg = sarg + sarg;
    dsrgdb = sarg * -.5 * sarg / sphi3;
    d2sdb2 = -dsrgdb * sarg / sphi3;
L120:
    if (*vds - *vbs < 0.) {
	goto L130;
    }
    barg = sqrt(mosarg_1.phi + *vds - *vbs);
    dbrgdb = -.5 / barg;
    d2bdb2 = dbrgdb * .5 / (mosarg_1.phi + *vds - *vbs);
    goto L200;
L130:
    barg = sphi / ((*vbs - *vds) * .5 / mosarg_1.phi + 1.);
    dbrgdb = barg * -.5 * barg / sphi3;
    d2bdb2 = -dbrgdb * barg / sphi3;

/*  CALCULATE THRESHOLD VOLTAGE (VON) */
/*     NARROW-CHANNEL EFFECT */

L200:
    factor = mosarg_1.fnarrw * .125 * knstnt_1.twopi * knstnt_1.epssil / 
	    mosarg_1.cox * mosarg_1.xl;
    eta = factor + 1.;
    vbin = mosarg_1.vbi + factor * (mosarg_1.phi - *vbs);
    if (mosarg_1.gamma <= 0.) {
	goto L215;
    }
    if (mosarg_1.xnsub <= 0.) {
	goto L215;
    }
    xwd = mosarg_1.xd * barg;
    xws = mosarg_1.xd * sarg;

/*     SHORT-CHANNEL EFFECT WITH VDS .NE. 0.0D0 */

    argss = 0.;
    argsd = 0.;
    dbargs = 0.;
    dbargd = 0.;
    dgdvds = 0.;
    dgddb2 = 0.;
    if (mosarg_1.xj <= 0.) {
	goto L205;
    }
    argxs = xws * 2. / mosarg_1.xj + 1.;
    args = sqrt(argxs);
    argss = mosarg_1.xj * .5 / mosarg_1.xl * (args - 1.);
    argxd = xwd * 2. / mosarg_1.xj + 1.;
    argd = sqrt(argxd);
    argsd = mosarg_1.xj * .5 / mosarg_1.xl * (argd - 1.);
L205:
    gamasd = mosarg_1.gamma * (1. - argss - argsd);
    gamass = mosarg_1.gamma * (1. - argss * 2.);
    dbxwd = mosarg_1.xd * dbrgdb;
    dbxws = mosarg_1.xd * dsrgdb;
    if (mosarg_1.xj <= 0.) {
	goto L210;
    }
    dbargs = .5 / mosarg_1.xl * dbxws / args;
    dbargd = .5 / mosarg_1.xl * dbxwd / argd;
    dasdb2 = -mosarg_1.xd * (d2sdb2 + dsrgdb * dsrgdb * mosarg_1.xd / (
	    mosarg_1.xj * argxs)) / (mosarg_1.xl * args);
    daddb2 = -mosarg_1.xd * (d2bdb2 + dbrgdb * dbrgdb * mosarg_1.xd / (
	    mosarg_1.xj * argxd)) / (mosarg_1.xl * argd);
    dgddb2 = mosarg_1.gamma * -.5 * (dasdb2 + daddb2);
L210:
    dgddvb = -mosarg_1.gamma * (dbargs + dbargd);
    dgsdvb = mosarg_1.gamma * -2. * dbargs;
    if (mosarg_1.xj <= 0.) {
	goto L220;
    }
    ddxwd = -dbxwd;
    dgdvds = -mosarg_1.gamma * .5 / mosarg_1.xl * ddxwd / argd;
    goto L220;
L215:
    gamasd = mosarg_1.gamma;
    gamass = mosarg_1.gamma;
    gammad = mosarg_1.gamma;
    dgddvb = 0.;
    dgsdvb = 0.;
    dgdvds = 0.;
    dgddb2 = 0.;
L220:
    mosarg_1.von = vbin + gamasd * sarg;
/*     WRITE(IOFILE,221) VON,VBIN,VBI,GAMASD,ARGSS,ARGSD,XJ */
/* L221: */
    vth = mosarg_1.von;
    mosarg_1.vdsat = 0.;
/* L225: */
    if (mosarg_1.xnfs == 0. || mosarg_1.cox == 0.) {
	goto L230;
    }
    cfs = knstnt_1.charge * mosarg_1.xnfs;
    cdonco = -(gamasd * dsrgdb + dgddvb * sarg) + factor;
    xn = cfs / mosarg_1.cox * mosarg_1.xw * mosarg_1.xl + 1. + cdonco;
    mosarg_1.von += status_1.vt * xn;
/*     WRITE (IOFILE,226) VON,CDONCO,XN,CFS,XD */
/* L226: */
    argg = 1. / (status_1.vt * xn);
    vgst = *vgs - mosarg_1.von;
    goto L300;
L230:
    vgst = *vgs - mosarg_1.von;
    if (*vgs > mosarg_1.von) {
	goto L300;
    }

/*  CUTOFF REGION */

    *gds = 0.;
    goto L1050;

/*  COMPUTE SOME MORE USEFUL QUANTITIES */

L300:
    sarg3 = sarg * sarg * sarg;
    sbiarg = sqrt(mosarg_1.phib);
    gammad = gamasd;
    dgdvbs = dgddvb;
    body = barg * barg * barg - sarg3;
    gdbdv = gammad * 2. * (barg * barg * dbrgdb - sarg * sarg * dsrgdb);
    dodvbs = -factor + dgdvbs * sarg + gammad * dsrgdb;
    if (mosarg_1.xnfs == 0.) {
	goto L400;
    }
    if (mosarg_1.cox == 0.) {
	goto L410;
    }
    dxndvb = dgdvbs * 2. * dsrgdb + gammad * d2sdb2 + dgddb2 * sarg;
    dodvbs += status_1.vt * dxndvb;
    dxndvd = dgdvds * dsrgdb;
    dodvds = dgdvds * sarg + status_1.vt * dxndvd;

/*  EVALUATE EFFECTIVE MOBILITY AND ITS DERIVATIVES */

L400:
    if (mosarg_1.cox <= 0.) {
	goto L410;
    }
    udenom = vgst;
    if (udenom <= mosarg_1.vbp) {
	goto L410;
    }
    ufact = exp(mosarg_1.uexp * log(mosarg_1.vbp / udenom));
    ueff = mosarg_1.uo * ufact;
    dudvgs = -ufact * mosarg_1.uexp / udenom;
    dudvds = 0.;
    dudvbs = mosarg_1.uexp * ufact * dodvbs / vgst;
    goto L500;
L410:
    ufact = 1.;
    ueff = mosarg_1.uo;
    dudvgs = 0.;
    dudvds = 0.;
    dudvbs = 0.;

/*     EVALUATE SATURATION VOLTAGE AND ITS DERIVATIVES ACCORDING TO */
/*     GROVE-FROHMAN EQUATION */

L500:
    vgsx = *vgs;
    gammad = gamasd / eta;
    dgdvbs = dgddvb;
    if (mosarg_1.xnfs != 0. && mosarg_1.cox != 0.) {
	vgsx = max(*vgs,mosarg_1.von);
    }
/* L505: */
    if (gammad <= 0.) {
	goto L535;
    }
    gammd2 = gammad * gammad;
    argv = (vgsx - vbin) / eta + mosarg_1.phi - *vbs;
    if (argv <= 0.) {
	goto L540;
    }
    arg = sqrt(argv * 4. / gammd2 + 1.);
    mosarg_1.vdsat = (vgsx - vbin) / eta + gammd2 * (1. - arg) / 2.;
    mosarg_1.vdsat = max(mosarg_1.vdsat,0.);
/* L510: */
    if (icharg == 0) {
	goto L530;
    }
    arg1 = gammd2 / (eta * eta);
    arg2 = *vds - arg1 * .5;
    argsq = (arg2 + arg1 * .5 + mosarg_1.phi - *vbs) * arg1;
    if (argsq >= 0.) {
	goto L515;
    }
    vpof = vth;
    goto L520;
L515:
    vpof = vbin + eta * (arg2 + arg1 * .5 + sqrt(argsq));
L520:
    argv1 = (vpof - vbin) / eta + mosarg_1.phi - *vbs;
    if (argv1 > 0.) {
	goto L525;
    }
    vdsat1 = 0.;
    goto L530;
L525:
    arg1 = sqrt(argv1 * 4. / gammd2 + 1.);
    vdsat1 = (vpof - vbin) / eta + gammd2 * (1. - arg1) / 2.;
    vdsat1 = max(vdsat1,0.);
L530:
    dsdvgs = (1. - 1. / arg) / eta;
    dsdvbs = (gammad * (1. - arg) + argv * 2. / (gammad * arg)) / eta * 
	    dgdvbs + 1. / arg + factor * dsdvgs;
    goto L545;
L535:
/* Computing MAX */
    d__1 = (vgsx - vbin) / eta;
    mosarg_1.vdsat = max(d__1,0.);
/* Computing MAX */
    d__1 = eta * *vds + vbin;
    vpof = max(d__1,0.);
/* Computing MAX */
    d__1 = (vpof - vbin) / eta;
    vdsat1 = max(d__1,0.);
    dsdvgs = 1.;
    dsdvbs = 0.;
    goto L545;
L540:
    mosarg_1.vdsat = 0.;
    vpof = vth;
    vdsat1 = 0.;
    dsdvgs = 0.;
    dsdvbs = 0.;

/*     STORE VDSAT AS ABOVE IN VPOF (PINCH-OFF) */

L545:
    if (mosarg_1.vmax <= 0.) {
	goto L600;
    }

/*     EVALUATE SATURATION VOLTAGE AND ITS DERIVATIVES ACCORDING TO */
/*     BAUM'S THEORY OF SCATTERING VELOCITY SATURATION */

    gammd2 = gammad * gammad;
    v1 = (vgsx - vbin) / eta + mosarg_1.phi - *vbs;
    v2 = mosarg_1.phi - *vbs;
    xv = mosarg_1.vmax * mosarg_1.xl / ueff;
    a1 = gammad / .75;
    b1 = (v1 + xv) * -2.;
    c1 = gammad * -2. * xv;
    d1 = v1 * 2. * (v2 + xv) - v2 * v2 - gammad * 1.3333333333333333 * sarg3;
    a = -b1;
    b = a1 * c1 - d1 * 4.;
    c__ = -d1 * (a1 * a1 - b1 * 4.) - c1 * c1;
    r__ = -a * a / 3. + b;
    s = a * 2. * a * a / 27. - a * b / 3. + c__;
    r3 = r__ * r__ * r__;
    s2 = s * s;
    p = s2 / 4. + r3 / 27.;
    p0 = abs(p);
    p2 = sqrt(p0);
    if (p >= 0.) {
	goto L550;
    }
    ro = sqrt(s2 / 4. + p0);
    ro = log(ro) / 3.;
    ro = exp(ro);
    fi = atan(p2 * -2. / s);
    y3 = ro * 2. * cos(fi / 3.) - a / 3.;
    goto L560;
L550:
    p3 = exp(log((d__1 = -s / 2. + p2, abs(d__1))) / 3.);
    p4 = exp(log((d__1 = -s / 2. - p2, abs(d__1))) / 3.);
    y3 = p3 + p4 - a / 3.;
L560:
    iknt = 0;
    a3 = sqrt(a1 * a1 / 4. - b1 + y3);
    b3 = sqrt(y3 * y3 / 4. - d1);
    for (i__ = 1; i__ <= 4; ++i__) {
	a4[i__ - 1] = a1 / 2. + sig1[i__ - 1] * a3;
	b4[i__ - 1] = y3 / 2. + sig2[i__ - 1] * b3;
	delta4 = a4[i__ - 1] * a4[i__ - 1] / 4. - b4[i__ - 1];
	if (delta4 < 0.) {
	    goto L570;
	}
	++iknt;
	x4[iknt - 1] = -a4[i__ - 1] / 2. + sqrt(delta4);
	++iknt;
	x4[iknt - 1] = -a4[i__ - 1] / 2. - sqrt(delta4);
L570:
	;
    }
    jknt = 0;
    i__1 = iknt;
    for (j = 1; j <= i__1; ++j) {
	if (x4[j - 1] <= 0.) {
	    goto L580;
	}
	poly4[j - 1] = x4[j - 1] * x4[j - 1] * x4[j - 1] * x4[j - 1] + a1 * 
		x4[j - 1] * x4[j - 1] * x4[j - 1];
	poly4[j - 1] = poly4[j - 1] + b1 * x4[j - 1] * x4[j - 1] + c1 * x4[j 
		- 1] + d1;
	if ((d__1 = poly4[j - 1], abs(d__1)) > 1e-6) {
	    goto L580;
	}
	++jknt;
	if (jknt > 1) {
	    goto L575;
	}
	xvalid = x4[j - 1];
L575:
	if (x4[j - 1] > xvalid) {
	    goto L580;
	}
	xvalid = x4[j - 1];
L580:
	;
    }
    if (jknt > 0) {
	goto L590;
    }
    ++status_1.ivmflg;
    goto L600;
L590:
    mosarg_1.vdsat = xvalid * xvalid + *vbs - mosarg_1.phi;

/*  EVALUATE EFFECTIVE CHANNEL LENGTH AND ITS DERIVATIVES */

L600:
    if (*vds == 0.) {
	goto L610;
    }
    gammad = gamasd;
    if (*vbs - mosarg_1.vdsat > 0.) {
	goto L601;
    }
    bsarg = sqrt(mosarg_1.vdsat - *vbs + mosarg_1.phi);
    dbsrdb = -.5 / bsarg;
    goto L602;
L601:
    bsarg = sphi / ((*vbs - mosarg_1.vdsat) * .5 / mosarg_1.phi + 1.);
    dbsrdb = bsarg * -.5 * bsarg / sphi3;
L602:
    bodys = bsarg * bsarg * bsarg - sarg3;
    gdbdvs = gammad * 2. * (bsarg * bsarg * dbsrdb - sarg * sarg * dsrgdb);
    if (mosarg_1.vmax > 0.) {
	goto L603;
    }
    if (mosarg_1.xnsub == 0.) {
	goto L610;
    }
    if (mosarg_1.xlamda > 0.) {
	goto L610;
    }
    argv = (*vds - mosarg_1.vdsat) / 4.;
    sargv = sqrt(argv * argv + 1.);
    arg = sqrt(argv + sargv);
    xlfact = mosarg_1.xd / (mosarg_1.xl * *vds);
    mosarg_1.xlamda = xlfact * arg;
    dldsat = *vds * xlfact * arg / (sargv * 8.);
    goto L605;
L603:
    argv = (vgsx - vbin) / eta - mosarg_1.vdsat;
    xdv = mosarg_1.xd / sqrt(mosarg_1.xneff);
    xlv = mosarg_1.vmax * xdv / (ueff * 2.);
    vqchan = argv - gammad * bsarg;
    dqdsat = gammad * dbsrdb - 1.;
    vl = mosarg_1.vmax * mosarg_1.xl;
    dfunds = vl * dqdsat - ueff * vqchan;
    dfundg = (vl - ueff * mosarg_1.vdsat) / eta;
    dfundb = -vl * (dqdsat + 1. - factor / eta) + ueff * (gdbdvs - dgdvbs * 
	    bodys / 1.5) / eta;
    dsdvgs = -dfundg / dfunds;
    dsdvbs = -dfundb / dfunds;
    if (mosarg_1.xnsub == 0.) {
	goto L610;
    }
    if (mosarg_1.xlamda > 0.) {
	goto L610;
    }
/* Computing MAX */
    d__1 = *vds - mosarg_1.vdsat;
    argv = max(d__1,0.);
    xls = sqrt(xlv * xlv + argv);
    dldsat = xdv / (xls * 2.);
    xlfact = xdv / (mosarg_1.xl * *vds);
    mosarg_1.xlamda = xlfact * (xls - xlv);
    dldsat /= mosarg_1.xl;
L605:
    dldvgs = dldsat * dsdvgs;
    dldvds = -mosarg_1.xlamda + dldsat;
    dldvbs = dldsat * dsdvbs;
    goto L620;
L610:
    dldvgs = 0.;
    dldvds = 0.;
    dldvbs = 0.;

/*     LIMIT CHANNEL SHORTENING AT PUNCH-THROUGH */

L620:
    xwb = mosarg_1.xd * sbiarg;
    mosarg_1.xld = mosarg_1.xl - xwb;
    clfact = 1. - mosarg_1.xlamda * *vds;
    dldvds = -mosarg_1.xlamda - dldvds;
    xleff = mosarg_1.xl * clfact;
    deltal = mosarg_1.xlamda * *vds * mosarg_1.xl;
    if (mosarg_1.xnsub == 0.) {
	xwb = 2.5e-7;
    }
    if (xleff >= xwb) {
	goto L700;
    }
    xleff = xwb / ((deltal - mosarg_1.xld) / xwb + 1.);
    clfact = xleff / mosarg_1.xl;
    dfact = xleff * xleff / (xwb * xwb);
    dldvgs = dfact * dldvgs;
    dldvds = dfact * dldvds;
    dldvbs = dfact * dldvbs;

/*  EVALUATE EFFECTIVE BETA (EFFECTIVE KP) */

L700:
    mosarg_1.beta1 = mosarg_1.beta * ufact / clfact;

/*  TEST FOR MODE OF OPERATION AND BRANCH APPROPRIATELY */

    gammad = gamasd;
    dgdvbs = dgddvb;
    if (*vds > 1e-8) {
	goto L730;
    }
    if (*vgs > mosarg_1.von) {
	goto L720;
    }
    if (mosarg_1.xnfs != 0. && mosarg_1.cox != 0.) {
	goto L710;
    }
    *gds = 0.;
    goto L1050;

L710:
    *gds = mosarg_1.beta1 * (mosarg_1.von - vbin - gammad * sarg) * exp(argg *
	     (*vgs - mosarg_1.von));
    goto L1050;


L720:
    *gds = mosarg_1.beta1 * (*vgs - vbin - gammad * sarg);
    goto L1050;

L730:
    if (*vgs > mosarg_1.von) {
	goto L900;
    }

/*  SUBTHRESHOLD REGION */

    if (mosarg_1.vdsat > 0.) {
	goto L830;
    }
    *gds = 0.;
    if (*vgs > vth) {
	goto L1020;
    }
    goto L1050;
L830:
    vdson = min(mosarg_1.vdsat,*vds);
    if (*vds <= mosarg_1.vdsat) {
	goto L850;
    }
    barg = bsarg;
    dbrgdb = dbsrdb;
    body = bodys;
    gdbdv = gdbdvs;
L850:
    cdson = mosarg_1.beta1 * ((mosarg_1.von - vbin - eta * vdson * .5) * 
	    vdson - gammad * body / 1.5);
    didvds = mosarg_1.beta1 * (mosarg_1.von - vbin - eta * vdson - gammad * 
	    barg);
    gdson = -cdson * dldvds / clfact - mosarg_1.beta1 * dgdvds * body / 1.5;
    if (*vds < mosarg_1.vdsat) {
	gdson += didvds;
    }
    gbson = -cdson * dldvbs / clfact + mosarg_1.beta1 * (dodvbs * vdson + 
	    factor * vdson - dgdvbs * body / 1.5 - gdbdv);
    if (*vds > mosarg_1.vdsat) {
	gbson += didvds * dsdvbs;
    }
    expg = exp(argg * (*vgs - mosarg_1.von));
    mosarg_1.cdrain = cdson * expg;
    gmw = mosarg_1.cdrain * argg;
    *gm = gmw;
    if (*vds > mosarg_1.vdsat) {
	*gm = gmw + didvds * dsdvgs * expg;
    }
    *gds = gdson * expg - *gm * dodvds - gmw * (*vgs - mosarg_1.von) * dxndvd 
	    / xn;
    *gmbs = gbson * expg - *gm * dodvbs - gmw * (*vgs - mosarg_1.von) * 
	    dxndvb / xn;
    goto L1020;


L900:
    if (*vds > mosarg_1.vdsat) {
	goto L1000;
    }

/*  LINEAR REGION */

    mosarg_1.cdrain = mosarg_1.beta1 * ((*vgs - vbin - eta * *vds / 2.) * *
	    vds - gammad * body / 1.5);
    arg = mosarg_1.cdrain * (dudvgs / ufact - dldvgs / clfact);
    *gm = arg + mosarg_1.beta1 * *vds;
    arg = mosarg_1.cdrain * (dudvds / ufact - dldvds / clfact);
    *gds = arg + mosarg_1.beta1 * (*vgs - vbin - eta * *vds - gammad * barg - 
	    dgdvds * body / 1.5);
    arg = mosarg_1.cdrain * (dudvbs / ufact - dldvbs / clfact);
    *gmbs = arg - mosarg_1.beta1 * (gdbdv + dgdvbs * body / 1.5 - factor * *
	    vds);
    goto L1020;

/*  SATURATION REGION */

L1000:
    mosarg_1.cdrain = mosarg_1.beta1 * ((*vgs - vbin - eta * mosarg_1.vdsat / 
	    2.) * mosarg_1.vdsat - gammad * bodys / 1.5);
    arg = mosarg_1.cdrain * (dudvgs / ufact - dldvgs / clfact);
    *gm = arg + mosarg_1.beta1 * mosarg_1.vdsat + mosarg_1.beta1 * (*vgs - 
	    vbin - eta * mosarg_1.vdsat - gammad * bsarg) * dsdvgs;
    *gds = -mosarg_1.cdrain * dldvds / clfact - mosarg_1.beta1 * dgdvds * 
	    bodys / 1.5;
    arg = mosarg_1.cdrain * (dudvbs / ufact - dldvbs / clfact);
    *gmbs = arg - mosarg_1.beta1 * (gdbdvs + dgdvbs * bodys / 1.5 - factor * 
	    mosarg_1.vdsat) + mosarg_1.beta1 * (*vgs - vbin - eta * 
	    mosarg_1.vdsat - gammad * bsarg) * dsdvbs;

/*     COMPUTE CHARGES FOR "ON" REGION */

L1020:
    if (icharg == 0) {
	goto L1500;
    }
    if (*vgs <= vth) {
	goto L1070;
    }
    mqspof_(vds, vbs, vgs, &vpof, &vdsat1, &vth, &vbin, &gamasd, qg, qc, qb, 
	    cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
    goto L2000;

/*  FINISH SPECIAL CASES */

L1050:
    mosarg_1.cdrain = 0.;
    *gm = 0.;
    *gmbs = 0.;
L1070:
    mosarg_1.xqc = mosarg_1.xqco;
    if (icharg == 0) {
	goto L1500;
    }
    mosq2_(vds, vbs, vgs, &mosarg_1.vdsat, &vth, &vbin, &gamasd, &
	    mosarg_1.cox, &mosarg_1.phi, qg, qc, qb, cggb, cgdb, cgsb, cbgb, 
	    cbdb, cbsb);
    mosarg_1.qspof = 0.;
    goto L2000;

/*  FINISHED */

L1500:
    *qg = 0.;
    *qb = 0.;
    *qc = 0.;
    mosarg_1.qspof = 0.;
L2000:
    return 0;
} /* moseq2_ */

/* Subroutine */ int moseq3_(doublereal *vds, doublereal *vbs, doublereal *
	vgs, doublereal *gm, doublereal *gds, doublereal *gmbs, doublereal *
	qg, doublereal *qc, doublereal *qb, doublereal *cggb, doublereal *
	cgdb, doublereal *cgsb, doublereal *cbgb, doublereal *cbdb, 
	doublereal *cbsb)
{
    /* Initialized data */

    static doublereal coeff0 = .0631353;
    static doublereal coeff1 = .8013292;
    static doublereal coeff2 = -.01110777;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal xn, us, cd1, fd2, cdo;
#define eta ((doublereal *)&mosarg_1 + 13)
    static doublereal vgb, vfb, wcs, gms, vth, gmw, wps, gds0, wcs2, arga, 
	    argc, argb, onfg, emax, vdsc, vbin, vbix, vpof, onxj, onxl, onxn, 
	    vdsx, vgsx;
    extern /* Subroutine */ int mosq3_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal dadvb, dbdvb, diddl;
#define alpha ((doublereal *)&mosarg_1 + 11)
    static doublereal fgate, dgdvb, dgdvg, dgdvd, dldvd, cdsat, dldem, gdsat, 
	    fbody, wfact;
#define theta ((doublereal *)&mosarg_1 + 14)
    static doublereal phibs, delxl, ondvt, vdsat1, sqphs3, dfbdvb, dfddvb, 
	    dfgdvb;
    static integer icharg;
    static doublereal dfgdvd, dfddvg, dfgdvg, dqbdvb, dcodvd, gammas, dfsdvb, 
	    cdonco, dvsdga, dcodvg, dcodvb, fdrain, dfddvd, dsqdvb;
#define xkappa ((doublereal *)&mosarg_1 + 15)
    static doublereal dwpdvb, fbodys, onfbdy, djonxj, qbonco, sqphbs, dvtdvd, 
	    sqphis, wconxj, dvtdvb, csonco, dxndvb, dvodvd, dvodvb, dvsdvg, 
	    xjonxl, dvsdvd, dvsdvb, wponxj, onvdsc, cdnorm, gdoncd, gdonfd, 
	    gdonfg, emoncd, emongd, demdvg, demdvd, demdvb, ddldvg, ddldvd, 
	    ddldvb, dlonxl, xlfact;
    extern /* Subroutine */ int mqspof_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal gamasd;


/*     THIS ROUTINE EVALUATES THE DRAIN CURRENT, ITS DERIVATIVES AND */
/*     THE CHARGES ASSOCIATED WITH THE GATE, CHANNEL AND BULK */
/*     FOR MOSFETS BASED ON SEMI-EMPIRICAL EQUATIONS */

/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */


/*     ICHARG=1 CAUSES CHARGES TO BE COMPUTED */
/*     ICHARG=0 BYPASSES THE COMPUTATION OF CHARGES */

/*     ICHARG=1 */
/*     IF (MODE.NE.1) GO TO 10 */
/*     ICHARG=0 */
/*     IF (MODEDC.EQ.2.AND.NOSOLV.NE.0) ICHARG=1 */
/*     IF (INITF.EQ.4) ICHARG=1 */

/*     REFERENCE CDRAIN EQUATIONS TO SOURCE AND */
/*     CHARGE EQUATIONS TO BULK */

/* L10: */
    icharg = 0;
    vgb = *vgs - *vbs;
    vfb = mosarg_1.vbi - mosarg_1.phi;
    mosarg_1.vdsat = 0.;
    *qg = 0.;
    *qb = 0.;
    *qc = 0.;
    *cgdb = 0.;
    *cbdb = 0.;
    onxl = 1. / mosarg_1.xl;
    *eta /= mosarg_1.xl * mosarg_1.xl * mosarg_1.xl;

/* .....SQUARE ROOT TERM */

    if (*vbs > 0.) {
	goto L120;
    }
    phibs = mosarg_1.phi - *vbs;
    sqphbs = sqrt(phibs);
    dsqdvb = -.5 / sqphbs;
    goto L200;
L120:
    sqphis = sqrt(mosarg_1.phi);
    sqphs3 = mosarg_1.phi * sqphis;
    sqphbs = sqphis / (*vbs / (mosarg_1.phi + mosarg_1.phi) + 1.);
    phibs = sqphbs * sqphbs;
    dsqdvb = -phibs / (sqphs3 + sqphs3);

/* .....SHORT CHANNEL EFFECT FACTOR */

L200:
    if (mosarg_1.xj == 0. || mosarg_1.xd == 0.) {
	goto L210;
    }
    wps = mosarg_1.xd * sqphbs;
    onxj = 1. / mosarg_1.xj;
    xjonxl = mosarg_1.xj * onxl;
    djonxj = mosarg_1.xld * onxj;
    wponxj = wps * onxj;
    wconxj = coeff0 + coeff1 * wponxj + coeff2 * wponxj * wponxj;
    wcs = wconxj * mosarg_1.xj;
    arga = wconxj + djonxj;
    argc = wponxj / (wponxj + 1.);
    argb = sqrt(1. - argc * argc);
    mosarg_1.fshort = 1. - xjonxl * (arga * argb - djonxj);
    dwpdvb = mosarg_1.xd * dsqdvb;
    dadvb = (coeff1 + coeff2 * (wponxj + wponxj)) * dwpdvb * onxj;
    dbdvb = -argc * argc * (1. - argc) * dwpdvb / (argb * wps);
    dfsdvb = -xjonxl * (dadvb * argb + arga * dbdvb);
    goto L220;
L210:
    mosarg_1.fshort = 1.;
    dfsdvb = 0.;
    wcs = 5e-8;

/* .....BODY EFFECT */

L220:
    gammas = mosarg_1.gamma * mosarg_1.fshort;
    fbodys = gammas * .5 / (sqphbs + sqphbs);
    fbody = fbodys + mosarg_1.fnarrw;
    onfbdy = 1. / (fbody + 1.);
    dfbdvb = -fbodys * dsqdvb / sqphbs + fbodys * dfsdvb / mosarg_1.fshort;
    qbonco = gammas * sqphbs + mosarg_1.fnarrw * phibs;
    dqbdvb = gammas * dsqdvb + mosarg_1.gamma * dfsdvb * sqphbs - 
	    mosarg_1.fnarrw;

/* .....STATIC FEEDBACK EFFECT */

    vbix = mosarg_1.vbi - *eta * *vds;

/* .....THRESHOLD VOLTAGE */

    vth = vbix + qbonco;
    dvtdvd = -(*eta);
    dvtdvb = dqbdvb;

/* .....JOINT WEAK INVERSION AND STRONG INVERSION */

    mosarg_1.von = vth;
    if (mosarg_1.xnfs == 0.) {
	goto L250;
    }
    csonco = knstnt_1.charge * mosarg_1.xnfs * mosarg_1.xl * mosarg_1.xw / 
	    mosarg_1.cox;
    cdonco = qbonco / (phibs + phibs);
    xn = csonco + 1. + cdonco;
    mosarg_1.von = vth + status_1.vt * xn;
    dxndvb = dqbdvb / (phibs + phibs) - qbonco * dsqdvb / (phibs * sqphbs);
    dvodvd = dvtdvd;
    dvodvb = dvtdvb + status_1.vt * dxndvb;
    goto L300;

/* .....CUTOFF REGION */

L250:
    if (*vgs > mosarg_1.von) {
	goto L300;
    }
    mosarg_1.cdrain = 0.;
    *gm = 0.;
    *gds = 0.;
    *gmbs = 0.;
    if (icharg != 0) {
	goto L800;
    }
    goto L1000;

/* .....DEVICE IS ON */

L300:
    vgsx = max(*vgs,mosarg_1.von);

/* .....MOBILITY MODULATION BY GATE VOLTAGE */

    onfg = *theta * (vgsx - vth) + 1.;
    fgate = 1. / onfg;
    us = mosarg_1.uo * fgate;
    dfgdvg = -(*theta) * fgate * fgate;
    dfgdvd = -dfgdvg * dvtdvd;
    dfgdvb = -dfgdvg * dvtdvb;

/* .....SATURATION VOLTAGE */

    mosarg_1.vdsat = (vgsx - vth) * onfbdy;
    vpof = mosarg_1.vdsat;
    if (mosarg_1.vmax > 0.) {
	goto L310;
    }
    dvsdvg = onfbdy;
    dvsdvd = -dvsdvg * dvtdvd;
    dvsdvb = -dvsdvg * dvtdvb - mosarg_1.vdsat * dfbdvb * onfbdy;
    goto L400;
L310:
    vdsc = mosarg_1.xl * mosarg_1.vmax / us;
    onvdsc = 1. / vdsc;
    arga = (vgsx - vth) * onfbdy;
    argb = sqrt(arga * arga + vdsc * vdsc);
    mosarg_1.vdsat = arga + vdsc - argb;
    dvsdga = (1. - arga / argb) * onfbdy;
    dvsdvg = dvsdga - (1. - vdsc / argb) * vdsc * dfgdvg * onfg;
    dvsdvd = -dvsdvg * dvtdvd;
    dvsdvb = -dvsdvg * dvtdvb - arga * dvsdga * dfbdvb;

/* .....CURRENT FACTORS IN LINEAR REGION */

L400:
    vdsx = min(*vds,mosarg_1.vdsat);
    if (vdsx == 0.) {
	goto L900;
    }
    cdo = vgsx - vth - (fbody + 1.) * .5 * vdsx;
    dcodvg = 1.;
    if (*vds < mosarg_1.vdsat) {
	dcodvd = -dvtdvd - (fbody + 1.) * .5;
    }
    dcodvb = -dvtdvb - dfbdvb * .5 * vdsx;

/* .....NORMALIZED DRAIN CURRENT */

/* L410: */
    cdnorm = cdo * vdsx;
    *gm = vdsx;
    *gds = vgsx - vth - (fbody + 1. + dvtdvd) * vdsx;
    *gmbs = dcodvb * vdsx;

/* .....DRAIN CURRENT WITHOUT VELOCITY SATURATION EFFECT */

    cd1 = mosarg_1.beta * cdnorm;
    mosarg_1.beta *= fgate;
    mosarg_1.cdrain = mosarg_1.beta * cdnorm;
    *gm = mosarg_1.beta * *gm + dfgdvg * cd1;
    *gds = mosarg_1.beta * *gds + dfgdvd * cd1;
    *gmbs = mosarg_1.beta * *gmbs;

/* .....VELOCITY SATURATION FACTOR */

    if (mosarg_1.vmax == 0.) {
	goto L500;
    }
    fdrain = 1. / (vdsx * onvdsc + 1.);
    fd2 = fdrain * fdrain;
    arga = fd2 * vdsx * onvdsc * onfg;
    dfddvg = -dfgdvg * arga;
    dfddvd = -dfgdvd * arga - fd2 * onvdsc;
    dfddvb = -dfgdvb * arga;

/* .....DRAIN CURRENT */

    *gm = fdrain * *gm + dfddvg * mosarg_1.cdrain;
    *gds = fdrain * *gds + dfddvd * mosarg_1.cdrain;
    *gmbs = fdrain * *gmbs + dfddvb * mosarg_1.cdrain;
    mosarg_1.cdrain = fdrain * mosarg_1.cdrain;
    mosarg_1.beta *= fdrain;

/* .....CHANNEL LENGTH MODULATION */

L500:
    if (*vds <= mosarg_1.vdsat) {
	goto L700;
    }
    if (mosarg_1.vmax == 0.) {
	goto L510;
    }
    if (*alpha == 0.) {
	goto L700;
    }
    cdsat = mosarg_1.cdrain;
    gdsat = cdsat * (1. - fdrain) * onvdsc;
    gdsat = max(1e-12,gdsat);
    gdoncd = gdsat / cdsat;
    gdonfd = gdsat / (1. - fdrain);
    gdonfg = gdsat * onfg;
    dgdvg = gdoncd * *gm - gdonfd * dfddvg + gdonfg * dfgdvg;
    dgdvd = gdoncd * *gds - gdonfd * dfddvd + gdonfg * dfgdvd;
    dgdvb = gdoncd * *gmbs - gdonfd * dfddvb + gdonfg * dfgdvb;

    emax = cdsat * onxl / gdsat;
    emoncd = emax / cdsat;
    emongd = emax / gdsat;
    demdvg = emoncd * *gm - emongd * dgdvg;
    demdvd = emoncd * *gds - emongd * dgdvd;
    demdvb = emoncd * *gmbs - emongd * dgdvb;

    arga = emax * .5 * *alpha;
    argc = *xkappa * *alpha;
    argb = sqrt(arga * arga + argc * (*vds - mosarg_1.vdsat));
    delxl = argb - arga;
    dldvd = argc / (argb + argb);
    dldem = (arga / argb - 1.) * .5 * *alpha;
    ddldvg = dldem * demdvg;
    ddldvd = dldem * demdvd - dldvd;
    ddldvb = dldem * demdvb;
    goto L520;
L510:
    delxl = sqrt(*xkappa * (*vds - mosarg_1.vdsat) * *alpha);
    dldvd = delxl * .5 / (*vds - mosarg_1.vdsat);
    ddldvg = 0.;
    ddldvd = -dldvd;
    ddldvb = 0.;

/* .....PUNCH THROUGH APPROXIMATION */

L520:
    if (delxl <= mosarg_1.xl * .5) {
	goto L600;
    }
    wcs2 = wcs * wcs;
/* Computing 2nd power */
    d__1 = mosarg_1.xl;
    delxl = mosarg_1.xl - d__1 * d__1 / (delxl * 4.);
/* Computing 2nd power */
    d__1 = mosarg_1.xl - delxl;
/* Computing 2nd power */
    d__2 = mosarg_1.xl;
    arga = d__1 * d__1 * 4. / (d__2 * d__2);
    ddldvg *= arga;
    ddldvd *= arga;
    ddldvb *= arga;
    dldvd *= arga;

/* .....SATURATION REGION */

L600:
    dlonxl = delxl * onxl;
    xlfact = 1. / (1. - dlonxl);
    mosarg_1.cdrain *= xlfact;
    diddl = mosarg_1.cdrain / (mosarg_1.xl - delxl);
    *gm = *gm * xlfact + diddl * ddldvg;
    gds0 = *gds * xlfact + diddl * ddldvd;
    *gmbs = *gmbs * xlfact + diddl * ddldvb;
    *gm += gds0 * dvsdvg;
    *gmbs += gds0 * dvsdvb;
    *gds = gds0 * dvsdvd + diddl * dldvd;

/* .....FINISH STRONG INVERSION CASE */

L700:
    if (*vgs >= mosarg_1.von) {
	goto L750;
    }

/* .....WEAK INVERSION */

    onxn = 1. / xn;
    ondvt = onxn / status_1.vt;
    wfact = exp((*vgs - mosarg_1.von) * ondvt);
    mosarg_1.cdrain *= wfact;
    gms = *gm * wfact;
    gmw = mosarg_1.cdrain * ondvt;
    *gm = gmw;
    if (*vds > mosarg_1.vdsat) {
	*gm += gds0 * dvsdvg * wfact;
    }
    *gds = *gds * wfact + (gms - gmw) * dvodvd;
    *gmbs = *gmbs * wfact + (gms - gmw) * dvodvb - gmw * (*vgs - mosarg_1.von)
	     * onxn * dxndvb;

/* .....CHARGE COMPUTATION */

L750:
    if (icharg == 0) {
	goto L1000;
    }
    if (*vgs <= vth) {
	goto L800;
    }
    mqspof_(vds, vbs, vgs, &vpof, &vdsat1, &vth, &vbin, &gamasd, qg, qc, qb, 
	    cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
    goto L2000;

/* .....CHARGE COMPUTATION FOR VGS<VTH */

L800:
    mosarg_1.xqc = mosarg_1.xqco;
    mosq3_(vds, vbs, &vpof, &vdsat1, &vth, &vbin, &gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, qg, qc, qb, cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
    mosarg_1.qspof = 0.;
    goto L2000;

/* .....SPECIAL CASE OF VDS=0.0D0 */

L900:
    mosarg_1.beta *= fgate;
    mosarg_1.cdrain = 0.;
    *gm = 0.;
    *gds = mosarg_1.beta * (vgsx - vth);
    *gmbs = 0.;
    if (mosarg_1.xnfs != 0. && *vgs < mosarg_1.von) {
	*gds *= exp((*vgs - mosarg_1.von) / (status_1.vt * xn));
    }
    if (icharg == 0) {
	goto L1000;
    }
    mosq3_(vds, vbs, &vpof, &vdsat1, &vth, &vbin, &gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, qg, qc, qb, cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
L1000:
    mosarg_1.qspof = 0.;

/* .....DONE */

L2000:
    return 0;
} /* moseq3_ */

#undef xkappa
#undef theta
#undef alpha
#undef eta


/* Subroutine */ int moscap_(doublereal *vgd, doublereal *vgs, doublereal *
	vgb, doublereal *covlgd, doublereal *covlgs, doublereal *covlgb, 
	doublereal *capbd, doublereal *capbs, doublereal *cggb, doublereal *
	cgdb, doublereal *cgsb, doublereal *cbgb, doublereal *cbdb, 
	doublereal *cbsb, doublereal *gcggb, doublereal *gcgdb, doublereal *
	gcgsb, doublereal *gcbgb, doublereal *gcbdb, doublereal *gcbsb, 
	doublereal *gcdgb, doublereal *gcddb, doublereal *gcdsb, doublereal *
	gcsgb, doublereal *gcsdb, doublereal *gcssb, doublereal *qgate, 
	doublereal *qchan, doublereal *qbulk, doublereal *qdrn, doublereal *
	qsrc)
{
    /* Local variables */
    static doublereal gcd, gcg, qgb, qgd, gcs, qgs, gcgxd, gcdxd, gcdxs, 
	    gcsxd, gcgxs, gcsxs;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*     COMPUTE EQUIVALENT CONDUCTANCES */
/*     DIVIDE UP THE CHANNEL CHARGE (1-XQC)/XQC TO SOURCE AND DRAIN */

    gcg = (*cggb + *cbgb) * status_1.ag[0];
    gcd = (*cgdb + *cbdb) * status_1.ag[0];
    gcs = (*cgsb + *cbsb) * status_1.ag[0];
    gcgxd = -mosarg_1.xqc * gcg;
    gcgxs = -(1. - mosarg_1.xqc) * gcg;
    gcdxd = -mosarg_1.xqc * gcd;
    gcdxs = -(1. - mosarg_1.xqc) * gcd;
    gcsxd = -mosarg_1.xqc * gcs;
    gcsxs = -(1. - mosarg_1.xqc) * gcs;
    *gcdgb = gcgxd - *covlgd * status_1.ag[0];
    *gcddb = gcdxd + (*capbd + *covlgd) * status_1.ag[0];
    *gcdsb = gcsxd;
    *gcsgb = gcgxs - *covlgs * status_1.ag[0];
    *gcsdb = gcdxs;
    *gcssb = gcsxs + (*capbs + *covlgs) * status_1.ag[0];
    *gcggb = (*cggb + *covlgd + *covlgs + *covlgb) * status_1.ag[0];
    *gcgdb = (*cgdb - *covlgd) * status_1.ag[0];
    *gcgsb = (*cgsb - *covlgs) * status_1.ag[0];
    *gcbgb = (*cbgb - *covlgb) * status_1.ag[0];
    *gcbdb = (*cbdb - *capbd) * status_1.ag[0];
    *gcbsb = (*cbsb - *capbs) * status_1.ag[0];

/*     COMPUTE TOTAL TERMINAL CHARGES */

    qgd = *covlgd * *vgd;
    qgs = *covlgs * *vgs;
    qgb = *covlgb * *vgb;
    *qgate = *qgate + qgd + qgs + qgb;
    *qbulk -= qgb;
    *qdrn = mosarg_1.xqc * *qchan - qgd;
    *qsrc = (1. - mosarg_1.xqc) * *qchan - qgs;

/*     FINISHED */

    return 0;
} /* moscap_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int cmeyer_(doublereal *vgs0, doublereal *vgd0, doublereal *
	vgb0, doublereal *von0, doublereal *vdsat0, doublereal *vgs1, 
	doublereal *vgd1, doublereal *vgb1, doublereal *covlgs, doublereal *
	covlgd, doublereal *covlgb, doublereal *cgs0, doublereal *cgd0, 
	doublereal *cgb0, doublereal *cgs1, doublereal *cgd1, doublereal *
	cgb1)
{
    static doublereal cgb, cgd, vdb, cgs, vgb, vgd, vbs, vds, vgs, vgbt, vons,
	     vddif;
    static integer indax;
    static doublereal vddif1, vddif2, vdbsat;


/*     THIS ROUTINE COMPUTES THE MOSFET OVERLAP CAPACITANCES AS FUNCTIONS */
/* OF THE DEVICE TERMINAL VOLTAGES. */

/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
    indax = 1;
    vgs = *vgs1;
    vgd = *vgd1;
    vgb = *vgb1;
    vons = mosarg_1.von;
    vbs = vgs - vgb;
    vdbsat = mosarg_1.vdsat - vbs;
    vdb = vgb - vgd;
L10:
    vds = vgs - vgd;
    vgbt = vgs - vons;
    if (vgbt > -mosarg_1.phi) {
	goto L100;
    }
    cgb = mosarg_1.cox + *covlgb;
    cgd = *covlgd;
    cgs = *covlgs;
    goto L430;


L100:
    if (vgbt > -mosarg_1.phi / 2.) {
	goto L200;
    }
    cgb = -vgbt * mosarg_1.cox / mosarg_1.phi + *covlgb;
    cgd = *covlgd;
    cgs = *covlgs;
    goto L430;


L200:
    if (vgbt > 0.) {
	goto L300;
    }
    cgb = -vgbt * mosarg_1.cox / mosarg_1.phi + *covlgb;
    cgd = *covlgd;
    cgs = mosarg_1.cox / (mosarg_1.phi * .75) * vgbt + mosarg_1.cox / 1.5 + *
	    covlgs;
    goto L430;


L300:
    if (vdbsat > vdb) {
	goto L400;
    }
    cgb = *covlgb;
    cgd = *covlgd;
    cgs = mosarg_1.cox / 1.5 + *covlgs;
    goto L430;


L400:
    vddif = vdbsat * 2. - vdb;
    vddif1 = vdbsat - vdb - 1e-12;
    vddif2 = vddif * vddif;
    cgd = mosarg_1.cox * (1. - vdbsat * vdbsat / vddif2) / 1.5 + *covlgd;
    cgs = mosarg_1.cox * (1. - vddif1 * vddif1 / vddif2) / 1.5 + *covlgs;
    cgb = *covlgb;


L430:
    switch (indax) {
	case 1:  goto L440;
	case 2:  goto L560;
    }
L440:
    indax = 2;
    *cgs1 = cgs;
    *cgd1 = cgd;
    *cgb1 = cgb;
    vgs = *vgs0;
    vgd = *vgd0;
    vgb = *vgb0;
    vons = *von0;
    vbs = vgs - vgb;
    vdbsat = *vdsat0 - vbs;
    vdb = vgb - vgd;
    goto L10;


L560:
    *cgs0 = cgs;
    *cgd0 = cgd;
    *cgb0 = cgb;

/*  FINISHED */

/* L1000: */
    return 0;
} /* cmeyer_ */

/* Subroutine */ int mosq2_(doublereal *vds, doublereal *vbs, doublereal *vgs,
	 doublereal *vdsat, doublereal *vth, doublereal *vbin, doublereal *
	gamasd, doublereal *cox, doublereal *phi, doublereal *qg, doublereal *
	qc, doublereal *qb, doublereal *cggb, doublereal *cgdb, doublereal *
	cgsb, doublereal *cbgb, doublereal *cbdb, doublereal *cbsb)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal vd, ve, vg, vs, ve2, ve3, ve5, vs2, vs3, vs5, vbd, vgb, 
	    vep5, vsp5, argd, argn, ve1p5, ve2p5, vsat, vs1p5, vs2p5, argd2, 
	    term0, term1, term2, term3, term4, term5, term6, term7, dddve, 
	    dddvs, term10, term11, term12, term20, term21, term22, sqarg, 
	    gamma2, dgndve, dqgdve, dvedvd, dvedvg, dgndvs;


/*     INITIALIZE CHARGES; */
/*     CHANGE REFERENCE VOLTAGES FOR CHARGE COMPUTATION */

    *qg = 0.;
    *qb = 0.;
    vbd = *vbs - *vds;
    vgb = *vgs - *vbs;
/* Computing MAX */
    d__1 = *phi - vbd;
    vd = max(d__1,1e-8);
/* Computing MAX */
    d__1 = *phi - *vbs;
    vs = max(d__1,1e-8);
    vg = vgb - *vbin + *phi;
    vsp5 = sqrt(vs);

/*     DETERMINE OPERATING REGION */

    if (*vgs <= *vth) {
	goto L1100;
    }

/*     COMPUTE CHARGES FOR "ON" REGION */

/* L1020: */
    vsat = *vdsat + vs;
    vs2 = vs * vs;
    vs3 = vs2 * vs;
    vs5 = vs3 * vs2;
    vs1p5 = vs * vsp5;
    vs2p5 = vs1p5 * vs;
/* L1025: */
    if (vd >= vsat) {
	goto L1035;
    }
    ve = vd;
/* L1030: */
    dvedvd = 1.;
    dvedvg = 0.;
    goto L1040;
L1035:
    ve = vsat;
    dvedvd = 0.;
    dvedvg = 0.;
L1040:
    ve2 = ve * ve;
    ve3 = ve2 * ve;
    ve5 = ve2 * ve3;
    vep5 = sqrt(ve);
    ve1p5 = ve * vep5;
    ve2p5 = ve1p5 * ve;
    term0 = ve + vs;
    term1 = vep5 + vsp5;
    term2 = vep5 * vsp5;
    term3 = ve2 + vs2;
    term4 = ve * vs;
    term5 = term0 * term1;
    term6 = term3 + term4 + term2 * term0;
    term7 = (term3 + term4) * term1;
    term10 = vep5 + vsp5 * .5;
    term11 = ve * 1.5 + vsp5 * term10;
    term12 = ve1p5 * 2. + vsp5 * term11;
    term20 = vep5 * .5 + vsp5;
    term21 = vs * 1.5 + vep5 * term20;
    term22 = vs1p5 * 2. + vep5 * term21;
    argn = vg * .5 * term5 - *gamasd * .4 * term6 - term7 / 3.;
    argd = vg * term1 - *gamasd * (term0 + term2) / 1.5 - term1 * .5 * term0;
    argd2 = argd * argd;
    *qg = *cox * (vg - argn / argd);
    dgndve = vg * .5 * term11 - *gamasd * .4 * term12 - (ve2 * 2.5 + vsp5 * 
	    term12) / 3.;
    dddve = vg * .5 - *gamasd * term10 / 1.5 - term11 * .5;
    dqgdve = -(*cox) / argd * (dgndve - (vg - *qg / *cox) * dddve);
    dgndvs = vg * .5 * term21 - *gamasd * .4 * term22 - (vs2 * 2.5 + vep5 * 
	    term22) / 3.;
    dddvs = vg * .5 - *gamasd * term20 / 1.5 - term21 * .5;
    *cgdb = -(*cox) / (argd * vep5) * (dgndve - (vg - *qg / *cox) * dddve) * 
	    dvedvd;
    *cgsb = -(*cox) / (argd * vsp5) * (dgndvs - (vg - *qg / *cox) * dddvs);
    *cggb = *cox * (1. - term1 / argd * (term0 * .5 - vg + *qg / *cox));
    argn = vg * (term0 + term2) / 1.5 - *gamasd * .5 * term5 - term6 * .4;
    dgndve = vg * term10 / 1.5 - *gamasd * .5 * term11 - term12 * .4;
    dgndvs = vg * term20 / 1.5 - *gamasd * .5 * term21 - term22 * .4;
    *qb = -(*gamasd) * *cox * argn / argd;
    *cbdb = -(*cox) / (vep5 * argd) * (*qb / *cox * dddve + *gamasd * dgndve) 
	    * dvedvd;
    *cbsb = -(*cox) / (vsp5 * argd) * (*qb / *cox * dddvs + *gamasd * dgndvs);
    *cbgb = -(*cox) / argd * (*gamasd * (term0 + term2) / 1.5 + *qb / *cox * 
	    term1);
    goto L2000;

/*  FINISH SPECIAL CASES */

L1100:
    if (vg > 0.) {
	goto L1110;
    }
    *qg = *cox * vg;
    *cggb = *cox;
    goto L1120;
L1110:
    gamma2 = *gamasd * .5;
    sqarg = sqrt(gamma2 * gamma2 + vg);
    *qg = *gamasd * *cox * (sqarg - gamma2);
    *cggb = *cox * .5 * *gamasd / sqarg;
L1120:
    *qb = -(*qg);
    *cbgb = -(*cggb);
    *cgdb = 0.;
    *cgsb = 0.;
    *cbdb = 0.;
    *cbsb = 0.;

/*  FINISHED */

L2000:
    *qc = -(*qg + *qb);
/* L2050: */
    return 0;
} /* mosq2_ */

/* Subroutine */ int mqspof_(doublereal *vds, doublereal *vbs, doublereal *
	vgs, doublereal *vpof, doublereal *vdsat1, doublereal *vth, 
	doublereal *vbin, doublereal *gamasd, doublereal *qg, doublereal *qc, 
	doublereal *qb, doublereal *cggb, doublereal *cgdb, doublereal *cgsb, 
	doublereal *cbgb, doublereal *cbdb, doublereal *cbsb)
{
    static doublereal qd, qs, qb1, qb2, qg1, qg2, cbgb1, cgdb1, cbdb1, cggb1, 
	    cggb2, cgdb2, cbgb2, cbdb2, cbsb1, cbsb2, cgsb1, cgsb2, csgb1;
    extern /* Subroutine */ int mosq2_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), mosq3_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    static doublereal qcpof, qcpof1, qcpof2, qspof2;


/* SPICE VERSION 2G.6  SCCSID=MOSARG 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */

/*     VDSAT1=DMAX1(VDS,VDSAT1)+1.0D-3 */
    if (mosarg_1.lev == 3) {
	goto L50;
    }
    if (mosarg_1.lev != 2) {
	goto L1000;
    }
    mosq2_(vds, vbs, vgs, &mosarg_1.vdsat, vth, vbin, gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, qg, qc, qb, cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
    if (*vds >= mosarg_1.vdsat) {
	goto L80;
    }
    mosq2_(vds, vbs, vpof, vdsat1, vth, vbin, gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, &qg1, &qcpof1, &qb1, &cggb1, &cgdb1, &cgsb1, &cbgb1,
	     &cbdb1, &cbsb1);
    mosq2_(&mosarg_1.vdsat, vbs, vgs, &mosarg_1.vdsat, vth, vbin, gamasd, &
	    mosarg_1.cox, &mosarg_1.phi, &qg2, &qcpof2, &qb2, &cggb2, &cgdb2, 
	    &cgsb2, &cbgb2, &cbdb2, &cbsb2);
    goto L75;
L50:
    mosq3_(vds, vbs, vpof, vdsat1, vth, vbin, gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, qg, &qcpof, qb, &cggb1, &cgdb1, &cgsb1, &cbgb1, &
	    cbdb1, &cbsb1);
    mosq3_(vds, vbs, vgs, &mosarg_1.vdsat, vth, vbin, gamasd, &mosarg_1.cox, &
	    mosarg_1.phi, qg, qc, qb, cggb, cgdb, cgsb, cbgb, cbdb, cbsb);
L75:
    if (*vgs > *vpof || *vds < mosarg_1.vdsat) {
	goto L100;
    }
L80:
    mosarg_1.xqc = mosarg_1.xqco;
    goto L1000;

/*     TANGENTIAL LIMITING OF QS */

L100:
    csgb1 = -(1. - mosarg_1.xqco) * (cggb1 + cbgb1);
    qs = csgb1 * (*vgs - *vpof) + (1. - mosarg_1.xqco) * qcpof1;
/*      write(IOFILE,*) "VGS,VDS,QC,CGGB,CGDB,CGSB,CBGB,CBDB,CBSB =", */
/*    1   vgs,vds,qc,cggb,cgdb,cgsb,cbgb,cbdb,cbsb */
/*      write(IOFILE,*) "VPOF,VDSAT,VDSAT1,QCPOF1,QCPOF2,QS,CSGB1 =", */
/*    1   vpof,vdsat,vdsat1,qcpof1,qcpof2,qs,csgb1 */
    qspof2 = (1. - mosarg_1.xqco) * qcpof2;
    if (abs(qs) < abs(qspof2)) {
	qs = qspof2;
    }
    if (abs(qs) >= abs(*qc) * .5) {
	goto L200;
    }
/*     CSDB=-0.25D0*(CGDB+CBDB) */
/*     QS=QS+CSDB*(VDSAT-VDS) */
/*     XQC=DMIN1(0.5D0,(QC-QS)/QC) */
    mosarg_1.xqc = .5;
/*      write(IOFILE,*) "QS,XQC =", */
/*    1   qs,xqc */
    goto L1000;
L200:
    qd = *qc - qs;
    mosarg_1.xqc = qd / *qc;
/*     write(IOFILE,*) "200,QS,QD,XQC =", */
/*    1   qs,qd,xqc */

/*     CONSTANT LIMITING OF QS */

/* 100 QDPOF = QCPOF * XQCO */
/*     QSPOF = QCPOF - QDPOF */
/*     IF( DABS( QSPOF ) .GT. 0.5D0 * DABS( QC ) ) GOTO 200 */
/*     XQC = 0.5D0 */
/*     GOTO 1000 */
/* 200 QD = QC - QSPOF */
/*     QS = QSPOF */
/*     XQC = QD / QC */
L1000:
    return 0;
} /* mqspof_ */

/* Subroutine */ int mosq3_(doublereal *vds, doublereal *vbs, doublereal *vgs,
	 doublereal *vdsat, doublereal *vth, doublereal *vbin, doublereal *
	gamasd, doublereal *cox, doublereal *phi, doublereal *qg, doublereal *
	qc, doublereal *qb, doublereal *cggb, doublereal *cgdb, doublereal *
	cgsb, doublereal *cbgb, doublereal *cbdb, doublereal *cbsb)
{
    /* System generated locals */
    static doublereal equiv_0[1], equiv_1[1], equiv_2[1], equiv_3[1];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal xl, cdo;
#define eta (equiv_2)
    static doublereal vfb, vgb, vbi;
#define vbp (equiv_1)
    static doublereal von, arga, vbix;
#define utra (equiv_3)
    static doublereal onxl;
#define uexp (equiv_2)
    static doublereal vdsx, vgsx, dadfb, dadco, gamma, dadvd;
#define alpha (equiv_0)
    static doublereal fbody;
#define theta (equiv_1)
    static doublereal phibs, gamma2, dfbdvb, dcodvb, dqbdvb, dcodvd, gammas;
#define xlamda (equiv_0)
    static doublereal dcodvg, dfsdvb, onfbdy, qbonco, dsqdvb;
#define xkappa (equiv_3)
    static doublereal fbodys, dvtdvb, dvtdvd, fnarrw, sqphbs, fshort;



/*     CHARGE EQUATIONS ARE REFERENCED TO BULK */

    vgb = *vgs - *vbs;
    vfb = vbi - *phi;
    onxl = 1. / xl;
    phibs = sqphbs * sqphbs;

/*     BODY EFFECT */

    gammas = gamma * fshort;
    fbodys = gammas / (sqphbs + sqphbs) * .5;
    fbody = fbodys + fnarrw;
    onfbdy = 1. / (fbody + 1.);
    dfbdvb = -fbodys * dsqdvb / sqphbs + fbodys * dfsdvb / fshort;
    qbonco = gammas * sqphbs + fnarrw * phibs;
    dqbdvb = gammas * dsqdvb + gamma * dfsdvb * sqphbs - fnarrw;

/* .....STATIC FEEDBACK EFFECT */

    vbix = vbi - *eta * *vds;

/* .....THRESHOLD VOLTAGE */

    *vth = vbix + qbonco;
    dvtdvd = -(*eta);
    dvtdvb = dqbdvb;

/*     BRANCH ACCORDING TO REGION OF OPERATION */

    if (*vgs <= *vth) {
	goto L800;
    }
    vgsx = max(*vgs,von);

/*     BRANCH ON VDS=0.0D0 */

    vdsx = min(*vds,*vdsat);
    if (vdsx == 0.) {
	goto L900;
    }
    cdo = vgsx - *vth - (fbody + 1.) * .5 * vdsx;
    dcodvg = 1.;
    if (*vds < *vdsat) {
	dcodvd = -dvtdvd - (fbody + 1.) * .5;
    }
    dcodvb = -dvtdvb - dfbdvb * .5 * vdsx;

/* .....CHARGE TERMS */

/* L420: */
    arga = (fbody + 1.) * vdsx * vdsx / (cdo * 12.);
    dadco = -arga / cdo;
    if (*vds < *vdsat) {
	dadvd = arga / vdsx;
    }
    dadfb = arga * onfbdy;

/* .....GATE CHARGE */

    *qg = *cox * (*vgs - vbix - vdsx * .5 + arga);
    *cggb = *cox * (dadco * dcodvg + 1.);
    if (*vds < *vdsat) {
	*cgdb = *cox * (-dvtdvd - .5 + dadvd + dadco * dcodvd);
    }
    *cgsb = -(*cggb) - *cgdb - *cox * (dadco * dcodvb + dadfb * dfbdvb);

/* .....BULK CHARGE */

    arga *= fbody;
    dadco *= fbody;
    if (*vds < *vdsat) {
	dadvd *= fbody;
    }
    dadfb *= fbody + 1. + fbody;

    *qb = -(*cox) * (qbonco + fbody * .5 * vdsx - arga);
    *cbgb = *cox * dadco * dcodvg;
    if (*vds < *vdsat) {
	*cbdb = -(*cox) * (fbody * .5 - dadvd - dadco * dcodvd);
    }
    *cbsb = -(*cbgb) - *cbdb + *cox * (dqbdvb + (vdsx * .5 - dadfb) * dfbdvb 
	    - dadco * dcodvb);
    goto L1000;

/* .....CHARGE TERMS OF VGS<VTH */

L800:
    if (vgb > vfb) {
	goto L810;
    }
    *qg = *cox * (vgb - vfb);
    *cggb = *cox;
    goto L820;
L810:
    gamma2 = gammas * .5;
    arga = sqrt(gamma2 * gamma2 + (vgb - vfb));
    *qg = gammas * *cox * (arga - gamma2);
    *cggb = *cox * .5 * gammas / arga;
L820:
    *qb = -(*qg);
    *cbgb = -(*cggb);
    *cgdb = 0.;
    *cgsb = 0.;
    *cbdb = 0.;
    *cbsb = 0.;
    goto L1000;

/*     SPECIAL CASE VDS=0.0D0 */

L900:
    *qg = *cox * (*vgs - vbi);
    *qb = -(*cox) * qbonco;
    *cggb = *cox;
    *cgdb = -(*cox) * (dvtdvd + .5);
    *cgsb = -(*cox) * (.5 - dvtdvb);
    *cbgb = 0.;
    *cbdb = *cox * -.5 * fbody;
    *cbsb = *cox * (dqbdvb + fbody * .5);

/*     DONE */

L1000:
    *qc = -(*qg + *qb);
    return 0;
} /* mosq3_ */

#undef xkappa
#undef xlamda
#undef theta
#undef alpha
#undef uexp
#undef utra
#undef vbp
#undef eta


/* SPICE VERSION 2G.6  SCCSID=dcop.ma 3/15/83 */
/* Subroutine */ int dcop_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_2505 = { "OPERATING POINT INFORMATION     ", 0. };

#define optitl ((doublereal *)&equiv_2505)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2506 = { "VD      ", 0. };

#define avd (*(doublereal *)&equiv_2506)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2507 = { "VBE     ", 0. };

#define avbe (*(doublereal *)&equiv_2507)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2508 = { "VBC     ", 0. };

#define avbc (*(doublereal *)&equiv_2508)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2509 = { "VCE     ", 0. };

#define avce (*(doublereal *)&equiv_2509)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2510 = { "VGS     ", 0. };

#define avgs (*(doublereal *)&equiv_2510)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2511 = { "VDS     ", 0. };

#define avds (*(doublereal *)&equiv_2511)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2512 = { "VBS     ", 0. };

#define avbs (*(doublereal *)&equiv_2512)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2513 = { "V-SOURCE", 0. };

#define asrcv (*(doublereal *)&equiv_2513)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2514 = { "I-SOURCE", 0. };

#define asrci (*(doublereal *)&equiv_2514)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2515 = { "ID      ", 0. };

#define aid (*(doublereal *)&equiv_2515)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2516 = { "IB      ", 0. };

#define aib (*(doublereal *)&equiv_2516)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2517 = { "IC      ", 0. };

#define aic (*(doublereal *)&equiv_2517)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2518 = { "IG      ", 0. };

#define aig (*(doublereal *)&equiv_2518)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2519 = { "REQ     ", 0. };

#define areq (*(doublereal *)&equiv_2519)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2520 = { "RPI     ", 0. };

#define arpi (*(doublereal *)&equiv_2520)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2521 = { "RO      ", 0. };

#define aro (*(doublereal *)&equiv_2521)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2522 = { "CAP     ", 0. };

#define acap (*(doublereal *)&equiv_2522)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2523 = { "CPI     ", 0. };

#define acpi (*(doublereal *)&equiv_2523)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2524 = { "CMU     ", 0. };

#define acmu (*(doublereal *)&equiv_2524)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2525 = { "CGS     ", 0. };

#define acgs (*(doublereal *)&equiv_2525)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2526 = { "CGD     ", 0. };

#define acgd (*(doublereal *)&equiv_2526)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2527 = { "CBD     ", 0. };

#define acbd (*(doublereal *)&equiv_2527)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2528 = { "CBS     ", 0. };

#define acbs (*(doublereal *)&equiv_2528)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2529 = { "CGSOVL  ", 0. };

#define acgsov (*(doublereal *)&equiv_2529)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2530 = { "CGDOVL  ", 0. };

#define acgdov (*(doublereal *)&equiv_2530)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2531 = { "CGBOVL  ", 0. };

#define acgbov (*(doublereal *)&equiv_2531)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2532 = { "DQGDVGB ", 0. };

#define acggb (*(doublereal *)&equiv_2532)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2533 = { "DQGDVDB ", 0. };

#define acgdb (*(doublereal *)&equiv_2533)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2534 = { "DQGDVSB ", 0. };

#define acgsb (*(doublereal *)&equiv_2534)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2535 = { "DQBDVGB ", 0. };

#define acbgb (*(doublereal *)&equiv_2535)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2536 = { "DQBDVDB ", 0. };

#define acbdb (*(doublereal *)&equiv_2536)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2537 = { "DQBDVSB ", 0. };

#define acbsb (*(doublereal *)&equiv_2537)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2538 = { "CGB     ", 0. };

#define acgb (*(doublereal *)&equiv_2538)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2539 = { "CDS     ", 0. };

#define acds (*(doublereal *)&equiv_2539)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2540 = { "VTH     ", 0. };

#define avth (*(doublereal *)&equiv_2540)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2541 = { "VDSAT   ", 0. };

#define avdsat (*(doublereal *)&equiv_2541)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2542 = { "GM      ", 0. };

#define agm (*(doublereal *)&equiv_2542)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2543 = { "GDS     ", 0. };

#define agds (*(doublereal *)&equiv_2543)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2544 = { "GMB     ", 0. };

#define agmb (*(doublereal *)&equiv_2544)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2545 = { "CCS     ", 0. };

#define accs (*(doublereal *)&equiv_2545)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2546 = { "CBX     ", 0. };

#define acbx (*(doublereal *)&equiv_2546)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2547 = { "RX      ", 0. };

#define arx (*(doublereal *)&equiv_2547)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2548 = { "BETADC  ", 0. };

#define abetad (*(doublereal *)&equiv_2548)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2549 = { "BETAAC  ", 0. };

#define abetaa (*(doublereal *)&equiv_2549)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2550 = { "FT      ", 0. };

#define aft (*(doublereal *)&equiv_2550)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2551 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_2551)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2552 = { "(//1H0,10X,  (2X,A8))   ", 0. };

#define afmt1 ((doublereal *)&equiv_2552)

    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_2553 = { "(1H ,A8,  F10.3)", 0. };

#define afmt2 ((doublereal *)&equiv_2553)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2554 = { "(1H ,A8,1P  E10.2)      ", 0. };

#define afmt3 ((doublereal *)&equiv_2554)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2555 = { "('0MODEL   ',  (2X,A8)) ", 0. };

#define afmt4 ((doublereal *)&equiv_2555)


    /* Format strings */
    static char fmt_11[] = "(////5x,\002VOLTAGE SOURCE CURRENTS\002//5x,\002"
	    "NAME\002,7x,\002CURRENT\002/)";
    static char fmt_21[] = "(/5x,a8,1x,1pd10.3)";
    static char fmt_91[] = "(//5x,\002TOTAL POWER DISSIPATION  \002,1pd9.2"
	    ",\002  WATTS\002)";
    static char fmt_111[] = "(\0020\002,/,\0020**** VOLTAGE-CONTROLLED CURRE"
	    "NT SOURCES\002)";
    static char fmt_176[] = "(\0020\002,/,\0020**** VOLTAGE-CONTROLLED VOLTA"
	    "GE SOURCES\002)";
    static char fmt_187[] = "(\0020\002,/,\0020**** CURRENT-CONTROLLED CURRE"
	    "NT SOURCES\002)";
    static char fmt_197[] = "(\0020\002,/,\0020**** CURRENT-CONTROLLED VOLTA"
	    "GE SOURCES\002)";
    static char fmt_211[] = "(\0020\002,/,\0020**** DIODES\002)";
    static char fmt_301[] = "(\0020\002,/,\0020**** BIPOLAR JUNCTION TRANSIS"
	    "TORS\002)";
    static char fmt_401[] = "(\0020\002,/,\0020**** JFETS\002)";
    static char fmt_501[] = "(\0020\002,/,\0020**** MOSFETS\002)";
    static char fmt_551[] = "(\002 DERIVATIVES OF GATE (DQGDVX) AND BULK (DQ"
	    "BDVX) CHARGES\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_6[12], equiv_7[12], equiv_8[12], equiv_9[12], 
	    equiv_10[12], equiv_11[12], equiv_12[12], equiv_13[12], equiv_16[
	    12], equiv_17[12], equiv_18[12], equiv_19[12], equiv_20[12], 
	    equiv_21[12], equiv_22[12], equiv_23[12], equiv_24[12];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal t1, t2;
#define cb (equiv_16)
#define cc (equiv_17)
#define cd (equiv_13)
#define cg (equiv_16)
    static doublereal gm[12];
#define vd (equiv_16)
#define ft (equiv_12)
#define ro (equiv_7)
    static doublereal xl;
#define rx (equiv_22)
    static doublereal xw;
#define ai1 (equiv_19)
#define av1 (equiv_18)
#define cbd (equiv_6)
#define cgb (equiv_23)
#define cgd (equiv_22)
#define cap (equiv_17)
    static doublereal gmb[12];
#define ccs (equiv_13)
#define cbs (equiv_7)
#define vbc (equiv_19)
#define cpi (equiv_8)
#define vbe (equiv_18)
#define vce (equiv_20)
#define cbx (equiv_21)
#define gds (equiv_19)
#define cgs (equiv_21)
#define cmu (equiv_9)
#define cds (equiv_24)
#define req (equiv_20)
#define rpi (equiv_6)
#define vbs (equiv_20)
#define vds (equiv_18)
#define vgs (equiv_17)
#define vth (equiv_11)
    static integer loc;
    static doublereal cbdb[12];
#define cbgb (equiv_24)
#define cgdb (equiv_22)
#define cggb (equiv_21)
    static doublereal cbsb[12], anam[12];
#define cgsb (equiv_23)
    static doublereal amod[12];
    static integer ipos, kntr;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer locv, iptr, loct, locm;
    static doublereal type__, xqco;
    extern /* Subroutine */ int sstf_(void);
    static integer node1, node2, node3, node4, node5, node6;
    static doublereal creal;
#define cgdov (equiv_9)
#define cgbov (equiv_10)
#define cgsov (equiv_8)
#define vdsat (equiv_12)
    static doublereal power;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
#define betaac (equiv_11)
#define betadc (equiv_10)
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern logical memptr_(integer *);
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *), 
	    second_(doublereal *);
    static integer ititle, numdev, kntlim;
    static doublereal covlgs, covlgd, covlgb, devmod;
    extern /* Subroutine */ int sencal_(void), clrmem_(integer *);

    /* Fortran I/O blocks */
    static cilist io___2388 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___2389 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___2392 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___2397 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___2398 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2400 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2401 = { 0, 0, 0, fmt_176, 0 };
    static cilist io___2402 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2403 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2404 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2405 = { 0, 0, 0, fmt_187, 0 };
    static cilist io___2406 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2407 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2408 = { 0, 0, 0, fmt_197, 0 };
    static cilist io___2409 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2410 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2411 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2414 = { 0, 0, 0, fmt_211, 0 };
    static cilist io___2415 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2416 = { 0, 0, 0, (char *)afmt4, 0 };
    static cilist io___2417 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2418 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2419 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2420 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2424 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___2425 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2426 = { 0, 0, 0, (char *)afmt4, 0 };
    static cilist io___2427 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2428 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2429 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2430 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2431 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2432 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2433 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2434 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2435 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2436 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2437 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2438 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2439 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2440 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2441 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2442 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2443 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___2444 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2445 = { 0, 0, 0, (char *)afmt4, 0 };
    static cilist io___2446 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2447 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2448 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2449 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2450 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2451 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2452 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2466 = { 0, 0, 0, fmt_501, 0 };
    static cilist io___2467 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2468 = { 0, 0, 0, (char *)afmt4, 0 };
    static cilist io___2469 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2470 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2471 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2472 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2473 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2474 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2475 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2476 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2477 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2478 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2479 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2480 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2481 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2482 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2483 = { 0, 0, 0, fmt_551, 0 };
    static cilist io___2484 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2485 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2486 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2487 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2488 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2489 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2490 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2491 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2492 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2493 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2494 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2495 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2496 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2497 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2498 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2499 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2500 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2501 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2502 = { 0, 0, 0, (char *)afmt3, 0 };
    static cilist io___2503 = { 0, 0, 0, (char *)afmt3, 0 };



/*     THIS ROUTINE PRINTS OUT THE OPERATING POINTS OF THE NONLINEAR */
/* CIRCUIT ELEMENTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




/* .. FIX-UP THE FORMAT STATEMENTS */

    kntr = 12;
    if (miscel_1.lwidth <= 80) {
	kntr = 7;
    }
    ipos = 12;
    move_(afmt1, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt1, &ipos);
    ipos = 9;
    move_(afmt2, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt2, &ipos);
    ipos = 11;
    move_(afmt3, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt3, &ipos);
    ipos = 14;
    move_(afmt4, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt4, &ipos);

/*  COMPUTE VOLTAGE SOURCE CURRENTS AND POWER DISSIPATION */

    second_(&t1);
    if (status_1.mode == 1 && status_1.modedc == 2 && status_1.nosolv != 0) {
	goto L700;
    }
    power = 0.;
    if (cirdat_1.jelcnt[8] == 0) {
	goto L50;
    }
    ititle = 0;
/* L11: */
    loc = cirdat_1.locate[8];
L20:
    if (loc == 0 || nodplc[loc + 10] != 0) {
	goto L50;
    }
    locv = nodplc[loc];
    iptr = nodplc[loc + 5];
    creal = blank_1.value[tabinf_1.lvnim1 + iptr - 1];
    power -= creal * blank_1.value[locv];
    if (ititle == 0) {
	io___2388.ciunit = status_1.iofile;
	s_wsfe(&io___2388);
	e_wsfe();
    }
    ititle = 1;
    io___2389.ciunit = status_1.iofile;
    s_wsfe(&io___2389);
    do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(doublereal)
	    );
    do_fio(&c__1, (char *)&creal, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L30: */
    loc = nodplc[loc - 1];
    goto L20;
L50:
    loc = cirdat_1.locate[9];
L60:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L90;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    power -= blank_1.value[locv] * (blank_1.value[tabinf_1.lvnim1 + node1 - 1]
	     - blank_1.value[tabinf_1.lvnim1 + node2 - 1]);
    loc = nodplc[loc - 1];
    goto L60;
L90:
    io___2392.ciunit = status_1.iofile;
    s_wsfe(&io___2392);
    do_fio(&c__1, (char *)&power, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  SMALL SIGNAL DEVICE PARAMETERS */

    numdev = cirdat_1.jelcnt[4] + cirdat_1.jelcnt[5] + cirdat_1.jelcnt[6] + 
	    cirdat_1.jelcnt[7] + cirdat_1.jelcnt[10] + cirdat_1.jelcnt[11] + 
	    cirdat_1.jelcnt[12] + cirdat_1.jelcnt[13];
    if (numdev == 0) {
	goto L600;
    }
    title_(&c__0, &miscel_1.lwidth, &c__1, optitl);
    kntlim = miscel_1.lwidth / 11;

/*  NONLINEAR VOLTAGE CONTROLLED CURRENT SOURCES */

    if (cirdat_1.jelcnt[4] == 0) {
	goto L175;
    }
    ititle = 0;
/* L111: */
    loc = cirdat_1.locate[4];
    kntr = 0;
L120:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L140;
    }
    ++kntr;
    locv = nodplc[loc];
    loct = tabinf_1.lx0 + nodplc[loc + 11];
    anam[kntr - 1] = blank_1.value[locv - 1];
    ai1[kntr - 1] = blank_1.value[loct - 1];
    if (kntr >= kntlim) {
	goto L150;
    }
L130:
    loc = nodplc[loc - 1];
    goto L120;
L140:
    if (kntr == 0) {
	goto L175;
    }
L150:
    if (ititle == 0) {
	io___2397.ciunit = status_1.iofile;
	s_wsfe(&io___2397);
	e_wsfe();
    }
    ititle = 1;
    io___2398.ciunit = status_1.iofile;
    s_wsfe(&io___2398);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2400.ciunit = status_1.iofile;
    s_wsfe(&io___2400);
    do_fio(&c__1, (char *)&asrci, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ai1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    kntr = 0;
    if (loc != 0 && nodplc[loc + 12] == 0) {
	goto L130;
    }

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L175:
    if (cirdat_1.jelcnt[5] == 0) {
	goto L186;
    }
    ititle = 0;
/* L176: */
    loc = cirdat_1.locate[5];
    kntr = 0;
L178:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L182;
    }
    ++kntr;
    locv = nodplc[loc];
    loct = tabinf_1.lx0 + nodplc[loc + 12];
    anam[kntr - 1] = blank_1.value[locv - 1];
    av1[kntr - 1] = blank_1.value[loct - 1];
    ai1[kntr - 1] = blank_1.value[loct];
    if (kntr >= kntlim) {
	goto L184;
    }
L180:
    loc = nodplc[loc - 1];
    goto L178;
L182:
    if (kntr == 0) {
	goto L186;
    }
L184:
    if (ititle == 0) {
	io___2401.ciunit = status_1.iofile;
	s_wsfe(&io___2401);
	e_wsfe();
    }
    ititle = 1;
    io___2402.ciunit = status_1.iofile;
    s_wsfe(&io___2402);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2403.ciunit = status_1.iofile;
    s_wsfe(&io___2403);
    do_fio(&c__1, (char *)&asrcv, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&av1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2404.ciunit = status_1.iofile;
    s_wsfe(&io___2404);
    do_fio(&c__1, (char *)&asrci, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ai1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    kntr = 0;
    if (loc != 0 && nodplc[loc + 13] == 0) {
	goto L180;
    }

/*  NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */

L186:
    if (cirdat_1.jelcnt[6] == 0) {
	goto L196;
    }
    ititle = 0;
/* L187: */
    loc = cirdat_1.locate[6];
    kntr = 0;
L188:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L192;
    }
    ++kntr;
    locv = nodplc[loc];
    loct = tabinf_1.lx0 + nodplc[loc + 11];
    anam[kntr - 1] = blank_1.value[locv - 1];
    ai1[kntr - 1] = blank_1.value[loct - 1];
    if (kntr >= kntlim) {
	goto L194;
    }
L190:
    loc = nodplc[loc - 1];
    goto L188;
L192:
    if (kntr == 0) {
	goto L196;
    }
L194:
    if (ititle == 0) {
	io___2405.ciunit = status_1.iofile;
	s_wsfe(&io___2405);
	e_wsfe();
    }
    ititle = 1;
    io___2406.ciunit = status_1.iofile;
    s_wsfe(&io___2406);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2407.ciunit = status_1.iofile;
    s_wsfe(&io___2407);
    do_fio(&c__1, (char *)&asrci, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ai1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    kntr = 0;
    if (loc != 0 && nodplc[loc + 12] == 0) {
	goto L190;
    }

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L196:
    if (cirdat_1.jelcnt[7] == 0) {
	goto L210;
    }
    ititle = 0;
/* L197: */
    loc = cirdat_1.locate[7];
    kntr = 0;
L198:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L202;
    }
    ++kntr;
    locv = nodplc[loc];
    loct = tabinf_1.lx0 + nodplc[loc + 12];
    anam[kntr - 1] = blank_1.value[locv - 1];
    av1[kntr - 1] = blank_1.value[loct - 1];
    ai1[kntr - 1] = blank_1.value[loct];
    if (kntr >= kntlim) {
	goto L204;
    }
L200:
    loc = nodplc[loc - 1];
    goto L198;
L202:
    if (kntr == 0) {
	goto L210;
    }
L204:
    if (ititle == 0) {
	io___2408.ciunit = status_1.iofile;
	s_wsfe(&io___2408);
	e_wsfe();
    }
    ititle = 1;
    io___2409.ciunit = status_1.iofile;
    s_wsfe(&io___2409);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2410.ciunit = status_1.iofile;
    s_wsfe(&io___2410);
    do_fio(&c__1, (char *)&asrcv, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&av1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2411.ciunit = status_1.iofile;
    s_wsfe(&io___2411);
    do_fio(&c__1, (char *)&asrci, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ai1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    kntr = 0;
    if (loc != 0 && nodplc[loc + 13] == 0) {
	goto L200;
    }

/*  DIODES */

L210:
    if (cirdat_1.jelcnt[10] == 0) {
	goto L300;
    }
    ititle = 0;
/* L211: */
    loc = cirdat_1.locate[10];
    kntr = 0;
L220:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L240;
    }
    ++kntr;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 10];
    anam[kntr - 1] = blank_1.value[locv - 1];
    amod[kntr - 1] = blank_1.value[locm - 1];
    cd[kntr - 1] = blank_1.value[loct];
    vd[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - blank_1.value[
	    tabinf_1.lvnim1 + node2 - 1];
    if (status_1.modedc != 1) {
	goto L225;
    }
    req[kntr - 1] = 1. / blank_1.value[loct + 1];
    cap[kntr - 1] = blank_1.value[loct + 3];
L225:
    if (kntr >= kntlim) {
	goto L250;
    }
L230:
    loc = nodplc[loc - 1];
    goto L220;
L240:
    if (kntr == 0) {
	goto L300;
    }
L250:
    if (ititle == 0) {
	io___2414.ciunit = status_1.iofile;
	s_wsfe(&io___2414);
	e_wsfe();
    }
    ititle = 1;
    io___2415.ciunit = status_1.iofile;
    s_wsfe(&io___2415);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2416.ciunit = status_1.iofile;
    s_wsfe(&io___2416);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&amod[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2417.ciunit = status_1.iofile;
    s_wsfe(&io___2417);
    do_fio(&c__1, (char *)&aid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2418.ciunit = status_1.iofile;
    s_wsfe(&io___2418);
    do_fio(&c__1, (char *)&avd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (status_1.modedc != 1) {
	goto L260;
    }
    io___2419.ciunit = status_1.iofile;
    s_wsfe(&io___2419);
    do_fio(&c__1, (char *)&areq, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&req[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2420.ciunit = status_1.iofile;
    s_wsfe(&io___2420);
    do_fio(&c__1, (char *)&acap, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cap[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L260:
    kntr = 0;
    if (loc != 0 && nodplc[loc + 15] == 0) {
	goto L230;
    }

/*  BIPOLAR JUNCTION TRANSISTORS */

L300:
    if (cirdat_1.jelcnt[11] == 0) {
	goto L400;
    }
    ititle = 0;
/* L301: */
    loc = cirdat_1.locate[11];
    kntr = 0;
L320:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L340;
    }
    ++kntr;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    locm = nodplc[loc + 7];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 21];
    anam[kntr - 1] = blank_1.value[locv - 1];
    amod[kntr - 1] = blank_1.value[locm - 1];
    cb[kntr - 1] = type__ * blank_1.value[loct + 2];
    cc[kntr - 1] = type__ * blank_1.value[loct + 1];
    vbe[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    vbc[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node1 - 1];
    vce[kntr - 1] = vbe[kntr - 1] - vbc[kntr - 1];
/* Computing MAX */
    d__3 = (d__1 = cb[kntr - 1], abs(d__1));
    d__2 = max(d__3,1e-20);
    betadc[kntr - 1] = cc[kntr - 1] / d_sign(&d__2, &cb[kntr - 1]);
    if (status_1.modedc != 1) {
	goto L325;
    }
    rx[kntr - 1] = 0.;
    if (blank_1.value[loct + 15] != 0.) {
	rx[kntr - 1] = 1. / blank_1.value[loct + 15];
    }
    ccs[kntr - 1] = blank_1.value[loct + 12];
    cbx[kntr - 1] = blank_1.value[loct + 14];
    rpi[kntr - 1] = 1. / blank_1.value[loct + 3];
    gm[kntr - 1] = blank_1.value[loct + 5];
    ro[kntr - 1] = 1. / blank_1.value[loct + 6];
    cpi[kntr - 1] = blank_1.value[loct + 8];
    cmu[kntr - 1] = blank_1.value[loct + 10];
    betaac[kntr - 1] = gm[kntr - 1] * rpi[kntr - 1];
/* Computing MAX */
    d__1 = cpi[kntr - 1] + cmu[kntr - 1] + cbx[kntr - 1];
    ft[kntr - 1] = gm[kntr - 1] / (knstnt_1.twopi * max(d__1,1e-20));
L325:
    if (kntr >= kntlim) {
	goto L350;
    }
L330:
    loc = nodplc[loc - 1];
    goto L320;
L340:
    if (kntr == 0) {
	goto L400;
    }
L350:
    if (ititle == 0) {
	io___2424.ciunit = status_1.iofile;
	s_wsfe(&io___2424);
	e_wsfe();
    }
    ititle = 1;
    io___2425.ciunit = status_1.iofile;
    s_wsfe(&io___2425);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2426.ciunit = status_1.iofile;
    s_wsfe(&io___2426);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&amod[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2427.ciunit = status_1.iofile;
    s_wsfe(&io___2427);
    do_fio(&c__1, (char *)&aib, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2428.ciunit = status_1.iofile;
    s_wsfe(&io___2428);
    do_fio(&c__1, (char *)&aic, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cc[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2429.ciunit = status_1.iofile;
    s_wsfe(&io___2429);
    do_fio(&c__1, (char *)&avbe, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vbe[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2430.ciunit = status_1.iofile;
    s_wsfe(&io___2430);
    do_fio(&c__1, (char *)&avbc, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vbc[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2431.ciunit = status_1.iofile;
    s_wsfe(&io___2431);
    do_fio(&c__1, (char *)&avce, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vce[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2432.ciunit = status_1.iofile;
    s_wsfe(&io___2432);
    do_fio(&c__1, (char *)&abetad, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&betadc[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (status_1.modedc != 1) {
	goto L360;
    }
    io___2433.ciunit = status_1.iofile;
    s_wsfe(&io___2433);
    do_fio(&c__1, (char *)&agm, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2434.ciunit = status_1.iofile;
    s_wsfe(&io___2434);
    do_fio(&c__1, (char *)&arpi, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&rpi[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2435.ciunit = status_1.iofile;
    s_wsfe(&io___2435);
    do_fio(&c__1, (char *)&arx, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&rx[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2436.ciunit = status_1.iofile;
    s_wsfe(&io___2436);
    do_fio(&c__1, (char *)&aro, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ro[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2437.ciunit = status_1.iofile;
    s_wsfe(&io___2437);
    do_fio(&c__1, (char *)&acpi, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cpi[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2438.ciunit = status_1.iofile;
    s_wsfe(&io___2438);
    do_fio(&c__1, (char *)&acmu, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cmu[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2439.ciunit = status_1.iofile;
    s_wsfe(&io___2439);
    do_fio(&c__1, (char *)&acbx, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbx[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2440.ciunit = status_1.iofile;
    s_wsfe(&io___2440);
    do_fio(&c__1, (char *)&accs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ccs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2441.ciunit = status_1.iofile;
    s_wsfe(&io___2441);
    do_fio(&c__1, (char *)&abetaa, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&betaac[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2442.ciunit = status_1.iofile;
    s_wsfe(&io___2442);
    do_fio(&c__1, (char *)&aft, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ft[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L360:
    kntr = 0;
    if (loc != 0 && nodplc[loc + 35] == 0) {
	goto L330;
    }

/*  JFETS */

L400:
    if (cirdat_1.jelcnt[12] == 0) {
	goto L500;
    }
    ititle = 0;
/* L401: */
    loc = cirdat_1.locate[12];
    kntr = 0;
L420:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L440;
    }
    ++kntr;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    locm = nodplc[loc + 6];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 18];
    anam[kntr - 1] = blank_1.value[locv - 1];
    amod[kntr - 1] = blank_1.value[locm - 1];
    cd[kntr - 1] = type__ * (blank_1.value[loct + 2] - blank_1.value[loct + 3]
	    );
    vgs[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    vds[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    if (status_1.modedc != 1) {
	goto L425;
    }
    gm[kntr - 1] = blank_1.value[loct + 4];
    gds[kntr - 1] = blank_1.value[loct + 5];
    cgs[kntr - 1] = blank_1.value[loct + 8];
    cgd[kntr - 1] = blank_1.value[loct + 10];
L425:
    if (kntr >= kntlim) {
	goto L450;
    }
L430:
    loc = nodplc[loc - 1];
    goto L420;
L440:
    if (kntr == 0) {
	goto L500;
    }
L450:
    if (ititle == 0) {
	io___2443.ciunit = status_1.iofile;
	s_wsfe(&io___2443);
	e_wsfe();
    }
    ititle = 1;
    io___2444.ciunit = status_1.iofile;
    s_wsfe(&io___2444);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2445.ciunit = status_1.iofile;
    s_wsfe(&io___2445);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&amod[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2446.ciunit = status_1.iofile;
    s_wsfe(&io___2446);
    do_fio(&c__1, (char *)&aid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2447.ciunit = status_1.iofile;
    s_wsfe(&io___2447);
    do_fio(&c__1, (char *)&avgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2448.ciunit = status_1.iofile;
    s_wsfe(&io___2448);
    do_fio(&c__1, (char *)&avds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (status_1.modedc != 1) {
	goto L460;
    }
    io___2449.ciunit = status_1.iofile;
    s_wsfe(&io___2449);
    do_fio(&c__1, (char *)&agm, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2450.ciunit = status_1.iofile;
    s_wsfe(&io___2450);
    do_fio(&c__1, (char *)&agds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2451.ciunit = status_1.iofile;
    s_wsfe(&io___2451);
    do_fio(&c__1, (char *)&acgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2452.ciunit = status_1.iofile;
    s_wsfe(&io___2452);
    do_fio(&c__1, (char *)&acgd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L460:
    kntr = 0;
    if (loc != 0 && nodplc[loc + 24] == 0) {
	goto L430;
    }

/*  MOSFETS */

L500:
    if (cirdat_1.jelcnt[13] == 0) {
	goto L600;
    }
    ititle = 0;
/* L501: */
    loc = cirdat_1.locate[13];
    kntr = 0;
L520:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L540;
    }
    ++kntr;
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    locm = nodplc[loc + 7];
    type__ = (doublereal) nodplc[locm + 1];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 25];
    anam[kntr - 1] = blank_1.value[locv - 1];
    amod[kntr - 1] = blank_1.value[locm - 1];
    cd[kntr - 1] = type__ * blank_1.value[loct + 3];
    vgs[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node2 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    vds[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node1 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    vbs[kntr - 1] = blank_1.value[tabinf_1.lvnim1 + node4 - 1] - 
	    blank_1.value[tabinf_1.lvnim1 + node3 - 1];
    if (status_1.modedc != 1) {
	goto L525;
    }
    xl = blank_1.value[locv] - blank_1.value[locm + 27] * 2.;
    xw = blank_1.value[locv + 1];
    covlgs = blank_1.value[locm + 12] * xw;
    covlgd = blank_1.value[locm + 13] * xw;
    covlgb = blank_1.value[locm + 14] * xl;
    xqco = blank_1.value[locm + 34];
    devmod = blank_1.value[locv + 7];
    vdsat[kntr - 1] = blank_1.value[locv + 9];
    vth[kntr - 1] = blank_1.value[locv + 8];
    gm[kntr - 1] = blank_1.value[loct + 6];
    gds[kntr - 1] = blank_1.value[loct + 7];
    gmb[kntr - 1] = blank_1.value[loct + 8];
    if (devmod > 0.) {
	goto L521;
    }
    vth[kntr - 1] = blank_1.value[locv + 8];
L521:
    cbd[kntr - 1] = blank_1.value[loct + 23];
    cbs[kntr - 1] = blank_1.value[loct + 25];
    cgsov[kntr - 1] = covlgs;
    cgdov[kntr - 1] = covlgd;
    cgbov[kntr - 1] = covlgb;
    if (xqco > .5) {
	goto L522;
    }
    cggb[kntr - 1] = blank_1.value[loct + 17];
    cgdb[kntr - 1] = blank_1.value[loct + 18];
    cgsb[kntr - 1] = blank_1.value[loct + 19];
    cbgb[kntr - 1] = blank_1.value[loct + 20];
    cbdb[kntr - 1] = blank_1.value[loct + 21];
    cbsb[kntr - 1] = blank_1.value[loct + 22];
    goto L525;
L522:
    cgs[kntr - 1] = blank_1.value[loct + 11];
    cgd[kntr - 1] = blank_1.value[loct + 13];
    cgb[kntr - 1] = blank_1.value[loct + 15];
L525:
    if (kntr >= kntlim) {
	goto L550;
    }
L530:
    loc = nodplc[loc - 1];
    goto L520;
L540:
    if (kntr == 0) {
	goto L600;
    }
L550:
    if (ititle == 0) {
	io___2466.ciunit = status_1.iofile;
	s_wsfe(&io___2466);
	e_wsfe();
    }
    ititle = 1;
    io___2467.ciunit = status_1.iofile;
    s_wsfe(&io___2467);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2468.ciunit = status_1.iofile;
    s_wsfe(&io___2468);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&amod[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (type__ == 0.) {
	goto L555;
    }
    io___2469.ciunit = status_1.iofile;
    s_wsfe(&io___2469);
    do_fio(&c__1, (char *)&aid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2470.ciunit = status_1.iofile;
    s_wsfe(&io___2470);
    do_fio(&c__1, (char *)&avgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2471.ciunit = status_1.iofile;
    s_wsfe(&io___2471);
    do_fio(&c__1, (char *)&avds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2472.ciunit = status_1.iofile;
    s_wsfe(&io___2472);
    do_fio(&c__1, (char *)&avbs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vbs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (status_1.modedc != 1) {
	goto L560;
    }
    io___2473.ciunit = status_1.iofile;
    s_wsfe(&io___2473);
    do_fio(&c__1, (char *)&avth, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vth[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2474.ciunit = status_1.iofile;
    s_wsfe(&io___2474);
    do_fio(&c__1, (char *)&avdsat, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vdsat[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2475.ciunit = status_1.iofile;
    s_wsfe(&io___2475);
    do_fio(&c__1, (char *)&agm, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2476.ciunit = status_1.iofile;
    s_wsfe(&io___2476);
    do_fio(&c__1, (char *)&agds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2477.ciunit = status_1.iofile;
    s_wsfe(&io___2477);
    do_fio(&c__1, (char *)&agmb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gmb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2478.ciunit = status_1.iofile;
    s_wsfe(&io___2478);
    do_fio(&c__1, (char *)&acbd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2479.ciunit = status_1.iofile;
    s_wsfe(&io___2479);
    do_fio(&c__1, (char *)&acbs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2480.ciunit = status_1.iofile;
    s_wsfe(&io___2480);
    do_fio(&c__1, (char *)&acgsov, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgsov[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2481.ciunit = status_1.iofile;
    s_wsfe(&io___2481);
    do_fio(&c__1, (char *)&acgdov, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgdov[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2482.ciunit = status_1.iofile;
    s_wsfe(&io___2482);
    do_fio(&c__1, (char *)&acgbov, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgbov[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (xqco > .5) {
	goto L552;
    }
    io___2483.ciunit = status_1.iofile;
    s_wsfe(&io___2483);
    e_wsfe();
    io___2484.ciunit = status_1.iofile;
    s_wsfe(&io___2484);
    do_fio(&c__1, (char *)&acggb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cggb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2485.ciunit = status_1.iofile;
    s_wsfe(&io___2485);
    do_fio(&c__1, (char *)&acgdb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgdb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2486.ciunit = status_1.iofile;
    s_wsfe(&io___2486);
    do_fio(&c__1, (char *)&acgsb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgsb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2487.ciunit = status_1.iofile;
    s_wsfe(&io___2487);
    do_fio(&c__1, (char *)&acbgb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbgb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2488.ciunit = status_1.iofile;
    s_wsfe(&io___2488);
    do_fio(&c__1, (char *)&acbdb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbdb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2489.ciunit = status_1.iofile;
    s_wsfe(&io___2489);
    do_fio(&c__1, (char *)&acbsb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cbsb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L560;
L552:
    io___2490.ciunit = status_1.iofile;
    s_wsfe(&io___2490);
    do_fio(&c__1, (char *)&acgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2491.ciunit = status_1.iofile;
    s_wsfe(&io___2491);
    do_fio(&c__1, (char *)&acgd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2492.ciunit = status_1.iofile;
    s_wsfe(&io___2492);
    do_fio(&c__1, (char *)&acgb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L560;
L555:
    io___2493.ciunit = status_1.iofile;
    s_wsfe(&io___2493);
    do_fio(&c__1, (char *)&aid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2494.ciunit = status_1.iofile;
    s_wsfe(&io___2494);
    do_fio(&c__1, (char *)&aig, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cg[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2495.ciunit = status_1.iofile;
    s_wsfe(&io___2495);
    do_fio(&c__1, (char *)&avgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2496.ciunit = status_1.iofile;
    s_wsfe(&io___2496);
    do_fio(&c__1, (char *)&avds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2497.ciunit = status_1.iofile;
    s_wsfe(&io___2497);
    do_fio(&c__1, (char *)&avbs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vbs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (status_1.modedc != 1) {
	goto L560;
    }
    io___2498.ciunit = status_1.iofile;
    s_wsfe(&io___2498);
    do_fio(&c__1, (char *)&agm, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2499.ciunit = status_1.iofile;
    s_wsfe(&io___2499);
    do_fio(&c__1, (char *)&agds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&gds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2500.ciunit = status_1.iofile;
    s_wsfe(&io___2500);
    do_fio(&c__1, (char *)&acgs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgs[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2501.ciunit = status_1.iofile;
    s_wsfe(&io___2501);
    do_fio(&c__1, (char *)&acgd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgd[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2502.ciunit = status_1.iofile;
    s_wsfe(&io___2502);
    do_fio(&c__1, (char *)&acgb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cgb[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2503.ciunit = status_1.iofile;
    s_wsfe(&io___2503);
    do_fio(&c__1, (char *)&acds, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cds[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L560:
    kntr = 0;
    if (loc != 0 && nodplc[loc + 32] == 0) {
	goto L530;
    }

/*  OPERATING POINT ANALYSES */

L600:
    if (status_1.modedc != 1) {
	goto L700;
    }
    if (dc_1.kinel == 0) {
	goto L610;
    }
    sstf_();
L610:
    if (tabinf_1.nsens == 0) {
	goto L700;
    }
    sencal_();

/*  FINISHED */

L700:
    if (status_1.modedc == 2) {
	goto L710;
    }
    if (ac_1.jacflg != 0) {
	goto L705;
    }
    clrmem_(&tabinf_1.lvnim1);
    clrmem_(&tabinf_1.lx0);
L705:
    clrmem_(&tabinf_1.lvn);
    clrmem_(&tabinf_1.lvntmp);
    if (memptr_(&tabinf_1.macins)) {
	clrmem_(&tabinf_1.macins);
    }
L710:
    second_(&t2);
    miscel_1.rstats[4] = miscel_1.rstats[4] + t2 - t1;
    return 0;
} /* dcop_ */

#undef cvalue
#undef nodplc
#undef betadc
#undef betaac
#undef vdsat
#undef cgsov
#undef cgbov
#undef cgdov
#undef cgsb
#undef cggb
#undef cgdb
#undef cbgb
#undef vth
#undef vgs
#undef vds
#undef vbs
#undef rpi
#undef req
#undef cds
#undef cmu
#undef cgs
#undef gds
#undef cbx
#undef vce
#undef vbe
#undef cpi
#undef vbc
#undef cbs
#undef ccs
#undef cap
#undef cgd
#undef cgb
#undef cbd
#undef av1
#undef ai1
#undef rx
#undef ro
#undef ft
#undef vd
#undef cg
#undef cd
#undef cc
#undef cb
#undef afmt4
#undef afmt3
#undef afmt2
#undef afmt1
#undef ablnk
#undef aft
#undef abetaa
#undef abetad
#undef arx
#undef acbx
#undef accs
#undef agmb
#undef agds
#undef agm
#undef avdsat
#undef avth
#undef acds
#undef acgb
#undef acbsb
#undef acbdb
#undef acbgb
#undef acgsb
#undef acgdb
#undef acggb
#undef acgbov
#undef acgdov
#undef acgsov
#undef acbs
#undef acbd
#undef acgd
#undef acgs
#undef acmu
#undef acpi
#undef acap
#undef aro
#undef arpi
#undef areq
#undef aig
#undef aic
#undef aib
#undef aid
#undef asrci
#undef asrcv
#undef avbs
#undef avds
#undef avgs
#undef avce
#undef avbc
#undef avbe
#undef avd
#undef optitl


/* Subroutine */ int sstf_(void)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2579 = { "/       ", 0. };

#define aslash (*(doublereal *)&equiv_2579)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2580 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_2580)


    /* Format strings */
    static char fmt_231[] = "(////,\0020****     SMALL-SIGNAL CHARACTERIST"
	    "ICS\002//,\0020\002,5x,5a8,\002 = \002,1pd10.3,/,\0020\002,5x"
	    ",\002INPUT RESISTANCE AT \002,a8,12x,\002 = \002,d10.3,/,\002"
	    "0\002,5x,\002OUTPUT RESISTANCE AT \002,2a8,a3,\002 = \002,d10.3)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k;
    static doublereal zin, anam, save[3];
    static integer locv;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static doublereal trfn;
    static integer ipos;
    static doublereal zout;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *),
	     zero8_(doublereal *, integer *);
    static doublereal creal;
    extern /* Subroutine */ int dcsol_(void);
    static integer iptri, iptro;
    extern /* Subroutine */ int dcdcmp_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal string[5];
    static integer noposi, nonegi, noposo, nonego;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___2578 = { 0, 0, 0, fmt_231, 0 };



/*     THIS ROUTINE COMPUTES THE VALUE OF THE SMALL-SIGNAL TRANSFER */
/* FUNCTION SPECIFIED BY THE USER. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



/*  SETUP CURRENT VECTOR FOR INPUT RESISTANCE AND TRANSFER FUNCTION */

    zero8_(&blank_1.value[(0 + (0 + (tabinf_1.lvn + 1 - 1 << 3))) / 8], &
	    cirdat_1.nstop);
    if (dc_1.kidin == 10) {
	goto L5;
    }
/* ...  VOLTAGE SOURCE INPUT */
    iptri = nodplc[dc_1.kinel + 5];
    blank_1.value[tabinf_1.lvn + iptri - 1] = 1.;
    goto L20;
/* ...  CURRENT SOURCE INPUT */
L5:
    noposi = nodplc[dc_1.kinel + 1];
    nonegi = nodplc[dc_1.kinel + 2];
    blank_1.value[tabinf_1.lvn + noposi - 1] = -1.;
    blank_1.value[tabinf_1.lvn + nonegi - 1] = 1.;

/*  LU DECOMPOSE AND SOLVE THE SYSTEM OF CIRCUIT EQUATIONS */

/* ...  REORDER THE RIGHT-HAND SIDE */
L20:
    dcdcmp_();
    dcsol_();
    blank_1.value[tabinf_1.lvn] = 0.;
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.icswpr + i__ - 1];
	k = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.lvntmp + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
/* L25: */
    }
    copy8_(&blank_1.value[tabinf_1.lvntmp], &blank_1.value[tabinf_1.lvn], &
	    cirdat_1.nstop);

/*  EVALUATE TRANSFER FUNCTION */

    if (nodplc[dc_1.kovar + 4] != 0) {
	goto L30;
    }
/* ...  VOLTAGE OUTPUT */
    noposo = nodplc[dc_1.kovar + 1];
    nonego = nodplc[dc_1.kovar + 2];
    trfn = blank_1.value[tabinf_1.lvn + noposo - 1] - blank_1.value[
	    tabinf_1.lvn + nonego - 1];
    goto L40;
/* ...  CURRENT OUTPUT (THROUGH VOLTAGE SOURCE) */
L30:
    iptro = nodplc[dc_1.kovar + 1];
    iptro = nodplc[iptro + 5];
    trfn = blank_1.value[tabinf_1.lvn + iptro - 1];

/*  EVALUATE INPUT RESISTANCE */

L40:
    if (dc_1.kidin == 9) {
	goto L50;
    }
/* ...  CURRENT SOURCE INPUT */
    zin = blank_1.value[tabinf_1.lvn + nonegi - 1] - blank_1.value[
	    tabinf_1.lvn + noposi - 1];
    goto L70;
/* ...  VOLTAGE SOURCE INPUT */
L50:
    creal = blank_1.value[tabinf_1.lvn + iptri - 1];
    if (abs(creal) >= 1e-20) {
	goto L60;
    }
    zin = 1e20;
    goto L70;
L60:
    zin = -1. / creal;

/*  SETUP CURRENT VECTOR FOR OUTPUT RESISTANCE */

L70:
    zero8_(&blank_1.value[tabinf_1.lvn], &cirdat_1.nstop);
    if (nodplc[dc_1.kovar + 4] != 0) {
	goto L80;
    }
/* ...  VOLTAGE OUTPUT */
    blank_1.value[tabinf_1.lvn + noposo - 1] = -1.;
    blank_1.value[tabinf_1.lvn + nonego - 1] = 1.;
    goto L90;
L80:
    if (nodplc[dc_1.kovar + 1] != dc_1.kinel) {
	goto L85;
    }
    zout = zin;
    goto L200;
/* ...  CURRENT OUTPUT (THROUGH VOLTAGE SOURCE) */
L85:
    blank_1.value[tabinf_1.lvn + iptro - 1] = 1.;

/*  PERFORM NEW FORWARD AND BACKWARD SUBSTITUTION */

/* ...  REORDER THE RIGHT-HAND SIDE */
L90:
    dcsol_();
    blank_1.value[tabinf_1.lvn] = 0.;
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.icswpr + i__ - 1];
	k = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.lvntmp + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
/* L95: */
    }
    copy8_(&blank_1.value[tabinf_1.lvntmp], &blank_1.value[tabinf_1.lvn], &
	    cirdat_1.nstop);

/*  EVALUATE OUTPUT RESISTANCE */

/* L100: */
    if (nodplc[dc_1.kovar + 4] != 0) {
	goto L110;
    }
/* ...  VOLTAGE OUTPUT */
    zout = blank_1.value[tabinf_1.lvn + nonego - 1] - blank_1.value[
	    tabinf_1.lvn + noposo - 1];
    goto L200;
/* ...  CURRENT OUTPUT (THROUGH VOLTAGE SOURCE) */
L110:
    creal = blank_1.value[tabinf_1.lvn + iptro - 1];
    if (abs(creal) >= 1e-20) {
	goto L120;
    }
    zout = 1e20;
    goto L200;
L120:
    zout = -1. / creal;

/*  PRINT RESULTS */

L200:
    for (i__ = 1; i__ <= 5; ++i__) {
	string[i__ - 1] = ablnk;
/* L210: */
    }
    ipos = 1;
    outnam_(&dc_1.kovar, &c__1, string, &ipos);
    copy8_(string, save, &c__3);
    move_(string, &ipos, &aslash, &c__1, &c__1);
    ++ipos;
    locv = nodplc[dc_1.kinel];
    anam = blank_1.value[locv - 1];
    move_(string, &ipos, &anam, &c__1, &c__8);
    io___2578.ciunit = status_1.iofile;
    s_wsfe(&io___2578);
    do_fio(&c__5, (char *)&string[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&trfn, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&anam, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zin, (ftnlen)sizeof(doublereal));
    do_fio(&c__3, (char *)&save[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zout, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* sstf_ */

#undef cvalue
#undef nodplc
#undef ablnk
#undef aslash


/* Subroutine */ int sencal_(void)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2705 = { "RS      ", 0. };

#define alsrs (*(doublereal *)&equiv_2705)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2706 = { "IS      ", 0. };

#define alsis (*(doublereal *)&equiv_2706)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2707 = { "N       ", 0. };

#define alsn (*(doublereal *)&equiv_2707)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2708 = { "RB      ", 0. };

#define alsrb (*(doublereal *)&equiv_2708)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2709 = { "RC      ", 0. };

#define alsrc (*(doublereal *)&equiv_2709)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2710 = { "RE      ", 0. };

#define alsre (*(doublereal *)&equiv_2710)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2711 = { "BF      ", 0. };

#define alsbf (*(doublereal *)&equiv_2711)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2712 = { "ISE     ", 0. };

#define alsise (*(doublereal *)&equiv_2712)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2713 = { "BR      ", 0. };

#define alsbr (*(doublereal *)&equiv_2713)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2714 = { "ISC     ", 0. };

#define alsisc (*(doublereal *)&equiv_2714)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2715 = { "NE      ", 0. };

#define alsne (*(doublereal *)&equiv_2715)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2716 = { "NC      ", 0. };

#define alsnc (*(doublereal *)&equiv_2716)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2717 = { "IKF     ", 0. };

#define alsik (*(doublereal *)&equiv_2717)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2718 = { "IKR     ", 0. };

#define alsikr (*(doublereal *)&equiv_2718)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2719 = { "VAF     ", 0. };

#define alsva (*(doublereal *)&equiv_2719)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2720 = { "JS      ", 0. };

#define alsjs (*(doublereal *)&equiv_2720)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_2721 = { "DC SENSITIVITY ANALYSIS         ", 0. };

#define sentit ((doublereal *)&equiv_2721)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2722 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_2722)


    /* Format strings */
    static char fmt_36[] = "(\0020DC SENSITIVITIES OF OUTPUT \002,5a8)";
    static char fmt_41[] = "(\0020\002,8x,\002ELEMENT\002,9x,\002ELEMENT\002"
	    ",7x,\002ELEMENT\002,7x,\002NORMALIZED\002/10x,\002NAME\002,12x"
	    ",\002VALUE\002,6x,\002SENSITIVITY    SENSITIVITY\002/35x,\002 (V"
	    "OLTS/UNIT) (VOLTS/PERCENT)\002/)";
    static char fmt_42[] = "(\0020\002,8x,\002ELEMENT\002,9x,\002ELEMENT\002"
	    ",7x,\002ELEMENT\002,7x,\002NORMALIZED\002/10x,\002NAME\002,12x"
	    ",\002VALUE\002,6x,\002SENSITIVITY    SENSITIVITY\002/35x,\002  ("
	    "AMPS/UNIT)  (AMPS/PERCENT)\002/)";
    static char fmt_101[] = "(10x,a8,4x,1pd10.3,5x,d10.3,5x,d10.3)";
    static char fmt_181[] = "(1x,a8)";
    static char fmt_186[] = "(10x,a8,5x,\0020.\002,13x,\0020.\002,13x,\0020"
	    ".\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double exp(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer j, n;
    static doublereal q1, q2, bf, qb, br, va, vb, xn, dq1, dq2, cbc, cbe, gbc,
	     gbe, dqb, vbc;
    static integer loc;
    static doublereal vbe;
    static integer isc, ise;
    static doublereal val, oik, ova, ovb, xnc, xne, vtc, vte, cbcn, cben, 
	    area, vabc, gben, vabe, vace, evbc, gbcn, evbe;
    static integer locm;
    static doublereal csat;
    static integer locs;
    extern /* Subroutine */ int asol_(void);
    static integer ipos;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer locv;
    static doublereal sens, type__;
    static integer loct;
    static doublereal oikr;
    static integer node1, node2, node3, node4, node5, node6;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static integer iptro;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer jstop;
    static doublereal sensn;
    static integer iptrv;
    static doublereal evben, evbcn, sqarg, alsvb;
    extern /* Subroutine */ int dcdcmp_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal string[5];
    static integer ioutyp, ivolts, noposo, nonego;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___2612 = { 0, 0, 0, fmt_36, 0 };
    static cilist io___2614 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___2615 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___2623 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2625 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2626 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2627 = { 0, 0, 0, fmt_181, 0 };
    static cilist io___2631 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2632 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2639 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2640 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2641 = { 0, 0, 0, fmt_181, 0 };
    static cilist io___2647 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2648 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2649 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2650 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2651 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2652 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2685 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2686 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2687 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2688 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2689 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2690 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2691 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2692 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2693 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2694 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2695 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2696 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2697 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2698 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2700 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___2701 = { 0, 0, 0, fmt_186, 0 };
    static cilist io___2704 = { 0, 0, 0, fmt_101, 0 };



/*     THIS ROUTINE COMPUTES THE DC SENSITIVITIES OF CIRCUIT ELEMENTS */
/* WITH RESPECT TO USER SPECIFIED OUTPUTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    if (dc_1.kinel != 0) {
	goto L8;
    }
/* L4: */
    dcdcmp_();


L8:
    i__1 = tabinf_1.nsens;
    for (n = 1; n <= i__1; ++n) {

/*  PREPARE ADJOINT EXCITATION VECTOR */

	zero8_(&blank_1.value[tabinf_1.lvn], &cirdat_1.nstop);
	locs = nodplc[tabinf_1.isens + n - 1];
	ioutyp = nodplc[locs + 4];
	if (ioutyp != 0) {
	    goto L10;
	}
/* ...  VOLTAGE OUTPUT */
	ivolts = 1;
	noposo = nodplc[locs + 1];
	nonego = nodplc[locs + 2];
	blank_1.value[tabinf_1.lvn + noposo - 1] = -1.;
	blank_1.value[tabinf_1.lvn + nonego - 1] = 1.;
	goto L20;
/* ...  CURRENT OUTPUT (THROUGH VOLTAGE SOURCE) */
L10:
	iptro = nodplc[locs + 1];
	ivolts = 0;
	iptro = nodplc[iptro + 5];
	blank_1.value[tabinf_1.lvn + iptro - 1] = -1.;

/*  OBTAIN ADJOINT SOLUTION BY DOING FORWARD/BACKWARD SUBSTITUTION ON */
/*  THE TRANSPOSE OF THE Y MATRIX */

L20:
	asol_();
	blank_1.value[tabinf_1.lvn] = 0.;

/*  REAL SOLUTION IN LVNIM1;  ADJOINT SOLUTION IN LVN ... */

	title_(&c__0, &miscel_1.lwidth, &c__1, sentit);
	ipos = 1;
	outnam_(&locs, &c__1, string, &ipos);
	move_(string, &ipos, &ablnk, &c__1, &c__7);
	jstop = (ipos + 6) / 8;
	io___2612.ciunit = status_1.iofile;
	s_wsfe(&io___2612);
	i__2 = jstop;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&string[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	if (ivolts != 0) {
	    io___2614.ciunit = status_1.iofile;
	    s_wsfe(&io___2614);
	    e_wsfe();
	}
	if (ivolts == 0) {
	    io___2615.ciunit = status_1.iofile;
	    s_wsfe(&io___2615);
	    e_wsfe();
	}

/*  RESISTORS */

	loc = cirdat_1.locate[0];
L100:
	if (loc == 0 || nodplc[loc + 7] != 0) {
	    goto L110;
	}
	locv = nodplc[loc];
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	val = 1. / blank_1.value[locv];
	sens = -(blank_1.value[tabinf_1.lvnim1 + node1 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node2 - 1]) * (blank_1.value[tabinf_1.lvn + 
		node1 - 1] - blank_1.value[tabinf_1.lvn + node2 - 1]) / (val *
		 val);
	sensn = val * sens / 100.;
	io___2623.ciunit = status_1.iofile;
	s_wsfe(&io___2623);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L105: */
	loc = nodplc[loc - 1];
	goto L100;

/*  VOLTAGE SOURCES */

L110:
	loc = cirdat_1.locate[8];
L140:
	if (loc == 0 || nodplc[loc + 10] != 0) {
	    goto L150;
	}
	locv = nodplc[loc];
	val = blank_1.value[locv];
	iptrv = nodplc[loc + 5];
	sens = -blank_1.value[tabinf_1.lvn + iptrv - 1];
	sensn = val * sens / 100.;
	io___2625.ciunit = status_1.iofile;
	s_wsfe(&io___2625);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L145: */
	loc = nodplc[loc - 1];
	goto L140;

/*  CURRENT SOURCES */

L150:
	loc = cirdat_1.locate[9];
L160:
	if (loc == 0 || nodplc[loc + 5] != 0) {
	    goto L170;
	}
	locv = nodplc[loc];
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	val = blank_1.value[locv];
	sens = blank_1.value[tabinf_1.lvn + node1 - 1] - blank_1.value[
		tabinf_1.lvn + node2 - 1];
	sensn = val * sens / 100.;
	io___2626.ciunit = status_1.iofile;
	s_wsfe(&io___2626);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L165: */
	loc = nodplc[loc - 1];
	goto L160;

/*  DIODES */

L170:
	loc = cirdat_1.locate[10];
L180:
	if (loc == 0 || nodplc[loc + 15] != 0) {
	    goto L210;
	}
	locv = nodplc[loc];
	io___2627.ciunit = status_1.iofile;
	s_wsfe(&io___2627);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	node3 = nodplc[loc + 3];
	locm = nodplc[loc + 4];
	locm = nodplc[locm];
	area = blank_1.value[locv];

/*  SERIES RESISTANCE (RS) */

	val = blank_1.value[locm + 1] * area;
	if (val != 0.) {
	    goto L190;
	}
	io___2631.ciunit = status_1.iofile;
	s_wsfe(&io___2631);
	do_fio(&c__1, (char *)&alsrs, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L200;
L190:
	val = 1. / val;
	sens = -(blank_1.value[tabinf_1.lvnim1 + node1 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node3 - 1]) * (blank_1.value[tabinf_1.lvn + 
		node1 - 1] - blank_1.value[tabinf_1.lvn + node3 - 1]) / (val *
		 val);
	sensn = val * sens / 100.;
	io___2632.ciunit = status_1.iofile;
	s_wsfe(&io___2632);
	do_fio(&c__1, (char *)&alsrs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  INTRINSIC PARAMETERS */

L200:
	csat = blank_1.value[locm] * area;
	xn = blank_1.value[locm + 2];
	vbe = blank_1.value[tabinf_1.lvnim1 + node3 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node2 - 1];
	vte = xn * status_1.vt;
	evbe = exp(vbe / vte);
	vabe = blank_1.value[tabinf_1.lvn + node3 - 1] - blank_1.value[
		tabinf_1.lvn + node2 - 1];

/*  SATURATION CURRENT (IS) */

	sens = vabe * (evbe - 1.);
	sensn = csat * sens / 100.;
	io___2639.ciunit = status_1.iofile;
	s_wsfe(&io___2639);
	do_fio(&c__1, (char *)&alsis, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&csat, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  IDEALITY FACTOR (N) */

	sens = -vabe * (csat / xn) * (vbe / vte) * evbe;
	if (abs(sens) < 1e-30) {
	    sens = 0.;
	}
	sensn = xn * sens / 100.;
	io___2640.ciunit = status_1.iofile;
	s_wsfe(&io___2640);
	do_fio(&c__1, (char *)&alsn, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xn, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L205: */
	loc = nodplc[loc - 1];
	goto L180;

/*  BIPOLAR JUNCTION TRANSISTORS */

L210:
	loc = cirdat_1.locate[11];
L220:
	if (loc == 0 || nodplc[loc + 35] != 0) {
	    goto L1000;
	}
	locv = nodplc[loc];
	io___2641.ciunit = status_1.iofile;
	s_wsfe(&io___2641);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	node3 = nodplc[loc + 3];
	node4 = nodplc[loc + 4];
	node5 = nodplc[loc + 5];
	node6 = nodplc[loc + 6];
	locm = nodplc[loc + 7];
	type__ = (doublereal) nodplc[locm + 1];
	locm = nodplc[locm];
	loct = tabinf_1.lx0 + nodplc[loc + 21];
	area = blank_1.value[locv];

/*  BASE RESISTANCE (RB) */

	val = blank_1.value[loct + 15];
	if (val != 0.) {
	    goto L230;
	}
	io___2647.ciunit = status_1.iofile;
	s_wsfe(&io___2647);
	do_fio(&c__1, (char *)&alsrb, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L240;
L230:
	val = 1. / val;
	sens = -(blank_1.value[tabinf_1.lvnim1 + node2 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node5 - 1]) * (blank_1.value[tabinf_1.lvn + 
		node2 - 1] - blank_1.value[tabinf_1.lvn + node5 - 1]) / (val *
		 val);
	sensn = val * sens / 100.;
	io___2648.ciunit = status_1.iofile;
	s_wsfe(&io___2648);
	do_fio(&c__1, (char *)&alsrb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  COLLECTOR RESISTANCE (RC) */

L240:
	val = blank_1.value[locm + 19] * area;
	if (val != 0.) {
	    goto L250;
	}
	io___2649.ciunit = status_1.iofile;
	s_wsfe(&io___2649);
	do_fio(&c__1, (char *)&alsrc, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L260;
L250:
	val = 1. / val;
	sens = -(blank_1.value[tabinf_1.lvnim1 + node1 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node4 - 1]) * (blank_1.value[tabinf_1.lvn + 
		node1 - 1] - blank_1.value[tabinf_1.lvn + node4 - 1]) / (val *
		 val);
	sensn = val * sens / 100.;
	io___2650.ciunit = status_1.iofile;
	s_wsfe(&io___2650);
	do_fio(&c__1, (char *)&alsrc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  EMITTER RESISTANCE (RE) */

L260:
	val = blank_1.value[locm + 18] * area;
	if (val != 0.) {
	    goto L270;
	}
	io___2651.ciunit = status_1.iofile;
	s_wsfe(&io___2651);
	do_fio(&c__1, (char *)&alsre, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L280;
L270:
	val = 1. / val;
	sens = -(blank_1.value[tabinf_1.lvnim1 + node3 - 1] - blank_1.value[
		tabinf_1.lvnim1 + node6 - 1]) * (blank_1.value[tabinf_1.lvn + 
		node3 - 1] - blank_1.value[tabinf_1.lvn + node6 - 1]) / (val *
		 val);
	sensn = val * sens / 100.;
	io___2652.ciunit = status_1.iofile;
	s_wsfe(&io___2652);
	do_fio(&c__1, (char *)&alsre, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  INTRINSIC PARAMETERS */

L280:
	bf = blank_1.value[locm + 1];
	br = blank_1.value[locm + 7];
	csat = blank_1.value[locm] * area;
	ova = blank_1.value[locm + 3];
	ovb = blank_1.value[locm + 9];
	oik = blank_1.value[locm + 4] / area;
	ise = (integer) (blank_1.value[locm + 5] * area);
	xne = blank_1.value[locm + 6];
	vte = xne * status_1.vt;
	oikr = blank_1.value[locm + 10] / area;
	isc = (integer) (blank_1.value[locm + 11] * area);
	xnc = blank_1.value[locm + 12];
	vtc = xnc * status_1.vt;
	vbe = type__ * (blank_1.value[tabinf_1.lvnim1 + node5 - 1] - 
		blank_1.value[tabinf_1.lvnim1 + node6 - 1]);
	vbc = type__ * (blank_1.value[tabinf_1.lvnim1 + node5 - 1] - 
		blank_1.value[tabinf_1.lvnim1 + node4 - 1]);
	vabe = type__ * (blank_1.value[tabinf_1.lvn + node5 - 1] - 
		blank_1.value[tabinf_1.lvn + node6 - 1]);
	vabc = type__ * (blank_1.value[tabinf_1.lvn + node5 - 1] - 
		blank_1.value[tabinf_1.lvn + node4 - 1]);
	vace = vabe - vabc;
	if (vbe <= -status_1.vt) {
	    goto L320;
	}
	evbe = exp(vbe / status_1.vt / blank_1.value[locm + 2]);
	cbe = csat * (evbe - 1.);
	gbe = csat * evbe / status_1.vt / blank_1.value[locm + 2];
	if ((doublereal) ise != 0.) {
	    goto L310;
	}
	cben = 0.;
	gben = 0.;
	goto L350;
L310:
	evben = exp(vbe / vte);
	cben = ise * (evben - 1.);
	gben = ise * evben / vte;
	goto L350;
L320:
	gbe = -csat / vbe;
	cbe = gbe * vbe;
	gben = -ise / vbe;
	cben = gben * vbe;
L350:
	if (vbc <= -status_1.vt) {
	    goto L370;
	}
	evbc = exp(vbc / status_1.vt / blank_1.value[locm + 8]);
	cbc = csat * (evbc - 1.);
	gbc = csat * evbc / status_1.vt / blank_1.value[locm + 8];
	if ((doublereal) isc != 0.) {
	    goto L360;
	}
	cbcn = 0.;
	gbcn = 0.;
	goto L400;
L360:
	evbcn = exp(vbc / vtc);
	cbcn = isc * (evbcn - 1.);
	gbcn = isc * evbcn / vtc;
	goto L400;
L370:
	gbc = -csat / vbc;
	cbc = gbc * vbc;
	gbcn = -isc / vbc;
	cbcn = gbcn * vbc;
L400:
	q1 = 1. / (1. - ova * vbc - ovb * vbe);
	q2 = oik * cbe + oikr * cbc;
	sqarg = sqrt(q2 * 4. + 1.);
	qb = q1 * (sqarg + 1.) / 2.;
	dqb = (cbe - cbc) / (qb * qb);
	sqarg = sqrt(q2 * 4. + 1.);
	dq1 = dqb * (sqarg + 1.) / 2.;
	dq2 = q1 * dqb / sqarg;

/*  COMPUTE SENSITIVITIES */

/* ...  BF */
	sens = -vabe * cbe / bf / bf;
	sensn = bf * sens / 100.;
	io___2685.ciunit = status_1.iofile;
	s_wsfe(&io___2685);
	do_fio(&c__1, (char *)&alsbf, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&bf, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  ISE */
	if ((doublereal) ise != 0.) {
	    goto L430;
	}
	io___2686.ciunit = status_1.iofile;
	s_wsfe(&io___2686);
	do_fio(&c__1, (char *)&alsise, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L440;
L430:
	sens = vabe * cben / ise;
	sensn = ise * sens / 100.;
	io___2687.ciunit = status_1.iofile;
	s_wsfe(&io___2687);
	do_fio(&c__1, (char *)&alsise, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ise, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  BR */
L440:
	sens = -vabc * cbc / br / br;
	sensn = br * sens / 100.;
	io___2688.ciunit = status_1.iofile;
	s_wsfe(&io___2688);
	do_fio(&c__1, (char *)&alsbr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&br, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  ISC */
	if ((doublereal) isc != 0.) {
	    goto L450;
	}
	io___2689.ciunit = status_1.iofile;
	s_wsfe(&io___2689);
	do_fio(&c__1, (char *)&alsisc, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L460;
L450:
	sens = vabc * cbcn / isc;
	sensn = isc * sens / 100.;
	io___2690.ciunit = status_1.iofile;
	s_wsfe(&io___2690);
	do_fio(&c__1, (char *)&alsisc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&isc, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  IS */
L460:
	sens = (vabe * (cbe / bf) + vabc * (cbc / br) + vace * (dqb * qb - 
		dq2 * q2)) / csat;
	sensn = csat * sens / 100.;
	io___2691.ciunit = status_1.iofile;
	s_wsfe(&io___2691);
	do_fio(&c__1, (char *)&alsjs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&csat, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  NE */
	sens = -vabe * gben * vbe / xne;
	sensn = xne * sens / 100.;
	io___2692.ciunit = status_1.iofile;
	s_wsfe(&io___2692);
	do_fio(&c__1, (char *)&alsne, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xne, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  NC */
	sens = -vabc * gbcn * vbc / xnc;
	sensn = xnc * sens / 100.;
	io___2693.ciunit = status_1.iofile;
	s_wsfe(&io___2693);
	do_fio(&c__1, (char *)&alsnc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xnc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  IK */
	if (oik != 0.) {
	    goto L470;
	}
	io___2694.ciunit = status_1.iofile;
	s_wsfe(&io___2694);
	do_fio(&c__1, (char *)&alsik, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L480;
L470:
	val = 1. / oik;
	sens = vace * dq2 * cbe / (val * val);
	sensn = val * sens / 100.;
	io___2695.ciunit = status_1.iofile;
	s_wsfe(&io___2695);
	do_fio(&c__1, (char *)&alsik, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  IKR */
L480:
	if (oikr != 0.) {
	    goto L490;
	}
	io___2696.ciunit = status_1.iofile;
	s_wsfe(&io___2696);
	do_fio(&c__1, (char *)&alsikr, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L500;
L490:
	val = 1. / oikr;
	sens = vace * dq2 * cbc / (val * val);
	sensn = val * sens / 100.;
	io___2697.ciunit = status_1.iofile;
	s_wsfe(&io___2697);
	do_fio(&c__1, (char *)&alsikr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  VA */
L500:
	if (ova != 0.) {
	    goto L510;
	}
	io___2698.ciunit = status_1.iofile;
	s_wsfe(&io___2698);
	do_fio(&c__1, (char *)&alsva, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L520;
L510:
	va = 1. / ova;
	sens = vace * q1 * q1 * dq1 * vbc / (va * va);
	sensn = va * sens / 100.;
	io___2700.ciunit = status_1.iofile;
	s_wsfe(&io___2700);
	do_fio(&c__1, (char *)&alsva, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&va, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* ...  VB */
L520:
	if (ovb != 0.) {
	    goto L530;
	}
	io___2701.ciunit = status_1.iofile;
	s_wsfe(&io___2701);
	do_fio(&c__1, (char *)&alsvb, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L540;
L530:
	vb = 1. / ovb;
	sens = vace * q1 * q1 * dq1 * vbe / (vb * vb);
	sensn = vb * sens / 100.;
	io___2704.ciunit = status_1.iofile;
	s_wsfe(&io___2704);
	do_fio(&c__1, (char *)&alsvb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sens, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sensn, (ftnlen)sizeof(doublereal));
	e_wsfe();


L540:
	loc = nodplc[loc - 1];
	goto L220;

/*  FINISHED */

L1000:
	;
    }
    return 0;
} /* sencal_ */

#undef cvalue
#undef nodplc
#undef ablnk
#undef sentit
#undef alsjs
#undef alsva
#undef alsikr
#undef alsik
#undef alsnc
#undef alsne
#undef alsisc
#undef alsbr
#undef alsise
#undef alsbf
#undef alsre
#undef alsrc
#undef alsrb
#undef alsn
#undef alsis
#undef alsrs


/* Subroutine */ int asol_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, loc, iord, jord;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *);
    static integer locnn;
    extern integer indxx_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE EVALUATES THE ADJOINT CIRCUIT RESPONSE BY DOING A */
/* FORWARD/BACKWARD SUBSTITUTION ON THE TRANSPOSE OF THE COEFFICIENT */
/* MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  FORWARD SUBSTITUTION */

    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	iord = nodplc[tabinf_1.icswpf + i__ - 1];
	loc = i__;
L10:
	loc = nodplc[tabinf_1.irpt + loc - 1];
	if (nodplc[tabinf_1.irowno + loc - 1] >= i__) {
	    goto L15;
	}
	j = nodplc[tabinf_1.irowno + loc - 1];
	jord = nodplc[tabinf_1.icswpf + j - 1];
	blank_1.value[tabinf_1.lvn + iord - 1] -= blank_1.value[tabinf_1.lvn 
		+ loc - 1] * blank_1.value[tabinf_1.lvn + jord - 1];
	goto L10;
L15:
	jord = nodplc[tabinf_1.irswpf + i__ - 1];
	locnn = indxx_(&jord, &iord);
	blank_1.value[tabinf_1.lvn + iord - 1] /= blank_1.value[tabinf_1.lvn 
		+ locnn - 1];
/* L20: */
    }

/*  BACKWARD SUBSTITUTION */

    i__ = cirdat_1.nstop;
L30:
    --i__;
    if (i__ <= 1) {
	goto L60;
    }
    iord = nodplc[tabinf_1.icswpf + i__ - 1];
    loc = i__;
L35:
    loc = nodplc[tabinf_1.irpt + loc - 1];
/* L40: */
    if (nodplc[tabinf_1.irowno + loc - 1] != i__) {
	goto L35;
    }
L50:
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L30;
    }
    j = nodplc[tabinf_1.irowno + loc - 1];
    jord = nodplc[tabinf_1.icswpf + j - 1];
    blank_1.value[tabinf_1.lvn + iord - 1] -= blank_1.value[tabinf_1.lvn + 
	    loc - 1] * blank_1.value[tabinf_1.lvn + jord - 1];
    goto L50;

/*     REORDER SOLUTION VECTOR */

L60:
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.irswpr + i__ - 1];
	k = nodplc[tabinf_1.icswpf + j - 1];
	blank_1.value[tabinf_1.lvntmp + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
/* L70: */
    }
    copy8_(&blank_1.value[tabinf_1.lvntmp], &blank_1.value[tabinf_1.lvn], &
	    cirdat_1.nstop);

/*  FINISHED */

    return 0;
} /* asol_ */

#undef cvalue
#undef nodplc


/* SPICE VERSION 2G.6  SCCSID=acan.ma 3/15/83 */
/* Subroutine */ int acan_(void)
{
    /* Format strings */
    static char fmt_121[] = "(\0020WARNING:  UNDERFLOW \002,i4,\002 TIME(S) "
	    "IN AC ANALYSIS AT FREQ = \002,1pd9.3,\002 HZ\002)";
    static char fmt_901[] = "(\0020*ERROR*:  CPU TIME LIMIT EXCEEDED ... ANA"
	    "LYSIS STOPPED\002/)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2;
    complex q__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal t1, t2;
    static integer loc, loco;
    static doublereal freq;
    static integer iptr, node1, node2;
    extern /* Subroutine */ int getm8_(integer *, integer *);
    static integer nandd, ibuff;
    extern /* Subroutine */ int acsol_(void), getm16_(integer *, integer *), 
	    dinit_(void), noise_(integer *), copy16_(complex *, complex *, 
	    integer *), disto_(integer *), acload_(void), acdcmp_(void), 
	    getcje_(void), pheadr_(doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int second_(doublereal *);
    static integer numcur, numpos, loccur;
    extern /* Subroutine */ int crunch_(void);
    static integer numout, lcvntp;
    extern /* Subroutine */ int extmem_(integer *, integer *), dblsgl_(
	    complex *, integer *), fwrite_(), clsraw_(void), clrmem_(integer *
	    );

    /* Fortran I/O blocks */
    static cilist io___2744 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___2749 = { 0, 0, 0, fmt_901, 0 };



/*     THIS ROUTINE DRIVES THE SMALL-SIGNAL ANALYSES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CJE 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
    second_(&t1);
/* .. POST-PROCESSOR INITIALIZATION */
    if (status_1.ipostp == 0) {
	goto L1;
    }
    numcur = cirdat_1.jelcnt[8];
    numpos = cirdat_1.nunods + numcur;
    getm16_(&ibuff, &numpos);
    numpos <<= 2;
    if (numcur == 0) {
	goto L1;
    }
    loc = cirdat_1.locate[8];
    loccur = nodplc[loc + 5] - 1;

/*  ALLOCATE STORAGE */

L1:
    i__1 = cirdat_1.nstop << 1;
    getm8_(&tabinf_1.ndiag, &i__1);
    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    getm8_(&tabinf_1.lvn, &i__1);
    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    getm8_(&tabinf_1.imvn, &i__1);
    getm16_(&tabinf_1.lcvn, &cirdat_1.nstop);
    if (ac_1.idist != 0) {
	dinit_();
    }
    nandd = 0;
    if (ac_1.inoise == 0) {
	goto L10;
    }
    if (ac_1.idist == 0) {
	goto L10;
    }
    nandd = 1;
    getm16_(&tabinf_1.lvntmp, &cirdat_1.nstop);
L10:
    getm16_(&tabinf_1.loutpt, &c__0);
    crunch_();
    numout = cirdat_1.jelcnt[42] + cirdat_1.jelcnt[43] + cirdat_1.jelcnt[44] 
	    + 1;
    tabinf_1.lynl = tabinf_1.lvn;
    tabinf_1.imynl = tabinf_1.imvn;
    lcvntp = tabinf_1.lvntmp;
    status_1.icalc = 0;
    if (status_1.ipostp != 0) {
	pheadr_(miscel_1.atitle);
    }
    freq = ac_1.fstart;

/*  LOAD Y MATRIX AND C VECTOR, SOLVE FOR V VECTOR */

L100:
    getcje_();
    if (cje_1.maxtim - cje_1.itime <= flags_1.limtim) {
	goto L900;
    }
    status_1.omega = knstnt_1.twopi * freq;
    acload_();
/* L110: */
    acdcmp_();
    acsol_();
    if (flags_1.igoof == 0) {
	goto L200;
    }
    io___2744.ciunit = status_1.iofile;
    s_wsfe(&io___2744);
    do_fio(&c__1, (char *)&flags_1.igoof, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&freq, (ftnlen)sizeof(doublereal));
    e_wsfe();
    flags_1.igoof = 0;

/*  STORE OUTPUTS */

L200:
    extmem_(&tabinf_1.loutpt, &numout);
    loco = tabinf_1.loutpt + status_1.icalc * numout;
    ++status_1.icalc;
    i__1 = loco;
    r__1 = (real) freq;
    r__2 = (real) status_1.omega;
    q__1.r = r__1, q__1.i = r__2;
    cvalue[i__1].r = q__1.r, cvalue[i__1].i = q__1.i;
    loc = cirdat_1.locate[42];
L310:
    if (loc == 0) {
	goto L350;
    }
    if (nodplc[loc + 4] != 0) {
	goto L320;
    }
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    tabinf_1.iseq = nodplc[loc + 3];
    i__1 = loco + tabinf_1.iseq - 1;
    i__2 = tabinf_1.lcvn + node1 - 1;
    i__3 = tabinf_1.lcvn + node2 - 1;
    q__1.r = cvalue[i__2].r - cvalue[i__3].r, q__1.i = cvalue[i__2].i - 
	    cvalue[i__3].i;
    cvalue[i__1].r = q__1.r, cvalue[i__1].i = q__1.i;
    loc = nodplc[loc - 1];
    goto L310;
L320:
    iptr = nodplc[loc + 1];
    iptr = nodplc[iptr + 5];
    tabinf_1.iseq = nodplc[loc + 3];
    i__1 = loco + tabinf_1.iseq - 1;
    i__2 = tabinf_1.lcvn + iptr - 1;
    cvalue[i__1].r = cvalue[i__2].r, cvalue[i__1].i = cvalue[i__2].i;
    loc = nodplc[loc - 1];
    goto L310;
L350:
    if (status_1.ipostp == 0) {
	goto L400;
    }
    i__1 = ibuff;
    r__1 = (real) freq;
    q__1.r = r__1, q__1.i = 0.f;
    cvalue[i__1].r = q__1.r, cvalue[i__1].i = q__1.i;
    i__1 = cirdat_1.nunods - 1;
    copy16_(&cvalue[tabinf_1.lcvn + 1], &cvalue[ibuff + 1], &i__1);
    if (numcur != 0) {
	copy16_(&cvalue[tabinf_1.lcvn + loccur], &cvalue[ibuff + 
		cirdat_1.nunods], &numcur);
    }
    dblsgl_(&cvalue[ibuff], &numpos);
    fwrite_(&cvalue[ibuff], &numpos);

/*  NOISE AND DISTORTION ANALYSES */

L400:
    if (nandd == 0) {
	goto L410;
    }
    copy16_(&cvalue[tabinf_1.lcvn], &cvalue[lcvntp], &cirdat_1.nstop);
L410:
    if (ac_1.inoise != 0) {
	noise_(&loco);
    }
    if (nandd == 0) {
	goto L420;
    }
    copy16_(&cvalue[lcvntp], &cvalue[tabinf_1.lcvn], &cirdat_1.nstop);
L420:
    if (ac_1.idist != 0) {
	disto_(&loco);
    }

/*  INCREMENT FREQUENCY */

    if (status_1.icalc >= ac_1.jacflg) {
	goto L1000;
    }
    if (ac_1.idfreq >= 3) {
	goto L510;
    }
    freq *= ac_1.fincr;
    goto L100;
L510:
    freq += ac_1.fincr;
    goto L100;

/*  FINISHED */

L900:
    io___2749.ciunit = status_1.iofile;
    s_wsfe(&io___2749);
    e_wsfe();
    flags_1.nogo = 1;
L1000:
    if (status_1.ipostp == 0) {
	goto L1010;
    }
    if (status_1.ipostp != 0) {
	clsraw_();
    }
    if (status_1.ipostp != 0) {
	clrmem_(&ibuff);
    }
L1010:
    clrmem_(&tabinf_1.lvnim1);
    clrmem_(&tabinf_1.lx0);
    clrmem_(&tabinf_1.lvn);
    clrmem_(&tabinf_1.imvn);
    clrmem_(&tabinf_1.lcvn);
    clrmem_(&tabinf_1.ndiag);
    if (ac_1.idist == 0) {
	goto L1020;
    }
    clrmem_(&tabinf_1.ld0);
    clrmem_(&tabinf_1.ld1);
L1020:
    if (nandd == 0) {
	goto L1040;
    }
    clrmem_(&tabinf_1.lvntmp);
L1040:
    second_(&t2);
    miscel_1.rstats[6] = miscel_1.rstats[6] + t2 - t1;
    miscel_1.rstats[7] += status_1.icalc;
    return 0;
} /* acan_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int cdiv_(doublereal *xr, doublereal *xi, doublereal *yr, 
	doublereal *yi, doublereal *cr, doublereal *ci)
{
    static doublereal amag2, xitemp, yitemp, xrtemp, yrtemp;

/* .. OK IF CR AND CI ARE REALLY XR AND XI OR YR AND YI */
    xrtemp = *xr;
    xitemp = *xi;
    yrtemp = *yr;
    yitemp = *yi;
    amag2 = yrtemp * yrtemp + yitemp * yitemp;
    *cr = (xrtemp * yrtemp + xitemp * yitemp) / amag2;
    *ci = (xitemp * yrtemp - xrtemp * yitemp) / amag2;
    return 0;
} /* cdiv_ */

/* Subroutine */ int cmult_(doublereal *xr, doublereal *xi, doublereal *yr, 
	doublereal *yi, doublereal *cr, doublereal *ci)
{
    static doublereal xitemp, yitemp, xrtemp, yrtemp;

/* .. OK IF CR AND CI ARE REALLY XR AND XI OR YR AND YI */
    xrtemp = *xr;
    xitemp = *xi;
    yrtemp = *yr;
    yitemp = *yi;
    *cr = xrtemp * yrtemp - xitemp * yitemp;
    *ci = xitemp * yrtemp + xrtemp * yitemp;
    return 0;
} /* cmult_ */

/* Subroutine */ int acdcmp_(void)
{
    /* Format strings */
    static char fmt_11[] = "(\0020\002,\002 UNDERFLOW OCCURED AT STEP N= "
	    "\002,i5)";

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, n, n1, n2, locc;
    extern /* Subroutine */ int cdiv_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *);
    static integer locr, nxti, nxtj;
    static doublereal gdiag;
    static integer locij;
    static doublereal ximag;
    static integer locnn;
    static doublereal xreal;
    extern integer indxx_(integer *, integer *);
    extern /* Subroutine */ int cmult_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)

    /* Fortran I/O blocks */
    static cilist io___2769 = { 0, 0, 0, fmt_11, 0 };



/*     THIS ROUTINE PERFORMS AN LU FACTORIZATION OF THE CIRCUIT EQUATION */
/* COEFFICIENT MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */

    n = 1;
L10:
    ++n;
    nxti = n;
    nxtj = n;

/*     CALCULATE CONTRIBUTION FROM (NXTI,NXTJ) */

    if (n >= cirdat_1.nstop) {
	return 0;
    }
    n1 = nodplc[tabinf_1.irswpf + nxti - 1];
    n2 = nodplc[tabinf_1.icswpf + nxtj - 1];
    locnn = indxx_(&n1, &n2);
    gdiag = (d__1 = blank_1.value[tabinf_1.lynl + locnn - 1], abs(d__1)) + (
	    d__2 = blank_1.value[tabinf_1.imynl + locnn - 1], abs(d__2));
    if (gdiag >= knstnt_1.pivtol) {
	goto L20;
    }
    blank_1.value[tabinf_1.lynl + locnn - 1] = knstnt_1.pivtol;
    blank_1.value[tabinf_1.imynl + locnn - 1] = 0.;
    io___2769.ciunit = status_1.iofile;
    s_wsfe(&io___2769);
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    e_wsfe();

/*     DOWN COL J */

L20:
    locr = nodplc[tabinf_1.irpt + locnn - 1];
L25:
    if (locr == 0) {
	goto L10;
    }
    i__ = nodplc[tabinf_1.irowno + locr - 1];
    cdiv_(&blank_1.value[tabinf_1.lynl + locr - 1], &blank_1.value[
	    tabinf_1.imynl + locr - 1], &blank_1.value[tabinf_1.lynl + locnn 
	    - 1], &blank_1.value[tabinf_1.imynl + locnn - 1], &blank_1.value[
	    tabinf_1.lynl + locr - 1], &blank_1.value[tabinf_1.imynl + locr - 
	    1]);
    locc = nodplc[tabinf_1.jcpt + locnn - 1];

/*     FOR EACH ELEMENT LOOK UP ROW NXTI */

L30:
    if (locc == 0) {
	goto L70;
    }
    j = nodplc[tabinf_1.jcolno + locc - 1];

/*     LOCATE ELEMENT (I,J) */

/* L35: */
    if (j < i__) {
	goto L45;
    }
    locij = locc;
L40:
    locij = nodplc[tabinf_1.irpt + locij - 1];
    if (nodplc[tabinf_1.irowno + locij - 1] == i__) {
	goto L55;
    }
    goto L40;
L45:
    locij = locr;
L50:
    locij = nodplc[tabinf_1.jcpt + locij - 1];
    if (nodplc[tabinf_1.jcolno + locij - 1] == j) {
	goto L55;
    }
    goto L50;
L55:
    cmult_(&blank_1.value[tabinf_1.lynl + locc - 1], &blank_1.value[
	    tabinf_1.imynl + locc - 1], &blank_1.value[tabinf_1.lynl + locr - 
	    1], &blank_1.value[tabinf_1.imynl + locr - 1], &xreal, &ximag);
    blank_1.value[tabinf_1.lynl + locij - 1] -= xreal;
    blank_1.value[tabinf_1.imynl + locij - 1] -= ximag;
    locc = nodplc[tabinf_1.jcpt + locc - 1];
    goto L30;
L70:
    locr = nodplc[tabinf_1.irpt + locr - 1];
    goto L25;
} /* acdcmp_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int acsol_(void)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    complex q__1;

    /* Local variables */
    static integer i__, j, k, loc;
    extern /* Subroutine */ int cdiv_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *);
    static integer iord, jord;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *);
    static doublereal ximag;
    static integer locnn;
    static doublereal xreal;
    extern /* Subroutine */ int cmult_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *);
    extern integer indxx_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE SOLVES THE CIRCUIT EQUATIONS BY PERFORMING A FORWARD */
/* AND BACKWARD SUBSTITUTION USING THE PREVIOUSLY-COMPUTED LU FACTORS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  FORWARD SUBSTITUTION */

    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	loc = i__;
	iord = nodplc[tabinf_1.irswpf + i__ - 1];
L10:
	loc = nodplc[tabinf_1.jcpt + loc - 1];
	if (nodplc[tabinf_1.jcolno + loc - 1] >= i__) {
	    goto L20;
	}
	j = nodplc[tabinf_1.jcolno + loc - 1];
	jord = nodplc[tabinf_1.irswpf + j - 1];
	cmult_(&blank_1.value[tabinf_1.lynl + loc - 1], &blank_1.value[
		tabinf_1.imynl + loc - 1], &blank_1.value[tabinf_1.lvn + jord 
		- 1], &blank_1.value[tabinf_1.imvn + jord - 1], &xreal, &
		ximag);
	blank_1.value[tabinf_1.lvn + iord - 1] -= xreal;
	blank_1.value[tabinf_1.imvn + iord - 1] -= ximag;
	goto L10;
L20:
	;
    }

/*      BACK SUBSTITUTION */

    i__ = cirdat_1.nstop;
    iord = nodplc[tabinf_1.irswpf + i__ - 1];
    jord = nodplc[tabinf_1.icswpf + i__ - 1];
    locnn = indxx_(&iord, &jord);
L30:
    cdiv_(&blank_1.value[tabinf_1.lvn + iord - 1], &blank_1.value[
	    tabinf_1.imvn + iord - 1], &blank_1.value[tabinf_1.lynl + locnn - 
	    1], &blank_1.value[tabinf_1.imynl + locnn - 1], &blank_1.value[
	    tabinf_1.lvn + iord - 1], &blank_1.value[tabinf_1.imvn + iord - 1]
	    );
    --i__;
    if (i__ <= 1) {
	goto L60;
    }
    iord = nodplc[tabinf_1.irswpf + i__ - 1];
    loc = i__;
L35:
    loc = nodplc[tabinf_1.jcpt + loc - 1];
/* L40: */
    if (nodplc[tabinf_1.jcolno + loc - 1] != i__) {
	goto L35;
    }
    locnn = loc;
L50:
    loc = nodplc[tabinf_1.jcpt + loc - 1];
    if (loc == 0) {
	goto L30;
    }
    j = nodplc[tabinf_1.jcolno + loc - 1];
    jord = nodplc[tabinf_1.irswpf + j - 1];
    cmult_(&blank_1.value[tabinf_1.lynl + loc - 1], &blank_1.value[
	    tabinf_1.imynl + loc - 1], &blank_1.value[tabinf_1.lvn + jord - 1]
	    , &blank_1.value[tabinf_1.imvn + jord - 1], &xreal, &ximag);
    blank_1.value[tabinf_1.lvn + iord - 1] -= xreal;
    blank_1.value[tabinf_1.imvn + iord - 1] -= ximag;
    goto L50;

/*  REORDER SOLUTION VECTOR */

L60:
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.icswpr + i__ - 1];
	k = nodplc[tabinf_1.irswpf + j - 1];
	blank_1.value[tabinf_1.ndiag + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
	blank_1.value[tabinf_1.ndiag + i__ + cirdat_1.nstop - 1] = 
		blank_1.value[tabinf_1.imvn + k - 1];
/* L70: */
    }
    copy8_(&blank_1.value[tabinf_1.ndiag], &blank_1.value[tabinf_1.lvn], &
	    cirdat_1.nstop);
    copy8_(&blank_1.value[tabinf_1.ndiag + 1 + cirdat_1.nstop - 1], &
	    blank_1.value[tabinf_1.imvn], &cirdat_1.nstop);
    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = tabinf_1.lcvn + i__ - 1;
	r__1 = (real) blank_1.value[tabinf_1.lvn + i__ - 1];
	r__2 = (real) blank_1.value[tabinf_1.imvn + i__ - 1];
	q__1.r = r__1, q__1.i = r__2;
	cvalue[i__2].r = q__1.r, cvalue[i__2].i = q__1.i;
/* L120: */
    }
    i__1 = tabinf_1.lcvn;
    cvalue[i__1].r = 0.f, cvalue[i__1].i = 0.f;

/*  FINISHED */

    return 0;
} /* acsol_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int acload_(void)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal y0, z0, gm, go, td, gx, xl, xw, gbd, gcd, gcg, ggd, arg,
	     gbs;
    static integer loc;
    static doublereal geq, gpi, gds, val, ggs, xgd, gcs, gmu, xbd, xgm, xqc, 
	    xgs, xbs, cbdb, cbgb, cgdb, cggb, area, cbsb, cgsb, xcgb, xcgd;
    static integer ndim;
    static doublereal gmbs;
    static integer locm;
    static doublereal gcpr, gdpr;
    static integer lmat, locv, loct, locy;
    static doublereal xceq, gspr, gepr;
    static integer iptr;
    static doublereal xcpi, xcmu, xcbx, xccs, xnrm, xrev, xqco, xcgs, rval, 
	    xval;
    static integer node1, node2;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static doublereal capbd, xcddb, xcbgb, xcdgb, capbs, xcmcb, xcggb, xcgdb, 
	    xcdsb, xcsdb, xcsgb, xcgsb, xcbdb, xcdxd, xcbsb, xcgxd;
    static integer locyi, itype;
    static doublereal xcgxs, xcdxs, xcsxd, xcssb, xcsxs, devmod;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal covlgs, covlgd, covlgb;


/*     THIS ROUTINE ZEROES-OUT AND THEN LOADS THE COMPLEX COEFFICIENT */
/*     MATRIX */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */



/*  ZERO Y MATRIX AND CURRENT VECTOR */

    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    zero8_(&blank_1.value[tabinf_1.lvn], &i__1);
    i__1 = cirdat_1.nstop + tabinf_1.nttbr;
    zero8_(&blank_1.value[tabinf_1.imvn], &i__1);

/*  RESISTORS */

    loc = cirdat_1.locate[0];
L20:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L30;
    }
    locv = nodplc[loc];
    val = blank_1.value[locv];
    locy = tabinf_1.lynl + nodplc[loc + 5];
    blank_1.value[locy - 1] += val;
    locy = tabinf_1.lynl + nodplc[loc + 6];
    blank_1.value[locy - 1] += val;
    locy = tabinf_1.lynl + nodplc[loc + 3];
    blank_1.value[locy - 1] -= val;
    locy = tabinf_1.lynl + nodplc[loc + 4];
    blank_1.value[locy - 1] -= val;
    loc = nodplc[loc - 1];
    goto L20;

/*  CAPACITORS */

L30:
    loc = cirdat_1.locate[1];
L40:
    if (loc == 0 || nodplc[loc + 11] != 0) {
	goto L50;
    }
    locv = nodplc[loc];
    val = status_1.omega * blank_1.value[locv];
    locyi = tabinf_1.imynl + nodplc[loc + 9];
    blank_1.value[locyi - 1] += val;
    locyi = tabinf_1.imynl + nodplc[loc + 10];
    blank_1.value[locyi - 1] += val;
    locyi = tabinf_1.imynl + nodplc[loc + 4];
    blank_1.value[locyi - 1] -= val;
    locyi = tabinf_1.imynl + nodplc[loc + 5];
    blank_1.value[locyi - 1] -= val;
    loc = nodplc[loc - 1];
    goto L40;

/*  INDUCTORS */

L50:
    loc = cirdat_1.locate[2];
L60:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L70;
    }
    locv = nodplc[loc];
    val = status_1.omega * blank_1.value[locv];
    locyi = tabinf_1.imynl + nodplc[loc + 12];
    locy = tabinf_1.lynl + nodplc[loc + 12];
    blank_1.value[locy - 1] = 0.;
    blank_1.value[locyi - 1] = -val;
    locy = tabinf_1.lynl + nodplc[loc + 5];
    locyi = tabinf_1.imynl + nodplc[loc + 5];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 6];
    locyi = tabinf_1.imynl + nodplc[loc + 6];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 7];
    locyi = tabinf_1.imynl + nodplc[loc + 7];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 8];
    locyi = tabinf_1.imynl + nodplc[loc + 8];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    loc = nodplc[loc - 1];
    goto L60;

/*  MUTUAL INDUCTORS */

L70:
    loc = cirdat_1.locate[3];
L80:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L90;
    }
    locv = nodplc[loc];
    val = status_1.omega * blank_1.value[locv];
    locy = tabinf_1.lynl + nodplc[loc + 3];
    locyi = tabinf_1.imynl + nodplc[loc + 3];
    blank_1.value[locy - 1] = 0.;
    blank_1.value[locyi - 1] = -val;
    locy = tabinf_1.lynl + nodplc[loc + 4];
    locyi = tabinf_1.imynl + nodplc[loc + 4];
    blank_1.value[locy - 1] = 0.;
    blank_1.value[locyi - 1] = -val;
    loc = nodplc[loc - 1];
    goto L80;

/*  NONLINEAR VOLTAGE CONTROLLED CURRENT SOURCES */

L90:
    loc = cirdat_1.locate[4];
L95:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L100;
    }
    ndim = nodplc[loc + 3];
    lmat = nodplc[loc + 6];
    loct = tabinf_1.lx0 + nodplc[loc + 11] + 2;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	val = blank_1.value[loct - 1];
	loct += 2;
	locy = tabinf_1.lynl + nodplc[lmat];
	blank_1.value[locy - 1] += val;
	locy = tabinf_1.lynl + nodplc[lmat + 1];
	blank_1.value[locy - 1] -= val;
	locy = tabinf_1.lynl + nodplc[lmat + 2];
	blank_1.value[locy - 1] -= val;
	locy = tabinf_1.lynl + nodplc[lmat + 3];
	blank_1.value[locy - 1] += val;
	lmat += 4;
/* L97: */
    }
    loc = nodplc[loc - 1];
    goto L95;

/*  NONLINEAR VOLTAGE CONTROLLED VOLTAGE SOURCES */

L100:
    loc = cirdat_1.locate[5];
L105:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L110;
    }
    ndim = nodplc[loc + 3];
    lmat = nodplc[loc + 7];
    loct = tabinf_1.lx0 + nodplc[loc + 12] + 3;
    locy = tabinf_1.lynl + nodplc[lmat];
    locyi = tabinf_1.imynl + nodplc[lmat];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 1];
    locyi = tabinf_1.imynl + nodplc[lmat + 1];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 2];
    locyi = tabinf_1.imynl + nodplc[lmat + 2];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 3];
    locyi = tabinf_1.imynl + nodplc[lmat + 3];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    lmat += 4;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	val = blank_1.value[loct - 1];
	loct += 2;
	locy = tabinf_1.lynl + nodplc[lmat];
	blank_1.value[locy - 1] -= val;
	locy = tabinf_1.lynl + nodplc[lmat + 1];
	blank_1.value[locy - 1] += val;
	lmat += 2;
/* L107: */
    }
    loc = nodplc[loc - 1];
    goto L105;

/*  NONLINEAR CURRENT CONTROLLED CURRENT SOURCES */

L110:
    loc = cirdat_1.locate[6];
L115:
    if (loc == 0 || nodplc[loc + 12] != 0) {
	goto L120;
    }
    ndim = nodplc[loc + 3];
    lmat = nodplc[loc + 6];
    loct = tabinf_1.lx0 + nodplc[loc + 11] + 2;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	val = blank_1.value[loct - 1];
	loct += 2;
	locy = tabinf_1.lynl + nodplc[lmat];
	locyi = tabinf_1.imynl + nodplc[lmat];
	blank_1.value[locy - 1] = val;
	blank_1.value[locyi - 1] = 0.;
	locy = tabinf_1.lynl + nodplc[lmat + 1];
	locyi = tabinf_1.imynl + nodplc[lmat + 1];
	blank_1.value[locy - 1] = -val;
	blank_1.value[locyi - 1] = 0.;
	lmat += 2;
/* L117: */
    }
    loc = nodplc[loc - 1];
    goto L115;

/*  NONLINEAR CURRENT CONTROLLED VOLTAGE SOURCES */

L120:
    loc = cirdat_1.locate[7];
L125:
    if (loc == 0 || nodplc[loc + 13] != 0) {
	goto L140;
    }
    ndim = nodplc[loc + 3];
    lmat = nodplc[loc + 7];
    loct = tabinf_1.lx0 + nodplc[loc + 12] + 3;
    locy = tabinf_1.lynl + nodplc[lmat];
    locyi = tabinf_1.imynl + nodplc[lmat];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 1];
    locyi = tabinf_1.imynl + nodplc[lmat + 1];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 2];
    locyi = tabinf_1.imynl + nodplc[lmat + 2];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[lmat + 3];
    locyi = tabinf_1.imynl + nodplc[lmat + 3];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    lmat += 4;
    i__1 = ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	val = blank_1.value[loct - 1];
	loct += 2;
	locy = tabinf_1.lynl + nodplc[lmat + i__ - 1];
	blank_1.value[locy - 1] -= val;
/* L127: */
    }
    loc = nodplc[loc - 1];
    goto L125;

/*  VOLTAGE SOURCES */

L140:
    loc = cirdat_1.locate[8];
L150:
    if (loc == 0 || nodplc[loc + 10] != 0) {
	goto L160;
    }
    locv = nodplc[loc];
    iptr = nodplc[loc + 5];
    blank_1.value[tabinf_1.lvn + iptr - 1] = blank_1.value[locv + 1];
    blank_1.value[tabinf_1.imvn + iptr - 1] = blank_1.value[locv + 2];
    locy = tabinf_1.lynl + nodplc[loc + 6];
    blank_1.value[locy - 1] += 1.;
    locy = tabinf_1.lynl + nodplc[loc + 7];
    blank_1.value[locy - 1] += -1.;
    locy = tabinf_1.lynl + nodplc[loc + 8];
    blank_1.value[locy - 1] += 1.;
    locy = tabinf_1.lynl + nodplc[loc + 9];
    blank_1.value[locy - 1] += -1.;
    loc = nodplc[loc - 1];
    goto L150;

/*  CURRENT SOURCES */

L160:
    loc = cirdat_1.locate[9];
L170:
    if (loc == 0 || nodplc[loc + 5] != 0) {
	goto L200;
    }
    locv = nodplc[loc];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    blank_1.value[tabinf_1.lvn + node1 - 1] -= blank_1.value[locv + 1];
    blank_1.value[tabinf_1.imvn + node1 - 1] -= blank_1.value[locv + 2];
    blank_1.value[tabinf_1.lvn + node2 - 1] += blank_1.value[locv + 1];
    blank_1.value[tabinf_1.imvn + node2 - 1] += blank_1.value[locv + 2];
    loc = nodplc[loc - 1];
    goto L170;

/*  DIODES */

L200:
    loc = cirdat_1.locate[10];
L210:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L250;
    }
    locv = nodplc[loc];
    area = blank_1.value[locv];
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 10];
    gspr = blank_1.value[locm + 1] * area;
    geq = blank_1.value[loct + 1];
    xceq = blank_1.value[loct + 3] * status_1.omega;
    locy = tabinf_1.lynl + nodplc[loc + 12];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lynl + nodplc[loc + 13];
    locyi = tabinf_1.imynl + nodplc[loc + 13];
    blank_1.value[locy - 1] += geq;
    blank_1.value[locyi - 1] += xceq;
    locy = tabinf_1.lynl + nodplc[loc + 14];
    locyi = tabinf_1.imynl + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + geq + gspr;
    blank_1.value[locyi - 1] += xceq;
    locy = tabinf_1.lynl + nodplc[loc + 6];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 7];
    locyi = tabinf_1.imynl + nodplc[loc + 7];
    blank_1.value[locy - 1] -= geq;
    blank_1.value[locyi - 1] -= xceq;
    locy = tabinf_1.lynl + nodplc[loc + 8];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 9];
    locyi = tabinf_1.imynl + nodplc[loc + 9];
    blank_1.value[locy - 1] -= geq;
    blank_1.value[locyi - 1] -= xceq;
    loc = nodplc[loc - 1];
    goto L210;

/*  BJTS */

L250:
    loc = cirdat_1.locate[11];
L260:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L300;
    }
    locv = nodplc[loc];
    area = blank_1.value[locv];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 21];
    gcpr = blank_1.value[locm + 19] * area;
    gepr = blank_1.value[locm + 18] * area;
    gpi = blank_1.value[loct + 3];
    gmu = blank_1.value[loct + 4];
    gm = blank_1.value[loct + 5];
    go = blank_1.value[loct + 6];
    xgm = 0.;
    td = blank_1.value[locm + 27];
    if (td == 0.) {
	goto L270;
    }
    arg = td * status_1.omega;
    gm += go;
    xgm = -gm * sin(arg);
    gm = gm * cos(arg) - go;
L270:
    gx = blank_1.value[loct + 15];
    xcpi = blank_1.value[loct + 8] * status_1.omega;
    xcmu = blank_1.value[loct + 10] * status_1.omega;
    xcbx = blank_1.value[loct + 14] * status_1.omega;
    xccs = blank_1.value[loct + 12] * status_1.omega;
    xcmcb = blank_1.value[loct + 16] * status_1.omega;
    locy = tabinf_1.lynl + nodplc[loc + 23];
    blank_1.value[locy - 1] += gcpr;
    locy = tabinf_1.lynl + nodplc[loc + 24];
    locyi = tabinf_1.imynl + nodplc[loc + 24];
    blank_1.value[locy - 1] += gx;
    blank_1.value[locyi - 1] += xcbx;
    locy = tabinf_1.lynl + nodplc[loc + 25];
    blank_1.value[locy - 1] += gepr;
    locy = tabinf_1.lynl + nodplc[loc + 26];
    locyi = tabinf_1.imynl + nodplc[loc + 26];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gmu + go + gcpr;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] + xcmu + xccs + xcbx;
    locy = tabinf_1.lynl + nodplc[loc + 27];
    locyi = tabinf_1.imynl + nodplc[loc + 27];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gx + gpi + gmu;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] + xcpi + xcmu + xcmcb;
    locy = tabinf_1.lynl + nodplc[loc + 28];
    locyi = tabinf_1.imynl + nodplc[loc + 28];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gpi + gepr + gm + go;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] + xcpi + xgm;
    locy = tabinf_1.lynl + nodplc[loc + 9];
    blank_1.value[locy - 1] -= gcpr;
    locy = tabinf_1.lynl + nodplc[loc + 10];
    blank_1.value[locy - 1] -= gx;
    locy = tabinf_1.lynl + nodplc[loc + 11];
    blank_1.value[locy - 1] -= gepr;
    locy = tabinf_1.lynl + nodplc[loc + 12];
    blank_1.value[locy - 1] -= gcpr;
    locy = tabinf_1.lynl + nodplc[loc + 13];
    locyi = tabinf_1.imynl + nodplc[loc + 13];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gmu + gm;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcmu + xgm;
    locy = tabinf_1.lynl + nodplc[loc + 14];
    locyi = tabinf_1.imynl + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gm - go;
    blank_1.value[locyi - 1] -= xgm;
    locy = tabinf_1.lynl + nodplc[loc + 15];
    blank_1.value[locy - 1] -= gx;
    locy = tabinf_1.lynl + nodplc[loc + 16];
    locyi = tabinf_1.imynl + nodplc[loc + 16];
    blank_1.value[locy - 1] -= gmu;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcmu - xcmcb;
    locy = tabinf_1.lynl + nodplc[loc + 17];
    locyi = tabinf_1.imynl + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gpi;
    blank_1.value[locyi - 1] -= xcpi;
    locy = tabinf_1.lynl + nodplc[loc + 18];
    blank_1.value[locy - 1] -= gepr;
    locy = tabinf_1.lynl + nodplc[loc + 19];
    locyi = tabinf_1.imynl + nodplc[loc + 19];
    blank_1.value[locy - 1] -= go;
    blank_1.value[locyi - 1] += xcmcb;
    locy = tabinf_1.lynl + nodplc[loc + 20];
    locyi = tabinf_1.imynl + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gpi - gm;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcpi - xgm - xcmcb;
    locyi = tabinf_1.imynl + nodplc[loc + 30];
    blank_1.value[locyi - 1] += xccs;
    locyi = tabinf_1.imynl + nodplc[loc + 31];
    blank_1.value[locyi - 1] -= xccs;
    locyi = tabinf_1.imynl + nodplc[loc + 32];
    blank_1.value[locyi - 1] -= xccs;
    locyi = tabinf_1.imynl + nodplc[loc + 33];
    blank_1.value[locyi - 1] -= xcbx;
    locyi = tabinf_1.imynl + nodplc[loc + 34];
    blank_1.value[locyi - 1] -= xcbx;
    loc = nodplc[loc - 1];
    goto L260;

/*  JFETS */

L300:
    loc = cirdat_1.locate[12];
L310:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L350;
    }
    locv = nodplc[loc];
    area = blank_1.value[locv];
    locm = nodplc[loc + 6];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 18];
    gdpr = blank_1.value[locm + 3] * area;
    gspr = blank_1.value[locm + 4] * area;
    gm = blank_1.value[loct + 4];
    gds = blank_1.value[loct + 5];
    ggs = blank_1.value[loct + 6];
    xgs = blank_1.value[loct + 8] * status_1.omega;
    ggd = blank_1.value[loct + 7];
    xgd = blank_1.value[loct + 10] * status_1.omega;
    locy = tabinf_1.lynl + nodplc[loc + 19];
    blank_1.value[locy - 1] += gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 20];
    locyi = tabinf_1.imynl + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + ggd + ggs;
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] + xgd + xgs;
    locy = tabinf_1.lynl + nodplc[loc + 21];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lynl + nodplc[loc + 22];
    locyi = tabinf_1.imynl + nodplc[loc + 22];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gdpr + gds + ggd;
    blank_1.value[locyi - 1] += xgd;
    locy = tabinf_1.lynl + nodplc[loc + 23];
    locyi = tabinf_1.imynl + nodplc[loc + 23];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gspr + gds + gm + ggs;
    blank_1.value[locyi - 1] += xgs;
    locy = tabinf_1.lynl + nodplc[loc + 8];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 9];
    locyi = tabinf_1.imynl + nodplc[loc + 9];
    blank_1.value[locy - 1] -= ggd;
    blank_1.value[locyi - 1] -= xgd;
    locy = tabinf_1.lynl + nodplc[loc + 10];
    locyi = tabinf_1.imynl + nodplc[loc + 10];
    blank_1.value[locy - 1] -= ggs;
    blank_1.value[locyi - 1] -= xgs;
    locy = tabinf_1.lynl + nodplc[loc + 11];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 12];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 13];
    locyi = tabinf_1.imynl + nodplc[loc + 13];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - ggd + gm;
    blank_1.value[locyi - 1] -= xgd;
    locy = tabinf_1.lynl + nodplc[loc + 14];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - gm;
    locy = tabinf_1.lynl + nodplc[loc + 15];
    locyi = tabinf_1.imynl + nodplc[loc + 15];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - ggs - gm;
    blank_1.value[locyi - 1] -= xgs;
    locy = tabinf_1.lynl + nodplc[loc + 16];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gds;
    loc = nodplc[loc - 1];
    goto L310;

/*  MOSFETS */

L350:
    loc = cirdat_1.locate[13];
L360:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L400;
    }
    locv = nodplc[loc];
    locm = nodplc[loc + 7];
    itype = nodplc[locm + 1];
    locm = nodplc[locm];
    devmod = blank_1.value[locv + 7];
    xnrm = 1.;
    xrev = 0.;
    if (devmod >= 0.) {
	goto L370;
    }
    xnrm = 0.;
    xrev = 1.;
L370:
    loct = tabinf_1.lx0 + nodplc[loc + 25];
    if (blank_1.value[locm + 6] == 0. && blank_1.value[locm + 7] == 0.) {
	goto L375;
    }
    gdpr = blank_1.value[locm + 6];
    gspr = blank_1.value[locm + 7];
    goto L380;
L375:
    gdpr = blank_1.value[locm + 15] / blank_1.value[locv + 12];
    gspr = blank_1.value[locm + 15] / blank_1.value[locv + 13];
L380:
    gm = blank_1.value[loct + 6];
    gds = blank_1.value[loct + 7];
    gmbs = blank_1.value[loct + 8];
    gbd = blank_1.value[loct + 9];
    gbs = blank_1.value[loct + 10];
    capbd = blank_1.value[loct + 23];
    capbs = blank_1.value[loct + 25];
/* C */
/* C    CHARGE ORIENTED MODEL PARAMETERS */
/* C */
    xl = blank_1.value[locv] - blank_1.value[locm + 27] * 2.;
    xw = blank_1.value[locv + 1];
    xqco = blank_1.value[locm + 34];
    xqc = blank_1.value[locv + 14];
    covlgs = blank_1.value[locm + 12] * xw;
    covlgd = blank_1.value[locm + 13] * xw;
    covlgb = blank_1.value[locm + 14] * xl;
    if (xqco > .5) {
	goto L385;
    }
    cggb = blank_1.value[loct + 17];
    cgdb = blank_1.value[loct + 18];
    cgsb = blank_1.value[loct + 19];
    cbgb = blank_1.value[loct + 20];
    cbdb = blank_1.value[loct + 21];
    cbsb = blank_1.value[loct + 22];
    gcg = (cggb + cbgb) * status_1.omega;
    gcd = (cgdb + cbdb) * status_1.omega;
    gcs = (cgsb + cbsb) * status_1.omega;
    xcgxd = -xqc * gcg;
    xcgxs = -(1. - xqc) * gcg;
    xcdxd = -xqc * gcd;
    xcdxs = -(1. - xqc) * gcd;
    xcsxd = -xqc * gcs;
    xcsxs = -(1. - xqc) * gcs;
    xcdgb = xcgxd - covlgd * status_1.omega;
    xcddb = xcdxd + (capbd + covlgd) * status_1.omega;
    xcdsb = xcsxd;
    xcsgb = xcgxs - covlgs * status_1.omega;
    xcsdb = xcdxs;
    xcssb = xcsxs + (capbs + covlgs) * status_1.omega;
    xcggb = (cggb + covlgd + covlgs + covlgb) * status_1.omega;
    xcgdb = (cgdb - covlgd) * status_1.omega;
    xcgsb = (cgsb - covlgs) * status_1.omega;
    xcbgb = (cbgb - covlgb) * status_1.omega;
    xcbdb = (cbdb - capbd) * status_1.omega;
    xcbsb = (cbsb - capbs) * status_1.omega;
    goto L390;

/*     MEYER"S MODEL PARAMETERS */

L385:
    xcgs = (blank_1.value[loct + 11] + covlgs) * status_1.omega;
    xcgd = (blank_1.value[loct + 13] + covlgd) * status_1.omega;
    xcgb = (blank_1.value[loct + 15] + covlgb) * status_1.omega;
    xbd = capbd * status_1.omega;
    xbs = capbs * status_1.omega;
/* C */
/* C    DO THE MAPPING FROM MEYER"S MODEL INTO CHARGE ORIENTED MODEL */
/* C */
    xcggb = xcgd + xcgs + xcgb;
    xcgdb = -xcgd;
    xcgsb = -xcgs;
    xcbgb = -xcgb;
    xcbdb = -xbd;
    xcbsb = -xbs;
    xcddb = xcgd + xbd;
    xcssb = xcgs + xbs;
/* C    XCGSB=-XCGB */
    xcdgb = -xcgd;
    xcsgb = -xcgs;
    xcdsb = 0.;
    xcsdb = 0.;
/* C */
L390:
    locyi = tabinf_1.imynl + nodplc[loc + 27];
    blank_1.value[locyi - 1] += xcggb;
    locyi = tabinf_1.imynl + nodplc[loc + 29];
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcbgb - xcbdb - 
	    xcbsb;
    locyi = tabinf_1.imynl + nodplc[loc + 30];
    blank_1.value[locyi - 1] += xcddb;
    locyi = tabinf_1.imynl + nodplc[loc + 31];
    blank_1.value[locyi - 1] += xcssb;
    locyi = tabinf_1.imynl + nodplc[loc + 10];
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcggb - xcgdb - 
	    xcgsb;
    locyi = tabinf_1.imynl + nodplc[loc + 11];
    blank_1.value[locyi - 1] += xcgdb;
    locyi = tabinf_1.imynl + nodplc[loc + 12];
    blank_1.value[locyi - 1] += xcgsb;
    locyi = tabinf_1.imynl + nodplc[loc + 14];
    blank_1.value[locyi - 1] += xcbgb;
    locyi = tabinf_1.imynl + nodplc[loc + 15];
    blank_1.value[locyi - 1] += xcbdb;
    locyi = tabinf_1.imynl + nodplc[loc + 16];
    blank_1.value[locyi - 1] += xcbsb;
    locyi = tabinf_1.imynl + nodplc[loc + 18];
    blank_1.value[locyi - 1] += xcdgb;
    locyi = tabinf_1.imynl + nodplc[loc + 19];
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcdgb - xcddb - 
	    xcdsb;
    locyi = tabinf_1.imynl + nodplc[loc + 20];
    blank_1.value[locyi - 1] += xcdsb;
    locyi = tabinf_1.imynl + nodplc[loc + 21];
    blank_1.value[locyi - 1] += xcsgb;
    locyi = tabinf_1.imynl + nodplc[loc + 23];
    blank_1.value[locyi - 1] = blank_1.value[locyi - 1] - xcsgb - xcsdb - 
	    xcssb;
    locyi = tabinf_1.imynl + nodplc[loc + 24];
    blank_1.value[locyi - 1] += xcsdb;
    locy = tabinf_1.lynl + nodplc[loc + 26];
    blank_1.value[locy - 1] += gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 28];
    blank_1.value[locy - 1] += gspr;
    locy = tabinf_1.lynl + nodplc[loc + 29];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gbd + gbs;
    locy = tabinf_1.lynl + nodplc[loc + 30];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gdpr + gds + gbd + 
	    xrev * (gm + gmbs);
    locy = tabinf_1.lynl + nodplc[loc + 31];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] + gspr + gds + gbs + 
	    xnrm * (gm + gmbs);
    locy = tabinf_1.lynl + nodplc[loc + 9];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 13];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 15];
    blank_1.value[locy - 1] -= gbd;
    locy = tabinf_1.lynl + nodplc[loc + 16];
    blank_1.value[locy - 1] -= gbs;
    locy = tabinf_1.lynl + nodplc[loc + 17];
    blank_1.value[locy - 1] -= gdpr;
    locy = tabinf_1.lynl + nodplc[loc + 18];
    blank_1.value[locy - 1] += (xnrm - xrev) * gm;
    locy = tabinf_1.lynl + nodplc[loc + 19];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbd + (xnrm - xrev) * 
	    gmbs;
    locy = tabinf_1.lynl + nodplc[loc + 20];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - xnrm * (gm + 
	    gmbs);
    locy = tabinf_1.lynl + nodplc[loc + 21];
    blank_1.value[locy - 1] -= (xnrm - xrev) * gm;
    locy = tabinf_1.lynl + nodplc[loc + 22];
    blank_1.value[locy - 1] -= gspr;
    locy = tabinf_1.lynl + nodplc[loc + 23];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gbs - (xnrm - xrev) * 
	    gmbs;
    locy = tabinf_1.lynl + nodplc[loc + 24];
    blank_1.value[locy - 1] = blank_1.value[locy - 1] - gds - xrev * (gm + 
	    gmbs);
    loc = nodplc[loc - 1];
    goto L360;

/*  TRANSMISSION LINES */

L400:
    loc = cirdat_1.locate[16];
L410:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L1000;
    }
    locv = nodplc[loc];
    z0 = blank_1.value[locv];
    y0 = 1. / z0;
    td = blank_1.value[locv + 1];
    arg = -status_1.omega * td;
    rval = cos(arg);
    xval = sin(arg);
    locy = tabinf_1.lynl + nodplc[loc + 9];
    blank_1.value[locy - 1] += y0;
    locy = tabinf_1.lynl + nodplc[loc + 10];
    locyi = tabinf_1.imynl + nodplc[loc + 10];
    blank_1.value[locy - 1] = -y0;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 11];
    locyi = tabinf_1.imynl + nodplc[loc + 11];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 12];
    blank_1.value[locy - 1] += y0;
    locy = tabinf_1.lynl + nodplc[loc + 13];
    locyi = tabinf_1.imynl + nodplc[loc + 13];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 14];
    locyi = tabinf_1.imynl + nodplc[loc + 14];
    blank_1.value[locy - 1] = -y0;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 15];
    locyi = tabinf_1.imynl + nodplc[loc + 15];
    blank_1.value[locy - 1] = y0;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 16];
    locyi = tabinf_1.imynl + nodplc[loc + 16];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 17];
    locyi = tabinf_1.imynl + nodplc[loc + 17];
    blank_1.value[locy - 1] = y0;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 18];
    locyi = tabinf_1.imynl + nodplc[loc + 18];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 19];
    locyi = tabinf_1.imynl + nodplc[loc + 19];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 20];
    locyi = tabinf_1.imynl + nodplc[loc + 20];
    blank_1.value[locy - 1] = -rval;
    blank_1.value[locyi - 1] = -xval;
    locy = tabinf_1.lynl + nodplc[loc + 21];
    locyi = tabinf_1.imynl + nodplc[loc + 21];
    blank_1.value[locy - 1] = rval;
    blank_1.value[locyi - 1] = xval;
    locy = tabinf_1.lynl + nodplc[loc + 22];
    locyi = tabinf_1.imynl + nodplc[loc + 22];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 23];
    locyi = tabinf_1.imynl + nodplc[loc + 23];
    blank_1.value[locy - 1] = -rval * z0;
    blank_1.value[locyi - 1] = -xval * z0;
    locy = tabinf_1.lynl + nodplc[loc + 24];
    locyi = tabinf_1.imynl + nodplc[loc + 24];
    blank_1.value[locy - 1] = -rval;
    blank_1.value[locyi - 1] = -xval;
    locy = tabinf_1.lynl + nodplc[loc + 25];
    locyi = tabinf_1.imynl + nodplc[loc + 25];
    blank_1.value[locy - 1] = rval;
    blank_1.value[locyi - 1] = xval;
    locy = tabinf_1.lynl + nodplc[loc + 26];
    locyi = tabinf_1.imynl + nodplc[loc + 26];
    blank_1.value[locy - 1] = -1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 27];
    locyi = tabinf_1.imynl + nodplc[loc + 27];
    blank_1.value[locy - 1] = 1.;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 28];
    locyi = tabinf_1.imynl + nodplc[loc + 28];
    blank_1.value[locy - 1] = -rval * z0;
    blank_1.value[locyi - 1] = -xval * z0;
    locy = tabinf_1.lynl + nodplc[loc + 30];
    locyi = tabinf_1.imynl + nodplc[loc + 30];
    blank_1.value[locy - 1] = -y0;
    blank_1.value[locyi - 1] = 0.;
    locy = tabinf_1.lynl + nodplc[loc + 31];
    locyi = tabinf_1.imynl + nodplc[loc + 31];
    blank_1.value[locy - 1] = -y0;
    blank_1.value[locyi - 1] = 0.;
    loc = nodplc[loc - 1];
    goto L410;

/*  FINISHED */

L1000:
    return 0;
} /* acload_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int noise_(integer *loco)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_2985 = { "NOISE ANALYSIS                  ", 0. };

#define titln ((doublereal *)&equiv_2985)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2986 = { "RB      ", 0. };

#define alsrb (*(doublereal *)&equiv_2986)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2987 = { "RC      ", 0. };

#define alsrc (*(doublereal *)&equiv_2987)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2988 = { "RE      ", 0. };

#define alsre (*(doublereal *)&equiv_2988)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2989 = { "RS      ", 0. };

#define alsrs (*(doublereal *)&equiv_2989)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2990 = { "RD      ", 0. };

#define alsrd (*(doublereal *)&equiv_2990)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2991 = { "IB      ", 0. };

#define alsib (*(doublereal *)&equiv_2991)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2992 = { "IC      ", 0. };

#define alsic (*(doublereal *)&equiv_2992)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2993 = { "ID      ", 0. };

#define alsid (*(doublereal *)&equiv_2993)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2994 = { "FN      ", 0. };

#define alsfn (*(doublereal *)&equiv_2994)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2995 = { "TOTAL   ", 0. };

#define alstot (*(doublereal *)&equiv_2995)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2996 = { "/       ", 0. };

#define aslash (*(doublereal *)&equiv_2996)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2997 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_2997)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2998 = { "(////,11X,  (2X,A8))    ", 0. };

#define afmt1 ((doublereal *)&equiv_2998)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2999 = { "(1H0,A8,1P  D10.3)      ", 0. };

#define afmt2 ((doublereal *)&equiv_2999)


    /* Format strings */
    static char fmt_16[] = "(\0020    FREQUENCY = \002,1pd10.3,\002 HZ\002/)";
    static char fmt_91[] = "(//\0020**** RESISTOR SQUARED NOISE VOLTAGES (SQ"
	    " V/HZ)\002)";
    static char fmt_201[] = "(//\0020**** DIODE SQUARED NOISE VOLTAGES (SQ V"
	    "/HZ)\002)";
    static char fmt_301[] = "(//\0020**** TRANSISTOR SQUARED NOISE VOLTAGES "
	    "(SQ V/HZ)\002)";
    static char fmt_401[] = "(//\0020**** JFET SQUARED NOISE VOLTAGES (SQ V/"
	    "HZ)\002)";
    static char fmt_501[] = "(//\0020**** MOSFET SQUARED NOISE VOLTAGES (SQ "
	    "V/HZ)\002)";
    static char fmt_611[] = "(////,\0020**** TOTAL OUTPUT NOISE VOLTAGE\002,"
	    "9x,\002= \002,1pd10.3,\002 SQ V/HZ\002/,\0020\002,40x,\002= \002"
	    ",d10.3,\002 V/RT HZ\002/,\0020     TRANSFER FUNCTION VALUE:\002,"
	    "/,\0020\002,7x,4a8,a1,\002= \002,d10.3,/,\0020     EQUIVALENT IN"
	    "PUT NOISE AT \002,a8,\002 = \002,d10.3,\002 /RT HZ\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    complex q__1;
    static complex equiv_3[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), log(doublereal), exp(doublereal);

    /* Local variables */
#define c__ (equiv_3)
    static integer i__;
#define v ((real *)equiv_3)
    static doublereal gm, xl, xw, fna, arg;
    static integer loc;
    static doublereal fnk, cox, vno1[12], vno2[12], vno3[12], vno4[12], vno5[
	    12], vno6[12], area, anam[12];
#define cval (equiv_3)
    static integer locm;
    static doublereal freq;
    static integer locv;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer ipos, loct, kntr;
    static doublereal gdpr, gspr, vnin, twoq, vout, anam1;
    static integer node1, node2, node3, node4, node5, node6;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
#define vimag ((real *)equiv_3 + 1)
#define vreal ((real *)equiv_3)
    static doublereal vntot[12];
    static integer nprnt, nkntr;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static doublereal vnrms, vtemp;
    static integer itype;
    static doublereal vnout;
    extern /* Subroutine */ int acasol_(void);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal string[5];
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *);
    static doublereal fourkt;
    static integer noposo, nonego, kntlim, ititle, ioutyp;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___2912 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___2922 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___2923 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2925 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2937 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___2938 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2939 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2940 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2941 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2942 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2949 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___2950 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2951 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2952 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2953 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2954 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2955 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2956 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2957 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2958 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___2959 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2960 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2961 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2962 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2963 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2964 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2972 = { 0, 0, 0, fmt_501, 0 };
    static cilist io___2973 = { 0, 0, 0, (char *)afmt1, 0 };
    static cilist io___2974 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2975 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2976 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2977 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2978 = { 0, 0, 0, (char *)afmt2, 0 };
    static cilist io___2984 = { 0, 0, 0, fmt_611, 0 };



/*     THIS ROUTINE COMPUTES THE NOISE DUE TO VARIOUS CIRCUIT ELEMENTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




/* .. FIX-UP FORMATS */
    kntr = 12;
    if (miscel_1.lwidth <= 80) {
	kntr = 7;
    }
    ipos = 11;
    move_(afmt1, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt1, &ipos);
    ipos = 11;
    move_(afmt2, &ipos, &ablnk, &c__1, &c__2);
    alfnum_(&kntr, afmt2, &ipos);
    nprnt = 0;
    freq = status_1.omega / knstnt_1.twopi;
    if (status_1.icalc >= 2) {
	goto L10;
    }
    fourkt = knstnt_1.charge * 4. * status_1.vt;
    twoq = knstnt_1.charge * 2.;
    noposo = nodplc[ac_1.nosout + 1];
    nonego = nodplc[ac_1.nosout + 2];
    kntlim = miscel_1.lwidth / 11;
    nkntr = 1;
L10:
    if (ac_1.nosprt == 0) {
	goto L30;
    }
    if (nkntr > status_1.icalc) {
	goto L30;
    }
    nprnt = 1;
    nkntr += ac_1.nosprt;
    title_(&c__0, &miscel_1.lwidth, &c__1, titln);
    io___2912.ciunit = status_1.iofile;
    s_wsfe(&io___2912);
    do_fio(&c__1, (char *)&freq, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  OBTAIN ADJOINT CIRCUIT SOLUTION */

L30:
    vnrms = 0.;
    i__1 = tabinf_1.lcvn + noposo - 1;
    i__2 = tabinf_1.lcvn + nonego - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vout = sqrt((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * *
	    vimag));
    vout = max(vout,1e-20);
    zero8_(&blank_1.value[tabinf_1.lvn], &cirdat_1.nstop);
    zero8_(&blank_1.value[tabinf_1.imvn], &cirdat_1.nstop);
    blank_1.value[tabinf_1.lvn + noposo - 1] = -1.;
    blank_1.value[tabinf_1.lvn + nonego - 1] = 1.;
    acasol_();

/*  RESISTORS */

    if (cirdat_1.jelcnt[0] == 0) {
	goto L200;
    }
    ititle = 0;
/* L91: */
/* L100: */
    loc = cirdat_1.locate[0];
    kntr = 0;
L110:
    if (loc == 0 || nodplc[loc + 7] != 0) {
	goto L130;
    }
    ++kntr;
    locv = nodplc[loc];
    anam[kntr - 1] = blank_1.value[locv - 1];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    i__1 = tabinf_1.lcvn + node1 - 1;
    i__2 = tabinf_1.lcvn + node2 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vntot[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag *
	     *vimag)) * fourkt * blank_1.value[locv];
    vnrms += vntot[kntr - 1];
    if (kntr >= kntlim) {
	goto L140;
    }
L120:
    loc = nodplc[loc - 1];
    goto L110;
L130:
    if (kntr == 0) {
	goto L200;
    }
L140:
    if (nprnt == 0) {
	goto L160;
    }
    if (ititle == 0) {
	io___2922.ciunit = status_1.iofile;
	s_wsfe(&io___2922);
	e_wsfe();
    }
    ititle = 1;
    io___2923.ciunit = status_1.iofile;
    s_wsfe(&io___2923);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2925.ciunit = status_1.iofile;
    s_wsfe(&io___2925);
    do_fio(&c__1, (char *)&alstot, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vntot[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L160:
    kntr = 0;
    if (loc != 0) {
	goto L120;
    }

/*  DIODES */

L200:
    if (cirdat_1.jelcnt[10] == 0) {
	goto L300;
    }
    ititle = 0;
/* L201: */
/* L210: */
    loc = cirdat_1.locate[10];
    kntr = 0;
L220:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L240;
    }
    ++kntr;
    locv = nodplc[loc];
    anam[kntr - 1] = blank_1.value[locv - 1];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    loct = nodplc[loc + 10];
    area = blank_1.value[locv];
    fnk = blank_1.value[locm + 9];
    fna = blank_1.value[locm + 10];

/*  OHMIC RESISTANCE */

    i__1 = tabinf_1.lcvn + node1 - 1;
    i__2 = tabinf_1.lcvn + node3 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno1[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[locm + 1] * area;

/*  JUNCTION SHOT NOISE AND FLICKER NOISE */

    i__1 = tabinf_1.lcvn + node3 - 1;
    i__2 = tabinf_1.lcvn + node2 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vtemp = (doublereal) (*vreal * *vreal) + (doublereal) (*vimag * *vimag);
/* Computing MAX */
    d__2 = (d__1 = blank_1.value[tabinf_1.lx0 + loct], abs(d__1));
    arg = max(d__2,1e-20);
    vno2[kntr - 1] = vtemp * twoq * arg;
    vno3[kntr - 1] = vtemp * fnk * exp(fna * log(arg)) / freq;
    vntot[kntr - 1] = vno1[kntr - 1] + vno2[kntr - 1] + vno3[kntr - 1];
    vnrms += vntot[kntr - 1];
    if (kntr >= kntlim) {
	goto L250;
    }
L230:
    loc = nodplc[loc - 1];
    goto L220;
L240:
    if (kntr == 0) {
	goto L300;
    }
L250:
    if (nprnt == 0) {
	goto L260;
    }
    if (ititle == 0) {
	io___2937.ciunit = status_1.iofile;
	s_wsfe(&io___2937);
	e_wsfe();
    }
    ititle = 1;
    io___2938.ciunit = status_1.iofile;
    s_wsfe(&io___2938);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2939.ciunit = status_1.iofile;
    s_wsfe(&io___2939);
    do_fio(&c__1, (char *)&alsrs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2940.ciunit = status_1.iofile;
    s_wsfe(&io___2940);
    do_fio(&c__1, (char *)&alsid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno2[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2941.ciunit = status_1.iofile;
    s_wsfe(&io___2941);
    do_fio(&c__1, (char *)&alsfn, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno3[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2942.ciunit = status_1.iofile;
    s_wsfe(&io___2942);
    do_fio(&c__1, (char *)&alstot, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vntot[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L260:
    kntr = 0;
    if (loc != 0) {
	goto L230;
    }

/*  BIPOLAR JUNCTION TRANSISTORS */

L300:
    if (cirdat_1.jelcnt[11] == 0) {
	goto L400;
    }
    ititle = 0;
/* L301: */
/* L310: */
    loc = cirdat_1.locate[11];
    kntr = 0;
L320:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L340;
    }
    ++kntr;
    locv = nodplc[loc];
    anam[kntr - 1] = blank_1.value[locv - 1];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    loct = nodplc[loc + 21];
    area = blank_1.value[locv];
    fnk = blank_1.value[locm + 43];
    fna = blank_1.value[locm + 44];

/*  EXTRINSIC RESISTANCES */

/* ...  BASE RESISTANCE */
    i__1 = tabinf_1.lcvn + node2 - 1;
    i__2 = tabinf_1.lcvn + node5 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno1[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[tabinf_1.lx0 + loct + 15];
/* ...  COLLECTOR RESISTANCE */
    i__1 = tabinf_1.lcvn + node1 - 1;
    i__2 = tabinf_1.lcvn + node4 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno2[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[locm + 19] * area;
/* ...  EMITTER RESISTANCE */
    i__1 = tabinf_1.lcvn + node3 - 1;
    i__2 = tabinf_1.lcvn + node6 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno3[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[locm + 18] * area;

/*  BASE CURRENT SHOT NOISE AND FLICKER NOISE */

    i__1 = tabinf_1.lcvn + node5 - 1;
    i__2 = tabinf_1.lcvn + node6 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vtemp = (doublereal) (*vreal * *vreal) + (doublereal) (*vimag * *vimag);
/* Computing MAX */
    d__2 = (d__1 = blank_1.value[tabinf_1.lx0 + loct + 2], abs(d__1));
    arg = max(d__2,1e-20);
    vno4[kntr - 1] = vtemp * twoq * arg;
    vno5[kntr - 1] = vtemp * fnk * exp(fna * log(arg)) / freq;

/*  COLLECTOR CURRENT SHOT NOISE */

    i__1 = tabinf_1.lcvn + node4 - 1;
    i__2 = tabinf_1.lcvn + node6 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno6[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * twoq * (d__1 = blank_1.value[tabinf_1.lx0 + loct + 1], 
	    abs(d__1));
    vntot[kntr - 1] = vno1[kntr - 1] + vno2[kntr - 1] + vno3[kntr - 1] + vno4[
	    kntr - 1] + vno5[kntr - 1] + vno6[kntr - 1];
    vnrms += vntot[kntr - 1];
    if (kntr >= kntlim) {
	goto L350;
    }
L330:
    loc = nodplc[loc - 1];
    goto L320;
L340:
    if (kntr == 0) {
	goto L400;
    }
L350:
    if (nprnt == 0) {
	goto L360;
    }
    if (ititle == 0) {
	io___2949.ciunit = status_1.iofile;
	s_wsfe(&io___2949);
	e_wsfe();
    }
    ititle = 1;
    io___2950.ciunit = status_1.iofile;
    s_wsfe(&io___2950);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2951.ciunit = status_1.iofile;
    s_wsfe(&io___2951);
    do_fio(&c__1, (char *)&alsrb, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2952.ciunit = status_1.iofile;
    s_wsfe(&io___2952);
    do_fio(&c__1, (char *)&alsrc, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno2[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2953.ciunit = status_1.iofile;
    s_wsfe(&io___2953);
    do_fio(&c__1, (char *)&alsre, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno3[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2954.ciunit = status_1.iofile;
    s_wsfe(&io___2954);
    do_fio(&c__1, (char *)&alsib, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno4[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2955.ciunit = status_1.iofile;
    s_wsfe(&io___2955);
    do_fio(&c__1, (char *)&alsic, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno6[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2956.ciunit = status_1.iofile;
    s_wsfe(&io___2956);
    do_fio(&c__1, (char *)&alsfn, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno5[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2957.ciunit = status_1.iofile;
    s_wsfe(&io___2957);
    do_fio(&c__1, (char *)&alstot, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vntot[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L360:
    kntr = 0;
    if (loc != 0) {
	goto L330;
    }

/*  JFETS */

L400:
    if (cirdat_1.jelcnt[12] == 0) {
	goto L500;
    }
    ititle = 0;
/* L401: */
/* L410: */
    loc = cirdat_1.locate[12];
    kntr = 0;
L420:
    if (loc == 0 || nodplc[loc + 24] != 0) {
	goto L440;
    }
    ++kntr;
    locv = nodplc[loc];
    anam[kntr - 1] = blank_1.value[locv - 1];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    locm = nodplc[loc + 6];
    locm = nodplc[locm];
    loct = nodplc[loc + 18];
    area = blank_1.value[locv];
    fnk = blank_1.value[locm + 9];
    fna = blank_1.value[locm + 10];

/*  EXTRINSIC RESISTANCES */

/* ...  DRAIN RESISTANCE */
    i__1 = tabinf_1.lcvn + node1 - 1;
    i__2 = tabinf_1.lcvn + node4 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno1[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[locm + 3] * area;
/* ...  SOURCE RESISTANCE */
    i__1 = tabinf_1.lcvn + node3 - 1;
    i__2 = tabinf_1.lcvn + node5 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno2[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * blank_1.value[locm + 4] * area;

/*  DRAIN CURRENT SHOT NOISE AND FLICKER NOISE */

    i__1 = tabinf_1.lcvn + node4 - 1;
    i__2 = tabinf_1.lcvn + node5 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vtemp = (doublereal) (*vreal * *vreal) + (doublereal) (*vimag * *vimag);
    vno3[kntr - 1] = vtemp * fourkt * 2. * (d__1 = blank_1.value[tabinf_1.lx0 
	    + loct + 4], abs(d__1)) / 3.;
/* Computing MAX */
    d__2 = (d__1 = blank_1.value[tabinf_1.lx0 + loct + 2], abs(d__1));
    arg = max(d__2,1e-20);
    vno4[kntr - 1] = vtemp * fnk * exp(fna * log(arg)) / freq;
    vntot[kntr - 1] = vno1[kntr - 1] + vno2[kntr - 1] + vno3[kntr - 1] + vno4[
	    kntr - 1];
    vnrms += vntot[kntr - 1];
    if (kntr >= kntlim) {
	goto L450;
    }
L430:
    loc = nodplc[loc - 1];
    goto L420;
L440:
    if (kntr == 0) {
	goto L500;
    }
L450:
    if (nprnt == 0) {
	goto L460;
    }
    if (ititle == 0) {
	io___2958.ciunit = status_1.iofile;
	s_wsfe(&io___2958);
	e_wsfe();
    }
    ititle = 1;
    io___2959.ciunit = status_1.iofile;
    s_wsfe(&io___2959);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2960.ciunit = status_1.iofile;
    s_wsfe(&io___2960);
    do_fio(&c__1, (char *)&alsrd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2961.ciunit = status_1.iofile;
    s_wsfe(&io___2961);
    do_fio(&c__1, (char *)&alsrs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno2[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2962.ciunit = status_1.iofile;
    s_wsfe(&io___2962);
    do_fio(&c__1, (char *)&alsid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno3[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2963.ciunit = status_1.iofile;
    s_wsfe(&io___2963);
    do_fio(&c__1, (char *)&alsfn, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno4[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2964.ciunit = status_1.iofile;
    s_wsfe(&io___2964);
    do_fio(&c__1, (char *)&alstot, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vntot[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L460:
    kntr = 0;
    if (loc != 0) {
	goto L430;
    }

/*  MOSFETS */

L500:
    if (cirdat_1.jelcnt[13] == 0) {
	goto L600;
    }
    ititle = 0;
/* L501: */
/* L510: */
    loc = cirdat_1.locate[13];
    kntr = 0;
L520:
    if (loc == 0 || nodplc[loc + 32] != 0) {
	goto L540;
    }
    ++kntr;
    locv = nodplc[loc];
    anam[kntr - 1] = blank_1.value[locv - 1];
    node1 = nodplc[loc + 1];
    node2 = nodplc[loc + 2];
    node3 = nodplc[loc + 3];
    node4 = nodplc[loc + 4];
    node5 = nodplc[loc + 5];
    node6 = nodplc[loc + 6];
    locm = nodplc[loc + 7];
    itype = nodplc[locm + 1];
    loct = nodplc[loc + 25];
    locm = nodplc[locm];
    xl = blank_1.value[locv] - blank_1.value[locm + 27] * 2.;
    xw = blank_1.value[locv + 1];
    cox = blank_1.value[locm + 21];
    if (cox <= 0.) {
	cox = knstnt_1.epsox / 1e-7;
    }
    fnk = blank_1.value[locm + 35];
    fna = blank_1.value[locm + 36];

/*  EXTRINSIC RESISTANCES */

    if (blank_1.value[locm + 6] <= 0. && blank_1.value[locm + 7] <= 0.) {
	goto L522;
    }
    gdpr = blank_1.value[locm + 6];
    gspr = blank_1.value[locm + 7];
    goto L524;
L522:
    gdpr = blank_1.value[locm + 15] / blank_1.value[locv + 12];
    gspr = blank_1.value[locm + 15] / blank_1.value[locv + 13];
/* ...  DRAIN RESISTANCE */
L524:
    i__1 = tabinf_1.lcvn + node1 - 1;
    i__2 = tabinf_1.lcvn + node5 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno1[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * gdpr;
/* ...  SOURCE RESISTANCE */
    i__1 = tabinf_1.lcvn + node3 - 1;
    i__2 = tabinf_1.lcvn + node6 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vno2[kntr - 1] = ((doublereal) (*vreal * *vreal) + (doublereal) (*vimag * 
	    *vimag)) * fourkt * gspr;

/*  DRAIN CURRENT SHOT NOISE AND FLICKER NOISE */

    i__1 = tabinf_1.lcvn + node5 - 1;
    i__2 = tabinf_1.lcvn + node6 - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cval->r = q__1.r, cval->i = q__1.i;
    vtemp = (doublereal) (*vreal * *vreal) + (doublereal) (*vimag * *vimag);
    gm = blank_1.value[tabinf_1.lx0 + loct + 6];
/* Computing MAX */
    d__2 = (d__1 = blank_1.value[tabinf_1.lx0 + loct + 3], abs(d__1));
    arg = max(d__2,1e-20);
    vno3[kntr - 1] = vtemp * fourkt * abs(gm) / 1.5;
    vno4[kntr - 1] = vtemp * fnk * exp(fna * log(arg)) / (freq * cox * xl * 
	    xl);
/* L525: */
    vntot[kntr - 1] = vno1[kntr - 1] + vno2[kntr - 1] + vno3[kntr - 1] + vno4[
	    kntr - 1];
    vnrms += vntot[kntr - 1];
    if (kntr >= kntlim) {
	goto L550;
    }
L530:
    loc = nodplc[loc - 1];
    goto L520;
L540:
    if (kntr == 0) {
	goto L600;
    }
L550:
    if (nprnt == 0) {
	goto L560;
    }
    if (ititle == 0) {
	io___2972.ciunit = status_1.iofile;
	s_wsfe(&io___2972);
	e_wsfe();
    }
    ititle = 1;
    io___2973.ciunit = status_1.iofile;
    s_wsfe(&io___2973);
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&anam[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2974.ciunit = status_1.iofile;
    s_wsfe(&io___2974);
    do_fio(&c__1, (char *)&alsrd, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno1[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2975.ciunit = status_1.iofile;
    s_wsfe(&io___2975);
    do_fio(&c__1, (char *)&alsrs, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno2[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2976.ciunit = status_1.iofile;
    s_wsfe(&io___2976);
    do_fio(&c__1, (char *)&alsid, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno3[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2977.ciunit = status_1.iofile;
    s_wsfe(&io___2977);
    do_fio(&c__1, (char *)&alsfn, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vno4[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    io___2978.ciunit = status_1.iofile;
    s_wsfe(&io___2978);
    do_fio(&c__1, (char *)&alstot, (ftnlen)sizeof(doublereal));
    i__1 = kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vntot[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L560:
    kntr = 0;
    if (loc != 0) {
	goto L530;
    }

/*  COMPUTE EQUIVALENT INPUT NOISE VOLTAGE */

L600:
    vnout = sqrt(vnrms);
    vnin = vnout / vout;
    if (nprnt == 0) {
	goto L620;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	string[i__ - 1] = ablnk;
/* L610: */
    }
    ioutyp = 1;
    ipos = 1;
    outnam_(&ac_1.nosout, &ioutyp, string, &ipos);
    move_(string, &ipos, &aslash, &c__1, &c__1);
    ++ipos;
    locv = nodplc[ac_1.nosin];
    anam1 = blank_1.value[locv - 1];
    move_(string, &ipos, &anam1, &c__1, &c__8);
    io___2984.ciunit = status_1.iofile;
    s_wsfe(&io___2984);
    do_fio(&c__1, (char *)&vnrms, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&vnout, (ftnlen)sizeof(doublereal));
    do_fio(&c__5, (char *)&string[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&vout, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&anam1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&vnin, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  SAVE NOISE OUTPUTS */

L620:
    loc = cirdat_1.locate[43];
L630:
    if (loc == 0) {
	goto L1000;
    }
    tabinf_1.iseq = nodplc[loc + 3];
    if (nodplc[loc + 4] != 2) {
	goto L640;
    }
    i__1 = *loco + tabinf_1.iseq - 1;
    cvalue[i__1].r = vnout, cvalue[i__1].i = 0.f;
    goto L650;
L640:
    i__1 = *loco + tabinf_1.iseq - 1;
    cvalue[i__1].r = vnin, cvalue[i__1].i = 0.f;
L650:
    loc = nodplc[loc - 1];
    goto L630;

/*  FINISHED */

L1000:
    return 0;
} /* noise_ */

#undef cvalue
#undef nodplc
#undef vreal
#undef vimag
#undef cval
#undef v
#undef c__
#undef afmt2
#undef afmt1
#undef ablnk
#undef aslash
#undef alstot
#undef alsfn
#undef alsid
#undef alsic
#undef alsib
#undef alsrd
#undef alsrs
#undef alsre
#undef alsrc
#undef alsrb
#undef titln


/* Subroutine */ int acasol_(void)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    complex q__1;

    /* Local variables */
    static integer i__, j, k, loc;
    extern /* Subroutine */ int cdiv_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *);
    static integer iord, jord;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *);
    static doublereal ximag;
    static integer locnn;
    static doublereal xreal;
    extern /* Subroutine */ int cmult_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *);
    extern integer indxx_(integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE EVALUATES THE RESPONSE OF THE ADJOINT CIRCUIT BY */
/* DOING A FORWARD/BACKWARD SUBSTITUTION STEP USING THE TRANSPOSE OF THE */
/* CIRCUIT EQUATION COEFFICIENT MATRIX. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */

/*  EVALUATES ADJOINT RESPONSE BY DOING FORWARD/BACKWARD SUBSTITUTION ON */
/*  THE TRANSPOSE OF THE Y MATRIX */

/*  FORWARD SUBSTITUTION */

    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	loc = i__;
	iord = nodplc[tabinf_1.icswpf + i__ - 1];
L10:
	loc = nodplc[tabinf_1.irpt + loc - 1];
	if (nodplc[tabinf_1.irowno + loc - 1] >= i__) {
	    goto L15;
	}
	j = nodplc[tabinf_1.irowno + loc - 1];
	jord = nodplc[tabinf_1.icswpf + j - 1];
	cmult_(&blank_1.value[tabinf_1.lynl + loc - 1], &blank_1.value[
		tabinf_1.imynl + loc - 1], &blank_1.value[tabinf_1.lvn + jord 
		- 1], &blank_1.value[tabinf_1.imvn + jord - 1], &xreal, &
		ximag);
	blank_1.value[tabinf_1.lvn + iord - 1] -= xreal;
	blank_1.value[tabinf_1.imvn + iord - 1] -= ximag;
	goto L10;
L15:
	jord = nodplc[tabinf_1.irswpf + i__ - 1];
	locnn = indxx_(&jord, &iord);
	cdiv_(&blank_1.value[tabinf_1.lvn + iord - 1], &blank_1.value[
		tabinf_1.imvn + iord - 1], &blank_1.value[tabinf_1.lynl + 
		locnn - 1], &blank_1.value[tabinf_1.imynl + locnn - 1], &
		blank_1.value[tabinf_1.lvn + iord - 1], &blank_1.value[
		tabinf_1.imvn + iord - 1]);
/* L20: */
    }

/*  BACKWARD SUBSTITUTION */

    i__ = cirdat_1.nstop;
L30:
    --i__;
    if (i__ <= 1) {
	goto L60;
    }
    iord = nodplc[tabinf_1.icswpf + i__ - 1];
    loc = i__;
L35:
    loc = nodplc[tabinf_1.irpt + loc - 1];
/* L40: */
    if (nodplc[tabinf_1.irowno + loc - 1] != i__) {
	goto L35;
    }
L50:
    loc = nodplc[tabinf_1.irpt + loc - 1];
    if (loc == 0) {
	goto L30;
    }
    j = nodplc[tabinf_1.irowno + loc - 1];
    jord = nodplc[tabinf_1.icswpf + j - 1];
    cmult_(&blank_1.value[tabinf_1.lynl + loc - 1], &blank_1.value[
	    tabinf_1.imynl + loc - 1], &blank_1.value[tabinf_1.lvn + jord - 1]
	    , &blank_1.value[tabinf_1.imvn + jord - 1], &xreal, &ximag);
    blank_1.value[tabinf_1.lvn + iord - 1] -= xreal;
    blank_1.value[tabinf_1.imvn + iord - 1] -= ximag;
    goto L50;

/*  REORDER SOLUTION VECTOR */

L60:
    i__1 = cirdat_1.nstop;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = nodplc[tabinf_1.irswpr + i__ - 1];
	k = nodplc[tabinf_1.icswpf + j - 1];
	blank_1.value[tabinf_1.ndiag + i__ - 1] = blank_1.value[tabinf_1.lvn 
		+ k - 1];
	blank_1.value[tabinf_1.ndiag + i__ + cirdat_1.nstop - 1] = 
		blank_1.value[tabinf_1.imvn + k - 1];
/* L70: */
    }
    copy8_(&blank_1.value[tabinf_1.ndiag], &blank_1.value[tabinf_1.lvn], &
	    cirdat_1.nstop);
    copy8_(&blank_1.value[tabinf_1.ndiag + 1 + cirdat_1.nstop - 1], &
	    blank_1.value[tabinf_1.imvn], &cirdat_1.nstop);
    i__1 = cirdat_1.nstop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = tabinf_1.lcvn + i__ - 1;
	r__1 = (real) blank_1.value[tabinf_1.lvn + i__ - 1];
	r__2 = (real) blank_1.value[tabinf_1.imvn + i__ - 1];
	q__1.r = r__1, q__1.i = r__2;
	cvalue[i__2].r = q__1.r, cvalue[i__2].i = q__1.i;
/* L120: */
    }
    i__1 = tabinf_1.lcvn;
    cvalue[i__1].r = 0.f, cvalue[i__1].i = 0.f;

/*  FINISHED */

    return 0;
} /* acasol_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int dinit_(void)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double exp(doublereal), log(doublereal);

    /* Local variables */
    static doublereal pc, gm, pe, go, tf, vd, xm, tr, cb1, cb2, gm2, gm3, go2,
	     go3, cbc, cbe, cbo, arg, vbc;
    static integer loc;
    static doublereal vbe, gpi, geq, evd, ova, xmc, gmu, xme, tau, vte, cdb1, 
	    cdb2, cjc1, cjc2, cje1, cje2, cdj1, cdj2, cb1r, cb2r, geq2, geq3, 
	    gpi2, gpi3, gmo2, gmu2, gmu3, cdbo, area, fcpb, fcpc, fcpe, cjco, 
	    evbc, cjeo;
    static integer locd;
    static doublereal czbc, czbe, evbe, cbor, gmo23;
    static integer locm;
    static doublereal csat, sarg, gm2o3;
    static integer locv, loct;
    static doublereal phib, cdjo, argd;
    extern /* Subroutine */ int getm8_(integer *, integer *);
    static doublereal argbc, argbe, denom;
    extern /* Subroutine */ int getm16_(integer *, integer *);
    static doublereal czero, trivt, twovt;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal twovte, trivte;


/*     THIS ROUTINE PERFORMS STORAGE-ALLOCATION AND ONE-TIME COMPUTATION */
/* NEEDED TO DO THE SMALL-SIGNAL DISTORTION ANALYSIS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    getm8_(&tabinf_1.ld0, &cirdat_1.ndist);
    i__1 = cirdat_1.nstop * 5;
    getm16_(&tabinf_1.ld1, &i__1);

/*  BIPOLAR JUNCTION TRANSISTORS */

    loc = cirdat_1.locate[11];
L100:
    if (loc == 0 || nodplc[loc + 35] != 0) {
	goto L200;
    }
    locv = nodplc[loc];
    area = blank_1.value[locv];
    locm = nodplc[loc + 7];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 21];
    locd = tabinf_1.ld0 + nodplc[loc + 22];
    csat = blank_1.value[locm] * area;
    ova = blank_1.value[locm + 3];
    tf = blank_1.value[locm + 23];
    tr = blank_1.value[locm + 32];
    czbe = blank_1.value[locm + 20] * area;
    czbc = blank_1.value[locm + 28] * area;
    pe = blank_1.value[locm + 21];
    xme = blank_1.value[locm + 22];
    pc = blank_1.value[locm + 29];
    xmc = blank_1.value[locm + 30];
    fcpe = blank_1.value[locm + 45];
    fcpc = blank_1.value[locm + 49];
    vbe = blank_1.value[loct - 1];
    vbc = blank_1.value[loct];
    gpi = blank_1.value[loct + 3];
    go = blank_1.value[loct + 6];
    gm = blank_1.value[loct + 5];
    gmu = blank_1.value[loct + 4];
    if (vbe > 0.) {
	goto L110;
    }
    evbe = 1.;
    cbe = csat * vbe / status_1.vt;
    goto L120;
L110:
    evbe = exp(vbe / status_1.vt);
    cbe = csat * (evbe - 1.);
L120:
    if (vbc > 0.) {
	goto L130;
    }
    evbc = 1.;
    cbc = csat * vbc / status_1.vt;
    arg = 1. - vbc / pc;
    goto L140;
L130:
    evbc = exp(vbc / status_1.vt);
    cbc = csat * (evbc - 1.);
L140:
    if (vbe >= fcpe) {
	goto L150;
    }
    arg = 1. - vbe / pe;
    sarg = exp(xme * log(arg));
    cjeo = czbe / sarg;
    argbe = pe - vbe;
    cje1 = xme * cjeo / argbe;
    cje2 = (xme + 1.) * cje1 / argbe;
    goto L160;
L150:
    denom = exp((xme + 1.) * log(1. - fcpe));
    cjeo = czbe * (1. - fcpe * (xme + 1.) + xme * vbe / pe) / denom;
    cje1 = czbe * xme / (denom * pe);
    cje2 = 0.;
L160:
    if (vbc >= fcpc) {
	goto L170;
    }
    arg = 1. - vbc / pc;
    sarg = exp(xmc * log(arg));
    cjco = czbc / sarg;
    argbc = pc - vbc;
    cjc1 = xmc * cjco / argbc;
    cjc2 = (xmc + 1.) * cjc1 / argbc;
    goto L180;
L170:
    denom = exp((xmc + 1.) * log(1. - fcpc));
    cjco = czbc * (1. - fcpc * (xmc + 1.) + xmc * vbc / pc) / denom;
    cjc1 = czbc * xmc / (denom * pc);
    cjc2 = 0.;
L180:
    twovt = status_1.vt + status_1.vt;
    go2 = (-go + csat * (evbe + evbc) * ova) / twovt;
    gmo2 = (cbe + csat) * ova / status_1.vt - go2 * 2.;
    gm2 = (gm + go) / twovt - gmo2 - go2;
    gmu2 = gmu / twovt;
    if (vbc <= 0.) {
	gmu2 = 0.;
    }
    gpi2 = gpi / twovt;
    if (vbe <= 0.) {
	gpi2 = 0.;
    }
    cbo = tf * csat * evbe / status_1.vt;
    cbor = tr * csat * evbc / status_1.vt;
    cb1 = cbo / status_1.vt;
    cb1r = cbor / status_1.vt;
    trivt = status_1.vt * 3.;
    go3 = -(go2 + (cbc + csat) * ova / twovt) / trivt;
    gmo23 = go3 * -3.;
    gm2o3 = -gmo23 + (cbe + csat) * ova / (status_1.vt * twovt);
    gm3 = (gm2 - (cbe - cbc) * ova / twovt) / trivt;
    gmu3 = gmu2 / trivt;
    gpi3 = gpi2 / trivt;
    cb2 = cb1 / twovt;
    cb2r = cb1r / twovt;
    blank_1.value[locd - 1] = cje1;
    blank_1.value[locd] = cje2;
    blank_1.value[locd + 1] = cjc1;
    blank_1.value[locd + 2] = cjc2;
    blank_1.value[locd + 3] = go2;
    blank_1.value[locd + 4] = gmo2;
    blank_1.value[locd + 5] = gm2;
    blank_1.value[locd + 6] = gmu2;
    blank_1.value[locd + 7] = gpi2;
    blank_1.value[locd + 8] = cbo;
    blank_1.value[locd + 9] = cbor;
    blank_1.value[locd + 10] = cb1;
    blank_1.value[locd + 11] = cb1r;
    blank_1.value[locd + 12] = go3;
    blank_1.value[locd + 13] = gmo23;
    blank_1.value[locd + 14] = gm2o3;
    blank_1.value[locd + 15] = gm3;
    blank_1.value[locd + 16] = gmu3;
    blank_1.value[locd + 17] = gpi3;
    blank_1.value[locd + 18] = cb2;
    blank_1.value[locd + 19] = cb2r;
    loc = nodplc[loc - 1];
    goto L100;

/*  DIODES */

L200:
    loc = cirdat_1.locate[10];
L210:
    if (loc == 0 || nodplc[loc + 15] != 0) {
	goto L300;
    }
    locv = nodplc[loc];
    area = blank_1.value[locv];
    locm = nodplc[loc + 4];
    locm = nodplc[locm];
    loct = tabinf_1.lx0 + nodplc[loc + 10];
    locd = tabinf_1.ld0 + nodplc[loc + 11];
    csat = blank_1.value[locm] * area;
    vte = blank_1.value[locm + 2] * status_1.vt;
    tau = blank_1.value[locm + 3];
    czero = blank_1.value[locm + 4] * area;
    phib = blank_1.value[locm + 5];
    xm = blank_1.value[locm + 6];
    fcpb = blank_1.value[locm + 11];
    vd = blank_1.value[loct - 1];
    geq = blank_1.value[loct + 1];
    evd = 1.;
    if (vd >= 0.) {
	evd = exp(vd / vte);
    }
    if (vd >= fcpb) {
	goto L220;
    }
    arg = 1. - vd / phib;
    sarg = exp(xm * log(arg));
    cdjo = czero / sarg;
    argd = phib - vd;
    cdj1 = xm * cdjo / argd;
    cdj2 = (xm + 1.) * cdj1 / argd;
    goto L230;
L220:
    denom = exp((xm + 1.) * log(1. - fcpb));
    cdjo = czero * (1. - fcpb * (xm + 1.) + xm * vd / phib) / denom;
    cdj1 = czero * xm / (denom * phib);
    cdj2 = 0.;
    cdj2 = 0.;
L230:
    cdbo = tau * csat * evd / vte;
    cdb1 = cdbo / vte;
    twovte = vte * 2.;
    geq2 = geq / twovte;
    if (vd <= 0.) {
	geq2 = 0.;
    }
    trivte = vte * 3.;
    geq3 = geq2 / trivte;
    cdb2 = cdb1 / twovte;
    blank_1.value[locd - 1] = cdj1;
    blank_1.value[locd] = cdj2;
    blank_1.value[locd + 1] = cdbo;
    blank_1.value[locd + 2] = cdb1;
    blank_1.value[locd + 3] = geq2;
    blank_1.value[locd + 4] = geq3;
    blank_1.value[locd + 5] = cdb2;
    loc = nodplc[loc - 1];
    goto L210;

/*  FINISHED */

L300:
    return 0;
} /* dinit_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int disto_(integer *loco)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_3232 = { "DISTORTION ANALYSIS             ", 0. };

#define distit ((doublereal *)&equiv_3232)


    /* Format strings */
    static char fmt_111[] = "(///5x,\0022ND HARMONIC DISTORTION\002,30x,\002"
	    "FREQ1 = \002,1pd9.2,\002  HZ\002//5x,\002DISTORTION FREQUENCY "
	    " \002,d9.2,\002  HZ\002,16x,\002MAG \002,d9.3,3x,\002PHS \002,0p"
	    "f7.2)";
    static char fmt_121[] = "(\0021\002,4x,\0023RD HARMONIC DISTORTION\002,3"
	    "0x,\002FREQ1 = \002,1pd9.2,\002  HZ\002//5x,\002DISTORTION FREQU"
	    "ENCY  \002,d9.2,\002  HZ\002,16x,\002MAG \002,d9.3,3x,\002PHS"
	    " \002,0pf7.2)";
    static char fmt_151[] = "(\0021\002,4x,\0022ND ORDER INTERMODULATION DIF"
	    "FERENCE COMPONENT\002,7x,\002FREQ1 = \002,1pd9.2,\002  HZ\002,15"
	    "x,\002FREQ2 = \002,d9.2,\002  HZ\002//5x,\002DISTORTION FREQUENC"
	    "Y  \002,d9.2,\002  HZ\002,16x,\002MAG \002,d9.3,3x,\002PHS \002,"
	    "0pf7.2,9x,\002MAG \002,1pd9.3,3x,\002PHS \002,0pf7.2)";
    static char fmt_161[] = "(\0021\002,4x,\0022ND ORDER INTERMODULATION SUM"
	    " COMPONENT\002,14x,\002FREQ1 = \002,1pd9.2,\002  HZ\002,15x,\002"
	    "FREQ2 = \002,d9.2,\002  HZ\002//5x,\002DISTORTION FREQUENCY  "
	    "\002,d9.2,\002  HZ\002,16x,\002MAG \002,d9.3,3x,\002PHS \002,0pf"
	    "7.2,9x,\002MAG \002,1pd9.3,3x,\002PHS \002,0pf7.2)";
    static char fmt_171[] = "(\0021\002,4x,\0023RD ORDER INTERMODULATION DIF"
	    "FERENCE COMPONENT\002,7x,\002FREQ1 = \002,1pd9.2,\002  HZ\002,15"
	    "x,\002FREQ2 = \002,d9.2,\002  HZ\002//5x,\002DISTORTION FREQUENC"
	    "Y  \002,d9.2,\002  HZ\002,16x,\002MAG \002,d9.3,3x,\002PHS \002,"
	    "0pf7.2,9x,\002MAG \002,1pd9.3,3x,\002PHS \002,0pf7.2)";
    static char fmt_211[] = "(\0020WARNING:  UNDERFLOW \002,i4,\002 TIME(S) "
	    "IN DISTORTION ANALYSIS AT FREQ = \002,1pd9.3,\002 HZ\002)";
    static char fmt_301[] = "(////1x,\002BJT DISTORTION COMPONENTS\002//1x"
	    ",\002NAME\002,11x,\002GM\002,8x,\002GPI\002,7x,\002GO\002,8x,"
	    "\002GMU\002,6x,\002GMO2\002,7x,\002CB\002,8x,\002CBR\002,7x,\002"
	    "CJE\002,7x,\002CJC\002,6x,\002TOTAL\002)";
    static char fmt_311[] = "(////1x,\002BJT DISTORTION COMPONENTS\002//1x"
	    ",\002NAME\002,11x,\002GM\002,8x,\002GPI\002,7x,\002GO\002,8x,"
	    "\002GMU\002,6x,\002GMO2\002,7x,\002CB\002,8x,\002CBR\002,7x,\002"
	    "CJE\002,7x,\002CJC\002,6x,\002GM203\002,5x,\002GMO23\002,5x,\002"
	    "TOTAL\002)";
    static char fmt_446[] = "(\0020\002,a8,\002MAG\002,1p12d10.3)";
    static char fmt_447[] = "(9x,\002PHS\002,12(1x,f7.2,2x))";
    static char fmt_501[] = "(////1x,\002DIODE DISTORTION COMPONENTS\002//"
	    "1x,\002NAME\002,11x,\002GEQ\002,7x,\002CB\002,8x,\002CJ\002,7x"
	    ",\002TOTAL\002)";
    static char fmt_781[] = "(///5x,\002HD2     MAGNITUDE  \002,1pd10.3,5x"
	    ",\002PHASE  \002,0pf7.2,5x,\002=  \002,f7.2,\002  DB\002)";
    static char fmt_791[] = "(///5x,\002HD3     MAGNITUDE  \002,1pd10.3,5x"
	    ",\002PHASE  \002,0pf7.2,5x,\002=  \002,f7.2,\002  DB\002)";
    static char fmt_841[] = "(///5x,\002IM2D    MAGNITUDE  \002,1pd10.3,5x"
	    ",\002PHASE  \002,0pf7.2,5x,\002=  \002,f7.2,\002  DB\002)";
    static char fmt_851[] = "(///5x,\002IM2S    MAGNITUDE  \002,1pd10.3,5x"
	    ",\002PHASE  \002,0pf7.2,5x,\002=  \002,f7.2,\002  DB\002)";
    static char fmt_861[] = "(///5x,\002IM3     MAGNITUDE  \002,1pd10.3,5x"
	    ",\002PHASE  \002,0pf7.2,5x,\002=  \002,f7.2,\002  DB\002)";
    static char fmt_866[] = "(////5x,\002APPROXIMATE CROSS MODULATION COMPON"
	    "ENTS\002)";
    static char fmt_871[] = "(/5x,\002CMA     MAGNITUDE  \002,1pd10.3,24x"
	    ",\002=  \002,0pf7.2,\002  DB\002)";
    static char fmt_881[] = "(/5x,\002CMP     MAGNITUDE  \002,1pd10.3,24x"
	    ",\002=  \002,0pf7.2,\002  DB\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    doublereal d__1;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9, q__10;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8;
    static complex equiv_1[12];

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    void r_cnjg(complex *, complex *);
    double r_imag(complex *), d_lg10(doublereal *), cos(doublereal), sin(
	    doublereal);

    /* Local variables */
    static integer j;
    static doublereal cb1, cb2, gm2, gm3, go2, go3, cma, arg;
    static complex bcw, bew, cew;
    static integer loc;
    static doublereal cmp;
#define vdo ((real *)equiv_1)
    static doublereal cdb1, cdb2, cjc1, cjc2, cje1, cje2, cdj1, cdj2, cb1r, 
	    cb2r;
    static complex bc2w, bcw2, be2w, ce2w, bew2, cew2, dsg2;
    static doublereal gmo2, gpi2, gpi3, geq2, gmu2, gmu3, geq3;
    static complex bcw12, bew12, cew12;
    static integer locd;
    static doublereal omag;
    static integer idnn;
    static doublereal gmo23;
#define cvdo (equiv_1)
    static integer idnp, locv, loct;
    static doublereal gm2o3, xmag;
    static integer kntr;
    static doublereal xphs;
    static integer locm;
    static complex dscb1;
    static doublereal o2mag;
    static integer node1, node2, node3;
    static doublereal o3mag;
    static complex dsgm2, dsgo2;
    static doublereal freq1, freq2, o2log, o3log;
    static integer icvw1, icvw2;
    static doublereal o2phs, o3phs;
    extern /* Subroutine */ int zero8_(doublereal *, integer *);
    static complex cvabc, cvabe, cvace, dgm2o3, dgmo23;
    static doublereal rload, freqd;
    extern /* Subroutine */ int acsol_(void);
    static integer icv2w1, icvw12;
    static doublereal o12mag, o12phs;
    static complex dscje1, dscjc1, dscdb1, dscdj1, dscb1r, cvout;
    static integer iprnt;
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static complex difvi1, difvi2, difvi3;
    extern /* Subroutine */ int copy16_(complex *, complex *, integer *);
    static complex difvn1, difvn2, difvn3, dsgpi2, dsgmo2;
    static doublereal ow2mag, o12log, o21mag, o21phs;
    static complex dsgmu2;
    static doublereal o21log;
    static complex disto1, disto2, disto3;
    static integer iflag;
    static doublereal ow2phs;
    extern /* Subroutine */ int acload_(void), acdcmp_(void);
    static integer icvadj;
    extern /* Subroutine */ int acasol_(void);
    static doublereal cmalog;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static complex cvdist;
    extern /* Subroutine */ int magphs_(complex *, doublereal *, doublereal *)
	    ;
    static doublereal ophase;
    static integer kdisto, ititle;
    static doublereal cmplog;

    /* Fortran I/O blocks */
    static cilist io___3116 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___3117 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___3118 = { 0, 0, 0, fmt_151, 0 };
    static cilist io___3121 = { 0, 0, 0, fmt_161, 0 };
    static cilist io___3122 = { 0, 0, 0, fmt_171, 0 };
    static cilist io___3123 = { 0, 0, 0, fmt_211, 0 };
    static cilist io___3186 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___3187 = { 0, 0, 0, fmt_446, 0 };
    static cilist io___3188 = { 0, 0, 0, fmt_447, 0 };
    static cilist io___3191 = { 0, 0, 0, fmt_311, 0 };
    static cilist io___3192 = { 0, 0, 0, fmt_446, 0 };
    static cilist io___3193 = { 0, 0, 0, fmt_447, 0 };
    static cilist io___3204 = { 0, 0, 0, fmt_501, 0 };
    static cilist io___3205 = { 0, 0, 0, fmt_446, 0 };
    static cilist io___3206 = { 0, 0, 0, fmt_447, 0 };
    static cilist io___3210 = { 0, 0, 0, fmt_781, 0 };
    static cilist io___3214 = { 0, 0, 0, fmt_791, 0 };
    static cilist io___3218 = { 0, 0, 0, fmt_841, 0 };
    static cilist io___3219 = { 0, 0, 0, fmt_851, 0 };
    static cilist io___3223 = { 0, 0, 0, fmt_861, 0 };
    static cilist io___3228 = { 0, 0, 0, fmt_866, 0 };
    static cilist io___3229 = { 0, 0, 0, fmt_871, 0 };
    static cilist io___3230 = { 0, 0, 0, fmt_881, 0 };



/*     THIS ROUTINE PERFORMS THE SMALL-SIGNAL DISTORTION ANALYSIS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    icvw1 = tabinf_1.ld1;
    icv2w1 = icvw1 + cirdat_1.nstop;
    icvw2 = icv2w1 + cirdat_1.nstop;
    icvw12 = icvw2 + cirdat_1.nstop;
    icvadj = icvw12 + cirdat_1.nstop;
    iprnt = 0;
    if (status_1.icalc >= 2) {
	goto L10;
    }
    idnp = nodplc[ac_1.idist + 1];
    idnn = nodplc[ac_1.idist + 2];
    locv = nodplc[ac_1.idist];
    rload = 1. / blank_1.value[locv];
    kntr = 1;
L10:
    if (ac_1.idprt == 0) {
	goto L30;
    }
    if (kntr > status_1.icalc) {
	goto L30;
    }
    iprnt = 1;
    kntr += ac_1.idprt;
    title_(&c__0, &miscel_1.lwidth, &c__1, distit);
L30:
    i__1 = *loco;
    freq1 = (doublereal) cvalue[i__1].r;
    freq2 = ac_1.skw2 * freq1;
    copy16_(&cvalue[tabinf_1.lcvn], &cvalue[icvw1], &cirdat_1.nstop);
    i__1 = icvw1 + idnp - 1;
    i__2 = icvw1 + idnn - 1;
    q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
	    cvalue[i__2].i;
    cvout.r = q__1.r, cvout.i = q__1.i;
    magphs_(&cvout, &omag, &ophase);

/*  BEGIN THE DISTORTION ANALYSIS */

    for (kdisto = 1; kdisto <= 7; ++kdisto) {
	cvdist.r = 0.f, cvdist.i = 0.f;
	switch (kdisto) {
	    case 1:  goto L1000;
	    case 2:  goto L110;
	    case 3:  goto L120;
	    case 4:  goto L130;
	    case 5:  goto L140;
	    case 6:  goto L160;
	    case 7:  goto L170;
	}
L110:
	freqd = freq1 * 2.;
	arg = sqrt(rload * 2. * ac_1.refprl) / (omag * omag);
	if (iprnt == 0) {
	    goto L200;
	}
	io___3116.ciunit = status_1.iofile;
	s_wsfe(&io___3116);
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ophase, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L200;
L120:
	freqd = freq1 * 3.;
	arg = rload * 2. * ac_1.refprl / (omag * omag * omag);
	if (iprnt == 0) {
	    goto L200;
	}
	io___3117.ciunit = status_1.iofile;
	s_wsfe(&io___3117);
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ophase, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L200;
L130:
	freqd = freq2;
	goto L200;
L140:
	freqd = freq1 - freq2;
	arg = sqrt(rload * 2. * ac_1.refprl) * ac_1.spw2 / (omag * omag);
	if (iprnt == 0) {
	    goto L200;
	}
	io___3118.ciunit = status_1.iofile;
	s_wsfe(&io___3118);
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freq2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ophase, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2phs, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L200;
L160:
	freqd = freq1 + freq2;
	arg = sqrt(rload * 2. * ac_1.refprl) * ac_1.spw2 / (omag * omag);
	if (iprnt == 0) {
	    goto L200;
	}
	io___3121.ciunit = status_1.iofile;
	s_wsfe(&io___3121);
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freq2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ophase, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2phs, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L200;
L170:
	freqd = freq1 * 2. - freq2;
	arg = rload * 2. * ac_1.refprl * ac_1.spw2 / (omag * omag * omag);
	if (iprnt == 0) {
	    goto L200;
	}
	io___3122.ciunit = status_1.iofile;
	s_wsfe(&io___3122);
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freq2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ophase, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ow2phs, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  LOAD AND DECOMPOSE Y MATRIX */

L200:
	status_1.omega = knstnt_1.twopi * freqd;
	flags_1.igoof = 0;
	acload_();
	acdcmp_();
	if (flags_1.igoof == 0) {
	    goto L220;
	}
	io___3123.ciunit = status_1.iofile;
	s_wsfe(&io___3123);
	do_fio(&c__1, (char *)&flags_1.igoof, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&freqd, (ftnlen)sizeof(doublereal));
	e_wsfe();
	flags_1.igoof = 0;
L220:
	if (kdisto == 4) {
	    goto L710;
	}

/*  OBTAIN ADJOINT SOLUTION */

	zero8_(&blank_1.value[tabinf_1.lvn], &cirdat_1.nstop);
	zero8_(&blank_1.value[tabinf_1.imvn], &cirdat_1.nstop);
	blank_1.value[tabinf_1.lvn + idnp - 1] = -1.;
	blank_1.value[tabinf_1.lvn + idnn - 1] = 1.;
	acasol_();
	copy16_(&cvalue[tabinf_1.lcvn], &cvalue[icvadj], &cirdat_1.nstop);
	zero8_(&blank_1.value[tabinf_1.lvn], &cirdat_1.nstop);
	zero8_(&blank_1.value[tabinf_1.imvn], &cirdat_1.nstop);

/*  BJTS */

	if (cirdat_1.jelcnt[11] == 0) {
	    goto L500;
	}
	ititle = 0;
/* L301: */
/* L311: */
/* L320: */
	loc = cirdat_1.locate[11];
L330:
	if (loc == 0 || nodplc[loc + 35] != 0) {
	    goto L500;
	}
	locv = nodplc[loc];
	loct = tabinf_1.lx0 + nodplc[loc + 21];
	locd = tabinf_1.ld0 + nodplc[loc + 22];
	node1 = nodplc[loc + 4];
	node2 = nodplc[loc + 5];
	node3 = nodplc[loc + 6];
	cje1 = blank_1.value[locd - 1];
	cje2 = blank_1.value[locd];
	cjc1 = blank_1.value[locd + 1];
	cjc2 = blank_1.value[locd + 2];
	go2 = blank_1.value[locd + 3];
	gmo2 = blank_1.value[locd + 4];
	gm2 = blank_1.value[locd + 5];
	gmu2 = blank_1.value[locd + 6];
	gpi2 = blank_1.value[locd + 7];
	cb1 = blank_1.value[locd + 10];
	cb1r = blank_1.value[locd + 11];
	go3 = blank_1.value[locd + 12];
	gmo23 = blank_1.value[locd + 13];
	gm2o3 = blank_1.value[locd + 14];
	gm3 = blank_1.value[locd + 15];
	gmu3 = blank_1.value[locd + 16];
	gpi3 = blank_1.value[locd + 17];
	cb2 = blank_1.value[locd + 18];
	cb2r = blank_1.value[locd + 19];
	i__1 = icvw1 + node2 - 1;
	i__2 = icvw1 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew.r = q__1.r, bew.i = q__1.i;
	i__1 = icvw1 + node1 - 1;
	i__2 = icvw1 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cew.r = q__1.r, cew.i = q__1.i;
	i__1 = icvw1 + node2 - 1;
	i__2 = icvw1 + node1 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bcw.r = q__1.r, bcw.i = q__1.i;
	if (kdisto == 2) {
	    goto L370;
	}
	i__1 = icv2w1 + node2 - 1;
	i__2 = icv2w1 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	be2w.r = q__1.r, be2w.i = q__1.i;
	i__1 = icv2w1 + node1 - 1;
	i__2 = icv2w1 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	ce2w.r = q__1.r, ce2w.i = q__1.i;
	i__1 = icv2w1 + node2 - 1;
	i__2 = icv2w1 + node1 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bc2w.r = q__1.r, bc2w.i = q__1.i;
	if (kdisto == 3) {
	    goto L380;
	}
	i__1 = icvw2 + node2 - 1;
	i__2 = icvw2 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew2.r = q__1.r, bew2.i = q__1.i;
	i__1 = icvw2 + node1 - 1;
	i__2 = icvw2 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cew2.r = q__1.r, cew2.i = q__1.i;
	i__1 = icvw2 + node2 - 1;
	i__2 = icvw2 + node1 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bcw2.r = q__1.r, bcw2.i = q__1.i;
	if (kdisto == 5) {
	    goto L390;
	}
	if (kdisto == 6) {
	    goto L400;
	}
	i__1 = icvw12 + node2 - 1;
	i__2 = icvw12 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew12.r = q__1.r, bew12.i = q__1.i;
	i__1 = icvw12 + node1 - 1;
	i__2 = icvw12 + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cew12.r = q__1.r, cew12.i = q__1.i;
	i__1 = icvw12 + node2 - 1;
	i__2 = icvw12 + node1 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bcw12.r = q__1.r, bcw12.i = q__1.i;
	goto L410;

/*  CALCULATE HD2 CURRENT GENERATORS */

L370:
	z__2.r = cew.r * .5, z__2.i = cew.i * .5;
	z__1.r = z__2.r * cew.r - z__2.i * cew.i, z__1.i = z__2.r * cew.i + 
		z__2.i * cew.r;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	z__2.r = bew.r * .5, z__2.i = bew.i * .5;
	z__1.r = z__2.r * bew.r - z__2.i * bew.i, z__1.i = z__2.r * bew.i + 
		z__2.i * bew.r;
	difvn2.r = z__1.r, difvn2.i = z__1.i;
	z__2.r = bcw.r * .5, z__2.i = bcw.i * .5;
	z__1.r = z__2.r * bcw.r - z__2.i * bcw.i, z__1.i = z__2.r * bcw.i + 
		z__2.i * bcw.r;
	difvn3.r = z__1.r, difvn3.i = z__1.i;
	d__1 = gmo2 * .5;
	z__2.r = d__1 * bew.r, z__2.i = d__1 * bew.i;
	z__1.r = z__2.r * cew.r - z__2.i * cew.i, z__1.i = z__2.r * cew.i + 
		z__2.i * cew.r;
	dsgmo2.r = z__1.r, dsgmo2.i = z__1.i;
	goto L420;

/*  CALCULATE HD3 CURRENT GENERATORS */

L380:
	z__2.r = cew.r * .5, z__2.i = cew.i * .5;
	z__1.r = z__2.r * ce2w.r - z__2.i * ce2w.i, z__1.i = z__2.r * ce2w.i 
		+ z__2.i * ce2w.r;
	difvi1.r = z__1.r, difvi1.i = z__1.i;
	z__3.r = cew.r * .25, z__3.i = cew.i * .25;
	z__2.r = z__3.r * cew.r - z__3.i * cew.i, z__2.i = z__3.r * cew.i + 
		z__3.i * cew.r;
	z__1.r = z__2.r * cew.r - z__2.i * cew.i, z__1.i = z__2.r * cew.i + 
		z__2.i * cew.r;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	z__2.r = bew.r * .5, z__2.i = bew.i * .5;
	z__1.r = z__2.r * be2w.r - z__2.i * be2w.i, z__1.i = z__2.r * be2w.i 
		+ z__2.i * be2w.r;
	difvi2.r = z__1.r, difvi2.i = z__1.i;
	z__3.r = bew.r * .25, z__3.i = bew.i * .25;
	z__2.r = z__3.r * bew.r - z__3.i * bew.i, z__2.i = z__3.r * bew.i + 
		z__3.i * bew.r;
	z__1.r = z__2.r * bew.r - z__2.i * bew.i, z__1.i = z__2.r * bew.i + 
		z__2.i * bew.r;
	difvn2.r = z__1.r, difvn2.i = z__1.i;
	z__2.r = bcw.r * .5, z__2.i = bcw.i * .5;
	z__1.r = z__2.r * bc2w.r - z__2.i * bc2w.i, z__1.i = z__2.r * bc2w.i 
		+ z__2.i * bc2w.r;
	difvi3.r = z__1.r, difvi3.i = z__1.i;
	z__3.r = bcw.r * .25, z__3.i = bcw.i * .25;
	z__2.r = z__3.r * bcw.r - z__3.i * bcw.i, z__2.i = z__3.r * bcw.i + 
		z__3.i * bcw.r;
	z__1.r = z__2.r * bcw.r - z__2.i * bcw.i, z__1.i = z__2.r * bcw.i + 
		z__2.i * bcw.r;
	difvn3.r = z__1.r, difvn3.i = z__1.i;
	q__2.r = bew.r * ce2w.r - bew.i * ce2w.i, q__2.i = bew.r * ce2w.i + 
		bew.i * ce2w.r;
	q__3.r = be2w.r * cew.r - be2w.i * cew.i, q__3.i = be2w.r * cew.i + 
		be2w.i * cew.r;
	q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
	z__2.r = gmo2 * q__1.r, z__2.i = gmo2 * q__1.i;
	z__1.r = z__2.r * .5, z__1.i = z__2.i * .5;
	dsgmo2.r = z__1.r, dsgmo2.i = z__1.i;
	goto L430;

/*  CALCULATE IM2D CURRENT GENERATORS */

L390:
	r_cnjg(&q__2, &cew2);
	q__1.r = cew.r * q__2.r - cew.i * q__2.i, q__1.i = cew.r * q__2.i + 
		cew.i * q__2.r;
	difvn1.r = q__1.r, difvn1.i = q__1.i;
	r_cnjg(&q__2, &bew2);
	q__1.r = bew.r * q__2.r - bew.i * q__2.i, q__1.i = bew.r * q__2.i + 
		bew.i * q__2.r;
	difvn2.r = q__1.r, difvn2.i = q__1.i;
	r_cnjg(&q__2, &bcw2);
	q__1.r = bcw.r * q__2.r - bcw.i * q__2.i, q__1.i = bcw.r * q__2.i + 
		bcw.i * q__2.r;
	difvn3.r = q__1.r, difvn3.i = q__1.i;
	d__1 = gmo2 * .5;
	r_cnjg(&q__3, &cew2);
	q__2.r = bew.r * q__3.r - bew.i * q__3.i, q__2.i = bew.r * q__3.i + 
		bew.i * q__3.r;
	r_cnjg(&q__5, &bew2);
	q__4.r = cew.r * q__5.r - cew.i * q__5.i, q__4.i = cew.r * q__5.i + 
		cew.i * q__5.r;
	q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dsgmo2.r = z__1.r, dsgmo2.i = z__1.i;
	goto L420;

/*  CALCULATE IM2S CURRENT GENERATORS */

L400:
	q__1.r = cew.r * cew2.r - cew.i * cew2.i, q__1.i = cew.r * cew2.i + 
		cew.i * cew2.r;
	difvn1.r = q__1.r, difvn1.i = q__1.i;
	q__1.r = bew.r * bew2.r - bew.i * bew2.i, q__1.i = bew.r * bew2.i + 
		bew.i * bew2.r;
	difvn2.r = q__1.r, difvn2.i = q__1.i;
	q__1.r = bcw.r * bcw2.r - bcw.i * bcw2.i, q__1.i = bcw.r * bcw2.i + 
		bcw.i * bcw2.r;
	difvn3.r = q__1.r, difvn3.i = q__1.i;
	d__1 = gmo2 * .5;
	q__2.r = bew.r * cew2.r - bew.i * cew2.i, q__2.i = bew.r * cew2.i + 
		bew.i * cew2.r;
	q__3.r = bew2.r * cew.r - bew2.i * cew.i, q__3.i = bew2.r * cew.i + 
		bew2.i * cew.r;
	q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dsgmo2.r = z__1.r, dsgmo2.i = z__1.i;
	goto L420;

/*  CALCULATE IM3 CURRENT GENERATORS */

L410:
	r_cnjg(&q__3, &cew2);
	q__2.r = ce2w.r * q__3.r - ce2w.i * q__3.i, q__2.i = ce2w.r * q__3.i 
		+ ce2w.i * q__3.r;
	q__4.r = cew.r * cew12.r - cew.i * cew12.i, q__4.i = cew.r * cew12.i 
		+ cew.i * cew12.r;
	q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
	z__1.r = q__1.r * .5, z__1.i = q__1.i * .5;
	difvi1.r = z__1.r, difvi1.i = z__1.i;
	r_cnjg(&q__3, &bew2);
	q__2.r = be2w.r * q__3.r - be2w.i * q__3.i, q__2.i = be2w.r * q__3.i 
		+ be2w.i * q__3.r;
	q__4.r = bew.r * bew12.r - bew.i * bew12.i, q__4.i = bew.r * bew12.i 
		+ bew.i * bew12.r;
	q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
	z__1.r = q__1.r * .5, z__1.i = q__1.i * .5;
	difvi2.r = z__1.r, difvi2.i = z__1.i;
	r_cnjg(&q__3, &bcw2);
	q__2.r = bc2w.r * q__3.r - bc2w.i * q__3.i, q__2.i = bc2w.r * q__3.i 
		+ bc2w.i * q__3.r;
	q__4.r = bcw.r * bcw12.r - bcw.i * bcw12.i, q__4.i = bcw.r * bcw12.i 
		+ bcw.i * bcw12.r;
	q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
	z__1.r = q__1.r * .5, z__1.i = q__1.i * .5;
	difvi3.r = z__1.r, difvi3.i = z__1.i;
	q__2.r = cew.r * cew.r - cew.i * cew.i, q__2.i = cew.r * cew.i + 
		cew.i * cew.r;
	r_cnjg(&q__3, &cew2);
	q__1.r = q__2.r * q__3.r - q__2.i * q__3.i, q__1.i = q__2.r * q__3.i 
		+ q__2.i * q__3.r;
	z__1.r = q__1.r * .75, z__1.i = q__1.i * .75;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	q__2.r = bew.r * bew.r - bew.i * bew.i, q__2.i = bew.r * bew.i + 
		bew.i * bew.r;
	r_cnjg(&q__3, &bew2);
	q__1.r = q__2.r * q__3.r - q__2.i * q__3.i, q__1.i = q__2.r * q__3.i 
		+ q__2.i * q__3.r;
	z__1.r = q__1.r * .75, z__1.i = q__1.i * .75;
	difvn2.r = z__1.r, difvn2.i = z__1.i;
	q__2.r = bcw.r * bcw.r - bcw.i * bcw.i, q__2.i = bcw.r * bcw.i + 
		bcw.i * bcw.r;
	r_cnjg(&q__3, &bcw2);
	q__1.r = q__2.r * q__3.r - q__2.i * q__3.i, q__1.i = q__2.r * q__3.i 
		+ q__2.i * q__3.r;
	z__1.r = q__1.r * .75, z__1.i = q__1.i * .75;
	difvn3.r = z__1.r, difvn3.i = z__1.i;
	d__1 = gmo2 * .5;
	r_cnjg(&q__5, &bew2);
	q__4.r = q__5.r * ce2w.r - q__5.i * ce2w.i, q__4.i = q__5.r * ce2w.i 
		+ q__5.i * ce2w.r;
	q__6.r = bew.r * cew12.r - bew.i * cew12.i, q__6.i = bew.r * cew12.i 
		+ bew.i * cew12.r;
	q__3.r = q__4.r + q__6.r, q__3.i = q__4.i + q__6.i;
	r_cnjg(&q__8, &cew2);
	q__7.r = q__8.r * be2w.r - q__8.i * be2w.i, q__7.i = q__8.r * be2w.i 
		+ q__8.i * be2w.r;
	q__2.r = q__3.r + q__7.r, q__2.i = q__3.i + q__7.i;
	q__9.r = cew.r * bew12.r - cew.i * bew12.i, q__9.i = cew.r * bew12.i 
		+ cew.i * bew12.r;
	q__1.r = q__2.r + q__9.r, q__1.i = q__2.i + q__9.i;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dsgmo2.r = z__1.r, dsgmo2.i = z__1.i;
	goto L430;

L420:
	z__1.r = go2 * difvn1.r, z__1.i = go2 * difvn1.i;
	dsgo2.r = z__1.r, dsgo2.i = z__1.i;
	z__1.r = gm2 * difvn2.r, z__1.i = gm2 * difvn2.i;
	dsgm2.r = z__1.r, dsgm2.i = z__1.i;
	z__1.r = gmu2 * difvn3.r, z__1.i = gmu2 * difvn3.i;
	dsgmu2.r = z__1.r, dsgmu2.i = z__1.i;
	z__1.r = gpi2 * difvn2.r, z__1.i = gpi2 * difvn2.i;
	dsgpi2.r = z__1.r, dsgpi2.i = z__1.i;
	d__1 = cb1 * .5 * status_1.omega;
	r__1 = -r_imag(&difvn2);
	r__2 = difvn2.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscb1.r = z__1.r, dscb1.i = z__1.i;
	d__1 = cb1r * .5 * status_1.omega;
	r__1 = -r_imag(&difvn3);
	r__2 = difvn3.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscb1r.r = z__1.r, dscb1r.i = z__1.i;
	d__1 = cje1 * .5 * status_1.omega;
	r__1 = -r_imag(&difvn2);
	r__2 = difvn2.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscje1.r = z__1.r, dscje1.i = z__1.i;
	d__1 = cjc1 * .5 * status_1.omega;
	r__1 = -r_imag(&difvn3);
	r__2 = difvn3.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscjc1.r = z__1.r, dscjc1.i = z__1.i;
	goto L440;

L430:
	d__1 = go2 * 2.;
	z__2.r = d__1 * difvi1.r, z__2.i = d__1 * difvi1.i;
	z__3.r = go3 * difvn1.r, z__3.i = go3 * difvn1.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	dsgo2.r = z__1.r, dsgo2.i = z__1.i;
	d__1 = gm2 * 2.;
	z__2.r = d__1 * difvi2.r, z__2.i = d__1 * difvi2.i;
	z__3.r = gm3 * difvn2.r, z__3.i = gm3 * difvn2.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	dsgm2.r = z__1.r, dsgm2.i = z__1.i;
	d__1 = gmu2 * 2.;
	z__2.r = d__1 * difvi3.r, z__2.i = d__1 * difvi3.i;
	z__3.r = gmu3 * difvn3.r, z__3.i = gmu3 * difvn3.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	dsgmu2.r = z__1.r, dsgmu2.i = z__1.i;
	d__1 = gpi2 * 2.;
	z__2.r = d__1 * difvi2.r, z__2.i = d__1 * difvi2.i;
	z__3.r = gpi3 * difvn2.r, z__3.i = gpi3 * difvn2.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	dsgpi2.r = z__1.r, dsgpi2.i = z__1.i;
	z__3.r = cb1 * difvi2.r, z__3.i = cb1 * difvi2.i;
	z__5.r = cb2 * difvn2.r, z__5.i = cb2 * difvn2.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscb1.r = z__1.r, dscb1.i = z__1.i;
	r__1 = -r_imag(&dscb1);
	r__2 = dscb1.r;
	q__1.r = r__1, q__1.i = r__2;
	dscb1.r = q__1.r, dscb1.i = q__1.i;
	z__3.r = cb1r * difvi3.r, z__3.i = cb1r * difvi3.i;
	z__5.r = cb2r * difvn3.r, z__5.i = cb2r * difvn3.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscb1r.r = z__1.r, dscb1r.i = z__1.i;
	r__1 = -r_imag(&dscb1r);
	r__2 = dscb1r.r;
	q__1.r = r__1, q__1.i = r__2;
	dscb1r.r = q__1.r, dscb1r.i = q__1.i;
	z__3.r = cje1 * difvi2.r, z__3.i = cje1 * difvi2.i;
	z__5.r = cje2 * difvn2.r, z__5.i = cje2 * difvn2.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscje1.r = z__1.r, dscje1.i = z__1.i;
	r__1 = -r_imag(&dscje1);
	r__2 = dscje1.r;
	q__1.r = r__1, q__1.i = r__2;
	dscje1.r = q__1.r, dscje1.i = q__1.i;
	z__3.r = cjc1 * difvi3.r, z__3.i = cjc1 * difvi3.i;
	z__5.r = cjc2 * difvn3.r, z__5.i = cjc2 * difvn3.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscjc1.r = z__1.r, dscjc1.i = z__1.i;
	r__1 = -r_imag(&dscjc1);
	r__2 = dscjc1.r;
	q__1.r = r__1, q__1.i = r__2;
	dscjc1.r = q__1.r, dscjc1.i = q__1.i;

/*  DETERMINE CONTRIBUTION OF EACH DISTORTION SOURCE */

L440:
	i__1 = icvadj + node2 - 1;
	i__2 = icvadj + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cvabe.r = q__1.r, cvabe.i = q__1.i;
	i__1 = icvadj + node2 - 1;
	i__2 = icvadj + node1 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cvabc.r = q__1.r, cvabc.i = q__1.i;
	i__1 = icvadj + node1 - 1;
	i__2 = icvadj + node3 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cvace.r = q__1.r, cvace.i = q__1.i;
	q__2.r = dsgm2.r + dsgo2.r, q__2.i = dsgm2.i + dsgo2.i;
	q__1.r = q__2.r + dsgmo2.r, q__1.i = q__2.i + dsgmo2.i;
	disto1.r = q__1.r, disto1.i = q__1.i;
	q__2.r = dsgpi2.r + dscb1.r, q__2.i = dsgpi2.i + dscb1.i;
	q__1.r = q__2.r + dscje1.r, q__1.i = q__2.i + dscje1.i;
	disto2.r = q__1.r, disto2.i = q__1.i;
	q__2.r = dsgmu2.r + dscb1r.r, q__2.i = dsgmu2.i + dscb1r.i;
	q__1.r = q__2.r + dscjc1.r, q__1.i = q__2.i + dscjc1.i;
	disto3.r = q__1.r, disto3.i = q__1.i;
	q__1.r = dsgm2.r * cvace.r - dsgm2.i * cvace.i, q__1.i = dsgm2.r * 
		cvace.i + dsgm2.i * cvace.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[0].r = z__1.r, cvdo[0].i = z__1.i;
	q__1.r = dsgpi2.r * cvabe.r - dsgpi2.i * cvabe.i, q__1.i = dsgpi2.r * 
		cvabe.i + dsgpi2.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[1].r = z__1.r, cvdo[1].i = z__1.i;
	q__1.r = dsgo2.r * cvace.r - dsgo2.i * cvace.i, q__1.i = dsgo2.r * 
		cvace.i + dsgo2.i * cvace.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[2].r = z__1.r, cvdo[2].i = z__1.i;
	q__1.r = dsgmu2.r * cvabc.r - dsgmu2.i * cvabc.i, q__1.i = dsgmu2.r * 
		cvabc.i + dsgmu2.i * cvabc.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[3].r = z__1.r, cvdo[3].i = z__1.i;
	q__1.r = dsgmo2.r * cvace.r - dsgmo2.i * cvace.i, q__1.i = dsgmo2.r * 
		cvace.i + dsgmo2.i * cvace.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[4].r = z__1.r, cvdo[4].i = z__1.i;
	q__1.r = dscb1.r * cvabe.r - dscb1.i * cvabe.i, q__1.i = dscb1.r * 
		cvabe.i + dscb1.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[5].r = z__1.r, cvdo[5].i = z__1.i;
	q__1.r = dscb1r.r * cvabc.r - dscb1r.i * cvabc.i, q__1.i = dscb1r.r * 
		cvabc.i + dscb1r.i * cvabc.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[6].r = z__1.r, cvdo[6].i = z__1.i;
	q__1.r = dscje1.r * cvabe.r - dscje1.i * cvabe.i, q__1.i = dscje1.r * 
		cvabe.i + dscje1.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[7].r = z__1.r, cvdo[7].i = z__1.i;
	q__1.r = dscjc1.r * cvabc.r - dscjc1.i * cvabc.i, q__1.i = dscjc1.r * 
		cvabc.i + dscjc1.i * cvabc.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[8].r = z__1.r, cvdo[8].i = z__1.i;
	if (kdisto == 3) {
	    goto L450;
	}
	if (kdisto == 7) {
	    goto L460;
	}
	q__8.r = cvdo[0].r + cvdo[1].r, q__8.i = cvdo[0].i + cvdo[1].i;
	q__7.r = q__8.r + cvdo[2].r, q__7.i = q__8.i + cvdo[2].i;
	q__6.r = q__7.r + cvdo[3].r, q__6.i = q__7.i + cvdo[3].i;
	q__5.r = q__6.r + cvdo[4].r, q__5.i = q__6.i + cvdo[4].i;
	q__4.r = q__5.r + cvdo[5].r, q__4.i = q__5.i + cvdo[5].i;
	q__3.r = q__4.r + cvdo[6].r, q__3.i = q__4.i + cvdo[6].i;
	q__2.r = q__3.r + cvdo[7].r, q__2.i = q__3.i + cvdo[7].i;
	q__1.r = q__2.r + cvdo[8].r, q__1.i = q__2.i + cvdo[8].i;
	cvdo[9].r = q__1.r, cvdo[9].i = q__1.i;
	q__1.r = cvdist.r + cvdo[9].r, q__1.i = cvdist.i + cvdo[9].i;
	cvdist.r = q__1.r, cvdist.i = q__1.i;
	if (iprnt == 0) {
	    goto L480;
	}
	for (j = 1; j <= 10; ++j) {
	    magphs_(&cvdo[j - 1], &xmag, &xphs);
	    i__1 = j - 1;
	    r__1 = (real) xmag;
	    r__2 = (real) xphs;
	    q__1.r = r__1, q__1.i = r__2;
	    cvdo[i__1].r = q__1.r, cvdo[i__1].i = q__1.i;
/* L445: */
	}
	if (ititle == 0) {
	    io___3186.ciunit = status_1.iofile;
	    s_wsfe(&io___3186);
	    e_wsfe();
	}
	ititle = 1;
	io___3187.ciunit = status_1.iofile;
	s_wsfe(&io___3187);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	for (j = 1; j <= 10; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___3188.ciunit = status_1.iofile;
	s_wsfe(&io___3188);
	for (j = 1; j <= 10; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	goto L480;
L450:
	z__4.r = gm2o3 * cew.r, z__4.i = gm2o3 * cew.i;
	z__3.r = z__4.r * bew.r - z__4.i * bew.i, z__3.i = z__4.r * bew.i + 
		z__4.i * bew.r;
	z__2.r = z__3.r * bew.r - z__3.i * bew.i, z__2.i = z__3.r * bew.i + 
		z__3.i * bew.r;
	z__1.r = z__2.r * .25, z__1.i = z__2.i * .25;
	dgm2o3.r = z__1.r, dgm2o3.i = z__1.i;
	z__4.r = gmo23 * bew.r, z__4.i = gmo23 * bew.i;
	z__3.r = z__4.r * cew.r - z__4.i * cew.i, z__3.i = z__4.r * cew.i + 
		z__4.i * cew.r;
	z__2.r = z__3.r * cew.r - z__3.i * cew.i, z__2.i = z__3.r * cew.i + 
		z__3.i * cew.r;
	z__1.r = z__2.r * .25, z__1.i = z__2.i * .25;
	dgmo23.r = z__1.r, dgmo23.i = z__1.i;
	goto L470;
L460:
	z__5.r = bew.r * .5, z__5.i = bew.i * .5;
	r_cnjg(&q__1, &bew2);
	z__4.r = z__5.r * q__1.r - z__5.i * q__1.i, z__4.i = z__5.r * q__1.i 
		+ z__5.i * q__1.r;
	z__3.r = z__4.r * cew.r - z__4.i * cew.i, z__3.i = z__4.r * cew.i + 
		z__4.i * cew.r;
	z__8.r = bew.r * .25, z__8.i = bew.i * .25;
	z__7.r = z__8.r * bew.r - z__8.i * bew.i, z__7.i = z__8.r * bew.i + 
		z__8.i * bew.r;
	r_cnjg(&q__2, &cew2);
	z__6.r = z__7.r * q__2.r - z__7.i * q__2.i, z__6.i = z__7.r * q__2.i 
		+ z__7.i * q__2.r;
	z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	z__1.r = gm2o3 * z__2.r, z__1.i = gm2o3 * z__2.i;
	dgm2o3.r = z__1.r, dgm2o3.i = z__1.i;
	z__5.r = cew.r * .5, z__5.i = cew.i * .5;
	r_cnjg(&q__1, &cew2);
	z__4.r = z__5.r * q__1.r - z__5.i * q__1.i, z__4.i = z__5.r * q__1.i 
		+ z__5.i * q__1.r;
	z__3.r = z__4.r * bew.r - z__4.i * bew.i, z__3.i = z__4.r * bew.i + 
		z__4.i * bew.r;
	z__8.r = cew.r * .25, z__8.i = cew.i * .25;
	z__7.r = z__8.r * cew.r - z__8.i * cew.i, z__7.i = z__8.r * cew.i + 
		z__8.i * cew.r;
	r_cnjg(&q__2, &bew2);
	z__6.r = z__7.r * q__2.r - z__7.i * q__2.i, z__6.i = z__7.r * q__2.i 
		+ z__7.i * q__2.r;
	z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	z__1.r = gmo23 * z__2.r, z__1.i = gmo23 * z__2.i;
	dgmo23.r = z__1.r, dgmo23.i = z__1.i;
L470:
	q__2.r = disto1.r + dgm2o3.r, q__2.i = disto1.i + dgm2o3.i;
	q__1.r = q__2.r + dgmo23.r, q__1.i = q__2.i + dgmo23.i;
	disto1.r = q__1.r, disto1.i = q__1.i;
	q__1.r = dgm2o3.r * cvace.r - dgm2o3.i * cvace.i, q__1.i = dgm2o3.r * 
		cvace.i + dgm2o3.i * cvace.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[9].r = z__1.r, cvdo[9].i = z__1.i;
	q__1.r = dgmo23.r * cvace.r - dgmo23.i * cvace.i, q__1.i = dgmo23.r * 
		cvace.i + dgmo23.i * cvace.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[10].r = z__1.r, cvdo[10].i = z__1.i;
	q__10.r = cvdo[0].r + cvdo[1].r, q__10.i = cvdo[0].i + cvdo[1].i;
	q__9.r = q__10.r + cvdo[2].r, q__9.i = q__10.i + cvdo[2].i;
	q__8.r = q__9.r + cvdo[3].r, q__8.i = q__9.i + cvdo[3].i;
	q__7.r = q__8.r + cvdo[4].r, q__7.i = q__8.i + cvdo[4].i;
	q__6.r = q__7.r + cvdo[5].r, q__6.i = q__7.i + cvdo[5].i;
	q__5.r = q__6.r + cvdo[6].r, q__5.i = q__6.i + cvdo[6].i;
	q__4.r = q__5.r + cvdo[7].r, q__4.i = q__5.i + cvdo[7].i;
	q__3.r = q__4.r + cvdo[8].r, q__3.i = q__4.i + cvdo[8].i;
	q__2.r = q__3.r + cvdo[9].r, q__2.i = q__3.i + cvdo[9].i;
	q__1.r = q__2.r + cvdo[10].r, q__1.i = q__2.i + cvdo[10].i;
	cvdo[11].r = q__1.r, cvdo[11].i = q__1.i;
	q__1.r = cvdist.r + cvdo[11].r, q__1.i = cvdist.i + cvdo[11].i;
	cvdist.r = q__1.r, cvdist.i = q__1.i;
	if (iprnt == 0) {
	    goto L480;
	}
	for (j = 1; j <= 12; ++j) {
	    magphs_(&cvdo[j - 1], &xmag, &xphs);
	    i__1 = j - 1;
	    r__1 = (real) xmag;
	    r__2 = (real) xphs;
	    q__1.r = r__1, q__1.i = r__2;
	    cvdo[i__1].r = q__1.r, cvdo[i__1].i = q__1.i;
/* L475: */
	}
	if (ititle == 0) {
	    io___3191.ciunit = status_1.iofile;
	    s_wsfe(&io___3191);
	    e_wsfe();
	}
	ititle = 1;
	io___3192.ciunit = status_1.iofile;
	s_wsfe(&io___3192);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	for (j = 1; j <= 12; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___3193.ciunit = status_1.iofile;
	s_wsfe(&io___3193);
	for (j = 1; j <= 12; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
L480:
	q__1.r = disto1.r - disto3.r, q__1.i = disto1.i - disto3.i;
	blank_1.value[tabinf_1.lvn + node1 - 1] -= q__1.r;
	q__1.r = disto2.r + disto3.r, q__1.i = disto2.i + disto3.i;
	blank_1.value[tabinf_1.lvn + node2 - 1] -= q__1.r;
	q__1.r = disto1.r + disto2.r, q__1.i = disto1.i + disto2.i;
	blank_1.value[tabinf_1.lvn + node3 - 1] += q__1.r;
	q__1.r = disto1.r - disto3.r, q__1.i = disto1.i - disto3.i;
	blank_1.value[tabinf_1.imvn + node1 - 1] -= r_imag(&q__1);
	q__1.r = disto2.r + disto3.r, q__1.i = disto2.i + disto3.i;
	blank_1.value[tabinf_1.imvn + node2 - 1] -= r_imag(&q__1);
	q__1.r = disto1.r + disto2.r, q__1.i = disto1.i + disto2.i;
	blank_1.value[tabinf_1.imvn + node3 - 1] += r_imag(&q__1);
	loc = nodplc[loc - 1];
	goto L330;

/*   JUNCTION DIODES */

L500:
	if (cirdat_1.jelcnt[10] == 0) {
	    goto L700;
	}
	ititle = 0;
/* L501: */
/* L510: */
	loc = cirdat_1.locate[10];
L520:
	if (loc == 0 || nodplc[loc + 15] != 0) {
	    goto L700;
	}
	locv = nodplc[loc];
	node1 = nodplc[loc + 1];
	node2 = nodplc[loc + 2];
	node3 = nodplc[loc + 3];
	locm = nodplc[loc + 4];
	locm = nodplc[locm];
	loct = tabinf_1.lx0 + nodplc[loc + 10];
	locd = tabinf_1.ld0 + nodplc[loc + 11];
	cdj1 = blank_1.value[locd - 1];
	cdj2 = blank_1.value[locd];
	cdb1 = blank_1.value[locd + 2];
	geq2 = blank_1.value[locd + 3];
	geq3 = blank_1.value[locd + 4];
	cdb2 = blank_1.value[locd + 5];
	i__1 = icvw1 + node3 - 1;
	i__2 = icvw1 + node2 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew.r = q__1.r, bew.i = q__1.i;
	if (kdisto == 2) {
	    goto L540;
	}
	i__1 = icv2w1 + node3 - 1;
	i__2 = icv2w1 + node2 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	be2w.r = q__1.r, be2w.i = q__1.i;
	if (kdisto == 3) {
	    goto L550;
	}
	i__1 = icvw2 + node3 - 1;
	i__2 = icvw2 + node2 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew2.r = q__1.r, bew2.i = q__1.i;
	if (kdisto == 5) {
	    goto L560;
	}
	if (kdisto == 6) {
	    goto L570;
	}
	i__1 = icvw12 + node3 - 1;
	i__2 = icvw12 + node2 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	bew12.r = q__1.r, bew12.i = q__1.i;
	goto L580;

/*    CALCULATE HD2 CURRENT GENERATORS */

L540:
	z__2.r = bew.r * .5, z__2.i = bew.i * .5;
	z__1.r = z__2.r * bew.r - z__2.i * bew.i, z__1.i = z__2.r * bew.i + 
		z__2.i * bew.r;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	goto L590;

/*    CALCULATE HD3 CURRENT GENERATORS */

L550:
	z__2.r = bew.r * .5, z__2.i = bew.i * .5;
	z__1.r = z__2.r * be2w.r - z__2.i * be2w.i, z__1.i = z__2.r * be2w.i 
		+ z__2.i * be2w.r;
	difvi1.r = z__1.r, difvi1.i = z__1.i;
	z__3.r = bew.r * .25, z__3.i = bew.i * .25;
	z__2.r = z__3.r * bew.r - z__3.i * bew.i, z__2.i = z__3.r * bew.i + 
		z__3.i * bew.r;
	z__1.r = z__2.r * bew.r - z__2.i * bew.i, z__1.i = z__2.r * bew.i + 
		z__2.i * bew.r;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	goto L600;

/*    CALCULATE IM2D CURRENT GENERATORS */

L560:
	r_cnjg(&q__2, &bew2);
	q__1.r = bew.r * q__2.r - bew.i * q__2.i, q__1.i = bew.r * q__2.i + 
		bew.i * q__2.r;
	difvn1.r = q__1.r, difvn1.i = q__1.i;
	goto L590;

/*    CALCULATE IM2S CURRENT GENERATORS */

L570:
	q__1.r = bew.r * bew2.r - bew.i * bew2.i, q__1.i = bew.r * bew2.i + 
		bew.i * bew2.r;
	difvn1.r = q__1.r, difvn1.i = q__1.i;
	goto L590;

/*    CALCULATE IM3 CURRENT GENERATORS */

L580:
	r_cnjg(&q__3, &bew2);
	q__2.r = be2w.r * q__3.r - be2w.i * q__3.i, q__2.i = be2w.r * q__3.i 
		+ be2w.i * q__3.r;
	q__4.r = bew.r * bew12.r - bew.i * bew12.i, q__4.i = bew.r * bew12.i 
		+ bew.i * bew12.r;
	q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
	z__1.r = q__1.r * .5, z__1.i = q__1.i * .5;
	difvi1.r = z__1.r, difvi1.i = z__1.i;
	q__2.r = bew.r * bew.r - bew.i * bew.i, q__2.i = bew.r * bew.i + 
		bew.i * bew.r;
	r_cnjg(&q__3, &bew2);
	q__1.r = q__2.r * q__3.r - q__2.i * q__3.i, q__1.i = q__2.r * q__3.i 
		+ q__2.i * q__3.r;
	z__1.r = q__1.r * .75, z__1.i = q__1.i * .75;
	difvn1.r = z__1.r, difvn1.i = z__1.i;
	goto L600;
L590:
	z__1.r = geq2 * difvn1.r, z__1.i = geq2 * difvn1.i;
	dsg2.r = z__1.r, dsg2.i = z__1.i;
	d__1 = cdb1 * .5 * status_1.omega;
	r__1 = -r_imag(&difvn1);
	r__2 = difvn1.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscdb1.r = z__1.r, dscdb1.i = z__1.i;
	d__1 = cdj1 * .5 * status_1.omega;
	r__1 = -r_imag(&difvn1);
	r__2 = difvn1.r;
	q__1.r = r__1, q__1.i = r__2;
	z__1.r = d__1 * q__1.r, z__1.i = d__1 * q__1.i;
	dscdj1.r = z__1.r, dscdj1.i = z__1.i;
	goto L610;

L600:
	d__1 = geq2 * 2.;
	z__2.r = d__1 * difvi1.r, z__2.i = d__1 * difvi1.i;
	z__3.r = geq3 * difvn1.r, z__3.i = geq3 * difvn1.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	dsg2.r = z__1.r, dsg2.i = z__1.i;
	z__3.r = cdb1 * difvi1.r, z__3.i = cdb1 * difvi1.i;
	z__5.r = cdb2 * difvn1.r, z__5.i = cdb2 * difvn1.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscdb1.r = z__1.r, dscdb1.i = z__1.i;
	r__1 = -r_imag(&dscdb1);
	r__2 = dscdb1.r;
	q__1.r = r__1, q__1.i = r__2;
	dscdb1.r = q__1.r, dscdb1.i = q__1.i;
	z__3.r = cdj1 * difvi1.r, z__3.i = cdj1 * difvi1.i;
	z__5.r = cdj2 * difvn1.r, z__5.i = cdj2 * difvn1.i;
	z__4.r = z__5.r / 3., z__4.i = z__5.i / 3.;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__1.r = status_1.omega * z__2.r, z__1.i = status_1.omega * z__2.i;
	dscdj1.r = z__1.r, dscdj1.i = z__1.i;
	r__1 = -r_imag(&dscdj1);
	r__2 = dscdj1.r;
	q__1.r = r__1, q__1.i = r__2;
	dscdj1.r = q__1.r, dscdj1.i = q__1.i;

/*  DETERMINE CONTRIBUTION OF EACH DISTORTION SOURCE */

L610:
	i__1 = icvadj + node3 - 1;
	i__2 = icvadj + node2 - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cvabe.r = q__1.r, cvabe.i = q__1.i;
	q__2.r = dsg2.r + dscdb1.r, q__2.i = dsg2.i + dscdb1.i;
	q__1.r = q__2.r + dscdj1.r, q__1.i = q__2.i + dscdj1.i;
	disto1.r = q__1.r, disto1.i = q__1.i;
	q__1.r = dsg2.r * cvabe.r - dsg2.i * cvabe.i, q__1.i = dsg2.r * 
		cvabe.i + dsg2.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[0].r = z__1.r, cvdo[0].i = z__1.i;
	q__1.r = dscdb1.r * cvabe.r - dscdb1.i * cvabe.i, q__1.i = dscdb1.r * 
		cvabe.i + dscdb1.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[1].r = z__1.r, cvdo[1].i = z__1.i;
	q__1.r = dscdj1.r * cvabe.r - dscdj1.i * cvabe.i, q__1.i = dscdj1.r * 
		cvabe.i + dscdj1.i * cvabe.r;
	z__1.r = arg * q__1.r, z__1.i = arg * q__1.i;
	cvdo[2].r = z__1.r, cvdo[2].i = z__1.i;
	q__2.r = cvdo[0].r + cvdo[1].r, q__2.i = cvdo[0].i + cvdo[1].i;
	q__1.r = q__2.r + cvdo[2].r, q__1.i = q__2.i + cvdo[2].i;
	cvdo[3].r = q__1.r, cvdo[3].i = q__1.i;
	q__1.r = cvdist.r + cvdo[3].r, q__1.i = cvdist.i + cvdo[3].i;
	cvdist.r = q__1.r, cvdist.i = q__1.i;
	if (iprnt == 0) {
	    goto L680;
	}
	for (j = 1; j <= 4; ++j) {
	    magphs_(&cvdo[j - 1], &xmag, &xphs);
	    i__1 = j - 1;
	    r__1 = (real) xmag;
	    r__2 = (real) xphs;
	    q__1.r = r__1, q__1.i = r__2;
	    cvdo[i__1].r = q__1.r, cvdo[i__1].i = q__1.i;
/* L670: */
	}
	if (ititle == 0) {
	    io___3204.ciunit = status_1.iofile;
	    s_wsfe(&io___3204);
	    e_wsfe();
	}
	ititle = 1;
	io___3205.ciunit = status_1.iofile;
	s_wsfe(&io___3205);
	do_fio(&c__1, (char *)&blank_1.value[locv - 1], (ftnlen)sizeof(
		doublereal));
	for (j = 1; j <= 4; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___3206.ciunit = status_1.iofile;
	s_wsfe(&io___3206);
	for (j = 1; j <= 4; ++j) {
	    do_fio(&c__1, (char *)&vdo[(j << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
L680:
	blank_1.value[tabinf_1.lvn + node2 - 1] += disto1.r;
	blank_1.value[tabinf_1.lvn + node3 - 1] -= disto1.r;
	blank_1.value[tabinf_1.imvn + node2 - 1] += r_imag(&disto1);
	blank_1.value[tabinf_1.imvn + node3 - 1] -= r_imag(&disto1);
	loc = nodplc[loc - 1];
	goto L520;

/*  OBTAIN TOTAL DISTORTION SOLUTION IF NECESSARY */

L700:
	switch (kdisto) {
	    case 1:  goto L1000;
	    case 2:  goto L710;
	    case 3:  goto L790;
	    case 4:  goto L710;
	    case 5:  goto L710;
	    case 6:  goto L840;
	    case 7:  goto L860;
	}
L710:
	acsol_();

/*  STORE SOLUTION, PRINT AND STORE ANSWERS */

/* L760: */
	switch (kdisto) {
	    case 1:  goto L1000;
	    case 2:  goto L770;
	    case 3:  goto L790;
	    case 4:  goto L800;
	    case 5:  goto L820;
	    case 6:  goto L840;
	    case 7:  goto L860;
	}
L770:
	copy16_(&cvalue[tabinf_1.lcvn], &cvalue[icv2w1], &cirdat_1.nstop);
	magphs_(&cvdist, &o2mag, &o2phs);
	if (iprnt == 0) {
	    goto L900;
	}
	o2log = d_lg10(&o2mag) * 20.;
	io___3210.ciunit = status_1.iofile;
	s_wsfe(&io___3210);
	do_fio(&c__1, (char *)&o2mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o2phs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o2log, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L900;
L790:
	magphs_(&cvdist, &o3mag, &o3phs);
	if (iprnt == 0) {
	    goto L900;
	}
	o3log = d_lg10(&o3mag) * 20.;
	io___3214.ciunit = status_1.iofile;
	s_wsfe(&io___3214);
	do_fio(&c__1, (char *)&o3mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o3phs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o3log, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L900;
L800:
	copy16_(&cvalue[tabinf_1.lcvn], &cvalue[icvw2], &cirdat_1.nstop);
	i__1 = icvw2 + idnp - 1;
	i__2 = icvw2 + idnn - 1;
	q__1.r = cvalue[i__1].r - cvalue[i__2].r, q__1.i = cvalue[i__1].i - 
		cvalue[i__2].i;
	cvout.r = q__1.r, cvout.i = q__1.i;
	magphs_(&cvout, &ow2mag, &ow2phs);
	goto L1000;
L820:
	copy16_(&cvalue[tabinf_1.lcvn], &cvalue[icvw12], &cirdat_1.nstop);
L840:
	magphs_(&cvdist, &o12mag, &o12phs);
	if (iprnt == 0) {
	    goto L900;
	}
	o12log = d_lg10(&o12mag) * 20.;
	if (kdisto == 6) {
	    goto L850;
	}
	io___3218.ciunit = status_1.iofile;
	s_wsfe(&io___3218);
	do_fio(&c__1, (char *)&o12mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o12phs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o12log, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L900;
L850:
	io___3219.ciunit = status_1.iofile;
	s_wsfe(&io___3219);
	do_fio(&c__1, (char *)&o12mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o12phs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o12log, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L900;
L860:
	magphs_(&cvdist, &o21mag, &o21phs);
	if (iprnt == 0) {
	    goto L900;
	}
	o21log = d_lg10(&o21mag) * 20.;
	io___3223.ciunit = status_1.iofile;
	s_wsfe(&io___3223);
	do_fio(&c__1, (char *)&o21mag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o21phs, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&o21log, (ftnlen)sizeof(doublereal));
	e_wsfe();
	cma = (d__1 = o21mag * 4. * cos((o21phs - ophase) / knstnt_1.rad), 
		abs(d__1));
	cma = max(cma,1e-20);
	cmp = (d__1 = o21mag * 4. * sin((o21phs - ophase) / knstnt_1.rad), 
		abs(d__1));
	cmp = max(cmp,1e-20);
	cmalog = d_lg10(&cma) * 20.;
	cmplog = d_lg10(&cmp) * 20.;
	io___3228.ciunit = status_1.iofile;
	s_wsfe(&io___3228);
	e_wsfe();
	io___3229.ciunit = status_1.iofile;
	s_wsfe(&io___3229);
	do_fio(&c__1, (char *)&cma, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cmalog, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___3230.ciunit = status_1.iofile;
	s_wsfe(&io___3230);
	do_fio(&c__1, (char *)&cmp, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cmplog, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  SAVE DISTORTION OUTPUTS */

L900:
	iflag = kdisto + 2;
	if (iflag >= 7) {
	    --iflag;
	}
	loc = cirdat_1.locate[44];
L910:
	if (loc == 0) {
	    goto L1000;
	}
	if (nodplc[loc + 4] != iflag) {
	    goto L920;
	}
	tabinf_1.iseq = nodplc[loc + 3];
	i__1 = *loco + tabinf_1.iseq - 1;
	cvalue[i__1].r = cvdist.r, cvalue[i__1].i = cvdist.i;
L920:
	loc = nodplc[loc - 1];
	goto L910;
L1000:
	;
    }

/*  FINISHED */

/* L2000: */
    return 0;
} /* disto_ */

#undef cvalue
#undef nodplc
#undef cvdo
#undef vdo
#undef distit


/* SPICE VERSION 2G.6  SCCSID=ovtpvt.ma 3/15/83 */
/* Subroutine */ int ovtpvt_(void)
{
    /* Initialized data */

    static struct {
	char e_1[96];
	doublereal e_2;
	} equiv_3265 = { "DC TRANSFER CURVES              TRANSIENT ANALYSIS"
		"              AC ANALYSIS                     ", 0. };

#define subtit ((doublereal *)&equiv_3265)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_3266 = { "(1PE11.3,2X,8E00.00)    ", 0. };

#define prform ((doublereal *)&equiv_3266)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3267 = { ".       ", 0. };

#define aper (*(doublereal *)&equiv_3267)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3268 = { ")       ", 0. };

#define rprn (*(doublereal *)&equiv_3268)


    /* Format strings */
    static char fmt_111[] = "(\002Y\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double r_imag(complex *), d_lg10(doublereal *);

    /* Local variables */
    static integer i__, k;
    static doublereal t1, t2;
    static integer id, loc;
    static doublereal yvr;
    static complex cval;
    static doublereal xmag;
    static integer locx;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer ipos, locy, locv;
    static doublereal xvar;
    extern /* Subroutine */ int plot_(integer *, integer *, integer *, 
	    integer *);
    static integer lout;
    static doublereal xphs;
    extern /* Subroutine */ int getm8_(integer *, integer *), title_(integer *
	    , integer *, integer *, doublereal *);
    static integer locyt, ktype;
    extern /* Subroutine */ int ntrpl8_(integer *, integer *, integer *);
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    extern /* Subroutine */ int second_(doublereal *), crunch_(void);
    static integer ifract, ifwdth;
    extern /* Subroutine */ int alfnum_(integer *, doublereal *, integer *);
    static integer noprln;
    extern /* Subroutine */ int setprn_(integer *);
    static integer numpnt;
    extern /* Subroutine */ int clrmem_(integer *), setplt_(integer *), 
	    fouran_(void), magphs_(complex *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___3252 = { 0, 0, 0, (char *)prform, 0 };
    static cilist io___3253 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___3261 = { 0, 0, 0, (char *)prform, 0 };
    static cilist io___3262 = { 0, 0, 0, fmt_111, 0 };




/*     THIS ROUTINE GENERATES THE REQUESTED TABULAR LISTINGS OF ANALYSIS */
/* RESULTS.  IT CALLS PLOT TO GENERATE LINE-PRINTER PLOTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


    second_(&t1);
    if (status_1.icalc <= 0) {
	goto L1000;
    }
    crunch_();
    if (flags_1.nogo < 0) {
	goto L1000;
    }

/*  CONSTRUCT FORMAT STATEMENT TO BE USED FOR PRINTING THE OUTPUTS */

/* Computing MAX */
    i__1 = outinf_1.numdgt - 1;
    ifract = max(i__1,0);
    ifwdth = ifract + 9;
    ipos = 15;
    alfnum_(&ifwdth, prform, &ipos);
    move_(prform, &ipos, &aper, &c__1, &c__1);
    ++ipos;
    alfnum_(&ifract, prform, &ipos);
    move_(prform, &ipos, &rprn, &c__1, &c__1);

/* Computing MIN */
    i__1 = 8, i__2 = (miscel_1.lwidth - 12) / ifwdth;
    noprln = min(i__1,i__2);
    if ((i__1 = status_1.mode - 2) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L60;
    } else {
	goto L300;
    }
L50:
    outinf_1.numout = cirdat_1.jelcnt[40] + 1;
    goto L70;
L60:
    outinf_1.numout = cirdat_1.jelcnt[41] + 1;

/*  DC AND TRANSIENT ANALYSIS PRINTING */

L70:
    loc = cirdat_1.locate[status_1.mode + 29];
L80:
    if (loc == 0) {
	goto L200;
    }
/* Computing MIN */
    i__1 = noprln, i__2 = nodplc[loc + 2];
    outinf_1.kntr = min(i__1,i__2);
    if (outinf_1.kntr <= 0) {
	goto L120;
    }
    title_(&c__1, &miscel_1.lwidth, &c__1, &subtit[(status_1.mode << 2) - 4]);
    setprn_(&loc);

/*  GET BUFFER SPACE */

    getm8_(&locx, &outinf_1.npoint);
    i__1 = outinf_1.kntr * outinf_1.npoint;
    getm8_(&locy, &i__1);

/*  INTERPOLATE OUTPUTS */

    ntrpl8_(&locx, &locy, &numpnt);

/*  PRINT OUTPUTS */

    i__1 = numpnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xvar = blank_1.value[locx + i__ - 1];
	locyt = locy;
	i__2 = outinf_1.kntr;
	for (k = 1; k <= i__2; ++k) {
	    outinf_1.yvar[k - 1] = blank_1.value[locyt + i__ - 1];
	    locyt += outinf_1.npoint;
/* L90: */
	}
	io___3252.ciunit = status_1.iofile;
	s_wsfe(&io___3252);
	do_fio(&c__1, (char *)&xvar, (ftnlen)sizeof(doublereal));
	i__2 = outinf_1.kntr;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__1, (char *)&outinf_1.yvar[k - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
/* L100: */
    }
    io___3253.ciunit = status_1.iofile;
    s_wsfe(&io___3253);
    e_wsfe();
    clrmem_(&locx);
    clrmem_(&locy);
L120:
    loc = nodplc[loc - 1];
    goto L80;

/*  DC AND TRANSIENT ANALYSIS PLOTTING */

L200:
    loc = cirdat_1.locate[status_1.mode + 34];
L210:
    if (loc == 0) {
	goto L250;
    }
    outinf_1.kntr = nodplc[loc + 2];
    if (outinf_1.kntr <= 0) {
	goto L220;
    }
    locv = nodplc[loc];
    title_(&c__1, &miscel_1.lwidth, &c__1, &subtit[(status_1.mode << 2) - 4]);
    setplt_(&loc);

/*     GET BUFFER SPACE */

    getm8_(&locx, &outinf_1.npoint);
    i__1 = outinf_1.kntr * outinf_1.npoint;
    getm8_(&locy, &i__1);

/*  INTERPOLATE OUTPUTS AND LOAD PLOT BUFFERS */

    ntrpl8_(&locx, &locy, &numpnt);
    plot_(&numpnt, &locx, &locy, &locv);
    clrmem_(&locx);
    clrmem_(&locy);
L220:
    loc = nodplc[loc - 1];
    goto L210;

/*  FOURIER ANALYSIS */

L250:
    if (status_1.mode == 1) {
	goto L1000;
    }
    if (tabinf_1.nfour == 0) {
	goto L1000;
    }
    if (flags_1.nogo != 0) {
	goto L1000;
    }
    fouran_();
    goto L1000;

/*  AC ANALYSIS PRINTING */

L300:
    outinf_1.numout = cirdat_1.jelcnt[42] + cirdat_1.jelcnt[43] + 
	    cirdat_1.jelcnt[44] + 1;
    for (id = 33; id <= 35; ++id) {
	loc = cirdat_1.locate[id - 1];
L320:
	if (loc == 0) {
	    goto L599;
	}
/* Computing MIN */
	i__1 = noprln, i__2 = nodplc[loc + 2];
	outinf_1.kntr = min(i__1,i__2);
	if (outinf_1.kntr <= 0) {
	    goto L595;
	}
	title_(&c__1, &miscel_1.lwidth, &c__1, &subtit[(status_1.mode << 2) - 
		4]);
	setprn_(&loc);

/*  PRINT AC OUTPUTS */

	lout = tabinf_1.loutpt;
	i__1 = status_1.icalc;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = lout;
	    xvar = (doublereal) cvalue[i__2].r;
	    i__2 = outinf_1.kntr;
	    for (k = 1; k <= i__2; ++k) {
		tabinf_1.iseq = outinf_1.itab[k - 1];
		tabinf_1.iseq = nodplc[tabinf_1.iseq + 3];
		i__3 = lout + tabinf_1.iseq - 1;
		cval.r = cvalue[i__3].r, cval.i = cvalue[i__3].i;
		ktype = outinf_1.itype[k - 1];
		switch (ktype) {
		    case 1:  goto L450;
		    case 2:  goto L450;
		    case 3:  goto L430;
		    case 4:  goto L440;
		    case 5:  goto L450;
		    case 6:  goto L450;
		}
L430:
		outinf_1.yvar[k - 1] = (doublereal) cval.r;
		goto L500;
L440:
		outinf_1.yvar[k - 1] = (doublereal) r_imag(&cval);
		goto L500;
L450:
		magphs_(&cval, &xmag, &xphs);
		switch (ktype) {
		    case 1:  goto L460;
		    case 2:  goto L460;
		    case 3:  goto L430;
		    case 4:  goto L440;
		    case 5:  goto L470;
		    case 6:  goto L465;
		}
L460:
		outinf_1.yvar[k - 1] = xmag;
		goto L500;
L465:
		outinf_1.yvar[k - 1] = d_lg10(&xmag) * 20.;
		goto L500;
L470:
		outinf_1.yvar[k - 1] = xphs;
L500:
		;
	    }
	    lout += outinf_1.numout;
/* L580: */
	    io___3261.ciunit = status_1.iofile;
	    s_wsfe(&io___3261);
	    do_fio(&c__1, (char *)&xvar, (ftnlen)sizeof(doublereal));
	    i__2 = outinf_1.kntr;
	    for (k = 1; k <= i__2; ++k) {
		do_fio(&c__1, (char *)&outinf_1.yvar[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
/* L590: */
	}
	io___3262.ciunit = status_1.iofile;
	s_wsfe(&io___3262);
	e_wsfe();
L595:
	loc = nodplc[loc - 1];
	goto L320;
L599:
	;
    }

/*  AC ANALYSIS PLOTTING */

    for (id = 38; id <= 40; ++id) {
	loc = cirdat_1.locate[id - 1];
L610:
	if (loc == 0) {
	    goto L760;
	}
	outinf_1.kntr = nodplc[loc + 2];
	if (outinf_1.kntr <= 0) {
	    goto L750;
	}
	locv = nodplc[loc];
	title_(&c__1, &miscel_1.lwidth, &c__1, &subtit[(status_1.mode << 2) - 
		4]);
	setplt_(&loc);

	getm8_(&locx, &status_1.icalc);
	i__1 = outinf_1.kntr * status_1.icalc;
	getm8_(&locy, &i__1);

/*     LOAD PLOT BUFFERS */

	lout = tabinf_1.loutpt;
	i__1 = status_1.icalc;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = lout;
	    xvar = (doublereal) cvalue[i__2].r;
	    locyt = locy;
	    i__2 = outinf_1.kntr;
	    for (k = 1; k <= i__2; ++k) {
		tabinf_1.iseq = outinf_1.itab[k - 1];
		tabinf_1.iseq = nodplc[tabinf_1.iseq + 3];
		i__3 = lout + tabinf_1.iseq - 1;
		cval.r = cvalue[i__3].r, cval.i = cvalue[i__3].i;
		ktype = outinf_1.itype[k - 1];
		switch (ktype) {
		    case 1:  goto L670;
		    case 2:  goto L670;
		    case 3:  goto L650;
		    case 4:  goto L660;
		    case 5:  goto L670;
		    case 6:  goto L670;
		}
L650:
		yvr = (doublereal) cval.r;
		goto L695;
L660:
		yvr = (doublereal) r_imag(&cval);
		goto L695;
L670:
		magphs_(&cval, &xmag, &xphs);
		switch (ktype) {
		    case 1:  goto L680;
		    case 2:  goto L680;
		    case 3:  goto L650;
		    case 4:  goto L660;
		    case 5:  goto L690;
		    case 6:  goto L685;
		}
L680:
		yvr = d_lg10(&xmag);
		goto L695;
L685:
		yvr = d_lg10(&xmag) * 20.;
		goto L695;
L690:
		yvr = xphs;
L695:
		blank_1.value[locyt + i__ - 1] = yvr;
		locyt += status_1.icalc;
/* L700: */
	    }
	    blank_1.value[locx + i__ - 1] = xvar;
	    lout += outinf_1.numout;
/* L710: */
	}
	plot_(&status_1.icalc, &locx, &locy, &locv);
	clrmem_(&locx);
	clrmem_(&locy);
L750:
	loc = nodplc[loc - 1];
	goto L610;
L760:
	;
    }

/*  FINISHED */

L1000:
    clrmem_(&tabinf_1.loutpt);
    second_(&t2);
    miscel_1.rstats[10] = miscel_1.rstats[10] + t2 - t1;
    return 0;
} /* ovtpvt_ */

#undef cvalue
#undef nodplc
#undef rprn
#undef aper
#undef prform
#undef subtit


/* Subroutine */ int ntrpl8_(integer *locx, integer *locy, integer *numpnt)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, k;
    static doublereal v1, v2, x1, x2, tol, yvr, dxx1;
    static integer loco;
    static doublereal dx1x2, xvar;
    static integer loco1, loco2, icpnt, locyt, ippnt;
    static doublereal xvtol;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)


/*     THIS ROUTINE INTERPOLATES THE ANALYSIS DATA TO OBTAIN THE VALUES */
/* PRINTED AND/OR PLOTTED, USING LINEAR INTERPOLATION. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


/*  FOR DC TRANSFER CURVE, NO INTERPOLATION NECESSARY */

    if (status_1.mode != 1) {
	goto L4;
    }
    *numpnt = status_1.icalc;
    loco = tabinf_1.loutpt;
    i__1 = *numpnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locyt = *locy;
	blank_1.value[*locx + i__ - 1] = blank_1.value[loco];
	i__2 = outinf_1.kntr;
	for (k = 1; k <= i__2; ++k) {
	    tabinf_1.iseq = outinf_1.itab[k - 1];
	    tabinf_1.iseq = nodplc[tabinf_1.iseq + 3];
	    blank_1.value[locyt + i__ - 1] = blank_1.value[loco + 
		    tabinf_1.iseq - 1];
	    locyt += outinf_1.npoint;
/* L2: */
	}
	loco += outinf_1.numout;
/* L3: */
    }
    return 0;
L4:
    xvar = outinf_1.xstart;
    xvtol = outinf_1.xincr * 1e-5;
    ippnt = 0;
    icpnt = 2;
    loco1 = tabinf_1.loutpt;
    loco2 = loco1 + outinf_1.numout;
    if (status_1.icalc < 2) {
	goto L50;
    }
L10:
    x1 = blank_1.value[loco1];
    x2 = blank_1.value[loco2];
    dx1x2 = x1 - x2;
L20:
    if (outinf_1.xincr < 0.) {
	goto L24;
    }
    if (xvar <= x2 + xvtol) {
	goto L30;
    }
    goto L28;
L24:
    if (xvar >= x2 + xvtol) {
	goto L30;
    }
L28:
    if (icpnt >= status_1.icalc) {
	goto L100;
    }
    ++icpnt;
    loco1 = loco2;
    loco2 = loco1 + outinf_1.numout;
    goto L10;
L30:
    ++ippnt;
    blank_1.value[*locx + ippnt - 1] = xvar;
    dxx1 = xvar - x1;
    locyt = *locy;
    i__1 = outinf_1.kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tabinf_1.iseq = outinf_1.itab[i__ - 1];
	tabinf_1.iseq = nodplc[tabinf_1.iseq + 3];
	v1 = blank_1.value[loco1 + tabinf_1.iseq - 1];
	v2 = blank_1.value[loco2 + tabinf_1.iseq - 1];
	yvr = v1 + (v1 - v2) * dxx1 / dx1x2;
/* Computing MIN */
	d__1 = abs(v1), d__2 = abs(v2);
	tol = min(d__1,d__2) * 1e-10;
	if (abs(yvr) <= tol) {
	    yvr = 0.;
	}
	blank_1.value[locyt + ippnt - 1] = yvr;
	locyt += outinf_1.npoint;
/* L40: */
    }
    if (ippnt >= outinf_1.npoint) {
	goto L100;
    }
    xvar = outinf_1.xstart + (doublereal) ippnt * outinf_1.xincr;
    if (abs(xvar) >= abs(xvtol)) {
	goto L20;
    }
    xvar = 0.;
    goto L20;

/*  SPECIAL HANDLING IF ICALC = 1 */

/* ...  ICALC=1;  JUST COPY OVER THE SINGLE POINT AND RETURN */
L50:
    ippnt = 1;
    blank_1.value[*locx + ippnt - 1] = xvar;
    locyt = *locy;
    i__1 = outinf_1.kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tabinf_1.iseq = outinf_1.itab[i__ - 1];
	tabinf_1.iseq = nodplc[tabinf_1.iseq + 3];
	blank_1.value[locyt + ippnt - 1] = blank_1.value[loco1 + 
		tabinf_1.iseq - 1];
	locyt += outinf_1.npoint;
/* L60: */
    }
    goto L100;

/*  RETURN */

L100:
    *numpnt = ippnt;
    return 0;
} /* ntrpl8_ */

#undef cvalue
#undef nodplc


/* Subroutine */ int setprn_(integer *loc)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3305 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_3305)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3306 = { "  TIME  ", 0. };

#define atimex (*(doublereal *)&equiv_3306)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3307 = { "  FREQ  ", 0. };

#define afreq (*(doublereal *)&equiv_3307)


    /* Format strings */
    static char fmt_91[] = "(/3x,a8,5x,14a8,a4)";
    static char fmt_101[] = "(\002X\002/\002 \002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, loce, loct;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer ipos, npos, itemp, jstop;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal asweep;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___3303 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___3304 = { 0, 0, 0, fmt_101, 0 };



/*     THIS ROUTINE FORMATS THE COLUMN HEADERS FOR TABULAR LISTINGS OF */
/* OUTPUT VARIABLES. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


/*  SET LIMITS DEPENDING UPON THE ANALYSIS MODE */

    if ((i__1 = status_1.mode - 2) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L20;
    } else {
	goto L30;
    }
L10:
    outinf_1.xstart = dc_1.tcstar[0];
    outinf_1.xincr = dc_1.tcincr[0];
    outinf_1.npoint = dc_1.icvflg;
    itemp = dc_1.itcelm[0];
    loce = nodplc[itemp];
    asweep = blank_1.value[loce - 1];
    goto L40;
L20:
    outinf_1.xstart = tran_1.tstart;
    outinf_1.xincr = tran_1.tstep;
    outinf_1.npoint = tran_1.jtrflg;
    asweep = atimex;
    goto L40;
L30:
    outinf_1.xstart = ac_1.fstart;
    outinf_1.xincr = ac_1.fincr;
    outinf_1.npoint = status_1.icalc;
    asweep = afreq;

/*  CONSTRUCT AND PRINT THE OUTPUT VARIABLE NAMES */

L40:
    loct = *loc + 2;
    ipos = 1;
    npos = ipos + outinf_1.numdgt + 8;
    i__1 = outinf_1.kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	loct += 2;
	outinf_1.itab[i__ - 1] = nodplc[loct - 1];
	outinf_1.itype[i__ - 1] = nodplc[loct];
	outnam_(&outinf_1.itab[i__ - 1], &outinf_1.itype[i__ - 1], 
		outinf_1.string, &ipos);
	if (ipos >= npos) {
	    goto L70;
	}
	i__2 = npos;
	for (j = ipos; j <= i__2; ++j) {
	    move_(outinf_1.string, &j, &ablnk, &c__1, &c__1);
/* L60: */
	}
	ipos = npos;
	goto L80;
L70:
	move_(outinf_1.string, &ipos, &ablnk, &c__1, &c__1);
	++ipos;
L80:
	npos = npos + outinf_1.numdgt + 8;
/* L90: */
    }
    move_(outinf_1.string, &ipos, &ablnk, &c__1, &c__7);
    jstop = (ipos + 6) / 8;
    io___3303.ciunit = status_1.iofile;
    s_wsfe(&io___3303);
    do_fio(&c__1, (char *)&asweep, (ftnlen)sizeof(doublereal));
    i__1 = jstop;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&outinf_1.string[j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    io___3304.ciunit = status_1.iofile;
    s_wsfe(&io___3304);
    e_wsfe();
    return 0;
} /* setprn_ */

#undef cvalue
#undef nodplc
#undef afreq
#undef atimex
#undef ablnk


/* Subroutine */ int setplt_(integer *loc)
{
    /* Initialized data */

    static integer logopt[6] = { 2,2,1,1,1,1 };
    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3328 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_3328)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3329 = { "  TIME  ", 0. };

#define atimex (*(doublereal *)&equiv_3329)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3330 = { "  FREQ  ", 0. };

#define afreq (*(doublereal *)&equiv_3330)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3331 = { "*+=$0<>?", 0. };

#define pltsym (*(doublereal *)&equiv_3331)


    /* Format strings */
    static char fmt_41[] = "(\0020LEGEND:\002/)";
    static char fmt_61[] = "(1x,a1,\002: \002,5a8)";
    static char fmt_101[] = "(\002X\002/3x,a8,4x,5a8)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, loce, loct;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer ipos;
    static doublereal achar;
    static integer itemp, jstop;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal asweep;
    static integer ioutyp;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___3319 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___3325 = { 0, 0, 0, fmt_61, 0 };
    static cilist io___3327 = { 0, 0, 0, fmt_101, 0 };



/*     THIS ROUTINE GENERATES THE 'LEGEND' SUBHEADING USED TO IDENTIFY */
/* INDIVIDUAL TRACES ON MULTI-TRACE LINE-PRINTER PLOTS. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=DC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=AC 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */


/*  SET LIMITS DEPENDING UPON THE ANALYSIS MODE */

    if ((i__1 = status_1.mode - 2) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L20;
    } else {
	goto L30;
    }
L10:
    outinf_1.xstart = dc_1.tcstar[0];
    outinf_1.xincr = dc_1.tcincr[0];
    outinf_1.npoint = dc_1.icvflg;
    itemp = dc_1.itcelm[0];
    loce = nodplc[itemp];
    asweep = blank_1.value[loce - 1];
    goto L40;
L20:
    outinf_1.xstart = tran_1.tstart;
    outinf_1.xincr = tran_1.tstep;
    outinf_1.npoint = tran_1.jtrflg;
    asweep = atimex;
    goto L40;
L30:
    outinf_1.xstart = ac_1.fstart;
    outinf_1.xincr = ac_1.fincr;
    outinf_1.npoint = status_1.icalc;
    asweep = afreq;

/*  CONSTRUCT AND PRINT THE OUTPUT VARIABLES WITH CORRESPONDING PLOT */
/*    SYMBOLS */

L40:
    loct = *loc + 2;
    if (outinf_1.kntr == 1) {
	goto L80;
    }
    io___3319.ciunit = status_1.iofile;
    s_wsfe(&io___3319);
    e_wsfe();
    i__1 = outinf_1.kntr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	loct += 2;
	outinf_1.itab[i__ - 1] = nodplc[loct - 1];
	ioutyp = nodplc[loct];
	outinf_1.itype[i__ - 1] = ioutyp;
	outinf_1.ilogy[i__ - 1] = 1;
	if (status_1.mode <= 2) {
	    goto L50;
	}
	outinf_1.ilogy[i__ - 1] = logopt[ioutyp - 1];
L50:
	ipos = 1;
	outnam_(&outinf_1.itab[i__ - 1], &outinf_1.itype[i__ - 1], 
		outinf_1.string, &ipos);
	move_(outinf_1.string, &ipos, &ablnk, &c__1, &c__7);
	jstop = (ipos + 6) / 8;
	move_(&achar, &c__1, &pltsym, &i__, &c__1);
	io___3325.ciunit = status_1.iofile;
	s_wsfe(&io___3325);
	do_fio(&c__1, (char *)&achar, (ftnlen)sizeof(doublereal));
	i__2 = jstop;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&outinf_1.string[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
/* L70: */
    }
L80:
    if (outinf_1.kntr >= 2) {
	goto L90;
    }
    outinf_1.itab[0] = nodplc[*loc + 3];
    ioutyp = nodplc[*loc + 4];
    outinf_1.itype[0] = ioutyp;
    outinf_1.ilogy[0] = 1;
    if (status_1.mode <= 2) {
	goto L90;
    }
    outinf_1.ilogy[0] = logopt[ioutyp - 1];
L90:
    ipos = 1;
    outnam_(outinf_1.itab, outinf_1.itype, outinf_1.string, &ipos);
    move_(outinf_1.string, &ipos, &ablnk, &c__1, &c__7);
    jstop = (ipos + 6) / 8;
    io___3327.ciunit = status_1.iofile;
    s_wsfe(&io___3327);
    do_fio(&c__1, (char *)&asweep, (ftnlen)sizeof(doublereal));
    i__1 = jstop;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&outinf_1.string[j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    return 0;
} /* setplt_ */

#undef cvalue
#undef nodplc
#undef pltsym
#undef afreq
#undef atimex
#undef ablnk


/* Subroutine */ int plot_(integer *numpnt, integer *locx, integer *locy, 
	integer *locv)
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3385 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_3385)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3386 = { "X       ", 0. };

#define aletx (*(doublereal *)&equiv_3386)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3387 = { ".       ", 0. };

#define aper (*(doublereal *)&equiv_3387)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3388 = { "(-------", 0. };

#define asym1 (*(doublereal *)&equiv_3388)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3389 = { "--------", 0. };

#define asym2 (*(doublereal *)&equiv_3389)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3390 = { ")       ", 0. };

#define arprn (*(doublereal *)&equiv_3390)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3391 = { "*+=$0<>?", 0. };

#define pltsym (*(doublereal *)&equiv_3391)


    /* Format strings */
    static char fmt_271[] = "(/2a8,\002----\002,1pd12.3,4(15x,d10.3)/26x,51"
	    "(\002 -\002))";
    static char fmt_273[] = "(/2a8,1x,1pd10.3,3(4x,d10.3),1x,d10.3/22x,29"
	    "(\002 -\002))";
    static char fmt_291[] = "(/20x,1pd12.3,4(15x,d10.3)/26x,51(\002 -\002))";
    static char fmt_293[] = "(/15x,1pd12.3,3(4x,d10.3),1x,d10.3/22x,29("
	    "\002 -\002))";
    static char fmt_316[] = "(1pd10.3,3x,d10.3,3x,13a8)";
    static char fmt_317[] = "(1pd10.3,1x,d10.3,1x,7a8,a1)";
    static char fmt_331[] = "(26x,51(\002 -\002)//)";
    static char fmt_332[] = "(22x,29(\002 -\002)//)";
    static char fmt_401[] = "(\0020WARNING:  TOO FEW POINTS FOR PLOTTING\002"
	    "/)";
    static char fmt_501[] = "(\002Y\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double d_lg10(doublereal *), exp(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal y1, y2, del, yvr, pmin[8];
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static doublereal asym[2];
    static integer ipos, ktmp;
    static doublereal ymin, ymax, xvar, ymin1, ymax1;
    extern /* Subroutine */ int copy8_(doublereal *, doublereal *, integer *),
	     scale_(doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    static integer iwide, nwide, icoor[8], jcoor[8];
    static doublereal aplot[13], small, aspot, ycoor[40]	/* was [5][8] 
	    */;
    static integer locyt, ispot, lspot, nwide4;
    static doublereal agraph[13];
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal delplt[8];
    static integer mltscl, numcor, jpoint;

    /* Fortran I/O blocks */
    static cilist io___3369 = { 0, 0, 0, fmt_271, 0 };
    static cilist io___3370 = { 0, 0, 0, fmt_273, 0 };
    static cilist io___3371 = { 0, 0, 0, fmt_291, 0 };
    static cilist io___3372 = { 0, 0, 0, fmt_293, 0 };
    static cilist io___3379 = { 0, 0, 0, fmt_316, 0 };
    static cilist io___3380 = { 0, 0, 0, fmt_317, 0 };
    static cilist io___3381 = { 0, 0, 0, fmt_331, 0 };
    static cilist io___3382 = { 0, 0, 0, fmt_332, 0 };
    static cilist io___3383 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___3384 = { 0, 0, 0, fmt_501, 0 };



/*     THIS ROUTINE GENERATES THE LINE-PRINTER PLOTS. */

/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    iwide = 1;
    nwide = 101;
    nwide4 = 25;
    if (miscel_1.lwidth > 80) {
	goto L3;
    }
    iwide = 0;
    nwide = 57;
    nwide4 = 14;
L3:
    if (*numpnt <= 0) {
	goto L400;
    }
    for (i__ = 1; i__ <= 13; ++i__) {
	agraph[i__ - 1] = ablnk;
/* L5: */
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	ispot = nwide4 * (i__ - 1) + 1;
	move_(agraph, &ispot, &aper, &c__1, &c__1);
/* L7: */
    }
    locyt = *locy;
    lspot = *locv - 1;
    mltscl = 0;
    if (blank_1.value[*locv - 1] == 0.) {
	mltscl = 1;
    }
    i__1 = outinf_1.kntr;
    for (k = 1; k <= i__1; ++k) {
	lspot += 2;
	ymin = blank_1.value[lspot - 1];
	ymax = blank_1.value[lspot];
	if (ymin != 0.) {
	    goto L10;
	}
	if (ymax != 0.) {
	    goto L10;
	}
	goto L100;
L10:
	ymin1 = min(ymin,ymax);
	ymax1 = max(ymin,ymax);
/* L30: */
	if (outinf_1.ilogy[k - 1] == 1) {
	    goto L40;
	}
	d__1 = max(ymin1,1e-20);
	ymin1 = d_lg10(&d__1);
	d__1 = max(ymax1,1e-20);
	ymax1 = d_lg10(&d__1);
/* Computing MAX */
	d__1 = ymax1 - ymin1;
	del = max(d__1,1e-4) / 4.;
	goto L50;
L40:
/* Computing MAX */
	d__1 = ymax1 - ymin1;
	del = max(d__1,1e-20) / 4.;
L50:
	ymin = ymin1;
	ymax = ymax1;
	goto L200;

/*  DETERMINE MAX AND MIN VALUES */

L100:
	ymax1 = blank_1.value[locyt];
	ymin1 = ymax1;
	if (*numpnt == 1) {
	    goto L150;
	}
	i__2 = *numpnt;
	for (i__ = 2; i__ <= i__2; ++i__) {
/* Computing MIN */
	    d__1 = ymin1, d__2 = blank_1.value[locyt + i__ - 1];
	    ymin1 = min(d__1,d__2);
/* Computing MAX */
	    d__1 = ymax1, d__2 = blank_1.value[locyt + i__ - 1];
	    ymax1 = max(d__1,d__2);
/* L110: */
	}

/*  SCALING */

L150:
	scale_(&ymin1, &ymax1, &c__4, &ymin, &ymax, &del);

/*  DETERMINE COORDINATES */

L200:
	ycoor[k * 5 - 5] = ymin;
	pmin[k - 1] = ymin;
	small = del * 1e-4;
	if ((d__1 = ycoor[k * 5 - 5], abs(d__1)) <= small) {
	    ycoor[k * 5 - 5] = 0.;
	}
	for (i__ = 1; i__ <= 4; ++i__) {
	    ycoor[i__ + 1 + k * 5 - 6] = ycoor[i__ + k * 5 - 6] + del;
	    if ((d__1 = ycoor[i__ + 1 + k * 5 - 6], abs(d__1)) <= small) {
		ycoor[i__ + 1 + k * 5 - 6] = 0.;
	    }
/* L210: */
	}
	if (outinf_1.ilogy[k - 1] == 1) {
	    goto L230;
	}
	for (i__ = 1; i__ <= 5; ++i__) {
/* L220: */
	    ycoor[i__ + k * 5 - 6] = exp(knstnt_1.xlog10 * ycoor[i__ + k * 5 
		    - 6]);
	}
L230:
	delplt[k - 1] = del / (doublereal) nwide4;
	locyt += outinf_1.npoint;
/* L235: */
    }

/*  COUNT DISTINCT COORDINATES */

    icoor[0] = 1;
    jcoor[0] = 1;
    numcor = 1;
    if (outinf_1.kntr == 1) {
	goto L290;
    }
    i__1 = outinf_1.kntr;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = numcor;
	for (j = 1; j <= i__2; ++j) {
	    l = jcoor[j - 1];
/* ...  COORDINATES ARE *EQUAL* IF THE MOST SIGNIFICANT 24 BITS AGREE */
	    for (k = 1; k <= 5; ++k) {
/* ***************************************************************** */
/*  TEMPORARILY CHECK 'EQUALITY' THIS WAY */
		y1 = ycoor[k + i__ * 5 - 6];
		y2 = ycoor[k + l * 5 - 6];
		if (y1 == 0. && y2 == 0.) {
		    goto L240;
		}
/* Computing MAX */
		d__2 = abs(y1), d__3 = abs(y2);
		if ((d__1 = (y1 - y2) / max(d__2,d__3), abs(d__1)) >= 1e-7) {
		    goto L245;
		}
L240:
		;
	    }
	    icoor[i__ - 1] = l;
	    goto L250;
L245:
	    ;
	}
	icoor[i__ - 1] = i__;
	++numcor;
	jcoor[numcor - 1] = i__;
L250:
	;
    }

/*  PRINT COORDINATES */

/* L260: */
    i__1 = numcor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	asym[0] = asym1;
	asym[1] = asym2;
	ipos = 2;
	i__2 = outinf_1.kntr;
	for (j = 1; j <= i__2; ++j) {
	    if (icoor[j - 1] != jcoor[i__ - 1]) {
		goto L270;
	    }
	    move_(asym, &ipos, &pltsym, &j, &c__1);
	    ++ipos;
L270:
	    ;
	}
	move_(asym, &ipos, &arprn, &c__1, &c__1);
	k = jcoor[i__ - 1];
	if (iwide != 0) {
	    io___3369.ciunit = status_1.iofile;
	    s_wsfe(&io___3369);
	    do_fio(&c__2, (char *)&asym[0], (ftnlen)sizeof(doublereal));
	    for (j = 1; j <= 5; ++j) {
		do_fio(&c__1, (char *)&ycoor[j + k * 5 - 6], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
	if (iwide == 0) {
	    io___3370.ciunit = status_1.iofile;
	    s_wsfe(&io___3370);
	    do_fio(&c__2, (char *)&asym[0], (ftnlen)sizeof(doublereal));
	    for (j = 1; j <= 5; ++j) {
		do_fio(&c__1, (char *)&ycoor[j + k * 5 - 6], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
/* L280: */
    }
    goto L300;
L290:
    if (iwide != 0) {
	io___3371.ciunit = status_1.iofile;
	s_wsfe(&io___3371);
	for (j = 1; j <= 5; ++j) {
	    do_fio(&c__1, (char *)&ycoor[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    if (iwide == 0) {
	io___3372.ciunit = status_1.iofile;
	s_wsfe(&io___3372);
	for (j = 1; j <= 5; ++j) {
	    do_fio(&c__1, (char *)&ycoor[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

/*  PLOTTING */

L300:
    aspot = ablnk;
    i__1 = *numpnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xvar = blank_1.value[*locx + i__ - 1];
	locyt = *locy;
	copy8_(agraph, aplot, &c__13);
	i__2 = outinf_1.kntr;
	for (k = 1; k <= i__2; ++k) {
	    yvr = blank_1.value[locyt + i__ - 1];
	    ktmp = icoor[k - 1];
	    ymin1 = pmin[ktmp - 1];
	    jpoint = (integer) ((yvr - ymin1) / delplt[k - 1] + .5) + 1;
	    if (jpoint <= 0) {
		goto L306;
	    }
	    if (jpoint > nwide) {
		goto L306;
	    }
	    move_(&aspot, &c__1, aplot, &jpoint, &c__1);
	    if (aspot == ablnk) {
		goto L303;
	    }
	    if (aspot == aper) {
		goto L303;
	    }
	    move_(aplot, &jpoint, &aletx, &c__1, &c__1);
	    goto L306;
L303:
	    move_(aplot, &jpoint, &pltsym, &k, &c__1);
L306:
	    locyt += outinf_1.npoint;
/* L310: */
	}
	yvr = blank_1.value[*locy + i__ - 1];
	if (outinf_1.ilogy[0] == 1) {
	    goto L315;
	}
	yvr = exp(knstnt_1.xlog10 * yvr);
L315:
	if (iwide != 0) {
	    io___3379.ciunit = status_1.iofile;
	    s_wsfe(&io___3379);
	    do_fio(&c__1, (char *)&xvar, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yvr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__13, (char *)&aplot[0], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (iwide == 0) {
	    io___3380.ciunit = status_1.iofile;
	    s_wsfe(&io___3380);
	    do_fio(&c__1, (char *)&xvar, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yvr, (ftnlen)sizeof(doublereal));
	    for (k = 1; k <= 8; ++k) {
		do_fio(&c__1, (char *)&aplot[k - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
/* L320: */
    }

/*  FINISHED */

    if (iwide != 0) {
	io___3381.ciunit = status_1.iofile;
	s_wsfe(&io___3381);
	e_wsfe();
    }
    if (iwide == 0) {
	io___3382.ciunit = status_1.iofile;
	s_wsfe(&io___3382);
	e_wsfe();
    }
    goto L500;

/*  TOO FEW POINTS */

L400:
    io___3383.ciunit = status_1.iofile;
    s_wsfe(&io___3383);
    e_wsfe();
L500:
    io___3384.ciunit = status_1.iofile;
    s_wsfe(&io___3384);
    e_wsfe();
    return 0;
} /* plot_ */

#undef cvalue
#undef nodplc
#undef pltsym
#undef arprn
#undef asym2
#undef asym1
#undef aper
#undef aletx
#undef ablnk


/* Subroutine */ int scale_(doublereal *xmin, doublereal *xmax, integer *n, 
	doublereal *xminp, doublereal *xmaxp, doublereal *del)
{
    /* Initialized data */

    static doublereal vint[5] = { 1.,2.,5.,10.,20. };
    static doublereal eps = 1e-12;

    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double d_lg10(doublereal *), exp(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__, m1, m2, np, nx;
    static doublereal fm1, fm2;
    static integer nal;
    static doublereal xfact;


/*     THIS ROUTINE DETERMINES THE 'OPTIMAL' SCALE TO USE FOR THE PLOT OF */
/* SOME OUTPUT VARIABLE. */


/*  ADAPTED FROM ALGORITHM 463 OF 'COLLECTED ALGORITHMS OF THE CACM' */

/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */


/* ...  TRAP TOO-SMALL DATA SPREAD */
/* *********************************************************** */
/*  TEMPORILY CHECK 'EQUALITY' THIS WAY */
    if (*xmin == 0. && *xmax == 0.) {
	goto L4;
    }
/* Computing MAX */
    d__2 = abs(*xmin), d__3 = abs(*xmax);
    if ((d__1 = (*xmax - *xmin) / max(d__2,d__3), abs(d__1)) >= 1e-4) {
	goto L10;
    }
L4:
    if (*xmin >= 0.) {
	goto L5;
    }
    *xmax = *xmin * .5 + eps;
    *xmin = *xmin * 1.5 - eps;
    goto L10;
L5:
    *xmax = *xmin * 1.5 + eps;
    *xmin = *xmin * .5 - eps;
/* ...  FIND APPROXIMATE INTERVAL SIZE, NORMALIZED TO [1,10] */
L10:
    a = (*xmax - *xmin) / (doublereal) (*n);
    nal = (integer) d_lg10(&a);
    if (a < 1.) {
	--nal;
    }
    xfact = exp(knstnt_1.xlog10 * (doublereal) nal);
    b = a / xfact;
/* ...  FIND CLOSEST PERMISSIBLE INTERVAL SIZE */
    for (i__ = 1; i__ <= 3; ++i__) {
	if (b < vint[i__ - 1] + eps) {
	    goto L30;
	}
/* L20: */
    }
    i__ = 4;
/* ...  COMPUTE INTERVAL SIZE */
L30:
    *del = vint[i__ - 1] * xfact;
    fm1 = *xmin / *del;
    m1 = (integer) fm1;
    if (fm1 < 0.) {
	--m1;
    }
    if ((d__1 = (doublereal) m1 + 1. - fm1, abs(d__1)) < eps) {
	++m1;
    }
/* ...  COMPUTE NEW MAXIMUM AND MINIMUM LIMITS */
    *xminp = *del * (doublereal) m1;
    fm2 = *xmax / *del;
    m2 = (integer) (fm2 + 1.);
    if (fm2 < -1.) {
	--m2;
    }
    if ((d__1 = fm2 + 1. - (doublereal) m2, abs(d__1)) < eps) {
	--m2;
    }
    *xmaxp = *del * (doublereal) m2;
    np = m2 - m1;
/* ...  CHECK WHETHER ANOTHER LOOP REQUIRED */
    if (np <= *n) {
	goto L40;
    }
    ++i__;
    goto L30;
/* ...  DO FINAL ADJUSTMENTS AND CORRECT FOR ROUNDOFF ERROR(S) */
L40:
    nx = (*n - np) / 2;
/* Computing MIN */
    d__1 = *xmin, d__2 = *xminp - (doublereal) nx * *del;
    *xminp = min(d__1,d__2);
/* Computing MAX */
    d__1 = *xmax, d__2 = *xminp + (doublereal) (*n) * *del;
    *xmaxp = max(d__1,d__2);
    return 0;
} /* scale_ */

/* Subroutine */ int fouran_(void)
{
    /* Initialized data */

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_3441 = { "FOURIER ANALYSIS                ", 0. };

#define fortit ((doublereal *)&equiv_3441)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_3442 = { "        ", 0. };

#define ablnk (*(doublereal *)&equiv_3442)


    /* Format strings */
    static char fmt_61[] = "(\002 FOURIER COMPONENTS OF TRANSIENT RESPONSE"
	    " \002,5a8///)";
    static char fmt_71[] = "(\0020DC COMPONENT =\002,1pd12.3/,\0020HARMONIC "
	    "  FREQUENCY    FOURIER    NORMALIZED    PHASE     NORMALIZED\002"
	    "/,\002    NO         (HZ)     COMPONENT    COMPONENT    (DEG)   "
	    " PHASE (DEG)\002//)";
    static char fmt_81[] = "(i6,1pd15.3,d12.3,0pf13.6,f10.3,f12.3/)";
    static char fmt_101[] = "(//5x,\002TOTAL HARMONIC DISTORTION =  \002,f12"
	    ".6,\002  PERCENT\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    complex q__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);

    /* Local variables */
    static integer j, k;
    static doublereal arg, thd, yvr, dcco, harm;
    static integer locx, locy, nknt, loct, ipnt, ipos;
    extern /* Subroutine */ int move_(doublereal *, integer *, doublereal *, 
	    integer *, integer *);
    static integer iknt;
    static doublereal freq1;
    extern /* Subroutine */ int getm8_(integer *, integer *), zero8_(
	    doublereal *, integer *);
    static doublereal phase, cosco[9], sinco[9];
    extern /* Subroutine */ int title_(integer *, integer *, integer *, 
	    doublereal *);
    static integer jstop;
    static doublereal xnorm, pnorm;
    extern /* Subroutine */ int ntrpl8_(integer *, integer *, integer *);
    static doublereal forfac;
#define nodplc ((integer *)&blank_1)
#define cvalue ((complex *)&blank_1)
    static doublereal forprd;
    static integer kfrout, numpnt;
    extern /* Subroutine */ int outnam_(integer *, integer *, doublereal *, 
	    integer *);
    static doublereal xnharm;
    extern /* Subroutine */ int magphs_(complex *, doublereal *, doublereal *)
	    ;
    static doublereal phasen;
    extern /* Subroutine */ int clrmem_(integer *);

    /* Fortran I/O blocks */
    static cilist io___3426 = { 0, 0, 0, fmt_61, 0 };
    static cilist io___3428 = { 0, 0, 0, fmt_71, 0 };
    static cilist io___3435 = { 0, 0, 0, fmt_81, 0 };
    static cilist io___3439 = { 0, 0, 0, fmt_81, 0 };
    static cilist io___3440 = { 0, 0, 0, fmt_101, 0 };



/*     THIS ROUTINE DETERMINES THE FOURIER COEFFICIENTS OF A TRANSIENT */
/* ANALYSIS WAVEFORM. */

/* SPICE VERSION 2G.6  SCCSID=TABINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=CIRDAT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=FLAGS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=MISCEL 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=STATUS 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=KNSTNT 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=TRAN 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=OUTINF 3/15/83 */
/* SPICE VERSION 2G.6  SCCSID=BLANK 3/15/83 */




    forprd = 1. / tran_1.forfre;
    outinf_1.xstart = tran_1.tstop - forprd;
    outinf_1.kntr = 1;
/* C    XN=101.0D0 */
    outinf_1.xincr = forprd / outinf_1.npoint;
/* C    NPOINT=XN */
    getm8_(&locx, &outinf_1.npoint);
    getm8_(&locy, &outinf_1.npoint);
    i__1 = tabinf_1.nfour;
    for (nknt = 1; nknt <= i__1; ++nknt) {
	outinf_1.itab[0] = nodplc[tabinf_1.ifour + nknt - 1];
	kfrout = outinf_1.itab[0];
	ntrpl8_(&locx, &locy, &numpnt);
	dcco = 0.;
	zero8_(sinco, &c__9);
	zero8_(cosco, &c__9);
	loct = locy + 1;
	ipnt = 0;
L10:
	yvr = blank_1.value[loct + ipnt - 1];
	dcco += yvr;
	forfac = (doublereal) ipnt * knstnt_1.twopi / outinf_1.npoint;
	arg = 0.;
	for (k = 1; k <= 9; ++k) {
	    arg += forfac;
	    sinco[k - 1] += yvr * sin(arg);
	    cosco[k - 1] += yvr * cos(arg);
/* L20: */
	}
	++ipnt;
	if (ipnt != outinf_1.npoint) {
	    goto L10;
	}
	dcco /= outinf_1.npoint;
	forfac = 2. / outinf_1.npoint;
	for (k = 1; k <= 9; ++k) {
	    sinco[k - 1] *= forfac;
	    cosco[k - 1] *= forfac;
/* L30: */
	}
	title_(&c__0, &c__72, &c__1, fortit);
	ipos = 1;
	outnam_(&kfrout, &c__1, outinf_1.string, &ipos);
	move_(outinf_1.string, &ipos, &ablnk, &c__1, &c__7);
	jstop = (ipos + 6) / 8;
	io___3426.ciunit = status_1.iofile;
	s_wsfe(&io___3426);
	i__2 = jstop;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&outinf_1.string[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	io___3428.ciunit = status_1.iofile;
	s_wsfe(&io___3428);
	do_fio(&c__1, (char *)&dcco, (ftnlen)sizeof(doublereal));
	e_wsfe();
	iknt = 1;
	freq1 = tran_1.forfre;
	xnharm = 1.;
	r__1 = (real) sinco[0];
	r__2 = (real) cosco[0];
	q__1.r = r__1, q__1.i = r__2;
	magphs_(&q__1, &xnorm, &pnorm);
	phasen = 0.;
	io___3435.ciunit = status_1.iofile;
	s_wsfe(&io___3435);
	do_fio(&c__1, (char *)&iknt, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xnorm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xnharm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pnorm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phasen, (ftnlen)sizeof(doublereal));
	e_wsfe();
	thd = 0.;
	for (iknt = 2; iknt <= 9; ++iknt) {
	    freq1 = (doublereal) iknt * tran_1.forfre;
	    r__1 = (real) sinco[iknt - 1];
	    r__2 = (real) cosco[iknt - 1];
	    q__1.r = r__1, q__1.i = r__2;
	    magphs_(&q__1, &harm, &phase);
	    xnharm = harm / xnorm;
	    phasen = phase - pnorm;
	    thd += xnharm * xnharm;
	    io___3439.ciunit = status_1.iofile;
	    s_wsfe(&io___3439);
	    do_fio(&c__1, (char *)&iknt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&freq1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&harm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xnharm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phase, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phasen, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L90: */
	}
	thd = sqrt(thd) * 100.;
	io___3440.ciunit = status_1.iofile;
	s_wsfe(&io___3440);
	do_fio(&c__1, (char *)&thd, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L105: */
    }
    clrmem_(&locx);
    clrmem_(&locy);
/* L110: */
    return 0;
} /* fouran_ */

#undef cvalue
#undef nodplc
#undef ablnk
#undef fortit


/* Main program alias */ int spice_ () { MAIN__ (); return 0; }
