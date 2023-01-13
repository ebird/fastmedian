
<!-- README.md is generated from README.Rmd. Please edit that file -->

# fastmedian

An optimized median function that uses C++ code to quickly calculate the
median of a numeric vector after removing NA values.

## Installation

You can install the development version of `fastmedian` with:

``` r
remotes::install_github("mstrimas/ebirdstwf")
```

## Example

``` r
library(fastmedian)
med(1:4)
#> [1] 2.5
med(c(1:3, 100, 1000))
#> [1] 3
med(c(NA_real_, 1:3, 100, NA_real_, 1000, NA_real_))
#> [1] 3
```
