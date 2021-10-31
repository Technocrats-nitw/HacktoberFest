import React from "react";
import './TestLetter.css'
function TestLetter({ letterInfo }) {
    const status = letterInfo.status;
    let statusclass;
    if (status === "correct")
        statusclass = 'test-letter-correct'
    else if (status === "incorrect")
        statusclass = 'test-letter-incorrect'
    else if (status === "notattempted")
        statusclass = 'test-letter-notattempted'
    return (
        <span className={`test-letter ${statusclass}`}>{letterInfo.testletter}</span>
    )
}
export default TestLetter