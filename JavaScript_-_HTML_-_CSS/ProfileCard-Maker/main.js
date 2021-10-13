let subBtn= document.getElementById('sub-btn');
subBtn.addEventListener('click',(e)=>{
    e.preventDefault();
    let person = document.getElementById('person').value;
    let cardName = document.getElementById('card-name');
    cardName.innerText=person;

    let email = document.getElementById('email').value;
    let cardEmail = document.getElementById('card-email');
    cardEmail.innerText=email;
    
    let profession = document.getElementById('position').value;
    let cardProfession = document.getElementById('card-profession');
    cardProfession.innerText= profession;

    // let gender = document.getElementById('gender').value;
    // if(gender==="Female");

     
    let about = document.getElementById('about').value;
    let cardAbout = document.getElementById('card-about');
    cardAbout.innerText=about;

    if(person==='')
    {
        alert('enter name');
        document.getElementById('card-visibility').classList.add('card'); 
    }  
    else{
        document.getElementById('card-visibility').classList.add('card-style');  

    }
    
})