#include <Rcpp.h>
#include <string>
#include <vector>
using namespace Rcpp;
// [[Rcpp::export]]
List split2(IntegerVector pnrnum, // PNR as sequence number - base data
              NumericVector inn, // Starttimes - base data
              NumericVector out, // Endtimes - base data
              IntegerVector event, // Event at end of interval 0/1 - base data
              IntegerVector mergevar, // Merge variable, multiple records can have same pnr - base data
              NumericMatrix split, // split guide matrix - pnrnum and date columns
              int numcov){ // Max number of covariate dates for each individual 

// This function received "base data" with pnrnum (integer consecutive version of pnr),
//                                    inn/out (start/end of interval)
//                                    event (0/1) 
//                                    mergevar (variable to later add residual data) and 
//                                    split (splitguide) - Matrix with 3 columns:
//                                      pnrnum
//                                      date (integer) of comorbidity
//                                      Number of comorbidity (First in list is 1) Sorted to ensure that first date comes first
  // Define output vectors
  std::vector<int> Opnrnum;
  Opnrnum.reserve(pnrnum.size()*2);
  std::vector<int> Omergevar;
  Omergevar.reserve(pnrnum.size()*2);
  std::vector<double> Oinn;  // Starttimes output
  Oinn.reserve(pnrnum.size()*2);
  std::vector<double> Oout; // Endtimes output
  Oout.reserve(pnrnum.size()*2);
  std::vector<int> Oevent; // Event at end 0/1
  Oevent.reserve(pnrnum.size()*2);
  std::vector<std::string> Oval; // output value
  Oval.reserve(pnrnum.size()*2);
  std::vector<std::vector<int> > Osplit; // Matrix for 0/1 according to splits
  Osplit.resize(numcov); // One vector for each splitparameter
  for(int i=0; i<numcov;i++)Osplit[i].reserve(pnrnum.size()*2);
  int l1=pnrnum.size(); // length of base data
  int l2=split.nrow();
   l2=l2-split(l2-1,3); // start of last element of splitting guide
  int counter=0; // counts through split guide
  int INN=-1; // start of pnr-range in output data
  int OUT=-1; // end of pnr-range in output data
  int OUText=0; // Lengthening of out from splitting
  // Loop through all data in base data and split a new pnr has
  // been identified.  The base data are added to output vectors sequentially and split
  // prior to interrogating next pnr
   for(int i=0; i<l1; i++){ // Loop through base data
      INN=OUT+1;  // Start of next pnr-sequence - INN/OUT necessary because record can be split and reanalyzed
      while (counter<l2 && split(counter,0)<pnrnum(i)) counter+=split(counter,3); // Increase row by number of covariates in splitting guide until match - or end passed
       //Searching in splitting guide until match found or passed - counter maintains place in splitting guide
      OUT+=1;
      // Start by pushing the record with all comorbidities=0
      Opnrnum.push_back(pnrnum(i));
      Omergevar.push_back(mergevar(i));
      Oinn.push_back(inn(i));
      Oout.push_back(out(i));
      Oevent.push_back(event(i));
      for(int j=0; j<numcov;j++) Osplit[j].push_back(0);
       // Any splitting?
       if (split(counter,0) == pnrnum(i)) { // Match and potentially split
        for (int ii=0; ii<split(counter+ii,3); ii++){ // Outer loop through elements of splitting guide for current pnr
          OUT=OUT+OUText; // No relevant action on initialisation - but relevant after splitting which lengthens number of records
          OUText=0; // reset - on first pass, just one record
          for (int iii=INN; iii<=OUT; iii++){ // inner loop - Output data - just one record prior to split - iii refers to O-copy of base records
             if (split(counter+ii,1)<-2000000000 || split(counter+ii,1)>Oout[iii]) {
             //std::cout<<"splitvalue="<<  split(counter+ii,1) <<"\n";            
             // Past current record - remain current value which may have been established previously
             }
               else // Zero record length - and equality - just change value
                 if (split(counter+ii,1)==Oinn[iii] && Oinn[iii]==Oout[iii])
                   Osplit[split(counter+ii,2)-1][iii]=1;
                 else
                 if (split(counter+ii,1)<=Oinn[iii]) {
                    Osplit[split(counter+ii,2)-1][iii]=1; // Before interval, change to "1"
                 }
                   else
                     if(split(counter+ii,1)>Oinn[iii] && split(counter+ii,1)<Oout[iii]){
                       OUText +=1; //Extra record to trawl
                       //Date in period, create new record and adjust
                       Opnrnum.push_back(Opnrnum[iii]);
                       Omergevar.push_back(Omergevar[iii]);
                       Oinn.push_back(split(counter+ii,1)); // New starts at split
                       Oout.push_back(Oout[iii]); // and original end
                       Oevent.push_back(Oevent[iii]);
                       for(int j=0; j<numcov;j++)
                         if(j==split(counter+ii,2)-1)Osplit[j].push_back(1);
                         else Osplit[j].push_back(Osplit[j][iii]);  // previous value
                         //Adjust old record
                       Oout[iii]=split(counter+ii,1);
                       Oevent[iii]=0;
                     }
                     else
                       if (split(counter+ii,1)==Oout[iii] && Oevent[iii]==1){ // Date at end of period, period>=1 day and EVENT, create 2 records
                         //Date in period, create new record and adjust
                         OUText +=1;
                         Opnrnum.push_back(Opnrnum[iii]);
                         Omergevar.push_back(Omergevar[iii]);
                         Oinn.push_back(split(counter+ii,1)); // New starts at split
                         Oout.push_back(Oout[iii]); // and original end
                         Oevent.push_back(Oevent[iii]);
                         for(int j=0; j<numcov;j++)
                           if(j==ii-1)Osplit[j].push_back(1); // all starts with prior value
                           else Osplit[j].push_back(Osplit[j][iii]);
                           //Adjust old record
                         Oevent[iii]=0; // No date change
                      }
           }// end iii-loop - base data copy
         } // End ii-loop - splitting guide
       } // end match and split
   } // End i-for loop - sequencing base data
  return (Rcpp::List::create(Rcpp::Named("pnrnum") = Opnrnum,
                             Rcpp::Named("merge")=Omergevar,
                             Rcpp::Named("inn") = Oinn,
                             Rcpp::Named("out") = Oout,
                             Rcpp::Named("event") = Oevent,
                             Rcpp::Named("split") = Osplit));
}



// /*** R
// library(data.table)
// pnrnum <- 1:10
// inn <- c(100,100,150,100,133,167,100,150,100,100)
// out <- c(200,150,200,133,167,200,150,200,200,200)
// event <- c(1,0,0,0,0,1,0,1,1,1)
// mergevar <- 11:20
// 
// split2 <- c(100,150,175,101,132,100,175,175,175,175)
// split3 <- c(101,150,174,101,150, 50, 50,175,175,175)
// split4 <- c(150,101,173,101,167, 200,200,174,175,176)
// split <- data.table(pnrnum,split2,split3,split4)
// split2 <- melt(data=split,id.vars="pnrnum",measure.vars=c("split2","split3","split4"))
// setkeyv(split2,"pnrnum")
// split2[,number:=1:.N,by="pnrnum"]
// split2[,variable:=NULL]
// setkeyv(split2,c("pnrnum","value"))
// split2 <- as.matrix (split2)
// 
// out <- split2_beta(pnrnum, # PNR as sequence number - base data
//         inn, # Starttimes - base data
//         out, # Endtimes - base data
//         event, # Event at end of interval 0/1 - base data
//         mergevar, # Merge variable, multiple records can have same pnr - base data
//         split2, # split guide matrix - pnrnum and date columns
//         3)
// out <- cbind(setDT(out[1:5]),setDT(do.call(cbind,out[6])))
// setkeyv(out,c("pnrnum","inn"))
// */
