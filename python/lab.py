from math import cos, sin, pi
x = pi
f_x = cos(2 * x)
f_prime_x = -2 * sin(2 * x)
f_double_prime_x = -4 * cos(2 * x)
# Rounding f'(x) to avoid small floating-point errors
f_prime_x_rounded = round(f_prime_x, 10)
print("The value of f(x) is:", f_x)
print("The value of f'(x) is:", f_prime_x_rounded)  # Rounded value
print("The value of f''(x) is:", f_double_prime_x)
