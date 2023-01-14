setInterval(function(){
	fetch('/getPayload')
	.then(response =>  {
		if(response.ok) {
		return response.json()
		} })
	.then(data => {
		var payload = data.payload;
		// code to update elements based on payload
		if(payload == '0'){
			document.getElementById("slouch-grade").src = "/static/images/d-icon.png";
			document.getElementById("slouch_val").src = "/static/images/0.jpg";
			document.getElementById("progress-bar").setAttribute("style", "width: 25%");
			document.getElementById("progress-bar").setAttribute("class", "progress-bar bg-danger");
			alert("TERRIBLE POSTURE!");
			}
			else if(payload == '1'){
			document.getElementById("slouch-grade").src = "/static/images/c-icon.png";
			document.getElementById("slouch_val").src = "/static/images/1.jpg";
			document.getElementById("progress-bar").style.width = "50%";
			document.getElementById("progress-bar").className = "progress-bar bg-warning";
			alert("BAD POSTURE!");
			}
			else if(payload == '2'){
			document.getElementById("slouch-grade").src = "/static/images/b-icon.png";
			document.getElementById("slouch_val").src = "/static/images/2.jpg";
			document.getElementById("progress-bar").style.width = "75%";
			document.getElementById("progress-bar").className = "progress-bar bg-info";
			alert("OKAY POSTURE!");
			}
			else if(payload == '3'){
			document.getElementById("slouch-grade").src = "/static/images/a-icon.png";
			document.getElementById("slouch_val").src = "/static/images/3.jpg";
			document.getElementById("progress-bar").style.width = "100%";
			document.getElementById("progress-bar").className = "progress-bar bg-success";
			alert("GOOD POSTURE!");
			}
		}).catch(error => {
		console.log(error);
		var payload = '0';
		// code to update elements based on payload
		if(payload == '0'){
			document.getElementById("slouch-grade").src = "/static/images/d-icon.png";
			document.getElementById("slouch_val").src = "/static/images/0.jpg";
			document.getElementById("progress-bar").setAttribute("style", "width: 25%");
			document.getElementById("progress-bar").setAttribute("class", "progress-bar bg-danger");
			alert("TERRIBLE POSTURE!");
			}
			else if(payload == '1'){
			document.getElementById("slouch-grade").src = "/static/images/c-icon.png";
			document.getElementById("slouch_val").src = "/static/images/1.jpg";
			document.getElementById("progress-bar").style.width = "50%";
			document.getElementById("progress-bar").className = "progress-bar bg-warning";
			alert("BAD POSTURE!");
			}
			else if(payload == '2'){
			document.getElementById("slouch-grade").src = "/static/images/b-icon.png";
			document.getElementById("slouch_val").src = "/static/images/2.jpg";
			document.getElementById("progress-bar").style.width = "75%";
			document.getElementById("progress-bar").className = "progress-bar bg-info";
			alert("OKAY POSTURE!");
			}
			else if(payload == '3'){
			document.getElementById("slouch-grade").src = "/static/images/a-icon.png";
			document.getElementById("slouch_val").src = "/static/images/3.jpg";
			document.getElementById("progress-bar").style.width = "100%";
			document.getElementById("progress-bar").className = "progress-bar bg-success";
			alert("GOOD POSTURE!");
			}
		});
		}, 20000);
	
	