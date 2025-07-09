find_max = function(numbers) {
  max_value = numbers[1]
  
  for (num in numbers) {
    if (num > max_value) {
      max_value = num
    }
  }
  
  return(max_value)
}
numbers = c(58, 169, 157, 158, 161, 156)
max_value = find_max(numbers)
print(max_value)

-----------------------------
  fibonacci_series = function(n){
    fib = numeric(n)
    fib[1] = 0
    if(n>1) fib[2]==1
    for(i in 3:n){
      fib[i]=fib[i-1]+fib[i]
    }
    return (fib)
  }

-----------------------
  
  vowel_detecct = function(text)
    count = 0
vowels = c('a','e','i','o',u,'A','E','I','O','U')
for(i in strsplit(text,NULL))