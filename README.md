# rcppTests

I built this little test package for two reasons:

1. Dirk's [comment here](https://stackoverflow.com/a/24113063/5977215) 
 > But the most important lesson is that you should not just believe what people tell you on the internet, but rather measure and profile whenever possible.
 
2. I can update a vector by-reference in a C++ function using `Rcpp`


Therefore, I have two functions in this package, `rcppReference` and `rcppValue`, the first updates a vector by-reference, and the second by-value.




Here is a benchmark of how the two functions perform

```

library(rcppTests)

n <- 10000

resValue <- rcppTests::rcppValue(n)
resReference <- rcppTests::rcppReference(n)

sum(resValue)
# [1] 5000
sum(resReference)
# [1] 5000

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

So there we are, both functions perform as expected, and both perform at about the same speed.
