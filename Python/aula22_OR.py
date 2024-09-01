# or (ou) é quando qualuqer uma das condições forem verdadeiras, será válido

entrada = input("entrar ou sair? ")
senha_digitada = input("senha: ")
senha_permitida = 12345

#senha digitada está como string, logo ter que passar para int
if (entrada == "entrar" or entrada == "ENTRAR") and int(senha_digitada) ==  senha_permitida: 
    print("entrar")

else:
    print("sair") 

