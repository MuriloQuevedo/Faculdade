#recebe dados do úsuario

nome = input("Qual o seu nome? ") 
print(f"O seu nome é {nome}")

# vai dar errado, irá concatenar as duas. Pois nessa situação, são strings 
numero_1 = input("digite um número ")
numero_2 = input("digite outro número ")
print(f"a soma dos números : {numero_1 + numero_2}")


# jeito correto
numero_1 = input("digite um número ")
numero_2 = input("digite outro número ")

int_numero_1 = int(numero_1)
int_numero_2 = int(numero_2)
print(f"a soma dos números : {int_numero_1 + int_numero_2}")