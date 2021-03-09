# ERR 2 -2.5
# ERR5x3 -4.5
# No les pongo el error4 porque la funcion internamente hace el assert
# pero sepan que la idea era que el test fuera el unico que hiciera asserts
from Tarea1 import check_char
from Tarea1 import caps_switch
abecedario1 = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
abecedario2= ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
#Casos de exito para check_char rango A-Z
def test_checkchar ():
    for i in range(len(abecedario1)):
        assert check_char(abecedario1[i])==0
#Casos de exito para check_char rango a-z
def test_checkchar2 ():
    for i in range(len(abecedario2)):
        assert check_char(abecedario2[i])==0
#Casos de exito para caps_switch, rango A-Z
def test_caps_Switch ():
    for i in range(len(abecedario1)):
        assert caps_switch(abecedario1[i])==abecedario2[i]

#Casos de exito para caps_switch rango a-z
def test_caps_Switch2 ():
     for i in range(len(abecedario1)):
        assert caps_switch(abecedario2[i])==abecedario1[i]

#CASOS NEGATIVOS PARA CHECK_CHAR
#Condicion b:No puede recibir más de un caracter
def test_errorUnico_caracter ():
    check_char("aa")
#Condicion c: NO recibe caracteres fuera del rango A-z
def test_fuera_del_rango ():
    check_char("AB81")
#Condicion d: Recibe únicamente string como entrada
def test_caracterInval ():
    check_char(52)
