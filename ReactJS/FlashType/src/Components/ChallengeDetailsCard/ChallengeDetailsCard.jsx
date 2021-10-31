import React from 'react'
import './ChallengeDetailsCard.css'
// 2  values  as props
function ChallengeDetailsCard({ cardname, cardvalue }) {
    return (
        <div data-aos="fade-up" className="details-card-container">
            <div className="card-name">{cardname}</div>
            <div className="card-value">{cardvalue}</div>
        </div>
    )
}
export default ChallengeDetailsCard