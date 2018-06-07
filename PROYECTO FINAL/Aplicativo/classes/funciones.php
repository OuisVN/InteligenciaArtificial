<?php

	/*
		Funciones de este Programa:
		
		- ObtenerPoblacionInicial();
		- PersonaAzar();
		- SeleccionNatural();
		- cmp();								// EJ: $a = array(3, 2, 5, 6, 1); Resultado: 1, 2, 3, 5, 6.
		- RecrearPoblacion();
		- Reproduccion();
		- Cambiar();
		- Entrenamiento();		
	*/	
	
	function ObtenerPoblacionInicial(){
		global $poblacion, $tamano_poblacion;
		
		for($i = 0; $i < $tamano_poblacion; $i++){
			$persona = PersonaAzar();
			array_push($poblacion, array($persona, Entrenamiento($persona))); // ARRAY_PUSH: Inserta uno o más elementos al final de un array.
		}
	}
	
	function PersonaAzar(){
		global $tamano_permitido;
		
		$persona = '';
		for($i = 0; $i < $tamano_permitido; $i++){
			$persona .= str_shuffle('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !')[0]; 	// STR_SHUFFLE: Reordena aleatoriamente una cadena.
																									// .= Es para concatenar.
		}
		
		return $persona;
	}
	
	function SeleccionNatural(){
		global $poblacion, $tamano_poblacion, $numero_generacion;
		
		usort($poblacion, "cmp"); 								// USORT: Ordena un array según sus valores usando una función de comparación definida por el usuario (cmp).
		array_splice($poblacion, ceil($tamano_poblacion / 2));	// ARRAY_SPLICE: Elimina una porción del array y la reemplaza con otra cosa.
																// CEIL: Redondear fracciones hacia arriba. EJ: 3.4 -> 4
		echo '
			<tr>
				<td>'.$numero_generacion.'</td>
				<td>'.$poblacion[0][0].'</td>
				<td>'.$poblacion[0][1].'</td>
			</tr>
		';
	}
	
	function cmp($a, $b){
		if ($a[1] == $b[1]){
			return 0;
		}
		
		return ($a[1] > $b[1]) ? -1 : 1;
	}
	
	function RecrearPoblacion(){
		global $poblacion, $tamano_poblacion, $numero_generacion;
		
		$numero_generacion++;
		$c = count($poblacion); // COUNT: Cuenta todos los elementos de un array.
		
		for($i = $c; $i < $tamano_poblacion; $i++){
			$a = rand(0, $c-1); // RAND: Genera un número entero aleatorio.
			$b = rand(0, $c-1); // RAND: Genera un número entero aleatorio.
			array_push($poblacion, Reproduccion($poblacion[$a][0], $poblacion[$b][0])); // ARRAY_PUSH: Inserta uno o más elementos al final de un array.
		}
	}
	
	function Reproduccion($ia, $ib){
		global $tamano_permitido;
		
		$umbral 	= rand(0, $tamano_permitido - 1); 	// RAND: Genera un número entero aleatorio.
		$antes 		= substr($ia, 0, $umbral); 			// SUBSTR: Devuelve parte de una cadena.
		$despues  	= substr($ib, $umbral); 			// SUBSTR: Devuelve parte de una cadena.
		$hijo 		= $antes.$despues; 					// Concatena la variable $antes con la variable $despues.
		$hijo 		= Cambiar($hijo);
		
		return array($hijo, Entrenamiento($hijo));
	}
	
	function Cambiar($hijo){
		global $tamano_permitido;
		
		$ejemplo = PersonaAzar();
		for($i = 0; $i < $tamano_permitido; $i++){
			if(rand(0,100) == 100){
				$hijo[$i] = $ejemplo[$i];
			}
		}
		return $hijo;
	}
	
	function Entrenamiento($persona){
		global $numero_generacion, $tamano_poblacion, $cantidad_prueba, $palabra, $tamano_permitido;
		
		$cantidad_prueba++;		
		$nivel_error = 0;		
		for($i = 0; $i < strlen($persona); $i++){ 						// STRLEN: Obtiene la longitud de un string.
			$nivel_error -= abs(ord($palabra[$i]) - ord($persona[$i])); 	// ORD: Devuelve el valor ASCII de un entero.
		}
		
		if($nivel_error == 0){			
			echo '
				<script>swal("¡Palabra Encontrada!", "Generacion: '.$numero_generacion.', Palabra: '.$persona.', Nivel de Error: '.$nivel_error.'", "success");</script>
				
				<div class="row">
					<div class="col-md-1"></div>
					<div class="col-md-4">
						<font style="font-size: 15px;">
							- <b>Tama&ntilde;o Poblaci&oacute;n:</b> '.$tamano_poblacion.'.<br/>
							- <b>Palabra:</b> '.$palabra.'.<br/>
							- <b>Tama&ntilde;o Palabra Especificado:</b> '.$tamano_permitido.'.<br/>
							- <b>Cantidad Intentos:</b> <font style="color: red">'.$cantidad_prueba.'</font>.
						</font>
					</div>
					<div class="col-md-7"></div>
				</div>
				
				<br style="line-height: 30px;">
				
				<tr>
					<td><b>'.$numero_generacion.'</b></td>
					<td><b>'.$persona.'</b></td>
					<td><b>'.$nivel_error.'</b></td>
				</tr>
			';
			
			exit(); // Imprime un mensaje y termina el script actual.
		}
		
		return $nivel_error;
	}
?>