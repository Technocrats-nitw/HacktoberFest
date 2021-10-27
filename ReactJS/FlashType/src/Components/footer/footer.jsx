import React from 'react'
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faFacebook, faGithub, faGoogle, faInstagram, faTwitter } from '@fortawesome/free-brands-svg-icons'
import './footer.css'
function footer() {
    return (
        <div className="footer-container">
            <div className="about">
                <a href="" className="link">
                    About us
                </a>
                <a href="" className="link">
                    Blog
                </a>
                <a href="" className="link">
                    Ios App
                </a>
                <a href="" className="link">
                    Android App
                </a>
            </div>
            <div className="icons">
                <a href="">
                    <FontAwesomeIcon icon={faFacebook} size="2x" color="wheat" />
                </a>
                <a href="">
                    <FontAwesomeIcon icon={faTwitter} size="2x" color="wheat" />
                </a>
                <a href="https://github.com/ashutosht-01">
                    <FontAwesomeIcon icon={faGithub} size="2x" color="wheat" />
                </a>
                <a href="">
                    <FontAwesomeIcon icon={faGoogle} size="2x" color="wheat" />
                </a>
                <a href="">
                    <FontAwesomeIcon icon={faInstagram} size="2x" color="wheat" />
                </a>
            </div>

        </div>
    )
}
export default footer