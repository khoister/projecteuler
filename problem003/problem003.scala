object Problem003 {

  def prime_sieve(n : Int) : Array[Int] = {
    val limit = n+1
    var primes = new Array[Int](limit)
    primes(0) = 0
    primes(1) = 0

    // Initialize
    for (i <- 2 until limit) {
      primes(i) = 1
    }

    // Eliminate the non-primes
    for (j <- 2 until limit if primes(j) == 1) {
      // Squaring would be the right thing but getting
      // some sort of overflow error
      // var k = j * j
      var k = j + j

      while (k < limit)
      {
        primes(k) = 0
        k += j
      }
    }
    return primes
  }

  def main(args: Array[String]): Unit = {
    val n : BigInt = BigInt("600851475143")
    val v : Int = Math.sqrt(n.toDouble).toInt

    val s = prime_sieve(v)
    var largest_prime_factor = 0
    for (i <- 0 until s.length if s(i) == 1) {
      if (n % i == 0)
        largest_prime_factor = i
    }
    println("Largest prime factor -> " + largest_prime_factor)
  }

}

