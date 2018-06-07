<?php include_once('includes/header.php'); ?>
	
		<link type="text/css" rel="stylesheet" href="assets/css/imagen.css">
		<script type="text/javascript" src="assets/js/tesseract.js"></script>
		<script type="text/javascript">
			function barraProgreso(paquete){
				var historial = document.getElementById('contenido');

				if(historial.firstChild && historial.firstChild.status === paquete.status){
					if('progress' in paquete){
						var progreso = historial.firstChild.querySelector('progress')
						progreso.value = paquete.progress
					}
				}else{
					var linea = document.createElement('div');
					linea.status = paquete.status;
					var estado = document.createElement('div')
					estado.className = 'status'
					estado.appendChild(document.createTextNode(paquete.status))
					linea.appendChild(estado)

					if('progress' in paquete){
						var progreso = document.createElement('progress')
						progreso.value = paquete.progress
						progreso.max = 1
						linea.appendChild(progreso)
					}


					if(paquete.status == 'done'){
						var pre = document.createElement('pre')
						pre.appendChild(document.createTextNode(paquete.data.text))
						linea.innerHTML = ''
						linea.appendChild(pre)
						$('#palabra').val(paquete.data.text);
						$("#tamano_permitido").val($("#palabra").val().length);
					}

					historial.insertBefore(linea, historial.firstChild)
				}
			}

			function reconocerArchivo(archivo){
				document.querySelector("#contenido").innerHTML = ''

				Tesseract.recognize(archivo, {
					lang: document.querySelector('#lenguaje').value
				})
					.progress(function(paquete){
						barraProgreso(paquete)

					})
					.then(function(data){
						barraProgreso({ status: 'done', data: data })
					})
			}
		</script>
		<div class="container">
			<br/>
			<div class="row">
				<div class="col-md-12 tamaño_12">
					<div class="titulo azul text-center sombra"><u>Algoritmos Geneticos</u></div>
					<div class="contenido azul sombra">
						<div class="row">
							<div class="col-md-8">
								<select class="form-control" id="lenguaje" style="height: 44px" onchange="window.lastFile && reconocerArchivo(window.lastFile)">
									<option value="spa" selected>Espa&ntilde;ol</option>
								</select>
							</div>
							<div class="col-md-4">
								<input type="file" class="form-control" onchange="reconocerArchivo(window.lastFile=this.files[0])" />
							</div>
						</div>
						<div id="contenido"></div>
						<br/><br/>
						<table class="table table-bordered sombra" style="width: 100%">
							<thead class="text-center">
								<tr>
									<td><b>TAMA&Ntilde;O POBLACI&Oacute;N</b></td>
									<td><b>N&Uacute;MERO DE LETRAS</b></td>
									<td><b>PALABRA</b></td>
									<td></td>
								</tr>
							</thead>
							<tbody class="text-center">
								<tr>
									<td>
										<select id="tamano_poblacion" class="form-control sombra" name="tamano_poblacion">
											<option value="100" selected>100 Personas</option>
											<option value="200">200 Personas</option>
											<option value="300">300 Personas</option>
											<option value="400">400 Personas</option>
											<option value="500">500 Personas</option>
										</select>
									</td>
									<td>
										<input type="number" id="tamano_permitido" class="form-control sombra" name="tamano_permitido" value="9"/>
									</td>
									<td>
										<input type="text" id="palabra" class="form-control sombra" name="palabra" value="Cotecnova"/>
									</td>
									<td>
										<button type="button" class="btn btn-success sombra probar"><b>PROBAR</b></button>
									</td>
								</tr>
							</tbody>
							<tfoot class="text-center">
								<tr>
									<td><b>TAMA&Ntilde;O POBLACI&Oacute;N</b></td>
									<td><b>N&Uacute;MERO DE LETRAS</b></td>
									<td><b>PALABRA</b></td>
									<td></td>
								</tr>
							</tfoot>
						</table>
					</div>
				</div>
			</div>
		</div>		
		
		<?php include_once('includes/footer.php'); ?>