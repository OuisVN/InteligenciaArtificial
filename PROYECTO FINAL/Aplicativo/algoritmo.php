<?php include_once('includes/header.php'); ?>
	
		<?php 
			$poblacion 			= array();
			$cantidad_prueba 	= 0;
			$contador 			= 1;
			
			if($_REQUEST['tamano_poblacion'] == null){
				$tamano_poblacion = 100;
			}else{
				$tamano_poblacion 	= $_REQUEST['tamano_poblacion']; 	// Tamaño de la Población.
			}
			
			if($_REQUEST['tamano_permitido'] == null){
				$tamano_permitido = 9;
			}else{
				$tamano_permitido 	= $_REQUEST['tamano_permitido']; 	// EJ: Probando --> Contiene 8 Letras.
			}
			
			if($_REQUEST['palabra'] == null){
				$palabra = 'Cotecnova';
			}else{
				$palabra 			= $_REQUEST['palabra']; 			// Palabra a encontrar.
			}
		?>
		<div class="container">
			<br/>
			<div class="row">
				<div class="col-md-12 tamaño_12">
					<div class="titulo azul text-center sombra"><u>Algoritmos Geneticos</u></div>
					<div class="contenido azul sombra">
						<button type="button" class="btn btn-secondary derecha sombra regresar" style="margin-right: 15px">Volver Atr&aacute;s</button>
						<table id="tabla" class="table table-bordered table-hover sombra" style="width: 100%">
							<thead class="text-center">
								<tr>
									<td><b>GENERACION</b></td>
									<td><b>PALABRA</b></td>
									<td><b>NIVEL DE ERROR</b></td>
								</tr>
							</thead>
							<tbody class="text-center">
								<?php
									ObtenerPoblacionInicial();
			
									while(true){
										SeleccionNatural();
										RecrearPoblacion();
									}
								?>
							</tbody>
							<tfoot class="text-center">
								<tr>
									<td><b>ENTRENAMIENTO #</b></td>
									<td><b>PALABRA</b></td>
									<td><b>NIVEL DE ERROR</b></td>
								</tr>
							</tfoot>
						</table>
					</div>
				</div>
			</div>
		</div>		
		
		<?php include_once('includes/footer.php'); ?>