# **Cifrado Vernam**
## Objetivo.
Implementar el cifrado de Vernam para cifrar y descifrar mensajes.

## Funcionamiento.
El programa usa la herramienta _Make_ que permite la automatización de la compilación, para ello solo basta con ejecutar el siguiente comando:

>  make

De esta manera se compilará automáticamente el código y se habrá creado un ejecutable llamado _vernam_, así lo único que se tendrá que hacer para la ejecución del programa es ejecutar dicho ejecutable de la siguiente manera:

> ./vernam.

## Ejemplo de prueba.  


### Cifrar un mensaje:


### Entrada:  
Mensaje Original: _SOL_  

### Salida:  
Mensaje original en binario: _010100110100111101001100_  
Longitud del mensaje binario: _24_  

### Entrada:  
Clave aleatoria: _001111000001100001110011_

### Salida:
Mensaje cifrado en binario: _011011110101011100111111_
Mensaje cifrado: _oW?_


### Descifrar un mensaje:


### Entrada:  
Mensaje Cifrado: _[t_  

### Salida:
Mensaje cifrado en binario: _0101101101110100_  
Longitud del mensaje binario: _16_

### Entrada:
Clave aleatoria: _0000111100100001_

### Salida: 
Mensaje original en binario: _0101010001010101_  
Mensaje original: _TU_


