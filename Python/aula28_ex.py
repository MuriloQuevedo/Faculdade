nome = input("usuario, digite seu nome ")
idade = input("digite sua idade ")


if nome == "" or idade == "":
    print("Desculpe, você deixou campos vazios")

else:
    print(f"seu nome é {nome}")
    print(f"sua idade é {idade}")
    quantidade = (len(nome))
    print(f"seu nome tem {quantidade} letras")
    print(nome[0:1], "é a sua primeira letra") # print(f"A última letra do seu nome é: {nome[0]}"), mesma coisa
    print(f"A última letra do seu nome é: {nome[-1]}")


