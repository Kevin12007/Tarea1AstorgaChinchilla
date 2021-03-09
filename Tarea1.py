# ERR3x3 -4.5 Usan asserts cuando yo les pido retornar el codigo de error
#############################################################################
# Elaborado por: Andrey Astorga Bogantes y Kevin Chinchilla Gomez           #
# Fecha de creación: 27/02/21 8:30am                                        #
# Fecha de modificación:27/02/21 11:30pm                                    #
# Versión: 3.9                                                              #
#############################################################################

# Corresponde el metodo check_char, este recibe como entrada "parametro"
#   y verifica que cumpla con las condiciones, es decir:
#
# Debe ser un unico caracter
# Debe estar en el rango de A-Z o a-z
# Deber ser un string
def check_char(parametro):
    # El siguiente assert se encarga de verificar que el parametro
    # de entrada no sea un int, float, etc.
    #
    # Solamente puede ser de tipo string
    Error1003 = "ERROR #1003:Entrada inválida, debe ser un string"
    assert ((type(parametro) == str)), Error1003
    # Se define una lista con todos los caracteres aceptables por el método
    abecedario = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                  'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                  'w', 'x', 'y', 'z']
    largo = len(parametro)
    contador1 = 0  # Variable que sirve para verificar
    #                   los tipos de datos ingresados en forma de string
    for cont in range(largo):
        for cont2 in range(len(abecedario)):
            if abecedario[cont2] == parametro[cont]:
                contador1 = contador1+1

    # El siguiente assert se encarga de verificar que los datos dentro del
    #   string de entrada "parametro" se encuentran dentro del rango A-z o a-z
    #
    # Utiliza la variable contador1 para hacer la comparación
    Error1002 = "Error #1002: Debe ingresar datos solo del rango A-z o a-z"
    assert (contador1 == largo), Error1002

    # El siguiente assert se encarga de verificar
    #   que "parametro" solamente constituya una letra
    #
    # Utiliza la variable largo para hacer la verificacion
    Error1001 = "Error #1001: Debe ingresar solo un caracter"
    assert (largo == 1), Error1001
    return 0  # Si ninguno de los assert presenta error,
    #               el dato esta correcto y retorna 0


# Corresponde al metodo caps_switch, este recibe una entrada y si cumple con
#   chech_char, convierte la letra de entrada de mayuscula a minuscula
#   y viceversa
#
# Su entrada debe ser un string, de un unico caracter,
#   la conversion lo hace mediante la funcion de python swapcase

def caps_switch(entrada):
    entra2 = check_char(entrada)  # Llama a la funcion check_char
    if (entra2 == 0):
        salida = entrada.swapcase()  # Hace el cambio de mayuscula a
        #                               minuscula o viceversa
        return salida  # retorna el cambio
    else:
        return entra2  # En caso de error
