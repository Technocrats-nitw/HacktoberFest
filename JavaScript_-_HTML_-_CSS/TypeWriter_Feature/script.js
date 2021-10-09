const TypeWriter = function(txtElement,devElement, devs, words, wait = 1500) {
    this.txtElement = txtElement;
    this.devElement = devElement;
    this.devs = devs;
    this.words = words;
    this.txt = '';
    this.wordIndex = 0;
    this.wait = parseInt(wait, 10);
    this.type();
    this.isDeleting = false;
}

TypeWriter.prototype.type = function() {
    const current = this.wordIndex % this.words.length;
    const fullTxt = this.words[current];
    const dev = this.devs[current];

    if (this.isDeleting) {
        this.txt = fullTxt.substring(0, this.txt.length - 1);
    } else {
        this.txt = fullTxt.substring(0, this.txt.length + 1);
    }

    this.txtElement.innerHTML = '<span class="txt"> ' + this.txt + '</span>'

    let typeSpeed = 100;
    if (this.isDeleting) {
        typeSpeed /= 2;
    }

    if (!this.isDeleting && this.txt === fullTxt) {
        this.devElement.innerHTML = '<span class="txt"> ' + dev + '</span>'
        typeSpeed = this.wait;
        this.isDeleting = true;
    } else if (this.isDeleting && this.txt === '') {
        this.isDeleting = false;
        this.devElement.innerHTML = '<span class="txt-dev"> '+'</span>'
        this.wordIndex++;

        typeSpeed = 500;
    }
    setTimeout(() => this.type(), typeSpeed);
}

document.addEventListener('DOMContentLoaded', init);

function init() {
    const txtElement = document.querySelector('.txt-type');
    const devElement = document.querySelector('.dev-type');
    const words = JSON.parse(txtElement.getAttribute('data-word'));
    const devs = JSON.parse(devElement.getAttribute('data-word'));
    const wait = txtElement.getAttribute('data-wait');

    new TypeWriter(txtElement,devElement, devs, words, wait);
}