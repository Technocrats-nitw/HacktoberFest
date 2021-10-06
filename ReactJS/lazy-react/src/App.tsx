import React, { Suspense } from 'react';
import './App.css';
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";

const HomePage = React.lazy(()=>import("./Components/Home"));
const AboutPage = React.lazy(()=>import("./Components/About"));
const ContactPage = React.lazy(()=>import("./Components/Contact"));


function App() {
  return (
    <div className="App">
      <Router>
        <Suspense fallback={<div>Loading...</div>}>

          <div>
            <nav>
              <ul>
                <li>
                  <Link to="/">Home</Link>
                </li>
                <li>
                  <Link to="/about">About</Link>
                </li>
                <li>
                  <Link to="/Contact">Contact</Link>
                </li>
              </ul>
            </nav>
            
            <Switch>
              <Route path="/contact">
                <ContactPage />
              </Route>
              <Route path="/about">
                <AboutPage />
              </Route>
              <Route path="/">
                <HomePage />
              </Route>
            </Switch>
          </div>
        </Suspense>
      </Router>
    </div>
  );
}

export default App;
