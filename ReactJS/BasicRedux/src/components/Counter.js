import { useSelector, useDispatch } from "react-redux";

import { counterActions } from "../store/counter";
import classes from "./Counter.module.css";

const Counter = () => {
  const dispatch = useDispatch();  // This hook returns a reference to the dispatch function from the Redux store.
  const counter = useSelector((state) => state.counter.counter);
  const showCounter = useSelector((state) => state.counter.showCounter);

  const incrementHandler = () => {
    dispatch(counterActions.increment());  //increases counter by 1
  };
  const incrementByHandler = () => {
    dispatch(counterActions.increment_by({ amount: 5 })); // increases counter by 5
  };
  const decrementHandler = () => {
    dispatch(counterActions.decrement()); //decreases counter by 1
  };
  const decrementByHandler = () => {
    dispatch(counterActions.decrement_by({ amount: 5 })); // decreases counter by 5
  };
  const toggleCounterHandler = () => {
    dispatch(counterActions.toggleCounter());
  };

  return (
    <main className={classes.counter}>
      <h1>Redux Counter</h1>
      {showCounter && <div className={classes.value}>{counter}</div>}
      <div>
        <button onClick={incrementHandler}>Increment</button>
        <button onClick={incrementByHandler}>Increase by 5</button>
        <button onClick={decrementHandler}>Decrement</button>
        <button onClick={decrementByHandler}>Decrease by 5</button>
      </div>
      <button onClick={toggleCounterHandler}>Toggle Counter</button>
    </main>
  );
};

export default Counter;
