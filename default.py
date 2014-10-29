# -*- coding: utf-8 -*-
import serial
import time
global puerto
def index():
		response.flash = T("Welcome to web2py!")
		return dict(message=T('Hello World'))
    
try:
	puerto_Serie=serial.Serial('/dev/ttyACM1', 115200)
	puerto_Serie.close()
	puerto_Serie.open()

	puerto=1


except Exception as e:
	try:
		puerto_Serie=serial.Serial('/dev/ttyACM0', 115200)
		puerto_Serie.close()
		puerto_Serie.open()

		puerto=1

		
	except :
		if e.strerror=='No such file or directory':
			puerto=3
			pass
			
		


   
 
def led_ON():
	puerto_Serie.write("1")
def led_OFF():
	puerto_Serie.write("0")

	
	
def temporizador_para_consulta():
	global puerto
	datos=[]
	datos=puerto_Serie.readline()
	time.sleep(0.2)
	
	led_recibido=datos[9]
	puerta_recibido=datos[20]
	temperatura_recibido=datos[35:]

	dic={"led":int(led_recibido), "puerta":int(puerta_recibido),"temperatura":int(temperatura_recibido),'puerto':puerto}
	return dic
	


	
	
	
