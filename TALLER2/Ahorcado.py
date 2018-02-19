
# coding: utf-8

# In[1]:


''' 
    Corporación de estudios tecnológicos del norte del valle. 
    Inteligencia Artificial
    *- Juan David Cardona
    *- Cristian Durán
    *- Mauricio Lopez
'''

## Librería para ocultar la palabra secreta.
## Se utiliza para cifrar contraseñas o datos importantes.
import getpass
## Librerá para usar comandos de CMD.
import os

def _Borrar():
    os.system("cls")

def _Ahorcado():
    
    ## VARIABLES QUE UTILIZARÁ EL AHORCADO.
    Ahorcado         = ["0","1","2","3","4","5","6"]
    PalabrasErroneas = []
    
    # Getpass para ocultar la palabra secreta.
    PalabraSecreta   = list(getpass.getpass("Por favor, escribe la palabra secreta: "))  
    
    ## VARIABLES QUE UTILIZARÁ EL AHORCADO.
    Mostrar          = []    
    Mostrar          = ["_"] * len(PalabraSecreta)
    Intentos         = 0

    while Intentos < 7:
        
        ## Limpiar Pantalla
        _Borrar()
        
        ## Visual del Ahorcado.
        print("AHORCADO: ", Mostrar)
        print("INTENTOS ACTUALES: ", Ahorcado[Intentos])
        print("PALABRAS INCORRECTAS: ", PalabrasErroneas)
        
        print("")
        print("")
        
        ## Muñeco respecto a los intentos.
        if(Intentos == 1):
            print("  O  ")
        if(Intentos == 2):
            print("  O  ")
            print(" / ")
        if(Intentos == 3):
            print("  O  ")
            print(" / \ ")
        if(Intentos == 4):
            print("  O  ")
            print(" /|\ ")
        if(Intentos == 5):
            print("  O  ")
            print(" /|\ ")
            print(" / ")   
        if(Intentos == 6):
            print("  O  ")
            print(" /|\ ")
            print(" / \ ")
        ## Final del muñeco pero todavía con vida.    
        
        ## If en donde si adivina la palabra secreta, se activa con un mensaje de ganador.
        if PalabraSecreta == Mostrar:
            print("¡Felicidades, has ganado!")
            break
        
        ## Para que el usuario que va a jugar ponga una letra.
        letra = input("Por favor, escribe una letra: ")
        
        ## Vida del código
        if PalabraSecreta.__contains__(letra):
            
            ## Si la palabra tiene una/s letra/s hará la búsqueda e irá agregando la letra en su posición
            ## el for parará cuando llegue al limite de la palabra secreta.
            for comprobar, i in zip(PalabraSecreta,range(len(PalabraSecreta))):
                if comprobar == letra:
                    Mostrar[i] = letra
        else:
            
            ## Si la letra ya ha sido escrita y esta en la lista de Palabras Erroneas no contará como equivocación.
            if PalabrasErroneas.__contains__(letra):
                print("Esta palabra ya la has intentado con anterioridad, prueba con otra.")
            else:
                
                ## Si la letra no ha sido escrita con anterioridad si hará el conteo y agregará la letra en la lista
                ## de palabras erroneas.
                Intentos += 1
                PalabrasErroneas.append(letra)
        ## Vida del código
        
    else:
        
        ## Limpiar Pantalla
        _Borrar()
        
        ## If en donde si no logra adivinar la palabra secreta, se activa con un mensaje de perdedor.
        print("¡Has Perdido! La palabra era: ", PalabraSecreta)
        
        print("")
        print("")
        
        ## Visual del Ahorcado.
        print("  Ø  ")
        print(" /|\ ")
        print(" / \ ")
        ## Final del muñeco pero muerto.
        
## Ver Función.        
_Ahorcado()

