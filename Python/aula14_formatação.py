a = "A"
b = "B"
c = 1.1

string = "a={}, b={}, c={}"
formato = string.format(a, b, c)
print(formato)

# outro jeito
string = "a={0}, b={1}, c={2}"
formato = string.format(a, b, c)
print(formato)