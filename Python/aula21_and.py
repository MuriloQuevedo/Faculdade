# and (e), todas as condições precisam ser verdedeiras

entrada = input("entrar ou sair? ")
senha_digitada = input("senha: ")
senha_permitida = 12345


if entrada == "entrar" and int(senha_digitada) ==  senha_permitida:
   
    print("entrar")

else:
    print("sair") 