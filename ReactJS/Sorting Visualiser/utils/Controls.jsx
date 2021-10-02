import React from 'react'

import styles from './Controls.module.scss';

const Controls = ({ clickHandler, disabled }) => {
  return (
    <div className={styles.container}>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(7)}>Clear Board</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(1)}>Insertion Sort</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(2)}>Quick Sort</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(3)}>Merge Sort</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(4)}>Bubble Sort</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(5)}>Selection Sort</button>
      <button className={styles.button} disabled={disabled} onClick={() => clickHandler(6)}>Radix Sort</button>
    </div>
  )
}

export default Controls
