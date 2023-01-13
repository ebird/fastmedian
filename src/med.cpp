#include <Rcpp.h>

//' Calculate the sample median using optimized C++ code
//'
//' @param x numeric vector.
//' @export
//' @return Sample median of x after removing NA values.
// [[Rcpp::export]]
double med(const Rcpp::NumericVector& x) {
 Rcpp::NumericVector xx = Rcpp::clone(x);
 Rcpp::NumericVector::iterator last = std::remove_if(xx.begin(), xx.end(), R_IsNA);
 Rcpp::NumericVector::iterator start = xx.begin();
 const int sz = last - start;
 const int middle = sz / 2 - 1;
 if (sz == 0) {
   return Rcpp::NumericVector::get_na();
 } else if (sz % 2 == 0) {
   std::nth_element(start, start + middle, last);
   return (xx[middle] + *(std::min_element(start + middle + 1, last))) / 2.0;
 } else {
   std::nth_element(start, start + middle + 1 , last);
   return xx[middle + 1];
 }
}
