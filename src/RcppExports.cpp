// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// Matcher
List Matcher(int Ncontrols, int Tcontrols, int Ncases, int reuseControls, IntegerVector controlIndex, IntegerVector caseIndex, IntegerVector controls, IntegerVector cases, int Ndateterms, IntegerMatrix datescases, IntegerMatrix datescontrols, int NoIndex);
RcppExport SEXP _heaven_Matcher(SEXP NcontrolsSEXP, SEXP TcontrolsSEXP, SEXP NcasesSEXP, SEXP reuseControlsSEXP, SEXP controlIndexSEXP, SEXP caseIndexSEXP, SEXP controlsSEXP, SEXP casesSEXP, SEXP NdatetermsSEXP, SEXP datescasesSEXP, SEXP datescontrolsSEXP, SEXP NoIndexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type Ncontrols(NcontrolsSEXP);
    Rcpp::traits::input_parameter< int >::type Tcontrols(TcontrolsSEXP);
    Rcpp::traits::input_parameter< int >::type Ncases(NcasesSEXP);
    Rcpp::traits::input_parameter< int >::type reuseControls(reuseControlsSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type controlIndex(controlIndexSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type caseIndex(caseIndexSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type controls(controlsSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type cases(casesSEXP);
    Rcpp::traits::input_parameter< int >::type Ndateterms(NdatetermsSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type datescases(datescasesSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type datescontrols(datescontrolsSEXP);
    Rcpp::traits::input_parameter< int >::type NoIndex(NoIndexSEXP);
    rcpp_result_gen = Rcpp::wrap(Matcher(Ncontrols, Tcontrols, Ncases, reuseControls, controlIndex, caseIndex, controls, cases, Ndateterms, datescases, datescontrols, NoIndex));
    return rcpp_result_gen;
END_RCPP
}
// daysnonhosp
Rcpp::NumericVector daysnonhosp(Rcpp::NumericVector id, Rcpp::NumericVector pdate, Rcpp::NumericVector iddates, Rcpp::NumericVector inddto, Rcpp::NumericVector uddto);
RcppExport SEXP _heaven_daysnonhosp(SEXP idSEXP, SEXP pdateSEXP, SEXP iddatesSEXP, SEXP inddtoSEXP, SEXP uddtoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type id(idSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type pdate(pdateSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type iddates(iddatesSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type inddto(inddtoSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type uddto(uddtoSEXP);
    rcpp_result_gen = Rcpp::wrap(daysnonhosp(id, pdate, iddates, inddto, uddto));
    return rcpp_result_gen;
END_RCPP
}
// innerMedicinMacro
Rcpp::List innerMedicinMacro(Rcpp::DataFrame dat, Rcpp::DataFrame admdat, Rcpp::List doses, NumericVector idunique, double prescriptionwindow, double maxdepot, bool collapse);
RcppExport SEXP _heaven_innerMedicinMacro(SEXP datSEXP, SEXP admdatSEXP, SEXP dosesSEXP, SEXP iduniqueSEXP, SEXP prescriptionwindowSEXP, SEXP maxdepotSEXP, SEXP collapseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::DataFrame >::type dat(datSEXP);
    Rcpp::traits::input_parameter< Rcpp::DataFrame >::type admdat(admdatSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type doses(dosesSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type idunique(iduniqueSEXP);
    Rcpp::traits::input_parameter< double >::type prescriptionwindow(prescriptionwindowSEXP);
    Rcpp::traits::input_parameter< double >::type maxdepot(maxdepotSEXP);
    Rcpp::traits::input_parameter< bool >::type collapse(collapseSEXP);
    rcpp_result_gen = Rcpp::wrap(innerMedicinMacro(dat, admdat, doses, idunique, prescriptionwindow, maxdepot, collapse));
    return rcpp_result_gen;
END_RCPP
}
// na_locf
IntegerVector na_locf(IntegerVector x);
RcppExport SEXP _heaven_na_locf(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(na_locf(x));
    return rcpp_result_gen;
END_RCPP
}
// split2
List split2(IntegerVector pnrnum, IntegerVector inn, IntegerVector out, IntegerVector event, IntegerVector mergevar, IntegerMatrix split, int numcov);
RcppExport SEXP _heaven_split2(SEXP pnrnumSEXP, SEXP innSEXP, SEXP outSEXP, SEXP eventSEXP, SEXP mergevarSEXP, SEXP splitSEXP, SEXP numcovSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type pnrnum(pnrnumSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type inn(innSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type out(outSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type event(eventSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type mergevar(mergevarSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type split(splitSEXP);
    Rcpp::traits::input_parameter< int >::type numcov(numcovSEXP);
    rcpp_result_gen = Rcpp::wrap(split2(pnrnum, inn, out, event, mergevar, split, numcov));
    return rcpp_result_gen;
END_RCPP
}
// splitDate
List splitDate(IntegerVector inn, IntegerVector out, IntegerVector event, IntegerVector mergevar, IntegerVector seq, IntegerVector varname);
RcppExport SEXP _heaven_splitDate(SEXP innSEXP, SEXP outSEXP, SEXP eventSEXP, SEXP mergevarSEXP, SEXP seqSEXP, SEXP varnameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type inn(innSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type out(outSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type event(eventSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type mergevar(mergevarSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type seq(seqSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type varname(varnameSEXP);
    rcpp_result_gen = Rcpp::wrap(splitDate(inn, out, event, mergevar, seq, varname));
    return rcpp_result_gen;
END_RCPP
}
// splitFT
List splitFT(IntegerVector pnrnum, IntegerVector inn, IntegerVector out, IntegerVector event, IntegerVector mergevar, IntegerVector Spnrnum, std::vector<std::string> val, IntegerVector start, IntegerVector end, IntegerVector num, int numcov);
RcppExport SEXP _heaven_splitFT(SEXP pnrnumSEXP, SEXP innSEXP, SEXP outSEXP, SEXP eventSEXP, SEXP mergevarSEXP, SEXP SpnrnumSEXP, SEXP valSEXP, SEXP startSEXP, SEXP endSEXP, SEXP numSEXP, SEXP numcovSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type pnrnum(pnrnumSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type inn(innSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type out(outSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type event(eventSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type mergevar(mergevarSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type Spnrnum(SpnrnumSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type val(valSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type start(startSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type end(endSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type num(numSEXP);
    Rcpp::traits::input_parameter< int >::type numcov(numcovSEXP);
    rcpp_result_gen = Rcpp::wrap(splitFT(pnrnum, inn, out, event, mergevar, Spnrnum, val, start, end, num, numcov));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_heaven_Matcher", (DL_FUNC) &_heaven_Matcher, 12},
    {"_heaven_daysnonhosp", (DL_FUNC) &_heaven_daysnonhosp, 5},
    {"_heaven_innerMedicinMacro", (DL_FUNC) &_heaven_innerMedicinMacro, 7},
    {"_heaven_na_locf", (DL_FUNC) &_heaven_na_locf, 1},
    {"_heaven_split2", (DL_FUNC) &_heaven_split2, 7},
    {"_heaven_splitDate", (DL_FUNC) &_heaven_splitDate, 6},
    {"_heaven_splitFT", (DL_FUNC) &_heaven_splitFT, 11},
    {NULL, NULL, 0}
};

RcppExport void R_init_heaven(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
