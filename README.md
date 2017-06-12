# rcppTests

A repository for testing various aspects of using Rcpp in an R package

Benchmark between passing by-value and passing by-reference
```

library(rcppTests)

n <- 10000

resValue <- rcppTests::rcppValue(n)
resReference <- rcppTests::rcppReference(n)

sum(resValue) == sum(resReference)
# [1] TRUE

library(microbenchmark)

n <- 1e+7
microbenchmark(
  value = { rcppValue(n) },
  ref = { rcppReference(n) }
)

# Unit: milliseconds
#   expr      min       lq     mean   median       uq      max neval
# value 51.19497 53.75807 55.60829 54.75141 55.97052 71.43570   100
#   ref 51.38387 53.46435 55.39959 54.55089 56.04772 70.77768   100

```
