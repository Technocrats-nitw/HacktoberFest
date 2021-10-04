import { useSelector } from 'react-redux';

import Counter from './components/Counter';
import Header from './components/Header';
import Auth from './components/Auth';
import UserProfile from './components/UserProfile';

function App() {
  //UseSelector allows you to extract data from the Redux store state, using a selector function.
  const isAuthenticated = useSelector(state => state.auth.isAuthenticated); 
  return (
    <>
      <Header /> 
      {/* Show loginform if not authenticated */}
      {!isAuthenticated && <Auth />}

      {/* Show profile info if authenticated */}
      {isAuthenticated && <UserProfile /> }
      <Counter />
    </>
  );
}

export default App;
