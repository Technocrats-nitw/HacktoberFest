import React from 'react'
import TestLetter from '../TestLetter/TestLetter'
import './TypingChallenge.css'
function TypingChallenge({ selectedParagraph, timeStarted, timeRemaning, testInfo, onInputChange }) {
    return (
        <div className="typing-challenge">
            <div className="timer-container">
                <p className="timer">00:
                    {timeRemaning > 10 ? timeRemaning : `0${timeRemaning}`}
                </p>
                <p className="timer-info">
                    {/* when timer started we do NOT need to render this statement */}
                    {!timeStarted ? "Start typing to start the test" : undefined} </p>
            </div>
            <div className="text-area">
                <div className="text-area-left">
                    <div className="test-paragraph">
                        {/* selectedParagraph  n testletter*/}
                        {testInfo.map(function (testobj, index) {
                            return <TestLetter
                                // test letter is NOT unique  but index is unique N child components put through array requires key prop 
                                key={index}
                                letterInfo={testobj} />
                        })}

                    </div>
                </div>
                <div className="text-area-right">
                    <textarea onChange={(event) => {
                        onInputChange(event.target.value)
                    }}
                        className="right-text-area" name="" placeholder="start typing "  >

                    </textarea>
                </div>
            </div>
        </div>
    )
}
export default TypingChallenge