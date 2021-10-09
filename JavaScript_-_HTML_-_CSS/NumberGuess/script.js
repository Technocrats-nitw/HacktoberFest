window.onload = function(){
	document.getElementById('onload').addEventListener("click",function(){
		this.style.display = "none";
		document.getElementById('process').style.display = "flex";
	})
	document.getElementById('final').addEventListener("click",function(){
		this.style.display = "none";
		document.getElementById('process').style.display = "flex";
	})

	document.getElementById('cheater').addEventListener("click",function(){
		this.style.display = "none";
		document.getElementById('process').style.display = "flex";
	})

	var ans = 500
	var beg = 0
	var last = 1000
	var a = 0
	var attempt = document.getElementsByClassName('attempt')
	console.log(attempt)
	document.getElementById('num').innerHTML = ans
	document.getElementById('big').addEventListener("click",function(){
		beg = ans
		ans = Math.ceil((last + beg)/2)
		document.getElementById('num').innerHTML = ans
		a++
		for(var i=0;i<a;i++)
		{
			attempt[i].style.color = "white"
		}
		document.getElementById('progress').style.width = String((100-100*(last-beg)/last))+"%"
		if(a==10)
		{
			falsified_data()
		}
	})
	document.getElementById('small').addEventListener("click",function(){
		last = ans
		ans = Math.floor((last + beg)/2)
		document.getElementById('num').innerHTML = ans
		if(beg == 0)
		{
			document.getElementById('progress').style.width = String((60 + 5*a))+"%"
		}
		else{
			document.getElementById('progress').style.width = String((100-100*(last-beg)/last))+"%"
		}
		a++
		for(var i=0;i<a;i++)
		{
			attempt[i].style.color = "white"
		}
		if(a==10)
		{
			falsified_data()
		}
	})
	document.getElementById('right').addEventListener("click",finale)
	function finale(){
		document.getElementById('process').style.display = "none"
		document.getElementById('final').style.display = "flex"
		for(var i=0;i<10;i++)
		{
			attempt[i].style.color = "black";
		}
		a=0
		ans = 500
		document.getElementById('progress').style.width = String(0)+"%"
		window.onload()
	}	
	function falsified_data(){
		document.getElementById('process').style.display = "none"
		document.getElementById('cheater').style.display = "flex"
		for(var i=0;i<10;i++)
		{
			attempt[i].style.color = "black";
		}
		a = 0
		ans = 500
		document.getElementById('progress').style.width = String(0)+"%"
		window.onload()
	}	 
}
