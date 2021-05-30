// we try  to  accelerate some linear algebra opertaion
// using the distributed systems
// we want to find the unknowns for a very very large set of equations
// 20 equations and 20004 equations 4096 equations
// so here we can leverage parallelism rather than doing this operations serially
// what is gausian elimination
// each of the row of the matrix represents one linear equation
// each column is representing the coffecients of some variable
// converting it into  upper triangular matrix allows us to solve the systems of linear equations because you can
// 
