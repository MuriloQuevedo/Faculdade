# try : tentar executar o código 
# except : ocorreu algum erro ao tentar executar

numero = input("digite um número ")

if (numero.isdigit()): # isdigit verifica se só foram digitados números
    numero_int = int(numero)
    print(f"o dobro de {numero_int} é {numero_int * 2}")

else:
    print("náo é um número")


#ele executa todas as linhas que tiver funcionando, e se chegar em uma errada, aí ele pula pro except

try:
    print(f"número:{numero} ")
    numero_int = int(numero)
    print(f"o dobro de {numero_int} é {numero_int * 2}")

except:
    print("isso não é um número")