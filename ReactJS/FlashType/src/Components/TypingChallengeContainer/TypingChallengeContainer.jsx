import React from "react"
import './TypingChallengeContainer.css'
import ChallengeDetailsCard from "../ChallengeDetailsCard/ChallengeDetailsCard"
import TypingChallenge from "../TypingChallenge/TypingChallenge"
function TypingChallengeContainer({ selectedParagraph, words, charecters, wpm, timeStarted, timeRemaning, testInfo, onInputChange }) {


    return (
        <div className="typing-challenge-container">
            {/* details section */}
            <div className="details-container">

                {/* words typed */}
                <ChallengeDetailsCard cardname="Words" cardvalue={words} />

                {/* charecter typed */}
                <ChallengeDetailsCard cardname="Charecters" cardvalue={charecters} />

                {/* speed */}
                <ChallengeDetailsCard cardname="Speed" cardvalue={wpm} />

            </div>

            {/* real challenge section */}
            <div className="type-writter-container">
                <TypingChallenge
                    selectedParagraph={selectedParagraph}
                    timeStarted={timeStarted}
                    timeRemaning={timeRemaning}
                    testInfo={testInfo}
                    onInputChange={onInputChange}
                />
            </div>
        </div>

    )
}
export default TypingChallengeContainer