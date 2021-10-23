function func(){
    let title = document.getElementById('title').value;
    let main = document.getElementById('box');
    let text = document.getElementById('message').value;
    let boxStyle = document.getElementById('boxBorder');
    main.innerHTML = `<h1>${title}</h1>
                       <p>${text}</p>`;
    boxStyle.style.border="2px solid black";
    html2pdf()
    .from(main)
    .save();
}

// news
let news = document.getElementById('news-section');
document.getElementById('newsBtn').addEventListener('click',()=>{
   news.style.display="flex";
   news.style.flexDirection="column";
})