#' rcpp Reference
#'
#' function to update a logical vector
#' @param vectorSize integer
#'
#' @export
rcppReference <- function(vectorSize){
  return(rcppChangeVectorReference(vectorSize))
}


#' rcpp Value
#'
#' function to update a logical vector
#' @param vectorSize integer
#' @export
rcppValue <- function(vectorSize){
  return(rcppChangeVector(vectorSize))
}

