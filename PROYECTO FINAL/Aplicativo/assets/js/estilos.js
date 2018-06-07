$(document).on("click", ".regresar", function(e){
	window.location = '/index';
});

$(document).on("click", ".probar", function(e){
	if(validacion()){
		var tamano_poblacion = $('#tamano_poblacion').val();
		var tamano_permitido = $('#tamano_permitido').val();
		var palabra = $('#palabra').val();
		
		window.location = '/algoritmo?&tamano_poblacion='+tamano_poblacion+'&tamano_permitido='+tamano_permitido+'&palabra='+palabra;
	}
	else{
		e.preventDefault();
		return false;
	}
});

function validacion(){
	if ($('#tamano_permitido').val() == ''){
		swal({
  			title: "¡ADVERTENCIA!",
  			text: "Por favor, Rellene el campo de Tamaño Permitido.",
			type: "warning",
  			timer: 2500,
  			showConfirmButton: false
		});
		$('#tamano_permitido').focus();
		return false;
	}
	if ($('#tamano_permitido').val() < 1){
		swal({
  			title: "¡ADVERTENCIA!",
  			text: "No se permiten valores negativos en el campo de Tamaño Permitido.",
			type: "warning",
  			timer: 2500,
  			showConfirmButton: false
		});
		$('#tamano_permitido').focus();
		return false;
	}
	if ($('#tamano_permitido').val() > $('#palabra').val().length){
		swal({
  			title: "¡ADVERTENCIA!",
  			text: "El Tamaño Permitido no puede sobrepasar a la Palabra ingresada.",
			type: "warning",
  			timer: 2500,
  			showConfirmButton: false
		});
		$('#palabra').focus();
		return false;
	}
	if ($('#palabra').val() == ''){
		swal({
  			title: "¡ADVERTENCIA!",
  			text: "Por favor, Rellene el campo de Palabra.",
			type: "warning",
  			timer: 2500,
  			showConfirmButton: false
		});
		$('#palabra').focus();
		return false;
	}
	return true;
}