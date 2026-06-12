,>,                Read Digit 1 into Cell 0 and Digit 2 into Cell 1
>++++++[<-------->--------<-] Subtract 48 from both to get raw integers

<<                 Go back to Cell 0
[                  Multiplication Loop (runs Cell 0 times)
 >                 Go to Cell 1
 [>>+>+<<<-]       Move Cell 1 to Cell 3 and Cell 4
 >>>               Go to Cell 4
 [<<<+>>>-]        Move Cell 4 back to Cell 1
 <<<-              Decrement Cell 0
]

# Cell 2 now contains the total product (0 to 81)
# Now we divide Cell 2 by 10 to split the digits
>>                 Move to Cell 2 (Product)
[
 -                 Decrement Product total
 >+                Move to Cell 3 (Temporary Ones counter)
 ++++++++++        Set Cell 4 to 10 (Divisor loop)
 [
  -                Decrement Cell 4
  >+<              Move to Cell 5 to flag if we hit a multiple of 10
 ]
 >                 Move to Cell 5
 [
  -                Clear Cell 5 flag
  <<-              We didn't hit 10 yet; decrement Cell 3 (Ones)
  >>               Return to Cell 5
 ]
 <<                Move back to Cell 3
 [
  >+               If Cell 3 wasn't cleared by the flag, it means we hit a multiple of 10!
  <-               Clear Cell 3
 ]
 >                 Move to Cell 4 (Tens counter accumulator)
 [-<<<<+>>>>]      If we hit 10, increment our Tens digit tracking cell (Cell 0)
 <<<<              Go back to Cell 2
]

# Cell 0 now holds the Tens digit, Cell 3 holds the Ones digit
# Convert Tens to ASCII and print if it's greater than 0
>++++++[<++++++++>-]<.

# Convert Ones to ASCII and print
>>>++++++[<++++++++>-]<.

# Print a newline character (ASCII 10) at the very end
++++++++++.
