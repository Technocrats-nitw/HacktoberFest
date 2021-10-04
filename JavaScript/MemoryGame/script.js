console.log('Running')
let clickedCard = null;
var checkDone = 0
setTimeout(() => {
    const cards = document.querySelectorAll('.card');
    for (var i = 0; i < 16; i++) {
        cards[i].className += ' color-hidden';
    }
}, 1000);

function onCardClicked(e) {
    const target = e.currentTarget;
    if (target === clickedCard || target.className.includes('done')) {
        return;
    }
    target.className = target.className
        .replace('color-hidden', '')
        .trim();
    target.className += ' done';
    console.log(target.getAttribute('data-color'))

    if (!clickedCard) {
        clickedCard = target;
    } else if (clickedCard) {
        if (clickedCard.getAttribute('data-color') === target.getAttribute('data-color')) {
            console.log('Cards are equal')
            clickedCard = null;
            checkDone++;
            if (checkDone < 8) {
                document.querySelector('.sound-equal').play()
            } else {
                document.querySelector('.sound-winner').play()
            }
        } else {
            console.log('Cards Not Equal')
            document.querySelector('.sound-unequal').play()
            setTimeout(() => {
                console.log('we are here')
                clickedCard.className = clickedCard.className.replace('done', '').trim() + ' color-hidden';
                target.className = target.className.replace('done', '').trim() + ' color-hidden';
                clickedCard = null;
            }, 500);
        }
    }
    console.log(checkDone)
    if (checkDone === 8) {
        document.querySelector('.winner').innerHTML = '<h1>Hurray!!! You won.</h1>'
    }
}