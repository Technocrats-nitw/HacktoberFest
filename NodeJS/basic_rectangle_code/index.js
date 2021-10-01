var rect = require('./rectangle');

function solve(l,b){
    console.log("solving l= "+l+" b="+b);

    rect(l,b,(err, rectangle) =>{
        if(err){
            console.log("ERROR :",err.message);
        }
        else{
            console.log("Area = "+rectangle.area() + " peri = " + rectangle.perimeter());
        }
    });
    console.log("Moving ahead ");
}

solve(2,4);
solve(3,5);
solve(-3,5);