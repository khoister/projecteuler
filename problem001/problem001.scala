object Problem001 {

  def main(args: Array[String]): Unit = {
    var total = 0;
    for (i <- 1 until 1000 if i%3==0 || i%5==0) {
        total += i;
    }
    println("Sum is " + total)
  }
}

