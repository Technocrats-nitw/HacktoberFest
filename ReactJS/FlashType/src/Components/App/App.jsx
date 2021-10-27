import React from 'react'
import Nav from '../Nav/Nav'
import Landing from '../Landing/Landing'
import Challenge from '../ChallengeSection/ChallengeSection'
import { SAMPLE_PARAGRAPHS } from "../../data/sampleParagraphs";
import Footer from '../footer/footer'
import './App.css'

const totaltime = 60

const ServiceUrl = "http://metaphorpsum.com/paragraphs/1/13"

const DefaultStates = {
    selectedParagraph: "",
    timeStarted: false,
    timeRemaning: totaltime,
    Words: 0,
    Charecters: 0,
    Wpm: 0,
    testInfo: []
}

class App extends React.Component {

    state = DefaultStates;

    fetchNewParagraphFallback = () => {
        const data =
            SAMPLE_PARAGRAPHS[
            Math.floor(Math.random() * SAMPLE_PARAGRAPHS.length)
            ];

        const selectedParagraphArray = data.split('')
        const testinfo = selectedParagraphArray.map(function (letter) {
            return {
                testletter: letter,
                status: 'notattempted'
            };
        })
        this.setState({ ...DefaultStates, selectedParagraph: data, testInfo: testinfo })
    };

    fetchNewParagraph = () => {
        fetch(ServiceUrl).then(function (response) {
            return response.text()
        }).then((data) => {
            this.setState({ selectedParagraph: data })
            const selectedParagraphArray = data.split('')
            const testinfo = selectedParagraphArray.map(function (letter) {
                return {
                    testletter: letter,
                    status: 'notattempted'
                };
            })
            this.setState({ ...DefaultStates, selectedParagraph: data, testInfo: testinfo })
        })
    }

    componentDidMount() {

        this.fetchNewParagraphFallback();

    }
    //timer function

    startTimer = () => {
        this.setState({ timeStarted: true })
        const Timer = setInterval(() => {
            if (this.state.timeRemaning > 0) {
                //change the speed
                const timeSpent = totaltime - this.state.timeRemaning;
                const wpm = (timeSpent > 0) ? ((this.state.Words / timeSpent) * totaltime) : 0;
                this.setState({
                    timeRemaning: this.state.timeRemaning - 1,
                    Wpm: parseInt(wpm)
                })
            } else {
                // after executing clear interval it stops calling callback function
                clearInterval(Timer)
            }
        }, 1000)
    }
    handeluserInput = (inputvalue) => {
        if (!this.state.timeStarted) this.startTimer()
        // algorithm
        // underflow case
        // All charecters marked unattempted 
        // find out the last charecter index in inputvalue
        // check if charecter in that is same as in testInfo
        // update status
        //  yes-coorect
        //  no-incorrect
        const charecters = inputvalue.length;
        const words = inputvalue.split(" ").length;
        const index = inputvalue.length - 1;

        //underflow Case
        if (index < 0) {
            this.setState({
                testInfo: [
                    {
                        testletter: this.state.testInfo[0].testletter,
                        status: "notattempted"
                    },
                    //    In this logic only for new array only 1st letter is repeated
                    ...this.state.testInfo.slice(1)
                ],
                Words: words,
                Charecters: charecters
            })
            return;
        }


        //copy of test Info
        const testinfo = this.state.testInfo;
        //if index has not overflown
        if ((index < this.state.selectedParagraph.length))
            testinfo[index + 1].status = "notattempted"
        //check for Correct typed letter
        const isCorrect = (testinfo[index].testletter === inputvalue[index])
        //update the testinfo
        testinfo[index].status = (isCorrect) ? "correct" : "incorrect"
        //update the state
        this.setState({
            testInfo: testinfo,
            Words: words,
            Charecters: charecters
        })
    }

    startAgain = () => {

        this.fetchNewParagraph();
    }
    render() {

        console.log('test info ', this.state.testInfo)


        return (
            <div className="app">
                {/*Nav Section*/}
                <Nav />
                {/*Landing Section */}
                <Landing />
                {/* Challenge   Section   */}
                <Challenge
                    selectedParagraph={this.state.selectedParagraph}
                    words={this.state.Words}
                    charecters={this.state.Charecters}
                    wpm={this.state.Wpm}
                    timeStarted={this.state.timeStarted}
                    timeRemaning={this.state.timeRemaning}
                    testInfo={this.state.testInfo}
                    onInputChange={this.handeluserInput}
                    startAgain={this.startAgain}
                />
                {/*footer Section */}
                <Footer />
            </div>
        )
    }
}
export default App