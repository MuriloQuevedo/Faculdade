# in (esta entre) not in (não estar entre)
# string são iteráveis, ou seja, pode ser "buscada", uma parte da mesma

# exemplo
# 0 1 2 3 4 5 
# S u k u n a
# -6 -5 -4 -3 -2 -1 

nome = "Sukuna"
print(nome[2])

print(10 * "-")

print("S" in nome)
print("Z" in nome)

print(10 * "-")

print("S" not in nome)
print("Z" not in nome)

print(10 * "-")

nome = input("digite seu nome ")
encontrar = input("digite o que deseja encontrar em seu nome ")

if encontrar in nome:
    print(f"{encontrar} está em {nome}")

else:
    print(f"{encontrar} não está em {nome}")