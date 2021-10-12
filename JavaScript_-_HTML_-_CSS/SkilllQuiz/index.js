var time = 59;
var count;
var points;


var startBtn = document.getElementById("start-page-btn");
var rulesBtn = document.getElementById("rules-btn");
var htmlBtn = document.getElementById("html");
var cssBtn = document.getElementById("css");
startBtn.onclick = function () {
    var startPage = document.getElementById("start-page");
    startPage.style.display = "none";
}
rulesBtn.onclick = function () {
    var rulesPage = document.getElementById("rules");
    rulesPage.style.display = "none";
}

let mcq = [
    {

        question: "What does HTML stand for?",
        answer: "Hyper Text Markup Language",
        options: [
            "Hyper Text Markup Link",
            "Hyper Tool Markup Language",
            "Hyper Text Markup Language",
            "Hyper Text Marking Link"
        ]
    },
    {

        question: "Which of the following characters indicate closing of a tag?",
        answer: "/",
        options: [
            "!",
            "/",
            "\\",
            "|"
        ]
    },
    {

        question: "Which of the following attributes is used to open an hyperlink in new tab?",
        answer: "target",
        options: [
            "tab",
            "href",
            "target",
            "ref"
        ]
    },
    {

        question: "Which tag is used for creating a drop-down selection list?",
        answer: "select",
        options: [
            "select",
            "option",
            "dropdown",
            "list"
        ]
    },
    {

        question: "Where is the script tag used?",
        answer: "In the head and body tags",
        options: [
            "In the head tag",
            "In the body tag",
            "In the head and body tags",
            "Nowhere"
        ]
    },
    {

        question: "What is the default value of the position property?",
        answer: "static",
        options: [
            "absolute",
            "static",
            "relative",
            "fixed"
        ]
    },
    {

        question: "How do you display hyperlinks without an underline?",
        answer: "text-decoration:none",
        options: [
            "decoration:none",
            "text-decoration:no-underline",
            "underline:none",
            "text-decoration:none"
        ]
    },
    {

        question: "Which of the following defines 1% of viewport width?",
        answer: "vw",
        options: [
            "px",
            "vh",
            "vw",
            "vmin"
        ]
    },
    {

        question: "Which of the following property specifies the time required for a transition effect to complete?",
        answer: "transition-duration",
        options: [
            "transition-duration",
            "transition-timing-function",
            "transition-time",
            "timing-transition"
        ]
    },
    {

        question: "What is the difference between display:none and visibility:hidden?",
        answer: "tag will not appear on page in both the cases but space will be allocated in case of visibility:hidden",
        options: [
            "tag will not appear on page in both the cases but space will be allocated in case of display:none",
            "tag will not appear on page in both the cases but space will be allocated in case of visibility:hidden",
            "They both are same",
            "tag is still visible in display:none"
        ]
    }
]
htmlBtn.onclick = function () {
    var choicePage = document.getElementById("quiz-choice-page");
    choicePage.style.display = "none";
    var container = document.getElementById("containerBox");
    container.style.display = "block";
    var quiz = document.getElementById("name");
    quiz.innerText = "HTML";
    time = 59;
    display(0);
    count = 0;
    points = 0;
}
cssBtn.onclick = function () {
    var choicePage = document.getElementById("quiz-choice-page");
    choicePage.style.display = "none";
    var container = document.getElementById("containerBox");
    container.style.display = "block";
    var quiz = document.getElementById("name");
    quiz.innerText = "CSS";
    time = 59;
    // count=4;
    display(5);
    count = 5;
    points = 0;
}
// window.onload=function(){
//     display(0);
// }
function next() {
    if (count == 3 || count == 8) {
        var hide = document.getElementById("nxt");
        hide.style.display = "none";
    }

    var ticked = document.querySelector("div.choice.color");
    if (ticked.innerText == mcq[count].answer) {
        points++;
        console.log(points);
    }

    if (count >= 0 && count < 9) {
        count++;
        display(count);
    }

    var one = document.getElementsByClassName("choice");
    for (let i = 0; i < one.length; i++) {
        if (one[i].classList.contains('color')) {
            one[i].classList.remove('color');
        }

    }
}




function display(count) {
    let q = document.getElementById('problem');
    q.style.fontSize = 16 + "px";
    let a1 = document.getElementById('choice1');
    let a2 = document.getElementById('choice2');
    let a3 = document.getElementById('choice3');
    let a4 = document.getElementById('choice4');
    q.innerHTML = "<h3>" + mcq[count].question + "</h3>";
    a1.innerHTML = "<p>" + mcq[count].options[0] + "</p>"
    a2.innerHTML = "<p>" + mcq[count].options[1] + "</p>"
    a3.innerHTML = "<p>" + mcq[count].options[2] + "</p>"
    a4.innerHTML = "<p>" + mcq[count].options[3] + "</p>"
    var one = document.getElementsByClassName("choice");
    //     submit.onclick= function(){
    //         console.log("total score is");
    //    console.log(points);
    //     }

    toggle();



}
setInterval(function () {
    if (time > 0) {
        document.getElementById('timer').innerHTML = time;
        time--;
    }
    else {
        showScore();
        document.getElementById("containerBox").style.visibility = "hidden";
        document.getElementById('timer').innerHTML = time;
        document.getElementById('nxt').style.display = "none";
    }
}, 1000)





function toggle() {
    var one = document.getElementsByClassName("choice");
    var submit = document.getElementById("submit");



    for (let j = 0; j < one.length; j++) {
        
            if(one[j].classList.contains("hover_effect"))
                     {
                         one[j].classList.remove("hover_effect");
                         
                     }
       
        one[j].onclick = function () {
            console.log(one[j].innerText);
            console.log(mcq[count].answer);


            for (let i = 0; i < one.length; i++) {
                if (one[i].classList.contains('color')) {
                    one[i].classList.remove('color');
                   
                }
               
            }
            one[j].classList.add("color");

            

        }
        submit.onclick = showScore;
    }
    

}

function showScore() {

    next();

    var score = document.getElementById("score");
    var section = document.getElementById("section");
    var rulesPage = document.getElementById("rules");
    var choicePage = document.getElementById("quiz-choice-page");
    var foot = document.getElementById("submit");
    var nxt = document.getElementById("nxt");
    var nxt_ans = document.getElementById("nxt_ans");
    foot.innerText = "Start again";
    section.style.display = "none";
    score.style.display = "flex";
    time = 0;
    submit.onclick = function () {
        score.style.display = "none";
        section.style.display = "block";
        nxt.style.display = "block";
        nxt_ans.style.display = "none";
        rulesPage.style.display = "block";
        choicePage.style.display = "flex";
        time = 60;
        display(0);
        foot.innerText = "Submit";
        count = 0;
        points = 0;
    }
    console.log("total score is");
    console.log(points);

    var comment = document.getElementById("para");
    var final = document.getElementById("points");
    if (points === 5)
        comment.innerText = "Excellent!You've scored the maximum points";
    else if (points === 4)
        comment.innerText = "Brilliant!";
    else if (points === 3)
        comment.innerText = "Great score!";
    else if (points === 2)
        comment.innerText = "Good! With some practice you can do better";
    else {
        comment.innerText = "You need to work harder!"
    }
    final.innerHTML = "<h2>" + "Your score is: " + points + "/5" + "</h2>";
    final.classList.add("total");
    (comment.innerText).style.color = "black";
    //comment.classList.add("remark");

}

var ans = document.getElementById("ans");
ans.addEventListener("click", function () {
    var score = document.getElementById("score");
    var nxt = document.getElementById("nxt");
    var nxt_ans = document.getElementById("nxt_ans");
    // var start = document.getElementById("submit");
    // var rulesPage = document.getElementById("rules");
    var section = document.getElementById("section");
    var quiz_name = document.getElementById("name");
    var start = document.getElementById('submit');
    score.style.display = "none";
    section.style.display = "block";
    nxt.style.display = "none";
    nxt_ans.style.display = "block";


    if (quiz_name.innerText == "CSS") {
        count = 5;
        answer();
    }
    else {
        count = 0;
        answer();
    }
    nxt_ans.onclick = function () {
        if (quiz_name.innerText == "CSS" && count < 9) {
            count++;
            answer();
        }
        else if (quiz_name.innerText == "HTML" && count < 4) {
            count++;
            answer();
        }
    }


    // nxt_ans.onclick=function{
    //     count++;
    //     display(count);
    // }
    // start.onclick=function(){

    //     rulesPage.style.display="flex";

    //      }
    function answer() {
        let q = document.getElementById('problem');
        q.style.fontSize = 16 + "px";
        //  let a = document.getElementsByClassName("choice");
        //  for(let i=0;i<4;i++)
        //  {
        //      a[i].onmouseover=function(){
        //          a[i].removeClass('.choice');
        //      }
        //  }
        let a = document.getElementsByClassName('choice');
        let a1 = document.getElementById('choice1');
        let a2 = document.getElementById('choice2');
        let a3 = document.getElementById('choice3');
        let a4 = document.getElementById('choice4');
        q.innerHTML = "<h3>" + mcq[count].question + "</h3>";
        a1.innerHTML = "<p>" + mcq[count].options[0] + "</p>"
        a2.innerHTML = "<p>" + mcq[count].options[1] + "</p>"
        a3.innerHTML = "<p>" + mcq[count].options[2] + "</p>"
        a4.innerHTML = "<p>" + mcq[count].options[3] + "</p>"
        // ( mcq[count].answer).classList.add('.hover_effect');
        for(let i=0;i<4;i++)
        {
            if(a[i].classList.contains("hover_effect"))
            {
               
                a[i].classList.remove("hover_effect");
            }
            
        }
        console.log(a1.innerText);
        // (mcq[count].answer).style.color="green";
        if(a1.innerText==mcq[count].answer)
        {
            
            a1.classList.add("hover_effect");
        }
        else if(a2.innerText==mcq[count].answer)
        {
            
            a2.classList.add("hover_effect");
        }
        else if(a3.innerText==mcq[count].answer)
        {
           
            a3.classList.add("hover_effect");
        }
        else
        {
            // a4.style.color="green";
            // a4.style.fontWeight="600";
            a4.classList.add("hover_effect");
        }
    }
})
