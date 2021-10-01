import './App.css';
import Nav from './Components/Nav';
import About from './about';
import Shop from './shop';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';

function App() {
  return (
    <Router>
      <div className='App'>
        <Nav />
        <Switch>
          {/* exact ensures that the router switches to Home tab only when the entire URL matches the path */}
          <Route path='/' exact component={Home} />
          <Route path='/About' component={About} />
          <Route path='/Shop' component={Shop} />
        </Switch>
      </div>
    </Router>
  );
}

const Home = () => {
  return (
    <div>
      <h1>Home Page</h1>
    </div>
  );
};

export default App;
