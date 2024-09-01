# if / elif . . .  / else
# se / se não se  / se não
# else é a última coisa a ser executada

entrada = input("sim ou nao? ")

if entrada == "sim":
    print("voce digitou 'sim'") # precisa desse espaço, para o código ficar dentro do if, precisa dos dois pontos também

elif entrada == "nao":
    print("voce digitou 'nao'")

else:
    print("rebelde em, era pra digitar sim ou nao. e nem isso e capaz de fazer")