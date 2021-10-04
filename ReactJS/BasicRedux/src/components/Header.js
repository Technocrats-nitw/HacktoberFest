import { useSelector,useDispatch } from 'react-redux';
import {authActions } from '../store/auth';

import classes from './Header.module.css';

const Header = () => {
  const dispatch = useDispatch();
  const isAuthenticated = useSelector(state => state.auth.isAuthenticated);
  const logoutHandler = event => {
    dispatch(authActions.logout());
  }
  return (
    <header className={classes.header}>
      <h1>Redux Auth</h1>
      {isAuthenticated && 
        <nav>
          <ul>
            <li>
              <button onClick={logoutHandler} >Logout</button>
            </li>
          </ul>
        </nav>
      }
    </header>
  );
};

export default Header;
