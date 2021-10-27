import React from 'react'
import './TryAgain.css'
function TryAgain({ charecters, words, wpm, startAgain }) {
    return (
        <div className="try-again-container">
            <h1 data-aos="fade-up">Test Results</h1>
            <div data-aos="fade-up" className="result-contianer">
                <p>
                    <b>Charecters:</b> {charecters}
                </p>
                <p>
                    <b>Words:</b> {words}
                </p>
                <p>
                    <b>Wpm:</b> {wpm}
                </p>
            </div>
            <div data-aos="fade-up">
                <button onClick={function () {
                    startAgain()
                }} className="end-buttons start-again-btn">Re-try</button>
                <button onClick={function () {
                    window.open("https://www.facebook.com/sharer.php?u=https://ashutosht-01.github.io/FlashType/",
                        "facebook-share-dialog",
                        "width=800 , height=600"
                    )
                }} className="end-buttons share-btn">Share</button>
                <button onClick={function () {
                    window.open(
                        "https://twitter.com/intent/tweet?text=https://ashutosht-01.github.io/FlashType/",
                        "Twitter",
                        "width:800, height:600"
                    );
                }} className="end-buttons tweet-btn">
                    Tweet</button>
            </div>
        </div>
    )
}
export default TryAgain