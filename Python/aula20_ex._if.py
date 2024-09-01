valor1 = input("digite o primeiro número ")
valor2 = input("digite o segundo numero ")

int_valor1 = int(valor1)
int_valor2 = int(valor2)

if int_valor1 > int_valor2:
    print(f"o valor 1 é maior: {int_valor1}")

elif int_valor2 > int_valor1:
    print(f"o segundo número é maior:{int_valor2}")

elif int_valor1 == int_valor2:
    print(f"os valores são iguais:{int_valor1} {int_valor2}")


