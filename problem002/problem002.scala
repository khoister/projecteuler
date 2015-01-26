/*
 * Problem 2
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms.
 *
 */

object Problem002 {

  def fib(n : Int) : Int = {
    var f1 = 1;
    var f2 = 1;
    var f  = 1;

    if (n == 1 || n == 2) return 1;
    else {
      for (i <- 3 to n) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
      }
      return f;
    }
  }

  def main(args: Array[String]): Unit = {
    var total = 0;
    var i = 1;
    var f = 0;

    while (f <= 4000000) {
      f = fib(i);
      i += 1;
      if (f%2 == 0)
        total += f;
    }

    println(total);
  }

}

