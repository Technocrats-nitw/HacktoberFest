import React from 'react'
import flash from '../../assets/img.png'
import './Landing.css'
import Typewriter from 'typewriter-effect';
function landing() {
    return (
        <div className="landing-container">
            <div data-aos="fade-right" className="landing-left">
                <div className="landing-header">
                    <h1>Can you type ...</h1>
                </div>
                <div className="type-container">
                    <Typewriter
                        options={{
                            strings: ['Fast?', 'Correct?', 'Quick?'],
                            autoStart: true,
                            loop: true,
                        }}
                    />
                </div>
            </div>
            <div data-aos="fade-left" className="landing-right">
                <img src={flash} alt="img" className="img-container" />
            </div>
        </div>
    )
}
export default landing