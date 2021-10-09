console.log('online');

const screen = document.getElementById('screen');
const equalsTo = document.getElementById('equalsTo');
let angle = "";
let screenValue = "";

function changeUnit(data)
{
    angle = data;
}
function sin(data){
    if( angle == "deg")
    {
        data = data * Math.PI / 180 ;
        console.log(Math.PI,data);
        return Math.sin(data);
    }
    return Math.sin(data);
}

function cos(data){
    if( angle == "deg")
    {
        data = data * Math.PI / 180 ;
        console.log(Math.PI,data);
        return Math.cos(data);
    }
    return Math.cos(data);
}

function display(data){
    if(data == "C"){
        screen.value = null;
        screenValue = '';
    }
    else if((data != '=') && (data !='inverse'))
    {
    screenValue += data;
    screen.value = screenValue;
    }
    else if(data =='inverse')
    {
        try {
            screen.value = `1/${screen.value}`;
        } catch (e) {
            screen.value = "syntax error";
            screenValue = '';
        }
    }
    else if(data == '=')
    {
        try {
            screen.value = eval(screen.value);
        screenValue = '';
            
        } catch (error) {
            screen.value = "syntax error";
            screenValue = '';
        }
        
    }
}

