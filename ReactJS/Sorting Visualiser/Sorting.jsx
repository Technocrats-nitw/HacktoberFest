import React, { Component } from 'react';
import Container from './Container/Container';
import styles from './Sorting.module.scss';
import Legend from './utils/Legend';
import Controls from './utils/Controls';


// DEEP COPYING UTIL
import _ from 'lodash';

// SORTING ALGORITHMS
import InsertionSort from './Algorithms/InsertionSort';
import QuickSort from './Algorithms/QuickSort';
import MergeSort from './Algorithms/MergeSort';
import BubbleSort from './Algorithms/BubbleSort';
import SelectionSort from './Algorithms/SelectionSort';
import RadixSort from './Algorithms/RadixSort';

const SIZE = 50;

// UTILITY FUNCTION FOR RANDOM INT GENERATION
function randomIntFromInterval(min, max) {
  return Math.floor(Math.random() * (max - min + 1) + min);
}

export class Sorting extends Component {
  state = {
    array: [],
    disabled: false
  };

  componentDidMount() {
    this.resetArray();
  }

  resetArray = () => {
    const array = [];
    for (let i = 0; i < SIZE; i++) {
      let val = randomIntFromInterval(0, 450);
      array[i] = {
        value: val,
        loading: false,
      };
    }
    this.setState({ array });
  };

  sortingVisualiser = (sort_type) => {
    this.setState({disabled: true});
    let temp = [];
    for (let i = 0; i < this.state.array.length; ++i)
      temp.push(this.state.array[i].value);
    let swaps, changes;
    switch (sort_type) {
      case 1:
        swaps = InsertionSort(temp);
        this.animateSorting(swaps);
        break;
      case 2:
        swaps = QuickSort(temp);
        this.animateSorting(swaps);
        break;
      case 3:
        changes = MergeSort(temp);
        this.animateChanges(changes);
        break;
      case 4:
        swaps = BubbleSort(temp);
        this.animateSorting(swaps);
        break;
      case 5:
        swaps = SelectionSort(temp);
        this.animateSorting(swaps);
        break;
      case 6:
        changes = RadixSort(temp);
        this.animateChanges(changes);
        break;
      default:
        break;
    }
  };

  animateChanges = (changes) => {
    let temp = _.cloneDeep(this.state.array);
    for (let i = 0; i <= changes.length; ++i) {
      if (i === changes.length) {
        setTimeout(() => {
          this.endSorting();
        }, i * 100);
        return;
      }
      setTimeout(() => {
        temp[changes[i][0]].value = changes[i][1];
        temp[changes[i][0]].loading = true;
        this.setState({ array: temp });
        temp[changes[i][0]].loading = false;
      }, i * 100);
    }
  };

  animateSorting = (swaps) => {
    let temp = _.cloneDeep(this.state.array);
    for (let i = 0; i <= swaps.length; ++i) {
      if (i === swaps.length) {
        setTimeout(() => {
          this.endSorting();
        }, i * 100);
        return;
      }
      setTimeout(() => {
        let t = temp[swaps[i][0]].value;
        temp[swaps[i][0]].value = temp[swaps[i][1]].value;
        temp[swaps[i][1]].value = t;
        temp[swaps[i][0]].loading = true;
        temp[swaps[i][1]].loading = true;
        this.setState({ array: temp });
        temp[swaps[i][0]].loading = false;
        temp[swaps[i][1]].loading = false;
      }, i * 100);
    }
  };

  endSorting = () => {
    let temp = _.cloneDeep(this.state.array);
    for (let i = 0; i <= temp.length; ++i) {
      if (i === temp.length) {
        setTimeout(() => {
          this.setState({ array: temp, disabled: false });
        }, i * 40);
        return;
      }
      setTimeout(() => {
        temp[i].value += 10;
        temp[i].loading = true;
        this.setState({ array: temp });
        temp[i].value -= 10;
        temp[i].loading = false;
      }, i * 40);
    }
  };

  clickHandler = (mode) => {
    if (mode === 7) {
      this.resetArray();
      return;
    }
    this.sortingVisualiser(mode);
  };

  render() {
    return (
      <div className={styles.container}>
        <Controls clickHandler={this.clickHandler} disabled={this.state.disabled}/>
        <Container array={this.state.array} />
        <Legend />
      </div>
    );
  }
}

export default Sorting;
