object Problem004 {

  def main(args : Array[String]) : Unit = {
    var largest = 0;
    for (i <- 100 until 1000) {
      for (j <- 100 until 1000) {
        val n = i * j
        val s = n.toString
        if (s == s.reverse) {
          if (n > largest)
            largest = n
        }
      }
    }
    println(largest)
  }

}
