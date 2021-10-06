// Colors
var color = ['#ff0000', '#ff4000', '#ff8000', '#ffbf00', '#ffff00', '#bfff00', '#80ff00', '#40ff00', 
            '#00ff00', '#00ff40', '#00ff80', '#00ffbf', '#00ffff', '#00bfff', '#0080ff', '#0040ff', '#0000ff', 
            '#4000ff', '#8000ff', '#bf00ff', '#ff00ff', '#ff00bf', '#ff0080', '#ff0040', '#ff0000'];

// center element
var divs = document.getElementById('3')

// main screen
var element = document.getElementById("num");

var i = 1;                  

function FizzBuzz() {         
  setTimeout(function() {   

    if(i%15==0) element.innerHTML = "FizzBuzz";
    else if(i%5==0) element.innerHTML = "Buzz";
    else if(i%3==0) element.innerHTML = "Fizz";
    else element.innerHTML = i;

    divs.innerHTML = i;
    for (var j = 0; j < 7; j++)
    {
        var divss = document.getElementById(j);
        var cur = i-3+j;
        if(i-3+j <= 0)
            cur = 100 + i - 3 + j;
        if(i-3+j > 100)
            cur = i - 3 + j - 100;
        divss.innerHTML = cur;
        if(cur == 100) divss.style.fontSize ='80%';
        else divss.style.fontSize = '100%';
        divss.style.backgroundColor = color[(j+i)%color.length];
        divss.style.justifyContent = 'center';
        divss.style.display = 'flex';
    }
    i++;                    
    if (i < 101) {           
      FizzBuzz();             
    }                       
  },500)
}

FizzBuzz();