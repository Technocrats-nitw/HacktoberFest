import React from 'react'
import TryAgain from '../TryAgain/TryAgain'
import TypingChallengeContainer from '../TypingChallengeContainer/TypingChallengeContainer'
import './TestContainer.css'
function TestContainer({ selectedParagraph, words, charecters, wpm, timeStarted, timeRemaning, testInfo, onInputChange, startAgain }) {
    return (
        <div className="test-container">
            ({timeRemaning > 0 ? (<div data-aos="fade-up" className="typing-challenge-container">
                <TypingChallengeContainer
                    selectedParagraph={selectedParagraph}
                    words={words}
                    charecters={charecters}
                    wpm={wpm}
                    timeStarted={timeStarted}
                    timeRemaning={timeRemaning}
                    testInfo={testInfo}
                    onInputChange={onInputChange}
                />
            </div>) : (<div className="tryagain-container">
                <TryAgain words={words} charecters={charecters} wpm={wpm} startAgain={startAgain} />
            </div>)}

        </div>

    )
}

export default TestContainer